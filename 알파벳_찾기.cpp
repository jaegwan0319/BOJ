#include <iostream>
#include <string>

using namespace std;

// 'a'가 아스키코드로 97이므로 모든 문자별로 -97을 해서
// 각 인덱스에 저장..!

int main(void){
    int arr[26];
    fill(arr,arr+26,-1);
    string word;
    cin >> word;
    for(int i = 0; i < word.size();i ++){
        arr[word[i]-97] = (arr[word[i]-97] == -1)?i:arr[word[i]-97];
    }
    for(int i = 0; i< 26; i++){
        cout << arr[i] << " ";
    }
    return 0;
}