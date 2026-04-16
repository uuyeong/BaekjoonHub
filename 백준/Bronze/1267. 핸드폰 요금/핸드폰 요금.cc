#include <iostream>
using namespace std;

int main(){

int n;
int temp;
int m=0, y=0;
cin>>n;
for(int i=0;i<n;i++){
cin>>temp;
m += (temp/60+1)*15;
y += (temp/30+1)*10;   
}

if(m<y){
cout<<'M'<<' '<<m<<endl;
}
else if ( m==y){
cout<<'Y'<<' '<<'M'<<' '<<m<<endl;
}
else {
cout<<'Y'<<' '<<y<<endl;
}

return 0;

}

