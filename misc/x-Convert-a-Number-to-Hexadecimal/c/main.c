/* 
    Convert a Number to Hexadecimal
    Given an integer num, return a string representing its hexadecimal representation. 
    For negative integers, two’s complement method is used.
    All the letters in the answer string should be lowercase characters, and there should 
    not be any leading zeros in the answer except for the zero itself.
    Note: You are not allowed to use any built-in library method to directly solve this problem.

    Example 1:
        Input: num = 26
        Output: "1a"

    Example 2:
        Input: num = -1
        Output: "ffffffff"

    Constraints:
        -231 <= num <= 231 - 1

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * toHex(int num){
    char *ret = (char *) malloc(sizeof(char));
    *ret = (num%16) >= 10 ? (num%16)-10+'a': (num%16)+'0';
    if(num/16 == 0){
        return ret;
    }else{
        if(num<0) num = (~num)+1;
        strcat(toHex(num/16), ret);
    }
}

int main(void){
    printf("%s \n",toHex(26));
    printf("%s \n",toHex(999999));
    printf("%s \n",toHex(7562));
    printf("%s \n",toHex(-1));
}