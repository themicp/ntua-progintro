#include <cstdio>
#include <cstring>

using namespace std;

#define max_lines 1000000

char s[ 25 ], c;
char line[ max_lines ][ 65 ];
int wordCount[ max_lines ];
int counter, i, j, k, lineLength, whitespaces, extraWhitespace, leftWhitespace, passedWords, lineLimit = 60;

int main() {
    for ( i = 0; i < max_lines; ++i ) {
        wordCount[ i ] = 0;
    }
    i = 0;
    while( scanf( "%s", s ) != EOF ) {
        lineLength = strlen( line[ i ] );
        if ( lineLength + strlen( s ) + 1 > lineLimit ) { //Can't fit the word
            whitespaces = 0;
            extraWhitespace = 0;
            leftWhitespace = 0;
            if ( lineLimit - lineLength > 0 ) {
                whitespaces = lineLimit - lineLength;
                extraWhitespace = whitespaces / ( wordCount[ i ] - 1 );
                leftWhitespace = whitespaces - extraWhitespace * ( wordCount[ i ] - 1 );
            }

            passedWords = 0;
            for ( j = 0; j < lineLength; ++j ) {
                if ( line[ i ][ j ] != ' ' ) {
                    printf( "%c", line[ i ][ j ] );
                } else {
                    printf( "%c", line[ i ][ j ] );
                    for ( k = 0; k < extraWhitespace; ++k ) {
                        printf( " " );
                    }
                    if ( ( wordCount[ i ] - 1 ) - passedWords <= leftWhitespace ) {
                        printf( " " );
                    }
                    ++passedWords;
                }
            }
            printf( "\n" );
            ++i;
        }

        //Append the word
        if ( strlen( line[ i ] ) > 0 ) {
            strcat( line[ i ], " " );
        }
        strcat( line[ i ], s );
        ++wordCount[ i ];
    }

    printf( "%s\n", line[ i ] );
    return 0;
}
