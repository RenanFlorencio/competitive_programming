# include <string>
# include <vector>
# include <iostream>
# include <stack>
using namespace std;

typedef long long ll;

ll modular(ll base, ll exp, int mod) {
   ll res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}

int main (){

    string s;
    ll n;
    cin >> n >> s;
    
    cout << modular(26, n - s.size(), 1000000000 + 7);


    return 0;
}