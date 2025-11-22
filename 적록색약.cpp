#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;

int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};
bool visited1[101][101], visited2[101][101];

//입력값 선언
int N;
char arr[101][101];
char redgreen[101][101];

void BFS(int x, int y, char Arr[][101], bool visited[][101]) {
    queue<pa> q;
    q.push({x,y});
    visited[x][y] = true;

    while(!q.empty()) {
        int a=q.front().first;
        int b=q.front().second;
        q.pop();

        for(int i = 0;i<4;i++) {
            int nx = a+dx[i];
            int ny = b+dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(Arr[nx][ny] == Arr[a][b] && visited[nx][ny] == false) {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }
}

void solve(void) {
    cin >> N;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            cin >> arr[i][j];
            redgreen[i][j] = arr[i][j];
            if(arr[i][j] == 'G') redgreen[i][j] = 'R';
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(visited1[i][j] == false) {
                ans1++;
                BFS(i,j,arr,visited1);
            }
        }
    }
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(visited2[i][j] == false) {
                ans2++;
                BFS(i,j,redgreen,visited2);
            }
        }
    }
    cout << ans1 << " " << ans2;
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}