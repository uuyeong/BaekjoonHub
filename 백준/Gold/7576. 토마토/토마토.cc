#include <iostream>
#include <vector>
#include <queue> // 토마토들이 동시에 익어야 하므로
#include <algorithm>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int day = 0;
int m, n; //n:행, m:열


void bfs(vector<vector <int>> &tomato, vector<vector <int>> &dist, pair<int, int> &curr, queue<pair<int,int>> &q){
    
    
    for(int i=0;i<4;i++){
        int nx = dx[i] + curr.first;
        int ny = dy[i] + curr.second;
        if( 0 <= nx && nx < n && 0<= ny && ny < m){
            if(tomato[nx][ny] == 0 && dist[nx][ny] == -1){ // 아직 익지 않은, 미방문 상태의 토마토라면
                dist[nx][ny] = dist[curr.first][curr.second] + 1;
                if(dist[nx][ny] > day) day = dist[nx][ny];
                tomato[nx][ny] = 1;
                q.push({nx, ny}); // 새로 익었으므로 큐에 넣는다.
            }
        }
            
    }
    
}




int main(){
    
    cin >> m >> n;
    vector<vector<int>> tomato(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
        //0: 시작부터 익은 토마토
        //-1: 미방문
        //else: 며칠 후에 익었는지 (거리)
    
    queue<pair<int, int>> q; //익은 토마토의 위치를 저장

    
    //입력 받기 (-1:토마토 없음 0:안익음 1:익음)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) { // 익은 토마토는 queue에 그 위치를 {x, y}쌍으로 넣어둔다. dist도 미리 0으로 초기화
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    
    
    while(!q.empty()){ // 익은 토마토 대기열이 비기 전까지 계속 돈다
        pair<int, int> curr = q.front(); // curr : 익은 토마토인데 아직 주변으로 전파하지 않은 토마토를 의미
        q.pop();
        bfs(tomato, dist, curr, q);
        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] == -1 && tomato[i][j] == 0){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<day<<endl;
    
    
    return 0;
}
