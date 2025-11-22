#include<iostream>
#include<vector>
using namespace std;

int isSosu(int N){
    // 소수가 아니면 0, 소수면 1 반환
    for(int i = 2;i<N;i++){
        if(N%i == 0) return 0;
    }
    return 1;
}

int main(void){
    int M, N;
    cin >> M >> N;
    vector<int> v;

    for(int i = M;i<=N;i++){
        if(isSosu(i) == 1){
            v.push_back(i);
        }
    }

    if(v.size() == 0){
        cout << -1;
    }
    else{
        int sum = 0;
        int min = v[0];
        for(int i = 0;i<v.size();i++){
            sum += v[i];
        }
        cout << sum << "\n" << min;
    }
}