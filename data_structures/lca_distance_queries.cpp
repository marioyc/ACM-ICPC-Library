#define MAX_V 50000
#define LOG2_MAXV 16

int N;
vector<int> L[MAX_V],W[MAX_V];

int Q[MAX_V],head,tail;
bool visited[MAX_V];
int P[MAX_V][LOG2_MAXV],level[MAX_V],dist[MAX_V][LOG2_MAXV];

void bfs(){
    head = 0; tail = 0;
    memset(visited,false,sizeof(visited));
    
    P[0][0] = -1;
    level[0] = 0;
    dist[0][0] = -1;
    Q[0] = 0; tail = 1;
    visited[0] = true;
    
    while(head<tail){
        int pos = Q[head];
        ++head;
        
        for(int i = L[pos].size()-1;i>=0;--i){
            int next = L[pos][i];
            
            if(!visited[next]){
                P[next][0] = pos;
                level[next] = level[pos]+1;
                dist[next][0] = W[pos][i];
                Q[tail] = next; ++tail;
                visited[next] = true;
            }
        }
    }
}

void lca_init(){
    bfs();
    
    for(int j = 1;(1<<j)<N;++j){
        for(int i = 0;i<N;++i){
            if(P[i][j-1]!=-1){
                P[i][j] = P[P[i][j-1]][j-1];
                dist[i][j] = dist[i][j-1]+dist[P[i][j-1]][j-1];
            }
        }
    }
}

int LCA(int p, int q){
    if(level[p]<level[q]) swap(p,q);
    
    int log = 0;
    while((1<<log)<=level[p]) ++log;
    --log;
    
    int ans = 0;
    
    for(int i = log;i>=0;--i){
        if(level[p]-(1<<i)>=level[q]){
            ans += dist[p][i];
            p = P[p][i];
        }
    }
    
    if(p==q) return ans;
    
    for(int i = log;i>=0;--i){
        if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
            ans += dist[p][i]+dist[q][i];
            p = P[p][i];
            q = P[q][i];
        }
    }
    
    ans += dist[p][0]+dist[q][0];
    
    return ans;
}
