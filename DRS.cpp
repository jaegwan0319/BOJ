#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll N,T;
vector<pair<string,ll>> driver;
vector<string> ans;
vector<pair<ll,string>> line;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;
    for(int i = 0;i<N;i++) {
        string s; ll temp;
        cin >> s >> temp;
        driver.push_back({s,temp});
    }

    ll sum = T;
    line.push_back({T,driver[0].first});
    //1위와 절대거리 젤 낮은 드라이버의 거리차이는 예외처리.
    for(int i = 1;i<N;i++) {
        sum += driver[i].second;
        
        line.push_back({T - sum%T,driver[i].first});
    }
    sort(line.begin(),line.end());

    //1등예외
    if(line[0].first<=1000) {
        ans.push_back(driver[0].first);
    }

    for(int i = 0;i<N-1;i++) {
        if(line[i+1].first - line[i].first <= 1000) {
            ans.push_back(line[i].second);
        }
    }

    sort(ans.begin(),ans.end());
    if(ans.size() == 0) {
        cout << -1;
        return 0;
    }
    for(string s : ans) {
        cout << s << " ";
    }
}