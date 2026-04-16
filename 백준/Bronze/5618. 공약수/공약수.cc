#include <iostream>

using namespace std;


int main(){
    int n;
    int s1=0, s2=0, s3=0;
    
    cin >> n;
    
    if(n==2){
        cin >> s1 >> s2;
        if(s2 < s1) swap(s1, s2); // 무조건 s1 <= s2
        for(int i=1; i<=s1; i++){
            if(s1%i == 0 && s2%i == 0) cout << i << endl;
        }
    }
    else if(n==3){
        cin >> s1 >> s2 >> s3;
        if(s2 < s1) swap(s1, s2);
        if(s3 < s2) swap(s2, s3);
        if(s3 < s1) swap(s1, s3);
        // 무조건 s1 <= s2 <= s3
        
        for(int i=1; i<=s1; i++){
            if(s1%i == 0 && s2%i == 0 && s3%i == 0) cout << i << endl;
        }
    }
    
    
    
    
    return 0;
}
