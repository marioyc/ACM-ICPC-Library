point get_center(point A, point B, point C){
    point v1 = (B - A).perp(),v2 = C - A;
    point m1 = (A + B) * 0.5;
    point m2 = (A + C) * 0.5;
    double k = (m2 - m1).dot(v2) / v1.dot(v2);
    return m1 + v1 * k;
}