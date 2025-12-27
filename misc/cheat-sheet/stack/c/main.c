#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

// #define STACK_VERSION1
#define STACK_VERSION2
// #define STACK_VERSION3
// #define STACK_VERSION4


#ifdef STACK_VERSION1
    /* Stack implementation version 1: static array */
    #define STACK_SIZE         (5)
    #define EMPTY              (-1)
    #define STACK_EMPTY        (INT_MIN)

    int stack[STACK_SIZE];
    int head = EMPTY;

    bool push(int value){
        if(head >= STACK_SIZE-1)    return  false;  /* Stack full */
        stack[++head] = value;
        return true;
    }


    int pop(void){
        if(head == EMPTY)   return STACK_EMPTY;  /* Stack empty */
        int ret = stack[head--];
        return ret;
    }

    int main(void){

        push(1);
        push(2);
        push(3);
        push(4);

        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        return -1;
    }
#elifdef STACK_VERSION2
    /* Stack implementation version 2: Linked list */
    #define STACK_SIZE         (5)
    #define EMPTY              (NULL)
    #define STACK_EMPTY        (INT_MIN)

    typedef struct node{
        int value;
        struct node *next; 
    }node;

    node *head = NULL;

    node *stackInit(void){

    }

    bool push(int value){
        node *new = (node *) malloc( sizeof(node) );
        if( new == NULL )   return false;

        new->value = value;
        new->next = head;
        head = new;
        return new;
    }


    int pop(void){
        if(head == EMPTY)   return STACK_EMPTY;  /* Stack empty */
        
        int ret = head->value;
        node *tmp = head;
        head = head->next;
        free(tmp);
        return ret;
    }

    int main(void){

        push(1);
        push(2);
        push(3);
        push(4);

        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        return -1;
    }

#elifdef STACK_VERSION3
    /* Stack implementation version 3: Linked list without global stack */
    #define STACK_SIZE         (5)
    #define EMPTY              (NULL)
    #define STACK_EMPTY        (INT_MIN)

    typedef struct node{
        int value;
        struct node *next; 
    }node;

    node *head;

    bool push(int value){
        node *new = (node *) malloc( sizeof(node) );
        if( new == NULL )   return false;

        new->value = value;
        new->next = head;
        head = new;
        return true;
    }


    int pop(){
        if(head == EMPTY)   return STACK_EMPTY;  /* Stack empty */
        
        int ret = head->value;
        node *tmp = head;
        head = head->next;
        free(tmp);
        return ret;
    }

    int main(void){

        push(1);
        push(2);
        push(3);
        push(4);

        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        printf("pop: %d\n",pop());
        return -1;
    }

#elifdef STACK_VERSION4

#endif



