#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int id = 1;
bool finished[10005];
int P[10005];
stack<int> S;
vector<int> graph[10005];
vector<vector<int>> scc;

//입력 선언
int V,E;

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
    
    if (parent == P[x]) {
        vector<int> temp; //한 scc를 저장
		while (x) {
			int y = S.top(); 
			S.pop();
			temp.push_back(y);
			finished[y] = true;
			if (y == x) break;
		}
        sort(temp.begin(),temp.end());
        scc.push_back(temp);
	}
	return parent;
}

void solve(void) {
    cin >> V >> E;
    for(int i = 0;i<E;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1;i<=V;i++) {
        if(finished[i] == false) {
            findSCCusingDFS(i);
        }
    }



    //출력
    sort(scc.begin(),scc.end());
    cout << scc.size() << "\n";
    for(int i = 0;i<scc.size();i++) {
        for(int j = 0;j<scc[i].size();j++) {
            cout << scc[i][j] << " ";
        }
        cout << -1 << '\n';
    }

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}