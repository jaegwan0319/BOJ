#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> ans;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    deque<int> deq;

    for(int i = 1;i<=N;i++) {
        deq.push_back(i);
    }

    while(ans.size() != N) {
        for(int i = 0;i<K-1;i++) {
            int x;
            x = deq.front();
            deq.pop_front();
            deq.push_back(x);
        }
        int x;
        x = deq.front();
        deq.pop_front();
        ans.push_back(x);
    }

    cout << "<" << ans[0];
    for(int i = 1;i<N;i++) {
        cout << ", " << ans[i];
    }
    cout << ">";
}