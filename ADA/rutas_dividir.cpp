///////////////////////////////////////////////////////////////////////////
////                                                   		           ////
////    Codigo realizado por: Brian Wilbert Pinto Medina               ////
////    GitHub: https://github.com/Pimed23/V-Ciclo/tree/master/ADA     ////
////                                                   		           ////
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <algorithm>
using namespace std;

int sumaMaxDiv( int arr[], int inicio, int final, int& indI, int& indF ) {

    if( inicio == final )
        return max( 0, arr[inicio]);

    int mitad = ( inicio + final ) / 2;

    int maxizq = sumaMaxDiv( arr, inicio, mitad, indI, indF );
    int maxder = sumaMaxDiv( arr, mitad + 1, final, indI, indF );

    int max2izq = arr[ mitad ];
    int suma = arr[ mitad ];
    indI = 1;
    
    for( int i = mitad - 1; i >= inicio; --i ) {
        suma += arr[ i ];
        if( suma >= max2izq ) {
            max2izq = suma;
            indI = i;
        }
    }

    int max2der = arr[ mitad + 1 ];
    suma = arr[ mitad + 1 ];
    indF = mitad + 1;

    for( int i = mitad + 2; i <= final; ++i ) {
        suma += arr[ i ];
        if( suma >= max2der ) {
            max2der = suma;
            indF = i;
        }
    }

    int maxcruz = max2izq + max2der;
    int maximo = max( maxizq, maxder );
    return max( maximo, maxcruz );    
}


int main() {
    int n_rutas, sum;
    int indI = 0, indF = 0;
    scanf("%i", &n_rutas);

    for( int i = 0; i < n_rutas; ++i ) {
        int C;
        scanf("%i", &C);
        int R[ C - 1 ];

        for( int j = 0; j < C - 1; ++j )
            scanf("%i", &R[ j ]);

        sum = sumaMaxDiv( R, 0, C - 2, indI, indF );

        if( sum > 0 )
            printf("La mejor parte de la ruta %i es entre las calles %i y %i\n", i + 1, indI + 1, indF + 2 );
        else
            printf("La ruta %i no tiene calles interesantes\n", i + 1 );
    }

    return 0;
}
