#include <stdbool.h>
#include <stdio.h>

/*
====================
canPlaceFlowers

  Verifica se é possível plantar 'n' flores em um canteiro sem 
  violar a regra de não ter flores adjacentes.
====================
*/
bool canPlaceFlowers( int *flowerbed, int flowerbedSize, int n ) {
    int flowersPlaced = 0;
    int *end = flowerbed + flowerbedSize;

    for ( int *current = flowerbed; current < end; current++ ) {
        if ( *current == 0 ) {
            bool emptyBefore = ( current == flowerbed ) || *( current - 1 ) == 0;
            bool emptyAfter = ( current == end - 1 ) || *( current + 1 ) == 0;

            if ( emptyBefore && emptyAfter ) {
                *current = 1;
                flowersPlaced++;
                current++; // Salta o próximo elemento
            }
        }

        if ( flowersPlaced >= n ) {
            return true;
        }
    }

    return flowersPlaced >= n;
}

/*
====================
main

  Função principal para testar o comportamento de canPlaceFlowers.
====================
*/
int main( void ) {
    int flowerBed[5] = { 0, 0, 1, 0, 0 };
    int flowerBedSize = sizeof( flowerBed ) / sizeof( flowerBed[0] );
    int n = 1;

    bool result = canPlaceFlowers( &flowerBed[0], flowerBedSize, n );
    printf( result ? "True" : "False" );

    return 0;
}
