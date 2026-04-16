#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 팩토리얼 미리 계산 (최대 16!)
long long fact[20];

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= 16; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

// 다항식 곱셈 (벡터 크기가 작으므로 이중 반복문으로 충분)
vector<long long> multiply(const vector<long long>& A, const vector<long long>& B) {
    vector<long long> C(A.size() + B.size() - 1, 0);
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }
    return C;
}

// 조합 nCk 계산
long long nCk(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    // 그래프 생성
    // 0 ~ N-1: 인덱스 노드 (Left)
    // N ~ 2N-1: 값 노드 (Right)
    vector<vector<int>> adj(2 * N);
    for (int i = 0; i < N; i++) {
        // i번째 인덱스에 값 a[i]가 오면 안 됨 -> 간선 추가
        int u = i;
        int v1 = N + a[i] - 1; // 값을 0-based 인덱스로 변환
        adj[u].push_back(v1);
        adj[v1].push_back(u);

        // i번째 인덱스에 값 b[i]가 오면 안 됨 (a[i]와 다를 경우에만)
        if (a[i] != b[i]) {
            int v2 = N + b[i] - 1;
            adj[u].push_back(v2);
            adj[v2].push_back(u);
        }
    }

    vector<bool> visited(2 * N, false);
    vector<long long> total_poly = {1}; // 전체 다항식 초기값: 1

    // 모든 연결 요소(컴포넌트)를 순회
    for (int i = 0; i < 2 * N; i++) {
        if (visited[i]) continue;
        if (adj[i].empty()) continue; // 고립된 노드 무시

        // BFS로 컴포넌트의 노드 수와 간선 수 파악
        vector<int> q;
        q.push_back(i);
        visited[i] = true;
        
        int head = 0;
        int edge_count = 0;
        int vertex_count = 0;

        while(head < q.size()){
            int u = q[head++];
            vertex_count++;
            edge_count += adj[u].size();
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push_back(v);
                }
            }
        }
        edge_count /= 2; // 양방향 그래프이므로 간선이 2번 카운트됨

        // 컴포넌트 종류 판별 (Path vs Cycle)
        // Path: 정점 수 = 간선 수 + 1
        // Cycle: 정점 수 = 간선 수
        int L = edge_count; // 공식에서의 길이 L은 간선의 개수 기준
        vector<long long> comp_poly;

        if (vertex_count == edge_count) {
            // Cycle일 경우 매칭 다항식 계수
            for (int k = 0; k <= L / 2; k++) {
                long long val;
                if (k == 0) val = 1;
                else val = nCk(L - k, k) * L / (L - k);
                comp_poly.push_back(val);
            }
        } else {
            // Path일 경우 매칭 다항식 계수
            for (int k = 0; k <= (L + 1) / 2; k++) {
                 comp_poly.push_back(nCk(L - k + 1, k));
            }
        }
        
        // 전체 다항식에 현재 컴포넌트 다항식을 곱함
        total_poly = multiply(total_poly, comp_poly);
    }

    // 포함-배제 원리 적용
    long long ans = 0;
    for (int k = 0; k < total_poly.size(); k++) {
        if (k > N) break;
        
        long long term = total_poly[k] * fact[N - k];
        
        if (k % 2 == 1) ans -= term;
        else ans += term;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precomputeFactorials();
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
