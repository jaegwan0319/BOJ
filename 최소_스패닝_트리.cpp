#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct edge {
    int a,b,w;
};

int p[10005];
int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void Merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x>y) p[x] = y;
    else p[y] = x;
}

vector<edge> e;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V,E;
    cin >> V >> E;

    for(int i = 1;i<=V;i++) {
        p[i] = i;
    }
    for(int i = 0;i<E;i++) {
        struct edge temp;
        cin >> temp.a;
        cin >> temp.b;
        cin >> temp.w;
        e.push_back(temp);
    }

    sort(e.begin(),e.end(),[&](edge &a,edge &b) {
        return a.w < b.w; 
    });

    int total = 0;
    for(int i = 0;i<E;i++) {
        int x = e[i].a;
        int y = e[i].b;
        int w = e[i].w;

        if(find(x) != find(y)) {
            Merge(x,y);
            total += w;
        }
    }

    cout << total;
}