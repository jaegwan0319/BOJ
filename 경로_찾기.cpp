#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 20060319

typedef pair<int,int> pa;
int N;
int arr[101][101];

void solve(void) {
    cin >> N;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            int temp;
            cin >> temp;
            if(i==j) {
                arr[i][j] = INF;
            }
            else if(temp == 0) {
                arr[i][j] = INF;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }

    for(int k = 0;k<N;k++) {
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(arr[i][j] != INF) {
                cout << 1 << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}