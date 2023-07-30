#include <stdio.h>

int main() {
    int k;
    printf( "Digite el numero: " );
    scanf( "%d", &k );

    int n = 0, res = 0;
    for (int i = 1; i <= k/2; i++) {
        n += 2 * i;

        while (n != 0) {
            res += n % 2;
            n /= 2;
        }
    }

    printf( "%d\n", res );

    return 0;
}
