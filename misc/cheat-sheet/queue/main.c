#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// #define QUEUE_VERSION_1         /* Version using dynamic memory to create an array. */
#define QUEUE_VERSION_2     /* Version using linked list. (problem when you have limited memory) */

/* 
    Implement the MyCircularQueue class:

    MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    
    int Front() Gets the front item from the queue. If the queue is empty, return -1.
    
    int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    
    boolean enQueue(int value) Inserts an element into the circular queue. 
        Return true if the operation is successful.
    
    boolean deQueue() Deletes an element from the circular queue. 
        Return true if the operation is successful.
    
    boolean isEmpty() Checks whether the circular queue is empty or not.
    
    boolean isFull() Checks whether the circular queue is full or not.

*/
#ifdef QUEUE_VERSION_1
    typedef struct queue{
        int *values;
        int head;
        int tail;
        int size;
    }queue_t;

    /*
        Initializes the object with the size of the queue to be k 
    */
    queue_t *createQueue(int size){
        queue_t *ret = (queue_t *) malloc( sizeof(queue_t) );
        if( ret == NULL )   return NULL;

        ret->values = (int *) malloc( sizeof( int) * size);
        if( ret == NULL )   return NULL;

        ret->head = 0;
        ret->tail = ret->head;
        ret->size = size;

        return ret;
    }

    /* 
        boolean enQueue(int value) Inserts an element into the circular queue. 
        Return true if the operation is successful.
    */
    bool enQueue(queue_t *queue, int value){
        /* Check if the queue is full */
        if( queue->tail == queue->size )    return false;

        /* Add the element in the queue and increase the tail pointer  */
        queue->values[ (queue->tail + queue->head) % queue->size  ] = value;   
        return true;
    }

    /*
        boolean deQueue() Deletes an element from the circular queue. 
        Return true if the operation is successful. 
    */
    bool deQueue(queue_t *queue){
        /* Check if the queue is empty */
        return false;
    }

    int main(void){
        return 1;
    }
#elif defined QUEUE_VERSION_2

#define QUEUE_EMPTY     (INT_MIN)

typedef struct node{
    int value;
    struct node *next;
}node;

typedef struct queue{
    node *head;
    node *tail;
}queue;

void initQueue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enQueue(queue *q, int value){
    /* Create a new node */
    node *new = (node *) malloc( sizeof(node) );
    if( new == NULL )   return false;
    new->value = value;
    new->next = NULL;

    /* If there is a tail, connect that tail to this new node. */
    if( q->tail != NULL ){
        q->tail->next = new;
    }
    q->tail = new;

    /* Make sure the head makes sense. */
    if( q->head == NULL ){
        q->head = new;
    }

    return true;
}

int deQueue(queue *q){
    /* Check if the queue is empty. */
    if( q->head == NULL )   return QUEUE_EMPTY;

    /* Save the head of the queue. */
    node *tmp = q->head;

    /* Save the result we're going to return. */
    int result = tmp->value;

    /* Take it off. */
    q->head = q->head->next;
    if(q->head == NULL ){ 
        q->tail = NULL;
    }
    free(tmp);

    return result;
}

int main(void){
    queue s1;
    initQueue(&s1);

    printf("%d\n", deQueue( &s1 ) );
    
    for( int i=0; i<10; i++){
        enQueue( &s1, i);
    }

    for( int i=0; i<12; i++){
        printf("%d\n", deQueue( &s1) );
    }

    return 1;
}

#endif
