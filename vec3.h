#ifndef VEC3_H_INCLUDED
#define VEC3_H_INCLUDED


class vec3{
    public:
    float x,y,z;
    bool s;
    int w;

    vec3():x(0.0), y(0.0), z(0.0){}
    ~vec3(){}
    vec3 abs(){return vec3(std::abs(x), std::abs(y), std::abs(z));}
    vec3(float x_, float y_, float z_) :x(x_), y(y_), z(z_){}

    vec3 operator+(const vec3& v)const  {return vec3(x + v.x,y + v.y, z + v.z);}
    void operator+=(const vec3& v) {x += v.x;y += v.y; z += v.z;}
    vec3 operator-(const vec3& v)const  {return vec3(x - v.x,y - v.y, z - v.z);}
    void operator-=(const vec3& v) {x -= v.x;y -= v.y; z -= v.z;}
    vec3 operator/(const vec3& v)const  {return vec3(x / v.x,y / v.y, z / v.z);}
    void operator/=(const vec3& v) {x /= v.x;y /= v.y; z /= v.z;}
    vec3 operator*(const vec3& v)const  {return vec3(x * v.x,y * v.y, z * v.z);}
    void operator*=(const vec3& v) {x *= v.x;y *= v.y; z *= v.z;}

    vec3 operator+(const float& v)const  {return vec3(x + v,y + v, z + v);}
    void operator+=(const float& v) {x += v;y += v; z += v;}
    vec3 operator-(const float& v)const  {return vec3(x - v,y - v, z - v);}
    void operator-=(const float& v) {x -= v;y -= v; z -= v;}
    vec3 operator/(const float& v)const  {return vec3(x / v,y / v, z / v);}
    void operator/=(const float& v) {x /= v;y /= v; z /= v;}
    vec3 operator*(const float& v)const  {return vec3(x * v,y * v, z * v);}
    void operator*=(const float& v) {x *= v;y *= v; z *= v;}

    bool operator==(const vec3& v)const {return (x == v.x && y == v.y && z == v.z);}
    bool operator!=(const vec3& v)const {return (x != v.x && y != v.y && z != v.z);}
    bool operator<=(const vec3& v)const {return (x <= v.x && y <= v.y && z <= v.z);}
    bool operator>=(const vec3& v)const {return (x >= v.x && y >= v.y && z >= v.z);}
    bool operator<(const vec3& v)const {return (x < v.x && y < v.y && z < v.z);}
    bool operator>(const vec3& v)const {return (x > v.x && y > v.y && z > v.z);}
    
    void print(){std::cout<< "x:" << x << " y:" << y << " z:" << z  <<std::endl;}

    int dotProduct(const vec3& v){return (v.x*x)+(v.y*y)+(v.z*z);}
    float mag(){return( sqrt((x*x) + (y*y) + (z*z)));}
    uint64_t ID(){return ((x)+(y*1000000)+(z*1000000000000));}
    void normaliza(){
        float m = mag();
        if(m > 0){
            x /= m; y /= m; z /= m;
        }
    }
    vec3 prodVectorial(const vec3& v){
    return vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }
    void Rotate(vec3 center, vec3 rotation, float degres){
        x -= center.x;
        y -= center.y;
        z -= center.z;
        float temp;
        const float rad_scl = 0.0174532925;

            temp = x * cos(((rotation.z*degres)*rad_scl)) - y * sin(((rotation.z * degres)*rad_scl));
            y = x *sin(((rotation.z*degres)*rad_scl)) + y * cos(((rotation.z*degres)*rad_scl));
            x = temp;

            temp = z * cos(((rotation.y*degres)*rad_scl)) - x * sin(((rotation.y * degres)*rad_scl));
            x = z *sin(((rotation.y*degres)*rad_scl)) + x * cos(((rotation.y*degres)*rad_scl));
            z = temp;
            temp = y * cos(((rotation.x*degres)*rad_scl)) - z * sin(((rotation.x * degres)*rad_scl));
            z = y *sin(((rotation.x*degres)*rad_scl)) + z * cos(((rotation.x*degres)*rad_scl));
            y = temp;

        x += center.x;
        y += center.y;
        z += center.z;
    }
    void invert(){
        x = -x;
        y = -y;
        z = -z;
    }

   std::string compact_to_send(){
        char* data;
        data = (char*)this;
        std::string s;
        for(int i = 0; i < sizeof(vec3); i++){
            s += data[i];
        }
        return s;
    }
    int descompact_to_use(std::string s){
        if(sizeof(vec3) != s.size())return -1;

        char *data = new char[sizeof(vec3)];
        data = (char*)s.c_str();
        *this = *(vec3*)data;
    }

};

#endif 

