#include<iostream>
#include<string>
using namespace std;
#define MAX 10001

struct Queue {
    int arr[MAX];
    int frontIdx = 0;
    int backIdx = 0;

    void push(void){
        int x;
        cin >> x;
        arr[backIdx] = x;
        backIdx++;
        return;
    }

    void pop(void){
        if(backIdx-frontIdx == 0){
            cout << -1 << "\n";
            return;
        }
        else{
            cout << arr[frontIdx] << "\n";
            frontIdx++;
            return;
        }
    }

    void size(void){
        cout << backIdx-frontIdx << "\n";
        return;
    }

    void empty(void){
        if(backIdx-frontIdx == 0) cout << 1 << "\n";
        else cout << 0 << "\n";
        return;
    }

    void front(void){
        if(backIdx-frontIdx == 0) cout << -1 << "\n";
        else cout << arr[frontIdx] << "\n";
        return;
    }

    void back(void){
        if(backIdx-frontIdx == 0) cout << -1 << "\n";
        else cout << arr[backIdx-1] << "\n";
        return;
    }
};

int main(void){
    int N;
    struct Queue q;
    cin >> N;
    while(N--){
        string s;
        cin >> s;
        if(s == "push"){
            q.push();
        }
        else if(s == "pop"){
            q.pop();
        }
        else if(s == "size"){
            q.size();
        }
        else if(s == "empty"){
            q.empty();
        }
        else if(s == "front"){
            q.front();
        }
        else if(s == "back"){
            q.back();
        }
    }
    return 0;
}