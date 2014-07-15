#define MAXV 1000

vector<int> L[MAXV];
stack<int> S;
bool in_stack[MAXV];
int low[MAXV],curh,cont_scc,id_scc[MAXV];

void tarjan(int cur){
    S.push(cur);
    in_stack[cur] = true;
    low[cur] = ++curh;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(low[to] == -1){
            tarjan(to);
            low[cur] = min(low[cur],low[to]);
        }else if(in_stack[to]){
            low[cur] = min(low[cur],low[to]);
        }
    }
    
    if(low[cur] == curh){
        int nxt;
        
        do{
            nxt = S.top();
            S.pop();
            in_stack[nxt] = false;
            id_scc[nxt] = cont_scc;
        }while(nxt != cur);
        
        ++cont_scc;
    }
    
    --curh;
}

void build_scc(int V){
    memset(low,-1,sizeof low);
    memset(in_stack,false,sizeof in_stack);
    curh = cont_scc = 0;
    
    for(int i = 0;i < V;++i)
        if(low[i] == -1)
            tarjan(i);
}
