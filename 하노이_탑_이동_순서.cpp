#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair<int,int>> result;

void hanoi(int x,int from,int temp, int to) {
    if(x == 1) {
        result.push_back(pair{from,to});
    }
    else {
        hanoi(x-1,from,to,temp);
        result.push_back(pair{from,to});
        hanoi(x-1,temp,from,to);
    }

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    hanoi(N,1,2,3);

    cout << result.size() << "\n";
    for(pair<int,int> i : result) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}