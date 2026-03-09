#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수
int N;
vector<pa> tree[10001];

void DFS(int cur) {
    
}

void solve(void) {
    int N;
    cin >> N;
    for(int i = 0;i<N-1;i++) {
        int a,b,weight;
        cin >> a >> b >> weight;
        tree[a].push_back({b,weight});
        tree[b].push_back({a,weight});
    }
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}