#ifndef _BTREE_BASE
#define _BTREE_BASE

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

/**
 *  Binary Tree Node Struct
 */
#define BTREE_ELEM int

typedef struct _btn {
    BTREE_ELEM data;
    struct _btn *left;
    struct _btn *right;
} btn;

/**************************************************************/
/*                     ÁRBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un dato BTREE_ELEM
 */
btn* btn_new(BTREE_ELEM data);

/**
 * Elimina un nodo, si tiene hijos elimina sus hijos también.
 */
void btn_free(btn** node);

/** 
 * Busca un nodo con un determinado elemento y devuelve su referencia
 * Se busca el nodo en pre-order (debe recorrer todo el árbol no hay un criterio de ordenamiento)
 * Debe devolver la referencia a la ubicación del puntero al nodo. Si no existe, devuelve NULL
 */ 
btn** btn_find(btn** node, BTREE_ELEM data, int cmp(BTREE_ELEM, BTREE_ELEM));

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */
int btn_isLeaf(btn *node);

/**
 * Cuenta la cantidad de nodos de un árbol binario.
 */
int btn_count(btn *node);

/**
 * Agrega un nodo en un árbol binario con el siguiente criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert(btn **node, btn *newNode);

/**
 * Agrega un dato a un BT con el criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert_data(btn **node, int data);

/**
 * Determinar el nivel de un nodo.
 * - Recibe como entrada la raíz, un dato y una función de comparación de datos del árbol.
 */
int _btn_level(btn *node, BTREE_ELEM data, int level, int cmp(BTREE_ELEM, BTREE_ELEM));

int btn_level(btn* root, BTREE_ELEM data, int cmp(BTREE_ELEM, BTREE_ELEM));

/**
 * Devuelve la altura de un BTN
 */
BTREE_ELEM btn_height(btn *node);

/**
 * Recorrido de un BT en inorden
 */
void btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx);

/**
 * Recorrido de un BT en postorder
 */
void btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx);

/**
 * Recorrido de un BT en preorder
 */
void btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx);

/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un árbol.
 */
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*));

/**
 * Dibuja un árbol binario con caracteres
 * (Los datos de los nodos deben enteros entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*));

#endif _BTREE_BASE