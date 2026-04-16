#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int, int>> meeting(n); // <끝 시간, 시작 시간>  !!!
    
    for(int i=0; i<n; i++){
        cin >> meeting[i].second >> meeting[i].first;
    }
    
    sort(meeting.begin(), meeting.end()); // 끝나는 시간으로 오름차순 sort
    
    
    int count = 0;
    int temp_endtime = 0; // 임시 회의 끝나는 시간 (현재 회의가 끝나는 시간)
    
    for(int i=0; i<n; i++){
        if(meeting[i].second >= temp_endtime){
            // 현재 순회하고 있는 미팅의 시작 시간이, 이전 미팅이 끝나는 시간보다 크거나 같다면
            temp_endtime = meeting[i].first; // 임시 회의 끝나는 시간 갱신
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}
