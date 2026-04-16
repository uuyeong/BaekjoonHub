#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    
    for(int i = -999 ; i <= 999 ; i++){
        for (int j = -999; j <= 999 ; j++){
            int h1 = a*i + b*j;
            int h2 = d*i + e*j;
            if(h1 == c && h2 == f){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    
    
    return 0;
}
