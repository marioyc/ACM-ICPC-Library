#define MAXL 100005
#define ALPH 26

struct state{
    int len,link,pos;
    int next[ALPH];
};

struct SuffixAutomata{
    state sa[2 * MAXL];
    int last,sz,len;

    SuffixAutomata(){
        sa[0].len = 0;
        sa[0].link = -1;
        memset(sa[0].next,0,sizeof sa[0].next);
        last = len = 0;
        sz = 1;
    }

    void sa_add(int c){
        int cur = sz++;
        sa[cur].len = sa[last].len + 1;
        sa[cur].pos = len;
        memset(sa[cur].next,0,sizeof sa[cur].next);
        
        int p = last;
        
        while(p != -1 && !sa[p].next[c]){
            sa[p].next[c] = cur;
            p = sa[p].link;
        }
        
        if(p == -1) sa[cur].link = 0;
        else{
            int q = sa[p].next[c];
            
            if(sa[q].len == sa[p].len + 1)
                sa[cur].link = q;
            else{
                int clone = sz++;
                sa[clone].len = sa[p].len + 1;
                sa[clone].link = sa[q].link;
                sa[clone].pos = sa[q].pos;
                memcpy(sa[clone].next,sa[q].next,sizeof(int) * ALPH);
                
                while(p != -1 && sa[p].next[c] == q){
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
                
                sa[q].link = sa[cur].link = clone;
            }
        }
        
        last = cur;
        ++len;
    }

    void print_sa(){
        for(int i = 0;i < sz;++i){
            printf("i = %d, len = %d, link = %d, pos = %d\n",i,sa[i].len,sa[i].link,sa[i].pos);
            for(int j = 0;j < ALPH;++j)
                if(sa[i].next[j])
                    printf("c = %c, to = %d\n",'a' + j,sa[i].next[j]);
        }
    }
};
