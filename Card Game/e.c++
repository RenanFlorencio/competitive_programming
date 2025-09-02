# include <iostream>
# include <map>
# include <vector>
using namespace std;

int solve(){
    int n;
    cin >> n;
    char atual;
    char last;
    string s;
    bool a_has_seq = false;

    cin >> s;
    if (n == 2){
        cout << (s[0] == 'B' ? "Bob" : "Alice") << endl;
        return 0;
    }
    if (s[0] == s[n-1]){
        // cout << "regra das quinas " << chars[0] << endl;
        cout << (s[0] == 'B' ? "Bob" : "Alice") << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++){

        if (s[i] == 'B' && s[n - 1] == 'B'){
            cout << "Bob" << endl;
            return 0;
        }

        if (s[i] == 'A' && s[i + 1] == 'A'){
            a_has_seq = true;
        }
        else {
            if (i != n - 2 && s[i] == 'A' && s[i + 1] == 'B'){
                a_has_seq = false;
            }
        }
    }
    if (a_has_seq){
        cout << "Alice" << endl;
        return 0;
    }

    cout << "Bob" << endl;
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