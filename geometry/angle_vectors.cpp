double get_angle(point P1, point P2){
    double sina = P1.y / P1.abs(),cosa = P1.x / P1.abs();
    double sinb = P2.y / P2.abs(),cosb = P2.x / P2.abs();
    double sinc = sinb * cosa - sina * cosb;
    double cosc = cosb * cosa + sina * sinb;
    
    double x = atan2(sinc,cosc);
    if(x < 0) x += 2 * M_PI;
    
    return x;
}
