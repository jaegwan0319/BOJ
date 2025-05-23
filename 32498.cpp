#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,result = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        int input;
        cin >> input;
        if(input%2 == 1){
            result++;
        }
    }
    cout << result;
    return 0;
}
