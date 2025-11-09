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
            // cout << "Found pattern at index " << i - j << endl;
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
    return ;
}

int main() {

    string s, p;
    cin >> s >> p;

    vector<int> pos = KMPsearch(p, s);
    cout << pos.size() << endl;

}