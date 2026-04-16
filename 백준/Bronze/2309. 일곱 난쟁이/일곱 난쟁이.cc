#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> n(9);
    int sum=0;
    
    for(int i=0; i<9; i++){
        cin >> n[i];
        sum += n[i];
    }
    
    sort(n.begin(), n.end());
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if( i==j )continue;
            if((sum - n[i] - n[j]) == 100){
                for(int k=0; k<9; k++){
                    if(k==i || k==j)continue;
                    cout << n[k] << '\n';
                }
                return 0;

            }
        }
    }
    
    
    
    return 0;
}
