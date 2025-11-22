#include<iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    int arr[100];
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2;i<=N;i++){
        arr[i] = arr[i-2] + arr[i-1];
    }

    cout << arr[N];
}