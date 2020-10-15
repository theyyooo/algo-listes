/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "heap.h"

/**
 * @brief initialise la liste
 * 
 * @param h liste
 */
void init_heap(Heap *h){
    h->index = 0;
}

/**
 * @brief test vide
 * 
 * @param h liste
 * @return boolean reponse 
 */
bool is_heap_empty(Heap *h){
    
    return h->index == 0;
    
}

/**
 * @brief supprime la dernière valeur
 * 
 * @param h liste
 * @return float renvoie la valeur supprimé
 */
float pop_heap(Heap *h){
    h->index --;
    return h->data[h->index-1];
}

/**
 * @brief ajoute une valeur à la liste tout en le triant
 * 
 * @param h liste
 * @param value valeur
 */
void push_heap(Heap *h, float value){

    int child_index = h->index;
    int parent_index = h->index-1 >>1; //didision par 2

    h->data[child_index] = value;

    while (h->data[parent_index] < h->data[child_index])
    {
        float temp = h->data[child_index];
        h->data[child_index] = h->data[parent_index];
        h->data[parent_index] = temp;
        child_index = parent_index;
        parent_index = parent_index-1 >>1;
    }
}

// float replace(Heap *h, float value){
// }

/**
 * @brief renvoie la derniere valeur
 * 
 * @param h liste 
 * @return float derniere valeur
 */
float peek_heap(Heap *h){
    return h->data[h->index-1];
}