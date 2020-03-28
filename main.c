#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    long int reg[16], ram[2000];
    long int Mascara16 = 0xFF00;
    long int prueba = 0x0F0F;
    long int prueba2 = 00040102;

    long int resultado = Mascara16 & prueba;
    printf("%04X",resultado);
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
    int CodOp,Op1,Op2;
    while(reg[4]>=0 && reg[4]<DS){
    CodOp = ram[reg[4]];

    }
}

