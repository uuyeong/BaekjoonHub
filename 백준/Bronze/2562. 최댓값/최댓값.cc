#include <iostream>
using namespace std;

int main(){
    int arr[9];
    for(int i=0;i<9;i++){
        cin>>arr[i];
    }
    int big=0, big_index=0;
    for(int i=0;i<9;i++){
        if(big<arr[i]){
            big = arr[i];
            big_index = i+1;
        }
    }
    cout<<big<<endl<<big_index<<endl;
    return 0;
}
