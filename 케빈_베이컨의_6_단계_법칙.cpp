#include<iostream>
using namespace std;

int arr[102][102];

void solve(void) {
    int N,M;
    cin >> N >> M;

    for(int i = 1;i<=N;i++) {
        for(int j = 1;j<=N;j++) {
            arr[i][j] = 1000; //충분히 큰수
        }
    }
    for(int i = 0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }

    for(int k = 1;k<=N;k++) {
        for(int i = 1;i<=N;i++) {
            for(int j = 1;j<=N;j++) {
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }   
    }
    int minIdx;
    int minNum=1000;
    for(int i = N;i>=1;i--) {
        int sum = -1000; //자기자신의경우를 미리 뺴줌
        for(int j = 1;j<=N;j++) {
            sum += arr[i][j];
        }
        if(sum <= minNum) {
            minNum = sum;
            minIdx = i;
        }
    }
    cout << minIdx;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << "debug";
    // cout.flush();

    solve();
    return 0;
}