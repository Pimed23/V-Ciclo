///////////////////////////////////////////////////////////////////////////
////                                                   		       ////
////    Codigo realizado por: Brian Wilbert Pinto Medina               ////
////    GitHub: https://github.com/Pimed23/V-Ciclo/tree/master/ADA     ////
////                                                   		       ////
///////////////////////////////////////////////////////////////////////////

#include <stdio.h>
using namespace std;

int sumaMax( int arr[], int size, int& indI, int& indF ) {
    int maxsum = 0;
    int suma = 0;
    int i = 0, f = 0;

    while( f < size ) {
        suma = suma + arr[ f ];
        f = f + 1;

        if( suma < 0 ) {
            suma = 0;
            i = f + 1;
        } else {
            if( suma >= maxsum ) {
                maxsum = suma;
                indI = i;
                indF = f + 1;
            }
        }
    }

    return maxsum;
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
        sum = sumaMax( R, C - 1, indI, indF );

        if( sum > 0 )
            printf("La mejor parte de la ruta %i es entre las calles %i y %i\n", i + 1, indI, indF );
        else
            printf("La ruta %i no tiene calles interesantes\n", i + 1 );
    }


    return 0;
}
