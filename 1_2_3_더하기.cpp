#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    int dp[10000];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4;i<=N;i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    cout << dp[N];
    return 0;
}