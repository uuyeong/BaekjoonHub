#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    // 시간을 먼저 정해둔 뒤, 그 시간 안에 n명을 모두 검사할 수 있는가??
    
    long long start = 1;
    long long end = (long long)times[0] * n; // 한 심사관이 다 할 때 보다는 빨리 끝날 것이므로
    // times[0] 강제 형변환 필요!!
    
    
    while(start <= end){
        long long mid = (start+end)/2; // 중간값
        long long person = 0;

        // mid 분 동안 몇명을 심사할 수 있는가?
        for(int i: times){
            person += (mid/i);
        }
        
        if(person < n){
            // 심사할 수 있는 사람이 n보다 적으면
            start = mid+1; // 피봇(mid)기준 오른쪽 선택
        }
        else {
            // 심사할 수 있는 사람이 n보다 크면
            answer = mid;
            end = mid-1; // 피봇(mid)기준 왼쪽 선택
        }
        
    }
    return answer;
}