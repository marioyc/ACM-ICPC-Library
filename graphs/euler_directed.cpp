#define MAXV 5000
#define MAXE 200000

struct DirectedEulerGraph {
  int V,ne,last[MAXV],to[MAXE],next[MAXE],cur[MAXV];
  int in[MAXV],out[MAXV];
  int start,end;
  vector<int> path;

  DirectedEulerGraph(){}

  void clear(int V_){
    V = V_; ne = 0;
    memset(last,-1,sizeof last);
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
  }

  void add_edge(int u, int v){
    to[ne] = v; next[ne] = last[u]; last[u] = ne++;
    ++out[u]; ++in[v];
    start = u;
  }

  bool check(){
    int cont = 0,aux = start;
    start = end = -1;

    for(int i = 0;i < V;++i){
      if(in[i] == out[i]) ++cont;
      else if(out[i] == in[i] + 1) start = i;
      else if(in[i] == out[i] + 1) end = i;
      else return false;
    }

    if(cont == V){
      start = end = aux;
      return true;
    }

    return (cont == V - 2 && start != -1 && end != -1);
  }

  bool build(){
    stack<int> S;
    S.push(start);
    memcpy(cur,last,sizeof last);
    path.clear();

    while(!S.empty()){
      int u = S.top();

      if(cur[u] == -1){
        path.push_back(u);
        S.pop();
      }else{
        int v = to[ cur[u] ];
        cur[u] = next[ cur[u] ];
        S.push(v);
      }
    }

    reverse(path.begin(),path.end());
    return path.size() == ne + 1;
  }
};
