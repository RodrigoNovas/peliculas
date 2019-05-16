#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
     int id;
     char codigo[3];
     char titulo[51];
     char fechaDeEstreno[51];
     char genero[51];
     char actorPrincipal[51];
     int status;
     int idActor;
}ePelicula;

#include "actores.h"
#endif // PELICULAS_H_INCLUDED

#include "validations.h"
#include "actores.h"

#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

//Alta
ePelicula getPelicula();
int addPelicula(ePelicula[], int);
int buscarEspacioLibre(ePelicula[], int);
void initPelicula(ePelicula[], int);
void harcodearPelicula(ePelicula[], int);

//Mostrar
void printPeliculas(ePelicula[], int);
void printOnePelicula(ePelicula onePelicula);
void printPeliculaConActores(ePelicula[], int, eActor[], int);
