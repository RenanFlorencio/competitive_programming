# include <algorithm>
# include <iostream>
# include <numeric>
# include <math.h>

typedef long long ll;
typedef long double ld;
using namespace std;
# define EPS 0.0000000001

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

bool areParallel(const line &l1, const line &l2){
    return fabs(l1.a * l2.b - l2.a * l1.b) < EPS;
}

bool areIntersect(line l1, line l2, point &p){
    if (areParallel(l1, l2)) return false; // no intersection if are parallel

    // Solve system of 2 linear equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    if (abs(l1.b)> EPS) p.y = - (l1.a * p.x + l1.c);
    else p.y = - (l2.a * p.x + l2.c);

    return true;
}

ld dist (point p, point q){
    return sqrt(pow(p.x-q.x, 2) + pow(p.y-q.y, 2));
}

ld perim(vector<point> &points){
    ld per = 0;
    per += dist(points[0], points[1]);
    per += dist(points[1], points[2]);
    per += dist(points[2], points[0]);
    return per;
}

bool diff_points(point p1, point p2, point p3){
    if (abs(p1.x - p2.x) < EPS && abs(p1.y - p2.y) < EPS){
        return false;
    }
    if (abs(p1.x - p3.x) < EPS && abs(p1.y - p3.y) < EPS){
        return false;
    }
    if (abs(p2.x - p3.x) < EPS && abs(p2.y - p3.y) < EPS){
        return false;
    }
    return true;
}

bool isCollinear(point p1, point p2, point p3){
    double c = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return abs(c) < EPS;
}

int main(){
    ll n, x1, x2, y1, y2;
    cin >> n;
    vector<line> lines;

    for (int i=0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        point p1 = point(x1, y1);
        point p2 = point(x2, y2);
        line l;
        pointsToLine(p1, p2, l);
        lines.push_back(l);
    }

    vector<vector<point>> possible;

    for (int i =0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                point p1, p2, p3;
                if (areIntersect(lines[i], lines[j], p1) && areIntersect(lines[j], lines[k], p2) && areIntersect(lines[i], lines[k], p3)){
                    if (diff_points(p1, p2, p3) && !isCollinear(p1, p2, p3)){
                        vector<point> curr = {p1, p2, p3};
                        possible.push_back(curr);
                    }
                }
            }
        }
    }

    if (possible.size() == 0){
        cout << "no triangle" << endl;
        return 0;
    }

    ld max = 0;
    for (int i = 0; i < possible.size(); i++){
        ld pr = perim(possible[i]);
        if (pr > max){
            max = pr;
        }
    }
    printf("%.10Lf\n", max);

    return 0;
}