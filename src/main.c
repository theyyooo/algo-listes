/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aurelio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include "stack.h"
#include "queue.h"
#include "array_list.h"
#include "heap.h"

float test(int a) {
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
}

float test_stack(){
    Stack s;
    float value = 5;

    init_stack(&s);  
    assert(s.index == 0);

    push_stack(&s, value);
    assert(s.data[s.index-1] == 5);

    push_stack(&s, value);
    pop_stack(&s);
    assert(s.index == 0);

    assert(is_stack_empty(&s) == true);

    push_stack(&s, value);
    assert(peek_stack(&s) == 5);

    push_stack(&s, value);
    push_stack(&s, 10);
    swap_stack(&s);
    assert(s.data[s.index -1] == 5);

    clear_stack(&s);
    assert(s.index == 0);
}

float test_queue(){
    Queue q;
    float value = 5;

    init_queue(&q);
    assert(q.index == 0);

    enqueue(&q, value);
     enqueue(&q, 8);
     assert(q.data[0] == 8);

    enqueue(&q, 8);
    enqueue(&q, value);
    dequeue(&q);
    assert(q.data[0] == 8);

    enqueue(&q, 8);
    assert(is_queue_empty(&q) == false);

    enqueue(&q, 8);
    assert(q.data[0] == 8);

    enqueue(&q, 8);
    assert(front(&q) == 8);

    enqueue(&q, 8);
    clear_queue(&q);
    assert(q.index == 0);

    
}

float test_array_list(){
    Array_list a;
    float value = 5;
    int position = 1;

    init_array_list(&a);
    assert(a.index == 0);

    insert_at(&a, 0,5);
    insert_at(&a, 1,10);
    insert_at(&a, 2,20);
    insert_at(&a, 1,70);
    assert(a.data[1] == 70);
    assert(a.data[3] == 20);

    add(&a, value);
    assert(a.data[a.index-1] = value);

    insert_at(&a, 0,5);
    insert_at(&a, 1,10);
    insert_at(&a, 2,20);
    remove_at(&a, 1);
    assert(a.data[1] == 20);

    insert_at(&a, 0,5);
    insert_at(&a, 1,10);
    insert_at(&a, 2,20);
    assert(get_at(&a, position) == 10);

    insert_at(&a, 0,5);
    insert_at(&a, 1,10);
    insert_at(&a, 2,20);
    clear(&a);
    assert(a.index == 0);
}

float test_heap(){
    float value = 5;
    Heap h;

    init_heap(&h);
    assert(h.index == 0);

    assert(is_heap_empty(&h) == true);

    push_heap(&h, 20);
    assert(h.data[0] == 20);

     push_heap(&h, 20);
    assert(peek_heap(&h) == 20);


}


/*
 * 
 */
int main(int argc, char** argv) {

    // test_stack();
    // test_queue();
    // test_array_list();
    test_heap();
    
    return (EXIT_SUCCESS);
}

