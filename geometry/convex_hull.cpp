vector<point> ConvexHull(vector<point> P){
    sort(P.begin(),P.end());
    int n = P.size(),k = 0;
    point H[2*n];
    
    for(int i=0;i<n;++i){
        while(k>=2 && !ccw(H[k-2],H[k-1],P[i])) --k;
        H[k++] = P[i];
    }
    
    for(int i=n-2,t=k;i>=0;--i){
        while(k>t && !ccw(H[k-2],H[k-1],P[i])) --k;
        H[k++] = P[i];
    }
    
    return vector<point> (H,H+k);
}
