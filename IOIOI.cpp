#include<iostream>
#include<vector>
#include<algorithm>
// typedef pair<int,int> pa;
using namespace std;

int N,M;
string s;

bool check(int start) {
    int key = 0; // key가 0일 때는 I를 받아야하고, key가 1일 때는 O를 받아야함.
    for(int i = start;i<=start+2*N;i++) {
        if(key==0) {
            if(s[i] == 'O') return false;
        }
        else if(key==1) {
            if(s[i] == 'I') return false;
        }

        if(key==0) key = 1;
        else key = 0;
    }
    return true;
}

void solve(void) {
    cin >> N;
    cin >> M;
    cin >> s;
    
    int ans = 0;
    int start = 0;
    int sum = 0;
    for(int i = 0;i<M-2;i++) {
        if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') {
            sum++;
            i++; //i를 두칸 뛰기?
            continue;
        }
        else {
            ans += max(0,sum-N+1);
            sum = 0;
        }
    }
    ans += max(0,sum-N+1);
    cout << ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}