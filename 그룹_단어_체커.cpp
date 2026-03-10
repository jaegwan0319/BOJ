#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> v(26); //index 0~25 총 26개.
int cnt = 0;

void solve(void) {
    fill(v.begin(), v.end(), 0);
    string s;
    cin >> s;
    char prev=-1;
    for(int i = 0;i<s.length();i++) {
        int now = s[i]-'a';
        if(prev!=-1) {
            if(v[now]!=0 && now!=prev) {
                return;
            }
        }
        v[now] = 1;
        prev = now;
    }
    cnt++;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0;i<N;i++) {
        solve();
    }
    cout << cnt;
}
