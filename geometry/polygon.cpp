//verdadero : sentido anti-horario, Complejidad : O(n)
bool ccw(const vector<point> &poly){
    //primero hallamos el punto inferior ubicado mas a la derecha
    int ind = 0,n = poly.size();
    double x = poly[0].x,y = poly[0].y;

    for(int i=1;i<n;i++){
        if (poly[i].y>y) continue;
        if (fabs(poly[i].y-y)<eps && poly[i].x<x) continue;
        ind = i;
        x = poly[i].x;
        y = poly[i].y;
    }
    
    if (ind==0) return ccw(poly[n-1],poly[0],poly[1]);
    return ccw(poly[ind-1],poly[ind],poly[(ind+1)%n]);
}

bool isInConvex(vector <point> &A, const point &P){
    // polygon should be in ccw order
    // if(!ccw(A)) reverse(A.begin(),A.end());
    int n = A.size(), lo = 1, hi = A.size() - 1;
    
    if(area(A[0], A[1], P) <= 0) return 0;
    if(area(A[n-1], A[0], P) <= 0) return 0;
    
    while(hi - lo > 1){
        int mid = (lo + hi) / 2;
        
        if(area(A[0], A[mid], P) > 0) lo = mid;
        else hi = mid;
    }
    
    return area(A[lo], A[hi], P) > 0;
}

bool PointInsidePolygon(const point &P, const vector<point> &poly){
    int n = poly.size();
    bool in = 0;
    
    for(int i = 0,j = n-1;i<n;j = i++){
        double dx = poly[j].x-poly[i].x;
        double dy = poly[j].y-poly[i].y;
        
        if((poly[i].y<=P.y+eps && P.y<poly[j].y) ||
            (poly[j].y<=P.y+eps && P.y<poly[i].y))
            if(P.x-eps<dx*(P.y-poly[i].y)/dy+poly[i].x)
                in ^= 1;
    }
    
    return in;
}

//valor positivo : vertices orientados en sentido antihorario
//valor negativo : vertices orientados en sentido horario
double signed_area(const vector<point> &poly){
  int n = poly.size();
  if(n<3) return 0.0;
  
  double S = 0.0;
  
  for(int i=1;i<=n;++i)
    S += poly[i%n].x*(poly[(i+1)%n].y-poly[i-1].y);
  
  S /= 2;
  return S;
}
