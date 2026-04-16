#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int small_index(vector<int> concent, int m){
    int small = concent[0]; // 콘센트 중에서 가장 작은 값 초기화
    int small_idx = 0; // 콘센트 중에서 가장 작은 값을 가진 콘센트의 인덱스
    for(int i=1; i<m; i++){
        if(small > concent[i]) small_idx = i;
    }
    return small_idx;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 0;
    int n, m;

    cin >> n >> m;
    vector<int> charge_time(n); // 충전기별 필요한 시간
    vector<int> concent(m); // 각 콘센트에 현재 누적된 시간

    
    // 충전에 필요한 시간 입력 받기
    for(int i=0; i<n; i++){
        cin >> charge_time[i];
    }
    
    sort(charge_time.begin(), charge_time.end()); // 오름차순 정렬
    
    int idx = 0;
    
    for(int i=n-1; i>=0; i--){
        idx = small_index(concent, m); // 콘센트들 중에서 가장 누적된 시간이 적은 콘센트 인덱스 반환
        concent[idx] += charge_time[i];
    }
    
    
    for(int i=0; i<m; i++){
        if(t < concent[i]) t = concent[i];
    }
    
    cout << t << endl;
    return 0;
}
