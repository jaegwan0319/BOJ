#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,N;
    stack<int> stack;
    vector<char> ans;
    cin >> n;
    N = n;
    int i = 1;
    while(n--){
        int num;
        cin >> num;
        if(stack.size() == 0){
            for(;i<=num;i++){
                stack.push(i);
                ans.push_back('+');
                //cout << i << "\n";
            }
        }
        
        if(stack.top() == num){
            stack.pop();
            ans.push_back('-');
            //cout << "x\n";
        }
        else if(num < i){
            cout << "NO";
            return 0;
        }
        else if(num >= i){
            for(;i<=num;i++){
                stack.push(i);
                ans.push_back('+');
                //cout << "c" << num << "\n";
            }
            stack.pop();
            ans.push_back('-');
        }
    }
    for(int j = 0;j<2*N;j++){
        cout << ans[j] << "\n";
    }
    return 0;
}