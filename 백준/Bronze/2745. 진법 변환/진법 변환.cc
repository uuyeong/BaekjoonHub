#include <iostream>
#include <cmath>

using namespace std;


int main(){
    string n;
    int b, result=0, c;
    cin >> n >> b;
    
    for(int i=0; i < int(n.size()); i++){
        if('A' <= n[i] && n[i] <= 'Z'){
            c = n[i] - 'A' + 10;
        }
        else {
            c = n[i] - '0';
            // cout << "c : " << c << endl;
        }
    
        
        result = result * b + c;
        // cout << b << "^" << t << "*" << c << "=" << result << endl;
    }
    
    cout << result << endl;
    
    
    return 0;
}
