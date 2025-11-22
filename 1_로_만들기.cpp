#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int cnt[1000005];
    cnt[1] = 0;
    cnt[2] = 1;
    cnt[3] = 1;

    if(N <= 3){
        cout << cnt[N];
        return 0;
    }

    for(int i = 4;i<=N;i++){
        //먼저 짝수 홀수 경우 나누기
        if(i%2 == 0){
            cnt[i] = cnt[i-1]<=cnt[i/2] ? cnt[i-1] : cnt[i/2];
        }
        else{
            if(i % 3 == 0){
                cnt[i] = cnt[i-1]<=cnt[i/3] ? cnt[i-1] : cnt[i/3];
            }
            else{
                cnt[i] = cnt[i-1];
            }
        }
        cnt[i]++;
    }

    cout << cnt[N];
}