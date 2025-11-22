#include<iostream>
using namespace std;

int main(void){
    int N , K;
    cin >> N >> K;

    int i=0, index = 0;
    while(1){
        i++;
        if( N%i == 0 ){
            index++;
            if(index == K){
                cout << i;
                return 0;
            }
        }
        if(i > N){
            cout << 0;
            return 0;
        }
        
    }
    return 0;
}