#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> s;
vector<string> index[51]; // 문자열 길이는 50까지 있음.
vector<string> realIdx[51];
int indexNum[51];


int compare(string a,string b){
    for(int i = 0;i<a.length();i++){
        if(a[i] < b[i]){
            return 1;
        }
        else if(a[i] > b[i]){
            return 2; // swap 실행
        }
    }
    // for문을 탈출할 경우는 두 문자열이 일치하는 경우밖에 없음
    return 0; //둘중 아무거나 반환.
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        string s1;
        cin >> s1;
        s.push_back(s1);
        index[s1.length()].push_back(s1);
        indexNum[s1.length()]++;
    }
    for(int i = 0;i<51;i++){
        for(int j = 0;j<indexNum[i];j++){
            for(int k=0;k<indexNum[i]-1;k++){
                if(compare(index[i][k],index[i][k+1]) == 0){
                    index[i].erase(index[i].begin() + k);
                    indexNum[i]--;
                }
                else{
                    if(compare(index[i][k],index[i][k+1]) == 2){
                        swap(index[i][k],index[i][k+1]);
                    }                    
                }
            }
        }
    }

    for(int i = 0;i<51;i++){
        for(int j = 0;j<indexNum[i];j++){
            cout << index[i][j] << "\n";
        }
    }
    return 0;
}
