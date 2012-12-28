struct HeavyLight{
    static const int MAXN = 100005;
    
    int N;
    vector<int> E[MAXN];
    
    int nodedad[MAXN];
    int treesize[MAXN];
    
    int pos,cntchain;
    int chainleader[MAXN];
    int homechain[MAXN];
    int homepos[MAXN];
    
    void init(int n){
        N = n;
        for(int i = 0;i < n;++i) E[i].clear();
        pos = cntchain = 0;
    }
    
    void add_edge(int u, int v){
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    void explore(int x = 0, int dad = -1){
        nodedad[x] = dad;
        treesize[x] = 1;
        
        int sz = E[x].size();
        
        for(int i = 0;i < sz;++i){
            if(E[x][i] != dad){
                explore(E[x][i], x);
                treesize[x] += treesize[ E[x][i] ];
            }
        }
    }
    
    void heavy_light(int x = 0, int dad = -1, int k = -1, int p = 0){
        if(p == 0){
            k = cntchain++;
            chainleader[k] = x;
        }
        
        homechain[x] = k;
        homepos[x] = pos++;
        
        int mx = -1,sz = E[x].size();
        
        for(int i = 0;i < sz;++i)
            if(E[x][i] != dad && (mx == -1 || treesize[ E[x][i] ] > treesize[ E[x][mx] ]) )
                mx = i;
        
        if(mx != -1) heavy_light(E[x][mx], x, k, p + 1);
        
        for(int i = 0;i < sz;++i)
            if(E[x][i] != dad && i != mx)
                heavy_light(E[x][i], x, -1, 0);
    }
};
