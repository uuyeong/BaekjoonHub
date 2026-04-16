#include <iostream>
using namespace std;

int main(){

int x,y,w,h;
int arr[4];
cin>>x>>y>>w>>h;

arr[0] = x;
arr[1] = h-y;
arr[2] = w-x;
arr[3] = y;

int small =1001;
for(int i=0;i<4;i++){
if(small>arr[i]){
small = arr[i];
}
}
cout << small <<endl;

}