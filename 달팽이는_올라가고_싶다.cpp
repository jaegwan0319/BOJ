#include<iostream>
using namespace std;

int day = 0;
int a,b,v;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> v;
    day = (v-a) / (a-b) + ((v-a) % (a-b) != 0) + 1;
    cout << day << "\n"; 
}
