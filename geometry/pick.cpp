A = I + B/2 - 1, donde:
A = Area de un poligono de coordenadas enteras
I = Numero de puntos enteros en su interior
B = Numero de puntos enteros sobre sus bordes

int IntegerPointsOnSegment(const point &P1, const point &P2){
    point P = P1-P2;
    P.x = abs(P.x); P.y = abs(P.y);
    
    if(P.x == 0) return P.y;
    if(P.y == 0) return P.x;
    return (__gcd(P.x,P.y));
}

Se asume que los vertices tienen coordenadas enteras. Sumar el valor de esta
funcion para todas las aristas para obtener el numero total de punto en el borde
del poligono.
