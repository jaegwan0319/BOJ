#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int arr[10];

void recur(int depth, int start) {
    if(depth == M) {
        for(int i = 0;i<M;i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = start;i<=N;i++) {
        arr[depth] = i;
        recur(depth+1, i);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    recur(0,1);
}