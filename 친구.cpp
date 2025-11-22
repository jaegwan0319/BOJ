#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int relation[52][52]; //맞다면 1 아니라면 0

void solve(void) {
    cin >> N;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            char temp;
            cin >> temp;
            if(temp == 'N') {
                relation[i][j] = relation[j][i] = 60;
            }
            else {
                relation[i][j] = relation[j][i] = 1;
            }
        }
    }

    //index 0 부터 N-1까지 
    for(int k = 0;k<N;k++) {
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                relation[i][j] = min(relation[i][j], relation[i][k] + relation[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0;i<N;i++) {
        int sum = 0;
        for(int j = 0;j<N;j++) {
            if(i==j) continue;
            if(relation[i][j] <= 2) {
                sum++;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}