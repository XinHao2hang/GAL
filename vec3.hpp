#ifndef VEC3_HPP
#define VEC3_HPP
/*
 * 三维向量:
 * 向量表示为列向量,仅用作坐标表示和变换使用,不是标准线性代数计算的向量
 * 
 * */
 #include"pmath.hpp"
template<typename T = float> 
class vec3
{
    
public:
    //三个分量
    T x,y,z;
    vec3(){};
    //构造函数
    vec3(T p_x,T p_y,T p_z):x(p_x),y(p_y),z(p_z){}
    //加法
    inline vec3 operator+(const vec3 & vec){return vec3(x + vec.x,y + vec.y,z + vec.z);}
    //减法
    inline vec3 operator-(const vec3 & vec){return vec3(x - vec.x,y - vec.y,z - vec.z);}
    //点积
    inline T dot(const vec3 & vec){return (x * vec.x + y * vec.y + z * vec.z);}
    //叉积
    inline vec3 cross(const vec3 & vec){return vec3(y * vec.z - vec.y * z,z * vec.x - vec.z * x,x * vec.y - vec.x * y);}
    //数乘
    inline vec3 operator*(T num){return vec3(num * x,num * y,num * z);}
    //反向
    inline vec3 operator-(){return vec3(-x,-y,-z);}
    //向量长度
    inline T length(){return sqrt(x * x + y * y + z * z);}
    //向量归一化
    inline void normal(){*this = getNormal();}
    //获取归一化向量
    inline vec3 getNormal(){return (*this)*(1/length());}
    //计算两个向量夹角cos值
    //inline T getCos(const vec3 & vec){return (*this).dot(vec)/((*this).length()*vec.length());}
    ~vec3(){};
};

#endif // VEC3_HPP
