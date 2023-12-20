const int MAX_DEN = 3000;
vector<int> Fnum,Fden;

void build(int lnum = 0, int lden = 1, int rnum = 1, int rden = 1){
    int a = lnum+rnum,b = lden+rden;
    if(b>MAX_DEN) return;
    
    build(lnum,lden,a,b);
    
    Fnum.push_back(a);
    Fden.push_back(b);
    
    build(a,b,rnum,rden);
}

template<typename T>
struct SternBrocot{
    T max_den;
    
    SternBrocot(T max_den) : max_den(max_den) {}

    // search for closest approximation of p / q
    // choose the smallest if two are equally close
    pair<T, T> search(T p, T q, T lnum = 0, T lden = 1, T rnum = 1, T rden = 1){
        assert(p >= 0 && p <= q);
        while(true){
            T mi_num = lnum + rnum;
            T mi_den = lden + rden;
            if(mi_den > max_den){
                T d_l = p * lden * rden - lnum * q * rden;
                T d_r = rnum * lden *  q - p * lden * rden;
                if(d_l <= d_r) return {lnum, lden};
                return {rnum, rden};
            }
            if(mi_num * q == mi_den * p) return {mi_num, mi_den};
            else if(mi_num * q > mi_den * p){
                if(p * lden == q * lnum) return {lnum, lden};
                T k = (q * rnum - p * rden) / (p * lden - q * lnum);
                k = min(k, (max_den - rden) / lden);
                rnum = lnum * k + rnum;
                rden = lden * k + rden;
            }else{
                if(rnum * q == p * rden) return {rnum, rden};
                T k = (p * lden - q * lnum) / (rnum * q - p * rden);
                k = min(k, (max_den - lden) / rden);
                lnum = lnum + k * rnum;
                lden = lden + k * rden;
            }
        }
        return {-1, -1};
    }
};
