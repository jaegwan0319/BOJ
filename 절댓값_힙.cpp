#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct compare {
    bool operator()(int a, int b){
        int abs_a = abs(a);
        int abs_b = abs(b);
        if(abs_a == abs_b){
            return a > b;
        }
        else return abs_a > abs_b;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int,vector<int>,compare> absHeap;
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            if(absHeap.empty()){
                cout << "0\n";
            }
            else{
                cout << absHeap.top() << "\n";
                absHeap.pop();
            }
        }
        else{
            absHeap.push(temp);
        }
    }
    return 0;
}