# include <iostream>
# include <math.h>
# include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
    ll n;
    ld p;
    cin >> n >> p;
    ld ans;

    vector<vector<ld>> a_wins_b(2 * n, vector<ld>(2 * n, 0));

    for (ll a_w = n; a_w >= 0; a_w--){

        for (ll b_w = n; b_w >= 0; b_w--){
            if (a_w == n){
                a_wins_b[a_w][b_w] = 1;
            }
            else if (b_w == n){
                a_wins_b[a_w][b_w] = 0;
            }
            else {
                a_wins_b[a_w][b_w] = p * a_wins_b[a_w + 1][b_w] + (1 - p) * a_wins_b[a_w][b_w + 1];
            }
        }
    }
    printf("%0.2Lf\n", a_wins_b[0][0]);
}


int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }

}