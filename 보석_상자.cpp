#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
ll N, M;
vector<ll> v;

//질투심을 기준으로 잡고 이분탐색 진행.
//여기서 x는 질투심
bool check(ll x) {
    ll need = 0;
    for(ll i:v) {
        // 나머지에 따라 예외처리
        if(i%x == 0) need += i/x;
        else need += (i/x + 1);
    }
    return need <= N;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0;i<M;i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }

    ll low=0, high=1e9+5;
    while(low+1<high) {
        ll mid = (low+high)/2;
        if(check(mid)) high = mid;
        else low = mid;
    }
    cout << high;
}