# include <string>
# include <iostream>
# include <vector>

using namespace std;
typedef long long ll;

ll needleman(string p, string q) {

    ll n = p.size(), m = q.size();
    ll i, j, table[n + 30][m + 30];

    for (i = 0; i <= n; i++) table[i][0] = i * -7; // initialize i
    for (j = 0; j <= m; j++) table[0][j] = j * -7; // initialize j

    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            // match: 2 points, mismatch: -1 points
            table[i][j] = table[i-1][j-1] + (p[i-1] == q[j-1] ? 5 : -4);
            // gap: -1 points
            table[i][j] = max(table[i][j], table[i-1][j] - 7); // delete from p
            table[i][j] = max(table[i][j], table[i][j-1] - 7); // delete from q
        }
    }

    // cout << "DP table" << endl;
    // for (i = 0; i <= n; i++){
    //     for (j = 0; j <= m; j++){
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return table[n][m];
}

int main(){

    string query, s;
    vector<string> high;
    vector<ll> score;
    ll maxlen, maxfound = 0;
    bool last_line_empty = false;
    
    getline(cin, s);
    getline(cin, query);
    cout << "The query sequence is:" << endl;
    cout << query << endl << endl;
    
    while (getline(cin, s)){ // throw first line away
        if (s.empty()){
            if (last_line_empty){
                break;
            }
            last_line_empty = true;
            continue;
        }
        if (s[0] == '>'){
            continue;
        }
        last_line_empty = false;
        
        maxlen = needleman(query, s);

        if (maxlen > maxfound){
            high.clear();
            score.clear();
            high.push_back(s);
            score.push_back(maxlen);
            maxfound = maxlen;
        }
        else if (maxlen == maxfound){
            high.push_back(s);
            score.push_back(maxlen);
        }
    }
    cout << "The most similar sequences are:" << endl << endl;
    
    for (int k = 0; k < score.size(); k++){
        cout << high[k] << endl;

        cout << "The similarity score is: " << score[k];

        if (k == score.size() - 1){
            cout << endl;
        }
        else {
            cout << endl << endl;
        }
    }
    
    return 0;
}