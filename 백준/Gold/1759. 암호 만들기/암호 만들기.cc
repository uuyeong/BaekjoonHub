#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;
vector<char> alpha;
vector<char> pass;

// 모음인지 검사
bool ismo(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

void backtracking(int index, int count){
    if(count == l){ // 패스워드 다 채웠다는 뜻
        int ja = 0;
        int mo = 0;
        
        for(int i=0; i<l; i++){
            if(ismo(pass[i])) mo++;
            else ja++;
        }
        if( mo >= 1 && ja >= 2){ // 자음 모음 개수 체크
            for(int i=0; i<l; i++){
                cout << pass[i];
            }
            cout << endl;
        }
        return;
    }
    
    // 패스워드를 아직 채우지 못한 경우
    for(int i=index; i<c ; i++){
        pass.push_back(alpha[i]);
        backtracking(i+1, count+1);
        pass.pop_back();
    }
    
    
}

int main(){
    cin >> l >> c;

    
    for(int i=0; i<c; i++){
        char temp;
        cin >> temp;
        alpha.push_back(temp);
    }
    
    sort(alpha.begin(), alpha.end()); // 오름차순 정렬 (이거 하려고 벡터 사용)
    
    backtracking(0, 0);
    
    
    return 0;
}
