#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool check_tag = false; // 현재 태그 단어인지 아닌지 검사
    
    string tag; // 태그 단어를 임시로 저장하는 변수
    string word; // 일반 단어를 임시로 저장하는 변수
    
    queue<string> result; // 최종적으로 출력할 문장 (queue)
    
    // 입력
    string s;
    getline(cin, s);
    
    
    
    for(int i=0; i<s.length(); i++){
        // 태그 시작 입력받음
        if(s[i] == '<'){
            if(!word.empty()){ // 태그가 시작되었는데 word에 문자들이 남아있는 경우
                reverse(word.begin(), word.end());
                result.push(word);
                word = ""; // word 초기화
            }
            tag.push_back('<');
            check_tag = true;

        }
        
        // 태그 끝 입력받음
        else if(s[i] == '>'){
            tag.push_back('>');
            result.push(tag); // 태그 문장이 끝났으니 태그 문장 그대로 큐에 넣어준다
            tag = ""; // tag 비우기
            check_tag = false;
        }
        
        // 공백 입력받음
        else if(s[i] == ' '){
            if(check_tag){ // 태그 안에 있는 빈칸
                tag.push_back(s[i]);
            }
            else{ // 태그 밖에 있는 빈칸
                if(word.empty()) result.push(" "); // 누적된 word없이 띄어쓰기만 나온 경우
                else{ // 누적된 word가 있는 경우
                    reverse(word.begin(), word.end());
                    result.push(word);
                    result.push(" ");
                    word = ""; // word 초기화
                }
            }
        }
        
        // 일반 문자 입력받음
        else{
            if(check_tag){ // 현재 태그 단어라면
                tag.push_back(s[i]);
            }
            else{ // 현재 일반 단어라면
                word.push_back(s[i]);
            }
            
        }
    }
    if(!word.empty()) {
        reverse(word.begin(), word.end());
        result.push(word);
        
    }// word에 단어가 남은 경우
    
    while(!result.empty()){
        cout<<result.front();
        result.pop();
    }
    
    cout << endl;
    return 0;
}
