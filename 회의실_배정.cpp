#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second; // a가 b보다 작으면 TRUE 반환
}

int N;
vector<pair<int, int>> meet;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0;i<N;i++) {
        int start, end;
        cin >> start >> end;

        meet.push_back({start, end});
    }
    sort(meet.begin(),meet.end(),compare);

    // 확인용 출력
    // for(int i = 0;i<N;i++) {
    //     cout << meet[i].first << " " <<  meet[i].second << "\n";
    // }

    int end_time = 0;
    int cnt = 0;
    for(int i = 0;i<N;i++) {
        if(meet[i].first < end_time) continue;

        cnt++;
        end_time = meet[i].second;
    }
    cout << cnt;
    return 0;
}