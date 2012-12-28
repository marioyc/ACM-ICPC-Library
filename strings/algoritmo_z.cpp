int next[MAX_P_LEN];
// next[i] : lcp entre la cadena y su sufijo
//           a partir del i-esimo caracter

void prefix_kmp(char *P){
    int L = strlen(P),p = 0,t;
    
    for(int i = 1;i < L;i++){
        if(i < p && next[i-t] < p-i) next[i] = next[i-t];
        else{
            int j = max(0, p-i);
            
            while(i+j < L && P[i+j] == P[j]) ++j;
            
            next[i] = j;
            p = i + j;
            t = i;
        }
    }
}

void LCP(char * P, char *T, int *lcp){
    int LP = strlen(P),LT = strlen(T);
    int p = 0,t;
    
    for(int i = 0;i < LT;i++){
        if(i < p && next[i-t] < p-i) lcp[i] = next[i-t];
        else{
            int j = max(0,p-i);
            
            while(i+j < LT && T[i+j] == P[j])  ++j;
            
            lcp[i] = j;
            p = i + j;
            t = i;
        }
    }
}
