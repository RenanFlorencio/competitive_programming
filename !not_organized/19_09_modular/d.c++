# include <iostream>
# include <math.h>
# include <vector>
# include <map>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ll x, y;
    cin >> x >> y;

    vector<ll> x_values;
    vector<ll> y_values;
    
    for (ll i = 0; i < 5; i++){
        x_values.push_back(0);
        y_values.push_back(0);
    }

    for (ll i = 0; i < max(x, y); i++){
        if (i < x){
            x_values[(i + 1) % 5] += 1;
        }
        if (i < y){
            y_values[(i + 1) % 5] += 1;
        }
    }

    ll soma = 0;
    soma += x_values[0] * y_values[0];

    for (int i = 1; i < 5; i++){
        soma += x_values[i] * y_values[5 - i];
    }

    cout << soma << endl;

    return 0;
}