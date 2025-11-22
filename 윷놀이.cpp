#include<iostream>
using namespace std;

void Sol(int arr[4]){
    int cnt = 0;
    for(int i = 0;i<4;i++){
        if(arr[i] == 1) cnt++;
    }
    if( cnt == 0) cout << "D";
    else if( cnt == 1) cout << "C";
    else if( cnt == 2) cout << "B";
    else if( cnt == 3) cout << "A";
    else if( cnt == 4) cout << "E";
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 3;
    int arr[4];
    while(T--){
        for(int i = 0;i<4;i++){
            cin >> arr[i];
        }
        Sol(arr);
        cout << "\n";
    }
    return 0;
}