#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
void BFS(int x,int y);
int visited[1005][1005]; // visitied 배열에 이동 횟수를 저장 및 체크..
int n,m;
int map[1005][1005];
int ans[1005][1005];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    int start_x,start_y;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                start_x = i;
                start_y = j;
            }
        }
    }

    BFS(start_x,start_y);

    for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        if(map[i][j] == 1 && visited[i][j] == 0){
            cout << -1 << " ";
        }
        else{
            cout << ans[i][j] << " ";
        }
    }
    cout << "\n";
}
}

void BFS(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    ans[x][y] = 0;

    while(!q.empty()) {
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        //상
        if(current_y - 1 >= 0 && visited[current_x][current_y-1] == 0 && map[current_x][current_y-1] != 0){
            visited[current_x][current_y-1] = 1;
            ans[current_x][current_y-1] = ans[current_x][current_y] + 1;
            q.push({current_x,current_y-1});
        }

        //하
        if(current_y + 1 <= m-1 && visited[current_x][current_y+1] == 0 && map[current_x][current_y+1] != 0){
            visited[current_x][current_y+1] = 1;
            ans[current_x][current_y+1] = ans[current_x][current_y] + 1;
            q.push({current_x,current_y+1});
        }

        //좌
        if(current_x - 1 >= 0 && visited[current_x-1][current_y] == 0 && map[current_x-1][current_y] != 0){
            visited[current_x-1][current_y] = 1;
            ans[current_x-1][current_y] = ans[current_x][current_y] + 1;
            q.push({current_x-1,current_y});
        }

        //우
        if(current_x + 1 <= n-1 && visited[current_x+1][current_y] == 0 && map[current_x+1][current_y] != 0){
            visited[current_x+1][current_y] = 1;
            ans[current_x+1][current_y] = ans[current_x][current_y] + 1;
            q.push({current_x+1,current_y});
        }
    }
}