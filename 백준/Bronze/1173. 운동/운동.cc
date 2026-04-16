#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int N, m, M, T, R;
    int ex_time=0;
    int all_time=0;
    cin>>N>>m>>M>>T>>R;
    
    if(m+T>M){
        cout<<-1<<endl;
        return 0;
    }
    
    int x=m;
    
    while(ex_time<N){
        if(x+T<=M){
            x+=T;
            ex_time ++;
            all_time ++;
        }
        else{
            x-=R;
            all_time++;
            if(x<m) x=m;
        }
    }
    
    cout<<all_time<<endl;

    return 0;

}
