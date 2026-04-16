#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;






int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n;
    cin >> t;

    
    while(t--){
        cin >> n;
        map<string, int> clothes; // 의상 종류, 개수
        for(int i=0; i<n; i++){
            string name, type;
            cin >> name >> type;
            clothes[type] ++;
        }
        
        int result = 1;
        for(auto const& [type, count] : clothes){
            result *= (count+1);
        }
        cout << result-1 << endl;

    }
    
    return 0;
}
