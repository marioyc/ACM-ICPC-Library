long long comb(int n, int m){
    if(m>n-m) m = n-m;
    
    long long C = 1;
    //C^{n}_{i} -> C^{n}_{i+1}
    for(int i=0;i<m;++i) C = C*(n-i)/(1+i);
    return C;
}

Cuando n y m son grandes y se pide comb(n,m)%MOD, donde MOD es un numero primo,
se puede usar el Teorema de Lucas.

#define MOD 3571

int C[MOD][MOD];

void FillLucasTable(){
    memset(C,0,sizeof(C));

    for(int i=0;i<MOD;++i) C[i][0] = 1;
    for(int i=1;i<MOD;++i) C[i][i] = 1;
    for(int i=2;i<MOD;++i)
        for(int j=1;j<i;++j)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
}

int comb(int n, int k){
    long long ans = 1;
	
    while(n!=0){
        int ni = n%MOD,ki = k%MOD;
        n /= MOD; k /= MOD;
        ans = (ans*C[ni][ki])%MOD;
    }
	
    return (int)ans;
}
