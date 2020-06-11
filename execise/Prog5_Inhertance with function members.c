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

typedef struct _2D_Point_s _2D_Point;
typedef struct _3D_Point_s _3D_Point;

typedef void (*make2dpoint_ft)(_2D_Point *, int, int);
typedef void (*make3dpoint_ft)(_3D_Point *, int, int, int);

struct _2D_Point_s
{
    int x;
    int y;
    make2dpoint_ft setpoint;
};

struct _3D_Point_s
{
    _2D_Point xy;
    int z;
    make3dpoint_ft setpoint;
};

void set2point(_2D_Point *self, int x, int y);
void set3point(_3D_Point *self, int x, int y, int z);

void _2D_Point_ctor(_2D_Point *current)
{
    current->setpoint = set2point;
}

void _3D_Point_ctor(_3D_Point *current)
{
    current->setpoint = set3point;
}

void main()
{
    _2D_Point group2D_A;
    _3D_Point group3D_A;

    _2D_Point_ctor(&group2D_A);
    _3D_Point_ctor(&group3D_A);

    group2D_A.setpoint(&group2D_A, 1, 2);
    group3D_A.setpoint(&group3D_A, 2, 5, 9);

    printf("2D Points %d %d\n", group2D_A.x, group2D_A.y);
    printf("3D points %d %d %d\n", group3D_A.xy.x, group3D_A.xy.y, group3D_A.z);
}

void set2point(_2D_Point *self, int x, int y)
{
    self->x = x;
    self->y = y;
}
void set3point(_3D_Point *self, int x, int y, int z)
{
    self->xy.x = x;
    self->xy.y = y;
    self->z = z;
}
