#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int big=arr[0], small=arr[0];
    for(int i=0;i<n;i++){
        if(big<arr[i]) big = arr[i];
        if(small>arr[i]) small = arr[i];
    }
    cout<<small<<" "<<big<<endl;
    return 0;
}