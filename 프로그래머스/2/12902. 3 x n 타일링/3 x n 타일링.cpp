#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n%2==1) return 0; // n이 홀수면 타일을 다 못채움
    
    long long answer = 0;
    int size = n/2; // 홀수 개수 열은 어차피 다 못채우므로
    long long floor[size];
    
    // 열이 2개일 때 방법의 수?    
    floor[0] = 3; // 누워있는게 아래, 위, 가운데에 있는 경우 3개
    
    // floor[1] : 열 4칸 -> (floor[0] * 3) + 2 * (1) = 11
    // floor[2] : 열 6칸 -> (floor[1] * 3) + 2 * (floor[0] + 1) 
    // floor[3] : 열 8칸 -> (floor[2] * 3) + 2 * (floor[1] + floor[0] + 1)
    // floor[4] : 열 10칸 -> (floor[3] * 3) + 2 * (floor[2] + floor[1] + floor[0] + 1)
    long long temp = 1;
    for(int i=1; i<size; i++){ // 열방향으로 진행하며 dp
        floor[i] = ((floor[i-1] * 3) + (2 * temp))%1000000007;    
        temp += floor[i-1];
    }
    
    answer = floor[size-1];
    return answer;
}