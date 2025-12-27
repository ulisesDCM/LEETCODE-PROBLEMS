#include <stdio.h>
#include <stdlib.h>

void Mymemcpy(void *destination, const void *source, size_t num){
    char *csrc = (char *) source;
    char *cdest = (char *) destination;

    for(int i=0; i<num; i++)
        cdest[i] = csrc[i];
}

int main(void){
    int testSource[10] = {1,2,3,4,5,6,7,8,9,10};
    int testDest[10] = {0};

    /* Printing all elements */
    for(int i=0; i< (sizeof(testSource) / sizeof(int)) ; i++){
        printf("testSource: %d \t testDest: %d\n",testSource[i], testDest[i] );
    }
    printf("\n");

    /* Use memcpy */
    Mymemcpy( &testDest[0], &testSource[0], sizeof(testSource));

    printf("\n");
    for(int i=0; i< (sizeof(testSource) / sizeof(int)) ; i++){
        printf("testSource: %d \t testDest: %d\n",testSource[i], testDest[i] );
    }

}