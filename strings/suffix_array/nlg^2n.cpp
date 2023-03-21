#define SA_MAXN 1000005 // 100005
#define SA_MAXLG 20 // 18

struct sa_entry{
    int nr[2],p;

    bool operator < (sa_entry &X)const{
        if(nr[0] == X.nr[0]) return nr[1] < X.nr[1];
        return nr[0] < X.nr[0];
    }
};

struct suffix_array{
    char A[SA_MAXN];
    sa_entry L[SA_MAXN];
    int P[SA_MAXLG + 1][SA_MAXN],N,step;
    // rank to position in A
    int inv[SA_MAXN];

    void build(){
        N = strlen(A);
        step = 1;
        int cursz = 1;
        for(int i = 0;i < N;++i)
            P[0][i] = A[i];
        while(cursz < N){
            for(int i = 0;i < N;++i){
                L[i].nr[0] = P[step - 1][i];
                L[i].nr[1] = (i + cursz < N? P[step - 1][i + cursz] : -1);
                L[i].p = i;
            }
            sort(L, L + N);
            for(int i = 0;i < N;++i){
                if(i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]){
                    P[step][L[i].p] = P[step][L[i - 1].p];
                }else{
                    P[step][L[i].p] = i;
                }
            }
            ++step;
            cursz <<= 1;
        }
        for(int i = 0;i < N;++i)
            inv[P[step - 1][i]] = i;
    }

    // LCP for two suffix initial positions in string A
    int lcp(int x, int y){
        if(x == y) return N - x;
        int ret = 0;
        for(int k = step - 1;k >= 0 && x < N && y < N;--k)
            if(P[k][x] == P[k][y])
                x += (1<<k), y += (1<<k), ret |= (1<<k);
        return ret;
    }
};