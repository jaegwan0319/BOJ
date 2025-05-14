#include <iostream>
using namespace std;

int arr[100];

int main(void){
    int N,M;
    int max = 0;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> arr[i];
    }
    for(int i = 0; i<N-2;i++){
        for(int j = i+1;j<N-1;j++){
            for(int k = j+1;k<N;k++){
                int temp = arr[i] + arr[j] + arr[k];
                if( max < temp && temp <= M ){
                    max = temp;

                }
            }
        }
    }

    cout << max;
}
