#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> index[31];

int main(void){
    index[1].push_back("hello");
    index[1].push_back("helloo");
    index[1].push_back("hellooo");
    index[2].push_back("hello");
    index[2].push_back("helloo");

    cout << index[1].length() << "\n" << index[2].length();
    return 0;
}