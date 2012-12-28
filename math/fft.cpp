#define lowbit(x) (((x) ^ (x-1)) & (x))
typedef complex<long double> Complex;

void FFT(vector<Complex> &A, int s){
    int n = A.size();
    int p = __builtin_ctz(n);
    
    vector<Complex> a = A;
    
    for(int i = 0;i<n;++i){
        int rev = 0;
        for(int j = 0;j<p;++j){
            rev <<= 1;
            rev |= ((i >> j) & 1);
        }
        A[i] = a[rev];
    }
    
    Complex w,wn;
    
    for(int i = 1;i<=p;++i){
        int M = (1<<i), K = (M>>1);
        wn = Complex(cos(s*2.0*M_PI/(double)M), sin(s*2.0*M_PI/(double)M));
        
        for(int j = 0;j<n;j += M){
            w = Complex(1.0, 0.0);
            for(int l = j;l<K+j;++l){
                Complex t = w;
                t *= A[l + K];
                Complex u = A[l];
                A[l] += t;
                u -= t;
                A[l + K] = u;
                w *= wn;
            }
        }
    }
    
    if(s==-1){
        for(int i = 0;i<n;++i)
            A[i] /= (double)n;
    }
}

vector<Complex> FFT_Multiply(vector<Complex> &P, vector<Complex> &Q){
    int n = P.size()+Q.size();
    while(n!=lowbit(n)) n += lowbit(n);
    
    P.resize(n,0);
    Q.resize(n,0);
    
    FFT(P,1);
    FFT(Q,1);
    
    vector<Complex> R;
    for(int i=0;i<n;i++) R.push_back(P[i]*Q[i]);
    
    FFT(R,-1);
    
    return R;
}

// Para multiplicacion de enteros grandes
const long long B = 100000;
const int D = 5;
