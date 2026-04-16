#include <iostream>
#include <string>
using namespace std;

int main(){
    int t, num;
    string arr;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>num>>arr;
        for(int j=0;j<arr.length();j++){
            for(int k=0;k<num;k++){
                cout<<arr[j];
            }
        }
        cout<<endl;
    }
    return 0;
}
