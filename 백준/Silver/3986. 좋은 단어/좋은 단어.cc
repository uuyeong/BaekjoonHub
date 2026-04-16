#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, count=0;
    cin >> n;
    
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        vector<char> stack;
        
        for(char c : word){
            if( !stack.empty() && stack.back() == c){
                stack.pop_back();
            }
            else{
                stack.push_back(c);
            }
        }
        
        if(stack.empty()) count++;
 
    }
    
    cout << count << '\n';
    
    return 0;
}
