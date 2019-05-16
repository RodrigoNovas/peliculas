#ifndef ACTORES_H_INCLUDED
#define ACTORES_H_INCLUDED

typedef struct
{
     int id;
     char nombre[51];
     char paisDeOrigen[51];
     int status;
}eActor;


#endif // ACTORES_H_INCLUDED

#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

void initActores(eActor lista[], int len);
void harcodearActores(eActor lista[]);

void printActores(eActor lista[], int len);
void printOneActor(eActor unActor);
