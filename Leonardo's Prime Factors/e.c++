# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<ll> sieve(ll n){
    vector<bool> isPrime(n + 2, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (ll i = 2; i * i <= n; i++){
        if (isPrime[i]){            
            for (int j = i * i; j <= n; j+= i){
                isPrime[j] = false;   
            }
        }
    }
    vector<ll> primes;
    for (int i = 2; i < isPrime.size(); i++){
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

void solve(vector<ll> &primes){
    ll x;
    cin >> x;
    __int128_t soma = 1;
    ll p_idx = 0;

    while (soma <= x){
        soma *= primes[p_idx++];
    }
    cout << p_idx - 1 << endl;
}


int main(){
    ll t;
    cin >> t;
    vector<ll> primes = sieve(100);
    while (t--){
        solve(primes);
    }
    return 0;
}