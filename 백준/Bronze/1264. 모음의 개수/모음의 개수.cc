#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(1){
        int cnt = 0;
        getline(cin, s);
        for(int i=0; i<s.length(); i++){
            s[i] = tolower(s[i]); 
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
               cnt++;
        }
        if(s == "#") break;
        cout << cnt << '\n';
    }
    return 0;
}
