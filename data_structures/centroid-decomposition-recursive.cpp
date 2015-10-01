#define MAXN 100005

struct CentroidDecomposition{
  vector<int> L[MAXN];
  int subsize[MAXN],cpar[MAXN];

  void dfs(int cur, int p){
    subsize[cur] = 1;

    for(int i = 0;i < L[cur].size();++i){
      int to = L[cur][i];

      if(to != p && cpar[to] == -1){
        dfs(to,cur);
        subsize[cur] += subsize[to];
      }
    }
  }

  void centroid_decomposition(int cur, int p, int n, int prevc){
    for(int i = 0;i < L[cur].size();++i){
      int to = L[cur][i];

      if(to != p && cpar[to] == -1 && 2 * subsize[to] > n){
        centroid_decomposition(to,cur,n,prevc);
        return;
      }
    }

    cpar[cur] = prevc;

    for(int i = 0;i < L[cur].size();++i){
      int to = L[cur][i];

      if(cpar[to] == -1){
        dfs(to,-1);
        centroid_decomposition(to,cur,subsize[to],cur);
      }
    }
  }

  void init(int start){
    memset(cpar,-1,sizeof cpar);
    dfs(start,-1);
    centroid_decomposition(start,-1,subsize[start],-2);
  }
};
