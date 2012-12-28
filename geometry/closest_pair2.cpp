void closest_pair(int l, int r){
    if(l == r) return;
    
    int mi = (l + r) >> 1;
    int X = p[mi].x;
    
    closest_pair(l,mi);
    closest_pair(mi + 1,r);
    
    int m = 0;
    
    for(int i = l;i <= r;++i)
        if(abs(X - p[i].x) <= best)
            aux[m++] = point(p[i].y,p[i].x,p[i].id);
    
    sort(aux,aux + m);
    
    for(int i = 0;i < m;++i){
        int e = i + 1;
        
        while(e < m && aux[e].x - aux[i].x <= best + EPS){
            double d = dist(aux[i],aux[e]);
            
            if(d < best){
                best = d;
                id1 = aux[i].id;
                id2 = aux[e].id;
            }
            
            ++e;
        }
    }
}