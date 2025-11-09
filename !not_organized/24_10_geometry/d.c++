# include <algorithm>
# include <iostream>
# include <numeric>

using namespace std;
# define EPS 0.0001

typedef long long ll;

struct line {
    double a, b, c; // Represented using ax + by + c
};

struct point{
    double x, y;
    point() { x =  y = 0.0; };
    point (double _x, double _y) : x(_x), y(_y) {}
};

void pointsToLine(point p1, point p2, line &l){
    if (abs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }
    else {
        l.a = - (double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = - (double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2){
    return ((abs(l1.a - l2.a)) < EPS && (abs(l1.b - l2.b) < EPS));
}

bool areSame(line l1, line l2){
    return areParallel(l1, l2) && (abs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p){
    if (areParallel(l1, l2)) return false; // no intersection if are parallel

    // Solve system of 2 linear equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (abs(l1.b)> EPS) p.y = - (l1.a * p.x + l1.c);
    else p.y = - (l2.a * p.x + l2.c);

    return true;
}

int solve(){
    ll coord1, coord2, coord3, coord4;
    cin >> coord1 >> coord2 >> coord3 >> coord4;
    point p1 = point(coord1, coord2);
    point p2 = point(coord3, coord4);
    line l1 = line();
    pointsToLine(p1, p2, l1);

    cin >> coord1 >> coord2 >> coord3 >> coord4;
    p1 = point(coord1, coord2);
    p2 = point(coord3, coord4);
    line l2 = line();
    pointsToLine(p1, p2, l2);

    point p = point();

    if (areSame(l1, l2)){
        cout << "LINE" << endl;
        return 0;
    }
    
    if (areIntersect(l1, l2, p)){
        printf("POINT %.2f %.2f\n", p.x, p.y);
    }
    else {
        cout << "NONE" << endl;
    }
    return 0;
}

int main(){

    ll t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while (t--){
        solve();
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}