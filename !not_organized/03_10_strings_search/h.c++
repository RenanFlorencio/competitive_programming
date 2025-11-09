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
    vector<int> lps = calculateLPS(s, s.size());
 
    stack<int> aux;
    int lenght = lps[lps.size() - 1];

    while (lenght > 0){
        aux.push(lenght);
        lenght = lps[lenght - 1];
    }

    while (!aux.empty()){
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << endl;

    return 0;
}