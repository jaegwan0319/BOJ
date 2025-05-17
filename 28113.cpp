#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, A, B;
    cin >> N >> A >> B;
    if( N <= B ){
        if( A < B ) cout << "Bus";
        else if ( A == B ) cout << "Anything";
        else cout << "Subway";
    }
    else {
        cout << "Bus";
    }
}
