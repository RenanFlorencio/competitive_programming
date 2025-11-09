# include <string>
# include <vector>
# include <iostream>
using namespace std;

typedef long long ll;

vector<int> computeLSarray (string P, ll M){
    
    ll len = 0;
    
    vector<int> lps (M);
    lps[0] = 0;

    ll i = 1;
    while (i < M) { 

        if (P[i] == P[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0){
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            
            // Case 2: reuse the previously computed value
            z[i] = min(r - i + 1, z[k]);
        }

        // Try to extend the Z-box beyond r
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        // Update the [l, r] window if extended
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

void print_array (vector<int> arr){

    for (auto i : arr){
        cout << i << " ";
    }
    cout << endl;
}


int main () {
    string s;
    cin >> s;

    vector<int> lps = computeLSarray(s, s.size());
    vector<int> z = zFunction(s);

    print_array(z);
    print_array(lps);
}