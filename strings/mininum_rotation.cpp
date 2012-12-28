int min_rotation(char *s){
    int N = strlen(s),ans = 0,p = 1,len = 0;
    
    while(p < N && ans + len + 1 < N){
        if(s[ans + len] == s[(p + len) % N]) ++len;
        else if(s[ans + len] < s[(p + len) % N]){
            p = p + len + 1;
            len = 0;
        }else{
            ans = max(ans + len + 1,p);
            p = ans + 1;
            len = 0;
        }
    }
    
    return ans;
}
