#define MAXN 100001
#define MAXE 500000

int last[MAXN],nxt[2 * MAXE],to[2 * MAXE],ne = 0;

void add_edge(int &u, int &v){
    to[ne] = v; nxt[ne] = last[u]; last[u] = ne++;
    to[ne] = u; nxt[ne] = last[v]; last[v] = ne++;
}

int low[MAXN],parent[MAXN],level[MAXN],comp[MAXN];

void dfs(int r){
    int u,v;
        
    stack<int> S;
    
    S.push(r);
    comp[r] = r;
    low[r] = level[r] = 0;
    parent[r] = -1;

    while(!S.empty()){
        u = S.top();
        
        for(int &e = last[u];e != -1;e = nxt[e]){
            v = to[e];
            
            if(comp[v] != -1 && v != parent[u] && level[u] > level[v]){
                low[u] = min(low[u],level[v]);
            }else if(comp[v] == -1){
                S.push(v);
                comp[v] = r;
                low[v] = level[v] = level[u] + 1;
                parent[v] = u;
                break;
            }
        }
        
        if(last[u] == -1){
            S.pop();
            if(u != r)
                low[ parent[u] ] = min(low[ parent[u] ],low[u]);
        }
    }
}