#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define LINKED_LIST_VER_1
#define LINKED_LIST_VER_2

#ifdef LINKED_LIST_VER_1

    typedef struct node{
        int value;
        struct node *next;
    }node_t;

    void printList(node_t *head){
        node_t *tmp = head;

        while(tmp != NULL){
            printf("%d - ",tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }

    node_t *createNode(int value){
        node_t *ret = (node_t *) malloc( sizeof(node_t) );
        if( ret == NULL )   return NULL;
        ret->value = value;
        ret->next = NULL;
        return ret;
    }

    node_t *insertAtHead(node_t **head, node_t *new){
        new->next = *head;
        *head = new;
        return new;
    }

    node_t *findNode(node_t *head, int value){
        node_t *tmp = head;
        while( (tmp != NULL) && (tmp->value != value))
            tmp = tmp->next;
        return tmp;
    }

    void insertAfterNode(node_t *node, node_t *new){
        new->next = node->next;
        node->next = new;
    }

    void removeNode(node_t *head, int value){
        node_t *tmp = head;
        node_t *prev = head;

        while( (tmp->next != NULL) && (tmp->value != value) ){
            prev = tmp;
            tmp = tmp->next;
        }

	if(node != NULL){
        	prev->next = prev->next->next;
		free(prev->next);
	}
    }

    int main(void){
        node_t *head = NULL;

        for(int i=0; i<10; i++){
            insertAtHead(&head, createNode(i) );
        }

        /* Print the all list */
        printList(head);

        /* Find an element */
        node_t *tmp = findNode(head, 3);
        if( tmp != NULL ){
            printf(" Node found \n");
            insertAfterNode(tmp, createNode(99) );
            printList(head);
        }else{
            printf("Node not found !!!\n");
        }

        removeNode(head, 99);
        printList(head);

        return 1;
    }
#elif defined LINKED_LIST_VER_2

	typedef struct GPIO{
		char *portName;
		int value;
	}GPIO_t;

	typedef struct node{
		GPIO_t *gpio;
		struct node *next;
	}node_t;

	GPIO_t *createGPIO(char *name, int value){
		GPIO_t *new = (GPIO_t *) malloc( sizeof(GPIO_t) );
		if(new == NULL) return NULL;
		
		new->portName = name;
		new->value = value;
		return new;
	}

	node_t *createNode(GPIO_t *port){
		node_t *new = (node_t *) malloc( sizeof(node_t) );
		if( new == NULL) return NULL;

		new->gpio = port;
		new->next = NULL;
		return new;
	}

	void printList(node_t *head){
		while( (head != NULL) ){
			printf("%s:%d -> ", head->gpio->portName, head->gpio->value);
		    head = head->next;	
		}
		printf("\n");
	}

	void insertAtHead(node_t **head, node_t *new){
		new->next = *head;
        *head = new;
	}
	
    void insertAfterNode(node_t *node, node_t *new){
        new->next = node->next;
        node->next = new;
    }

	void deleteNode(node_t *head,  char *name){
		node_t *prev = head;

        while( (head != NULL) && (head->gpio->portName != name)){
            prev = head;
            head = head->next;
        }

        if( head != NULL ){
            prev->next = head->next;
            free(head);
        }
	}

    node_t *findNode(node_t *head, char *name){
        while( (head != NULL) && (head->gpio->portName != name)){
            head = head->next;
        }
        return head;
    }

	int main(void){
        node_t *head = NULL;

        insertAtHead(&head, createNode( createGPIO("GPIOA",10) ) );
        insertAtHead(&head, createNode( createGPIO("GPIOB",20) ) );
        insertAtHead(&head, createNode( createGPIO("GPIOC",30) ) );
        printList(head);

        node_t *tmp =  findNode(head, "GPIOB");
        if( tmp != NULL ){
            printf("Node found \n");
        }else{
            printf("Node not found \n");
        }

        insertAfterNode(tmp, createNode( createGPIO("GPIOX", 99) ) );
        printList(head);

        deleteNode(head, "GPIOX");
        printList(head);
	}
#endif
