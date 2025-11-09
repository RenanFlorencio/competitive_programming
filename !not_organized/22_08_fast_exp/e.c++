# include <iostream>
# include <vector>
using namespace std;
typedef long long ll;

const int MAX_N = 3;
const ll MOD = 1000000009;
struct Matrix {ll mat[MAX_N][MAX_N]; };
Matrix mem;
ll n_mem = 0;

Matrix matmul(Matrix a, Matrix b){
    Matrix ans;
    for (int i = 0; i < MAX_N; i++){
        for(int j = 0; j < MAX_N; j++){
            ans.mat[i][j] = 0;
            for (int k = 0; k < MAX_N; k++){
                ans.mat[i][j] = (ans.mat[i][j] + ((a.mat[i][k] % MOD) * (b.mat[k][j] % MOD)) % MOD) % MOD;
            }
        }
    }
    return ans;
}

Matrix matrixpow(Matrix base, ll n) {

    Matrix ans;
    for (int i = 0; i < MAX_N; i++){
        for (int j = 0; j < MAX_N; j++){
            ans.mat[i][j] = (i == j);
        }
    }

    while (n > 0){
        if (n % 2){
            ans = matmul(ans, base);
        }
        base = matmul(base, base);
        n /= 2; 
    }
    
    return ans;
}

void solve(ll in){
    
    Matrix ans;
    ans.mat[0][0] = 1; ans.mat[0][1] = 1; ans.mat[0][2] = 1;
    ans.mat[1][0] = 1; ans.mat[1][1] = 0; ans.mat[1][2] = 0;
    ans.mat[2][0] = 0; ans.mat[2][1] = 1; ans.mat[2][2] = 0;

    mem = matrixpow(ans, in - 3);

    cout << ((mem.mat[0][0] * 2) % MOD + mem.mat[0][1] % MOD) % MOD << endl;
    
}


int main(){
    
    n_mem = 0;
    ll t;
    cin >> t;
    while (t != 0){
        if (t <= 3){
            cout << t - 1 << endl;
        }
        else{
            solve(t);
        }
        cin >> t;
    }

    return 0;
}