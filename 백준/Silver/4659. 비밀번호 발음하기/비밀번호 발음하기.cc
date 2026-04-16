#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    string input;
    bool temp = false;
    
    while(true){
        cin >> input;
        if(input == "end") break;
        
        // 조건 1 검사
        for(int i=0; i<input.size(); i++){
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
                temp = true;
                break;
            }
        }
        if(temp == false){
            cout << "<" << input << "> is not acceptable." << endl;
            continue;
        }
        
        // 조건 2 검사
        int ja = 0, mo = 0;
        char last = input[0];
        temp = false;
        if(last == 'a' || last == 'e' || last == 'i' || last =='o' || last == 'u'){
            ja++;
        }
        else{
            mo++;
        }
        for(int i=1; i<input.size(); i++){
            // 자음이 들어온 경우
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'){
                // 자음 연속
                mo = 0;
                if(last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u'){
                    ja++;
                    if(ja == 3){
                        cout << "<" << input << "> is not acceptable." << endl;
                        temp = true;
                        break;
                    }
                    last = input[i];
                }
                
                
                // 이전에는 모음인데, 이번엔 자음이 들어옴
                else{
                    ja=1;
                    last = input[i];
                }
            }
            else{ // 모음이 들어온 경우
                ja = 0;
                // 이전엔 자음인데 모음이 들어옴
                if(last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u'){
                    mo=1;
                    last = input[i];
                }
                else{ // 모음 두번 연속으로들어옴
                    mo++;
                    if(mo == 3){
                        cout << "<" << input << "> is not acceptable." << endl;
                        temp = true;
                        break;
                    }
                    last = input[i];
                }
            }
        }
        if(temp == true) continue;
        
        // 조건 3 검사
        temp = false;
        for(int i=1; i<input.size(); i++){
            if(input[i] == 'e' || input[i] == 'o') continue;
            if(input[i] == input[i-1]){
                cout << "<" << input << "> is not acceptable." << endl;
                temp = true;
                break;
            }
        }
        if(temp == true) continue;
        
        // 모두 통과
        cout << "<" << input << "> is acceptable." << endl;
    }
    
    
    return 0;
}
