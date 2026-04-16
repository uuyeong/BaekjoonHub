#include <iostream>

using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    int arr[100];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

    }
    
    cout << arr[0]*arr[n-1] << endl;
    return 0;


}