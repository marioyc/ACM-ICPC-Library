// a*x + b*y = gcd(a,b)
int ext_gcd(int  a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int g = extGcd(b,a % b,y,x);
    y -= a / b * x;
    return g;
}

// ASSUME: gcd(a, m) == 1
int mod_inv(int a, int m){
    int x,y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}

long long chinese_remainder(vector<int> rem, vector<int> mod){
    long long ans = rem[0],m = mod[0];
    int n = rem.size();

    for(int i=1;i<n;++i){
        int a = mod_inv(m,mod[i]);
        int b = mod_inv(mod[i],m);
        ans = (ans*b*mod[i]+rem[i]*a*m)%(m*mod[i]);
        m *= mod[i];
    }

    return ans;
}
