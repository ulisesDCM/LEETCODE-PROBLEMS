#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define STACK_LENGTH    (50)
#define EMPTY           (-1)

int stack[STACK_LENGTH] = {0};
int stack_top = EMPTY;

bool push(int value)
{
    if(stack_top > (STACK_LENGTH-1))
        return false;

    stack_top++;
    stack[stack_top] = value;
    return true;
}

int pop(void)
{
    int ret = 0;
    if(stack_top == EMPTY)
        return INT_MIN;

    ret = stack[stack_top];
    stack_top--;
    return ret; 
}

int main(void)
{
    push(50);
    push(100);
    push(-100);
    push(500);

    printf("%d\r\n",pop());
    printf("%d\r\n",pop());
    printf("%d\r\n",pop());
    printf("%d\r\n",pop());
    printf("%d\r\n",pop());
    printf("%d\r\n",pop());

    return 1;
}