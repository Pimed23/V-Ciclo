//////////////////////////////////////////////////////
//                  EJERCICIO #2                    //
//////////////////////////////////////////////////////

/*  Para este ejercicio utilizaremos un archivo de
    texto plano llamado test1.txt el cual sera in_ 
    cluido junto al archivo cpp.
*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    FILE *file = fopen( "test1.txt", "r" );
    char character;
    while(( character = fgetc( file )) != EOF )
        printf("%c \n", character );
    return 0;
}