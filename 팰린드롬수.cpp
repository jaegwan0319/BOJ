#include <iostream>
using namespace std;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int input;
    do{
        int pos = 0;  // input의 자릿수를 나타냄.
        cin >> input;
        
        if( input == 0 ) return 0;
        if( input % 10 == 0 ){
            cout << "no" << endl;
            continue;
        } 

        //자릿수계산.
        int temp = input;
        while(1){
            pos++;
            temp /= 10;
            if( temp == 0 ) break;
        }

        switch (pos){
            case 1:
                cout << "yes" << endl;
                break;

            case 2:
                if( input / 10 == input % 10 ) cout << "yes" << endl;
                else cout << "no" << endl;
                break;

            case 3:
                if( input / 100 == input % 10 ) cout << "yes" << endl;
                else cout << "no" << endl;
                break;

            case 4:
                if( input / 1000 == input % 10 && (input / 100)%10 == (input/10) % 10 ) cout << "yes" << endl;
                else cout << "no" << endl;
                break;

            case 5:
                if( input / 10000 == input % 10 && (input / 1000)%10 == (input/10) % 10 ) cout << "yes" << endl;
                else cout << "no" << endl;
        }



    } while( input != 0 );

}


// #include<iostream>
// using namespace std;

// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cout<<"A"<<"\n";
// }