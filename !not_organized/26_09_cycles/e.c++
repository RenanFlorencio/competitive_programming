# include <iostream>
# include <math.h>
# include <vector>
# include <map>
# include <set>
# include <tuple>
typedef long long ll;
typedef long double ld;
using namespace std;



int main(){
    ll l, n;
    cin >> l >> n;

    // char, posição, quantidade
    map<ll, set<char>> pos_char;
    map<char, bool> seen_char;
    string in;

    for (int i = 0; i < n; i++){
        cin >> in;
        for (int k = 0; k < l; k++){
            pos_char[k].insert(in[k]);
        }
    }

    ll count = 0;

    for (int i = 0; i < l; i++){

        set letters = pos_char[i];

        for (auto letter : letters){
            // cout << letter << endl;
            if (seen_char.find(letter) == seen_char.end()){
                seen_char[letter] = true;
            }
            else{
                // cout << letter << endl;
                count ++;
            }
        }
    }
    if (count >= n - 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    //cout << count << endl;
}