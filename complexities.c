#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int sum(int n){
    return n * (n+1) /2;
}

int sum2(int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + 1;
    }
    return sum;
}

int sum3(int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            sum = sum + 1;
        }
        
    }
    return sum;
}

int sum4(int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                sum = sum + 1;
            }
            
        }
        
    }
    return sum;
}


int main(){
    int n, count;
    scanf("%d", &n);

    count = sum4(n);

    printf("For the number (n) = %d, the sum is : %d and total count: %d\n", n, sum(n), count);
}