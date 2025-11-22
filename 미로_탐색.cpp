#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N,M;
int arr[101][101];
bool visited[101][101] = {false};
queue<pair<int,int>> q;
void BFS(int x, int y);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    BFS(0,0);
    cout << arr[N-1][M-1] << "\n";
    return 0;
}

void BFS(int i, int j){
    q.push(make_pair(i,j));

    while(!q.empty()){
        int n,m;
        n = q.front().first;
        m = q.front().second;
        q.pop();
        visited[i][j] = true;

        for(int k = 0;k<4;k++){
            int x = n + dx[k];
            int y = m + dy[k];

            if(x >= 0 && y >= 0 && x < N && y < M){
                if(arr[x][y] != 0 && !visited[x][y]){
                    visited[x][y] = true;
                    arr[x][y] = arr[n][m] + 1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
}