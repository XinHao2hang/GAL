#include<iostream>
#include<string.h>
using namespace std;
#include "core.hpp"
union A
{
    int a;
    char c[9];
};
int main()
{
    //vec3f a = projection(vec3f(1,5,3),(plane3f)triangle3f(vec3f(0,0,0),vec3f(1,1,0),vec3f(1,0,0)));
    //cout<<a.x<<" "<<a.y<<" "<<a.z<<endl;
    cout<<sizeof(A);
	return 0;
}
