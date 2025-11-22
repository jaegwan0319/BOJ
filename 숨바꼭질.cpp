#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
void BFS(int start);
int visited[100001]; // visitied 배열에 이동 횟수를 저장 및 체크..
int N,K;
int key = 0;
int ans;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    if(N == K) {
        cout << 0;
        return 0;
    }

    BFS(N);
}

void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty()) {
        int current_pos = q.front();
        q.pop();

        if(current_pos == K) {
            cout << visited[current_pos];
            return;
        }

        if (current_pos-1 >= 0 && visited[current_pos-1] == 0) {
            q.push(current_pos-1);
            visited[current_pos - 1] = visited[current_pos] + 1; 
        }

        if (current_pos+1 <= 100000 && visited[current_pos+1] == 0) {
            q.push(current_pos+1);
            visited[current_pos + 1] = visited[current_pos] + 1; 
        }

        if (current_pos*2 <= 100000 && visited[current_pos*2] == 0) {
            q.push(current_pos*2);
            visited[current_pos*2] = visited[current_pos] + 1; 
        }
    }
}