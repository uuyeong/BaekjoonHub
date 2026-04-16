#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    
    string input;
    deque<int> count;
    int temp = 0;
    
    cin >> input;
    
    
    // 입력 정리
    for(int i=0; i<input.size();i++){
        if(input[i] == 'X'){
            temp++;
        }
        else{
            if(temp > 0) count.push_back(temp);
            count.push_back(-1);
            temp = 0;
        }
    }
    if(temp > 0) count.push_back(temp);
    
    
    for(int c : count){
        if(c % 2 == 1){
            cout << -1 << endl;
            return 0;
        }
    }
    
    for(int c : count){
        if(c >= 4){
            int t = c/4;
            for(int i=0; i<t; i++){
                cout << "AAAA";
            }
            if(c%4 != 0){
                cout << "BB";
            }
            
        }
        else if(1<=c && c<4){
            cout << "BB";
        }
        else if(c == -1){
            cout << ".";
        }
    }
    
    cout << endl;
    
    return 0;
}
