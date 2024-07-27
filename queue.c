#include <stdio.h>
#define QUEUE_MAX 11 // There will be ten item at max
void printArray(int arr[], int length);

typedef struct 
{
    int head;
    int tail;
    int arr[QUEUE_MAX];
} Queue;

void enqueue(Queue *queue, int item);
int dequeue(Queue *queue);

int main(){
    Queue queue ={0,0,{}};
    for (int i = 1; i < 16; i++)
    {
        enqueue(&queue, i * 10);
        int len = sizeof(queue.arr)/sizeof(queue.arr[0]);
        printArray(queue.arr, len);
    }
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    for (int i = 1; i < 6; i++)
    {
        enqueue(&queue, i );
        int len = sizeof(queue.arr)/sizeof(queue.arr[0]);
        printArray(queue.arr, len);
    }
    
}

void enqueue(Queue *queue, int item){
    if ((queue->tail + 1) % QUEUE_MAX == queue->head)
    {
        printf("Queue is full.\n");
        return;
    }
    
    queue->arr[queue->tail] = item;
    queue->tail = (queue->tail+1) % QUEUE_MAX;
}

int dequeue(Queue *queue){
    if (queue->tail == queue->head)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = queue->arr[queue->head];
    queue->head = (queue->head + 1) % QUEUE_MAX;
    return item;
    
}


void printArray(int arr[], int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
    
}