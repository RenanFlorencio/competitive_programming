# include <algorithm>
# include <iostream>
# include <numeric>

using namespace std;
# define EPS 0.000001

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
};

void pointsToLine(point p1, point p2, line &l){
    if (abs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }
    else {
        l.a = - (ld)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = - (ld)(l.a * p1.x) - p1.y;
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

int main(){

    ld coordx1, coordy1, coordx2, coordy2, coordx3, coordy3, coordx4, coordy4; 
    while (cin >> coordx1){
        cin >> coordy1 >> coordx2 >> coordy2 >> coordx3 >> coordy3 >> coordx4 >> coordy4;
        point p1 = point(coordx1,coordy1);
        point p2 = point(coordx2, coordy2);
        point p3 = point(coordx3, coordy3);
        point p4 = point(coordx4, coordy4);
        
        point out;
        vec atob = vec(0., 0.);
        if (abs(coordx3 - coordx1) < EPS && abs(coordy3 - coordy1) < EPS){ 
            atob = toVec(p1, p2);
            out = translate(p4, atob);
        }
        else if (abs(coordx4 - coordx1) < EPS && abs(coordy4 - coordy1) < EPS){ 
            atob = toVec(p1, p2);
            out = translate(p3, atob);
        }
        else if (abs(coordx3 - coordx2) < EPS && abs(coordy3 - coordy2) < EPS){ 
            atob = toVec(p2, p1);
            out = translate(p4, atob);
        }
        else {
            atob = toVec(p2, p1);
            out = translate(p3, atob);
        }
        
        printf("%.3Lf %.3Lf\n", out.x, out.y);
    }
    return 0;
}