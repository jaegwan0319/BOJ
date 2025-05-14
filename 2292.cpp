#include <iostream>
using namespace std;

int main(void){
    //원을 기준으로 생각해보면
    //첫번째 원 : 1개
    //두번째 원 : 6개
    //세번째 원 : 12개
    //네번째 원 : 18개
    //다섯번째 원 : 24개

    int N,check = 0,line = 3;;
    int criterion = 12;
    cin >> N;
    
    if( N == 1 ) line = 1;
    else if ( N > 1 && N < 8) line = 2;
    else {
        for(int i = 8; i<=N-1;i++){
            check++;
            if(check == criterion ){
                check = 0;
                line++;
                criterion += 6;
            }
        }
    }

    cout << line;
    return 0;
}
