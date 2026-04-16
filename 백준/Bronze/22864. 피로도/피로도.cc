#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    
    int a, b, c, m;
    
    int job = 0;
    int tired = 0;
    
    cin >> a >> b >> c >> m;
    
    int work = 0;
    int rest = 0;
    
    while( (work + rest) < 24){
        if((tired+a) <= m) {
            job += b;
            tired += a;
            work++;
        }
        else{
            if(tired - c < 0){
                tired = 0;
                rest ++;
                continue;
            }
            tired -= c;
            rest++;
        }
    }
    
    cout<<job<<endl;
    
    
    return 0;
}
