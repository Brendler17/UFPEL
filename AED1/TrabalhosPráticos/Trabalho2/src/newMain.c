#include <stdio.h>
#include <stdlib.h>

/*
====================
Heap_t

  Estrutura para representar uma minHeap
====================
*/
typedef struct {
	int *elements;
	int size;
	int capacity;
} Heap_t;

/*
====================
SeatManager_t

  Estrutura para gerenciar assentos utilizando uma minHeap
====================
*/
typedef struct {
	Heap_t heap;
} SeatManager_t;

/*
====================
Swap

  Troca dois valores inteiros de posição
====================
*/
void Swap( int *a, int *b ) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
====================
MinHeapify

  Garante a propriedade da minHeap
====================
*/
void MinHeapify( Heap_t *heap, int index ) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if ( left < heap->size && heap->elements[left] < heap->elements[smallest] ) {
		smallest = left;
	}
	if ( right < heap->size && heap->elements[right] < heap->elements[smallest] ) {
		smallest = right;
	}

	if ( smallest != index ) {
		Swap( &heap->elements[smallest], &heap->elements[index] );
		MinHeapify( heap, smallest );
	}
}

/*
====================
isFull

  Retorna true se a minHeap estiver cheia
====================
*/
int IsFull( Heap_t *heap ) {
	return heap->size == heap->capacity;
}

/*
====================
isEmpty

  Retorna true se a minHeap estiver vazia
====================
*/
int IsEmpty( Heap_t *heap ) {
	return heap->size == 0;
}

/*
====================
Push

  Insere um novo elemento na minHeap
====================
*/
void Push( Heap_t *heap, int value ) {
	if ( IsFull( heap ) ) {
		printf( "\nHeap Cheia!\n" );
		return;
	}

	int position = heap->size;
	heap->size++;
	heap->elements[position] = value;

	while ( position > 0 && heap->elements[( position - 1 ) / 2] > heap->elements[position] ) {
		Swap( &heap->elements[position], &heap->elements[( position - 1 ) / 2] );
		position = ( position - 1 ) / 2;
	}
}

/*
====================
Pop

  Remove e retorna o menor elemento do heap
====================
*/
int Pop( Heap_t *heap ) {
	if ( IsEmpty( heap ) ) {
		return -1;
	}

	int root = heap->elements[0];
	heap->size--;
	heap->elements[0] = heap->elements[heap->size];

	MinHeapify( heap, 0 );

	return root;
}

/*
====================
SeatManagerCreate

  Inicializa um gerenciador de assentos
====================
*/
SeatManager_t *SeatManagerCreate( int n ) {
	SeatManager_t *seatManager = (SeatManager_t *) malloc( sizeof( SeatManager_t ) );
	if ( seatManager == NULL ) {
		printf( "\nErro ao alocar memória!\n" );
		return NULL;
	}

	seatManager->heap.capacity = n;
	seatManager->heap.size = 0;
	seatManager->heap.elements = (int *) malloc( n * sizeof( int ) );

	for ( int counter = 1; counter <= n; counter++ ) {
		Push( &seatManager->heap, counter );
	}

	return seatManager;
}

/*
====================
SeatManagerReserve

  Reserva e retorna o menor assento disponível
====================
*/
int SeatManagerReserve( SeatManager_t *obj ) {
	return Pop( &obj->heap );
}

/*
====================
SeatManagerUnreserve

  Desreserva e devolve o assento para a heap
====================
*/
void SeatManagerUnreserve( SeatManager_t *obj, int seatNumber ) {
	Push( &obj->heap, seatNumber );
}

/*
====================
SeatManagerFree

  Libera a memória da heap e do gerenciador
====================
*/
void SeatManagerFree( SeatManager_t *obj ) {
	free( obj->heap.elements );
	free( obj );
}

/*
====================
Main

  Testa a funcionalidade do gerenciador de assentos
====================
*/
int main( void ) {
	SeatManager_t *manager = SeatManagerCreate( 5 );
	printf( "Reserve: %d\n", SeatManagerReserve( manager ) );
	printf( "Reserve: %d\n", SeatManagerReserve( manager ) );
	SeatManagerUnreserve( manager, 1 );
	printf( "Reserve: %d\n", SeatManagerReserve( manager ) );
	SeatManagerFree( manager );
	return 0;
}
