# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<ll> sieve(ll n){
    vector<bool> isPrime(n + 1, true);
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
    ll n;
    cin >> n;
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    ll PF_idx = 0, PF = primes[PF_idx], ans = n;
    
    while (n != 1 && (PF * PF <= n)){
        if (n % PF == 0) ans -= ans / PF; // reduce each time there is a factor
        
        while (n % PF == 0) n /= PF; // reduce N as much as possible
        PF = primes[++PF_idx];
    }
    if (n != 1) ans -= ans / n; // n itself is a prime
    
    cout << ans << endl;
}


int main(){
    ll t;
    cin >> t;
    vector<ll> primes = sieve(pow(10,6) + 10);
    while (t--){
        solve(primes);
    }
    return 0;
}