#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque<int> q;
int c = 0;

void move_left(){
    int temp = q.front();
    q.pop_front();
    q.push_back(temp);
    c++;
}

void move_right(){
    int temp = q.back();
    q.pop_back();
    q.push_front(temp);
    c++;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        q.push_back(i);
    }
    
    
    int calculate;
    
    for(int i=0; i<m; i++){
        cin >> calculate;
        int idx = 0;
        for(int j=0; j<q.size(); j++){
            if( q[j] == calculate ) {
                idx = j;
                break;
            }
        }
        if(idx < q.size() / 2 + 1){
            while(! (q.front() == calculate)) move_left();
        }
        else{
            while(! (q.front() == calculate)) move_right();
        }
        
        
        // 해당 원소를 찾았으니 pop
        q.pop_front();
    }
    
    
    cout << c << endl;
    
    
    return 0;
}
