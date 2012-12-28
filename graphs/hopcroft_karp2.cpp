#define MAX_V1 50000
#define MAX_V2 50000
#define MAX_E 150000

int V1,V2,left[MAX_V2],right[MAX_V1];
int E,to[MAX_E],next[MAX_E],last[MAX_V1];

void hk_init(int v1, int v2){
    V1 = v1; V2 = v2; E = 0;
    memset(last,-1,sizeof last);
}

void hk_add_edge(int u, int v){
    to[E] = v; next[E] = last[u]; last[u] = E++;
}

bool visited[MAX_V1];

bool hk_dfs(int u){
    if(visited[u]) return false;
    visited[u] = true;
    
    for(int e = last[u],v;e != -1;e = next[e]){
        v = to[e];
        
        if(left[v] == -1 || hk_dfs(left[v])){
            right[u] = v;
            left[v] = u;
            return true;
        }
    }
    
    return false;
}

int hk_match(){
    memset(left,-1,sizeof left);
    memset(right,-1,sizeof right);
    bool change = true;
    
    while(change){
        change = false;
        memset(visited,false,sizeof visited);
        
        for(int i = 0;i < V1;++i)
            if(right[i] == -1)
                change |= hk_dfs(i);
    }
    
    int ret = 0;
    
    for(int i = 0;i < V1;++i)
        if(right[i] != -1) ++ret;
    
    return ret;
}
