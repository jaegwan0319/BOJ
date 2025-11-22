#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int board[55][55];
int N,M,K;
bool visited[55][55]{};

void BFS(int a, int b) {
    visited[a][b] = true;
    queue<pair<int,int>> q;
    q.push({a,b});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if(!visited[nx][ny] && board[nx][ny] == 1) {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
}

void solve() {
    cin>>M>>N>>K;
    while(K--) {
        int x,y; cin>>x>>y;
        board[x][y] = 1;
    }
    int ans = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(visited[i][j]==false && board[i][j] == 1){
                BFS(i,j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}