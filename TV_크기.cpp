#include<iostream>
#include<math.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D,H,W;
    cin >> D >> H >> W;
    double k = double(D*D) / (H*H + W*W);
    int width,height;
    height = int(sqrt(k)*H);
    width = int(sqrt(k)*W);
    cout << height << " " << width;
    return 0;
}