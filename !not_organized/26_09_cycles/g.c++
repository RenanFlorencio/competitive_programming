#include <iostream>
#include <list>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> vagas;
    vector<ll> estudantes;
    
    ll soma_vagas = 0, soma_estudantes = 0;
    ll in;
    for (int i = 0; i < n; i++){
        cin >> in;
        soma_estudantes += in;
        estudantes.push_back(in);
    }
    for (int i = 0; i < n; i++){
        cin >> in;
        soma_vagas += in;
        vagas.push_back(in);
    }

    if (soma_vagas < soma_estudantes){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> diff;
    for (int i = 0; i < n; i++){
        diff.push_back(vagas[i] - estudantes[i]);
    }

    ll count = 0;
    bool ready = true;
    for(int i = 0; i < n; i++){
        if (diff[i] < 0){
            ready = false;
            break;
        }
    }
    if (ready){
        cout << count << endl;
        return 0;
    }

    for (int i = 1; i < n; i++){
        
        ll new_diff = diff[i] + diff[i - 1];
        cout << new_diff << endl;
        cout << diff[i] << endl;
        if (diff[i - 1] < 0 || new_diff < diff[i - 1]){
            count += 1;
        }
        diff[i] = new_diff;

        ready = true;
        for(int i = 0; i < n; i++){
            if (diff[i] < 0){
                ready = false;
                break;
            }
        }

        if (ready){
            break;
        }
    }
    cout << count << endl;

    return 0;
}