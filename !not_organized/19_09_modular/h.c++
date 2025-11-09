# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;


int main (){

    ll n;
    cin >> n;
    
    if (n == 0){
        cout <<  1 << endl;
        return 0;
    }
    vector<int> lista = {8, 4, 2, 6};

    cout << lista[(n - 1) % 4] << endl;

    return 0;
}