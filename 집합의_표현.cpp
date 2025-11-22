#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> p;

int find(int x) {
    if(p[x] == x) return x;
    return find(p[x]);
}

void Merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x>y) p[x] = y;
    else p[y] = x;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin >> N >> M;

    p.resize(N+1);
    for(int i = 0;i<=N;i++) {
        p[i] = i;
    }

    for(int i = 0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;

        if(a==0) {
            Merge(b,c);
        }

        else {
            if(find(b)==find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}