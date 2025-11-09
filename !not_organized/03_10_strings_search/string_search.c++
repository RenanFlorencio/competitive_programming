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


vector<int> KMPsearch(string P, string T) {
    // Returns the indexes of the matches
    int M = P.size(); int N = T.size();

    vector<int> lps = computeLSarray(P, P.size());
    vector<int> pos;

    int i = 0, j = 0, counter = 0;
    
    while (i < N){
        if (P[j] == T[i]){
            i++; j++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1]; // Reset j
            pos.push_back(i - j);
        }
        // Mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            // Do not need to match all the characters
            if (j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return pos;
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

vector<int> zSearch(string P, string T) {

    string s = P + '$' + T;
    vector<int> z = zFunction(s);
    vector<int> pos;
    int m = P.size();

    for (int i = m + 1; i < z.size(); i++) {
        if (z[i] == m){
            // pattern match starts here in text
            pos.push_back(i - m - 1); 
        }
    }
    return pos;
}


int main(){

    string T = "abaabca";
    string P = "ab";
    cout << KMPsearch(P, T).size() << endl;
    cout << zSearch(P, T).size() << endl;

    return 0;
}