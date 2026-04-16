#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    vector<int> stack;
    
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        if(temp == "push"){
            int value;
            cin >> value;
            stack.push_back(value);
        }
        else if(temp == "pop"){
            if(stack.empty()) cout << -1 << endl;
            else{
                cout << stack.back() << endl;
                stack.pop_back();
            }
        }
        else if(temp == "size"){
            cout << stack.size() << endl;
        }
        else if(temp == "empty"){
            cout << stack.empty() << endl;
        }
        else if(temp == "top"){
            if(stack.empty()) cout << -1 << endl;
            else{
                cout << stack.back() << endl;
            }
        }
        else{
            cout << "error" << endl;
            return 0;
        }
    }
    return 0;
}
