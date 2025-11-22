#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> A;
queue<int> q;
vector<bool> visited;
vector<int> guri;

void BFS(int i){
    q.push(i);
    visited[i] = true;

    while(!q.empty()){
        int now_node = q.front();
        q.pop();

        for(edge i: A[now_node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                q.push(i.first);
                guri[i.first] = guri[now_node] + i.second;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N+1);
    visited = vector<bool>(N+1,false);
    guri = vector<int>(N+1,0);

    for(int i = 0;i<N;i++){
        int start, end, dis;
        cin >> start;
        while(1){
            cin >> end;
            if(end == -1) break;

            cin >> dis;
            A[start].push_back(edge(end,dis));
        }
    }
    
    BFS(1);
    int maxIdx, max = 0;
    for(int i = 1;i<N+1;i++){
        if(guri[i] >= max){
            max = guri[i];
            maxIdx = i;
        }
    }
    fill(guri.begin(),guri.end(),0);
    fill(visited.begin(),visited.end(),false);

    BFS(maxIdx);
    cout << *max_element(guri.begin(),guri.end());
}

