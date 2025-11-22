#include<iostream>
#include<vector>
#include<string>
using namespace std;

string s1;
string s2;

//s2에 s1에 나왔던 알파벳이 있으면 1반환 없으면 0반환
int check(char c) {
    for(int i = 0;i<s1.length();i++) {
        if(c == s1[i]) return 1;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1;
    cin >> s2;

    for(int i = 0;i<s2.length();i++) {
        if(check(s2[i]) == 1) int x;
        else cout << s2[i];
    }
}