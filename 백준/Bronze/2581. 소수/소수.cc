#include <iostream>

using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    
    for(int i=3; i*i<= n; i+=2){
        if(n%i == 0) return false;
    }
    
    return true;
}


int main(){
    int m, n;
    int sum = 0, min = 100001;
    
    cin >> m;
    cin >> n;
    
    for(int i=m; i<=n; i++){
        if(isPrime(i)){
            sum += i;
            if(i < min) min = i;
        }
    }
    
    if(sum == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << sum << endl << min << endl;
    
    return 0;
}
