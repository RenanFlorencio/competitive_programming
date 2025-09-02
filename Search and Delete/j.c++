# include <iostream>
# include <queue>
# include <map>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    int in;
    map<int, int> dict;

    for (int i = 0; i < n; i ++){
        cin >> in;
        
        if (dict.find(in) == dict.end()){
            dict[in] = 1;
        }
        else {
            dict[in] += 1;
        }
    }
    for (int i = 0; i < m; i++){
        cin >> in;

        if (dict.find(in) != dict.end()) {
            dict[in] -= 1;
        }
    }
    for (auto itr = dict.begin(); itr != dict.end(); ++itr){
        for (int i = 0; i < itr->second; i++){
            cout << itr->first << " ";
        }
    }
    cout << endl;

    return 0;
}