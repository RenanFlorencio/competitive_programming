# include <iostream>
# include <string>
# include <vector>

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

vector<ll> kasai(string txt, ll* sa, ll n) {
  // This algorithm was taken from https://www.topcoder.com/thrive/articles/suffix-array-lcp-and-finding-unique-substring
  
  vector<ll> lcp(n, 0);

  vector<ll> inverseSuff(n, 0);
  ll i, j;
  for (i = 0; i < n; i++)
    inverseSuff[sa[i]] = i;

  ll k = 0;

  for (i = 0; i < n; i++) {
    if (inverseSuff[i] == n - 1) {
      k = 0;
      continue;
    }

    ll j = sa[inverseSuff[i] + 1];

    while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
      k++;

    lcp[inverseSuff[i]] = k;

    if (k > 0)
      k--;
  }

  return lcp;
}

int main(){
    string s;
    ll k;
    getline(cin, s);
    cin >> k;
    ll n = s.size();
    s += "$";

    construct_SA(s, n + 1);
    vector<ll> lcp;
    lcp = kasai(s, SA, n + 1);

    ll soma = 0;
    ll achei = 0;

    for (int i = lcp.size() - 1; i >= 0; i--){
        soma += lcp[i];
        if (soma >= k){
            achei = i;
            break;
        }
    }
    // cout << "achei " << achei << endl;

    // for (int i = 0; i < lcp.size(); i++){
    //     cout << SA[i] << " ";
    //     soma += i;
    // }
    // cout << endl;

    cout << s.substr(lcp[achei], SA[achei]) << endl;
}