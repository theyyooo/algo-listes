/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

/**
 * @brief initialise stack
 * 
 * @param s liste
 */
void init_stack(Stack *s){
    s->index = 0;
}

/**
 * @brief pousse une valeur dans la liste
 * 
 * @param s liste
 * @param value  valeur
 */
void push_stack(Stack *s, float value) {
    (*s).data[(*s).index] = value;
    (*s).index ++;
}

/**
 * @brief supprime la dernière couche
 * 
 * @param s liste
 * @return float retourne la valeur supprimé
 */
float pop_stack(Stack *s){
    (*s).index--;
    return (*s).data[(*s).index];   
}

/**
 * @brief teste contenue
 * 
 * @param s  liste
 * @return boolean return booleen 
 */
bool is_stack_empty(Stack *s){
    if((*s).index == 0){
        return true;
    }
    else{
        return false;
    }
    
}

/**
 * @brief retourne la dernière valeur
 * 
 * @param s liste
 * @return float retourne valeur
 */
float peek_stack(Stack *s){
    return (*s).data[(*s).index-1];
}

/**
 * @brief échange les deux dernières couches
 * 
 * @param s liste
 */
void swap_stack(Stack *s){
     float temp = (*s).data[(*s).index-1];
     (*s).data[(*s).index-1] = (*s).data[(*s).index-2];
     (*s).data[(*s).index-2] = temp;
}

/**
 * @brief remet à 0 la liste
 * 
 * @param s liste
 */
void clear_stack(Stack *s){
   s->index = 0;
}
