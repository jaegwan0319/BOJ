#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//전역변수
int N;
int arr[501][501];
int dp[501][501];

void solve(void) {
    cin >> N;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<=i;j++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for(int i = 1;i<N;i++) {
        for(int j = 0;j<=i;j++) {
            if(j==0) {
                dp[i][j] = arr[i][j] + dp[i-1][j];
            }
            else if(j==i) {
                dp[i][j] = arr[i][j] + dp[i-1][j-1];
            }
            else {
                dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0;i<N;i++) {
        ans = max(ans, dp[N-1][i]); 
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}