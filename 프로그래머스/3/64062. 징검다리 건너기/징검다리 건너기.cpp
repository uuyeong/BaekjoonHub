#include <string>
#include <vector>

using namespace std;

bool func(vector<int> stones, int now, int k){    
    int count = 0;
    
    for(int i : stones){
        if(i < now){
            count++;
            if(count >= k) return false;
        }
        else count = 0;
    }
    
    return true;
}


int solution(vector<int> stones, int k) {    
    // 이분탐색을 쓴다면.. 건널 수 있는 최대 사람 수를 n으로 잡고?
    // 가장 큰 stones 원소 값이 최대 사람 수가 될듯?? (n최대값)
    // n명이 건넌다면.. 배열의 모든 칸수에서 -n을 하고 (이 때 음수가 되면 안됨)
    // 그 경우에 연속된 0칸이 k를 초과하면 n명에서 왼쪽 이분탐색
    // 레츠기릿
    int answer = 0;
    int right = 0;
    int left = 0;
    // stones중에서 가장 큰 원소 값을 right에 저장
    
    for(int i: stones){
        if(i>right) right=i;
    }
    
    int now;
    // 이분탐색
    while(left <= right){
        now = (left + right) / 2;
        
        // 만약 now명이 다리를 모두 건널 수 있다면 (오른쪽 선택)
        if(func(stones, now, k)){
            answer = now;
            left = now+1;
        }
        
        // 만약 now명이 다리를 건널 수 없다면 (왼쪽 선택)
        else{
            right = now-1;
        }

    }
    
    
    return answer;
}