/* 
    Base 7

    Given an integer num, return a string of its base 7 representation.
    Example 1:
        Input: num = 100
        Output: "202"

    Example 2:
        Input: num = -7
        Output: "-10"

    Constraints:
        -107 <= num <= 107
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

char * convertToBase7(int num){
    
    // Normal method.
    // char *ret = (char *) malloc(sizeof(char));
    // int str_indx=0;

    // do{
    //     ret[str_indx]= (char) (num%7 + '0');
    //     str_indx++;
    //     ret = (char *) realloc(ret, str_indx+1);  
    //     num/=7;
    // }while(num!=0);

    // //Reverse string.
    // for(int i=0, j=str_indx-1; i<j ;i++, j--){
    //     swap(&ret[i], &ret[j]);
    // }
    // return ret;

    //Recursive method.
    char *ret = (char *)malloc(sizeof(char));
    *ret= (char) (num%7 + '0');
    if(num/7 == 0){
        return ret;
    }else{
        strcat(convertToBase7(num/7),ret);
    }
}

int main(void){
    printf("%s \n",convertToBase7(0));
    printf("%s \n",convertToBase7(100));
    printf("%s \n",convertToBase7(200));
    printf("%s \n",convertToBase7(300));
    printf("%s \n",convertToBase7(500));

}