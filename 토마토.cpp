#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
using namespace std;


typedef tuple<int,int,int> tup;
int N,M,H;
int arr[101][101][101];
bool visited[101][101][101]{};
queue<tup> q;
int dx[] = {-1,1,0,0,0,0};
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,-1,1};
vector<tup> start;

void BFS(void) {
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for(int i = 0;i<6;i++) {
            int nx = x+dx[i], ny = y+dy[i], nz = z+dz[i];
            if(nx>=0&nx<N&&ny>=0&ny<M&&nz>=0&nz<H&&visited[nz][nx][ny]==false&&arr[nz][nx][ny]==0) {
                arr[nz][nx][ny] = arr[z][x][y] + 1;
                visited[nz][nx][ny] = true;
                q.push({nx,ny,nz});
            }
        }
    }
}

void solve(void) {
    cin >> M >> N >> H;
    for(int k = 0;k<H;k++) {
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<M;j++) {
                cin >> arr[k][i][j];
                if(arr[k][i][j] == 1) {
                    q.push({i,j,k});
                    visited[k][i][j] = true;
                }
            }
        }
    }
    BFS();
    
    //debug
    // for(int k = 0;k<H;k++) {
    //     for(int i = 0;i<N;i++) {
    //         for(int j = 0;j<M;j++) {
    //             cout << arr[k][i][j] << " ";
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for(int k = 0;k<H;k++) {
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<M;j++) {
                if(arr[k][i][j] == 0) {
                    cout << -1; return;
                }
                ans = max(ans, arr[k][i][j]);
            }
        }
    }
    if(ans == 1) cout << 0;
    else cout << ans-1;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}