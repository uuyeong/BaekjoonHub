#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int min_fuel = 1e9;

int path[10][10];

void dfs(int r, int c, int last_dir, int sum){

    if(r == n-1) { // 마지막 행에 도착했으면
        min_fuel = min(min_fuel, sum);
        return;
    }
    

    for(int i=-1; i<=1; i++){
        int next_c = c+i;
        
        if(0<= next_c && next_c < m && i != last_dir){
            dfs(r+1, next_c, i, sum + path[r+1][next_c]);
        }
    }
}


int main(){
        
    cin >> n >> m;
    
    // 입력
    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> path[i][j];
        }
    }
    
    // 탐색
    for(int i=0; i<m; i++){
        dfs(0, i, -2, path[0][i]);
        
    }
    
    cout<<min_fuel<<endl;
    
    return 0;
}
