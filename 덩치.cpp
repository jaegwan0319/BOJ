#include<iostream>
#include<vector>

using namespace std;
int weight[51];
int height[51];
int grade[51];

void getGrade(int N){
    for(int i = 0;i<N;i++){
        grade[i] = 1;
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if( weight[i] < weight[j] && height[i] < height[j] ){
                grade[i]++;
            }
        }
    }
    for(int i = 0;i<N;i++){
        cout << grade[i] << " ";
    }

}
int main(void){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> weight[i] >> height[i];
    }
    getGrade(n);
    return 0;
}