#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 사이클인지 아닌지 확인하기 위해 최종 부모 섬을 확인하는 함수
int Return_Parents(vector<int> & parents, int x){ // x는 부모를 찾는 섬을 의미
    while(parents[x] != x){
        x = parents[x];
    }
    
    return x;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<bool> visited(n);
    vector<int> parents(n);
    
    // costs 오름차순 정렬
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });   
    
    // 각 섬들의 부모를 자기 자신으로 초기화
    for(int i=0; i<n; i++){
        parents[i] = i;
    }
    
    // 이제 다리를 하나하나 연결하며 확인
    for(vector<int> i : costs){
        int s1 = i[0];
        int s2 = i[1];
        int cost = i[2];
        
        int s1_p = Return_Parents(parents, s1);
        int s2_p = Return_Parents(parents, s2);
        
        if( s1_p != s2_p ){
            // 사이클이 아니면 (부모가 다르면)
            answer += cost; // cost 더하기
            
            // 서로 부모 자식 관계로 연결 (인덱스가 작은게 부모)
            if(s1_p > s2_p) parents[s1_p] = s2_p;
            else parents[s2_p] = s1_p;
        }   
    }
    
    
    return answer;
}