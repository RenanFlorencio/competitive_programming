# include <iostream>
using namespace std;
typedef long long ll;

void solve(){
    
    string c;
    getline(cin, c);
    
    while (c != "*"){
        getline(cin, c);
    }

    string teste;
    while(getline(cin, teste)){
        if(teste.empty()){
            cout << "Fim de teste\n";
        }
        cout << teste << endl;
    }
}


int main(){

    int t;
    cin >> t;
    while (t--){
        solve();
    }

    return 0;
}

