struct Complex{
    double x,y;
    
    Complex(){}
    Complex(double _x, double _y):
        x(_x), y(_y){}
    
    void operator += (Complex &c){
        x += c.x; y += c.y;
    }
    
    Complex operator -= (Complex &c){
        x -= c.x; y -= c.y;
    }
    
    Complex operator * (Complex &c){
        return Complex(x * c.x - y * c.y,x * c.y + y * c.x);
    }
};

#define MAXN 262144
Complex A2[MAXN];

void fft(int n, Complex A[], int s){
    int p = __builtin_ctz(n);
    
    memcpy(A2,A,sizeof(Complex) * n);
    
    for(int i = 0;i < n;++i){
        int rev = 0;
        
        for(int j = 0;j < p;++j){
            rev <<= 1;
            rev |= ((i >> j) & 1);
        }
        
        A[i] = A2[rev];
    }
    
    Complex w,wn;
    int M = 2,K = 1;
    
    for(int i = 1;i <= p;++i,M <<= 1,K <<= 1){
        wn = Complex(cos(s * 2 * M_PI / M),sin(s * 2 * M_PI / M));
        
        for(int j = 0;j < n;j += M){
            w = Complex(1,0);
            
            for(int l = j;l < K+j;++l){
                Complex t = w * A[l + K],u = A[l];
                
                A[l] += t;
                u -= t;
                A[l + K] = u;
                w = w * wn;
            }
        }
    }
    
    if(s == -1)
        for(int i = 0;i < n;++i)
            A[i].x /= n, A[i].y /= n;;
}

Complex R[MAXN];
int nR;

void fft_mult(int nP, Complex P[], int nQ, Complex Q[]){
    nR = nP + nQ;
    while(__builtin_popcount(nR) > 1) nR += nR & -nR;
    
    for(int i = nP;i < nR;++i) P[i] = Complex(0,0);
    for(int i = nQ;i < nR;++i) Q[i] = Complex(0,0);
    
    fft(nR,P,1);
    fft(nR,Q,1);
    
    for(int i = 0;i < nR;i++) R[i] = P[i] * Q[i];
    
    fft(nR,R,-1);
}