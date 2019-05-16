#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "peliculas.h"

//INICIALIZAR **********************************************
void initPelicula(ePelicula lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        strcpy(lista[i].codigo, " ");
        strcpy(lista[i].titulo, " ");
        strcpy(lista[i].fechaDeEstreno, " ");
        strcpy(lista[i].genero, " ");
        strcpy(lista[i].actorPrincipal, " ");
        lista[i].id = 0;
        lista[i].status = LIBRE;
    }
}


//ALTA ****************************************************
int buscarEspacioLibre(ePelicula lista[], int len)
{
    int i;
    int index = -1;

    for(i=0; i<len; i++)
    {
        if(lista[i].status == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

ePelicula getPelicula()
{
    ePelicula PeliculaToReturn;
    char option;

        getIntValidated("\nIngrese el codigo de la pelicula: ", PeliculaToReturn.codigo);
        getStringValidated("\nIngrese el titulo de la pelicula: ", PeliculaToReturn.titulo);
        getStringValidated("\nIngrese la fecha de estreno de la pelicula: ", PeliculaToReturn.fechaDeEstreno);

        printf("\nGENEROS\n\n1.ACCION\n2.COMEDIA\n3.TERROR\n4.OTRO\n");
        getIntValidated("\nIntroduzca una opcion: ", &option);

        switch(option)
        {
            case '1':
                strcpy(PeliculaToReturn.genero, "Accion");
                break;
            case '2':
                strcpy(PeliculaToReturn.genero, "Comedia");
                break;
            case '3':
                strcpy(PeliculaToReturn.genero, "Terror");
                break;
            case '4':
                strcpy(PeliculaToReturn.genero, "0tro");
                break;
            default:
                printf("\n\nOpcion inexistente. Ingresar entre 1 y 4\n");
                break;
        }

        getStringValidated("\nIngrese el actor principal de la pelicula: ", PeliculaToReturn.actorPrincipal);

        PeliculaToReturn.status = OCUPADO;

        return PeliculaToReturn;
}

int addPelicula(ePelicula lista[], int len)
{
    int itsLoaded;
    int index;

    if(index < 0)
    {
        itsLoaded = -1;
    }

    index = buscarEspacioLibre(lista, len);
    if(index != -1)
    {
        lista[index] = getPelicula();
        for(index=0; index<len; index++)
        {
            lista[index].id =  index + 1;
        }
    }
    else
    {
        printf("No hay espacio.");
    }
    return itsLoaded;
}


//MOSTRAR **************************************************
void printPeliculas(ePelicula lista[], int len)
{
    int i;
    printf("ID\t  CODIGO\t TITULO  \tESTRENO  \tGENERO\tACTOR PRINCIPAL\n");
    printf("___________________________________________________________________________\n");

    for(i=0; i<len; i++)
    {
        if(lista[i].status != LIBRE)
        {
            printOnePelicula(lista[i]);
        }
    }

}
void printOnePelicula(ePelicula onePelicula)
{
    printf("\n%d\t%s\t\%s\t\t%s\t\t%s\t %s\n\n", onePelicula.id, onePelicula.codigo, onePelicula.titulo, onePelicula.fechaDeEstreno, onePelicula.genero, onePelicula.actorPrincipal);
    printf("--------------------------------------------------------------------------\n");
}


void printPeliculaConActores(ePelicula listaPelicula[] , int lenPeli, eActor listaActores[], int lenAct)
{
    int i;
    int j;
    for(i=0; i<lenPeli; i++)
    {
        if(listaPelicula[i].status != LIBRE)
        {
            printOnePelicula(listaPelicula[i]);

            for(j=0; j<lenAct; j++)
            {
                if( listaPelicula[i].id == listaActores[j].id && listaActores[j].status != LIBRE)
                {
                    printOneActor(listaActores[j]);
                }
            }
        }
    }
}
