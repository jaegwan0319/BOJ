#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int way; // 1일 경우 가중치 1, 3일 경우 가중치 3
int sum=0,m;

void input(){
    char a,b;
    cin >> a >> b;
    if(a == '*') {
        a = '0';
        way = 1;
    }
    if(b == '*'){
        b = '0';
        way = 3;
    }
    a -= '0'; b -= '0';
    sum += int(a);
    sum += int(b)*3;
}

int main(void){
    for(int i = 0;i<6;i++){
        input();
    }
    cin >> m;
    sum += m;
    for(int i = 0;i<10;i++){
        // if( 10-m == (sum + way*i)%10 ){
        //     cout << i; return 0;
        // }
        if( (sum+i)%10 == 0){
            cout << i;
            return 0;
        }
    }
    return 0;
}