//////////////////////////////////////////////////////
//                  EJERCICIO #4                    //
//////////////////////////////////////////////////////

/* Para el ejercicio se utilizo el archivo test3.txt
   se realizaron las limitaciones, tambien se tomo en
   cuenta que el vocablo encontrado puede tener nume_
   ros, palabras o caracteres especiales al mismo tiem_
   po.
*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    FILE *file = fopen( "test3.txt", "r" );
    char character;
    bool number = 0, word = 0, special = 0, unknown = 0;
    while(( character = fgetc( file )) != EOF ) {
        printf( "%c \n", character );
        if( character == ' ' || character == '\t' || character == '\n' )
            break;

        if( character >= 48 && character <= 57 ) {
            number = 1;
        } else if( character >= 97 && character <= 122 ) {
            word = 1;
        } else if( character >= 65 && character <= 90 ) {
            word = 1;
        } else if( character == '+' || character == '-' || character == '/' || character == '*' ) {
            special = 1;
        } else {
            unknown = 1;
        }
    }

    printf("El archivo contiene un/una ");

    if( number )
        printf("numero ");
    if( word )
        printf("palabra ");
    if( special )
        printf("caracter especial ");
    if( unknown )
        printf("caracter desconocido ");

    printf("\n");
    return 0;
}
