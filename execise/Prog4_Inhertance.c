/*
    TOPIC : Inheritance in c language
    Inheritance makes the availability of member variable (or) member function (or)
    feature/properties/characteristics of base class into derived class.This have
    advantage of code reusable.

    TERMINOLOGY : Base/Derived (or) Parent/child

    TYPES :
    1.Single
        A Derived class with only one Base class.
    2.Multilevel
        A Derived class with base class and that base class is derived class of
        another class
    3.Multiple
        A Derived class with multiple base class
    4.Hierarchical
        Multiple derived class with same base class
    5.Hybrid
        combination of Multiple and Hierarchical Inheritance
    6.Multipath
        A derived class with 2 base class and that 2 base class is derived from
        one common base class
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
}_2D_Point;

typedef struct{
    _2D_Point xy;
    int z;
}_3D_Point;

void main()
{
    _2D_Point group2D_A;
    _3D_Point group3D_A;

    group2D_A.x = 10;
    group2D_A.y = 6;
    group3D_A.xy.x = 5;
    group3D_A.xy.y = 9;
    group3D_A.z = 6;

    printf("2D Points %d %d\n", group2D_A.x, group2D_A.y);
    printf("3D points %d %d %d\n", group3D_A.xy.x, group3D_A.xy.y, group3D_A.z);
}

