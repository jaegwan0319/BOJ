#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[4],x,y,w,h,min;
    cin >> x >> y >> w >> h;
    arr[0] = x;
    arr[1] = w-x;
    arr[2] = y;
    arr[3] = h-y;
    min = x;
    for(int i = 0;i<4;i++){
        if(min > arr[i] ){
            min = arr[i];
        }
    }
    cout << min;
    return 0;
}
