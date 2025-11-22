#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll K,N;
vector<ll> v;

bool check(ll unit) {
    ll sum = 0;
    for(ll i:v) {
        sum += i/unit;
    }
    return N<=sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K >> N;
    for(int i = 0;i<K;i++) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }

    ll low = 0, high = 1e10;
    while(low+1<high) {
        ll mid = (low+high)/2;
        if(check(mid)) low = mid;
        else high = mid;
    }
    cout << low;
}