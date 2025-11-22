#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int N,five_max,three_max, ans = -1;
    cin >> N;
    five_max = N/5 + 1;
    three_max = N/3 + 1;
    for(int i = 1;i<=five_max;i++){
        int five = five_max-i;
        for(int j = 1;j<=three_max;j++){
            int three = three_max - j;
            if(5*five + 3*three == N){
                ans = five + three;
                cout << ans; return 0;
            }
            // 디버깅- cout << five << " " << three << " " << ans << "\n";
        }
    }
    cout << ans;
    return 0;
}