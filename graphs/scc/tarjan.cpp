// https://codeforces.com/blog/entry/131187
// sample submission: https://codeforces.com/contest/2115/submission/322462326

const int MAXV = 600005;

vector<int> L[MAXV];
stack<int> S;
bool claimed[MAXV];
int dfs_t,dfs_order[MAXV],rep_dfs_order[MAXV],cont_scc,id_scc[MAXV];

void tarjan(int cur){
    S.push(cur);
    dfs_order[cur] = rep_dfs_order[cur] = dfs_t++;

    for(int to : L[cur]){
        if(dfs_order[to] == -1){
            tarjan(to);
        }
        if(!claimed[to]){
            rep_dfs_order[cur] = min(rep_dfs_order[cur], rep_dfs_order[to]);
        }
    }

    if(rep_dfs_order[cur] == dfs_order[cur]){
        int nxt;
        do{
            nxt = S.top();
            S.pop();
            claimed[nxt] = true;
            id_scc[nxt] = cont_scc;
        }while(nxt != cur);
        ++cont_scc;
    }
}

void build_scc(int V){
    fill(dfs_order, dfs_order + V, -1);
    fill(claimed, claimed + V, false);
    dfs_t = cont_scc = 0;

    for(int i = 0;i < V;++i)
        if(dfs_order[i] == -1)
            tarjan(i);
}