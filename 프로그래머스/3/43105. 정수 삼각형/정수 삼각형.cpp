#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    // [0][0] -> [1][0] / [1][1] 둘 중 하나
    // [1][0] -> [2][0] / [2][1] 둘 중 하나
    // [1][1] -> [2][1] / [2][2] 둘 중 하나
    // 즉, [이전 행 + 1][이전 열] / [이전 행 + 1][이전 열 + 1] 둘 중 하나를 선택해 이동
    // dp는 그러면 행 기준? 으로 내려가기 or triangle과 같은 크기의 2차원 벡터 선언? 
    // 아니면 triangle 그대로 재사용(효율성 측면)
    
    // 아래에서부터위로 올라가자
    
    
    int r_size = triangle.size();
    // r_size = 5    
    
    for(int r=r_size-2; r>=0; r--){
        // 해당 행의 열 길이
        int c_size = r+1;
        int c = 0;
        
            /*(1회)
            r = 3
            c_size = 4
            c = 0
                (while문)
                c=0, triangle[3][0] = */
        
        
        while(c < c_size){
            triangle[r][c] += max(triangle[r+1][c], triangle[r+1][c+1]);
            c++;
        }
    }
    
    answer = triangle[0][0];
    
    return answer;
}