#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
    ptr++;    // Pointer moves to the next int position (as if it was an array)
    ++ptr;    // Pointer moves to the next int position (as if it was an array)
    ++*ptr;   // The value pointed at by ptr is incremented
    ++(*ptr); // The value pointed at by ptr is incremented
    ++*(ptr); // The value pointed at by ptr is incremented
    *ptr++;   // Pointer moves to the next int position (as if it was an array). But returns the old content
    (*ptr)++; // The value pointed at by ptr is incremented
    *(ptr)++; // Pointer moves to the next int position (as if it was an array). But returns the old content
    *++ptr;   // Pointer moves to the next int position, and then get's accessed, with your code, segfault
    *(++ptr); // Pointer moves to the next int position, and then get's accessed, with your code, segfault
 */
struct node 
{
    int value;
    struct node *next;
};

typedef struct node node_t;

void print_test(char **ptr, int elements)
{
    char **tmp = ptr;
    while(elements--)
    {
        while(**tmp)
        {
            printf("%c",**tmp);
            ++(*tmp);
        }
        printf("\r\n");
        tmp++;
    }
}

void test_double_pointers_string(void)
{
    char *myString[] = {
        "Hello world!!!",
        "ulises here"
        };

    char *arrPtr[] = {
        "ulises",
        "jose",
        "yola",
        "miguel"
    };

    print_test(myString, 2);
    print_test(arrPtr, 4);
}

void print_list(node_t *head)
{
    node_t *tmp = head;

    while (tmp)
    {
        printf("%d - ",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}
node_t *create_new_node(int value)
{
    node_t *new = (node_t *) malloc(sizeof(node_t));
    if(new == NULL)
        return NULL;

    new->value = value;
    new->next = NULL;
    return new;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while(tmp != NULL)
    {
        if(tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;        
    }
    
    return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

int main(void)
{
    // node_t *head = NULL;
    // node_t *tail = NULL;
    // node_t *tmp = NULL;
    // node_t *new_node = NULL;

    // //Creating a list of nodes.
    // for(int i=0; i<24; i++)
    // {
    //     tmp = create_new_node(i);
    //     insert_at_head( (node_t **) &head, tmp);
    // }
    
    // //Finding the node 13.
    // tmp = find_node(head,13);
    // printf("found node with value %d \r\n",tmp->value);

    // //Creating a new node.
    // new_node = create_new_node(50);

    //Insert the new node after the node 13.
    // insert_after_node(tmp, new_node);

    //Print all list.
    // print_list(head);

    unsigned char test = 255;
    printf("%d\r\n",test++);
    printf("%d\r\n",test++);


    return 1;
}
