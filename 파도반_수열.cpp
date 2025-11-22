#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int T;
        cin >> T;

        long long arr[101];
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 1;
        arr[4] = 2;
        arr[5] = 2;
        for(int i = 6;i<=100;i++) {
            arr[i] = arr[i-2] + arr[i-3];
        }

        while(T--) {
            int N;
            cin >> N;
            cout << arr[N] << "\n";
        }
        return 0;
}