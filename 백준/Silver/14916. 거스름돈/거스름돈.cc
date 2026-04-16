#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int count = 0;
    
    cin >> n;
    
    while(n>0){
        if(n%2==0 && n>=10){ // n이 짝수면서 10 이상이면
            n -= 10;
            count += 2;
        }
        else if(n%2==0 && n<10){ // n이 짝수이지만 10보다 작으면
            count += (n/2);
            break;
        }
        else{
            n -= 5;
            if(n<0){
                cout << -1 <<endl;
                return 0;
            }
            count ++;
        }
    }
    
    
    cout << count << endl;
    
    
    return 0;
}
