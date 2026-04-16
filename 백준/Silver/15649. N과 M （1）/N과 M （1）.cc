#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<bool> visited(9);

void backtracking(vector<int>& cur){
    if(cur.size() == m){
        // 출력
        for(int c : cur){
            cout << c << ' ';
        }
        cout << '\n';
        return;
    }
    
    
    for(int i=1; i<=n; i++){
        if(visited[i]){ // 이미 방문한 곳이라면
            continue;
        }
        visited[i] = true;
        cur.push_back(i);
        backtracking(cur);
        cur.pop_back();
        visited[i] = false;
        
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    vector<int> cur;

    backtracking(cur);
    
   
    return 0;
}
