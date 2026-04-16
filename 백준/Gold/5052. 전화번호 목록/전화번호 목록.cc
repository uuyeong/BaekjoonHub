#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, t;
    vector<string> number; // 나중에 초기화 점검
    string temp;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> t;
        number.clear();
        bool result = false;
        
        // 사전순 정렬?
        for(int i=0; i<t; i++){
            cin >> temp;
            number.push_back(temp);
        }
        sort(number.begin(), number.end());
        
        for(int i=0; i<t-1; i++){
            int size = int(number[i].size());
            if(number[i].substr(0, size) == number[i+1].substr(0, size)){
                result = true;
            }
        }
        if(result){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
    }
    
    return 0;
}

///
///
/// 12345
/// 1234567
/// 12
/// 123456789
///
