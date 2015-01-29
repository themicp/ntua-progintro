#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, *A, *B, i, j;
bool failed = false;

int cmp( const void * a, const void * b ) {
      return ( *( int* )a - *( int* )b );
}

int main() {
    scanf( "%i", &N );

    A = ( int* )malloc( N * sizeof( int ) );
    B = ( int* )malloc( N * sizeof( int ) );

    for ( i = 0; i < N; ++i ) {
        scanf( "%i", &A[ i ] );
    }
    for ( i = 0; i < N; ++i ) {
        scanf( "%i", &B[ i ] );
    }

    qsort( A, N, sizeof( int ), cmp );
    qsort( B, N, sizeof( int ), cmp );

    for ( i = 0; i < N; ++i ) {
        if ( A[ i ] != B[ i ] ) {
            failed = true;
            printf( "no %i", min( A[ i ], B[ i ] ) );

            j = N - 1;
            while ( A[ j ] == B[ j ] ) {
                --j;
            }
            printf( " %i\n", max( A[ j ], B[ j ] ) );
            break;
        }
    }
    if ( ! failed ) {
        printf( "yes\n" );
    }
    return 0;
}
