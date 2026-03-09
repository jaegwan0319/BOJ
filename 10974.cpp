#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수
int N;
int arr[10];
int visited[10];

void DFS(int depth, int prev) {
    if(depth == N) {
        for(int i = 0;i<N;i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = 1;i<=N;i++) {
        if(visited[i]) continue;
        visited[i] = true;
        arr[depth] = i;
        DFS(depth+1, i);
        visited[i] = false;
    }
}

void solve(void) {
    cin >> N;
    DFS(0,-1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}