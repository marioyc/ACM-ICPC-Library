vector<int> prefix_function(string &s){
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1;i < n;++i){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}


// number of times P is found int T
int kmp_match(string &P, string &T){
    auto pi = prefix_function(P);
    int n = P.size(),nt = T.size(),k = 0,nmatch = 0;
    for(int i = 0;i < nt;++i){
        while(k > 0 && T[i] != P[k]) k = pi[k - 1];
        if(P[k] == T[i]) ++k;
        if(k == n){
            ++nmatch;
            k = pi[k - 1];
        }
    }
    return nmatch;
}
