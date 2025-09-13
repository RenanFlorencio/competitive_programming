# include <iostream>
# include <math.h>

typedef long long ll;
typedef long double ld;
using namespace std;

bool is_prime(ll n){

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    ll x;
    cin >> x;

    if (x == 0){
        cout << 1 << endl;
        return 0;
    }
    if (x == 1){
        cout << 2 << endl;
        return 0;
    }

    while (!is_prime(x)){
        x ++;
    }
    cout << x << endl;

    return 0;
}