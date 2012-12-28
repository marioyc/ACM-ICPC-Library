// rem y mod tienen el mismo numero de elementos
long long chinese_remainder(vector<int> rem, vector<int> mod){
    long long ans = rem[0],m = mod[0];
    int n = rem.size();
  
    for(int i=1;i<n;++i){
        int a = modular_inverse(m,mod[i]);
        int b = modular_inverse(mod[i],m);
        ans = (ans*b*mod[i]+rem[i]*a*m)%(m*mod[i]);
        m *= mod[i];
    }
  
    return ans;
}
