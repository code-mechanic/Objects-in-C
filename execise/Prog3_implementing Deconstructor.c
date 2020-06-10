#include<stdio.h>
#include<stdlib.h>

void detail(char *name, int age, float h, float w)
{
    printf("My name is %s and i am %d years old and %.2f cm height and %.2f kg weight\n",
           name,age,h,w);
}

typedef void (*print_ft)(char*, int, float, float);

typedef struct
{
    int age;
    float weight;
    float height;
    char name[10];
    print_ft Print_Personal_Detail;
}Person;

Person *Person_ctor()
{
    Person *newobj = (Person*)malloc(sizeof(Person));
    newobj->Print_Personal_Detail = detail;
    return newobj;
}

void Person_dtor(Person **current)
{
    free(*current);
}

void main()
{
    /*OBJECT creation*/
    Person *Mohan;
    Person *Gokul;

    /* Parametric Constructor calling*/
    Mohan = Person_ctor();
    Gokul = Person_ctor();

    /*Calling member function from a class*/
    Mohan->Print_Personal_Detail("Mohan",21,78.5,74.6);
    Gokul->Print_Personal_Detail("Gokul",26,79.5,77.6);


    /*Deconstructor calling*/
    Person_dtor(&Mohan);
    Person_dtor(&Gokul);
}

