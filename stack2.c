#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isBalanced(char input[]);

int main(){
    char input[100];
    scanf("%s", &input);

    if (isBalanced(input))
    {
        printf("The characters are balanced");
    } else{
        printf("The characters are not balanced");
    }
    
}

bool isBalanced(char input[]){
    char stack[100], last_char;
    int top, i, len;
    top = 0;
    len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            stack[top] = input[i];
            top++;
        } else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
        {
            if (top == 0)
            {
                printf("Stack is Empty");
                return 0;
            } 
            top--;
            last_char = stack[top];
            if ((input[i] == ')' && stack[top] != '(') || (input[i] == '}' && stack[top] != '{') || (input[i] == ']' && stack[top] != '['))
            {
                return 0;
            }
        }
    }
    if (top ==0)
    {
        return 1;
    } else {
        return 0;
    }
    
}