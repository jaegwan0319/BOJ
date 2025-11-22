#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int stair[305];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1;i<=N;i++){
        int temp;
        cin >> temp;
        stair[i] = temp;
    }
    int dp[500];
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for(int i = 4;i<=N;i++){
        dp[i] = max(dp[i-3] + stair[i-1], dp[i-2]) + stair[i];
    }
    cout << dp[N];
}