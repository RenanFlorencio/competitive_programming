# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    string in;
    ll x;
    ll idx = 0;
    ll mod;
    ll last_char_idx = 0;
    cin >> in;
    cin >> x;

    for (int i = 0; i < in.size(); i++){

        if ((int)in[i] >= 48 && (int)in[i] <= 57){

            cout << "idx: " << idx << endl;
            ll new_lenght = idx + (((int)in[i] - 48) * idx);
            cout << "new: " << new_lenght << endl;
            if (new_lenght >= x){
                mod = x % last_char_idx;
                cout << "mod: " << mod << endl;
                cout << in[last_char_idx - mod - 1] << endl;
                break;
            }
            else{
                idx = new_lenght;
            }
        }
        else{
            idx += 1;
            last_char_idx += 1;
            cout << "id " << idx << endl;
            if (idx == x && !((int)in[idx - 1] >= 48 && (int)in[idx - 1] <= 57)){
                cout << in[i] << endl;
                break;
            }
        }
    }
    
    return 0;
}