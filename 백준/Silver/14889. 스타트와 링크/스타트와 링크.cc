#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<vector<int>> s;
int min_abs = 1e9;


// team1이 결정되면 team2도 자동으로 결정됨

void backtracking(int idx, vector<int>& t1){ // idx : 현재 사람 인덱스
    
    if(t1.size() == n/2){ // 팀 하나가 완성됨
        vector<int> t2;
        for(int i=0; i<n; i++){
            // t1에 없는 사람은 t2팀에 넣는다.
            if( find(t1.begin(), t1.end(), i) == t1.end()) t2.push_back(i);
        }
        int t1_sum=0, t2_sum=0;
        
        // t1 카운트
        for(int i=0; i<t1.size(); i++){
            for(int j=i+1; j<t1.size(); j++){
                t1_sum += s[t1[i]][t1[j]] + s[t1[j]][t1[i]];
            }
        }
        
        // t2 카운트
        for(int i=0; i<t2.size(); i++){
            for(int j=i+1; j<t2.size(); j++){
                t2_sum += s[t2[i]][t2[j]] + s[t2[j]][t2[i]];
            }
        }
        
        // 더 작은 값으로 min_abs 업데이트
        min_abs = min(min_abs, abs(t1_sum - t2_sum));
        
        return;
    }
    
    if(idx == n) return; // 사람을 다 돌았는데 팀이 미완성인 경우
    
    /*
    if(visited[idx]) return;
    visited[idx] = true;
     
    이 문제에는 visited 필요 x
    뒤로 돌아가야 하는 순열과는 달리
    조합은 앞으로만 나아가면 되기에 visited가 필요 없다.
    */
    
    t1.push_back(idx);
    backtracking(idx+1, t1); // idx사람을 t1팀으로 선택하는 갈래
    t1.pop_back();
    
    backtracking(idx+1, t1); // idx사람을 t1팀으로 선택하지 않는 갈래
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    s.assign(n, vector<int>(n));
    vector<int> team1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    
    team1.push_back(0);
    backtracking(1, team1);
    
    
    cout << min_abs << endl;
    
    return 0;
}
