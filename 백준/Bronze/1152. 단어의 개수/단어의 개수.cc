#include <iostream>

using namespace std;

int main(){

string str;
getline(cin, str);

int n = 1;

for(int i=0; i<str.length();i++) {
if(str[i]==' ') {
n++;
}
}

if(str[0]==' '){
n--;
}
if(str[str.length()-1]==' '){
n--;
}

cout<<n<<endl;

return 0;

}

