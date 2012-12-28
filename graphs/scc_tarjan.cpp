#define MAX_V 100000

vector<int> L[MAX_V],C[MAX_V];
int V,dfsPos,dfsNum[MAX_V],lowlink[MAX_V],num_scc,comp[MAX_V];
bool in_stack[MAX_V];
stack<int> S;

void tarjan(int v){
    dfsNum[v] = lowlink[v] = dfsPos++;
    S.push(v); in_stack[v] = true;
    
    for(int i = L[v].size()-1;i>=0;--i){
        int w = L[v][i];
        if(dfsNum[w]==-1){
            tarjan(w);
            lowlink[v] = min(lowlink[v],lowlink[w]);
        }else if(in_stack[w]) lowlink[v] = min(lowlink[v], lowlink[w]);
    }
    
    if(dfsNum[v]==lowlink[v]){
        vector<int> &com = C[num_scc];
        com.clear();
        int aux;
        
        do{
            aux = S.top(); S.pop();
            comp[aux] = num_scc;
            com.push_back(aux);
            in_stack[aux] = false;
        }while(aux!=v);
        
        ++num_scc;
    }
}

void build_scc(int _V){
    V = _V;
    memset(dfsNum,-1,sizeof(dfsNum));
    memset(in_stack,false,sizeof(in_stack));
    dfsPos = num_scc = 0;
    
    for(int i = 0;i<V;++i)
        if(dfsNum[i]==-1)
            tarjan(i);
}
