#include <iostream>
using namespace std;

int main(){


char chess[8][8];
int white = 0;

for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
cin >> chess[i][j] ;
}
}

for(int i=0;i<=6;i+=2){
for (int j=0;j<=6;j+=2){
if (chess[i][j]=='F'){
white ++;
}
}
}

for(int i=1;i<=7;i+=2){
for (int j=1;j<=7;j+=2){
if (chess[i][j]=='F'){
white ++;
}
}
}

cout<<white<<endl;

return 0;


}