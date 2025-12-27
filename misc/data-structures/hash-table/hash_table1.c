/* 
    Basic Hash table implementation using 
    open addressing method to handle collisions.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME    256
#define TABLE_SIZE  10

typedef struct {
    char name[MAX_NAME];    //Key
    int age;
    //Add other stuff later. 
}person;

/* This fixed lenght hash table use pointers 'cause:
        * I don't need space to save the whole structure just saving the
            address is enough, (8 bytes instead of Sum(sizeof(members)) )
            this will be more clear (and relevant) when the structure has more
            elements.

        * It's more easy to tell when a spot is empty just setting the pointer address
            to null (hash_table[i] = NULL)
 */
person *hash_table[TABLE_SIZE];

/**
 * @brief Hash function that creates a random number using a input key.
 * 
 * @param name 
 * @return unsigned int 
 */
unsigned int hash(char *name){
    int lenght = strlen(name);
    unsigned int hash_value = 0;
    for(int i=0; i<lenght; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool init_hash_table(void){
    for(int i=0; i<TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    return true;
}

void print_table(void){
    printf("------------------------------\n");
    for(int i=0; i<TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }else{
            printf("\t%i\t%s\n",i,hash_table[i]->name);

        }
    }
}

bool hash_table_insert(person *p){
    if(p == NULL)   return false;
    int bucketIndx = hash(p->name);

    for(int i=0; i<TABLE_SIZE; i++){
        int try = (i+bucketIndx) % TABLE_SIZE;
        if(hash_table[try] == NULL){
            hash_table[try] = p;
            return true;
        }        
    }
    return false;
}

person *hash_table_lookup(char *name){
    int bucketIndx = hash(name);
    for(int i=0; i<TABLE_SIZE; i++){
        int try = (i+bucketIndx) % TABLE_SIZE;
        if( (hash_table[try] != NULL) && 
            ( !strcmp(hash_table[try]->name, name)) ){
                return hash_table[try];       
            }
    }
    return NULL;
}

person *hash_table_delete(char *name){
    int bucketIndx = hash(name);

    for(int i=0; i<TABLE_SIZE; i++){
        int try = (i+bucketIndx) % TABLE_SIZE;
        if( (hash_table[try] != NULL) 
            && ( !strcmp( hash_table[try]->name, name) ) ){
                person *ret = hash_table[try];
                hash_table[try] = NULL;
                return ret;
            }
    }
    return NULL;
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
    tmp = hash_table_delete("Ulises");
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