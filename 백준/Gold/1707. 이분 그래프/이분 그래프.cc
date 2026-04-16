#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[20010]; //벡터 생성 후 0으로 초기화
int color[20010]; //이분 그래프 판단을 위해. 1, 2로 구분 (0은 초기화x)
// visited의 역할도 겸한다. 0이면 방문x, 1 or 2면 방문


bool dfs(int start, int c){
    color[start] = c; //현재 노드 색칠(+ 방문 표시)

    for(int i = 0; i < adj[start].size();i++){
        int next = adj[start][i];
        if(color[next] == 0) { //방문하지 않았다면
            if( !(dfs(next, 3-c))) return false; //어차피 c는 현재 1 or 2 이므로
                // 하위 dfs결과 false가 나오면 바로 false 반환
        }
        else{ // 이미 방문한 노드를 만날 경우, 색깔 검증을 해야 함
            if(c == color[next]) return false;
        }
    }

    return true;
}



void twograph(int v, int e){
    int n1, n2;
    bool result = true;
    
    
    //초기화
    for(int i=1; i <= v; i++){
        adj[i].clear();
        color[i] = 0;
    }
    
    for(int i = 0; i < e; i++){
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for(int i = 1; i <= v ; i++){
        if(color[i] == 0){
            if(!dfs(i, 1)){
                result = false;
                break;
            }
        }
    }
    if(result == true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}




int main(){
    int k;
    if (!(cin >> k)) return 0;
    int v, e;

    for(int i=0;i<k;i++){
        cin >> v >> e;
        twograph(v,e);
    }

    return 0;
}
