#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    string temp;
    vector<int> minus;
    cin >> s;
    stringstream ss(s);

    while(getline(ss,temp,'-')) {
        int sum = 0;    
        stringstream part(temp);
        string num;

        while(getline(part,num,'+')) {
            sum += stoi(num);
        }
        minus.push_back(sum);
    }

    int result = minus[0];
    for(int i = 1;i<minus.size();i++) {
        result -= minus[i];
    }

    cout << result;
    return 0;
}