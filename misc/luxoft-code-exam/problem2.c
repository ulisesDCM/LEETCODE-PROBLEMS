#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Descriptor
{
    int id;
    int name_length;
    char *name;
} Descriptor;

Descriptor *allocate_and_initialize_descriptor(int id, const char *name) 
{
    // Waiting to be implemented.
    int i=0;    //Loop counter.
    char *name_copy = NULL;
    char *tmp = (char *) name;

    // Allocate the return Descriptor in memory
    Descriptor *ret = (Descriptor *) malloc(sizeof( Descriptor) );
    if( (ret == NULL))
        return NULL;    //Return if there is no enough heap memory.

    // Copy the ID argument.
    ret->id = id;

    // Getting the name size;
    while(*tmp++)
    {
        ret->name_length++;
    }

    ret->name = (char *) malloc(sizeof(char)*ret->name_length);
    tmp = ret->name;
    
    if( (ret->name == NULL))
        return NULL;    //Return if there is no enough heap memory.

    while(*name)
    {
        *tmp++ = *name++; 
    }
    
    return ret;
}

void deallocate_descriptor(Descriptor *descriptor)
{
    free(descriptor->name);    
    free(descriptor);
}

#ifndef RunTests
int main()
{
    Descriptor *descriptor = allocate_and_initialize_descriptor(2, "Ulises");
    printf("Id: %d, name length: %d, name: %s\r\n", descriptor->id, descriptor->name_length, descriptor->name);
    deallocate_descriptor(descriptor);
}
#endif