#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *next;
};
Node *createNode(int data, Node *next);
void printNode(Node *head);
Node *prepend(Node *head, int data);
Node *append(Node *head, int data);
int count(Node *head);
Node *search(Node *head, int data);
Node *removeNode(Node *head, Node *node);
void insert(Node *node, int data);

int main(){
    Node *head = createNode(0, NULL);
    while (1==1) {
        printf("Linked List:\n");
        printNode(head);
        printf(
            "\n\n1) PrependItem\n"
            "2) AppendItem\n"
            "3) Count Items\n"
            "4) Search Item\n"
            "5) Remove Item\n"
            );

        int result;
        scanf("%d", &result);
        if (result == 1 || result == 2 || result == 4 || result == 5) {
            printf("Please enter a number:\n");
            int data;
            scanf("%d", &data);
            printf("\n\n\n\n\n");
            switch (result)
            {
            case 1:
            {
                head = prepend(head, data);
                break;
            }
            case 2: 
            {
                append(head, data);
                break;
            }
            case 4:
                {
                    Node *searchedItem = search(head, data);
                    printf("Searched Node: ");
                    printNode(searchedItem);
                    break;
                }
            case 5:
                {
                    Node *searchedItem = search(head, data);
                    removeNode(head, searchedItem);
                    break;
                }
            default:
                {
                    printf("Invalid Option.\n");
                    break;
                }
            }
        } else if(result == 3){
            int c = count(head);
            printf("Total number of item is: %d\n", c);
        } else {
            printf("Invalid Option.\n");
            continue;
        }
    }
    
    return 0;
}


Node *createNode(int data, Node *next){
    Node *node = (Node *) malloc(sizeof(Node));
    if(node == NULL){
        printf("Couldn't create the node.\n");
        exit(1);
    }

    node->data = data;
    node->next = next;
    return node;
}

void printNode(Node *head){
    Node *currentNode = head;
     while (currentNode != NULL){
        printf("%d,",currentNode->data);
        currentNode = currentNode->next;
     }
    printf("\n");
}

Node *prepend(Node *head, int data){
    Node *new = createNode(data, head);
    return new;
}

Node *append(Node *head, int data){
    Node *new = createNode(data, NULL);
    if (head == NULL) {
        return new;
    }
    
    Node *currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = new;
    return head;   
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

Node *removeNode(Node *head, Node *node){
    if(node == head){
        head = node->next;
        free(node);
        return head;
    }

    Node *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->next == node) {
            break;
        }
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        return head;
    }

    currentNode->next = node->next;
    free(node);

    return head;
    
}



void insert(Node *node, int data) {
    Node *new = createNode(data, node->next);
    node->next = new;
}

Node *reverse(Node *head){
    Node *current = head;
    while (current != NULL)
    {
        current = current->next;
    }
    
}