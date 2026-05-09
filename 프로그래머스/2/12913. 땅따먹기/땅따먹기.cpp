#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int r = land.size(); // land배열 행 개수
    //vector<vector<int>> dp;
    //dp = land; // dp초기화
        
    for(int i=1; i<r; i++){
        land[i][0] += max({land[i-1][1], land[i-1][2], land[i-1][3]}); 
        land[i][1] += max({land[i-1][0], land[i-1][2], land[i-1][3]}); 
        land[i][2] += max({land[i-1][0], land[i-1][1], land[i-1][3]}); 
        land[i][3] += max({land[i-1][0], land[i-1][1], land[i-1][2]}); 
    }
    answer = max({land[r-1][0], land[r-1][1], land[r-1][2], land[r-1][3]});
    return answer;
}