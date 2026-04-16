#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<bool>& visited, int cur, int start){
    
    for(int next : graph[cur]){
        if(visited[next]) continue;
        visited[next] = true;
        result[start][next] = 1;
        dfs(graph, result, visited, next, start);
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> graph(n); // 방향 그래프임을 주의하자!
    vector<vector<int>> result(n, vector<int> (n, 0)); // 최종 출력할 행렬

    
    // 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                graph[i].push_back(j); // 방향 그래프이므로 양쪽에 다 저장 x
                // result[i][j] = 1; // 일단 바로 가리키는 것은 1로 채운다.
            }
        }
    }
    
    
    // 끝까지 탐색해야 하므로 dfs 사용
    // 끊어진 그래프가 있을 수도 있으니 for문으로 dfs를 돌린다.
    for(int i=0; i<n; i++){
        vector<bool> visited(n, false); // 매번 초기화 (안하면 다음 노드 탐색 시 막히는 경우가 생김)
        dfs(graph, result, visited, i, i);
    }
    
    for(int i=0; i<n; i++){
        for(int  j=0; j<n; j++){
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    
    
    
    return 0;
}
