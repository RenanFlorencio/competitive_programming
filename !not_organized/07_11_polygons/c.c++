# include <vector>
# include <math.h>
# include <cmath>
# include <algorithm>
# include <iostream>

# define EPS 0.000000001
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
    bool operator == (point const& t) const {
        return x == t.x && y == t.y;
    }
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

ld dot_product(vec u, vec v){
    return u.x * v.x + u.y * v.y;
}

ld angle(point p1, point p2, point p3){
    vec p1p2 = toVec(p2, p1);
    vec p2p3 = toVec(p2, p3);

    ld dot = dot_product(p1p2, p2p3);
    ld norm = sqrt(dot_product(p1p2, p1p2)) * sqrt(dot_product(p2p3, p2p3));
    ld cos_theta = dot / norm;

    return acos(cos_theta); 
}

bool inPolygon(point p, const vector<point> &P){
    if ((ll)P.size() == 0) return false;
    ld sum = 0; // Assume the first vertex is equal to the last vertex
    for (ll i = 0; i < (ll)P.size()-1; i++){
        if (!cw(p, P[i], P[i+1], true))
            sum += angle(P[i], p, P[i+1]); // left-turn
        else 
            sum -= angle(P[i], p, P[i+1]); // right-turn
    }
    return abs(abs(sum) - 2 * PI) < EPS;
}

void solve(ll t){
    ll x, y, x0, y0;
    vector <point> points;
    while (t--){
        cin >> x >> y;
        point p(x, y);
        points.push_back(p);
    }
    points.push_back(points.front());
    
    cin >> x >> y;
    point q(x, y);
    
    if (inPolygon(q, points)) cout << "T" << endl;
    else cout << "F" << endl;
}

int main(){

    ll t;
    cin >> t;
    while (t != 0){
        solve(t);
        cin >> t;
    }

    return 0;
}