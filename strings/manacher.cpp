void manacher(int n, const char s[], int p[]){
  for (int i = 0, j = 0, k = 0; i <= 2 * (n - 1); ++i){
    int l = i < k ? min(p[j + j - i], (k - i) / 2) : 0;
    int a = i / 2 - l, b = (i + 1) / 2 + l;
    
    while(0 <= a && b < n && s[a] == s[b]){
      --a;
      ++b;
      ++l;
    }
    
    p[i] = l;
    
    if(k < 2 * b){
      j = i;
      k = 2 * b;
    }
  }
}