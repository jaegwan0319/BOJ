#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,X;
    vector<int> v;
    cin >> N >> X;

    for(int i = 0;i<N;i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> sum;
    for(int i = 0;i<N-1;i++) {
        int temp;
        temp = v[i] + v[i+1];
        sum.push_back(temp);
    }
    sort(sum.begin(),sum.end());
    cout << (sum[0]) * X;
}