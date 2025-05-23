#include<iostream>
using namespace std;

int result(int arr[]){
    if( arr[0] == arr[1] && arr[1] == arr[2] ){
        return (10000 + arr[0]*1000);
    }
    else if( arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2] ){
        int max = 0;
        for(int i = 0;i<3;i++){
            if(max < arr[i]) max = arr[i];
        }
        return (max*100);
    }
    else{
        if(arr[0]==arr[1]) return (1000+100*arr[0]);
        else if(arr[0]==arr[2]) return (1000+100*arr[0]);
        else return (1000+100*arr[1]);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,max=0;
    int arr[3];
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<3;j++){
            cin >> arr[j];
        }
        if( max < result(arr)) max = result(arr);
    }
    cout << max;
    return 0;
}
