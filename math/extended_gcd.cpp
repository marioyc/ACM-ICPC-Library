// a*x + b*y = gcd(a,b)
int extGcd(int  a, int b, int &x, int &y){
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
int modInv(int a, int m){
    int x,y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}