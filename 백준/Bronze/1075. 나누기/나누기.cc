#include <iostream>
using namespace std;

int main(){
    int num, x;
    cin >> num;
    cin >> x;
    
    num = num - num%100;
    
    while(num%x != 0){
        num++;
    }
    
    cout.width(2);
    cout.fill('0');
    cout << num%100 <<endl;
    return 0;

}