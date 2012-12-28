#define SZ 100
bool M[SZ][SZ];
int N,colour[SZ],dfsNum[SZ],num,pos[SZ],leastAncestor[SZ],parent[SZ];

int dfs(int u){
    int ans = 0,cont = 0,v;
        
    stack<int> S;
    S.push(u);

    while(!S.empty()){
        v = S.top();
        if(colour[v]==0){
            colour[v] = 1;
            dfsNum[v] = num++;
            leastAncestor[v] = num;
        }
        
        for(;pos[v]<N;++pos[v]){
            if(M[v][pos[v]] && pos[v]!=parent[v]){
                if(colour[pos[v]]==0){
                    parent[pos[v]]=v;
                    S.push(pos[v]);
                    if(v==u) ++cont;
                    break;
                }else leastAncestor[v]<?=dfsNum[pos[v]];
            }
        }
        
        if(pos[v]==N){
            colour[v] = 2;
            S.pop();
            
            if(v!=u) leastAncestor[parent[v]]<?=leastAncestor[v];
        }
    }
    
    if(cont>1){
        ++ans;
        printf("%d\n",u);
    }
    
    for(int i = 0;i<N;++i){
        if(i==u) continue;
        for(int j = 0;j<N;j++)
            if(M[i][j] && parent[j]==i && leastAncestor[j]>=dfsNum[i]){
                printf("%d\n",i);
                ++ans;
                break;
            }
    }
    
    return ans;
}



void Articulation_points(){
    memset(colour,0,sizeof(colour));
    memset(pos,0,sizeof(pos));
    memset(parent,-1,sizeof(parent));
    num = 0;
    
    int total = 0;
    for(int i = 0;i<N;++i) if(colour[i]==0) total += dfs(i);
    
    printf("# Articulation Points : %d\n",total);
}
