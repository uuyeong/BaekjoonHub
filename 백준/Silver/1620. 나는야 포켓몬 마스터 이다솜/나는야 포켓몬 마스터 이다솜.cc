#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> mon(n+1);
    map<string, int> mon2;
    
    
    for(int i=1; i<=n; i++){
        string temp;
        cin >> temp;
        mon2.insert({temp, i});
        mon[i] = temp;
    }
    
    for(int i=0; i<m; i++){
        string temp;
        cin >> temp;
        if(isdigit(temp[0])){ // 숫자면
            int x = stoi(temp);
            cout << mon[x] << '\n';
        }
        else{ // 문자면
            cout << mon2[temp] << '\n';
        }
        
    }
    
    
    return 0;
}
