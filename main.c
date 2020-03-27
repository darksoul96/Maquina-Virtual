#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int reg[16], ram[2000];


    return 0;
}

void LeerBinario(long int reg[], long int ram[])
{
    FILE *Arch;

    Arch=fopen("imagen.img","rb");
    if (Arch!=null)
    {
        fread(reg, sizeof(long int), 16, Arch);
        fread(ram, size(long int), 2000, Arch);
    }

    fclose(Arch);
}

