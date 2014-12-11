#include <cstdio>
#include <string>

using namespace std;

char character;
string candidate;
int N, i, j, countValid = 0;

bool isPalindrome( string text ) {
    int i = 0, j = text.length() - 1;
    while ( i <= j ) {
        if ( text[ i ] != text[ j ] ) {
            return false;
        }
        ++i;
        --j;
    }

    return true;
}

void skipText() {
    string skipped = "";
    char c;

    while ( c != '\n' ) {
        scanf( "%c", &c );
    }
}

int main() {
    scanf( "%i\n", &N );

    for ( i = 0; i < N; ++i ) {
        candidate = "";
        for ( j = 0; j <= 20; ++j ) {
            scanf( "%c", &character );
            if ( character == '\n' ) {
                break;
            }
            candidate.append( &character );
        }
        if ( character != '\n' && j == 21 ) {
            printf( "error\n" );
            skipText();
        }
        else {
            if ( j == 0 && character == '\n' ) {
                printf( "empty\n" );
            }
            else {
                if ( isPalindrome( candidate ) ) {
                    printf( "yes\n" );
                    ++countValid;
                }
                else {
                    printf( "no\n" );
                }
            }
        }
    }
    printf( "%.3f\n", 100 * (double)countValid/(double)N );

    return 0;
}
