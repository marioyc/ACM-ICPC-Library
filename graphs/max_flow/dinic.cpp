struct flow_graph{
    static const int MAX_E = 10000;

    int E,V,s,t,head,tail;
    int cap[2 * MAX_E],to[2 * MAX_E],next[2 * MAX_E];
    vector<int> last,dist,q,now;

    void init(int _V, int _s, int _t){
        E = 0;
        V = _V;
        s = _s;
        t = _t;
        last = vector<int>(V, -1);
        dist = vector<int>(V, -1);
        q = vector<int>(V, -1);
        now = vector<int>(V, -1);
    }

    void add_edge(int u, int v, int uv){
        assert(0 <= u < V && 0 <= v < V);
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = 0, next[E] = last[v]; last[v] = E++;
    }

    bool bfs(){
        fill(dist.begin(), dist.end(), -1);
        head = tail = 0;
        q[tail] = t; ++tail;
        dist[t] = 0;

        while(head < tail){
            int v = q[head]; ++head;

            for(int e = last[v];e != -1;e = next[e]){
                if(cap[e ^ 1] > 0 && dist[ to[e] ] == -1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v] + 1;
                }
            }
        }

        return dist[s] != -1;
    }

    int dfs(int v, int f){
        if(v == t) return f;

        for(int &e = now[v];e != -1;e = next[e]){
            if(cap[e] > 0 && dist[to[e]] == dist[v] - 1){
                int ret = dfs(to[e], min(f, cap[e]));
                if(ret > 0){
                    cap[e] -= ret;
                    cap[e ^ 1] += ret;
                    return ret;
                }
            }
        }

        return 0;
    }

    int max_flow(){
        int f = 0,df;

        while(bfs()){
            copy(last.begin(), last.end(), now.begin());
            while(true){
                df = dfs(s, INT_MAX);
                if(df == 0) break;
                f += df;
            }
        }

        return f;
    }
};