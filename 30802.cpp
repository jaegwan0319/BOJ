#include <iostream>
using namespace std;

int main(void){
    int N,size[6],T,P;
    int T_Bundle = 0,P_Bundle,P_Rest;
    cin >> N;
    for(int i = 0; i<6 ; i++){
        cin >> size[i];
    }
    cin >> T >> P;
    for(int i = 0; i<6;i++){
        T_Bundle +=(size[i]%T == 0)? (size[i] / T) : (size[i]/T + 1);
    }
    P_Bundle = N / P;
    P_Rest = N - P*P_Bundle;
    
    cout << T_Bundle << endl << P_Bundle << " " << P_Rest;
    return 0;
}
