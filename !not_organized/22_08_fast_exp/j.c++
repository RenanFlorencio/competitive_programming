# include <iostream>
# include <vector>
using namespace std;
typedef long long ll;

void solve(){
    ll n, in;
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n; i++){
        cin >> in;
        res = res ^ in;
    }

    cout << (res ? "first\n" : "second\n");
}

int main(){

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}