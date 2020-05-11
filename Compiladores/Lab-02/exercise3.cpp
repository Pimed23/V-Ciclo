///////////////////////////////////////////////////////////////
//                        EJERCICIO #3                       //
///////////////////////////////////////////////////////////////

/*
    Teniendo en cuenta el ejercicio 2, lo usaremos de plan_
    tilla para la solucion del ejercicio 3. Basta con cambiar
    el tamano de las matrices y cambiar unas cuantas condicio_
    nes y esta hecho.
*/


#include <iostream>
using namespace std;

bool checkTable( int table[ 6 ][ 4 ], string word ) {
    int state = 0, input = 0;
    string pEntrada;
    char character;
    enum Controller{ punto, menos, digito, FDC, other };
    Controller symbol;

    for( int i = 0; i < word.size() + 1; ++i ) {
        cout << "CARACTER " << word[ i ] << endl;
        character = tolower( word[ i ]);

        if( character == '.' )       
            symbol = punto;
        else if( character == '-' )
            symbol = menos;
        else if( character >= 48 && character <= 57 )
            symbol = digito;
        else if( character == *( word.end()))
            symbol = FDC;
        else
            symbol = other;
        
        switch( symbol ) {
            case punto:
                input = 0;
                pEntrada = "Punto";
                break;
            case menos:
                input = 1;
                pEntrada = "Menos";
                break;
            case digito:
                input = 2;
                pEntrada = "Digito";
                break;
            case FDC:
                input = 3;
                pEntrada = "FDC";
                break;
            case other:
                input = 4;
                pEntrada = "Other";
                break;
            default:
                break;
        }
        cout << "Estado = " << state + 1 << endl;
        cout << "Entrada = " << pEntrada << endl;
        state = table[ state ][ input ];

        if( state == 6 || input == 4 )
            return false;
        else if( state == 7 )
            return true;
        cout << endl;
    }
    return false;
}

int main() {
    string tableBase[ 6 ][ 4 ];
    string word;

    int tableTrans[ 6 ][ 4 ];
    int num;

    char control = 'Y';

    // Llenar la tabla:
    tableBase[ 0 ][ 0 ] = "3";
    tableBase[ 0 ][ 1 ] = "2";
    tableBase[ 0 ][ 2 ] = "4";
    tableBase[ 0 ][ 3 ] = "error";
    tableBase[ 1 ][ 0 ] = "3";
    tableBase[ 1 ][ 1 ] = "error";
    tableBase[ 1 ][ 2 ] = "4";
    tableBase[ 1 ][ 3 ] = "error";
    tableBase[ 2 ][ 0 ] = "error";
    tableBase[ 2 ][ 1 ] = "error";
    tableBase[ 2 ][ 2 ] = "5";
    tableBase[ 2 ][ 3 ] = "error";
    tableBase[ 3 ][ 0 ] = "3";
    tableBase[ 3 ][ 1 ] = "error";
    tableBase[ 3 ][ 2 ] = "4";
    tableBase[ 3 ][ 3 ] = "aceptar";
    tableBase[ 4 ][ 0 ] = "error";
    tableBase[ 4 ][ 1 ] = "error";
    tableBase[ 4 ][ 2 ] = "5";
    tableBase[ 4 ][ 3 ] = "aceptar";
    tableBase[ 5 ][ 0 ] = "error";
    tableBase[ 5 ][ 1 ] = "error";
    tableBase[ 5 ][ 2 ] = "error";
    tableBase[ 5 ][ 3 ] = "error";

    // Imprimir la tabla:
    cout << "TABLA DE TRANSICIONES" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "   |   Punto    |     Menos     |    Digito     |      FDC      |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for( int i = 0; i < 6; ++i ) {
        cout << i + 1 << "  |\t" << "  ";
        for( int j = 0; j < 4; ++j )
            cout << tableBase[ i ][ j ] << "\t|\t";
        cout << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
    cout << endl;

    for( int i = 0; i < 6; ++i ) {
        for( int j = 0; j < 4; ++j ) {
            if( tableBase[ i ][ j ] == "error" ) {
                num = 6;
            } else if( tableBase[ i ][ j ] == "aceptar" ) {
                num = 7;
            } else
                num = stoi( tableBase[ i ][ j ]) - 1;
            tableTrans[ i ][ j ] = num;
        }
    }

    // Imprimir la tabla:
    cout << "\nTABLA DE TRANSICIONES" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    cout << "   |   Punto    |     Menos     |    Digito     |      FDC      |" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for( int i = 0; i < 6; ++i ) {
        cout << i << "  |\t" << "  ";
        for( int j = 0; j < 4; ++j )
            cout << tableTrans[ i ][ j ] << "\t|\t";
        cout << endl;
    }
    cout << "-----------------------------------------------------------------" << endl;
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