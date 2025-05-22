#include<iostream>
#include<string>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string arr[3];
    int numIndex,result;
    cin >> arr[0] >> arr[1] >> arr[2];
    // 3의 배수만 -> Fizz // 5의 배수만 -> buzz // 둘다 -> Fizzbuzz
    for(int i = 0;i<3;i++){
        if( (arr[i].length() < 4) ) {
            numIndex = i;
            break;
        }
        else if( !( arr[i][3] == 'z') ){
            numIndex = i;
            break;
        }
    }
    switch(numIndex){
        case 0:
            result = stoi(arr[0]) + 3;
            break;
        case 1:
           result = stoi(arr[1]) + 2;
           break;
        case 2:
            result = stoi(arr[2]) + 1;
    }
    // 0->result // 1->Fizz // 2->Buzz // 3-> FizzBuzz
    int a;
    a = ((result%3==0 && result%5==0)?(3):((result%3==0)?(1):((result%5==0)?(2):(0))));
    switch(a){
        case 0:
            cout << result;
            break;
        case 1:
            cout << "Fizz";
            break;
        case 2:
            cout << "Buzz";
            break;
        case 3:
            cout << "FizzBuzz";
    }
    return 0;
}
