#include<iostream>
#include<string>

using namespace std;

int main(void){
    int N;
    cin >> N;
    while(N--){
        string input;
        cin >> input;
        if( input.length() >= 6 && input.length() <= 9){
            cout << "yes" << "\n";
        }
        else{
            cout << "no" << "\n";
        }
    }
    return 0;
}
