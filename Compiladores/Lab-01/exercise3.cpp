//////////////////////////////////////////////////////
//                  EJERCICIO #3                    //
//////////////////////////////////////////////////////

/* Para este ejercicio se crearon dos funciones el usua_
   debera ingresar el nombre del archivo que desea en_
   criptar y el desplazamiento deseado para la encryp_
   tacion de Cesar.
   El programa creara dos archivos uno con el texto 
   encriptado y uno con el texto desencriptado, los ar_
   chivos creados es llaman "Encrypth.txt" y
   "Decrypth.txt".
*/

#include <stdio.h>
#include <stdlib.h>
using namespace std;

void encryptionCesar( char *fname, int offset ) {
    FILE *fileRead, *fileWritten;
    fileRead = fopen( fname, "r" );
    fileWritten = fopen( "Encrypth.txt", "wt");
    char character;
    
    while(( character = fgetc( fileRead )) != EOF ) {
        character = character + offset;
        fputc( character, fileWritten );
    }
    fclose( fileRead );
    fclose( fileWritten );
}

void decryptionCesar( char *fname, int offset ) {
    FILE *fileRead, *fileWritten;
    fileRead = fopen( fname, "r" );
    fileWritten = fopen( "Decrypth.txt", "wt");
    char character;
    
    while(( character = fgetc( fileRead )) != EOF ) {
        character = character - offset;
        fputc( character, fileWritten );
    }
    fclose( fileRead );
    fclose( fileWritten );
}

int main() {
    int offset;
    char fname[ 30 ];
    char fencrypthed[] = "Encrypth.txt";
    
    printf( "Ingrese el nombre del archivo a codificar:\n" );
    scanf( "%30[^\n]", fname );
    printf( "Ingrese el desplazamiento deseado:\n" );
    scanf( "%i", &offset );
    encryptionCesar( fname, offset );
    decryptionCesar( fencrypthed, offset );

    return 0;
}