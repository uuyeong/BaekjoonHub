#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> result;
    
    // a와 b는 정렬되어있다
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    
    
    int p1 = 0, p2 = 0;
    
    while(p1 < n && p2 < m){
        if(a[p1] < b[p2]){
            result.push_back(a[p1]);
            p1++;
        }
        else{
            result.push_back(b[p2]);
            p2++;
        }
    }

    
    while(p1 < n){
        result.push_back(a[p1]);
        p1++;
    }
    while(p2 < m){
        result.push_back(b[p2]);
        p2++;
    }
    
    for(int i=0; i<result.size(); i++){
        cout << result[i] <<' ';
    }
    cout << '\n';
    return 0;
}
