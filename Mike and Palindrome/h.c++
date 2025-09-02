# include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;

    bool found_different = false;
    bool all_equal = true;

    for (int i = 0; i < input.length() / 2; i++){

        if (input[i] != input [input.length() - i - 1]) {
            if (found_different == true){
                cout << "NO" << endl;
                return 0;
            }
            found_different = true;
        }
    }
    if (!found_different && input.length() % 2 == 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}