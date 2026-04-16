#include <iostream>
#include <string>

using namespace std;

int main() {
    
    size_t n;
    cin>>n;
    
    string arr[n];
    string out;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    size_t length = arr[0].length();
    out.resize(length);
    
    for(int i=0;i<length;i++){
        char temp = arr[0][i];
        for(int j=1;j<n;j++){
            if(arr[j][i]!=temp){
                out[i]='?';
                break;
            }
        }
        if(out[i]!='?'){
            out[i]=temp;
        }
        
    }
    
    cout<<out<<endl;
    
    return 0;
    
}
