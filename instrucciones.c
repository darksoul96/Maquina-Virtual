#include <stdio.h>
#include <stdlib.h>


int main()
{

    return 0;
}

void mov(long int *op1, long int *op2, long int *cc)
{
    *op1=*op2;
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void add(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) + (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void sub(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) - (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void mul(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) * (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void div(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) / (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void mod(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1)%(*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void cmp(long int *op1, long int *op2, long int *cc)
{
     *cc=0x00000000;
    if ((*op1) - (*op2) == 0)
        (*cc)+=1;
        else
            if ((*op1) - (*op2) < 0)
                (*cc)+=0x80000000;
}

void swap(long int *op1, long int *op2, long int *cc)
{
    long int aux;

    aux=*op1;
    *op1=*op2;
    *op2=aux;
}

void rnd(long int *op1, long int *op2, long int *cc)
{
     time_t t;

     srand((unsigned) time(&t));
     *op1=rand()%(*op2);
}

void and(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) & (*op2);
    if ((*op1) - (*op2) == 0)
        (*cc)+=1;
        else
            if ((*op1) - (*op2) < 0)
                (*cc)+=0x80000000;
}

void or(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) | (*op2);
    if ((*op1) - (*op2) == 0)
        (*cc)+=1;
        else
            if ((*op1) - (*op2) < 0)
                (*cc)+=0x80000000;
}

void not(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) ~ (*op2);
    if ((*op1) - (*op2) == 0)
        (*cc)+=1;
        else
            if ((*op1) - (*op2) < 0)
                (*cc)+=0x80000000;
}

void xor(long int *op1, long int *op2, long int *cc)
{
    *op1=(*op1) ^ (*op2);
    if ((*op1) - (*op2) == 0)
        (*cc)+=1;
        else
            if ((*op1) - (*op2) < 0)
                (*cc)+=0x80000000;
}

void shl(long int *op1, long int *op2, long int  *cc)
{
    *op1=(*op1) << (*op2);
}

void shr(long int *op1, long int *op2, long int  *cc)
{
    *op1=(*op1) >> (*op2);
}
