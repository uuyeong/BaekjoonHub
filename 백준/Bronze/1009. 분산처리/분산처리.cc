#include <iostream>
using namespace std;

int main(){
    int t,a,b,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        x = 1;
        for(int j=0; j<b; j++){
            x = (x * a)%10;
        }
        if(x==0){
             cout<<"10"<<endl;
        }
        else{
            cout << x << endl;
        }
    }

    return 0;
}