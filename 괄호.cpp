#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solution(void){
    string s;
    int right_round =0, left_round =0;
    cin >> s;
    for(int i = 0;i<s.length();i++){
        if (s[i] == '(') left_round++;
        else if(s[i] == ')') right_round++;
        if(left_round < right_round){
            cout << "NO" << "\n";
            return;    
        }
    }
    if( right_round != left_round ){
        cout << "NO" << "\n";
        return;
    }
    else{
        cout << "YES" << "\n";
        return;
    }
    // int temp_left=0,temp_right=0;
    // for(int i = 0;i<s.length();i++){

    // }
}

int main(void){
    int T;
    cin >> T;
    while(T--){
        solution();
    }
}