#include<iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;

    cin >> a >> b;

    int max_common = 1 , min_common = 1;

    for(int i = 1; i<= ((a<b)?a:b); i++ ){
        if( a%i == 0 && b%i == 0 ){
            if ( max_common < i) max_common = i;
        }
    }

    for(int i = 1; i<= a*b;i++){
        if( i%a == 0 && i%b == 0 ){
            min_common = i;
            break;
        }
    }

    cout << max_common << '\n' << min_common << '\n';

    return 0;
}
