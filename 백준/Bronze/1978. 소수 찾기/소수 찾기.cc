#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, count = 0;
    cin >> n;
    
    int input[n];
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    for(int i=0; i<n; i++){
        if(input[i] < 2) continue;
        if(input[i] == 2){
            count++;
            continue;
        }
        if(input[i] % 2 == 0) continue;
        
        bool isPrime = true;
        for(int j=3; j*j <= input[i]; j+=2){
            if(input[i] % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) count++;
        
    }
    
    cout << count << endl;
    
    
    
    return 0;
}
