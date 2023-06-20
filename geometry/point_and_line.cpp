const double eps = 1e-9;

struct point{
    double x,y;
    
    point(){}
    point(double _x, double _y) : x(_x), y(_y){}
    
    double cross(point P){
        return x * P.y - y * P.x;
    }

    bool operator < (const point &p) const{
        if(fabs(x - p.x) > eps) return x < p.x;
        return y > p.y;
    }
};

double cross(point a, point b){
    return a.x * b.y - a.y * b.x;
}

bool is_upper(point &a){
    return a.y > 0 || (a.y == 0 && a.x >= 0);
}

bool polar_cmp(point a, point b){
    bool ua = is_upper(a),ub = is_upper(b);
    if(ua != ub) return !ua;
    return cross(a, b) > 0;
}

struct line{
    point p1,p2;
    
    line(){}
    
    line(point _p1, point _p2){
        p1 = _p1; p2 = _p2;
        if(p1.x > p2.x) swap(p1, p2);
    }
};
