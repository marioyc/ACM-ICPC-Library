#define MAXN 100000

int phi[MAXN + 1],factor[MAXN + 1];

void phi_sieve(){
    memset(factor,-1,sizeof factor);
    phi[1] = 1;
    
    for(int i = 2;i <= MAXN;++i){
        if(factor[i] == -1){
            phi[i] = i - 1;
            
            if(i <= MAXN / i)
                for(int j = i*i;j <= MAXN;j += i)
                    factor[j] = i;
        }else{
            int p = factor[i];
            int aux = i / p;
            
            if(aux % p == 0) phi[i] = phi[aux] * p;
            else phi[i] = (p - 1) * phi[aux];
        }
    }
}
