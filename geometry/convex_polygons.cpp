// sample submission: https://codeforces.com/contest/87/submission/323095058

struct point{
    ll x, y;
    point(){}
    point(ll _x, ll _y) : x(_x), y(_y) {}
};

ll signed_area(const point &p1, const point &p2, const point &p3){
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x);
}

// Point in convex polygon: https://cp-algorithms.com/geometry/point-in-convex-polygon.html
// 0: outside
// 1: inside
// 2: on border
int is_in_convex(vector<point> &A, const point P){
    // polygon should be in ccw order
    // if(!ccw(A)) reverse(A.begin(),A.end());
    int n = A.size();
 
    auto a1 = signed_area(A[0], A[1], P);
    if(a1 < 0) return 0;
    if(a1 == 0){
        if(P.x < min(A[0].x, A[1].x) || P.x > max(A[0].x, A[1].x)) return 0;
        if(P.y < min(A[0].y, A[1].y) || P.y > max(A[0].y, A[1].y)) return 0;
        return 2;
    }
    auto a2 = signed_area(A[n - 1], A[0], P);
    if(a2 < 0) return 0;
    if(a2 == 0){
        if(P.x < min(A[0].x, A[n - 1].x) || P.x > max(A[0].x, A[n - 1].x)) return 0;
        if(P.y < min(A[0].y, A[n - 1].y) || P.y > max(A[0].y, A[n - 1].y)) return 0;
        return 2;
    }
 
    int lo = 1,hi = n - 1,mi;
    while(hi - lo > 1){
        mi = (lo + hi) / 2;
        
        if(signed_area(A[0], A[mi], P) > 0) lo = mi;
        else hi = mi;
    }
 
    auto a3 = signed_area(A[lo], A[lo + 1], P);
    if(a3 == 0) return 2;
    if(a3 < 0) return 0;
    return 1;
}

// Minkowski sum of convex polygons: https://cp-algorithms.com/geometry/minkowski.html
vector<point> convex_polygon_sum(vector< vector<point> > pol){
    int npol = pol.size();
    vector<int> sz(npol);
    vector<int> pos(npol, 0);
    // for each polygon find the leftmost point (if tied, pick the lowest)
    for(int i = 0;i < npol;++i){
        sz[i] = pol[i].size();
        auto best = pol[i][0];
        for(int j = 1;j < sz[i];++j){
            auto p = pol[i][j];
            if(p.x <  best.x || (p.x == best.x && p.y < best.y)){
                pos[i] = j;
                best = p;
            }
        }
    }
    vector<point> H;
    point sum{0, 0},nxt[3];
    for(int i = 0;i < npol;++i){
        sum.x += pol[i][ pos[i] ].x;
        sum.y += pol[i][ pos[i] ].y;
    }
    H.push_back(sum);
    do{
        // compute the directions
        for(int i = 0;i < npol;++i){
            auto &aux = nxt[i];
            aux.x = -pol[i][ pos[i] ].x;
            aux.y = -pol[i][ pos[i] ].y;
            if(pos[i] + 1 < sz[i]){
                aux.x += pol[i][ pos[i] + 1 ].x;
                aux.y += pol[i][ pos[i] + 1 ].y;
            }else{
                aux.x += pol[i][0].x;
                aux.y += pol[i][0].y;
            }
        }
        // direction to next point
        auto cur = nxt[0];
        vector<int> candidates;
        candidates.push_back(0);
        // pick next direction, if aligned, sum the vectors
        for(int i = 1;i < npol;++i){
            auto aux = signed_area({0, 0}, nxt[i], cur);
            bool samedir = false;
            if(aux == 0){
                if(cur.x != 0 && (ll)nxt[i].x * cur.x > 0){
                    samedir = true;
                }
                if(cur.y != 0 && (ll)nxt[i].y * cur.y > 0){
                    samedir = true;
                }
            }
            if(aux > 0){
                cur = nxt[i];
                candidates.clear();
                candidates.push_back(i);
            }else if(aux == 0 && samedir){
                cur.x += nxt[i].x;
                cur.y += nxt[i].y;
                candidates.push_back(i);
            }
        }
        sum.x += cur.x;
        sum.y += cur.y;
        H.push_back(sum);
        for(int chosen : candidates){
            ++pos[chosen];
            if(pos[chosen] == sz[chosen]) pos[chosen] = 0;
        }
    }while(sum.x != H[0].x || sum.y != H[0].y);
    H.pop_back();
    return H;
}
