#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <complex>

using namespace std;

typedef long long ll;

vector<complex<ll>> fft(vector<complex<ll>> v, int inverse){
    int n = v.size();
    if(n == 1){
        return v;
    }
    vector<complex<ll>> odd, even;
    for(int i;i<n;i++){
        if(i%2==0){
            even.push_back(v.at(i));
        }
        else{
            odd.push_back(v.at(i));
        }
    }
    even = fft(even,1);
    odd = fft(odd,1);
    complex<ll> wn = exp(complex<ll>(0.0, 2.0 * 3.141592 * inverse / n));
    complex<ll> w = (1.0,0.0);

    vector<complex<ll>> result1,result2,result3;
    for(int i=0; i<n/2;i++){
        complex<ll> t = odd.at(i) * w;
        result1.push_back(even.at(i) + t);
        result2.push_back(even.at(i) - t);
        w *= wn;
    }
    for(complex<ll> d : result2){
        result1.push_back(d);
    }

    if (inverse == -1){
        for(auto &d : result1){
            d /= 2.0;
            result3.push_back(d);
        }
    }else{
        for(auto &d : result1){
            result3.push_back(d);
        }
    }
    return result3;
}

void solve(){
    ll a,b;
    cin >> a >> b;
    int bitlength = floor(log2(a)) + 1;
    int N = (1 << bitlength) + 1;
    string as = to_string(a);
    string bs = to_string(b);
    int leng = as.length();

    vector<complex<ll>> digita, digitb;
    for (int i = 0; i < leng; i++){
        digita.push_back(as[i]-'0');
        digitb.push_back(bs[i]-'0');
    }

    while(digita.size()!=bitlength){
        digita.push_back(0);
        digitb.push_back(0);
    }

    digita = fft(digita,1);
    digitb = fft(digitb,1);

    vector<complex<ll>> digitc;
    for(int i=0;i<leng;i++){
        digitc.push_back(digita.at(i) * digitb.at(i));
    }
    digitc = fft(digitc,-1);
    ll num = 0;

    for (auto it = digitc.rbegin(); it != digitc.rend(); ++it) {
        ll d = llround(it->real());
        num = num * 10 + d;
    }
    cout << num;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}