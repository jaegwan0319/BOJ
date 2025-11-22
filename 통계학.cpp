#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[9001];

int main(void){
    int N;
    int ans1, ans2, ans3, ans4;
    vector<int> v;
    cin >> N;
    for(int i = 0;i<N;i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        arr[temp+4000]++;
    }
    sort(v.begin(),v.end());
    double sum = 0;
    for(int i = 0;i<N;i++){
        sum += v[i];
    }
    if(sum/N < 0){
        ans1 = floor(sum/N - 0.5);
    }
    else{
        ans1 = floor(sum/N + 0.5);
    }
    ans2 = v[(N-1) / 2];
    int maxCount = *max_element(arr,arr+9000);
    int cnt = 0;
    int max;
    for(int i = 0;i<9000;i++){
        if(arr[i] == maxCount){
            max = i-4000;
            cnt++;
        }
        if(cnt == 2){
            break;
        }
    }
    ans3 = max;
    ans4 = v[N-1] - v[0];
    cout << ans1 << "\n";
    cout << ans2 << "\n";
    cout << ans3 << "\n";
    cout << ans4 << "\n";
    return 0;
}