#include<iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,two = 0,five = 0;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp = (i+1);
        while( temp % 2 == 0 ){
            two++;
            temp /= 2;
        }
        while( temp % 5 == 0 ){
            five++;
            temp /= 5;
        }
    }
    cout << ((two<five)?two:five); 
    return 0;
}