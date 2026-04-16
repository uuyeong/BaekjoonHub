#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, max_len=0;
    cin >> n >> k;
    vector<int> element(n);
    map<int, int> count; // < 원소, 개수 >
    
    for(int i=0; i<n; i++){
        cin >> element[i];
    }
    
    int start = 0;
    for(int end=0; end<n; end++){
        int cur = element[end];
        count[cur]++;
        while(count[cur] > k){
            int temp_start = element[start];
            count[temp_start]--;
            
            start++;
        }
        int cur_len = end - start + 1;
        if(cur_len > max_len) max_len = cur_len;
    }
    
    
    cout << max_len << endl;
    
    
    
    return 0;
}
