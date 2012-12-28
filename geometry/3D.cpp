struct XYZ{
    double x,y,z;
    
    XYZ(){}
    XYZ(double _x, double _y, double _z) :
        x(_x), y(_y), z(_z){}
    
    void normalize(){
        double r = sqrt(x * x + y * y + z * z);
        x /= r; y /= r; z /= r;
    }
    
    XYZ cross(XYZ p){
        return XYZ(y * p.z - z * p.y,z * p.x - x * p.z,x * p.y - y * p.x);
    }
    
    double dot(XYZ p){
        return x * p.x + y * p.y + z * p.z;
    }
};

// rotar p con eje de rotacion r
XYZ rotate(XYZ p, XYZ r, double theta){
   XYZ q(0,0,0);
   double costheta,sintheta;

   r.normalize();
   costheta = cos(theta);
   sintheta = sin(theta);

   q.x += (costheta + (1 - costheta) * r.x * r.x) * p.x;
   q.x += ((1 - costheta) * r.x * r.y - r.z * sintheta) * p.y;
   q.x += ((1 - costheta) * r.x * r.z + r.y * sintheta) * p.z;

   q.y += ((1 - costheta) * r.x * r.y + r.z * sintheta) * p.x;
   q.y += (costheta + (1 - costheta) * r.y * r.y) * p.y;
   q.y += ((1 - costheta) * r.y * r.z - r.x * sintheta) * p.z;

   q.z += ((1 - costheta) * r.x * r.z - r.y * sintheta) * p.x;
   q.z += ((1 - costheta) * r.y * r.z + r.x * sintheta) * p.y;
   q.z += (costheta + (1 - costheta) * r.z * r.z) * p.z;

   return q;
}