#include<iostream>
#include<vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K,ans=0;
    vector<int> value;
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        if(temp > K){}
        else{
            value.push_back(temp);
        }
    }
    for(int i = value.size()-1;i>=0;i--){
        int temp;
        temp = K/value[i];
        ans += temp;
        K -= temp*value[i];
        if(K == 0){
            break;
        }
    }
    cout << ans;
    return 0;
}