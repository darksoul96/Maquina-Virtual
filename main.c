#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main()
{
    long int reg[16], ram[2000];


    LeerBinario(reg,ram);

    scanf("%d");
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

    }
}

