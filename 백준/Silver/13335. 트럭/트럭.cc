#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int n, w, L;
    int time=0;
    
    cin >> n >> w >> L;
    vector<int> truck(n); // 트럭 무게 저장
    queue<int> bridge; // 다리의 상태
    // 0 : 다리가 비어있음
    
    for(int i=0; i<n; i++){
        cin >> truck[i];
    }
    
    for(int i=0; i<w; i++){
        bridge.push(0);
    }
    
    int weight = 0; // 임시 다리 위 트럭 무게 합
    int next_truck = 0; // 다음에 올라올 트럭의 인덱스
    
    while(next_truck < n){
        
        time++;
        weight -= bridge.front(); // 맨 앞의 트럭 무게를 제거 (트럭이 없으면 0이므로 변화가 없다)
        bridge.pop();
       
        // 새로운 트럭이 다리 위에 올라올 수 있는가? 판단
        if(weight + truck[next_truck] <= L){
            weight += truck[next_truck];
            bridge.push(truck[next_truck]);
            next_truck++;
        }
        else{
            bridge.push(0); // 트럭이 더 못올라오면 0 을 넣는다
        }
    
    }
    
    cout << time + w << endl; // 마지막 트럭이 올라오고, 다리 끝까지 가는 시간 더해줌
    
    return 0;
}
