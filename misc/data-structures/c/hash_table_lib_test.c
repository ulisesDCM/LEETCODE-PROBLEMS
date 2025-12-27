#include "hash_table_lib.h"
#include <string.h>
#include <stdio.h>

#define MAX_LINE 4096

static uint64_t hash(char *name, size_t length){
    uint64_t hashValue=0;
    for(int i=0;i<length;i++){        
        hashValue+=name[i];
        hashValue=hashValue*name[i];
    }
    return hashValue;
}


int main(int argc, char **argv){
    if(argc != 3){
        printf("usage: <wordlist filename> <num guesses> \n");
        return EXIT_FAILURE;
    }
    char *filename = argv[1];
    uint32_t num_guesses = atol(argv[2]);

    const int tablesize=(1<<20);
    hash_table *table = hash_table_create(tablesize, hash);
    
    FILE *fp = fopen(filename, "r");
    char *buffer[MAX_LINE];
    uint32_t numwords=0;
    while(!feof(fp) && fgets(buffer, MAX_LINE, fp) != NULL){
        buffer[strcspn(buffer, "\n\r")] == 0;
        char * newentry=malloc(strlen(buffer)+1);
        strcpy(newentry, buffer);
        hash_table_insert(table, newentry, newentry);
        numwords++;
    }
    fclose(fp);
    printf("Loaded %d words into the table.\n",numwords);
    
    // hash_table_print(table);

    return 1;
}