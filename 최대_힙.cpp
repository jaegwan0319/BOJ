#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct compare {
    bool operator()(int o1, int o2){
        return o1 < o2;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int,vector<int>,compare> max_heap;

    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        
        if(temp == 0){
            if(max_heap.empty()){
                cout << "0\n";
            }
            else{
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
        }
        else{
            max_heap.push(temp);
        }
    }
    return 0;
}