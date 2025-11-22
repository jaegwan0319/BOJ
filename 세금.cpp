#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cout << (N/100)*78 << " " << (N/100)*80 + ((N/5)/100)*78;
    return 0; 
}