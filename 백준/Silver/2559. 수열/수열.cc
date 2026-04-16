#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, sum=0, max_sum;
    cin >> n >> k;
    vector<int> temp(n);
    for(int i=0; i<n; i++){
        cin >> temp[i];
    }
    
    int start = 0, end = k-1;
    for(int i=start; i<=end; i++){
        sum += temp[i];
    }
    max_sum = sum;
    
    while(end < n-1){
        sum -= temp[start];
        start++;
        end++;
        sum += temp[end];
    
        if(sum > max_sum) max_sum = sum;
    }
    
    cout << max_sum << endl;
    return 0;
}
