#include"vec3.hpp"
/*
 * 直线,可以是2D,3D空间的直线,作为算法的函数输入参数使用
 * */
template<typename T> class Line
{
public:
    Line(){}
    Line(T p,T d):point(p),direction(d){}
    T point,direction;
};

/*
 * 线段
 * */
template<typename T> class SegmentLine
{
public:
    SegmentLine(){}
    SegmentLine(T pA,T pB):A(pA),B(pB){}
    T A,B;
    
};

template<typename T> class Triangle;
/*
 * 点法式平面
 * */
template<typename T> class Plane
{
public:
    Plane(){}
    Plane(T tPoint,T tNormal):point(tPoint),normal(tNormal){}
    //顶点和法向量
    T point,normal;
};

/*
 * 三角形,主要是方便平面操作,将所有平面都当做三角形处理
 * */
template<typename T> class Triangle
{
    inline Plane<T> toPlane(T pA,T pB,T pC)
    {
        return Plane<T>(pA,(pC-pA).cross(pB-pA).getNormal());
    }
public:
    Triangle(){}
    Triangle(T pA,T pB,T pC):A(pA),B(pB),C(pC){}
    T A,B,C;
    operator Plane<T>()
    {
        return toPlane(A,B,C);
    }
};

