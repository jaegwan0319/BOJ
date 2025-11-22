#include <iostream>
#include <vector>
using namespace std;
typedef struct codinate{
    int x,y,z; 
    struct codinate* link;
} codinate; // 
vector<codinate> v;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    codinate a = {1,2,3};
    //cout << a.x; // 1출력..
    int N;
    cin >> N;
    while (N--){
        int x,y,z;
        cin >> x >> y >> z;
        codinate tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.z = z;
        v.push_back(tmp);
    }
    for(int i = 0;i<v.size();i++){
        cout << v[i].x << " "<< v[i].y << " " << v[i].z << "\n";
    }
}

