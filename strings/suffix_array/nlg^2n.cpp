#define MAXN 100000
#define MAXLG 18

char A[MAXN];

struct entry{
	int nr[2],p;
	
	bool operator  < (entry X)const{
		if(nr[0]==X.nr[0]) return nr[1]<X.nr[1];
		return nr[0]<X.nr[0];
	}
}L[MAXN];

int P[MAXLG][MAXN],N,step;
int inv[MAXN];

void build_suffix_array(){
    N = strlen(A);
	for(int i=0;i<N;++i) P[0][i] = A[i];
	
	step = 1;
	int cont = 1;
	
	while(cont<N){
		for(int i=0;i<N;++i){
			L[i].nr[0] = P[step-1][i];
			L[i].nr[1] = (i+cont<N? P[step-1][i+cont]:-1);
			L[i].p = i;
		}
		
		sort(L,L+N);
		
		for(int i=0;i<N;++i){
			if(i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]) P[step][L[i].p] = P[step][L[i-1].p];
			else P[step][L[i].p] = i;
		}
		
		++step;
		cont <<= 1;
	}
	
	for(int i=0;i<N;++i) inv[P[step-1][i]] = i;
}

int lcp(int x, int y){
	if(x==y) return N-x;
	
	int ret = 0;
	
	for(int k=step-1;k>=0 && x<N && y<N;--k)
		if(P[k][x]==P[k][y])
			x += (1<<k), y += (1<<k), ret |= (1<<k);
	
	return ret;
}
