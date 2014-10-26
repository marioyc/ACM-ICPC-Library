bool prime[BSZ];
vector<int> p;
int np;

void bucket_sieve(int n){
    p.clear();
    np = 0;
    
    for(int x = 2,y = BSZ + 1;x <= n;x += BSZ, y += BSZ){
        memset(prime,true,sizeof prime);
        
        for(int i = 0;i < np;++i){
            int curp = p[i];
            int aux = (x + curp - 1) / curp * curp;
            
            while(aux <= y){
                prime[aux - x] = false;
                aux += curp;
            }
        }
        
        for(int i = x;i <= y;++i){
            if(prime[i - x]){
                if(i <= BSZ){
                    p.push_back(i);
                    ++np;
                
                    int aux = i * i;
                    
                    while(aux <= y){
                        prime[aux - x] = false;
                        aux += i;
                    }
                }
            }
        }
    }
}
