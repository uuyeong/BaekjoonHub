#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {
    long long answer = 0;
    long long dp[2001];
    dp[1] = 1; // 1칸까지 가는 경우의 수는 1
    dp[2] = 2; // 2칸까지 가는 경우의 수는 2 (1, 1), (2)
    
    for(int i=3; i<=n; i++){
        // i=3일 때 3칸까지 가는 경우의 수는
        // 1. 1칸까지 갔을 때 +2를 한다. 
        // 2. 2칸까지 갔을 때 +1을 한다. 
        
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    answer = dp[n];
    return answer;
}

