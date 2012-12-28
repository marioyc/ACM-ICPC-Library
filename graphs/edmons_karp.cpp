#define SZ 802

int flow[SZ][SZ],cap[SZ][SZ],prev[SZ],f;
//inicializar cap y flow en 0

vector< vector<int> > L;

bool augmenting(int &N, int t){
    fill(prev,prev+N,-1);
    queue<int> Q;
    Q.push(0);
    prev[0] = -2;
    
    int aux;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        for(int i = 0;i<L[aux].size();++i)
            if(flow[aux][L[aux][i]]<cap[aux][L[aux][i]] && prev[L[aux][i]]==-1){
                prev[L[aux][i]] = aux;
                if(L[aux][i]==t) goto found;
                Q.push(L[aux][i]);
            }
    }
    
    return false;
    
    found:
    
    int x = INT_MAX,cur = t,next;
    
    while(cur!=0){
        next = prev[cur];
        x = min(x,cap[next][cur]-flow[next][cur]);
        cur = next;
    }

    f += x;
    cur = t;
    
    while(cur!=0){
        next = prev[cur];
        flow[next][cur] += x;
        flow[cur][next] -= x;
        cur = next;
    }
    
    return true;
}
