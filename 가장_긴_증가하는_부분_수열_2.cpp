#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pa;

//전역변수 선언
vector<int> A;
vector<int> result;
vector<int> ans;

void binary_search(int input) {
    int start = 0;
    int end = result.size();
    int mid;

    while(start<end) {
        mid = (start+end)/2;
        
        if(result[mid] >= input) {
            end = mid;
        }
        else if(result[mid] < input) {
            start = mid+1;
        }
    }
    result[start] = input;
}

void solve(void) {
    int N;
    cin >> N;
    for(int i = 0;i<N;i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    result.push_back(A[0]);
    
    for(int i = 1;i<N;i++) {
        if(A[i] > result.back()) {
            result.push_back(A[i]);
        }
        else {
            binary_search(A[i]);
        }
        // for(int i : result) {
        //         cout << i << " ";
        //     }
        //     cout <<'\n';
    }

    cout << result.size();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
