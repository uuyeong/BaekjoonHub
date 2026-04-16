#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 회의 정보를 담을 구조체
struct Job {
    int start, end, profit;
};

// 종료 시간 기준 오름차순 정렬을 위한 비교 함수
bool compareJobs(const Job& a, const Job& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Job> jobs(N);
    for (int i = 0; i < N; i++) {
        cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
    }

    // 1. 종료 시간 기준으로 정렬 (O(N log N))
    sort(jobs.begin(), jobs.end(), compareJobs);

    // dp[i]: i번째 회의까지 고려했을 때의 최대 이익
    // 값의 범위가 크므로 long long 사용
    vector<long long> dp(N);
    
    // 첫 번째 회의 초기화
    dp[0] = jobs[0].profit;

    // 이분 탐색을 돕기 위해 종료 시간만 따로 저장한 벡터 (코드 간결성을 위해)
    vector<int> end_times(N);
    for(int i=0; i<N; ++i) end_times[i] = jobs[i].end;

    // 2. DP 수행 (O(N log N))
    for (int i = 1; i < N; i++) {
        long long currentProfit = jobs[i].profit;
        
        // 현재 회의(i)의 시작 시간보다 종료 시간이 작거나 같은 회의 중, 
        // 가장 늦게 끝나는 회의의 인덱스 찾기
        // upper_bound: 찾고자 하는 값(start)보다 '큰' 첫 번째 위치 반환
        auto it = upper_bound(end_times.begin(), end_times.begin() + i, jobs[i].start);
        
        int prevIdx = distance(end_times.begin(), it) - 1;

        // 겹치지 않는 이전 회의가 존재한다면 그 이익을 더함
        if (prevIdx != -1) {
            currentProfit += dp[prevIdx];
        }

        // 점화식: (이전까지의 최대값) vs (현재 회의 포함 + 겹치지 않는 이전 최대값)
        dp[i] = max(dp[i - 1], currentProfit);
    }

    cout << dp[N - 1] << endl;

    return 0;
}
