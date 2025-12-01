#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int pre[] = {0,0,1,1,2,2};
int nex[] = {1,2,0,2,0,1};
int chosen = -1;

//전역변수 선언
int N;
vector<vector<int>> v;
int dp[1005][3]; //각 RGB의 최솟값 계속 dp로 업데이트

void solve(void) {
    cin >> N;
    int sum = 0;
    for(int i = 0;i<N;i++) {
        vector<int> input(3);
        cin >> input[0] >> input[1] >> input[2];
        v.push_back(input);
    }
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];

    for(int i = 1;i<N;i++) {
        for(int j = 0;j<3;j++) {
            int minimum = 1000005;
            for(int k = 0;k<3;k++) {
                if(j == k) continue;
                if(dp[i-1][k] < minimum) minimum = dp[i-1][k];
                dp[i][j] = minimum + v[i][j];
            }
        }
    }

    int ans = min(min(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}