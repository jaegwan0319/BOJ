#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수
int N;
int arr[2][100001];
int dp[2][100001];

void solve(void) {
    int T;
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0;i<2;i++) {
            for(int j = 0;j<N;j++) {
                cin >> arr[i][j];
            }
        }
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        if(N>1) {
            dp[0][1] = dp[1][0] + arr[0][1];
            dp[1][1] = dp[0][0] + arr[1][1];
        }

        for(int i = 2;i<N;i++) {
            dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        cout << max(dp[0][N-1], dp[1][N-1]) << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}