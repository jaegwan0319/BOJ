#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, char> pa; //숫자와, 연산자 묶음

//전역변수 선언
vector<pa> history(10005); //초기화 안해도 될듯?
bool visited[10005]{};

int L(int x) {
    int d1,d2,d3,d4;
    d1 = x/1000;
    x -= d1*1000;
    d2 = x/100;
    x -= d2*100;
    d3 = x/10;
    x -= d3*10;
    d4 = x;

    int ans;
    ans = d2*1000 + d3*100 + d4*10 + d1;
    return ans;
}

int R(int x) {
    int d1,d2,d3,d4;
    d1 = x/1000;
    x -= d1*1000;
    d2 = x/100;
    x -= d2*100;
    d3 = x/10;
    x -= d3*10;
    d4 = x;

    int ans;
    ans = d4*1000 + d1*100 + d2*10 + d3;
    return ans;
}

void solve(void) {
    int T;
    cin >> T;
    while(T--) {
        int a,b;
        fill(&visited[0], &visited[10001], false);
        vector<char> s; //정답 string
        cin >> a >> b;

        queue<int> q;
        q.push(a);
        visited[a] = true;

        while(!q.empty()) {
            int cur = q.front();
            int next;
            q.pop();

            if(cur == b) {
                int check = cur;
                while(check != a) {
                    s.push_back(history[check].second);
                    check = history[check].first;
                }
                break;
            }

            //D
            next = cur*2 % 10000;
            if(visited[next] == false) {
                history[next] = {cur, 'D'};
                q.push(next);
                visited[next] = true;
            }
            //S
            next = (cur+10000-1) % 10000;
            if(visited[next] == false) {
                history[next] = {cur, 'S'};
                q.push(next);
                visited[next] = true;
            }
            //L
            next = L(cur);
            if(visited[next] == false) {
                history[next] = {cur, 'L'};
                q.push(next);
                visited[next] = true;
            }
            //R
            next = R(cur);
            if(visited[next] == false) {
                history[next] = {cur, 'R'};
                q.push(next);
                visited[next] = true;
            }
        }

        for(int i = s.size()-1;i>=0;i--) {
            cout << s[i];
        }
        cout << '\n';
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}