#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L,A,B,C,D;
    cin >> L >> A >> B >> C >> D;
    int math, language;
    math = (A%C == 0)?(A/C):(A/C + 1);
    language = (B%D == 0)?(B/D):(B/D + 1);
    
    cout << L - ((math>language)?math:language);
    return 0;
}