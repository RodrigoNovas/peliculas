#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validations.h"

void getString(char text[], char input[])
{
    printf("%s", text);
    setbuf(stdin, NULL);
    scanf("%s", input);
}

int getInt(char mensaje[], int *input)
{
    char ingreso[50];
    int retorno = 0;
    int flag = 1;
    int aux = 0;
    int i;

    printf(mensaje);
    scanf("%s", ingreso);

    for(i=0; i<=strlen(ingreso); i++)
    {
        if(ingreso[i] == '.')
        {
            flag = 0;
            break;
        }
    }

    aux = atoi(ingreso);

    if(aux > 0 && flag == 1)
    {
        *input = aux;
        retorno = 1;
    }

    return retorno;
}


int itsOnlyIntNumbers(char str[])
{
   int i = 0;
   int itsInt = 1;

   while(str[i] != '\0')
   {
        if (str[i] < '0' || str[i] > '9')
        {
            itsInt = 0;
            break;
        }
       i++;
   }
   return itsInt;
}

int itsOnlyLetters(char str[])
{
   int i = 0;
   int itsLetters = 1;

   while(str[i] != '\0')
   {
        if((str[i] != ' ') && (str[i] < 'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            itsLetters = 0;
            break;
        }
        i++;
   }
   return itsLetters;
}

int itsAlphanumeric(char str[])
{
   int i=0;
   int itsAlphanum = 1;

   while(str[i] != '\0')
   {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            itsAlphanum = 0;
            break;
        }
       i++;
   }
   return itsAlphanum;
}

int getStringIntNumbers(char text[], char input[])
{
    char aux[256];
    int flag = 0;

    getString(text, aux);
    if(itsOnlyIntNumbers(aux))
    {
        strcpy(input, aux);
        flag = 1;
    }

    return flag;
}

int getStringLetters(char text[], char input[])
{
     char aux[256];
     int flag = 0;

     getString(text, aux);
     if(itsOnlyLetters(aux))
     {
        strcpy(input, aux);
        flag = 1;
     }
    return flag;
}

int getIntValidated(char text[], char input[])
{
    int intValidated;

    while(1)
    {
        if (getStringIntNumbers(text, input) == 0)
        {
            printf("\nSolo debe ingresar numeros enteros\n");
            continue;
        }
        setbuf(stdin, NULL);
        intValidated = atoi(input);

        return intValidated;
    }
}

void getStringValidated(char text[], char input[])
{
    while(1)
    {
        if (getStringLetters(text, input) == 0)
        {
            printf("\nSolo debe ingresar letras\n");
            continue;
        }
        setbuf(stdin, NULL);
        break;
    }
}
