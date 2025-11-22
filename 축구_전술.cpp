#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int id = 1;
vector<bool> finished;
vector<int> P;
stack<int> S;
vector<int> graph[200005],reverseGraph[200005];
vector<vector<int>> scc; //
int sccIdx[200005];;

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
        vector<int> tempSCC;
		while (id) {
			int y = S.top(); 
			S.pop();
            sccIdx[y] = scc.size();
            tempSCC.push_back(y);
			finished[y] = true;
			if (y == x) {
                break;
            }
        }
        scc.push_back(tempSCC);
	}
	return parent;
}

void solve(void) {
    cin >> D >> L;
    //초기화
    id = 1;
    finished.clear(); P.clear();
    finished.resize(D+1);
    P.resize(D+1);
    scc.clear();
    for(int i = 0;i<=D;i++) {
        graph[i].clear();
        reverseGraph[i].clear();
    }
    //초기화 끝

    for(int i = 0;i<L;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }
    for(int i = 0;i<D;i++) {
        if(finished[i] == false) {
            findSCCusingDFS(i);
        }
    }

    // for(int i = 0;i<scc.size();i++) {
    //     for(int j : scc[i]) {
    //         cout << j <<" ";
    //     }
    //     cout <<'\n';
    // }


    vector<bool> check;
    check.resize(scc.size());

    for(int i = 0;i<scc.size();i++) {
        for(int j : scc[i]) {
            for(int k : reverseGraph[j]) {
                if(sccIdx[j]!=sccIdx[k]) {
                    check[i] = true; // 다른데에서 이 순환으로 연결되는게 존재할 때
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 0;i<scc.size();i++) {
        if(check[i] == false) {
            cnt++;
        }
    }
    if(cnt != 1) {
        cout << "Confused\n";
        return;
    }

    for(int i = 0;i<scc.size();i++) {
        if(check[i] == false) {
            //정답 출력
            sort(scc[i].begin(),scc[i].end());
            for(int j : scc[i]) {
                cout << j << '\n';
            }
            return;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}