#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

typedef pair<int,int> pa;

int N,M;
int arr[1005][1005];
bool visited[1005][1005]{};
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
//상-하-좌-우 순서

void BFS(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    int sum = 1;
    vector<pa> touch;
    visited[r][c] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++) {
            int curX = x+dr[i], curY = y+dc[i];
            if(curX>=0&&curX<N&&curY>=0&&curY<M&&!visited[curX][curY]&&arr[curX][curY]==0) {
                q.push({curX,curY});
                visited[curX][curY] = true;
                sum++;
            }
            else if(curX>=0&&curX<N&&curY>=0&&curY<M&&arr[curX][curY]!=0) {
                touch.push_back({curX,curY});
            }
        }
    }
    sort(touch.begin(),touch.end());
    pa prev = {-1,-1};
    for(pair<int,int> i : touch) {
        if(prev == i) continue;
        arr[i.first][i.second] += sum;
        prev = i;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            if(!visited[i][j] && arr[i][j] == 0) {
                BFS(i,j);
            }
        }
    }

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            cout << arr[i][j] % 10;
        }
        cout << '\n';
    }
    return 0;
}