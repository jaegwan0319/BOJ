#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct compare {
    bool operator()(int o1, int o2){
        return o1 > o2;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    priority_queue<int,vector<int>,compare> min_heap;

    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        
        if(temp == 0){
            if(min_heap.empty()){
                cout << "0\n";
            }
            else{
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }
        else{
            min_heap.push(temp);
        }
    }
    return 0;
}