#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    vector<int> real_lost;
    vector<bool> visited(reserve.size(), false);    
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 도난당한 학생이 여분을 가진 경우 (먼저 확인)
    for(int i : lost){
        auto it = find(reserve.begin(), reserve.end(), i); 
        if(it != reserve.end()){
            visited[it - reserve.begin()] = true;
            answer++;
        }
        else real_lost.push_back(i);
    }
    
    for(int i : real_lost){
        // 앞 번호 학생에게 빌리기
        auto it1 = find(reserve.begin(), reserve.end(), i - 1); 
        if (it1 != reserve.end() && !visited[it1 - reserve.begin()]) { 
            // 앞 번호 학생이 체육복이 있고 && 다른 학생이 빌려가지 않은 경우
            visited[it1 - reserve.begin()] = true; // 빌려갔다고 표시
            answer++;
        }
        // 뒷 번호 학생에게 빌리기
        else {
            auto it2 = find(reserve.begin(), reserve.end(), i + 1);
            if (it2 != reserve.end() && !visited[it2 - reserve.begin()]) {
                // 뒷 번호 학생이 체육복이 있고 && 다른 학생이 빌려가지 않은 경우
                visited[it2 - reserve.begin()] = true; // 빌려갔다고 표시
                answer++;
            }
        }
    }
    
    return answer;
}