    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    void mov(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=*op2;
        reg[9]=0x00000000;
        if (*op1 == 0)
            (reg[9])+=1;
            else
                if (*op1 < 0)
                    (reg[9])+=0x80000000;
    }

    void add(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) + (*op2);
        reg[9]=0x00000000;
        if (*op1 == 0)
            (reg[9])+=1;
            else
                if (*op1 < 0)
                    (reg[9])+=0x80000000;
    }

    void sub(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) - (*op2);
        reg[9]=0x00000000;
        if (*op1 == 0)
            (reg[9])+=1;
            else
                if (*op1 < 0)
                    (reg[9])+=0x80000000;
    }

    void mul(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) * (*op2);
        reg[9]=0x00000000;
        if (*op1 == 0)
            (reg[9])+=1;
            else
                if (*op1 < 0)
                    (reg[9])+=0x80000000;
    }

    void divi(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) / (*op2);
        reg[9]=0x00000000;
        if (*op1 == 0)
            (reg[9])+=1;
            else
                if (*op1 < 0)
                    (reg[9])+=0x80000000;
    }

    void mod(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1)%(*op2);
        reg[9]=0x00000000;
        if (*op1 == 0)
            (reg[9])+=1;
            else
                if (*op1 < 0)
                    (reg[9])+=0x80000000;
    }

    void cmp(long int *op1, long int *op2, long int reg[], long int ram[])
    {
         reg[9]=0x00000000;
        if ((*op1) - (*op2) == 0)
            (reg[9])+=1;
            else
                if ((*op1) - (*op2) < 0)
                    (reg[9])+=0x80000000;
    }

    void swap(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        long int aux;

        aux=*op1;
        *op1=*op2;
        *op2=aux;
    }

    void rnd(long int *op1, long int *op2, long int reg[], long int ram[])
    {
         time_t t;

         srand((unsigned) time(&t));
         *op1=rand()%(*op2);
    }

    void and(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) & (*op2);
        reg[9]=0x00000000;
        if ((*op1)== 0)
            (reg[9])+=1;
            else
                if ((*op1)< 0)
                    (reg[9])+=0x80000000;
    }

    void or(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) | (*op2);
        reg[9]=0x00000000;
        if ((*op1) == 0)
            (reg[9])+=1;
            else
                if ((*op1)< 0)
                    (reg[9])+=0x80000000;
    }

    void not(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=~(*op1);
        reg[9]=0x00000000;
        if ((*op1) == 0)
            (reg[9])+=1;
            else
                if ((*op1) < 0)
                    (reg[9])+=0x80000000;
    }

    void xor(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) ^ (*op2);
        reg[9]=0x00000000;
        if ((*op1) == 0)
            (reg[9])+=1;
            else
                if ((*op1) < 0)
                    (reg[9])+=0x80000000;
    }

    void shl(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) << (*op2);
    }

    void shr(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        *op1=(*op1) >> (*op2);
    }


    void jmp(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        reg[4]=*op1;
    }

    void je(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((*op1)==reg[0x0A])
        {
            reg[4]=*op2;
        }
    }

    void jg(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((*op1)>reg[0x0A])
        {
            reg[4]=*op2;
        }
    }

    void jl(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((*op1)<reg[0x0A])
        {
            reg[4]=*op2;
        }
    }

    void jz(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((reg[9])==0x01)
        {
            reg[4]=*op1;
        }
    }

    void jn(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((reg[9])==0x80000000)
        {
            reg[4]=*op1;
        }
    }

    void jp(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if (((reg[9])!=0x80000000) && ((reg[9])!=0x01))
        {
            reg[4]=*op1;
        }
    }

    void jnz(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((reg[9])!=0x01)
        {
            reg[4]=*op1;
        }
    }

    void jnn(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if ((reg[9])!=0x80000000)
        {
            reg[4]=*op1;
        }
    }

    void jnp(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        if (((reg[9])==0x80000000) || ((reg[9])==0x01))
        {
            reg[4]=*op1;
        }
    }


    void sys(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        long mascara=0x01, aux;
        int bits[16], i;
        char auxc;



        if (*op1 == 1)
        {
            for (i=0;i<16;i++)
            {
                if (reg[10] & mascara)
                    bits[i]=1;
                else
                    bits[i]=0;
                mascara <<= 1;
            }

            //for (i=0;i<16;i++)
              //  printf("%d ",bits[i]);
            //printf("\n");

            if (bits[8] == 0)
            {
                if (bits[0] == 1)
                {
                    for (i=0;i<reg[12];i++)
                    {
                       scanf("%d",&aux);
                       ram[reg[13]+reg[2]+i]=aux;
                    }
                }
                else
                    if (bits[2] == 1)
                    {
                        for (i=0;i<reg[12];i++)
                        {
                            scanf("%o",&aux);
                            ram[reg[13]+reg[2]+i]=aux;
                        }
                    }
                else
                {
                    for (i=0;i<reg[12];i++)
                    {
                        scanf("%x",&aux);
                        ram[reg[13]+reg[2]+i]=aux;
                    }
                }
            }
            else
            {
                for (i=0;i<reg[12];i++)
                {
                    scanf("%c",&auxc);
                    ram[reg[13]+reg[2]+i]=auxc;
                }
            }

        }
        else
            if ((*op1 == 2) || (*op1 == 3))
            {
                for (i=0;i<16;i++)
                {
                    if (reg[10] & mascara)
                        bits[i]=1;
                    else
                        bits[i]=0;
                    mascara <<= 1;
                }


            }
            else
            {


            }


    }

    void stop(long int *op1, long int *op2, long int reg[], long int ram[])
    {
        reg[4]=-1;
    }
