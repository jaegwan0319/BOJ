#include<bits/stdc++.h>
using namespace std;

deque<int> deq;
string s; //함수 호출 string
int N; //배열 크기.
string arr; //배열 문자열 받음.

void R(void) {

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        deq.clear(); // vector초기화
        cin >> s;
        cin >> N;
        cin >> arr;
        int error = 0;
        int isReverse = 0; // 1이면 뒤집힌거.

        arr[0] = ','; arr[arr.length()-1] = ',';

        stringstream ss(arr);
        string temp;
        if(N!=0) {
            while(getline(ss,temp,',')) {
                if(temp.length() == 0) {
                    continue;
                }

                int tempNum;
                tempNum = stoi(temp);
                deq.push_back(tempNum);
        }
        }

        for(int i = 0;i<s.length();i++) {
            if(s[i] == 'R') {
                if(isReverse == 0) {
                    isReverse = 1;
                }
                else {
                    isReverse = 0;
                }
            }
            else {
                if(deq.size() == 0) {
                    error = 1;
                    continue;
                }
                N--;
                if(isReverse == 0) deq.pop_front();
                else deq.pop_back();
            }
        }
        if(error == 1) {
            cout << "error\n";
            continue;
        }
        cout << "[";
        if(isReverse == 0) {
            for(int i = 0;i<N;i++) {
                cout << deq[i];
                if(i == N-1) break;
                cout << ",";
            }
        }
        else {
            for(int i = N-1;i>=0;i--) {
                cout << deq[i];
                if(i == 0) break;
                cout << ",";
            }
        }
        cout << "]\n";
    }
    return 0;
}