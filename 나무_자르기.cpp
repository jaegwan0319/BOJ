#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define ll long long
ll N,M; 
vector<ll> v;

bool check(ll h) {
    ll sum = 0;
    for(ll i:v) {
        sum += max(0LL,i-h);
    }
    return sum>=M;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0;i<N;i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    ll low = 0, high = 1e9+5;
    while(low+1 < high) {
        ll mid = (low+high)/2;
        if(check(mid)) low = mid;
        else high = mid;
    }

    cout << low;
}
