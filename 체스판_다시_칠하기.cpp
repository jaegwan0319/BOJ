#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<char>> board;
int N,M,minim=2500;

int main(void){
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        vector<char> temp;
        for(int j = 0;j<M;j++){
            char c;
            cin >> c;
            temp.push_back(c);
        }
        board.push_back(temp);
    }    

    for(int i = 0;i<N-7;i++){
        for(int j = 0;j<M-7;j++){
           
            int temp_min,cnt_first=0,cnt_sec=0;
            //#1 왼쪽위가 Black
            for(int k = 0;k<8;k++){
                for(int m = 0;m<8;m++){
                    if((k+m)%2 == 0){
                        if(board[i+k][j+m] == 'W')
                        cnt_first++;
                    }
                    else{
                        if(board[i+k][j+m] == 'B')
                        cnt_first++;
                    }
                
                }
            } //cout << cnt_first << "\n";
            //#2 왼쪽위가 White
            for(int k = 0;k<8;k++){
                for(int m = 0;m<8;m++){
                    if((k+m)%2 == 0){
                        if(board[i+k][j+m] == 'B')
                        cnt_sec++;
                    }
                    else{
                        if(board[i+k][j+m] == 'W')
                        cnt_sec++;
                    }
                
                }
            } //cout << cnt_sec << "\n";
            temp_min = (cnt_first < cnt_sec)?(cnt_first):(cnt_sec);
            minim = (temp_min<minim)?(temp_min):(minim);
        }
    }
    cout << minim;
    return 0;
}