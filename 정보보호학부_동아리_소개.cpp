#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char in;
    cin >> in;
    if(in == 'M'){
        cout << "MatKor";
    }
    else if(in == 'W'){
        cout << "WiCys";
    }
    else if(in == 'C'){
        cout << "CyKor";
    }
    else if(in == 'A'){
        cout << "AlKor";
    }
    else if(in == '$'){
        cout << "$clear";
    }
    return 0;
}