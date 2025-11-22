#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,k,x;
int T;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> n >> k >> x;
        vector<int> v;
        vector<int> kResult;
        for(int i = 0;i<n;i++) {
            int temp; cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(),v.end());
        vector<pair<int,int>> median; // {거리차이,중앙값}
        median.push_back({(v[0]-0)/2,0});
        for(int i = 0;i<n-1;i++) {
            median.push_back({(v[i+1]-v[i])/2 , (v[i+1]+v[i])/2});
        }
        median.push_back({(x-v[n-1])/2,x});

        sort(median.begin(),median.end());


        for(int i = 0;i<k;i++) {
            int noInsert = 0;
            int backIdx = median.size()-1;
            for(int j = 0;j<kResult.size();j++) {
                kResult[j] == median[backIdx].second;
                noInsert = 1;
            }
            if(!noInsert) kResult.push_back(median[backIdx].second);
            int pos = median[backIdx].second;
            int length = median[backIdx].first;

            median.pop_back();

            if(length-1>=0 && pos-1>=0) median.push_back({length-1,pos-1});
            if(length-1>=0 && pos+1<=x) median.push_back({length-1,pos+1});
            sort(median.begin(),median.end());
        }
        for(int i:kResult) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}