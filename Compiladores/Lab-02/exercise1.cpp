///////////////////////////////////////////////////////////////
//                        EJERCICIO #1                       //
///////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

bool checkDiagram( string word ) {
    int state = 1;
    for( int i = 0; i < word.size(); ++i ) {
        char symbol = tolower( word[ i ]);
        switch( state ) {
            case 1:
                if( symbol >= 48 && symbol <= 57 )                  
                    state = 2;
                else if( symbol >= 97 && symbol <= 122 )            
                    state = 3;
                else                                                
                    state = 2;
            case 2:
                break;
            case 3:
                if( symbol >= 97 && symbol <= 122 )                 
                    state = 3;
                else if( symbol >= 48 && symbol <= 57 )         
                    state = 3;
                else
                    state = 2;
            default:
                break;
        }
    }

    if( state != 3 )
        return false;
    else
        return true;
}

int main() {
    string word;
    printf( "Ingrese la cadena a ser evaluada:\n" );
    cin >> word;
    if( checkDiagram( word ))
        printf( "La cadena es reconocida por el automata.\n" );
    else
        printf( "La cadena NO es reconocida por el automata.\n" );
    return 0;
}