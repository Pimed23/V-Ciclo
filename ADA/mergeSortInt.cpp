///////////////////////////////////////////////////////////
////                                                   ////
////    Codigo realizado por: Brian Pinto Medina       ////
////    GitHub: https://github.com/Pimed23/ADA.git     ////
////                                                   ////
///////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>

///////////////////////////////////////////////////////////
/////////////// DECLARACION DE SIMPLEARRAY ////////////////
///////////////////////////////////////////////////////////

class SimpleArray {
    public:
        SimpleArray();
        SimpleArray( const int );
        SimpleArray( const SimpleArray& ); 
        ~SimpleArray();

        void mergeSort();
        void mergeSortDes();
        void fillRandArray();
        void printArray();
        void quickSort();

    private:
        void intercala( int, int, int );
        void intercalaDes( int, int, int );
        void mergeSort( int, int );
        void mergeSortDes( int, int );

        int size;
        int *arr;
};

///////////////////////////////////////////////////////////
//////////////////// FUNCION PRINCIPAL ////////////////////
///////////////////////////////////////////////////////////

int main() {
    FILE *arch;
    arch = fopen( "timeSorting.txt", "wt" );
    
    int numElem;
    printf("Numero de elementos a ordenar: "); 
    scanf( "%i", &numElem );

    srand( time( NULL ));
    
    for( int i = 1; i < numElem + 1; ++i ) {
        unsigned int time0, time1;
        unsigned int timeMS0, timeMS1;
        unsigned int timeQS0, timeQS1;
        double timeCreation, timeMerge, timeQuick;
        int nElem = i;
        
        time0 = clock();
        SimpleArray A( nElem ); 
        A.fillRandArray();
        A.mergeSortDes();
        time1 = clock();
        timeCreation = double( time1 - time0 ) / CLOCKS_PER_SEC;
        
        SimpleArray B( A );                     
        SimpleArray C( A );                             
        
        timeMS0 = clock();
        B.mergeSort();
        timeMS1 = clock();
        timeMerge = double( timeMS1 - timeMS0 ) / CLOCKS_PER_SEC;
        
        timeQS0 = clock();
        C.quickSort();
        timeQS1 = clock();
        timeQuick = double( timeQS1 - timeQS0 ) / CLOCKS_PER_SEC;

        //printf("\nARRAY OF %i ELEMENTS\n", nElem );
        //printf("\nMERGE SORT\n");
        //printf("Ordering time: %lf\n", timeMerge );
        fprintf( arch, "%lf\t", timeMerge );
        //printf("\nQUICK SORT\n");
        //printf("Ordering time: %lf\n", timeQuick );
        fprintf( arch, "%lf\n", timeQuick );
    }
    
    fclose( arch );

}

///////////////////////////////////////////////////////////
//////////////// DEFINICION DE SIMPLE ARRAY ///////////////
///////////////////////////////////////////////////////////

// Default constructor //
SimpleArray::SimpleArray() {
    this -> size = 0;
    this -> arr = new int[ size ];
}

// Parametrized constructor //
SimpleArray::SimpleArray( const int nElem ) {
    this -> size = nElem;
    this -> arr = new int[ size ];
}

// Copy constructor //
SimpleArray::SimpleArray( const SimpleArray &other ) {
    this -> size = other.size;
    this -> arr = new int[ size ];

    for( int i = 0; i < size; ++i )     
        this -> arr[ i ] = other.arr[ i ];             
}

// Destructor //
SimpleArray::~SimpleArray() {
    delete[] arr; 
}

// fillRandArray //
void SimpleArray::fillRandArray() {
    for( int i = 0; i < size; ++i )
        arr[ i ] = rand() % 100 + 1; 
}

// printArray //
void SimpleArray::printArray() {
    for( int i = 0; i < size; ++i )
        printf( "%i ", arr[ i ]);
    printf("\n");
}

// Intercala //
void SimpleArray::intercala( int p, int q, int r ) {
    int B[ size ];
    int i, j, k;
    
    for( i = p; i <= q; ++i )
        B[ i ] = arr[ i ];
    
    for( j = q + 1; j <= r; ++j ) 
        B[ r + q + 1 - j ] = arr[ j ];
    
    i = p;
    j = r;
    
    for( k = p; k <= r; ++k ) {
        if( B[ i ] <= B[ j ]) {
            arr[ k ] = B[ i ];
            ++i;
        } else {
            arr[ k ] = B[ j ];
            --j;
        }
    }
}

// MergeSort //
void SimpleArray::mergeSort() {
    mergeSort( 0, size - 1 );
}

// MergeSort //
void SimpleArray::mergeSort( int left, int right ) {
    if( left < right ) {
        int mid = ( left + right ) / 2;

        mergeSort( left, mid );
        mergeSort( mid + 1, right );
        intercala( left, mid, right );
    }
}

// MergeSort //
void SimpleArray::mergeSortDes() {
    mergeSortDes( 0, size - 1 );
}

// MergeSort //
void SimpleArray::mergeSortDes( int left, int right ) {
    if( left < right ) {
        int mid = ( left + right ) / 2;

        mergeSortDes( left, mid );
        mergeSortDes( mid + 1, right );
        intercalaDes( left, mid, right );
    }
}

// Intercala //
void SimpleArray::intercalaDes( int p, int q, int r ) {
    int B[ size ];
    int i, j, k;
    
    for( i = p; i <= q; ++i )
        B[ i ] = arr[ i ];
    
    for( j = q + 1; j <= r; ++j ) 
        B[ r + q + 1 - j ] = arr[ j ];
    
    i = p;
    j = r;
    
    for( k = p; k <= r; ++k ) {
        if( B[ i ] >= B[ j ]) {
            arr[ k ] = B[ i ];
            ++i;
        } else {
            arr[ k ] = B[ j ];
            --j;
        }
    }
}


// QuickSort //
void SimpleArray::quickSort() {
    std::sort( arr, arr + size );
}
