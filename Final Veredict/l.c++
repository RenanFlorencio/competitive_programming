# include <iostream>
# include <map>
# include <vector>
using namespace std;

int solve(){
    long long n, x;
    cin >> n >> x;
    long long in;
    long long soma = 0;
    for (int i = 0; i < n; i++){
        cin >> in;
        soma += in;
    }

    if (soma == x * n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        solve();
    }

    return 0;
}