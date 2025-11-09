
typedef long long ll;

struct point{
    double x, y;
    point() { x =  y = 0.0; };
    point (double _x, double _y) : x(_x), y(_y) {}
};

int insideCircle(point p, point c, ll r){
    ll dx = p.x - c.x, dy = p.y - c.y;
    ll Euc = dx*dx + dy*dy, rSq = r*r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; // inside / border / outside
}

