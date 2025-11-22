#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    vector<int> v;
    cin >> N;
    int t = N;
    while(N--){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<t;i++){
        cout << v[i] << "\n";
    }
    return 0;
}