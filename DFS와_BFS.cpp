#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, V;
queue<int> q;
vector<vector<int>> list;
vector<bool> visited;
void DFS(int now);
void BFS(int now);

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    list.resize(N+1);
    visited = vector<bool>(N+1,false);

    for(int i = 0;i<M;i++){
        int a,b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    // 작은 순으로 정렬
    for(int i = 1;i<=N;i++){
        sort(list[i].begin(),list[i].end());
    }

    //DFS 탐색
    DFS(V);
    
    cout << "\n";
    fill(visited.begin(),visited.end(),false);

    //BFS 탐색
    BFS(V);

}

void DFS(int now){
    cout << now << " ";
    visited[now] = true;

    for(int i: list[now]){
        if(!visited[i]){
            DFS(i);
        }
    }
    return;
}

void BFS(int now){
    q.push(now);
    visited[now] = true;

    while(!q.empty()){
        int now_node = q.front();
        q.pop();
        cout << now_node << " ";
        for(int i: list[now_node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}