#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
// 반올림은 floor(x+0.5) 로 구현.

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    double N;
    int exceptNum;
    vector<int> v;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    if(N == 0){
        cout << 0;
    }
    else{
        sort(v.begin(),v.end());

        exceptNum = floor(N*0.15+0.5);
        int startIdx = exceptNum;
        int lastIdx = N-1-exceptNum;
        int sum = 0;
        for(int i = startIdx;i <= lastIdx;i++){
            sum += v[i];
        }
        cout << floor((sum/(N-2*exceptNum)) + 0.5);
    }
    return 0;
}