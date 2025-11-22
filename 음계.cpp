#include <iostream>
#include <string>

using namespace std;

// ascedning >> 0 반환 // descending >> 1 반환 // mix >> 2 반환
int check(int arr[8]){
    for(int i = 0; i<7; i++){
        if ( arr[i+1] == arr[i] + 1 ){
            if ( i == 6 ){
                return 0;
            }
        }
        else break;
    }
    for(int i = 0; i<7; i++){
        if ( arr[i+1] == arr[i] - 1 ){
            if ( i == 6 ){
                return 1;
            }
        }
        else break;
    }
    return 2;
}


int main(void){
    int arr[8];
    for(int i = 0; i<8; i++){
        cin >> arr[i];
    }
    if ( check(arr) == 0 )
        cout << "ascending";
    else if ( check(arr) == 1 )
        cout << "descending";
    else   
        cout << "mixed";
    
    return 0;
}