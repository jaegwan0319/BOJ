#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int>> A;
vector<bool> visited;

void DFS(int i){
    if(visited[i]){
        return;
    }

    visited[i] = true;

    for(int j: A[i]){
        if(!visited[j]){
            DFS(j);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;
    A.resize(N+1);
    visited = vector<bool>(N + 1, false);

    for(int i = 0;i<M;i++){
        int x,y;
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    int cnt = 0;

    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            cnt++;
            DFS(i);
        }
    }

    cout << cnt;
}