# include <iostream>
# include <math.h>

typedef long long ll;
typedef long double ld;
using namespace std;

ll fact(ll n){

    ll fc = 1;
    for (int i = 1; i <= n; i++){
        fc *= i;
    }
    return fc;
}

int main(){

    ll n, m;
    cin >> n >> m;

    if (n > m){
        cout << fact(m) << endl;
    }
    else{
        cout << fact(n) << endl;
    }

    return 0;
}