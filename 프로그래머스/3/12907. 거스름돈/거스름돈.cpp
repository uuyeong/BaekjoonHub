#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<long long> dp(n+1, 0); // dp[i] 는 i원을 만들기 위해 생기는 경우의 수
    
    sort(money.begin(), money.end()); // 돈 오름차순 정렬
    
    // dp[0] = 1 (0)
    // dp[1] = 1 (1)
    // dp[2] = 2 (1/1, 2)
    // dp[3] = 2 (1/1/1, 1/2)
    // dp[4] = 3 (1/1/1/1, 1/1/2, 2/2)
    // dp[5] = 4 (1/1/1/1/1, 1/1/1/2, 1/2/2, 5)
    
    // coin에서 작은 수부터 
    
    dp[0] = 1; // 0원을 만드는 경우의 수 -> 아무것도 안고름 -> 1
    for(int coin : money){
       for(int i=coin; i<=n; i++){
            dp[i] = (dp[i] + dp[i-coin])%1000000007;
        } 
    }
    
    answer = dp[n];
    return answer;
}