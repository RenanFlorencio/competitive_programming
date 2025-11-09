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

int main(){

    ll n;
    ld cd1, cd2;
    cin >> n;
    vector<line> lines;
    vector<point> points;

    for (ll i = 0; i < n; i++){
        cin >> cd1 >> cd2;
        points.push_back(point(cd1, cd2));
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            if (i != j){
                line l = line();
                pointsToLine(points[i], points[j], l);
                lines.push_back(l);
            }
        }
    }

    ll count = 0;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            if (i != j){
                point p = point();
                if (areIntersect(lines[i], lines[j], p)){
                    count++;
                };
            }
        }
    }
    cout << count << endl;

    return 0;
}