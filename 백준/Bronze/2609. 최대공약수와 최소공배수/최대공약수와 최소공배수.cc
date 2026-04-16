#include <iostream>
#include <cmath>

using namespace std;


int main(){
    long long x, y;
    cin >> x >> y;
    long long max=0, min;
    
    if(y<x) swap(x, y); // 무조건 x <= y
    for(int i=1; i<=x; i++){
        if(x%i == 0 && y%i == 0) max = i;
    }
    long long t = y;
    while(true){
        if(t % x == 0){
            min = t;
            break;
        }
        t += y;
    }
    
    cout << max << endl << min << endl;
    
    return 0;
}
