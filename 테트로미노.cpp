#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pa;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

//전역 변수 선언
int arr[505][505];
int ans = 0;
int N,M;

void DFS(int x, int y, int prevX, int prevY, int sum, int way) {
    if(way == 3) {
        ans = max(ans, sum);
        return;
    }

    for(int i = 0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!(nx==prevX&&ny==prevY) && nx>=0&&nx<N&&ny>=0&&ny<M) {
            DFS(nx,ny,x,y,sum+arr[nx][ny],way+1);
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

    //세갈레로 나뉘는 5번쨰 모양만 예외로 하고 나머지는 DFS 가능하지 않을까?
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            DFS(i,j,i   ,j,arr[i][j],0);
        }
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            for(int k = 0;k<4;k++) {
                int sum = arr[i][j];
                for(int x = 0;x<4;x++) {
                    if(x==k) continue;
                    
                    int nx = i+dx[x];
                    int ny = j+dy[x];
                    if(nx<0||nx>=N||ny<0||ny>=M) continue;
                    sum += arr[nx][ny];
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}