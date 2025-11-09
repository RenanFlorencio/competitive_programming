# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

ll x0, y0, d;

void extendedEuclid(ll a, ll b){
    if (b == 0) { x0 == 1; y0 == 0; d = a; return ;}

    extendedEuclid(b, a % b);

    ll x1 = y0;
    ll y1 = x0 - (a / b) * y0;
    x0 = x1;
    y0 = y1;
}


int main(){
    
    ll n, s, k;
    // # s + (k.t) % N = 0
    // # (k.t) % N = -S % N
    // x0 = t.r = b/d . r (r vem de euclides) tem que fazer %(n/d) para pegar a primeira solução positiva

    ll b = (-s) % n;
    extendedEuclid(k, n);

    if (b % d != 0){
        cout << -1 << endl;
        return 0;
    }


    ll r0 = (b / d) * x0;
    ll r = r0 % (n / d); // Primeira resposta
    cout << r << endl;


    return 0;
}