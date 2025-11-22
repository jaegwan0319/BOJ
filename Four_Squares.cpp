#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int min[50004];
    min[1] = 1;
    min[2] = 2;
    min[3] = 3;
    min[4] = 1;
    min[5] = 2;
    min[6] = 3;

    for(int i = 7;i<=50000;i++) {
        min[i] = i;
        for(int j = 1;j*j<=i;j++) {
            if(min[i] > min[i-j*j] + 1) {
                min[i] = min[i-j*j] + 1;
            }
        }
    }

    cout << min[n];
}