#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수 선언
int A[1005];
int length[1005];
vector<int> v[1005];

void solve(void) {
    int N;
    cin >> N;
    for(int i = 0;i<N;i++) {
        cin >> A[i];
    }

    length[0] = 1;
    for(int i = 1;i<N;i++) {
        int maxLen = 0;
        for(int j = 0;j<i;j++) {
            if(A[j] < A[i]) {
                maxLen = max(maxLen, length[j]);
            }
        }
        length[i] = maxLen+1;
        if(maxLen == 0) {
            length[i] = 1;
        }
    }

    int ans = 0;
    for(int i = 0;i<N;i++) {
        ans = max(ans, length[i]);
    }
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
