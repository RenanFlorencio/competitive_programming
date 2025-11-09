# include <string>
# include <vector>
# include <iostream>
# include <stack>
using namespace std;

typedef long long ll;

vector<int> calculateLPS (string P, ll M){
    // Returns the lenghts of the borders of the array
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

int main (){

    string s;
    cin >> s;
    stack<int> h;
    vector<int> lps = calculateLPS(s, s.size());
    
    int size = s.size();
    // Look at each border, the remaining section of the string is added to form a period
    // "abcdabc" -> "abc" is border, add "d" and we get 4
    // Do the same for each border, the borders can all be recursively verified
    while (size > 0){
        size = lps[size - 1];
        cout << s.size() - size << " ";
    }

    cout << endl;
    return 0;
}