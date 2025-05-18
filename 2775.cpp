#include <iostream>
using namespace std;

int people[15][14];

void solution(void){
    int k,n;
    cin >> k >> n;
    cout << people[k][n-1] << '\n';
    return;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i<14;i++){
        people[0][i] = i+1;
    }

    for(int i = 1;i<15;i++){
        for(int j = 0;j<14;j++){
            int sum = 0;
            for(int k = 0;k<=j;k++){
                sum += people[i-1][k];
            }
            people[i][j] = sum;
        }
    }




    int T;
    cin >> T;

    while(T--){
        solution();
    }
}
