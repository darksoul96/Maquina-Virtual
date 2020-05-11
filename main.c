#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "instrucciones.h"

void LeerBinario(long int reg[], long int ram[], int argc, char *argv[],int imagenes);
void Ejecucion(long int [], long int []);
void Interprete(long, long, long, long int [], long int []);
void (*funciones[0x8F])(long int *op1, long int *op2, long int reg[], long int ram[]);
void cargaOp(long int TOp, long int **Op, long celda, long int reg[], long int ram[]);
void ejecutaOp(long int * Op1, long int * Op2, long int CodOp,long int reg[],long int ram[]);
void cargarFunciones(void *[]);
void cuentaProcFlag(int *imagenes, int flags[],int argc, char*argv[]);

int main(int argc, char *argv[])
{
    long int reg[16], ram[8092];
    void * funciones[0x8F];
    int flags[4]={0};
    int imagenes;
    cuentaProcFlag(&imagenes,flags,argc,argv);
    cargarFunciones(funciones);
    LeerBinario(reg,ram,argc,argv,imagenes);
    Ejecucion(reg,ram);
    return 0;
}

void cuentaProcFlag(int *imagenes, int flags[],int argc, char*argv[])
{
    int i, condicion=1, contador=0;
    argc = argc -1 ;                // el primer valor de argc no tiene nada util
    i = argc;
    while (condicion==1){
        if (strcmp(argv[i],"-d")==0){
            flags[3]=1;
            contador++;
        }
        else if (strcmp(argv[i],"-c")==0){
            flags[2]=1;
            contador++;
        }
        else if (strcmp(argv[i],"-b")==0){
            flags[1]=1;
            contador++;
        }
        else if (strcmp(argv[i],"-a")==0){
            flags[0]=1;
            condicion =0;                   // como estan en orden, si lee una -a ya terminaron las flags.
            contador++;
        }
        else
            condicion=0;
        i--;
    }
    *imagenes=argc-contador;

}


void cargarFunciones(void* func[])
{
    funciones[0x01]=mov;
    funciones[0x02]=add;
    funciones[0x03]=sub;
    funciones[0x04]=mul;
    funciones[0x05]=divi;
    funciones[0x06]=mod;
    funciones[0x13]=cmp;
    funciones[0x17]=swap;
    funciones[0x19]=rnd;
    funciones[0x31]=and;
    funciones[0x32]=or;
    funciones[0x33]=not;
    funciones[0x34]=xor;
    funciones[0x37]=shl;
    funciones[0x38]=shr;
    funciones[0x20]=jmp;
    funciones[0x21]=je;
    funciones[0x22]=jg;
    funciones[0x23]=jl;
    funciones[0x24]=jz;
    funciones[0x25]=jp;
    funciones[0x26]=jn;
    funciones[0x27]=jnz;
    funciones[0x28]=jnp;
    funciones[0x29]=jnn;
    funciones[0x81]=sys;
    funciones[0x8F]=stop;
}

void LeerBinario(long int reg[], long int ram[], int argc, char *argv[],int imagenes)
{
    int i=0,j,full=0,corrimiento,imgactual,dataSegmentOriginal;
    FILE *Arch;
    ram[0] = imagenes;
    ram[1] = 0;
    corrimiento = 16*imagenes+2;
    while(full==0 && i<ram[0])
    {
        imgactual = i+1;                          // argv arranca de 1, por eso le sumo 1.
        Arch=fopen(argv[imgactual],"rb");
        if (Arch!=NULL)
        {
            fread(reg, sizeof(long int), 16, Arch);     // Leo los reg de la img en los de la MV y los recalculo 1 por 1.
            dataSegmentOriginal = reg[2];               // Guardo la longitud del CS original para copiar en ram con fread.
            reg[1] += corrimiento;
            reg[2] += corrimiento;
            if(reg[3]== -1 )
                reg[3] = ram[ (16 * (i) + 2)  + 3]; // rescato el ES de la imagen anterior. acordarse que i=0 equivale a la img 1.
            else
                reg[3]+= corrimiento;
            reg[5]+= corrimiento;
            for(j=0; j<16; j++)             // cargo los registros corregidos en su correspondiente lugar de la ram.
                ram[16*i+2] = reg[j];
            fread(ram[reg[1]],sizeof(long int),dataSegmentOriginal,Arch);   // Cargo en Ram el CS, partiendo desde el CS corregido.
            corrimiento += reg[0];
            if(corrimiento > 8192)
                full = 1;
            fclose(Arch);
        }
        else
        {
            printf("Archivo %d es invalido",i);
        }

    }
    if(full==1)
        printf("Memoria insuficiente");
    i++;
}



void Ejecucion(long int reg[], long int ram[])
{
    long celda1,celda2,celda3;
    long int salto;
    int cCelda=0;
    reg[4]=1;
    salto = reg[4];
    while(cCelda>=0 && cCelda<reg[2])
    {
        celda1 = ram[cCelda];
        cCelda++;
        celda2 = ram[cCelda];
        cCelda++;
        celda3 = ram[cCelda];
        Interprete(celda1, celda2, celda3, reg, ram);
        if(salto == reg[4])
            reg[4]++;
        cCelda=(reg[4]-1)*3;
        salto = reg[4];
    }
}

void Interprete(long celda1, long celda2, long celda3, long int reg[], long int ram[])
{
    long int CodOp, TOp1, TOp2, *Op1, *Op2;
    CodOp = (celda1 & 0xFFFF0000)>>16;
    TOp1 = (celda1 & 0x0000FF00)>>8;
    TOp2 = celda1 & 0x000000FF;
    cargaOp(TOp1, &Op1, celda2, reg, ram);
    cargaOp(TOp2, &Op2, celda3, reg, ram);
    ejecutaOp(Op1,Op2,CodOp,reg,ram);
}


void cargaOp(long int TOp, long int **Op, long celda, long int reg[], long int ram[])
{
    long aux;

    if (TOp == 0x00)
    {
        *Op=(long int)malloc(sizeof(long int));
        **Op=celda;
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
            else
            {
                if(aux == 0x3)
                {
                    aux=celda & 0x0FFFFFFF;
                    *Op=ram;
                    *Op+=reg[3]+aux;
                }

            }
        }
}

void ejecutaOp(long int * Op1, long int * Op2, long int CodOp,long int reg[],long int ram[])
{
    (*funciones[CodOp])(Op1,Op2,reg,ram);
}
