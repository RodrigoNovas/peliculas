#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"

#define LEN 5
int main()
{

    ePelicula listPeliculas[LEN];
    eActor listActores[LEN];

    initPelicula(listPeliculas, LEN);
    harcodearActores(listActores);


    char option;

    do
    {
        printf("\n _____________________________\n|                             |\n|            MENU             |\n|                             |\n|    1. ALTA                  |\n|    2. BAJA                  |\n|    3. MODIFICACION          |\n|    4. MOSTRAR               |\n|    5. SALIR                 |\n|                             |\n|_____________________________|\n\n");
        getIntValidated("\nIntroduzca una opcion: ", &option);

        switch(option)
        {
            case '1':
                system("cls");
                addPelicula(listPeliculas, LEN);
                break;

            case '2':
                //printPeliculas(listPeliculas, LEN);
                //removePelicula(listPeliculas, LEN, 0);
                break;

            case '3':
                //printPeliculas(listPeliculas, LEN);
                //findPeliculaById(listPeliculas, LEN, 0);
                //modifyPelicula(listPeliculas, LEN, 0);
                break;

            case '4':
                system("cls");
                printPeliculas(listPeliculas, LEN);
                break;

            case '5':
                option = '5';
                break;

            default:
                printf("\n\nOpcion inexistente. Ingresar entre 1 y 5\n");
                break;
          }
    }while(option != '5' );

    return 0;
}
