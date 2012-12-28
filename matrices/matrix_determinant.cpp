#define MAX_SIZE 500
int size;

struct Matrix{
    double X[MAX_SIZE][MAX_SIZE];
    Matrix(){}
};

const double eps = 1e-7;

double determinant(Matrix M0){
    double ans = 1;
    
    for(int i = 0,r = 0;i<size;++i){
        bool found = false;
        
        for(int j = r;j<size;++j)
            if(fabs(M0.X[j][i])>eps){
                found = true;
                
                if(j>r) ans = -ans;
                else break;
                
                for(int k = 0;k<size;++k) swap(M0.X[r][k],M0.X[j][k]);
                break;
            }
        
        if(found){
            for(int j = r+1;j<size;++j){
                double aux = M0.X[j][i]/M0.X[r][i];
                for(int k = i;k<size;++k) M0.X[j][k] -= aux*M0.X[r][k];
            }
            
            r++;
        }else return 0;
    }
    
    for(int i = 0;i<size;++i) ans *= M0.X[i][i];
    return ans;
}
