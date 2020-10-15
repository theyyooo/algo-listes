/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 #include "queue.h"

/**
 * @brief initialise la liste
 * 
 * @param q liste
 */
 void init_queue(Queue *q){
     q->index = 0;
 }

/**
 * @brief ajoute une valeur à la première case tout en déplaceant le reste
 * 
 * @param q liste
 * @param value valeur
 */
void enqueue(Queue *q, float value){
    for (int i = q->index; i >= 0; i--)
    {
        q->data[i+1] = q->data[i];
    }
    q->data[0] = value;
    q->index++; 
}

/**
 * @brief supprime la première valeur et décale tout le tableau
 * 
 * @param q liste
 * @return float valeur supprimé
 */
float dequeue(Queue *q){
    float val_suppr = q->data[0];
    for (int i = 0; i < q->index; i--)
    {
        q->data[i] = q->data[i+1];
    }
    q->index--;
    return val_suppr;
}

/**
 * @brief test sur le contenue
 * 
 * @param q liste
 * @return boolean retourne booléen
 */
bool is_queue_empty(Queue *q){
    if((*q).index == 0){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief affiche la première valeur
 * 
 * @param q liste
 * @return float valeur retourné
 */
float front(Queue *q){
    return (*q).data[0];
}

/**
 * @brief remet à 0 la liste
 * 
 * @param q liste
 */
void clear_queue(Queue *q){
    q->index = 0;
}
