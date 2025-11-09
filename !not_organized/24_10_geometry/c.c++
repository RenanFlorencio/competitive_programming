# include <algorithm>
# include <iostream>
# include <numeric>

using namespace std;
# define EPS 0.0001

typedef long long ll;
typedef long double ld;

struct line {
    double a, b, c; // Represented using ax + by + c
};

struct vec {
    ld x, y;
    vec (ld _x, ld _y) : x(_x), y(_y) {};
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

point translate(point p, vec v){
    return point(p.x + v.x, p.y + v.y);
}

vec toVec (point a, point b){ // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
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

ld cross(vec a, vec b) { return a.x * b.y - a.y * b.x;}

bool collinear (point p, point q, point r){
    return abs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

int main(){
    ll n;
    ld coord1, coord2;
    cin >> n;
    if (n <= 4){
        cout << "YES" << endl;
    }

    vector<point> points;
    for (ll i = 0; i < n; i++){
        cin >> coord1 >> coord2;
        point p = point(coord1, coord2);
        points.push_back(p);
    }
    cout << collinear(points[0], points[2], points[4]) << endl;

    for (ll i = 2; i < n; i++){
        cout << "AQUI" << endl;
        if (collinear(points[i], points[i - 1], points[i-2])){
            cout << "COLINEAR" << endl;
        }
    }
}