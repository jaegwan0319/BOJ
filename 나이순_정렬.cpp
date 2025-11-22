#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int N;
    vector<pair<int, int>> age;
    vector<string> name;
    cin >> N;
    for(int i = 0;i<N;i++){
        int tempAge;
        string tempName;
        cin >> tempAge >> tempName;
        age.push_back(make_pair(tempAge,i));
        name.push_back(tempName);
    }
    sort(age.begin(),age.end());
    for(int i = 0;i<N;i++){
        cout << age[i].first << " " << name[age[i].second] << "\n";
    }
    return 0;
}