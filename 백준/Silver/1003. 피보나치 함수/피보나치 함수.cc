#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        int temp, temp_1=1, temp_2=1;
        if(x==0) cout<<"1 0"<<endl;
        else if(x==1) cout<<"0 1"<<endl;
        else{
            for(int j=0;j<x-2;j++){
                temp = temp_2;
                temp_2 += temp_1;
                temp_1 = temp;
            }
            cout<<temp_1<<" "<<temp_2<<endl;
        }
    }
    return 0;
}