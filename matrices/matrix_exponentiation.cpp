#define MAX_SIZE 64

int size;
const long long MOD = 1000000007;

struct Matrix{
    long long X[MAX_SIZE][MAX_SIZE];
    
    Matrix(){}
    
    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i < size;++i) X[i][i] = 1;
    }
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    memset(m.X,0,sizeof(m.X));

    for(int i = 0;i < size;++i)
        for(int j = 0;j < size;++j)
            for(int k = 0;k < size;++k)
                m.X[i][k] = (m.X[i][k] + m1.X[i][j] * m2.X[j][k]) % MOD;
}

Matrix pow(Matrix &M0, int n){
	Matrix ret;
	ret.init();
	
	if(n == 0) return ret;
	if(n == 1) return M0;
	
	Matrix P = M0;
	
	while(n){
	    if(n & 1){
	        aux = ret;
	        mult(ret,aux,P);
	    }
	    
	    n >>= 1;
	    aux = P;
	    mult(P,aux,aux);
	}
	
    return ret;
}

// para exponente n escrito en base 2<=b<=9
Matrix exp(Matrix &M0, string &n, int b){
    Matrix P[b + 1];
	
    for(int i = 0;i <= b;++i) P[i] = pow(M0,i);
	
    int L = n.size();
    Matrix ret;
    ret.init();
    
    for(int i = 0;i < L;++i){
        int x = n[i] - '0';
        M0 = ret;
        ret = pow(M0,b);
		
        aux = ret;
        mult(ret,aux,P[x]);
    }
	
    return ret;
}
