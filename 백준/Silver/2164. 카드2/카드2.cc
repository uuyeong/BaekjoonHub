#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<int> q;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        q.push_back(i);
    }
    
    while(q.size() > 1){
        q.pop_front();
        int temp = q.front();
        q.pop_front();
        q.push_back(temp);
    }
    
    cout << q.front() << endl;
    
    
    
    return 0;
}
