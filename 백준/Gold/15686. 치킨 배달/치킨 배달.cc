#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M;

vector<vector<int>> input;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> picked_chicken; // 선택된 치킨집 (백트래킹을 위한.. 살려둘 치킨집들 저장)

int result = 99999999;


int calculate_distance(pair<int, int> &h, pair<int, int> &p){
    return(abs(h.first - p.first)+abs(h.second - p.second));
}

void solve(int idx, int cnt){ // idx: 몇번째 치킨집부터 고려할 것인가 cnt: 현재 치킨집을 몇개까지 세었는가
    if(cnt == M){ // 치킨집 M개가 모두 선택되었다면 -> "도시의 치킨 거리" 계산
        int current_city_dist = 0;
        
        for(auto h : home){
            int home_dist = 99999999;
            for(auto p : picked_chicken){
                home_dist = min(home_dist, calculate_distance(h, p));
            }
            current_city_dist += home_dist;
        }
        result = min(result, current_city_dist);
        return;
    }
    
    for(int i=idx; i < chicken.size(); i++){
        picked_chicken.push_back(chicken[i]);
        solve(i+1, cnt+1);
        picked_chicken.pop_back();
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    
    input.assign(N, vector<int>(N));
    
    // 입력
    for(int i=0; i<N; i++){
        for(int j=0;j<N; j++){
            cin >> input[i][j];
            if(input[i][j] == 1) home.push_back({i, j});
            if(input[i][j] == 2) chicken.push_back({i, j});
        }
    }
    
    solve(0,0);
    
    cout << result << endl;
    
    
    return 0;
}
