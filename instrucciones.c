#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mov(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=*op2;
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void add(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) + (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void sub(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) - (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void mul(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) * (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void divi(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) / (*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void mod(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1)%(*op2);
    *cc=0x00000000;
    if (*op1 == 0)
        (*cc)+=1;
        else
            if (*op1 < 0)
                (*cc)+=0x80000000;
}

void cmp(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
     *cc=0x00000000;
    if ((*op1) - (*op2) == 0)
        (*cc)+=1;
        else
            if ((*op1) - (*op2) < 0)
                (*cc)+=0x80000000;
}

void swap(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    long int aux;

    aux=*op1;
    *op1=*op2;
    *op2=aux;
}

void rnd(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
     time_t t;

     srand((unsigned) time(&t));
     *op1=rand()%(*op2);
}

void and(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) & (*op2);
    *cc=0x00000000;
    if ((*op1)== 0)
        (*cc)+=1;
        else
            if ((*op1)< 0)
                (*cc)+=0x80000000;
}

void or(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) | (*op2);
    *cc=0x00000000;
    if ((*op1) == 0)
        (*cc)+=1;
        else
            if ((*op1)< 0)
                (*cc)+=0x80000000;
}

void not(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=~(*op1);
    *cc=0x00000000;
    if ((*op1) == 0)
        (*cc)+=1;
        else
            if ((*op1) < 0)
                (*cc)+=0x80000000;
}

void xor(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) ^ (*op2);
    *cc=0x00000000;
    if ((*op1) == 0)
        (*cc)+=1;
        else
            if ((*op1) < 0)
                (*cc)+=0x80000000;
}

void shl(long int *op1, long int *op2, long int  *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) << (*op2);
}

void shr(long int *op1, long int *op2, long int  *cc, long int *ip, long int reg[], long int ram[])
{
    *op1=(*op1) >> (*op2);
}


void jmp(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *ip=*op1;
}

void je(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*op1)==reg[0x0A])
    {
        *ip=*op2;
    }
}

void jg(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*op1)>reg[0x0A])
    {
        *ip=*op2;
    }
}

void jl(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*op1)<reg[0x0A])
    {
        *ip=*op2;
    }
}

void jz(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*cc)==0x01)
    {
        *ip=*op1;
    }
}

void jn(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*cc)==0x80000000)
    {
        *ip=*op1;
    }
}

void jp(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if (((*cc)!=0x80000000) && ((*cc)!=0x01))
    {
        *ip=*op1;
    }
}

void jnz(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*cc)!=0x01)
    {
        *ip=*op1;
    }
}

void jnn(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if ((*cc)!=0x80000000)
    {
        *ip=*op1;
    }
}

void jnp(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    if (((*cc)==0x80000000) || ((*cc)==0x01))
    {
        *ip=*op1;
    }
}


void sys(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
}

void stop(long int *op1, long int *op2, long int *cc, long int *ip, long int reg[], long int ram[])
{
    *ip=-1;
}
