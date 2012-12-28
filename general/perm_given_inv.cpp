vector <int> getPermutation(int n, int inv){
    vector<int> ans;
    if(inv>n*(n-1)/2) return ans;
    
    for(int i = 1;i<=n;++i) ans.push_back(i);
    
    for(int i = 1;i<=n;++i){
        if(inv<=i*(i-1)/2){
            int I = i*(i-1)/2;
            reverse(ans.begin()+(n-i),ans.end());
            
            for(int j=0;I>inv;++j){
                int diff = I-inv;
                
                if(diff>=n-j-1){
                    rotate(ans.begin()+(n-i+j),ans.begin()+(n-j-1),
                        ans.begin()+(n-j));
                    I -= n-j-1;
                }else{
                    rotate(ans.begin()+(n-i+j),ans.begin()+(n-i+j+diff),
                        ans.begin()+(n-i+j+diff+1));
                    I = inv;
                }
            }
            
            break;
        }
    }
    
    return ans;
}
