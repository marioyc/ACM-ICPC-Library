#define MAX_SIZE 100000
int parent[MAX_SIZE],rank[MAX_SIZE];

void Make_Set(const int x){
    parent[x] = x; rank[x] = 0;
}

int Find(const int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX = Find(x),PY = Find(y);
    
    if(rank[PX] > rank[PY]) parent[PY] = PX;
    else{
        parent[PX] = PY;
        if(rank[PX]==rank[PY]) ++rank[PY];
    }
}
