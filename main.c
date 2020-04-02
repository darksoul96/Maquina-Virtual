#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "instrucciones.c"

void LeerBinario(long int [], long int []);
void Ejecucion(long int [], long int []);
void Interprete(long , long , long , long int [], long int []);
void (*funciones[0x8F])(long int *op1, long int *op2, long int *cc);
void cargaOp(long int TOp, long int **Op, long celda, long int reg[], long int ram[]);

void cargarFunciones(void *[]);
int main()
{
    long int reg[16], ram[2000];

    LeerBinario(reg,ram);


//    funciones[0x01]=mov;
//    funciones[0x02]=add;
//    funciones[0x03]=sub;
//    funciones[0x04]=mul;
//    funciones[0x05]=divi;
//    funciones[0x06]=mod;
//    funciones[0x13]=cmp;
//    funciones[0x17]=swap;
//    funciones[0x19]=rnd;
//    funciones[0x31]=and;
//    funciones[0x32]=or;
//    funciones[0x33]=not;
//    funciones[0x34]=xor;
//    funciones[0x37]=shl;
//    funciones[0x38]=shr;
//    funciones[0x20]=jmp;
//    funciones[0x21]=je;
//    funciones[0x22]=jg;
//    funciones[0x23]=jl;
//    funciones[0x24]=jz;
//    funciones[0x25]=jp;
//    funciones[0x26]=jn;
//    funciones[0x27]=jnz;
//    funciones[0x28]=jnp;
//    funciones[0x29]=jnn;
//    funciones[0x81]=sys;
//    funciones[0x8F]=stop;

    Ejecucion(reg,ram);
    //cargarFunciones(funciones);

    return 0;
}

void LeerBinario(long int reg[], long int ram[])
{
    FILE *Arch;
    Arch=fopen("imagenMemoria.img","r");
    if (Arch!=NULL)
    {
        fread(reg, sizeof(long int), 16, Arch);
        fread(ram, sizeof(long int), 2000, Arch);
    }
    fclose(Arch);
}


void Ejecucion(long int reg[], long int ram[]){ // YA ESTA PROBADO QUE LEE BIEN, DEJE LOS PRINT PARA VER NOMAS
    long celda1,celda2,celda3;
    long int IP;
    IP = reg[4];
    while(IP>=0 && IP<reg[2]){
        celda1 = ram[IP];
        IP++;
        celda2 = ram[IP];
        IP++;
        celda3 = ram[IP];
        Interprete(celda1, celda2, celda3, reg, ram);
        IP++;
        printf("%08X\t",celda1); // LUEGO HAY QUE BORRARLOS
        printf("%08X\t",celda2);
        printf("%08X\n",celda3);
        reg[4] = IP;
    }
}

void Interprete(long celda1, long celda2, long celda3, long int reg[], long int ram[]){
        long int CodOp, TOp1, TOp2, *Op1, *Op2;
        printf("%08X\t",celda1);
        CodOp = (celda1 & 0xFFFF0000)>>16;    // REALIZO UN CORRIMIENTO DE 16 BITS A LA DERECHA, PARA QUEDARME SOLO CON EL 0004
        TOp1 = (celda1 & 0x0000FF00)>>8;
        TOp2 = celda1 & 0x000000FF;
        printf("%04X\t",CodOp);             // LOS MUESTRO SOLO PARA VER QUE ESTE BIEN CARGADO
        printf("%02X\t",TOp1);
        printf("%02X\t",TOp2);
        cargaOp(TOp1, &Op1, celda2, reg, ram);
        if(&reg[10]==Op1)                   // IGUALE EL REG[10](AX) CON EL OP1 PARA VER SI LO CARGO BIEN
            printf("Son iguales");
        cargaOp(TOp2, &Op2, celda3, reg, ram);
        if(&ram[32+reg[2]]==Op2)
            printf("Son iguales op2");
}


void cargaOp(long int TOp, long int **Op, long celda, long int reg[], long int ram[])
{
    long aux;
    if (TOp == 0x00)
    {
        *Op=(long int)malloc(sizeof(long int));
        *Op=celda;
    }
    else
        if (TOp == 0x01)
        {
            *Op=reg;
            *Op+=celda;
        }
            else
            {
                aux=(celda & 0xF0000000)>>28;
                if (aux == 0x2)
                {
                    aux=celda & 0x0FFFFFFF;
                    *Op=ram;
                    *Op+=reg[2]+aux;
                }
            }
}
