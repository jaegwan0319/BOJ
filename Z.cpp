#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int N,r,c;
int cnt = 0;

void solve(int nowR,int nowC,int n) {
    if(n == 0) {
        return;
    }

    int half = pow(2,n-1);
    //1사분면
    if(r < nowR + half && c < nowC + half) {
        solve(nowR,nowC,n-1);
    }
    //2사분면
    else if(r < nowR + half && c >= nowC + half) {
        cnt += half*half;
        solve(nowR,nowC+half,n-1);
    }
    //3사분면
    else if(r >= nowR + half && c < nowC + half) {
        cnt += half*half*2;
        solve(nowR+half,nowC,n-1);
    }
    //4사분면
    else if(r >= nowR + half && c >= nowC + half) {
        cnt += half*half*3;
        solve(nowR+half,nowC+half,n-1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;
    solve(0,0,N);
    
    cout << cnt;
    return 0;
}