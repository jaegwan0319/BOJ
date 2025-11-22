#include<iostream>
using namespace std;

int main(void){
    int N,arr[11],M,idx,sum = 0;
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> arr[i];
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> idx;
        sum += arr[idx];
    }
    cout << sum;
    return 0;
}