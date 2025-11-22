#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M[11];
    int sum = 0;

    int N;
    for(int i = 0;i<11;i++) {
        cin >> M[i];
    }

    cin >> N;

    int B,S;
    float L;
    for(int i = 0;i<N;i++) {
        cin >> B >> L >> S;
        if(S>=17 && L>=2.0) {
            sum += M[B];
        }
    }
    cout << sum << "\n";
    return 0;
}
