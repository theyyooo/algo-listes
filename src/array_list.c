/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "array_list.h"

/**
 * @brief initialise une liste
 * 
 * @param l est une liste
 */
void init_array_list(Array_list *l){
    l->index = 0;
}

/**
 * @brief insert une valeur à un endroit donné en décalant le tableau
 * 
 * @param l est une liste
 * @param position est un lieu en int
 * @param value  est un float de la valeur souhaité
 */
void insert_at(Array_list *l, int position, float value){
    for (int i = l->index; i > position; i--)
    {
        l->data[i+1] = l->data[i];
    }
    l->data[position] = value;
    l->index++; 
}

/**
 * @brief ajoute une valeur à la fin de la liste
 * 
 * @param l est une liste
 * @param value  est un float de la valeur souhaité
 */
void add(Array_list *l, float value){
    l->data[l->index] = value;
    l->index++;
}

/**
 * @brief  supprime une valeur à l'endroit souhaité tout en décalant le tableau
 * 
 * @param l est un liste
 * @param position est la colonne qui va être supprimé
 * @return float renvoie la valeur supprimé
 */
float remove_at(Array_list *l, int position){
    return (*l).data[position];
    for (int i = position; i < l->index; i++)
    {
        l->data[i] = l->data[i+1];
    }
    l->index--; 
}

/**
 * @brief recupérer une valeur à une colonne donné.
 * 
 * @param l est une liste
 * @param position est la colonne de la valeur voulu
 * @return float revoie la valeur voulu
 */
float get_at(Array_list *l,int position){
    return (*l).data[position];
}

/**
 * @brief remet à 0 la liste
 * 
 * @param l  est une liste
 */
void clear(Array_list *l){
    l->index = 0;
}

