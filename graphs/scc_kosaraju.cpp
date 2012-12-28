#define MAX_V 500

int V, num_scc, scc[MAX_V];
vector< vector<int> > G;
vector< vector<int> > GT;
bool visited[MAX_V];
stack<int> S;
queue<int> Q;

void dfs(int v){
    visited[v] = true;
    for(int i=G[v].size()-1;i>=0;--i) if(!visited[G[v][i]]) dfs(G[v][i]);
    S.push(v);
}

void bfs(int v){
    Q.push(v);
    visited[v] = true;
    
    int aux;
    
    while(!Q.empty()){
        aux = Q.front();
        scc[aux] = num_scc;
        Q.pop();
        
        for(int i=GT[aux].size()-1;i>=0;i--){
            if(!visited[GT[aux][i]]){
                Q.push(GT[aux][i]);
                visited[GT[aux][i]] = true;
            }
        }
    }
}

void SCC(){
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<V;++i) if(!visited[i]) dfs(i);
    
    num_scc = 0;
    int aux;
    
    memset(visited,false,sizeof(visited));
    
    
    while(!S.empty()){
        aux = S.top();
        S.pop();
        
        if(!visited[aux]){
            bfs(aux);
            ++num_scc;
        }
    }
}
