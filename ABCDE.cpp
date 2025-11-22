#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<vector<int>> relation;
vector<bool> visited;
int ans = 0; //

void DFS(int num, int cnt); // cnt == 3가 되면 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    relation.resize(N);
    visited = vector<bool>(N,false);

    for(int i = 0;i<M;i++){
        int a,b;
        cin >> a >> b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }
    
    for(int i = 0;i<N;i++){
        if(visited[i]) continue;
        DFS(i,0);
        if(ans == 1) break;
    }

    cout << ans << "\n";
    return 0;
}

void DFS(int num, int cnt){
    if(cnt == 4){
        ans = 1;
        return;
    }


    visited[num] = true;
    for(int i: relation[num]){
        if(visited[i]) continue;
        DFS(i,cnt+1);
    }
    visited[num] = false;
}