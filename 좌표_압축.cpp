#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> v,sorted_v;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        sorted_v.push_back(temp);
    }

    sort(sorted_v.begin(),sorted_v.end());

    map<int, int> m;
    int before;
    int j = 0;
    
    for(int i = 0;i<N;i++){
        if(before == sorted_v[i]) continue;
        
        m[sorted_v[i]] = j;
        before = sorted_v[i];
        j++;
    }

    for(int i = 0;i<N;i++){
        cout << m[v[i]] << " ";
    }

    return 0;
}