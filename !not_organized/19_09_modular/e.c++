# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;


int main(){

    ll x, k, d;
    cin >> x >> k >> d;

    x = abs(x);

    ll min = x % d;
    ll complement = x / d;

    if (complement > k){
        cout << x - k * d << endl;
        return 0;
    }

    // Even amount more steps
    if ((k - complement) % 2 == 0){
        cout << min << endl;
    }
    // Odd amount more steps
    else{
        cout << abs(min - d) << endl;
    }

    return 0;
}