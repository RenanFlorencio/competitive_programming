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
    string s, t, u;
    cin >> s >> t;
    u = s + "$" + t + "%";
    ll n = u.size();
    cout << "s size " << s.size() << " t size " << t.size() << endl;

    construct_SA(u, n);
    vector<ll> lcp;
    lcp = kasai(u, SA, n);

    for (int i = 0; i < lcp.size(); i++){
        cout << lcp[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        cout << SA[i] << " ";
    }
    cout << endl;

    bool found = false;
    ll max_n = -1;
    ll idx = -1;
    for (int i = 2; i < lcp.size(); i++){
        // if (i >= s.size() - 1 + 2 && i <= s.size() + 2){
        //     continue;
        // }

        if (lcp[i] > max_n){
            if ((SA[i - 2] < s.size() && SA[i-1] > s.size()) || (SA[i-2] > s.size() && SA[i-1] < s.size())){
                max_n = lcp[i];
                idx = i;
            }
        }
    }
    cout << max_n << endl;

    if (max_n == - 1){
        cout << "0 0 0 0" << endl;
    }
    else{
        if (SA[max_n] >= s.size()){
            cout << SA[max_n + 1] << " " << SA[max_n + 1] + lcp[max_n] << " ";
            cout << SA[max_n] - s.size() - 1 << " " << SA[max_n] - s.size() - 1 + lcp[max_n];
        }
        else{
            cout << SA[max_n] << " " << SA[max_n] + lcp[max_n] << " ";
            cout << SA[max_n + 1] - s.size() - 1 << " " << SA[max_n + 1] - s.size() - 1 + lcp[max_n];        
        }
        cout << endl;
    }

}