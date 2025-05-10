#include <iostream>
using namespace std;

int findResult(int N){
    int a = 666;
    int cnt = 1;
    while(1){
        int seriesCheck = 0;
        if( N == cnt ) return a;
        a++;
        int num = a;
        while(1){
            if( num == 0 ) break; 
            else if(num % 10 == 6) seriesCheck += 1;
            else seriesCheck = 0;
            
            if ( seriesCheck == 3 ){
                cnt++;   
                break;
            }
            num /= 10;
        }
    }
}


int main(void){
    int N;
    cin >> N;
    cout << findResult(N);
    return 0;
}
