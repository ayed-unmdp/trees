

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./bin/btree_base.h"
#include "./bin/btree_search.h"

// toStr devuelve el contenido de un nodo como string
// asume que t_elem_tree es un número entero
void btn_intToStr(btn* node, char* str) {
    if (!node) return;    
    sprintf(str, "(%03d)", node->data);    
}

// compara 2 elementos del árbol cuando son enteros
int btn_cmp_int(t_elem_btree a, t_elem_btree b) {
    return a - b;
}


void main(){
    btn* root = NULL;
    sbt_insert_data (&root, 20, btn_cmp_int);
    sbt_insert_data (&root, 10, btn_cmp_int);
    sbt_insert_data (&root, 15, btn_cmp_int);
    sbt_insert_data (&root, 12, btn_cmp_int);
    sbt_insert_data (&root, 30, btn_cmp_int);
    sbt_insert_data (&root, 25, btn_cmp_int);
    sbt_insert_data (&root, 35, btn_cmp_int);
    sbt_insert_data (&root, 40, btn_cmp_int);

    printf("\n%10s: \n", "Árbol");
    btn_print(root, btn_intToStr);

    sbt_remove_data (&root, 20, btn_cmp_int);

    printf("\n%10s: \n", "Árbol sin nel 20");
    btn_print(root, btn_intToStr);

    sbt_insert_data (&root, 28, btn_cmp_int);
    sbt_insert_data (&root, 29, btn_cmp_int);
    sbt_insert_data (&root, 27, btn_cmp_int);
    sbt_insert_data (&root, 32, btn_cmp_int);
    sbt_insert_data (&root, 33, btn_cmp_int);
    sbt_insert_data (&root, 9, btn_cmp_int);
    sbt_insert_data (&root, 20, btn_cmp_int);
    sbt_insert_data (&root, 31, btn_cmp_int);
    sbt_insert_data (&root, 36, btn_cmp_int);
    sbt_insert_data (&root, 45, btn_cmp_int);


    printf("\n%10s: \n", "Árbol con más nodos");
    btn_print(root, btn_intToStr);

    sbt_remove_data2 (&root, 25, btn_cmp_int);

    printf("\n%10s: \n", "Árbol sin el 25");
    btn_print(root, btn_intToStr);

    sbt_remove_data_smart (&root, 10, btn_cmp_int);

    printf("\n%10s: \n", "Árbol sin el 10");
    btn_print(root, btn_intToStr);
 
}
