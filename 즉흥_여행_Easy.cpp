#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int id = 1;
bool finished[200005];
int P[200005];
stack<int> S;
vector<int> graph[200005];
int sccNum = 0;

//입력 선언
int D,L;

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
        sccNum++;
		while (x) {
			int y = S.top(); 
			S.pop();
			finished[y] = true;
			if (y == x) break;
        }
	}
	return parent;
}

void solve(void) {
    cin >> D >> L;
    for(int i = 0;i<L;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i = 1;i<=D;i++) {
        if(finished[i] == false) {
            findSCCusingDFS(i);
        }
    }

    if(sccNum == 1) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}