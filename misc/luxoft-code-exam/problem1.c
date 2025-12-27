#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count_letters(const char **strings, int string_count, char target)
{
    // Waiting to be implemented
    int i=0;    //Loop counter.
    int ret=0;  //letter counter to return.

    //Iterate for all strings.
    for(i=0; i<string_count; i++)
    {
        while(*strings[i])
        {
            // printf("%c\r\n", *strings[i]);
            if(*strings[i] == target)
            {
                // If target found, then increase counter.
                ret++;
            }
            *strings[i]++;  //Go to the next character of the string.
        }
    }
    
    return ret;
}

#ifndef RunTests
int main()
{
    char *string_arr[] = {"eeee", "Jacqueline!"};
    int res = count_letters( (const char **) &string_arr, 2, 'e');
    printf("%d\r\n", res);
}
#endif