#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    string input;
    getline(cin, input);
    int count[26] = {0};
    
    for(int i=0; i<input.size(); i++){ // 대문자 -> 소문자 변경
        if(int(input[i]) < 97){
            input[i] = char(int(input[i]) + 32);
        }
        int index = int(input[i]) - 97;
        count[index]++;
    }
    
    int big = 0; // 인덱스가 저장된다
    for(int i=0; i<26; i++){
        if(count[i] > count[big]) big = i;
    }
    for(int i=0; i<26; i++){
        if( big == i ) continue;
        if( count[big] == count[i]){
            cout << "?" << endl;
            return 0;
        }
    }
  
    cout << char(big+65) << endl;
    
    return 0;
}

