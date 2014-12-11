#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M, **A, i, j, *minRow, *maxCol, maxRowTotal, minColTotal;

int main() {
    scanf( "%i %i", &N, &M );
    A = ( int** )malloc( N * sizeof( int* ) );
    maxCol = ( int* )malloc( M * sizeof( int ) );
    minRow = ( int* )malloc( N * sizeof( int ) );
    for ( i = 0; i < N; ++i ) {
        A[ i ] = ( int* )malloc( M * sizeof( int ) );
    }

    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < M; ++j ) {
            scanf( "%i", &A[ i ][ j ] );
            minRow[ i ] = j == 0 ? A[ i ][ j ] : min( minRow[ i ], A[ i ][ j ] );
            maxCol[ j ] = i == 0 ? A[ i ][ j ] : max( maxCol[ j ], A[ i ][ j ] );
        }
    }
    
    for ( i = 0; i < M; ++i ) {
        minColTotal = i == 0 ? maxCol[ i ] : min( minColTotal, maxCol[ i ] );
    }
    for ( i = 0; i < N; ++i ) {
        maxRowTotal = i == 0 ? minRow[ i ] : max( maxRowTotal, minRow[ i ] );
    }
    printf( "%i\n%i\n", minColTotal, maxRowTotal );

    return 0;
}
