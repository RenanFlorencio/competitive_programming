# include <iostream>

using namespace std;
typedef long long ll;

#define MAX_N 500010
ll RA[MAX_N], tempRA[MAX_N];
ll SA[MAX_N], tempSA[MAX_N];
ll c[MAX_N];

void countSort(ll k, ll n) {
    ll i, sum, maxi = max(300LL, n); // 256 ASCII chars or n
    fill(c, c + MAX_N, 0);

    for (i = 0; i < n; i++) {
        ll rank = (i + k < n) ? RA[i + k] : 0;
        c[rank]++;  
    }

    for (i = sum = 0; i < maxi; i++) {
        ll t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (i = 0; i < n; i++) {
        ll rank = (SA[i] + k < n) ? RA[SA[i] + k] : 0;
        tempSA[c[rank]++] = SA[i];
    }

    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}


void construct_SA(string T, ll n){

  ll i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
      countSort(k, n); // Sort SA based on the second rank
      countSort(0, n); // Sort SA based on the first rank

      tempRA[SA[0]] = r = 0;
      for (i = 1; i < n; i++){
          tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++ r ;
      }
      for (i = 0; i < n; i++){
          RA[i] = tempRA[i];
      }
      if (RA[SA[n-1]] == n - 1) break;
  } 
}

int main(){
    string T;
    ll n;

    getline(cin, T);
    T += "$"; // Append a terminal character
    construct_SA(T, T.size());

    for (ll i = 1; i < T.size(); i++){
        cout << SA[i] << " ";
    }
    cout << endl;

    return 0;
}