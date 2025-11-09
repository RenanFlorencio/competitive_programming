# include <iostream>
# include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){

    ld n;
    cin >> n;
    ld sqrt2 = sqrt(2);
    ld res;
    if (n <= 1){
        res = 2.0;
    }
    else{
        res = n * sqrt2;
    }

    printf("%.12Lf\n", res);
}

