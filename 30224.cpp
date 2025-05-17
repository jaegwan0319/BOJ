#include <iostream>
using namespace std;

int containSeven(int a){
    while(1){
        if(a % 10 == 7) return 2;
        a/=10;
        if(a == 0) return 0;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int input,result;
    cin >> input;
    result = containSeven(input) + (input % 7 == 0);
    cout << result;
    return 0;
}
