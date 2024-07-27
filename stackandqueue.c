#include <stdio.h>

#define STACK_MAX 100

void printArray(int arr[], int length);

typedef struct{
    int top;
    int arr[STACK_MAX];
} Stack;

void push(Stack *stack, int i){
    if (stack->top >= STACK_MAX)
    {
        printf("Stack is full.\n");
        return;
    }
    
    stack->arr[stack->top] = i;
    stack->top++;
}

int pop(Stack *stack){
    if (stack->top <= 0)
    {
        printf("Stack is Empty.\n");
        return -1;
    }
    
    stack->top--;
    return stack->arr[stack->top];
}

void printStack(Stack stack){
    printf("Stack top: %d\n", stack.top);
    printArray(stack.arr, stack.top);
}


int main(){
    Stack stack = {0, {}};
    for (int i = 0; i < 110; i++)
    {
        push(&stack,i);
    }
    printStack(stack);

    for (int i = 0; i < 110; i++)
    {
        pop(&stack);
    }
    
    

}




void printArray(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
    
}