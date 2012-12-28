int survivor(int n, int m){
   for (int s=0,i=1;i<=n;++i) s = (s+m)%i;
   return (s+1);
}
