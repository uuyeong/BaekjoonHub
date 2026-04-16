#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const long long INF = 1e18;
const int MAX_K = 300005;

struct Node {
    int cnt;
    long long sum;
};

// 세그먼트 트리: 가격 순위 구간에 대해 개수와 합을 저장
Node tree[4 * MAX_K];
int N, K, M, A_cnt, B_cnt;
vector<int> costs;
vector<int> group_type; // 0: None, 1: Han, 2: Eun, 3: Both

// 4개의 그룹
vector<int> g_none, g_han, g_eun, g_both;

// 좌표 압축을 위한 벡터
vector<int> all_costs;

int get_rank(int c) {
    return lower_bound(all_costs.begin(), all_costs.end(), c) - all_costs.begin();
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node].cnt += 1;
        tree[node].sum += val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node].cnt = tree[node * 2].cnt + tree[node * 2 + 1].cnt;
    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

// 가장 작은 k개의 합을 구하는 쿼리
long long query(int node, int start, int end, int k) {
    if (k <= 0) return 0;
    if (tree[node].cnt <= k) return tree[node].sum;
    if (start == end) return (long long)k * all_costs[start]; // 같은 가격이 여러 개일 경우

    int mid = (start + end) / 2;
    if (tree[node * 2].cnt >= k) {
        return query(node * 2, start, mid, k);
    } else {
        return tree[node * 2].sum + query(node * 2 + 1, mid + 1, end, k - tree[node * 2].cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> K)) return 0;
    cin >> M >> A_cnt >> B_cnt;

    costs.resize(K + 1);
    group_type.resize(K + 1, 0); // 기본 None

    for (int i = 1; i <= K; i++) {
        cin >> costs[i];
        all_costs.push_back(costs[i]);
    }
    
    // 좌표 압축 준비
    sort(all_costs.begin(), all_costs.end());
    all_costs.erase(unique(all_costs.begin(), all_costs.end()), all_costs.end());
    int D = all_costs.size();

    // 선호도 입력 처리
    for (int i = 0; i < A_cnt; i++) {
        int idx; cin >> idx;
        group_type[idx] |= 1; // Bit 0: Han
    }
    for (int i = 0; i < B_cnt; i++) {
        int idx; cin >> idx;
        group_type[idx] |= 2; // Bit 1: Eun
    }

    // 그룹 분류
    for (int i = 1; i <= K; i++) {
        if (group_type[i] == 0) g_none.push_back(costs[i]);
        else if (group_type[i] == 1) g_han.push_back(costs[i]);
        else if (group_type[i] == 2) g_eun.push_back(costs[i]);
        else if (group_type[i] == 3) g_both.push_back(costs[i]);
    }

    // 각 그룹 정렬 (가격 오름차순)
    sort(g_none.begin(), g_none.end());
    sort(g_han.begin(), g_han.end());
    sort(g_eun.begin(), g_eun.end());
    sort(g_both.begin(), g_both.end());

    // 초기 세그먼트 트리 구성: 선택 후보군(None 그룹 전체) 넣기
    for (int c : g_none) {
        update(1, 0, D - 1, get_rank(c), c);
    }

    // 초기 상태 (i=0): Han과 Eun 그룹에서 필수(M개)를 제외한 나머지를 트리에 넣음
    // 만약 M보다 그룹 크기가 작으면? -> 나중에 loop에서 impossible 처리됨, 여기선 안전하게 범위 체크
    int han_start = max(0, M);
    for (int i = han_start; i < g_han.size(); i++) update(1, 0, D - 1, get_rank(g_han[i]), g_han[i]);

    int eun_start = max(0, M);
    for (int i = eun_start; i < g_eun.size(); i++) update(1, 0, D - 1, get_rank(g_eun[i]), g_eun[i]);

    // 누적 합 미리 계산 (필수 선택 비용 계산용)
    vector<long long> psum_han(g_han.size() + 1, 0);
    for (int i = 0; i < g_han.size(); i++) psum_han[i+1] = psum_han[i] + g_han[i];

    vector<long long> psum_eun(g_eun.size() + 1, 0);
    for (int i = 0; i < g_eun.size(); i++) psum_eun[i+1] = psum_eun[i] + g_eun[i];
    
    long long current_both_sum = 0;
    long long min_total_cost = INF;

    // Both 그룹에서 i개를 선택하는 경우 순회
    for (int i = 0; i <= g_both.size(); i++) {
        // 현재 Both 그룹에서 i개를 선택했을 때 비용 더하기
        if (i > 0) current_both_sum += g_both[i-1];

        // 필요한 Han, Eun의 최소 개수
        int req_h = max(0, M - i);
        int req_e = max(0, M - i);

        // 불가능한 경우 체크
        bool possible = true;
        if (req_h > g_han.size()) possible = false;
        if (req_e > g_eun.size()) possible = false;
        
        // 이미 필수적으로 선택된 개수
        int mandatory_count = i + req_h + req_e;
        if (mandatory_count > N) possible = false;

        if (possible) {
            // 필수 비용 계산
            long long mandatory_cost = current_both_sum + psum_han[req_h] + psum_eun[req_e];
            
            // 더 채워야 할 개수
            int needed = N - mandatory_count;

            // 트리에 있는 후보들 중 가장 싼 needed개의 합
            if (tree[1].cnt < needed) {
                // 후보가 부족함
            } else {
                long long extra_cost = query(1, 0, D - 1, needed);
                min_total_cost = min(min_total_cost, mandatory_cost + extra_cost);
            }
        }

        // 다음 루프(i -> i+1) 준비: Both 하나 추가됨에 따라 Han/Eun 요구량 감소 가능성
        // req가 M-i 에서 M-(i+1)로 줄어든다면, Han/Eun에서 하나가 필수에서 해제되어 트리에 들어감
        if (i < g_both.size()) { // 마지막 루프 후에는 업데이트 불필요
            int next_req = max(0, M - (i + 1));
            int curr_req = max(0, M - i);

            if (curr_req > next_req) {
                // curr_req - 1 인덱스의 아이템이 필수 영역에서 해제됨 -> 트리에 추가
                // 단, 인덱스가 유효해야 함
                if (curr_req - 1 < g_han.size()) {
                    int val = g_han[curr_req - 1];
                    update(1, 0, D - 1, get_rank(val), val);
                }
                if (curr_req - 1 < g_eun.size()) {
                    int val = g_eun[curr_req - 1];
                    update(1, 0, D - 1, get_rank(val), val);
                }
            }
        }
    }

    if (min_total_cost == INF) cout << -1 << endl;
    else cout << min_total_cost << endl;

    return 0;
}
