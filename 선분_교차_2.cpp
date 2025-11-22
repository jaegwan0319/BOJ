#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef struct {
    ll x;
    ll y;
} point;

point p[4];

//c에 위치에 대해 알아내는 함수
int ccw(point a, point b, point c) {
    long long t1 = a.x * b.y + b.x * c.y + c.x * a.y;
    long long t2 = a.y * b.x + b.y * c.x + c.y * a.x;

    if(t1 - t2 > 0) return 1;
    else if (t1 - t2 == 0) return 0;
    else return -1;
}

bool contained(point A, point B, point C) {
    return (min(A.x,B.x)<=C.x&&max(A.x,B.x)>=C.x&&min(A.y,B.y)<=C.y&&max(A.y,B.y)>=C.y);
}
//같을때는 제외
bool realContained(point A, point B, point C) {
    return (min(A.x,B.x)<C.x&&max(A.x,B.x)>C.x&&min(A.y,B.y)<C.y&&max(A.y,B.y)>C.y);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int i = 0;i<4;i++) {
        cin >> p[i].x >> p[i].y;
    }
    //[0],[1],[2],[3] 을 각각 a,b,c,d라고 하자.
    ll a = ccw(p[2],p[3],p[0]);
    ll b = ccw(p[2],p[3],p[1]);
    ll c = ccw(p[0],p[1],p[2]);
    ll d = ccw(p[0],p[1],p[3]);




    //일반 교차
    if(ccw(p[0],p[1],p[2])*ccw(p[0],p[1],p[3])==-1&&ccw(p[2],p[3],p[0])*ccw(p[2],p[3],p[1])==-1) {
        cout << 1;
        return 0;
    }
    cout << 0;
}