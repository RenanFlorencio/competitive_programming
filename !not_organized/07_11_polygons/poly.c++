# include <vector>
# include <math.h>
# include <cmath>
# include <algorithm>

# define EPS 0.0000000001
# define PI 3.14159265359
using namespace std;
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


vec toVec (point a, point b){ // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

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

struct point {
    double x, y;
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
};

int orientation(point a, point b, point c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(point a, point b, point c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(point a, point b, point c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<point>& a, bool include_collinear = false) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<point> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
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

ld dot_product(vec u, vec v){
    return u.x * v.x + u.y * v.y;
}

vec normalize(vec u){
    vec res(0,0);
    ld norm = sqrt(pow(u.x, 2) + pow(u.y, 2));
    res.x = u.x / norm;
    res.y = u.y / norm;
    return res;
}

bool ccw (point p1, point p2, point p3){
    vec p1p2 = toVec(p1, p2);
    vec p1p3 = toVec(p1, p3);

    ld dot = p1p2.x * p1p3.x + p1p2.y * p1p3.y;
    if (dot < EPS) return true;
    return false;
}

ld angle(point p1, point p2, point p3){
    vec p1p2 = toVec(p1, p2);
    vec p1p3 = toVec(p1, p3);
    
    return acos(dot_product(p1p2, p1p3) / dot_product(normalize(p1p2), normalize(p1p3)));
}

bool  isConvex(const vector<point> &P){
    ll sz = (ll)P.size();
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 0; i < sz-1; i++){
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;
    }
    return true;
}

bool inPolygon(point p, const vector<point> &P){
    if ((ll)P.size() == 0) return false;
    ld sum = 0; // Assume the first vertex is equal to the last vertex
    for (int i = 0; i < (ll)P.size()-1; i++){
        if (ccw(p, P[i], P[i+1]))
            sum += angle(P[i], p, P[i+1]); // left-turn
        else 
            sum -= angle(P[i], p, P[i+1]); // right-turn
    }
    return abs(abs(sum) - 2 * PI) < EPS;
}