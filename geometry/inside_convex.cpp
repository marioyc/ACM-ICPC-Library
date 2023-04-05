struct point{
    ll x, y;
    point(){}
    point(ll _x, ll _y) : x(_x), y(_y) {}
};

ll area(const point &p1, const point &p2, const point &p3){
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x);
}

// 0: outside
// 1: inside
// 2: on border
int isInConvex(vector<point> &A, const point P){
    // polygon should be in ccw order
    // if(!ccw(A)) reverse(A.begin(),A.end());
    int n = A.size();

    ll a1 = area(A[0], A[1], P);
    if(a1 < 0) return 0;
    if(a1 == 0){
        if(P.x < min(A[0].x, A[1].x) || P.x > max(A[0].x, A[1].x)) return 0;
        if(P.y < min(A[0].y, A[1].y) || P.y > max(A[0].y, A[1].y)) return 0;
        return 2;
    }
    ll a2 = area(A[n - 1], A[0], P);
    if(a2 < 0) return 0;
    if(a2 == 0){
        if(P.x < min(A[0].x, A[n - 1].x) || P.x > max(A[0].x, A[n - 1].x)) return 0;
        if(P.y < min(A[0].y, A[n - 1].y) || P.y > max(A[0].y, A[n - 1].y)) return 0;
        return 2;
    }

    int lo = 1,hi = n - 1,mi;
    while(hi - lo > 1){
        mi = (lo + hi) / 2;
        
        if(area(A[0], A[mi], P) > 0) lo = mi;
        else hi = mi;
    }

    ll a3 = area(A[lo], A[lo + 1], P);
    if(a3 == 0) return 2;
    if(a3 < 0) return 0;
    return 1;
}
