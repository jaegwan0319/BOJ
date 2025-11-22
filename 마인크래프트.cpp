#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,B;
    vector<int> ground;
    cin >> N >> M >> B;

    int low=256,high=0;

    for(int i = 0;i<N;i++) {
        for(int j = 0;j<M;j++) {
            int temp;
            cin >> temp;
            ground.push_back(temp);

            low = min(low,temp);
            high = max(high,temp);
        }
    }
    sort(ground.begin(),ground.end());

    //정답 변수
    int time=2147483647,height;

    for(int i = low;i<=high;i++) {
        int fill=0; //해당 높이(i)까지 만들기위해 채워야되는 블록 수
        int block = B; //가지고 있는 블록 수(초기값은 B)
        int tempTime = 0;

        //i보다 높은 블록부터 깎기
        for(int j = 0;j<ground.size();j++) {
            if(ground[j] > i) {
                block += ground[j] - i;
                tempTime += 2 * (ground[j] - i);
            }
        }

        //블록 채우기
        for(int j = 0;j<ground.size();j++) {
            if(ground[j] < i) {
                fill += i - ground[j];
                tempTime += i - ground[j]; 
            }
        }

        if(fill > block) continue;
        else {
            if(tempTime <= time) {
                time = tempTime;
                height = i;
            }
        }
    }

    cout << time << " " << height << "\n";
    return 0;
}