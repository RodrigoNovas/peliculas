#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

void getString(char[], char[]);
int getInt(char mensaje[], int *input);

int itsOnlyIntNumbers(char str[]);
int itsOnlyLetters(char[]);
int itsAlphanumeric(char str[]);

int getStringIntNumbers(char[], char[]);
int getStringLetters(char[], char[]);

int getIntValidated(char text[], char input[]);
void getStringValidated(char text[], char input[]);


#endif // VALIDATIONS_H_INCLUDED
