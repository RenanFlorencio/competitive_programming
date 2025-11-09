# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;


int main(){
    ll a, b;
    cin >> a >> b;
    ll result = 1;

    ll diff = b - a;
    
    if (diff >= 10){
        cout << 0 << endl;
        return 0;
    }
    
    for (ll i = a + 1; i <= b; i++){
        result = (result * (i % 10)) % 10;
    }
    
    cout << result << endl;

    return 0;
}