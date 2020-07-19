///////////////////////////////////////////////////////////////////////
///     Realizado por: Pinto Medina, Brian                          ///
///     GitHub:                                                     ///
///////////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

vector<vector<int>> acumulado( vector<vector<int>> );
vector<vector<int>> maxSumSubArray2D( vector<vector<int>> );
void printMatrix( vector<vector<int>> );
void printResult( vector<vector<int>>, vector<vector<int>> );


int main() {
    int tam, temp;
    cin >> tam;

    vector<vector<int>> matrix;
    
    for( int i = 0; i < tam; ++i ) {
        vector<int> tempVec;
        for( int j = 0; j < tam; ++j ) {
            cin >> temp;
            tempVec.push_back( temp );
        }
        matrix.push_back(tempVec);
    }
    
    vector<vector<int>> result = maxSumSubArray2D( matrix );
    printResult(matrix, result);

    return 0;    
}

vector<vector<int>> maxSumSubArray2D( vector<vector<int>> matrix ) {
    vector<vector<int>> result;

    vector<vector<int>> processed = acumulado( matrix );
    int maxSum = INT_MIN;
    int sum;

    for( int fInf = 0; fInf < processed.size(); ++fInf ) {
        for( int fSup = fInf; fSup < processed.size(); ++fSup ) {
            for( int cInf = 0; cInf < processed[0].size(); ++cInf ) {
                for( int cSup = cInf; cSup < processed[0].size(); ++cSup ) {
                    if( fInf == 0 && cInf == 0 ) 
                        sum = processed[fSup][cSup];
    
                    else if (fInf == 0)
                        sum = processed[fSup][cSup] - processed[fSup][cInf - 1];

                    else if (cInf == 0)
                        sum = processed[fSup][cSup] - processed[fInf - 1][cSup];

                    else 
                        sum = processed[fSup][cSup] - processed[fInf - 1][cSup] - processed[fSup][cInf - 1] + processed[fInf - 1][cInf - 1];
                    
                    if( sum > maxSum ) {
                        vector<int> subMatrix = { fInf, cInf, fSup, cSup, sum };
                        maxSum = sum;
                        result.clear();
                        result.push_back( subMatrix );
                    } else if (sum == maxSum) {
                        vector<int> subMatrix = { fInf, cInf, fSup, cSup, sum };
                        result.push_back( subMatrix );
                    }
                }
            }
        }
    }
    return result;
}

vector<vector<int>> acumulado( vector<vector<int>> matrix ) {
    vector<vector<int>> processed(matrix.size(), vector<int>( matrix[0].size()));
    processed[0][0] = matrix[0][0];
    for( size_t i = 1; i < matrix.size(); ++i )
        processed[i][0] = processed[i - 1][0] + matrix[i][0];
    
    for( size_t i = 1; i < matrix.size(); ++i )
        processed[0][i] = processed[0][i - 1] + matrix[0][i];

    for( size_t i = 1; i < matrix.size(); ++i )
        for( size_t j = 1; j < matrix[0].size(); ++j )
            processed[i][j] = processed[i - 1][j] + processed[i][j - 1] - processed[i - 1][j - 1] + matrix[i][j];
    return processed;
}

void printMatrix( vector<vector<int>> matrix ) {
    for( size_t i = 0; i < matrix.size(); ++i ) {
        for( size_t j = 0; j < matrix[0].size(); ++j ) {
            cout.width(5);
            cout.fill(' ');
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printResult( vector<vector<int>> matrix, vector<vector<int>> result ) {
    int fInf, fSup, cInf, cSup;
    for( size_t i = 0; i < result.size(); ++i ) {
        cInf = result[i][0];
        cSup = result[i][2];
        fInf = result[i][1];
        fSup = result[i][3];
        
        for( size_t j = cInf; j <= cSup; ++j ) {
            for( size_t k = fInf; k <= fSup; ++k ) {
                cout.width(5);
                cout.fill(' ');
                cout << matrix[j][k] << "\t";
            }
            cout << endl;
        }
        cout << "Sumando " << result[i][4] << "\n";
    }
}