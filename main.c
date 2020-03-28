#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    long int reg[16], ram[2000];
    //LeerBinario(reg,ram);
    void (*funciones[143]);

    double (*vector[10])(double);
    vector[0] = sin;
    vector[1] = cos;
    vector[CodOp](Op1,Op2,ram,reg);

    return 0;
}

void LeerBinario(long int reg[], long int ram[])
{
    FILE *Arch;

    Arch=fopen("imagen.img","rb");
    if (Arch!=NULL)
    {
        fread(reg, sizeof(long int), 16, Arch);
        fread(ram, sizeof(long int), 2000, Arch);
    }

    fclose(Arch);
}


void Ejecucion(long int reg[], long int ram[]){
    long celda1,celda2,celda3;
    while(reg[4]>=0 && reg[4]<DS){
        celda1 = ram[reg[4];
        celda2 = ++ram[reg[4];
        celda3 = ++ram[reg[4];
        interprete(celda1, celda2, celda3, reg,ram);
        (reg[4])++;
    }
}

void Interprete(long celda1, long celda2, long celda3, long int reg[], long int ram[]){
        long int CodOp,TOp1,TOp2,Op1,Op2;
        CodOp = celda1 & 0xFFFF0000;
        TOp1 = celda1 & 0x0000FF00;
        TOp2 = celda1 & 0x000000FF;
}


void cargaOp(long int TOp, long int *Op){

}

}



