#include<stdio.h>
#include<stdlib.h>

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

typedef int (*add_ft)(int, int);
typedef int (*sub_ft)(int, int);

typedef struct
{
    add_ft add;
    sub_ft sub;
}Arithematic;

void Arith_ctor(Arithematic **current)
{
    Arithematic *newobj = (Arithematic*)malloc(sizeof(Arithematic));
    *current = newobj;
    (*current)->add = add;
    (*current)->sub = sub;
}

void main()
{
    Arithematic *Arith;
    Arith_ctor(&Arith);
    int addition = Arith->add(5,2);
    int subtraction = Arith->sub(5,2);
    printf("Results : %d and %d",addition,subtraction);
}
