#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M, i, j;
float avgRowTotal = 0, avgColTotal = 0;
float **A, *avgCol, *avgRow;

int main() {
    scanf( "%i %i", &N, &M );
    A = ( float** )malloc( N * sizeof( float* ) );
    avgCol = ( float* )malloc( M * sizeof( float ) );
    avgRow = ( float* )malloc( N * sizeof( float ) );
    for ( i = 0; i < N; ++i ) {
        A[ i ] = ( float* )malloc( M * sizeof( float ) );
        avgRow[ i ] = 0;
    }
    for ( i = 0; i < M; ++i ) {
        avgCol[ i ] = 0;
    }

    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < M; ++j ) {
            scanf( "%f", &A[ i ][ j ] );
            avgRow[ i ] += A[ i ][ j ]/M;
            avgCol[ j ] += A[ i ][ j ]/N;
        }
    }
    
    for ( i = 0; i < M; ++i ) {
        avgColTotal += avgCol[ i ]/M;
    }
    for ( i = 0; i < N; ++i ) {
        avgRowTotal += avgRow[ i ]/N;
    }
    printf( "%.3f\n%.3f\n", avgColTotal, avgRowTotal );

    return 0;
}
