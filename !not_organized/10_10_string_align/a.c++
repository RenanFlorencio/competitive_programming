# include <string>
# include <vector>
# include <iostream>
# include <stack>
using namespace std;

typedef long long ll;

void solve(){
  string s;
  bool can_merge = true;
  cin >> s;
  ll counter = 1;
  ll last = s[0];
  for (ll i = 1; i < s.size(); i++){
    if (s[i] != last){

      if (s[i] < last){
        counter++;
      }
      else if (s[i] > last){
        if (can_merge){
          can_merge = false;
        }
        else{
          counter ++;
        }
      }
    
    }
    last = s[i];
  }
  cout << counter << endl;

}
int main(){
  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}