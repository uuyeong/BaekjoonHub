#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> dist(101, -1); // visited가 아닌 dist (거리)를 저장하여 계층을 센다. (-1: 방문하지 않았다)

void bfs(vector<vector<int>> & relation, queue<int>& q, int p2){
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int next : relation[node]){
            if(dist[next] != -1) continue;
            if(next == p2) {
                dist[p2] = dist[node] + 1;
                return; // 찾았을 때
            }
            
            dist[next] = dist[node] + 1; // 다음 노드의 촌수는 현재 노드 촌수 + 1
            q.push(next);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, p1, p2;
    cin >> n >> p1 >> p2;
    cin >> m;
    vector<vector<int>> relation(n+1); // 관계를 저장 (행의 개수가 n+1개)
    
    for(int i=0; i<m; i++){ // 관계를 정리 ( relation[사람1] = {사람2, 사람3...} )
        int t1, t2;
        cin >> t1 >> t2;
        relation[t1].push_back(t2);
        relation[t2].push_back(t1);
    }
    
    queue<int> q; // queue에 push pop을 통해 찾아가기
    q.push(p1);
    dist[p1] = 0; // 시작지점 촌수는 0
    
    bfs(relation, q, p2);
    
    cout << dist[p2] << endl;
    
    return 0;
}
