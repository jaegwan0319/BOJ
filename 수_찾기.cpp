#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    vector<int> arr; // 들어있는 수
    vector<int> check; // check할 수
    vector<int> is_exist; // 존재여부 1 : 존재, 0 : 존재X
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        int temp;
        cin >> temp;
        check.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0;i<M;i++){
        if(binary_search(arr.begin(),arr.end(),check[i])){
            is_exist.push_back(1);
        }
        else {
            is_exist.push_back(0);
        }
    }

    for(int i = 0;i<M;i++){
        cout << is_exist[i] << "\n";
    }
    return 0;
}
// 이분탐색(binary_search) 하려면 반드시 sort (오름차순 정리) 하고 이용.