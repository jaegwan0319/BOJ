#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

const int MX = 1000005;
int arr[MX];
int pos = 0;

void push(int x){
    arr[pos++] = x;
}

void pop(void){
    if(pos == 0){
        cout << -1 << "\n";
    }
    else{
        cout << arr[pos-1] << "\n";
        pos--;
    }
}

void size(void){
    cout << pos << "\n";
}

void empty(void){
    if(pos == 0){
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}

void top(void){
    if(pos == 0){
        cout << -1 << "\n";
    }
    else{
        cout << arr[pos-1] << "\n";
    }
}

int main(void){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        string s;
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(s == "pop"){
            pop();
        }
        else if(s == "size"){
            size();
        }
        else if(s == "empty"){
            empty();
        }
        else if(s == "top"){
            top();
        }
    }
}