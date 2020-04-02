#include <stdio.h>
#include <stdlib.h>

int main(){
    long reg[16],ram[2000];
    FILE *Arch;
    int i;
    Arch=fopen("imagenMemoria.img","r");
    if (Arch!=NULL)
    {
        for (i=0; i<16; i++){
            fread(&(reg[i]),sizeof(long),1,Arch);}
        i=0;
        while (fread(&(ram[i]),sizeof(long),1,Arch))
            i++;
    }
    fclose(Arch);
    for(i=0;i<16;i++){
       printf("Reg: %X\n",reg[i]);
    }
    //ram[0]=0x00040102;
    //ram[1]=0x0A;
    //ram[2]=0x20000020;
    for (i=0;i<19; i+=3)
            printf("\n[%08X]\t\t\t%08X %08X %08X",i,ram[i],ram[i+1],ram[i+2]);
}
