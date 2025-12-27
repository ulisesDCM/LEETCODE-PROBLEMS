#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE  100000
                    
typedef struct {
    int key;                /* Key  */
    int data;               /* Optional data */
    struct eDATA *next;     /* Pointer to the next chaining element */
}eDATA;


typedef struct {
    eDATA *hash_table[TABLE_SIZE];    
} MyHashMap;

unsigned int hash(int key){
    return (key * 1) % TABLE_SIZE;
}

MyHashMap* myHashMapCreate() {
    MyHashMap *ret = (MyHashMap *) malloc(sizeof(MyHashMap));
    for(int i=0; i<TABLE_SIZE; i++)
        ret->hash_table[i] = NULL;
    return ret;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
  eDATA *new = (eDATA*) malloc(sizeof(eDATA));
  new->key = key;
  new->data = value;
  unsigned int hashIndx = hash(new->key);
  eDATA *tmp = obj->hash_table[hashIndx];
  eDATA *prev = NULL; 
  while( (tmp != NULL) && (tmp->key != key)){
    tmp = tmp->next;
  }

  if(tmp == NULL){
    /* Element not found added to the list */
        new->next = (eDATA *) obj->hash_table[hashIndx];
        obj->hash_table[hashIndx] = new;
  }else{
    /* Element founded change just the value */
    tmp->data = value;
  }
  
}

int myHashMapGet(MyHashMap* obj, int key) {
    unsigned int hashIndx = hash(key);
    while( (obj->hash_table[hashIndx] != NULL) && 
            (obj->hash_table[hashIndx]->key != key) ){
                obj->hash_table[hashIndx] = (eDATA *) obj->hash_table[hashIndx]->next;
            }
    return (obj->hash_table[hashIndx] != NULL ? obj->hash_table[hashIndx]->data : -1);
}

void myHashMapRemove(MyHashMap* obj, int key) {
    unsigned int hashIndx = hash(key);
    eDATA *tmp = obj->hash_table[hashIndx];
    eDATA *prev = NULL;

    while( (tmp != NULL) && (tmp->key != key)){
        prev = tmp;
        tmp = (eDATA *) tmp->next;
    }

    /* No element founded */
    if(tmp == NULL) return ;

    if(prev == NULL){
        /* Remove head */
        obj->hash_table[hashIndx] = (eDATA *) tmp->next;
    }else{
        /* Remove element in the middle */
        prev->next = tmp->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    
}

int main(void){
    return 1;
}
