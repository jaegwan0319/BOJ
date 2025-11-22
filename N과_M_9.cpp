#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int> pa;

//전역 변수 선언
int arr[10];
int N,M;
vector<int> v;
map<int, int> m;

void DFS(int depth) {
    if(depth == M) {
        for(int i = 0;i<M;i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    else {
        int prev = -1;
        for(int i = 0;i<N;i++) {
            if(m[v[i]] != 0 && prev != v[i]) {
                m[v[i]]--;
                arr[depth] = v[i];
                prev = v[i];
                DFS(depth+1);
                m[v[i]]++;
            }
        }
    }
}

void solve(void) {
    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        m[temp]++;
    }
    sort(v.begin(), v.end());

    DFS(0);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}