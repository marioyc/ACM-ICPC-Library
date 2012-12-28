int V,E,to[32000],nxt[32000],last[1000],now[1000];
int ans[32000];

void init(){
    memset(last,-1,sizeof(last));
    E = 0;
}

void make_edge(int u, int v){
    to[E] = v; nxt[E] = last[u]; last[u] = E++;
}

// A : vertice inicial
void euler(int A){
    for(int i = 0;i < V;++i)
        now[i] = last[i];
    
    stack<int> S;
    S.push(A);
    
    int cur,sz = 0;
    
    while(!S.empty()){
        cur = S.top();
        
        if(now[cur] != -1){
            S.push(to[now[cur]]);
            now[cur] = nxt[now[cur]];
        }else{
            ans[sz++] = cur;
            S.pop();
        }
    }
    
    for(int i = sz - 1;i > 0;--i)
        printf("%d %d\n",ans[i] + 1,ans[i - 1] + 1)
}
