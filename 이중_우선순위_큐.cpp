#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int> pa;

void solve(void) {
    int T;
    cin >> T;
    while(T--) {
        map<int, int> m; //key는 queue에 있는지 확인할 숫자, value는 key숫자가 몇 개 있는지를 나타냄.
        priority_queue<int, vector<int>, greater<int>> minpq;
        priority_queue<int, vector<int>, less<int>> maxpq;
        
        int N;
        cin >> N;
        while(N--) {
            char temp;
            int num;
            cin >> temp >> num;
            if(temp == 'I') {
                minpq.push(num);
                maxpq.push(num);
                m[num]++;
            }
            else if(temp == 'D') {
                while(maxpq.size() >= 1 && m[maxpq.top()] == 0) {
                    maxpq.pop();
                }
                while(minpq.size() >= 1 && m[minpq.top()] == 0) {
                    minpq.pop();
                }

                if(minpq.size() == 0 || maxpq.size() == 0) continue;

                if(num == -1) { //최솟값 삭제
                    int tempNum = minpq.top();
                    if(m[tempNum]==0) continue;
                    m[tempNum]--;
                    minpq.pop();
                }
                else { //최댓값 삭제
                    int tempNum = maxpq.top();
                    if(m[tempNum]==0) continue;
                    m[maxpq.top()]--;
                    maxpq.pop();
                }
            }
        }
        
        while(maxpq.size() >= 1 && m[maxpq.top()] == 0) {
            maxpq.pop();
        }
        while(minpq.size() >= 1 && m[minpq.top()] == 0) {
            minpq.pop();
        }
        if(minpq.size() == 0 || maxpq.size() == 0) {
            cout << "EMPTY\n";
        }
        else {
            cout << maxpq.top() << " " << minpq.top() << '\n';
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}