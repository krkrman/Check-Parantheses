#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef char int8_t;

typedef struct Stack
{
    uint8_t* array;
    uint8_t capacity;
    int8_t top;
} Stack_st_t;

Stack_st_t* createStack(uint8_t capacity)
{
    Stack_st_t* stack = (Stack_st_t*)malloc(sizeof(Stack_st_t));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (uint8_t*)malloc(stack->capacity * sizeof(uint8_t));
    return stack;
}
uint8_t isEmpty(Stack_st_t* stack)
{
    return stack->top == -1;
}

uint8_t isFull(Stack_st_t* stack)
{
    return stack->top == stack->capacity -1;
}

void push(Stack_st_t* stack, uint8_t item)
{
    if (isFull(stack))
    {
        printf("Stack is Full");
        return;
    }
    stack->array[++stack->top] = item;
}
void printStack(Stack_st_t* stack)
{
    for(int i =0; i<stack->top +1 ; i++)
    {
        printf("%c", stack->array[i]);
    }
}
void pop(Stack_st_t* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is Empty");
        return;
    }
    stack->top--;
}

uint8_t getTop(Stack_st_t* stack)
{
    return stack->array[stack->top];
}

uint8_t* balancedParentheses(Stack_st_t* stack, uint8_t* expression)
{   int i = 0;
    while(expression[i] != '\0')
    {
        if(expression[i] == '(' || expression[i] == '{')
        {
            push(stack, expression[i]);
        }
        else if(expression[i] == ')')
        {
            if(getTop(stack) == '(')
            {
                pop(stack);
            }
        }
        else if(expression[i] == '}')
        {

            if(getTop(stack) == '{')
            {
                pop(stack);
            }
        }
        i++;
    }
    if(isEmpty(stack))
        return "Balanced";
    else
        return "Not Balanced";
}
int main()
{
    Stack_st_t* stack = createStack(100);
    uint8_t* expression1 = "(2*3+(5/2+(4*3)))";
    printf("%s: " ,expression1 );
    uint8_t* isBalanced1 = balancedParentheses(stack , expression1);
    printf("%s\n" ,isBalanced1 );

    uint8_t* expression2 = "(2*3+(5/2+(4*3))";
    printf("%s: " ,expression2 );
    uint8_t* isBalanced2 = balancedParentheses(stack , expression2);
    printf("%s" ,isBalanced2 );

    return 0;
}
