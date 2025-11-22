#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pa;

int N;
int sum = 1;
int arr[27][27];
bool visited[27][27];
vector<int> ans;
int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};

void BFS(int r, int c) {
    queue<pa> q;
    q.push({r,c});
    visited[r][c] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&visited[nx][ny]==false&&arr[nx][ny]==1) {
                q.push({nx,ny});
                visited[nx][ny] = true;
                sum++;
            }
        }
    }
    ans.push_back(sum);
}

void solve(void) {
    cin >> N;
    
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    }
    
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<N;j++) {
            if(visited[i][j]==false && arr[i][j]==1) {
                sum = 1;
                BFS(i,j);
            }
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(int i : ans) {
        cout << i << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}