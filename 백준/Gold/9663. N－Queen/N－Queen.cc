#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
int cnt=0;
vector<int> arr;


void solve(int row){ // row:
    if(row == N){
        cnt++;
        return;
    }
    
    for (int i = 0; i < N; i++) {
            arr[row] = i; // 현재 행(row)의 i번째 열에 퀸을 놓아봄
            
            bool is_safe = true;
            // 검사
            for (int j = 0; j < row; j++) {
                // 1. 같은 열에 있는지 확인
                // 2. 대각선에 있는지 확인
                if (arr[row] == arr[j] || abs(arr[row] - arr[j]) == abs(row - j)) {
                    is_safe = false;
                    break; // 하나라도 걸리면 더 볼 필요 없음
                }
            }
            
            // 안전하다면 다음 행으로 진행
            if (is_safe) {
                solve(row + 1);
            }
        }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    arr.resize(N);
    // 모든 행마다 퀸이 있어야 한다. (모든 행마다 없으면 한 행에 퀸이 2개 이상 생겨야 하는데, 이는 규칙 위반)
    solve(0); // 0번 행부터 시작
        
    cout << cnt << endl;
    
    return 0;
}
