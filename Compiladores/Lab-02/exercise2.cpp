///////////////////////////////////////////////////////////////
//                        EJERCICIO #2                       //
///////////////////////////////////////////////////////////////

/*
    Para este ejercicio lo primero que se procede a 
    hacer es crear una matriz para que actue como nues_
    tra tabla de transiciones; una vez hecho esto se
    procedera a convertir la tabla a una tabla de ente_
    ros ya que de esta manera sera mas facil trabajar.
    
    La tabla se convirtio de la siguiente manera:
    - Los numeros simplemente se transformaron de string
      a int.
    - A los valores "error" y "aceptar" se le dio el va_
      lor de 3 y 4 respectivamente, ya que esos valores
      son ajenos al contenido de nuestra tabla y podria
      evitar errores futuros.
    
    Una vez hecho esto simplemente se realiza el algorit_
    mo propuesto en pseudocodigo.
*/

#include <iostream>
using namespace std;

bool checkTable( int table[ 3 ][ 3 ], string word ) {
    int state = 0, input = 0;
    string pEntrada;
    char character;
    enum Controller{ digito, letra, FDC, other };
    Controller symbol;

    for( int i = 0; i < word.size() + 1; ++i ) {
        cout << "CARACTER " << word[ i ] << endl;
        character = tolower( word[ i ]);

        if( character >= 48 && character <= 57 )       
            symbol = digito;
        else if( character >= 97 && character <= 122 )          
            symbol = letra;
        else if( character == *( word.end()))
            symbol = FDC;
        else
            symbol = other;
        
        switch( symbol ) {
            case digito:
                input = 0;
                pEntrada = "Digito";
                break;
            case letra:
                input = 1;
                pEntrada = "Letra";
                break;
            case FDC:
                input = 2;
                pEntrada = "FDC";
                break;
            case other:
                input = 3;
                pEntrada = "Other";
                break;
            default:
                break;
        }
        cout << "Estado = " << state + 1 << endl;
        cout << "Entrada = " << pEntrada << endl;
        state = table[ state ][ input ];

        if( state == 3 || input == 3 )
            return false;
        else if( state == 4 )
            return true;
        cout << endl;
    }
    return false;
}

int main() {
    string tableBase[ 3 ][ 3 ];
    string word;

    int tableTrans[ 3 ][ 3 ];
    int num;

    char control = 'Y';

    // Llenar la tabla:
    tableBase[ 0 ][ 0 ] = "2";
    tableBase[ 0 ][ 1 ] = "3";
    tableBase[ 0 ][ 2 ] = "error";
    tableBase[ 1 ][ 0 ] = "error";
    tableBase[ 1 ][ 1 ] = "error";
    tableBase[ 1 ][ 2 ] = "error";
    tableBase[ 2 ][ 0 ] = "3";
    tableBase[ 2 ][ 1 ] = "3";
    tableBase[ 2 ][ 2 ] = "aceptar";

    // Imprimir la tabla:
    cout << "TABLA DE TRANSICIONES" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "   |   Digito   |     Letra     |      FDC      |" << endl;
    cout << "-------------------------------------------------" << endl;
    for( int i = 0; i < 3; ++i ) {
        cout << i + 1 << "  |\t" << "  ";
        for( int j = 0; j < 3; ++j )
            cout << tableBase[ i ][ j ] << "\t|\t";
        cout << endl;
    }
    cout << "-------------------------------------------------" << endl;
    cout << endl;

    for( int i = 0; i < 3; ++i ) {
        for( int j = 0; j < 3; ++j ) {
            if( tableBase[ i ][ j ] == "error" ) {
                num = 3;
            } else if( tableBase[ i ][ j ] == "aceptar" ) {
                num = 4;
            } else
                num = stoi( tableBase[ i ][ j ]) - 1;
            tableTrans[ i ][ j ] = num;
        }
    }

    // Imprimir la tabla:
    cout << "\nTABLA DE TRANSICIONES" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "   |   Digito   |     Letra     |      FDC      |" << endl;
    cout << "-------------------------------------------------" << endl;
    for( int i = 0; i < 3; ++i ) {
        cout << i << "  |\t" << "  ";
        for( int j = 0; j < 3; ++j )
            cout << tableTrans[ i ][ j ] << "\t|\t";
        cout << endl;
    }
    cout << "-------------------------------------------------" << endl;
    cout << endl;

    cout << "Ingrese la cadena a ser evaluada: " << endl;
    cin >> word;
    cout << endl;

    while( control == 'Y' ) {
        if( checkTable( tableTrans, word ))
            cout << "\nLa cadena es reconocida por el automata." << endl;
        else
            cout << "\nLa cadena NO es reconocida por el automata." << endl;
        
        cout << "Desea evaluar otra cadena Y/N..." << endl;
        cin >> control;
        
        while( control != 'Y' && control != 'N' ) {
            cout << "Opcion invalida..." << endl;
            cout << "Desea evaluar otra cadena Y/N..." << endl;
            cin >> control;
            if( control == 'Y' || control == 'N' )
                break;            
        }

        if( control == 'N' )
            break;

        cout << "\nIngrese la cadena a ser evaluada: " << endl;
        cin >> word;
        cout << endl;
    }

    return 0;
}