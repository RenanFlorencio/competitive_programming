# include <iostream>
# include <vector>
using namespace std;
typedef long long ll;

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

ll fact(ll n){

    ll fc = 1;
    for (int i = 1; i <= n; i++){
        fc *= i;
    }
    return fc;
}

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
