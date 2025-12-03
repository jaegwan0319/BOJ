#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수
int N,M;
int arr[10];
bool visited[10]{};

void DFS(int depth) {
    if(depth == M) {
        for(int i = 0;i<M;i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1;i<=N;i++) {
        if(visited[i] == true) continue;
        arr[depth] = i;
        visited[i] = true;
        DFS(depth + 1);
        visited[i] = false;
    }
}

void solve(void) {
    cin >> N >> M;

    DFS(0);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}