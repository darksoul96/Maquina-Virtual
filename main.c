#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    long int reg[16], ram[2000];
    printf("%08X\n",CodOp);
    printf("%08X\n",Op1);
    printf("%08X\n",Op2);
    //LeerBinario(reg,ram);
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
    long instruccion;
    while(reg[4]>=0 && reg[4]<DS){
        interprete(reg,ram);
        (reg[4])++;
    }
}

void Interprete(long int reg[], long int ram[]){
        long int CodOp,Op1,Op2;
        instruccion = ram[reg[4]];
        CodOp = instruccion & 0xFFFF0000;
        Op1 = instruccion & 0x0000FF00;
        Op2 = instruccion & 0x000000FF;

}

