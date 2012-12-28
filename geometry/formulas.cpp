double AreaHeron(double const &a, double const &b, double const &c){
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double Circumradius(const double &a, const double &b, const double &c){
    return a*b*c/4/AreaHeron(a,b,c);
}

double Circumradius(const point &P1, const point &P2, const point &P3){
    return (P2-P1).abs()*(P3-P1).abs()*(P3-P2).abs()/4/fabs(signed_area(P1,P2,P3));
}

double Inradius(const double &a, const double &b, const double &c){
    return 2*AreaHeron(a,b,c)/(a+b+c);
}
