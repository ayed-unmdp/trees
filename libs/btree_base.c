#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: Árbol binario.
 * BTN - Binary Tree Node: nodo de árbol binario.
 * BST - Binary Search Tree: ABB - Árbol binario de búsqueda.
 * AVL - AVL Tree: Árbol AVL.
 * root: nodo raíz del árbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un árbol.
 */
/**************************************************************/

#include "btree_base.h"

/**************************************************************/
/*                     ÁRBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un dato BTREE_ELEM
 */
btn* btn_new(BTREE_ELEM data) {
    /**** COMPLETAR ****/
}

/**
 * Elimina un nodo, si tiene hijos elimina sus hijos también.
 */
void btn_free(btn** node) {
    /**** COMPLETAR ****/
}

/** 
 * Busca un nodo con un determinado elemento y devuelve su referencia
 * Se busca el nodo en pre-order (debe recorrer todo el árbol no hay un criterio de ordenamiento)
 * Debe devolver la referencia a la ubicación del puntero al nodo. Si no existe, devuelve NULL
 */ 
btn** btn_find(btn** node, BTREE_ELEM data, int cmp(BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */
int btn_isLeaf(btn *node) {
    /**** COMPLETAR ****/
}

/**
 * Cuenta la cantidad de nodos de un árbol binario.
 */
int btn_count(btn *node) {
    int result = 0;
    if (node != NULL) {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }
    return result;
}

/**
 * Agrega un nodo en un árbol binario con el siguiente criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert(btn **node, btn *newNode) {
    /**** COMPLETAR ****/
}

/**
 * Agrega un dato a un BT con el criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert_data(btn **node, int data) {
    /**** COMPLETAR ****/
}


/**
 * Determinar el nivel de un nodo.
 * - Recibe como entrada la raíz, un dato y una función de comparación de datos del árbol.
 */
int _btn_level(btn *node, BTREE_ELEM data, int level, int cmp(BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

int btn_level(btn* root, BTREE_ELEM data, int cmp(BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}


/**
 * Devuelve el dato máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
int _max(int a, int b) { return (a > b) ? a : b; }

/**
 * Devuelve la altura de un BTN
 */
BTREE_ELEM btn_height(btn *node) {
    int result = -1;
    /**** COMPLETAR ****/
    return result;
}

/**
 * Recorrido de un BT en inorden
 */
void btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;

    /**** COMPLETAR ****/
}

/**
 * Recorrido de un BT en postorder
 */
void btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;

    /**** COMPLETAR ****/
}

/**
 * Recorrido de un BT en preorder
 */
void btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx) {
    if (!node) return;

    /**** COMPLETAR ****/
}


/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un árbol.
 */
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*)) {
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);
    

    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    
    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los datos de los nodos deben enteros entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*)) {
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++) {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ') {
            j++;
        }
        if (s[i][j] != '\0') {
            printf("%s\n", s[i]);
        }
    }
}






