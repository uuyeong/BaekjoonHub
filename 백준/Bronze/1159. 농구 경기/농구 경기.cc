#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    string name;
    int nach[26];
    for(int i=0;i<26;i++){
        nach[i]=0;
    }
    
    for(int i=0;i<n;i++){
        cin>>name;
        nach[name[0]-97]++;
    }
    
    int temp =0;
    
    for(int i=0;i<26;i++){
        if(nach[i]>=5){
            cout<<(char)(i+97);
            temp = 1;
        }
    }
    
    if(temp==0) cout<<"PREDAJA"<<endl;
    else cout<<endl;
    
    return 0;

}
