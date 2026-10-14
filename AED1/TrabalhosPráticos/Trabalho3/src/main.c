#include <stdio.h>

/*
====================
TreeNode_t

  Estrutura de um nó de árvore binária
====================
*/
struct TreeNode_t {
	int val;
	struct TreeNode_t *left;
	struct TreeNode_t *right;
};

/*
====================
GetDepth_r

  Retorna o nó mais profundo e sua profundidade
====================
*/
struct TreeNode_t *GetDepth_r( struct TreeNode_t *node, int *depth ) {
	if ( node == NULL ) {
		*depth = 0;
		return NULL;
	}

	int depthLeft = 0, depthRight = 0;
	struct TreeNode_t *left = GetDepth_r( node->left, &depthLeft );
	struct TreeNode_t *right = GetDepth_r( node->right, &depthRight );

	*depth = 1 + ( depthLeft > depthRight ? depthLeft : depthRight );

	if ( depthLeft == depthRight ) {
		return node;
	}
	return ( depthLeft > depthRight ) ? left : right;
}

/*
====================
SubtreeWithAllDeepest

  Retorna a menor subárvore contendo todos os nós mais profundos
====================
*/
struct TreeNode_t *SubtreeWithAllDeepest( struct TreeNode_t *root ) {
	int depth = 0;
	return GetDepth_r( root, &depth );
}

/*
====================
Main

  Função principal
====================
*/
int main( void ) {
	return 0;
}
