# include <algorithm>
# include <iostream>
# include <numeric>

using namespace std;
# define EPS 0.0001

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

bool areIntersect(line l1, line l2, point &p){
    if (areParallel(l1, l2)) return false; // no intersection if are parallel

    // Solve system of 2 linear equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (abs(l1.b)> EPS) p.y = - (l1.a * p.x + l1.c);
    else p.y = - (l2.a * p.x + l2.c);

    return true;
}

int main(){
    point p1 = point(1, 1);
    point p2 = point(2, 2);
    line l1 = line();

    pointsToLine(p1, p2, l1);

    cout << l1.a << endl;
    cout << l1.b << endl;
    cout << l1.c << endl;

    return 0;
}