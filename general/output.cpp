ostream &operator << (ostream &os, unsigned __int128 x) {
    static char buf[40];
    int len = 0;
    do{
        buf[len++] = '0' + x % 10;
        x /= 10;
    }while(x > 0);
    for(int i = len - 1;i >= 0;--i) os << buf[i];
    return os;
}

ostream &operator << (ostream &os, __int128 x) {
    if(x < 0){
        os << '-' << static_cast<unsigned __int128>(-x);
    }else{
        os << static_cast<unsigned __int128>(x);
    }
    return os;
}
