#define MAX_R 500
#define MAX_C 501
int R,C,MOD;

struct Matrix{
    int X[MAX_R][MAX_C];
    Matrix(){}
};

void GaussianElimination(Matrix &M0){
    for(int i = 0,r = 0;r<R && i<C;++i){
        bool found = false;
        
        for(int j = r;j<R;++j){
            if(M0.X[j][i]>0){
                found = true;
                
                if(j==r) break;
                
                for(int k = i;k<C;++k) swap(M0.X[r][k],M0.X[j][k]);
                break;
            }
        }
        
        if(found){
            int aux = modular_inverse(M0.X[r][i],MOD);
            
            for(int j = i;j<C;++j) M0.X[r][j] = (M0.X[r][j]*aux)%MOD;
            
            for(int j = r+1;j<R;++j){
                aux = MOD-M0.X[j][i];
                for(int k = i;k<C;++k)
                    M0.X[j][k] = (M0.X[j][k]+aux*M0.X[r][k])%MOD;
            }
            
            ++r;
        }else return;
    }
    
    for(int i = R-1;i>0;--i)
        for(int j = 0;j<i;++j)
            M0.X[j][C-1] = (M0.X[j][C-1]+(MOD-M0.X[j][i])*M0.X[i][C-1])%MOD;
}
