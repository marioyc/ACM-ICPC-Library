vector<int> add(vector<int> &a, vector<int> &b){
    int n = a.size(),m = b.size(),sz = max(n,m);
    vector<int> c(sz,0);
	
    for(int i = 0;i<n;++i) c[i] += a[i];
    for(int i = 0;i<m;++i) c[i] += b[i];
	
	// mejor no quitar si son reales
    while(sz>1 && c[sz-1]==0){
        c.pop_back();
        --sz;
    }
	
    return c;
}

vector<int> multiply(vector<int> &a, vector<int> &b){
    int n = a.size(),m = b.size(),sz = n+m-1;
    vector<int> c(sz,0);
	
    for(int i = 0;i<n;++i)
        for(int j = 0;j<m;++j)
            c[i+j] += a[i]*b[j];
	
	// mejor no quitar si son reales
    while(sz>1 && c[sz-1]==0){
        c.pop_back();
        --sz;
    }
	
    return c;
}

bool is_root(vector<int> &P, int r){
    int n = P.size();
    long long y = 0;
	
    for(int i = 0;i<n;++i){
        if(abs(y-P[i])%r!=0) return false;
        y = (y-P[i])/r;
    }
	
    return y==0;
}
