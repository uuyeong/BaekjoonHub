#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c=0;
    if(!(cin>>n))return -1;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // 합이 a[i]인 것을 찾자
    for(int i=0; i<n; i++){
        
        bool flag = false;
        int start = 0, end = n-1; // 투포인터
        while(start < end){
            if(start == i){
                start++;
                continue;
            }
            if(end == i){
                end--;
                continue;
            }
            
            /*
            if(a[start] >= 0 && i < end){ // start, end가 0 이상이면 검사하려는 a[i]가 무조건 a[end]보다 커야 한다.
                continue;
            }
            if(a[end] < 0 && i > start) continue; // 마찬가지로 start, end가 0 미만이면 검사하려는 a[i]는 무조건 a[start]보다 작아야 한다.
            if(a[start] == a[end] && (a[start]+a[end]) != a[i]) break;
            */
            if( (a[start] + a[end]) < a[i] ) start++;
            else if ( (a[start] + a[end]) > a[i] ) end--;
            else{
                flag = true;
                break;
            }
        }
        
        if(flag) c++;
    }

    cout << c << endl;
    
    return 0;
}
