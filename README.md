```cpp

/// biblioteca para manipulação de vetores 3d.
/// verção sem comentarios em vec3.h.

class vec3{
    public:
    float x,y,z;
    
    bool s; // 
    int w;  // vriaveis axtras usadas em outros projetos (opcional)
    
    vec3():x(0.0), y(0.0), z(0.0){} 
    vec3(float x_, float y_, float z_) :x(x_), y(y_), z(z_){}
    ~vec3(){}                                                   
    /// construtores EX: 
    /// vec3   vec; gera um vetor com (0,0,0);
    /// vec3   vec(10,10,10); gera um vetor (10,10,10);
     
    vec3 abs(){return vec3(std::abs(x), std::abs(y), std::abs(z));}
    /// quando cahamada retorna um vetor com os componetes x, y e z positivos. EX:
    // vec = vec.abs();

    vec3 operator+(const vec3& v)const  {return vec3(x + v.x,y + v.y, z + v.z);}
    void operator+=(const vec3& v) {x += v.x;y += v.y; z += v.z;}
    vec3 operator-(const vec3& v)const  {return vec3(x - v.x,y - v.y, z - v.z);}
    void operator-=(const vec3& v) {x -= v.x;y -= v.y; z -= v.z;}
    vec3 operator/(const vec3& v)const  {return vec3(x / v.x,y / v.y, z / v.z);}
    void operator/=(const vec3& v) {x /= v.x;y /= v.y; z /= v.z;}
    vec3 operator*(const vec3& v)const  {return vec3(x * v.x,y * v.y, z * v.z);}
    void operator*=(const vec3& v) {x *= v.x;y *= v.y; z *= v.z;}
    /// operadores emtre vec3 e vec3. EX:
    /// vec += vec3(3,3,3); vec começou como (0,0,0), terminou com (3,3,3); a mesma logica serve para as outras três operações.
    /// vec = vec_1 + vec3(3,3,3); aqui acontece a mesma coisa com vec, vec_1 não foi alterado.

    vec3 operator+(const float& v)const  {return vec3(x + v,y + v, z + v);}
    void operator+=(const float& v) {x += v;y += v; z += v;}
    vec3 operator-(const float& v)const  {return vec3(x - v,y - v, z - v);}
    void operator-=(const float& v) {x -= v;y -= v; z -= v;}
    vec3 operator/(const float& v)const  {return vec3(x / v,y / v, z / v);}
    void operator/=(const float& v) {x /= v;y /= v; z /= v;}
    vec3 operator*(const float& v)const  {return vec3(x * v,y * v, z * v);}
    void operator*=(const float& v) {x *= v;y *= v; z *= v;}
    /// operadores entre vec3 e float. EX:
    /// vec += 3; vec começou como (0,0,0), terminou com (3,3,3); a mesma logica serve para as outras três operações.
    /// vec = vec_1 + 3; aqui acontece a mesma coisa com vec, vec_1 não foi alterado.

    bool operator==(const vec3& v)const {return (x == v.x && y == v.y && z == v.z);}
    bool operator!=(const vec3& v)const {return (x != v.x && y != v.y && z != v.z);}
    bool operator<=(const vec3& v)const {return (x <= v.x && y <= v.y && z <= v.z);}
    bool operator>=(const vec3& v)const {return (x >= v.x && y >= v.y && z >= v.z);}
    bool operator<(const vec3& v)const {return (x < v.x && y < v.y && z < v.z);}
    bool operator>(const vec3& v)const {return (x > v.x && y > v.y && z > v.z);}
    /// operadores logicos.
    /// sempre compara os componentes uns com os outros. x com x, y com y, e z com z.
    
    void print(){std::cout<< "x:" << x << " y:" << y << " z:" << z  <<std::endl;}
    /// função print para debuging. EX:
    /// vec.print();

    int dotProduct(const vec3& v){return (v.x*x)+(v.y*y)+(v.z*z);}
    /// retorna o produto da multiplicação dos vetores, ou produto escalar.
    
    float mag(){return( sqrt((x*x) + (y*y) + (z*z)));}
    /// retorna a magnitude do vertor, ou a distância que ele esta da origen(0,0,0).
    
    uint64_t ID(){return ((x)+(y*1000000)+(z*1000000000000));}
    /// retorna um ID unico para cada vetor dentro de uma area de 1000000x1000000x1000000, vetores mais distantes disto pode ter o mesmo ID, ou se adiferença entre eles for menor que 0.000001. em ambos os componentes x,y e z.
    
    void normaliza(){
        float m = mag();
        if(m > 0){
            x /= m; y /= m; z /= m;
        }
    }
    /// normaliza o vetor. EX:
    /// vec.normaliza; a distancia entre vec e a origem será de 1.
    
    vec3 prodVectorial(const vec3& v){
    return vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }
    /// retorna o produto crusado de dois  vetores. EX:
    /// vec = vec_1.prodVectorial(vec_2);
    
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
    /// roteciona o vetor em relação a um ponto e um ou mais eixos;
    /// vec.rotate(vec3(0,0,0), vec3(1,1,1), 120); rotaciona vec mos eixos x, y e z, na mesma proporção, 120 graus, tendo como eixp a origem(0,0,0).
    void invert(){
        x = -x;
        y = -y;
        z = -z;
    }
    /// inverte a direção que o vetor esta apontando. EX:
    /// vec.invert();
    
   std::string compact_to_send(){
        char* data;
        data = (char*)this;
        std::string s;
        for(int i = 0; i < sizeof(vec3); i++){
            s += data[i];
        }
        return s;
    }
    /// converte o vetor em um array de caracteres.
    
    int descompact_to_use(std::string s){
        if(sizeof(vec3) != s.size())return -1;

        char *data = new char[sizeof(vec3)];
        data = (char*)s.c_str();
        *this = *(vec3*)data;
    }
    /// converte um arra de carcteres em um vetor;
    /// vec.descompat_to_use(vec.compact_to_send()); 
};
