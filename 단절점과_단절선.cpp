#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N,Q;
int cnt[100005]{};
vector<int> tree[100005];
bool visited[100005]{};

void DFS(int i);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0;i<N-1;i++) {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
     
    for(int i = 1;i<=N;i++) {
        cnt[i] = tree[i].size();
    }

    cin >> Q;
    for(int i = 0;i<Q;i++) {
        int a,b;
        cin >> a >> b;
        if(a == 1) {
            if(cnt[b] >= 2) cout << "yes\n";
            else cout << "no\n";
        }
        else {
            cout << "yes\n";
        }
    }
    return 0;
}