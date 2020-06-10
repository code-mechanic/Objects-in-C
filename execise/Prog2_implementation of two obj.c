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

int SumofArray(int arr[], int size)
{
    static int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int findFactorial(int n)
{
    static int result = 1;
    if(n == 0 || n == 1)
        return 1;
    else
    {
        result = n*findFactorial(n-1);
    }
    return result;
}
typedef int (*add_ft)(int, int);
typedef int (*sub_ft)(int, int);
typedef int (*sumofarray_ft)(int arr[], int);
typedef int (*factorial_ft)(int);

typedef struct
{
    add_ft add;
    sub_ft sub;
    sumofarray_ft SumofArray;
    factorial_ft findFactorial;
}Arithematic;

void Arith_ctor(Arithematic **current)
{
    Arithematic *newobj = (Arithematic*)malloc(sizeof(Arithematic));
    (*current) = newobj;
    (*current)->add = add;
    (*current)->sub = sub;
    (*current)->SumofArray = SumofArray;
    (*current)->findFactorial = findFactorial;
}

void main()
{
    int arr[] = {1,2,3,4,5};
    /*OBJECT creation*/
    Arithematic *Arith_obj1;
    Arithematic *Arith_obj2;

    /* Constructor calling*/
    Arith_ctor(&Arith_obj1);
    Arith_ctor(&Arith_obj2);

    /*Calling member function from a class*/
    int addition = Arith_obj1->add(5,2);
    int subtraction = Arith_obj1->sub(5,2);
    int sumArray = Arith_obj2->SumofArray(arr,5);
    int factorial = Arith_obj2->findFactorial(4);

    printf("Results from object 1 : %d and %d\n",addition,subtraction);
    printf("Results from object 2 : %d and %d",sumArray,factorial);

    /*Releasing the memory*/
    free(Arith_obj1);
    free(Arith_obj2);
}

