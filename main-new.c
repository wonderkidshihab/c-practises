#include <stdio.h>

void printArray(int arr[], int length);
int arrayLength(int arr[]);
void bubbleSortArray(int* arr, int length);


int main(){
    int arr[] = {1,2,5,23,6,34,734,324,45,3423,43};
    int length = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, length);
    bubbleSortArray(arr, length);
    printArray(arr, length);
    return 0;
}


void printArray(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
}

// int arrayLength(int* arr){
//     return sizeof(&arr) / sizeof(arr[0]);
// }


void bubbleSortArray(int* arr, int length){
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length -i -1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}