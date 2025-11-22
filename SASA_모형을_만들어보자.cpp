#include<iostream>
using namespace std;

int main(void){
    int a,b;
    cin >> a >> b;

    int c,d;
    c = a/2;
    d = b/2;
    cout << ((c<d)?c:d);
    return 0;
}