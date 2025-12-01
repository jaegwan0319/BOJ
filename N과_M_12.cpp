#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int N,M;
vector<int> v;
int arr[10];
map<int, bool> check;

void DFS(int depth, int pre) {
    if(depth == M) {
        for(int i = 0;i<M;i++) cout << arr[i] << " ";
        cout << "\n";
    }

    else {
        int prev = 0;
        for(int i = 0;i<v.size();i++) {
            if(pre <= v[i]) {
                arr[depth] = v[i];
                prev = v[i];
                DFS(depth+1, prev);
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        int temp;
        cin >> temp;
        if(check[temp] == false) {
            check[temp] = true;
            v.push_back(temp);
        }
    }
    sort(v.begin(),v.end());

    DFS(0,0);
}