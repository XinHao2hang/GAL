#ifndef GEOMETRY_ALGORITHM_HPP
#define GEOMETRY_ALGORITHM_HPP
/*
 * 基本几何算法
 * */
#include"primitives.h"

/*
 * 计算平面与直线是否相交
 * */
template<typename T>
inline bool intersect(Line<vec3<T>> L,Plane<vec3<T>> S,vec3<T>& result)/*两点表示的直线*/
{
    if(L.direction.dot(S.normal) == 0)
        return false;
    result = L.point + L.direction * ((S.point - L.point).dot(S.normal)) * (1 / (L.direction.dot(S.normal)));
    return true;
}

/*
 * 获取两个向量夹角cos值
 * */
template<typename T>
T getCos(vec3<T> A,vec3<T> B)
{
    return A.dot(B) / (A.length()*B.length());
}

/*
 * 计算向量A在向量B上的投影长度
 * */
template<typename T>
inline T projection(vec3<T> A,vec3<T> B)
{
    return A.length() * getCos(A,B);
}

/*
 * 计算点到直线投影
 * */
template<typename T>
inline vec3<T> projection(vec3<T> P,Line<vec3<T>> L)
{
    return L.point + L.direction * projection(P - L.point,L.direction);
}

/*
 * 计算点P到直线B的距离
 * */
template<typename T>
inline T distance(vec3<T> P,Line<vec3<T>> L)
{
    return ((P - L.point).cross(L.direction)).length();
}

/*
 * 计算点P到平面S的距离
 * */
template<typename T>
inline T distance(vec3<T> P,Plane<vec3<T>> S)
{
    
    return (P - S.point).dot(S.normal);
}

/*
 * 计算点到平面投影
 * */
template<typename T>
inline vec3<T> projection(vec3<T> P,Plane<vec3<T>> S)
{
    return P - S.normal * distance(P,S);
}

/*
 * 计算两点间距离
 * */
template<typename T>
inline T distance(vec3<T> A,vec3<T> B)
{
    return (B-A).length();
}


/*
 * 计算点是否在有限平面上
 * */
template<typename T>
inline bool intersect(vec3<T> point,Triangle<vec3<T>> S)
{
    
}
#endif // GEOMETRY_ALGORITHM_HPP
