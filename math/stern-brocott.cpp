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
