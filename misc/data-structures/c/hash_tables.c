#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME    256
#define TABLE_SIZE  10
#define DELETED_NODE    (person*)   (0xFFFFFFFFFFFFFFFFUL)

typedef struct 
{
    char name[MAX_NAME];
    int age;
}person;

person *hashTable[TABLE_SIZE];

unsigned int hash(char *name)
{
    int lenght=strlen(name);
    unsigned int hashValue=0;
    for(int i=0;i<lenght;i++){        
        hashValue+=name[i];
        hashValue=(hashValue*name[i])%TABLE_SIZE;
    }
    return hashValue;
}

bool initHashTable(void)
{
    for(int i=0;i<TABLE_SIZE;i++)
        hashTable[i]=NULL;  
    return true;
}

void printTable(void)
{
    printf("\t----START----\n");
    for(int i=0;i<TABLE_SIZE;i++){
        if(hashTable[i]==NULL){
            printf("\t%i\t---\n",i);
        }else if(hashTable[i]==DELETED_NODE){
            printf("\t%i\t<--deleted node\n",i);
        }else{
            printf("\t%i\t%s\n",i,hashTable[i]->name);
        }
    }
    printf("\t----END----\n\n");
}

bool hashTableInsert(person *p)
{
    if(p==NULL) return false;
    int index=hash(p->name);
    for(int i=0;i<TABLE_SIZE;i++){
        int try=(i+index)%TABLE_SIZE;
        if(hashTable[try] == NULL   ||
            hashTable[try] == DELETED_NODE){
            hashTable[try]=p;
            return true;
        }
    }
    return true;
}

person *hashTableLookUp(char *name)
{
    int index=hash(name);
    for(int i=0;i<TABLE_SIZE;i++){
        int try=(i+index)%TABLE_SIZE;
        if(hashTable[try]==NULL){
            return false;
        }
        
        if(hashTable[try] == DELETED_NODE) continue;

        if(strcmp(hashTable[try]->name, name) == 0){
            return hashTable[try];
        }
    }
    return NULL;
}

person *hashTableDelete(char *name)
{
     int index=hash(name);
     for(int i=0;i<TABLE_SIZE;i++){
        int try=(i+index)%TABLE_SIZE;
        if(hashTable[try]==NULL) return NULL;
        if(hashTable[try]==DELETED_NODE) continue;
        if(strcmp(hashTable[try]->name, name) == 0)
        {
            person *tmp=hashTable[try];
            hashTable[try]=DELETED_NODE;
            return tmp;
        }   
     }
     return NULL;
}

int main(void)
{
    /* Init the hash table */
    initHashTable();
    printTable();

    /* Inserting elements in the hash table */
    person Jacob={.name="Jacob",.age=256};
    person Kate={.name="Kate",.age=23};
    person Mpho={.name="Mpho",.age=23};
    person Sara={.name="Sara",.age=66};
    person Natalie={.name="Natalie",.age=10};
    person Edna={.name="Edna",.age=10};
    person Maren={.name="Maren",.age=66};
    person Eliza={.name="Eliza",.age=10};
    person Robert={.name="Robert",.age=10};
    person Jane={.name="Jane",.age=10};

    printf("----- Inserting elements in the table\n");
    hashTableInsert(&Jacob);
    hashTableInsert(&Kate);
    hashTableInsert(&Mpho);
    hashTableInsert(&Sara);
    hashTableInsert(&Natalie);
    hashTableInsert(&Edna);
    hashTableInsert(&Maren);
    hashTableInsert(&Eliza);
    hashTableInsert(&Robert);
    hashTableInsert(&Jane);
    printTable();
    // return 1;

    /* Look up for some elements in the hash table */
    printf("----- Looking for elements in the table\n");
    person *tmp=hashTableLookUp("Mpho");
    if(tmp==NULL){
        printf("Person not found!!!\n");
    }else{
        printf("Person found!!!\n");
    }

    tmp=hashTableLookUp("Ulises");
    if(tmp==NULL){
        printf("Person not found!!!\n");
    }else{
        printf("Person found!!!\n");
    }

    /* Deleting elements from the hash table */
    printf("----- Deleting elements in the table\n");
    hashTableDelete("Mpho");
    tmp=hashTableLookUp("Mpho");
    if(tmp==NULL){
        printf("Person not found!!!\n");
    }else{
        printf("Person found!!!\n");
    }
    printTable();

    return 1;
}