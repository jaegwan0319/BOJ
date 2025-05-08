#include <iostream>
#include <string>

using namespace std;

int getScore(string s){
    int cnt = 0 ,result = 0;
    for (int i = 0; i < s.size(); i++){
        if ( s[i] == 'O' ){
            cnt++;
            result += cnt;
        }
        else if ( s[i] == 'X' ){
            cnt = 0;
        }
    }
    return result;
}

int main(void){
    int T;
    string s;
    cin >> T;
    for (int i = 0; i<T; i++){
        cin >> s;
        cout << getScore(s) << endl;
    }
    return 0;
}
