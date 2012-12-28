//Distancia de un punto a una recta infinita
double PointToLineDist(const point &P, const line &L){
    return 2 * fabs(signed_area(L.p1,L.p2,P)) / (L.p2 - L.p1).abs();
}

//Distancia de un punto a un segmento de recta
double PointToSegmentDist(const point &P, const line &L){
    point v = L.p2 - L.p1,w = P - L.p1;
    
    double aux1 = w.dot(v);
    if(aux1 < eps) return (P-L.p1).abs();
    
    double aux2 = v.dot(v);
    if(aux2 <= aux1+eps) return (P-L.p2).abs();
    
    return PointToLineDist(P,L);
}

bool cross(point a, point b, point c, point d){
    return area(a,b,c) * area(a,b,d) < eps && area(c,d,a) * area(c,d,b) < eps;
}

point intersection(point a, point b, point c, point d){
    return a + (b - a) * ((c - a).cross(d - c) / (b - a).cross(d - c));
}

point projection(point x, point a, point b){
    return a + (b - a) * ((x - a).dot(b - a) / (b - a).dot(b - a));
}

point reflection(point x, point a, point b){
    return x + (projection(x,a,b) - x) * 2;
}
