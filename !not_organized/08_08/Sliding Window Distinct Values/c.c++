# include <iostream>
# include <queue>
# include <map>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    queue<int> temp;
    map<int, int> dict;
    int in;
    int first_element;
    
    for (int i = 0; i < n; i ++){
        cin >> in;
        temp.push(in);
        
        if (dict.find(in) == dict.end()){
            dict[in] = 1;
        }
        else {
            dict[in] += 1;
        }

        if (i >= k - 1){
            cout << dict.size() << " ";
            first_element = temp.front();
            temp.pop();
            
            dict[first_element] -= 1;
            if (dict[first_element] == 0){
                dict.erase(first_element);
            }
        }
    }
    cout << endl;
}