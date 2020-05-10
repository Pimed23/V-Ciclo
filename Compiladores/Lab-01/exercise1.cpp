//////////////////////////////////////////////////////
//                  EJERCICIO #1                    //
//////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main() {
    string chain;
    cout << "Ingrese una cadena:\n";
    getline( std::cin, chain );
    
    for( int i = 0; i < chain.size(); ++i )
        cout << chain[ i ] << endl;
    return 0;
}