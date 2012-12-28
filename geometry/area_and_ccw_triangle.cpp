double signed_area(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)/2;
}

bool ccw(const point &p1, const point &p2, const point &p3){
    return signed_area(p1,p2,p3)>-eps;
}
