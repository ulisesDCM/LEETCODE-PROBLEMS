/*  
    Basic hash table implementation using
    chaining  method to handle collisions.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE  10
#define MAX_NAME    256

typedef struct 
{
    char name[MAX_NAME];    /* key */
    int age;
    struct person *next;    /* Next element in the linked list */
}person;


person *hash_table[TABLE_SIZE];

unsigned int hash(char *name){
    int length = strlen(name);
    unsigned int hash_value = 0;
    for(int i=0; i<length; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool init_hash_table(void){
    for(int i=0; i<TABLE_SIZE; i++)
        hash_table[i] = NULL;
    return true;
}

void print_table(void){
    printf("-----------------\n");
    for(int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("%i \t --- \t \n",i);
        }else{
            printf("%i\t ",i);
            person *tmp = hash_table[i];
            while( tmp != NULL){
                printf("%s - ",tmp->name);
                tmp = (person *) tmp->next;
            }
            printf("\n");
        }
    }
}

bool hash_table_insert(person *p){
    unsigned int hashIndx = hash(p->name);
    p->next = (struct person *) hash_table[hashIndx];
    hash_table[hashIndx] = p;
    return true;   
}

person *hash_table_lookup(char *name){
    unsigned int hashIndx = hash(name);
    person *tmp = hash_table[hashIndx];

    while( (tmp != NULL) && ( strcmp(tmp->name, name) != 0)){
        tmp = (person *) tmp->next;
    }
    return tmp;

}

person *hash_table_delete(char *name){
    unsigned int hashIndx = hash(name);
    person *tmp = hash_table[hashIndx];
    person *prev = NULL;

    while( (tmp != NULL) && ( strcmp(tmp->name, name) != 0)){
        prev = tmp;
        tmp = (person *) tmp->next;
    }
    
    if(tmp == NULL) return NULL;
    if(prev == NULL){
        /* Removing head (first element)*/
        hash_table[hashIndx] = (person *) tmp->next;
    }else{
        /* Removing element in the middle */
        prev->next = tmp->next;
    }
    return tmp;
}

int main(void){
    /* Making some people */
    person Jacob = {.age=20, .name = "Jacob"};
    person Ulises = {.age=21, .name = "Ulises"};
    person Miguel = {.age=22, .name = "Miguel"};
    person Jose = {.age=23, .name = "Jose"};
    person Yolanda = {.age=24, .name = "Yolanda"};
    person Luna = {.age=25, .name = "Luna"};
    person Elena = {.age=26, .name = "Elena"};

    /* Test the hash table functions */
    init_hash_table();      /* Initializes the hash table (array of pointers) with a empty value (NULL) */
    print_table();          /* Print hash table values */
    hash_table_insert(&Jacob);
    hash_table_insert(&Ulises);
    hash_table_insert(&Miguel);
    hash_table_insert(&Jose);
    hash_table_insert(&Yolanda);
    hash_table_insert(&Luna);
    hash_table_insert(&Elena);
    print_table();

    /* Find some name in the hash table */
    person *tmp = hash_table_lookup("Luna");
    if(tmp != NULL){
        printf("Luna found :) !!!\n");
    }else{
        printf("Luna not found :( !!!\n");
    }

    tmp = hash_table_lookup("Ulises");
    if(tmp != NULL){
        printf("Ulises found :) !!!\n");
    }else{
        printf("Ulises not found :( !!!\n");
    }

    /* Delete a value in the hash map */
    tmp = hash_table_delete("Luna");
    print_table();

    tmp = hash_table_lookup("Luna");
    if(tmp != NULL){
        printf("Luna found :) !!!\n");
    }else{
        printf("Luna not found :( !!!\n");
    }
    /* Just testing my hash function */ 
 /*    
    printf("Jacob --> %u\n",hash("Jacob"));
    printf("Ulises --> %u\n",hash("Ulises"));
    printf("Miguel --> %u\n",hash("Miguel"));
    printf("Jose --> %u\n",hash("Jose"));
    printf("Yolanda --> %u\n",hash("Yolanda"));
    printf("Luna --> %u\n",hash("Luna"));
    printf("Elena --> %u\n",hash("Elena"));
 */
    return 1;
}