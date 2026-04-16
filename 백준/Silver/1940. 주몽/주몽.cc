#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, c = 0;
    cin >> n >> m;
    
    vector<int> code(n);
    
    for(int i=0; i<n; i++){
        cin >> code[i];
    }
    
    sort(code.begin(), code.end());
    
    int start = 0, end = n-1;
    while(start < end){
        if((code[start] + code[end]) < m){
            start++;
        }
        else if((code[start] + code[end]) > m){
            end--;
        }
        else{
            c++;
            start++;
            end--;
        }
    }
    cout << c <<endl;
    return 0;
}
