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

//각 선분 기울기, 교점 선언
long double m1, m2;
long double x,y;

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
//두 점이 같은지 확인하는 함수
bool isSame(point A, point B) {
    return (A.x==B.x && A.y==B.y);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    cout << fixed;


    for(int i = 0;i<4;i++) {
        cin >> p[i].x >> p[i].y;
    }
    //[0],[1],[2],[3] 을 각각 a,b,c,d라고 하자.
    ll a = ccw(p[2],p[3],p[0]); // <- 점 a의 위치에 대한 정보
    ll b = ccw(p[2],p[3],p[1]);
    ll c = ccw(p[0],p[1],p[2]);
    ll d = ccw(p[0],p[1],p[3]);

    //교점 계산
    //기울기 구하기
    m1 = ((long double)(p[1].y-p[0].y))/((long double)(p[1].x-p[0].x));
    m2 = ((long double)(p[3].y-p[2].y))/((long double)(p[3].x-p[2].x));
    int key = 0; //둘다 수직 -> 1 | 선분1만 수직 -> 2 | 선분2만 수직 -> 3 | 둘다 수평선 -> 4 | 선분1만 수평 -> 5 | 선분2만 수평 -> 6
    
    //평행할 때
    if(abs(m1-m2) <= 0.000001 || p[3].x - p[2].x == 0 && p[1].x - p[0].x == 0) {
        x = 0, y = 0;
        if(p[3].x - p[2].x == 0 && p[1].x - p[0].x == 0) key = 1;
        if(p[3].y - p[2].y == 0 && p[1].y - p[0].y == 0) key = 4;
    }
    //수직선일 때
    //선분1이 수직선
    else if(p[1].x - p[0].x == 0) {
        x = p[1].x;
        y = m2 * (x - p[2].x) + p[2].y;
        key = 2;
    }
    //선분2가 수직선
    else if(p[3].x - p[2].x == 0) {
        x = p[2].x;
        y = m1 * (x - p[0].x) + p[0].y;
        key = 3;
    }
    //정석 교점
    else {
        x = (m1*p[0].x - m2*p[2].x - p[0].y + p[2].y) / (m1-m2);
        y = m1* (x-p[0].x) + p[0].y;
    }
    //네점이 한 직선 위
    if(a==0&b==0&&c==0&&d==0) {
        //수직선 포함일 때
        if(key == 1) {
            //cout << "debug\n";
            if(min(p[0].y,p[1].y)<p[2].y&&p[2].y<max(p[0].y,p[1].y) || min(p[0].y,p[1].y)<p[3].y&&p[3].y<max(p[0].y,p[1].y) || min(p[2].y,p[3].y)<p[0].y&&p[0].y<max(p[2].y,p[3].y)
        || min(p[2].y,p[3].y)<p[1].y&&p[1].y<max(p[2].y,p[3].y)) {
                cout << 1; return 0;
            }
        }

        //둘다 수평선
        if(key == 4) {
            if(min(p[0].x,p[1].x)<p[2].x&&p[2].x<max(p[0].x,p[1].x) || min(p[0].x,p[1].x)<p[3].x&&p[3].x<max(p[0].x,p[1].x) || min(p[2].x,p[3].x)<p[0].x&&p[0].x<max(p[2].x,p[3].x)
        || min(p[2].x,p[3].x)<p[1].x&&p[1].x<max(p[2].x,p[3].x)) {
                cout << 1; return 0;
            }
        }
        
        //좌표출력X
        if(realContained(p[0],p[1],p[2])||realContained(p[0],p[1],p[3])||realContained(p[2],p[3],p[0])||realContained(p[2],p[3],p[1])) {
            cout << 1; return 0;
        }
        //only한점에서 만남 #1
        if(isSame(p[0],p[2])&&!isSame(p[1],p[3])) {
            cout << 1 << '\n' <<p[0].x << " " << p[0].y;return 0;
        }
        //only한점에서 만남 #2
        if(isSame(p[0],p[3])&&!isSame(p[1],p[2])) {
            cout << 1 << '\n' <<p[0].x << " " << p[0].y;return 0;
        }
        //only한점에서 만남 #3
        if(isSame(p[1],p[2])&&!isSame(p[0],p[3])) {
            cout << 1 << '\n' <<p[1].x << " " << p[1].y;return 0;
        }
        //only한점에서 만남 #4
        if(isSame(p[1],p[3])&&!isSame(p[0],p[2])) {
            cout << 1 << '\n' <<p[1].x << " " << p[1].y;return 0;
        }

        //두 직선이 같음
        if(isSame(p[0],p[2])&&isSame(p[1],p[3])  || isSame(p[0],p[3])&&isSame(p[1],p[2])) {
            cout << 1; return 0;
        }

        //그외
        cout << 0; return 0;
    }

    //세점이 한 직선 위
    if(a==0||b==0||c==0||c==0) {
        if(a==0) {
            if(contained(p[2],p[3],p[0])) {
                cout << 1 << '\n' << x << " " << y; return 0;
            }
            else if(isSame(p[0],p[2]) || isSame(p[0],p[3])) {
                cout << 1 << '\n' << p[0].x << " " << p[0].y; return 0;
            }
        }
        else if(b==0) {
            if(contained(p[2],p[3],p[1])) {
                cout << 1 << '\n' << x << " " << y; return 0;
            }
            else if(isSame(p[1],p[2]) || isSame(p[1],p[3])) {
                cout << 1 << '\n' << p[1].x << " " << p[1].y; return 0;
            }
        }
        else if(c==0) {
            if(contained(p[0],p[1],p[2])) {
                cout << 1 << '\n' << x << " " << y; return 0;
            }
            else if(isSame(p[2],p[0]) || isSame(p[2],p[1])) {
                cout << 1 << '\n' << p[2].x << " " << p[2].y; return 0;
            }
        }
        else if(d==0) {
            if(contained(p[0],p[1],p[3])) {
                cout << 1 << '\n' << x << " " << y; return 0;
            }
            else if(isSame(p[3],p[0]) || isSame(p[3],p[1])) {
                cout << 1 << '\n' << p[3].x << " " << p[3].y; return 0;
            }
        }
        //그외
        
        cout << 0; return 0;
    }

    //일반 교차
    if(a*b==-1 && c*d==-1) {
        cout << 1 << '\n' << x << " " << y; return 0;
    }
    cout << 0;
    return 0;
}