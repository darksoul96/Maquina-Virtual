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
    while(reg[4]>=0 && reg[4]<DS){
        interprete(reg,ram);
        (reg[4])++;
    }
}

void Interprete(long int reg[], long int ram[]){
        long int CodOp,TOp1,TOp2,Op1,Op2;
        long instruccion;
        instruccion = ram[reg[4]];
        CodOp = instruccion & 0xFFFF0000;
        TOp1 = instruccion & 0x0000FF00;
        TOp2 = instruccion & 0x000000FF;
        (reg[4])++;
        instruccion = ram[reg[4]];
        switch()




}



