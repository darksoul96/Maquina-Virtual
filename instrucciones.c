            #include <stdio.h>
            #include <stdlib.h>
            #include <time.h>

            void mov(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=*op2;
                reg[9]=0x00000000;
                if (*op1 == 0)
                    (reg[9])+=1;
                    else
                        if (*op1 < 0)
                            (reg[9])+=0x80000000;
            }

            void add(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) + (*op2);
                reg[9]=0x00000000;
                if (*op1 == 0)
                    (reg[9])+=1;
                    else
                        if (*op1 < 0)
                            (reg[9])+=0x80000000;
            }

            void sub(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) - (*op2);
                reg[9]=0x00000000;
                if (*op1 == 0)
                    (reg[9])+=1;
                    else
                        if (*op1 < 0)
                            (reg[9])+=0x80000000;
            }

            void mul(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) * (*op2);
                reg[9]=0x00000000;
                if (*op1 == 0)
                    (reg[9])+=1;
                    else
                        if (*op1 < 0)
                            (reg[9])+=0x80000000;
            }

            void divi(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) / (*op2);
                reg[9]=0x00000000;
                if (*op1 == 0)
                    (reg[9])+=1;
                    else
                        if (*op1 < 0)
                            (reg[9])+=0x80000000;
            }

            void mod(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1)%(*op2);
                reg[9]=0x00000000;
                if (*op1 == 0)
                    (reg[9])+=1;
                    else
                        if (*op1 < 0)
                            (reg[9])+=0x80000000;
            }

            void cmp(long int *op1, long int *op2, long int reg[], long int ram[]){
                 reg[9]=0x00000000;
                if ((*op1) - (*op2) == 0)
                    (reg[9])+=1;
                    else
                        if ((*op1) - (*op2) < 0)
                            (reg[9])+=0x80000000;
            }

            void swap(long int *op1, long int *op2, long int reg[], long int ram[]){
                long int aux;

                aux=*op1;
                *op1=*op2;
                *op2=aux;
            }

            void rnd(long int *op1, long int *op2, long int reg[], long int ram[]){
                 time_t t;

                 srand((unsigned) time(&t));
                 *op1=rand()%(*op2);
            }

            void and(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) & (*op2);
                reg[9]=0x00000000;
                if ((*op1)== 0)
                    (reg[9])+=1;
                    else
                        if ((*op1)< 0)
                            (reg[9])+=0x80000000;
            }

            void or(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) | (*op2);
                reg[9]=0x00000000;
                if ((*op1) == 0)
                    (reg[9])+=1;
                    else
                        if ((*op1)< 0)
                            (reg[9])+=0x80000000;
            }

            void not(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=~(*op1);
                reg[9]=0x00000000;
                if ((*op1) == 0)
                    (reg[9])+=1;
                    else
                        if ((*op1) < 0)
                            (reg[9])+=0x80000000;
            }

            void xor(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) ^ (*op2);
                reg[9]=0x00000000;
                if ((*op1) == 0)
                    (reg[9])+=1;
                    else
                        if ((*op1) < 0)
                            (reg[9])+=0x80000000;
            }

            void shl(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) << (*op2);
            }

            void shr(long int *op1, long int *op2, long int reg[], long int ram[]){
                *op1=(*op1) >> (*op2);
            }


            void jmp(long int *op1, long int *op2, long int reg[], long int ram[]){
                reg[4]=*op1;
            }

            void je(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((*op1)==reg[0x0A])
                    reg[4]=*op2;
            }

            void jg(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((*op1)>reg[0x0A])
                    reg[4]=*op2;
            }

            void jl(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((*op1)<reg[0x0A])
                    reg[4]=*op2;
            }

            void jz(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((reg[9])==0x01)
                    reg[4]=*op1;
            }

            void jn(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((reg[9])==0x80000000)
                    reg[4]=*op1;
            }

            void jp(long int *op1, long int *op2, long int reg[], long int ram[]){
                if (((reg[9])!=0x80000000) && ((reg[9])!=0x01))
                    reg[4]=*op1;
            }

            void jnz(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((reg[9])!=0x01)
                    reg[4]=*op1;
            }

            void jnn(long int *op1, long int *op2, long int reg[], long int ram[]){
                if ((reg[9])!=0x80000000)
                    reg[4]=*op1;
            }

            void jnp(long int *op1, long int *op2, long int reg[], long int ram[]){
                if (((reg[9])==0x80000000) || ((reg[9])==0x01))
                    reg[4]=*op1;
            }


            void sys(long int *op1, long int *op2, long int reg[], long int ram[]){
                long mascara=0x01, aux;
                int bits[16], i;
                char auxc;

                for (i=0;i<16;i++){
                        if (reg[10] & mascara)
                            bits[i]=1;
                        else
                            bits[i]=0;
                        mascara <<= 1;
                    }

                if (*op1 == 1){
                    if (bits[8] == 0){
                        if (bits[0] == 1){
                            for (i=0;i<reg[12];i++){
                               scanf("%d",&aux);
                               ram[reg[13]+reg[2]+i]=aux;
                            }
                        }
                        else
                            if (bits[2] == 1){
                                for (i=0;i<reg[12];i++){
                                    scanf("%o",&aux);
                                    ram[reg[13]+reg[2]+i]=aux;
                                }
                            }
                        else{
                            for (i=0;i<reg[12];i++){
                                scanf("%x",&aux);
                                ram[reg[13]+reg[2]+i]=aux;
                            }
                        }
                    }
                    else{
                        for (i=0;i<reg[12];i++){
                            scanf("%c",&auxc);
                            ram[reg[13]+reg[2]+i]=auxc;
                        }
                    }

                }
                else
                    if ((*op1 == 2) || (*op1 == 3)){

                        if (bits[0] == 1){ //Imprime celda decimal
                            if ((bits[12] == 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++)
                                    printf("[%04ld]: %d\n",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                            else
                            if((bits[12] == 0) && (bits[8] != 0))
                                for (i=0;i<reg[12];i++)
                                    printf("[%04ld]: %d",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                            else
                            if ((bits[12] != 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++)
                                    printf("%d\n",ram[reg[2]+reg[13]+i]);
                            else
                                for (i=0;i<reg[12];i++)
                                    printf("%d",ram[reg[2]+reg[13]+i]);
                        }

                        if (bits[2] == 1){ //Imprime celda octal
                            if ((bits[12] == 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++)
                                    printf("[%04ld]: %o\n",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                            else
                            if((bits[12] == 0) && (bits[8] != 0))
                                for (i=0;i<reg[12];i++)
                                    printf("[%04ld]: %o",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                            else
                            if ((bits[12] != 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++)
                                    printf("%o\n",ram[reg[2]+reg[13]+i]);
                            else
                                for (i=0;i<reg[12];i++)
                                    printf("%o",ram[reg[2]+reg[13]+i]);
                        }

                        if (bits[3] == 1){ //Imprime celda hexa
                            if ((bits[12] == 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++)
                                    printf("[%04ld]: %X\n",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                            else
                            if((bits[12] == 0) && (bits[8] != 0))
                                for (i=0;i<reg[12];i++)
                                    printf("[%04ld]: %X",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                            else
                            if ((bits[12] != 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++)
                                    printf("%X\n",ram[reg[2]+reg[13]+i]);
                            else
                                for (i=0;i<reg[12];i++)
                                    printf("%X",ram[reg[2]+reg[13]+i]);
                        }

                        if (bits[4] == 1){ //Imprime celda char
                            mascara=0xFF;
                            if ((bits[12] == 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++){
                                    auxc=(char)(ram[reg[2]+reg[13]+i] & mascara);
                                    printf("[%04ld]: %c\n",(reg[13]+i),auxc);
                                }
                            else
                            if((bits[12] == 0) && (bits[8] != 0))
                                for (i=0;i<reg[12];i++){
                                    auxc=(char)(ram[reg[2]+reg[13]+i] & mascara);
                                    printf("[%04ld]: %c",(reg[13]+i),ram[reg[2]+reg[13]+i]);
                                }
                            else
                            if ((bits[12] != 0) && (bits[8] == 0))
                                for (i=0;i<reg[12];i++){
                                    auxc=(char)(ram[reg[2]+reg[13]+i] & mascara);
                                    printf("%c\n",ram[reg[2]+reg[13]+i]);
                                }

                            else
                                for (i=0;i<reg[12];i++){
                                    auxc=(char)(ram[reg[2]+reg[13]+i] & mascara);
                                    printf("%c",ram[reg[2]+reg[13]+i]);
                                }
                        }

                        if (*op1 == 3){
                            printf("\n");
                            if (bits[0] == 1){
                                printf("[DS]: %d\n",reg[2]);
                                printf("[ES]: %d\n",reg[3]);
                                printf("[IP]: %d\n",reg[4]);
                                printf("[AC]: %d\n",reg[8]);
                                printf("[CC]: %d\n",reg[9]);
                                printf("[AX]: %d\n",reg[10]);
                                printf("[BX]: %d\n",reg[11]);
                                printf("[CX]: %d\n",reg[12]);
                                printf("[DX]: %d\n",reg[13]);
                                printf("[EX]: %d\n",reg[14]);
                                printf("[FX]: %d\n",reg[15]);
                            }
                            else
                            if (bits[2] == 1){
                                printf("[DS]: %o\n",reg[2]);
                                printf("[ES]: %o\n",reg[3]);
                                printf("[IP]: %o\n",reg[4]);
                                printf("[AC]: %o\n",reg[8]);
                                printf("[CC]: %o\n",reg[9]);
                                printf("[AX]: %o\n",reg[10]);
                                printf("[BX]: %o\n",reg[11]);
                                printf("[CX]: %o\n",reg[12]);
                                printf("[DX]: %o\n",reg[13]);
                                printf("[EX]: %o\n",reg[14]);
                                printf("[FX]: %o\n",reg[15]);
                            }
                            else
                            if (bits[3] == 1){
                                printf("[DS]: %04X\n",reg[2]);
                                printf("[ES]: %04X\n",reg[3]);
                                printf("[IP]: %04X\n",reg[4]);
                                printf("[AC]: %04X\n",reg[8]);
                                printf("[CC]: %04X\n",reg[9]);
                                printf("[AX]: %04X\n",reg[10]);
                                printf("[BX]: %04X\n",reg[11]);
                                printf("[CX]: %04X\n",reg[12]);
                                printf("[DX]: %04X\n",reg[13]);
                                printf("[EX]: %04X\n",reg[14]);
                                printf("[FX]: %04X\n",reg[15]);
                            }
                            else
                            if (bits[4] == 1){
                                mascara=0xFF;
                                printf("[DS]: %c\n",(char)(reg[2] & mascara));
                                printf("[ES]: %c\n",(char)(reg[3] & mascara));
                                printf("[IP]: %c\n",(char)(reg[4] & mascara));
                                printf("[AC]: %c\n",(char)(reg[8] & mascara));
                                printf("[CC]: %c\n",(char)(reg[9] & mascara));
                                printf("[AX]: %c\n",(char)(reg[10] & mascara));
                                printf("[BX]: %c\n",(char)(reg[11] & mascara));
                                printf("[CX]: %c\n",(char)(reg[12] & mascara));
                                printf("[DX]: %c\n",(char)(reg[13] & mascara));
                                printf("[EX]: %c\n",(char)(reg[14] & mascara));
                                printf("[FX]: %c\n",(char)(reg[15] & mascara));
                            }

                        }

                    }
            }

            void stop(long int *op1, long int *op2, long int reg[], long int ram[]){
                reg[4]=-1;
            }
