# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;


bool is_prime(ll n){

    if (n == 2){
        return true;
    }
    if (n == 0 || n == 1 || n % 2 == 0){
        return false;
    }

    for (int i = 3; i * i <= n; i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


bool is_tprime(ll n){

    if (n == 1){
        return false;
    }
    ll raiz = sqrt(n);
    if (raiz * raiz == n){
        n = raiz;
        return is_prime(n);
    }
    return false;
}

int main(){

    ll n, x;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        
        if (is_tprime(x)){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}