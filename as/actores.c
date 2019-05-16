#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "actores.h"

void initActores(eActor lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].id = 0;
        lista[i].status = LIBRE;
    }
}

void harcodearActores(eActor lista[])
{
    int i;
    int len = 5;
    int id[] = {1,2,3,4,5};
    char nombre[][50]= {"Julieta Roberto","Roberto Deniro","Richar Darin","Tita Merelo","Sandro"};
    char paisDeOrigen[][50]= {"EEUU","EEUU","Argentina","Argentina","Argentina"};


    for(i=0; i<len; i++)
    {
        lista[i].id = i + 1;
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].paisDeOrigen, paisDeOrigen[i]);
        lista[i].status = OCUPADO;
    }
}

void printActores(eActor lista[], int len)
{
    int i;
    printf("------------------------------\n");
    for(i=0; i<len; i++)
    {
        if(lista[i].status != LIBRE)
        {
            printOneActor(lista[i]);
        }
    }
    printf("------------------------------\n");
}
void printOneActor(eActor unActor)
{
    printf("\t%d %10s %10s\n\n", unActor.id, unActor.nombre, unActor.paisDeOrigen);
}
