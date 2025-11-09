# include <iostream>
# include <math.h>
# include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;


// FIND k*mu

// O algoritmo de Floyd explora o fato de que, para um índice
// i > µ, xi = xi+kλ, para um inteiro k > 0, pois tem ciclo. 
// Desse modo, ao fazer // i = kλ tem-se xi = x_2i.

// O algoritmo mantém dois ponteiros, a tartaruga (mais lenta,
// que anda um passo por vez) que aponta xi e a lebre (mais
// rápida, que anda dois passos por vez) que aponta x2i.

// Desse modo, o algoritmo procura pelo menor valor de i tal que
// xi = x2i, o que implica que o valor de i = kλ.

// OBTENDO mu
// Na fase 2, a lebre volta a apontar para x0 e a tartaruga
// mantém-se na i-ésima posição.
// Nessa fase, a lebre e a tartaruga avançam uma casa por
// iteração, mantendo-se separados por kλ casas.
// Assim que a lebre e a tartaruga estiverem apontando para o
// mesmo valor, encontrou-se a primeira repetição de tamanho
// kλ.
// Como kλ é múltiplo de λ, tem-se que xµ = xµ+kλ, portanto a
// posição apontada pela lebre corresponde a µ.

// OBTENDO lambda λ
// • Uma vez encontrado o valor de µ, a tartaruga mantém-se em
// sua posição e a lebre é deslocada para a casa seguinte à da
// tartaruga.
// • Em seguida, a lebre avança uma casa por vez enquanto a
// tartaruga mantém-se estacionada.
// • Quando a lebre e a tartaruga apontarem para o mesmo valor,
// tem-se que elas estarão separadas por λ casas.
// • No exemplo abaixo, tem-se λ = 2.


ll floydCircleFinding(ll x0, ll *mu, ll *lambda){
    // f(x) is defined earlier
    
    // 1st: find k*mu
    ll tortoise = f(x0), hare = f(f(x0)); // hare is 2x as fast
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }

    // 2nd: finding mu, hare and tortoise move at same speed; hare resets
    hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); *mu ++; }

    // 3rd: finding lamda, hare moves, tortoise stays;
    hare = f(tortoise); // one step after the tortoise
    while (tortoise != hare) { hare = f(hare); *lambda ++; }
    
}


int main(){



    return 0;
}