#include <iostream>
using namespace std;

int main(){

int arr[5];
for(int i=0;i<5;i++){  
cin>>arr[i];
}

int x=0;
int n;

while(n<3){
n=0;
x++;
for(int i=0;i<5;i++){
if(x%arr[i]==0){  
n++;
}
}
}
cout<<x<<endl;

return 0;

}