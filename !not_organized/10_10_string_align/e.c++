# include <string>
# include <iostream>
# include <algorithm>

using namespace std;
typedef long long ll;

ll needleman(string p, string q, ll n, ll m) {

    ll i, j;
    static ll table[1010][1010];

    for (i = 1; i <= n; i++) table[i][0] = 0;
    for (j = 1; j <= m; j++) table[0][j] = 0;

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            // match
            if (p[i-1] == q[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }
            else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    
    return table[n][m];
}

int main(){
    string p, q;
    ll maxlen;
    
    while (getline(cin, p)){
        getline(cin, q);
        maxlen = needleman(p, q, p.size(), q.size());
        cout << maxlen << endl;
    }
}