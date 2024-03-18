const int maxn = 200005;
int pal_r[2 * maxn];

// calculates radius from palindrome centers
// even indices: odd length palindromes
// odd indices: even length palindromes
// center of s[l..r] is at index (l + r)
// s[l..r] palindrome if pal_r[l + r] >= (r - l + 2) / 2
void manacher(string &s){
    int n = s.size();
    for (int i = 0, j = 0, k = 0;i <= 2 * (n - 1);++i){
        int l = i < k ? min(pal_r[j + j - i], (k - i) / 2) : 0;
        int a = i / 2 - l, b = (i + 1) / 2 + l;
        while(0 <= a && b < n && s[a] == s[b]){
            --a;
            ++b;
            ++l;
        }
        pal_r[i] = l;
        if(k < 2 * b){
            j = i;
            k = 2 * b;
        }
    }
}