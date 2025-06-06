struct UnionFind{
    vector<int> par,sz;

    UnionFind(int n){
        par = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x){
        if(par[x] != x) par[x] = find(par[x]);
        return par[x];
    }

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px != py){
            if(sz[px] > sz[py]) swap(px, py);
            par[px] = py;
            sz[py] += sz[px];
            return true;
        }
        return false;
    }
};