#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int r, c, max_count = -1;
vector<vector<char>> alpha;
vector<vector<bool>> visited;
vector<char> visited_alpha;

int dx[4] = {-1, 1, 0, 0}; // 좌 우 위 아래
int dy[4] = {0, 0, 1, -1};


void backtracking(int y, int x, int count){ // [x, y] : 현재 말의 위치 (x가 열 y가 행이다)
    
    if(visited[y][x]) return;
    
    if( find(visited_alpha.begin(), visited_alpha.end(), alpha[y][x]) == visited_alpha.end()){ // 처음 만나는 알파벳이면
        visited_alpha.push_back(alpha[y][x]);
        count++;
        if(count > max_count) max_count = count;
    }else{ // 이미 만났던 알파벳이면
        return;
    }
    
    
    visited[y][x] = true; // 현재 말 방문 처리
    
    for(int i=0; i<4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x < 0 || next_x >= c || next_y < 0 || next_y >= r) continue; // 범위 체크
        backtracking(next_y, next_x, count); // 백트래킹
    }
    // 되돌리기!
    visited[y][x] = false;
    visited_alpha.pop_back();
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> r >> c;
    
    // vector 크기 재지정 (전역변수라서)
    alpha.resize(r, vector<char>(c));
    visited.resize(r, vector<bool>(c));
    
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> alpha[i][j];
        }
    }
    
    int x = 0, y = 0; // 말의 시작 위치
    int count = 0; // 누적 거리
    
    backtracking(y, x, count);
    
    cout << max_count << endl;
 
    return 0;
}
