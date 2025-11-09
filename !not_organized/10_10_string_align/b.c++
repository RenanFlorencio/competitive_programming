# include <string>
# include <iostream>

using namespace std;
typedef long long ll;

ll needleman(string p, string q, ll n, ll m) {

    ll i, j, table[n + 10][m + 10];

    for (i = 0; i <= n; i++) table[i][0] = i * 1; // initialize i
    for (j = 0; j <= m; j++) table[0][j] = j * 1; // initialize j

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            // match: 0, mismatch: 1 points
            table[i][j] = table[i-1][j-1] + (p[i-1] == q[j-1] ? 0 : 1);
            // gap: 1
            table[i][j] = min(table[i][j], table[i-1][j] + 1); // delete from p
            table[i][j] = min(table[i][j], table[i][j-1] + 1); // delete from q
        }
    }

    // cout << "DP table" << endl;
    // for (i = 0; i <= n; i++){a
    //     for (j = 0; j <= m; j++){
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return table[n][m];
}

int main(){
    ll n, m, min;
    string p, q;
    while (cin >> n >> p >> m >> q){
        min = needleman(p, q, n, m);
        cout << min << endl;
    }
}