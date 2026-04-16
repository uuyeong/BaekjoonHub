#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    int a_cash, b_cash;
    int a_count = 0, b_count = 0;
    int down = 0, up = 0;
    int juga[15];
    
    cin >> a_cash;
    b_cash = a_cash;
    
    for(int i=0; i<14; i++){
        cin >> juga[i];
    }
    
    for(int i=0; i<14; i++){
        // a의 주식투자
        if(juga[i] == 0){} // 예외처리
        else{
            a_count += int(a_cash / juga[i]);
            a_cash -= (int(a_cash/juga[i]) * juga[i]);
        }
        
        
        
        // b의 투식투자
        if(i==0) continue;
        if(juga[i]>juga[i-1]){ // 상승했다면
            if(down > 0){
                down = 0;
            }
            up++;
            if(up >= 3){ // 전량 매도
                b_cash += (juga[i] * b_count);
                b_count = 0;
            }
        }
        else if(juga[i] == juga[i-1]){ // 그대로라면
            down = 0;
            up = 0;
        }
        else{ // 하락했다면
            if(up > 0){
                up = 0;
            }
            down++;
            if(down >= 3){ // 전량 매수
                b_count += int(b_cash / juga[i]);
                b_cash -= (int(b_cash/juga[i]) * juga[i]);
            }
        }
    }
    int a_result = a_cash + juga[13]*a_count;
    int b_result = b_cash + juga[13]*b_count;
    
    if(a_result > b_result) cout << "BNP" << endl;
    else if(a_result < b_result) cout << "TIMING" << endl;
    else cout << "SAMESAME" << endl;
    
    return 0;
}
