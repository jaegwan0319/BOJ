#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N,M;
queue<int> q;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int adj[105][105]{};
    int N,M;
    cin>>N>>M;
    for(int i = 0;i<M;i++) {
        int a,b; cin>>a>>b;
        adj[a][b] = adj[b][a] = 1;
    }
    bool visited[105]{};

    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 1;i<=N;i++) {
            if(adj[x][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    int cnt = 0;
    for(int i = 2;i<=N;i++) {
        if(visited[i]) cnt++;
    }
    cout << cnt;
}