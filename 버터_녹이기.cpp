#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int,int>> butter;

bool check(int time) {
    vector<pair<int,int>> range(N);
    for(int i = 0;i<N;i++) {
        int a,b;
        a = butter[i].first - ((butter[i].second < time)?butter[i].second:time);
        b = butter[i].first + ((butter[i].second < time)?butter[i].second:time);
        range[i] = {a,b};
    }
    sort(range.begin(),range.end());

    pair<int,int> front = range[0], rear = range[N-1];
    for(int i = 0;i<N-1;i++) {
        front = range[i]; rear = range[i+1];
        if(front.second >= rear.first) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0;i<N;i++) {
        int x, h; cin >> x >> h;
        butter.push_back({x,(h-1)/2});
    }

    
    
    int low = 0, high = 1e9+1;
    while(low+1 < high) {
        int mid = (low+high)/2;
        if(check(mid)) low = mid;
        else high = mid; 
        //cout << high << "\n";
    }
    if(low == 1e9) {
        cout << "forever";
        return 0;
    }
    cout << low;
}