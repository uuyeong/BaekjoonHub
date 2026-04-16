#include <iostream>
#include <string>
using namespace std;

int main() {
string color[10] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
string in[3];
int num[3];
long long out=0;

cin >> in[0]>>in[1]>>in[2];

for(int i=0;i<3;i++){
for(int j=0;j<10;j++){
if (in[i]==color[j]){
num[i] = j;
}
}
}

out = 10*num[0] + num[1];

for(int i=0;i<num[2];i++){
out = 10*out;
}
 cout<<out<<endl;

return 0;   

}
