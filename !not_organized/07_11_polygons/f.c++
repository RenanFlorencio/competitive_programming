# include <vector>
# include <math.h>
# include <cmath>
# include <algorithm>
# include <iostream>

# define EPS 1e-11
# define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef long double ld; 

struct line {
    ld a, b, c; // Represented using ax + by + c
};

struct vec {
    ld x, y;
    vec (ld _x, ld _y) : x(_x), y(_y) {};
};


struct point{
    ld x, y;
    point() { x =  y = 0.0; };
    point (ld _x, ld _y) : x(_x), y(_y) {}
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
};

// make coefficients consistent so identical lines match
void normalize(line &l) {
    ld norm = sqrtl(l.a * l.a + l.b * l.b);
    if (norm < EPS) return;
    l.a /= norm; l.b /= norm; l.c /= norm;
    // fix sign
    if (l.a < -EPS || (fabsl(l.a) < EPS && l.b < -EPS)) {
        l.a = -l.a;
        l.b = -l.b;
        l.c = -l.c;
    }
}

void pointsToLine(point p1, point p2, line &l){
    if (fabsl(p1.x - p2.x) < EPS) {
        l.a = 1.0L; l.b = 0.0L; l.c = -p1.x;
    } else {
        l.a = - (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0L;
        l.c = - (l.a * p1.x) - p1.y;
    }
    normalize(l);
}

// void pointsToLine(point p1, point p2, line &l){
//     if (fabsl(p1.x - p2.x) < EPS) {
//         l.a = 1.0; l.b = 0.0; l.c = -p1.x;
//     }
//     else {
//         l.a = - (ld)(p1.y - p2.y) / (p1.x - p2.x);
//         l.b = 1.0;
//         l.c = - (ld)(l.a * p1.x) - p1.y;
//     }
// }

bool areParallel(line l1, line l2){
    return ((fabsl(l1.a - l2.a)) < EPS && (fabsl(l1.b - l2.b) < EPS));
}

bool areSame(line l1, line l2){
    return areParallel(l1, l2) && fabsl(l1.c - l2.c) < 1e-8;
}

bool pointInLine(line l, point p){
    return fabsl(p.x * l.a + p.y * l.b + l.c) < 1e-7;
}

int main(){

    ll n, k;
    ll x, y;
    vector<point> pts;
    cin >> n >> k;
    
    while (n--){ // Getting all points
        cin >> x >> y;
        point p(x, y);
        pts.push_back(p);
    }
    
    if (k == 1){
        cout << "Infinity" << endl;
        return 0;
    }
    if (k == n){
        cout << 1 << endl;
        return 0;
    }

    // Turning all points to lines
    vector<line> lines;
    ll sz = pts.size();
    for (ll i = 0; i < sz; i++){
        for (ll j = i+1; j < sz; j++){
            line l;
            pointsToLine(pts[i], pts[j], l);
            bool seen = false;
            for (ll r = 0; r < (ll)lines.size(); r++){
                if (areSame(l, lines[r])){
                        seen = true;
                        break;
                    }
                }
            if (!seen){    
                lines.push_back(l);
            }
        }
    }

    vector<ll> pts_in_line (lines.size(), 0);
    ll aceitas = 0;
    for (ll i = 0; i < (ll)lines.size(); i++){
        for (ll j = 0; j < (ll)pts.size(); j++){
            if (pointInLine(lines[i], pts[j])){
                pts_in_line[i] += 1;
            }
        }
        if (pts_in_line[i] >= k) aceitas++;
    }
    cout << aceitas << endl;

    return 0;
}