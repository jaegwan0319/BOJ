#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;

//scc위한 값들 선언
int id = 1;
vector<int> P; 
vector<bool> finished;
stack<int> S;
int includeX = 0;

int ans;

//입력값 선언
int N,M,X;
vector<int> graph[200001];
vector<int> reverseGraph[200001];
vector<int> key; // 1 -> 1포함 순환 | 2 -> 그냥 순환 | 0 -> 기본값.

int findSCCusingDFS(int x) {
	P[x] = id++;
	S.push(x);

	int parent = P[x];
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i]; //다음 요소
		if (P[y] == 0)
			parent = min(parent, findSCCusingDFS(y)); 
		else if (!finished[y])
			parent = min(parent, P[y]); 
	}
    
    if(parent==P[x] && P[x]==1) {
        while(1) {
            int y = S.top();
            S.pop();
            finished[y] = true;
            key[y] = 1;
            includeX++;
            if(y==x) break;
        }
    }

	else if (parent == P[x]) {
		vector<int> scc;
        int sccSize = 0;
		while (x) {
			int y = S.top(); 
			S.pop();
			scc.push_back(y);
			finished[y] = true;
            key[y] = 2;
            sccSize++;
			if (y == x) break;
		}
		ans += sccSize + 1;
	}
	return parent;
}

//한번더 DFS탐색을 위한 visited 선언
vector<bool> visited;
vector<bool> reverseVisited;
void basicDFS(int x) {
    switch(key[x]) {
        case 0:
            //cout << "key : "<<x<< "case 0 debug\n";
            ans++;
            break;
        case 1:
            //cout << "key : "<<x<<  "case 1 debug\n";
            break;
        case 2:
            // cout << "key : "<<x<<  "case 2 debug\n";
            ans--;
            break;
    }
	visited[x] = true;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
            basicDFS(y);
        } 
	}
}
void reverseCheckDFS(int x) {
	reverseVisited[x] = true;
    visited[x] = true;
	for (int i = 0; i < reverseGraph[x].size(); i++) {
		int y = reverseGraph[x][i];
		if (!reverseVisited[y]) {
            reverseCheckDFS(y);
        } 
	}
}

void solve(void) {
    cin >> N >> M >> X;
    P.resize(N+1);
    finished.resize(N+1);
    key.resize(N+1);
    visited.resize(N+1);
    reverseVisited.resize(N+1);
    fill(key.begin(),key.end(),0);

    for(int i = 0;i<M;i++) {
        int a,b;
        cin >> a >> b; // a <= b
        graph[b].push_back(a); // b가 a를 가리키는 방향 그래프임
        reverseGraph[a].push_back(b);
    }

    findSCCusingDFS(X);
    basicDFS(X);
    reverseCheckDFS(X);

    for(int i = 1;i<=N;i++) {
        if(visited[i] == false) {
            ans--;
            if(finished[i] == false) {
                findSCCusingDFS(i);
            }
        }
    }
    cout << ans;
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}