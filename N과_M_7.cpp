#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수
int N,M;
vector<int> v;
int arr[10];

void DFS(int depth, int prev) {
    if(depth == M) {    
        for(int i = 0;i<M;i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    for(int i = 0;i<N;i++) {
        
        arr[depth] = v[i];
        DFS(depth+1, i);
    }
}

void solve(void) {
    cin >> N >> M;
    v.resize(N);
    for(int &i:v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    DFS(0,-1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}