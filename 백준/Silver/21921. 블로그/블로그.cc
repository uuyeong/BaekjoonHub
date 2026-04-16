#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> day(n);
    int period = 1, sum = 0;
    
    for(int i=0; i<n; i++){
        cin >> day[i];
    }
    
    
    
    int start = 0, end = x-1; // 투포인터(인덱스)
    
    for(int i=start; i<=end; i++){
        sum+=day[i];
    }
    
    int max = sum;
    
    while(end < n-1){
        sum-=day[start];
        start++;
        end++;
        sum+=day[end];
        if(sum > max){
            max = sum;
            period = 1;
        }
        else if(sum == max) period++;
    }
    
    if(max == 0){
        cout << "SAD" << endl;
        return 0;
    }
    cout << max << endl << period << endl;
    
    return 0;
}
