#include <iostream>
#include <string>

using namespace std;

int main(void){
    int T;
    cin >> T;
    for (int i = 0; i<T; i++){
        int R;
        string s;
        cin >> R >> s;
        for (int j = 0; j< s.size(); j++){
            for (int k = 0; k<R; k++){
                cout << s[j];
            }
        }
        cout << endl;
    }
    return 0;
}
