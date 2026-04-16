#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<double> building; // 나중에 기울기 계산을 위해 실수형으로 선언


bool check(int now_building, int look_building){
    
    if(now_building == look_building) return false;
    
    double now_height = building[now_building];
    double look_height = building[look_building];
    
    if(now_building > look_building) swap(now_building, look_building); // 검사하는 방향을 통일
    
    double slope = (look_height - now_height) / (look_building - now_building);
    
    for(int i=now_building+1; i<look_building; i++){
        double line = slope * (i - now_building) + now_height;
        if(building[i] >= line ) return false;
    }
    
    
    return true;
}


int main(){
    
    cin >> n;
    
    building.resize(n);
    
    vector<vector<int>> look(n, vector<int>(n, -1));
        // -1 : 검사 x
        // 0 : 안보임
        // 1 : 보임
    
    
    int max_count = 0;
    
    // 입력
    for(int i=0; i<n; i++){
        cin >> building[i];
    }
   
    
    // 빌딩끼리 서로 보이는지 아닌지 결과 정리 (완전 탐색)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==i) continue;
            if(look[i][j] != -1) continue; // 이미 채워진 칸이므로
            
            if(check(i, j)) { // 서로 보이면
                look[i][j] = 1;
                look[j][i] = 1;
            }
            else{
                look[i][j] = 0;
                look[j][i] = 0;
                
            }
        }
    }
    
    
    for(int i=0; i<n; i++){
        int count = 0; // 매 빌딩마다 초기화 !!
        for(int j=0; j<n; j++){
            if( look[i][j] == 1) count++;
        }
        max_count = max(max_count, count);
    }
    
    cout<<max_count<<endl;
    
    return 0;
}
