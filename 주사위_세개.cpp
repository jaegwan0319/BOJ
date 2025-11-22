#include<iostream>
using namespace std;

int main(void){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if( a[0]==a[1] && a[1]==a[2] ){
        cout << 10000+a[0]*1000;
    }
    else if(a[0]!=a[1]&&a[1]!=a[2]&&a[2]!=a[0]){
        int max=0;
        for(int i = 0;i<3;i++){
            if( max < a[i]){
                max = a[i];
            }
        }
        cout << max*100;
    }
    else {
        if( a[0] == a[1]) cout << 1000+100*a[0];
        else if( a[1] == a[2] ) cout << 1000+100*a[1];
        else cout << 1000+100*a[0];
    }
    return 0;
}