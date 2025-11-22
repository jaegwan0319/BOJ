#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> v;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v.resize(N);
    for(int &i:v) {
        cin >> i;
    }

    int ans = 0;
    int left = 0;
    int arr[10] = {0};
    int kind = 0;

    for(int right = 0;right<N;right++) {
        int curr = v[right];

        if(arr[curr] == 0) {
            kind++;
        }
        arr[curr]++;
        while(kind > 2) {
            arr[v[left]]--;
            if(arr[v[left]] == 0) {
                kind--;
            }
            left++;
        }
        ans = max(right-left+1,ans);
    }
    cout << ans;
    return 0;
}