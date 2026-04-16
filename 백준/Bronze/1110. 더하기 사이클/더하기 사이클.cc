#include <iostream>
using namespace std;

int main(){
    int x,y;
    int n=0;
    cin>>y;
    x = y;
    
    do {
        y = (y % 10) * 10 + (y / 10 + y % 10) % 10;
        n++;
    } while (x != y);
    
    cout<<n<<endl;
    return 0;
    
}