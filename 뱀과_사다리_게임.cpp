#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> pa;

map<int,int> ladder, snake;
bool visited[110]{};

int BFS(void) {
    queue<pa> q; //first에는 시작 위치, second에는 몇번째 이동인지 기록
    q.push({1,0});
    visited[1] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(x == 100) {
            return cnt;
        }

        for(int i = 1;i<=6;i++) {
            int nx = x+i;
            if(nx<=100 && visited[nx] == false) {
                if(ladder[nx] != 0) {
                    if(visited[ladder[nx]] == false) {
                        q.push({ladder[nx], cnt+1});
                        visited[ladder[nx]] = true;
                    }
                }
                else if(snake[nx] != 0) {
                    if(visited[snake[nx]] == false) {
                        q.push({snake[nx], cnt+1});
                        visited[snake[nx]] = true;
                    }
                }
                else {
                    q.push({nx,cnt+1});
                    visited[nx] = true;
                }
            }
        }
    }
}

void solve(void) {
    int N,M;
    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        ladder[a] = b;
    }
    for(int i = 0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        snake[a] = b;
    }

    cout << BFS();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}