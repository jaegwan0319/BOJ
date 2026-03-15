#include<iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    int one,ten,hun;
    one = b%10;
    hun = b/100;
    ten = (b/10)%10;

    cout << a*one << '\n';
    cout << a*ten << '\n';
    cout << a*hun << '\n';
    cout << a*b;
    return 0;
}