#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//전역변수
char arr[100000000]; //트리 저장
int N;
map<char, int> m;

void preorder(int now) {
    cout << arr[now];
    if(arr[now*2] != '.') {
        preorder(now*2);
    }
    if(arr[now*2+1] != '.') {
        preorder(now*2+1);
    }
}

void inorder(int now) {
    if(arr[now*2] != '.') {
        inorder(now*2);
    }
    cout << arr[now];
    if(arr[now*2+1] != '.') {
        inorder(now*2+1);
    }
}

void postorder(int now) {
    if(arr[now*2] != '.') {
        postorder(now*2);
    }
    if(arr[now*2+1] != '.') {
        postorder(now*2+1);
    }
    cout << arr[now];
}

void solve(void) {
    cin >> N;
    m['A'] = 1;
    arr[1] = 'A';
    for(int i = 2;i<=100000000;i++) {
        arr[i] = '.';
    }

    for(int i = 1;i<=N;i++) {
        char temp;
        cin >> temp;
        int root = m[temp];
        int childIdx[2] = {root*2, root*2+1};

        char child[2];
        for(int i = 0;i<2;i++) {
            cin >> child[i];
            if(child[i] != '.') {
                m[child[i]] = childIdx[i];
            }
            arr[childIdx[i]] = child[i];
        }
    }

    //전위 순회
    preorder(1); cout << '\n';
    //중위 순회
    inorder(1); cout << '\n';
    //후위 순회
    postorder(1); cout << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}