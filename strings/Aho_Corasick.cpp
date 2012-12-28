struct AhoCorasick{
    static const int UNDEF = 0;
    static const int MAXN = 360;
    static const int CHARSET = 26;
    
    int end,have;
    int tag[MAXN];
    int fail[MAXN];
    int trie[MAXN][CHARSET];
    
    void init(){
        tag[0] = UNDEF;
        fill(trie[0],trie[0] + CHARSET,-1);
        end = 1;
        have = 0;
    }
    
    void add(int len, const int* s){
        int p = 0;
        
        for(int i = 0; i < len; ++i){
            if(trie[p][*s] == -1) {
                tag[end] = UNDEF;
                fill(trie[end],trie[end] + CHARSET,-1);
                trie[p][*s] = end++;
            }
            
            p = trie[p][*s];
            ++s;
        }
        
        tag[p] = (1 << have);
        ++have;
    }
    
    void build(){
        queue<int> bfs;
        fail[0] = 0;
        
        for(int i = 0;i < CHARSET;++i){
            if(trie[0][i] != -1){
                fail[trie[0][i]] = 0;
                bfs.push(trie[0][i]);
            }else{
                trie[0][i] = 0;
            }
        }
        
        while(!bfs.empty()){
            int p = bfs.front();
            tag[p] |= tag[fail[p]];
            bfs.pop();
            
            for(int i = 0;i < CHARSET;++i){
                if(trie[p][i] != -1){
                    fail[trie[p][i]] = trie[fail[p]][i];
                    bfs.push(trie[p][i]);
                }else{
                  trie[p][i] = trie[fail[p]][i];
                }
            }
        }
    }
};
