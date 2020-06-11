/*
    TOPIC : Void Pointer Analysis
    ===================================================================
    ->In general pointer should be assigned to same data type but
      exception to this rule is void pointer.
    ->We can assign address of any data type to void pointer likewise
      void pointer can be assigned to pointer of any other data type.
    ===================================================================
    RELATED TO PRIMITIVE DATATYPE:
        1. pointer to float is capable of point double data type through
           void pointer because 8 byte double is larger than 4 byte
           float.
        2. pointer to char is capable of point int data type through
           void pointer but reverse is undefined.
        3. pointer to (char,int(or)short) is capable of point long int.
    ===================================================================
    RELATED TO USER DEFINED DATA TYPE:
        1. Structure variable address is always same as the address
           of its first member
        2. In below example &var is same as &var.papa.if &var is
           passed to void pointer then by using arrow operator we
           can access all members in base structure.
        3. Array name also has same address as 1st element in it.
*/

#include<stdio.h>

typedef struct momo
{
    int b;
    int d;
}MOMO;

void findme(void *me)
{
    printf("%d",((MOMO *)me)->d);
}

int main()
{
    struct demo
    {
        MOMO papa;
        int a[5];
        char b;
    }var = {{987,654},{1,2,3},'A'};

    printf("%d %d\n\n",&var.papa,&var);//same address
    findme(&var);
}
