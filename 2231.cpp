#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    for(int i = 1;i<1000000;i++){
        int a = 0;
        int temp = i;
        a += temp;
        while( temp != 0){
            a += temp%10;
            temp /= 10;
        }

        if ( N == a ){
            cout << i;
            return 0;
        }

    }
    cout << 0;
    return 0;

}
