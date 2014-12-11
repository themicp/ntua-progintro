#include <cstdio>
#include <cmath>

int power, i, A[ 10 ], S[ 100000000 ];

int sumDigits( int x ) {
    S[ x ] = S[ x/10 ] + A[ x % 10 ];

    return S[ x ];
}

int main() {
    scanf( "%i", &power );

    for ( i = 0; i <= 9; ++i ) {
        A[ i ] = pow( i, power ); 
    }

    for ( i = 0; i < 99999999; ++i ) {
        if ( i == sumDigits( i ) ) {
            printf( "%i\n", i );
        }
    }

    return 0;
}
