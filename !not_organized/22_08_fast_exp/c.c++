# include <iostream>
# include <vector>
using namespace std;
typedef long long ll;

// APRENDER FIBONACCI

ll recursive(ll n, ll k, vector<ll>b, vector<ll> c){
    if (n < k){
        return b[n];
    }
    ll soma = 0;
    for (int i = 0; i < k; i++){
        soma += c[i] * recursive(n - i - 1, k, b, c);
    }
    return soma % (1000000000);
}


void solve(){
    ll k;
    vector<ll> b;
    vector<ll> c;
    ll n;
    ll res;

    cin >> k;
    for (int i = 0; i < k; i++){
        ll bi;
        cin >> bi;
        b.push_back(bi);
    }
    for (int i = 0; i < k; i++){
        ll ci;
        cin >> ci;
        c.push_back(ci);
    }

    cin >> n;

    if (n - 1 <= k){
        cout << b[n - 1] << endl;
    }
    else{        
        res = recursive(n - 1, k, b, c);
        cout << res % (1000000000) << endl;
    }
}


int main(){

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}