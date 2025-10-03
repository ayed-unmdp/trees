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
/*             ÁRBOLES BINARIOS DE BÚSQUEDA                   */
/**************************************************************/

/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
BTREE_ELEM _max_elem (BTREE_ELEM a, BTREE_ELEM b, int cmp (BTREE_ELEM, BTREE_ELEM) ) {
    return (cmp(a, b) > 0) ? a : b;    
}

/**
 * Agrega un nodo a un árbol binario de búsqueda (bst)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          *newNode: puntero al nodo que se va a insertar en el bst
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */
int bst_insert_node(btn **node, btn *newNode, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    if (node == NULL) return 0;
    if (newNode == NULL) return 1;

    /**** COMPLETAR ****/
}

/**
 * Agrega un valor a un árbol binario de búsqueda (bst)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          data: el dato a agregar.
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */
int bst_insert_data(btn **node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor mínimo de un
 * bst.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn** bst_get_min_node(btn **node) {
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    /**** COMPLETAR ****/
}

/**
 * Devuelve el valor mínimo de un bst
 */
BTREE_ELEM bst_min(btn *node) {
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor máximo de un
 * bst.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn** bst_get_max_node(btn **node) {
    /**** COMPLETAR ****/
}

/**
 * Devuelve el valor máximo de un bst
 */
BTREE_ELEM bst_get_max_data(btn *node) {
    if (node == NULL) return -1;
    btn **r = bst_get_max_node(&node);
    return (*r)->data;
}


/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un bst. (Versión recursiva)
 * Parámetros:
 *          data: el valor que se busca en el bst.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn* bst_findr(btn *node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un bst. (Versión iterativa)
 * Parámetros:
 *          data: el valor que se busca en el bst.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn *bst_findi(btn *node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}


/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor solicitado de
 * un bst.
 * Parámetros:
 *          data: el valor que se busca en el bst.
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar.
 */
btn** bst_find_node(btn **node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return NULL;  // []->nodo

    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un bst. (Versión iterativa en reducida) * 
 * Parámetros:
 *          data: el valor que se busca en el bst.
 *          **node: referencia al puntero al nodo del sub-árbol donde se
 * va a buscar.
 * Devuelve una doble puntero para permitir la modificación.
 */
btn** bst_findii(btn** node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Devuelve 1 si un valor se encuentra en el árbol, o 0 si no se encuentra
 */
int bst_in(btn* node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un bst, reemplazando el nodo por su rama Derecha y agregando
 * la rama Izquierda a la rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn* bst_remove_node(btn **node,  int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un bst, reemplazando el nodo por el máximo de su rama
 * izquierda, o en su defecto por el mínimo de su rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn* bst_remove_node2(btn **node) {
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un bst, reemplazando el nodo por
 * 1) el máximo de su rama izquierda, si la rama izquierda es igual o más alta
 * que la derecha.
 * 2) el mínimo de su rama derecha, si la rama derecha es más
 * alta que la izquierda.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn *bst_remove_node_smart(btn **node) {
    if (!node) return NULL;
    if (!(*node)) return NULL;

    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un bst.
 * Usa método de reemplazo por el hijo derecho.
 * Devuelve 1 si pudo eliminarlo,
 * Devuelve 0 si no pudo
 */
int bst_remove_data(btn **node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un bst.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * derecha. Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */
int bst_remove_data2(btn **node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un bst.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * según cual sea más alto.
 * Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */
int bst_remove_data_smart(btn **node, BTREE_ELEM data, int cmp (BTREE_ELEM, BTREE_ELEM)) {
    /**** COMPLETAR ****/
}