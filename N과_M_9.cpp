#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int, int> pa;

int N,M;
vector<int> v;
int visited[10]{};
map<int, int> m;

void DFS(int depth) {
    if(depth == M) {
        for(int i = 0;i<M;i++) cout << arr[i] << " ";
        cout << "\n";
    }

    else {
        for(int i = 0;i<N;i++) {
            if(!visited[i]) {
                visited[i] = true;
                arr[depth] = v[i];
                DFS(depth+1);
                visited[i] = false;
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    v.resize(N);
    for(int &i:v) {
        cin >> i;
        m[i]++;
    }
    sort(v.begin(),v.end());

    DFS(0);
}