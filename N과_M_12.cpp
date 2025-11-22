#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pa;

int arr[505][505];
bool visited[505][505]{};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N,M;
int max = 0;

void BFS(int x, int y) {
    queue<pa> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++) {
            int nx = X+dx[i];
            int ny = Y+dy[i];

            if(nx>=0&&nx<N&&ny>=0&&ny<M&&visited[nx][ny]==false&&arr[nx][ny]==1) {
                
            }
        }
    }
}

void solve(void) {
    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            BFS(i,j);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}