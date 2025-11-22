#include <iostream>
using namespace std;

int getValue(long long a, int i){
    //계산마다 1234567891로 나눈 후 나머지를 구해서 계속 연산.진행
    long long result;
    for(int k = 0;k<i;k++){
        a *= 31;
        a %= 1234567891;
    }
    result = a;
    return result;
}



// a는 1
int main(void){
    int L;
    long long result = 0;
    char arr[50];
    cin >> L;
    for (int i = 0; i<L; i++){
        cin >> arr[i];
    }
    for(int i = 0;i<L;i++){
        result += getValue(arr[i]-96, i);    
    }
    cout << result%1234567891;
}  