#define MAX_L 70
int f[MAX_L];

void prefixFunction(string P){
    int n = P.size(), k = 0;
    f[0] = 0;
	
    for(int i=1;i<n;++i){
        while(k>0 && P[k]!=P[i]) k = f[k-1];
        if(P[k]==P[i]) ++k;
        f[i] = k;
    }
}


int KMP(string P, string T){
    int n = P.size(), L = T.size(), k = 0, ans = 0;
    
    for(int i=0;i<L;++i){
        while(k>0 && P[k]!=T[i]) k = f[k-1];
        if(P[k]==T[i]) ++k;
        
        if(k==n){
            ++ans;
            k = f[k-1];
        }
    }
    
    return ans;
}
