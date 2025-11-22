#include<iostream>
using namespace std;

int main(void){
    int N,ball = 1;
    cin >> N;
    
    while(N--){
        int a,b;
        cin >> a >> b;
        if(a==ball){
            ball = b;
        }
        else if(b==ball){
            ball = a;
        }
    }
    cout << ball;
    return 0;
}