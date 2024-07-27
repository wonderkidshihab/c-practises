#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *prev;
    Node *next;
};
Node *createNode(int data, Node *prev, Node *next);
Node *prepend(Node *head, int data);
Node *append(Node *head, int item);
void insert(Node *node, int data);
void printNode(Node *node);
int count(Node *head);
Node *search(Node *head, int data);
Node *removeNode(Node *head,Node *node);

int main(){
    Node *head = createNode(10, NULL, NULL);
    for (int i = 2; i <= 10; i++)
    {
        append(head, i*10);
    }
    printNode(head);
    Node *s = search(head, 10);
    head = removeNode(head, s);
    printNode(head);

    

    
    return 0;
}



Node *createNode(int data, Node *prev, Node *next){
    Node *node = (Node *) malloc(sizeof(Node));
    if(node == NULL){
        printf("Couldn't assign memory for new Node.");
        exit(1);
    }
    node->data = data;
    node->prev = prev;
    node->next = next;
    return node;
}

Node *prepend(Node *head, int data){
    Node *new = createNode(data, NULL, head);
    new->next->prev = new;
    return new;
}

Node *append(Node *head, int item){
    Node *new = createNode(item, NULL, NULL);
    
    if (head == NULL) {
        return new;
    }

    Node *currentNode = head;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = new;
    new->prev = currentNode;

    return head;
}

void insert(Node *node, int data){
    Node *new = createNode(data, node, node->next);
    node->next = new;
    new->next->prev = new;
}

void printNode(Node *node){
    if (node == NULL)
    {
        printf("The node is Null.\n");
        
    }
    
    Node *currentNode = node;
    printf("Current Node datas: ");
    while (currentNode != NULL)
    {
        printf("%d,", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}


int count(Node *head){
    int c = 0;
    Node *currentNode = head;
    while (currentNode != NULL) {
        currentNode = currentNode->next;
        c++;
    }
    return c;
}
Node *search(Node *head, int data){
    Node *currentNode = head;
    Node *result;
    while (currentNode != NULL) {
        if(currentNode->data == data) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    printf("Can not find the searched Item.\n");
    return head;
}

Node *removeNode(Node *head,Node *node){
    if (node == head)
    {
        head = node->next;
        head->prev = NULL;
        free(node);
        return head;
    }
    
    node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);
    return head;
}