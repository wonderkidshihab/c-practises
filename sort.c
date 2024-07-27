#include <stdio.h>

void printArray(int arr[], int length);
void insertionSort(int arr[], int length);

int main(int argc, char const *argv[])
{
    int arr[] = {4,3,65,2,7,5,4};
    int length = sizeof(arr)/ sizeof(arr[0]);
    printArray(arr, length);
    insertionSort(arr, length);
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

void insertionSort(int arr[], int length){
    for (int i = 1; i < length; i++)
    {
        int item = arr[i];

        int j = i -1;
        
        while (j >= 0 && arr[j] > item)
        {
            arr[j+1] = arr[j];
            j--;
        }
        

        arr[j+1] = item;
    }
    
}