#include <stdio.h>

int linearSearch(int arr[], int n, int searchingFor);
int binarySearch(int arr[], int n, int searchingFor);

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,12,23,34,54,65,76,87,98};
    int n = 23;
    int searchingFor = 34;
    int searched = binarySearch(arr, n, searchingFor);
    printf("you are searching for: %d, after search the result is: %d\n", searchingFor, searched);
    return 0;
    
}

int linearSearch(int arr[], int n, int searchingFor){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == searchingFor)
        {
            return arr[i];
        }
        
    }
    return -1;
    
}


int binarySearch(int arr[], int n, int searchingFor){
    int left, right, mid;
    left = 0;
    right = n-1;
    while(left <= right){
        // mid = (left + right) / 2;
        mid = left + (right - left) /2;
        if(arr[mid] == searchingFor){
            return mid;
        }
        if(arr[mid] < searchingFor){
            left = mid +1;
        } else{
            right = mid -1;
        }
    }
    return -1;
}