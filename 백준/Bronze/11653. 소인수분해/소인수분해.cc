#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    while(n%2==0){
        n /= 2;
        cout << 2 << endl;
    }
    for(int i=3; i<=n; i++){
        while(n%i == 0){
            n /= i;
            cout << i << endl;
        }
    }
    
    return 0;
}
