#include <iostream>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    int x_1, y_1, x_2, y_2, r_1, r_2;
    
    for(int i=0;i<n;i++){
        cin>>x_1>>y_1>>r_1>>x_2>>y_2>>r_2;
        int dis = (x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1);
        int r_plus = (r_1+r_2)*(r_1+r_2);
        int r_min = (r_1-r_2)*(r_1-r_2);
        
        if(dis==0){
            if(r_1==r_2) cout<<-1<<endl;
            else cout<<0<<endl;
        }
        else if(r_min<dis && dis<r_plus) cout<<2<<endl;
        else if(dis == r_plus || dis == r_min) cout<<1<<endl;
        else cout<<0<<endl;
    }

    return 0;

}
