#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME    256
#define TABLE_SIZE  10

typedef struct person  
{
    char name[MAX_NAME];
    int age;
    struct person *next;
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
        }else{
            printf("\t%i\t",i);
            person *tmp=hashTable[i];
            while(tmp!=NULL){
                printf("%s - ",tmp->name);
                tmp=tmp->next;
            }
            printf("\n");
        }
    }
    printf("\t----END----\n\n");
}

bool hashTableInsert(person *p)
{
    if(p==NULL) return false;
    int index=hash(p->name);
    p->next=hashTable[index];
    hashTable[index]=p;
    return true;
}

person *hashTableLookUp(char *name)
{
    int index=hash(name);
    person *tmp=hashTable[index];
    while(tmp != NULL && strcmp(tmp->name,name) != 0)
        tmp=tmp->next;
    return tmp;
}

person *hashTableDelete(char *name)
{
    int index=hash(name);
    person *tmp=hashTable[index];
    person *prev=NULL;
    while(tmp != NULL && strcmp(tmp->name,name) != 0){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp==NULL ) return NULL;
    if(prev==NULL){
        hashTable[index]=tmp->next;
    }else{
        prev->next=tmp->next;
    }
    return tmp;
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
    printf("----- Looking for Mpho in the table\n");
    person *tmp=hashTableLookUp("Mpho");
    if(tmp==NULL){
        printf("Person not found!!!\n");
    }else{
        printf("Person found!!!\n");
    }

    printf("----- Looking for Ulises in the table\n");
    tmp=hashTableLookUp("Ulises");
    if(tmp==NULL){
        printf("Person not found!!!\n");
    }else{
        printf("Person found!!!\n");
    }

    /* Deleting elements from the hash table */
    printf("----- Deleting Mpho in the table\n");
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