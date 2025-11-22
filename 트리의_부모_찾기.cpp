#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N;
vector<int> ans;
vector<int> tree[100005];
bool visited[100005]{};

void DFS(int i);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    ans.resize(N+3);
    for(int i = 0;i<N-1;i++) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);

    for(int i = 2;i<=N;i++) {
        cout << ans[i] << "\n";
    }
}

void DFS(int i) {
    visited[i] = true;

    for(int k : tree[i]) {
        if(!visited[k]) {
            ans[k] = i;
            DFS(k);
        }
    }
}