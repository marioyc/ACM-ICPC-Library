#define MAX_SIZE 100
bool visited[MAX_SIZE];
int prev[MAX_SIZE];

int most_distant(int s){
    queue<int> Q;
    Q.push(s);
    
    memset(visited,false,sizeof(visited));
    visited[s] = true;
    prev[s] = -1;
    
    int ans = s;
    
    while(!Q.empty()){
        int aux = Q.front();
        Q.pop();
        
        ans = aux;
        
        for(int i=L[aux].size()-1;i>=0;--i){
            int v = L[aux][i];
            if(visited[v]) continue;
            visited[v] = true;
            Q.push(v);
            prev[v] = aux;
        }
    }
    
    return ans;
}
