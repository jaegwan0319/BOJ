#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(void){
    int N;
    cin >> N;
    queue<int> q;
    for(int i = 1;i<=N;i++){
        q.push(i);
    }
    if( N == 1) {
        cout << 1; return 0;
    }
    while(q.size() != 2){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    q.pop();
    cout << q.front();
    return 0;
}