#include<iostream>
using namespace std;

char arr[100];

int main(void) {
    arr[2] = 'a';
    cout << 100 - int(arr[2]);
    return 0;
}