#define CS 0
#define DS 500
#define ES 1000

typedef struct
{
    int opCode,codigoMaquina;
    char nmonico[5];
} TInstruccion;

typedef struct
{
    int linea;
    char rotulo[10];
} TRotulo;
