#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

bool compare(int a,int b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M; // M은 인덱스
        queue<pair<int, int>> que;
        vector<int> justWeight;
        for(int i = 0;i<N;i++){
            int weight;
            cin >> weight;
            que.push({weight, i});
            justWeight.push_back(weight);
        }
        sort(justWeight.begin(),justWeight.end(),compare);
        int max = justWeight[0];
        int cnt = 1;
        while(1){
            if(que.front().first == max){
                if(que.front().second == M){
                    cout << cnt << "\n";
                    break;
                }
                else{
                    que.pop();
                    cnt++;
                    justWeight.erase(justWeight.begin());
                    max = justWeight[0];
                }  
            }
            else{
                int tempWeight = que.front().first;
                int tempIdx = que.front().second;
                que.push({tempWeight, tempIdx});
                que.pop();
            }
        }
    }
}
