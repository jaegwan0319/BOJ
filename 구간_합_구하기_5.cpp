#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수
int N,M;
int arr[1025][1025];
int dp[1025][1025];

void solve(void) {
    cin >> N >> M;
    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=N;j++) {
            cin >> dp[i][j];
            arr[i][j] = dp[i][j];
        }
    }
    for(int j = 2;j<=N;j++) {
        dp[1][j] = dp[1][j] + dp[1][j-1];
    }
    for(int i = 2;i<=N;i++) {
        dp[i][1] = dp[i][1] + dp[i-1][1];
    }
    for(int i = 2;i<=N;i++) {
        for(int j = 2;j<=N;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i][j] - dp[i-1][j-1];
        }
    }

    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=N;j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    while(M--) {
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result;
        result = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        cout << result << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}