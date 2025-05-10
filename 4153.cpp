#include <iostream>
using namespace std;

int main(void){
    int input[3], max = 0;
    while(1){
        cin >> input[0] >> input[1] >> input[2];
        if( input[0] + input[1] + input[2] == 0 ) break;
        
        if ( input[0]*input[0] == input[1]*input[1] + input[2]*input[2]){
            cout << "right" << endl;
            
        }
        else if ( input[1]*input[1] == input[0]*input[0] + input[2]*input[2]){
            cout << "right" << endl;
            
        }
        else if ( input[2]*input[2] == input[1]*input[1] + input[0]*input[0]){
            cout << "right" << endl;
            
        }
        else cout << "wrong" << endl;

    }
    return 0;
}
