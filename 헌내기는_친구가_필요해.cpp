#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M;
int people = 0;
pair<int,int> start;
char campus[700][700];

void BFS(int i, int j);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            cin >> campus[i][j];
            if(campus[i][j] == 'I') start = {i,j};
        }
    }

    BFS(start.first,start.second);
    if(people == 0) {
        cout << "TT\n";
        return 0;
    }
    cout << people;
}

void BFS(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i,j});

    //지나간 곳을 X로 변환.
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        //좌
        if(c-1 >= 0 && campus[r][c-1] != 'X') {
            q.push({r,c-1});
            if(campus[r][c-1] == 'P') people++;
            campus[r][c-1] = 'X';
        }
        //우
        if(c+1 <= M-1 && campus[r][c+1] != 'X') {
            q.push({r,c+1});
            if(campus[r][c+1] == 'P') people++;
            campus[r][c+1] = 'X';
        }
        //상
        if(r-1 >= 0 && campus[r-1][c] != 'X') {
            q.push({r-1,c});
            if(campus[r-1][c] == 'P') people++;
            campus[r-1][c] = 'X';
        }
        //하
        if(r+1 <= N-1 && campus[r+1][c] != 'X') {
            q.push({r+1,c});
            if(campus[r+1][c] == 'P') people++;
            campus[r+1][c] = 'X';
        }
    }
}