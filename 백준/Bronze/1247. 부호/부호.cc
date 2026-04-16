#include <iostream>
using namespace std;

int main(){
    
    for(int j=0;j<3;j++){
        int n;
        long long sum = 0, flow =0;
        cin >> n ;
    
        for(int i = 0;i<n;i++){
            long long a;
            cin>>a;
            long long prev = sum;
            sum=sum+a;
            if(prev>0&&a>0&&sum<0) flow++;
            if(prev<0&&a<0&&sum>0) flow--;
        }
        
        if(flow==0){
            if(sum==0) cout<<'0'<<endl;
            else cout<<(sum>0 ?'+':'-')<<endl;
        }
        else cout<<(flow>0?'+':'-')<<endl;   
    }
    return 0;
    
    
}