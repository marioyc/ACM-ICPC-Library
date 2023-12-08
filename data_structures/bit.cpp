template<typename T>
struct BIT{
    int n;
    vector<T> bit;

    BIT(int n) : n(n){
        bit = vector<T>(n);
    }

    void update(int idx, T val){
        while(idx < n){
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    T query(int idx){
        T ret = 0;
        while(idx > 0){
            ret += bit[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
};
