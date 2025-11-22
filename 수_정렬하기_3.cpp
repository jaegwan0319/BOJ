#include<iostream>
using namespace std;

int arr[10001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i< N;i++){
        int in;
        cin >> in;
        arr[in]++;
    }
    for(int i = 1;i<10001;i++){
        for(int j = 0;j<arr[i];j++){
            cout << i << "\n";
        }
    }
    return 0;
}