#include<iostream>
using namespace std;

int main(void){
    int N,F;
    cin >> N >> F;
    int K;
    K = N%100;
    N = N - K;
    for(int i = 0;i<100;i++){
        if( (N+i) % F == 0){
            if(i < 10) cout << 0;
            cout << i;
            break;
        }
    }
    return 0;
}