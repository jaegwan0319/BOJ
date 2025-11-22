#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result = 1;
    int N,K;
    cin >> N >> K;
    for(int i = 0;i<K;i++){
        result *= N;
        N--;
    }
    while(K){
        result /= K;
        K--;
    }
    cout << result;
    
    return 0;
}