# include <iostream>
# include <map>
# include <vector>
using namespace std;

int main(){
    int n;
    long long counter = 0;
    cin >> n;
    
    map<int,int> dict;
    vector<int> vetor(n);
    for (int i = 0; i < n; i++){
        cin >> vetor[i];
        if (dict.find(vetor[i] + i) == dict.end()){
            dict[vetor[i] + i] = 1;
        }
        else{
            dict[vetor[i] + i] += 1;
        }
    }

    for (int j = 0; j < n; j++){
        int chave = j - vetor[j];
        if (dict.find(chave) != dict.end()){
            counter += dict[chave];
        }
    }

    cout << counter << endl;

    return 0;
}