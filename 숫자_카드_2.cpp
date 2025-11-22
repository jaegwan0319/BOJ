#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
    vector<int> have,check,checkcheck;

int binary_search(int target) {
    int left = 0;
    int right = have.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (have[mid] == target) {
            have.erase(have.begin() + mid);
            return mid;  // 찾았을 때 인덱스 반환
        }
        else if (have[mid] < target) {
            left = mid + 1;  // 오른쪽 반 탐색
        }
        else {
            right = mid - 1;  // 왼쪽 반 탐색
        }
    }

    return -1;  // 못 찾은 경우
}

int main(void){
    int N,M;
    vector<int> have,check,checkcheck;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        have.push_back(temp);
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        int temp;
        cin >> temp;
        check.push_back(temp);
    }
    sort(have.begin(),have.end());
    for(int i = 0;i<M;i++){
        int x=0;
        while(binary_search(check[i]) != -1){
            x++;
        }
        checkcheck.push_back(x);
    }
    for(int i = 0;i<M;i++){
        cout << checkcheck[i] << " ";
    }
    return 0;
}