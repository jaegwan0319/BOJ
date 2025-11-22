#include<iostream>
#include<vector>
using namespace std;
vector<int> v(10);

int main(void){
    cout << v.size();
    cout << v[0];
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
    v.resize(100,5);
    cout << v.size();
    for(int i = 0;i<v.size();i++){
        cout << v[i] << " ";
    }
}