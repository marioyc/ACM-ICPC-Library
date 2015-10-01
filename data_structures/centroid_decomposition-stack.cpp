#define MAXN 100005

struct CentroidDecomposition{
  vector<int> L[MAXN];

  bool used[MAXN],visited[MAXN];
  int st_size[MAXN],parent[MAXN];
  vector<int> aux;
  stack<int> S;

  int dfs(int r){
    aux.clear();
    parent[r] = -1;
    S.push(r);

    while(!S.empty()){
      int cur = S.top();

      if(!visited[cur]){
        visited[cur] = true;
        aux.push_back(cur);
        st_size[cur] = 1;

        for(int i = 0;i < L[cur].size();++i){
          int to = L[cur][i];

          if(!used[to] && to != parent[cur]){
            parent[to] = cur;
            S.push(to);
          }
        }
      }else{
        if(cur != r)
          st_size[ parent[cur] ] += st_size[cur];
        S.pop();
      }
    }

    int n = st_size[r],ret = 0;

    for(int i = 0;i < aux.size();++i){
      int cur = aux[i];

      if(!used[cur]){
        visited[cur] = false;
        int max_st_size = n - st_size[cur];

        for(int j = 0;j < L[cur].size();++j){
          int to = L[cur][j];

          if(!used[to] && to != parent[cur]){
            max_st_size = max(max_st_size,st_size[to]);
          }
        }

        if(2 * max_st_size <= n){
          ret = cur;
        }
      }
    }

    return ret;
  }

  int cpar[MAXN];

  int centroid_decomposition(int cur, int prevc = -1){
    int c = dfs(cur);
    used[c] = true;
    cpar[c] = prevc;

    for(int i = 0;i < L[c].size();++i){
      int to = L[c][i];

      if(!used[to])
        centroid_decomposition(to,c);
    }

    return c;
  }
};
