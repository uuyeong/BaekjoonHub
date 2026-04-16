#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int T;
    cin>>T;
    
    
    for(int i=0;i<T;i++){
        
        int n, m, out=1, tmp=1;
        cin>>n>>m;
        
        for(int j=m;j>m-n;--j){
            out *= j;
            out = out / tmp++;
        }
        cout<<out<<endl;
    }

    return 0;

}
