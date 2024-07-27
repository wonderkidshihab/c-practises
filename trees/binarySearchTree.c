#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *left;
    Node *right;
    Node *parent;
};

Node *createNode(int data);
void addLeft(Node *root, Node *left);
void addRight(Node *root, Node *right);
Node *bstInsert(Node *root, Node *child);
Node *createTree(int arr[], int length);
void preOrder(Node *tree);
void postOrder(Node *tree);
void inOrder(Node *tree);
Node *search(Node *root, int item);
Node *bstMinumum(Node *root);
Node *bstTransplant(Node *root, Node *current, Node *node);
Node *bstDelete(Node *root, Node *node);
int showMenu();
Node *processChoice(Node *root, int choice);





int main(){
    Node *root = createNode(0);
    while (1==1)
    {
        printf("\n\n\nCurrent BST (In Order):");
        inOrder(root);
        int choice = showMenu();
        if (choice != 0)
        {
            root = processChoice(root, choice);
        }
        
    }
    return 0;
}






Node *createNode(int data){
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL)
    {
        printf("Could not create new node with data: %d\n", data);
        exit(1);
    }

    new->data = data;
    return new;
}

Node *bstInsert(Node *root, Node *child){
    Node *parentNode, *currentNode;
    if (root == NULL)
    {
        root = child;
        return root;
    }
    parentNode = NULL;
    currentNode = root;
    while (currentNode != NULL)
    {
        parentNode = currentNode;
        if (child->data < currentNode->data)
        {
            currentNode = currentNode->left;
        } else{
            currentNode = currentNode->right;
        }
    }
    if (child->data < parentNode->data)
    {
        addLeft(parentNode, child);
    } else{
        addRight(parentNode, child);
    }
    return root;
}


void addLeft(Node *root, Node *left){
    root->left = left;
    if (left != NULL)
    {
        left->parent = root;
    }
}
void addRight(Node *root, Node *right){
    root->right = right;
    if (right != NULL)
    {
        right->parent = root;
    }   
}

Node *createTree(int arr[], int length){
    Node *root, *child;
    root = createNode(arr[0]);
    for (int i = 1; i < length; i++)
    {
        child = createNode(arr[i]);
        root = bstInsert(root, child);
    }
    return root;
}


void preOrder(Node *tree){
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
    return;
}

void postOrder(Node *tree){
    if(tree != NULL){
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d\t", tree->data);
    }
    return;
}

void inOrder(Node *tree){
    if (tree != NULL)
    {
        inOrder(tree->left);
        printf("%d  ", tree->data);
        inOrder(tree->right);
    }
    return;
}


Node *search(Node *root, int item){
    Node *node = root;
    while (node != NULL)
    {
        if (node->data ==item)
        {
            return node;
        }

        if (item < node->data)
        {
            node = node->left;
        } else {
            node = node-> right;
        }
    }
    return node;
}

Node *bstMinumum(Node *root){
    Node *node = root;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}


Node *bstTransplant(Node *root, Node *current, Node *node){
    if (current == root)
    {
        root = node;
    } else if(current == current->parent->left){
        addLeft(current->parent, node);
    } else{
        addRight(current->parent, node);
    }
    return root;
}

Node *bstDelete(Node *root, Node *node){
    Node *smallestNode;

    if (node->left == NULL)
    {
        node = bstTransplant(root, node, node->right);
    } else if(node->right == NULL){
        node = bstTransplant(root, node, node->left);
    } else{
        smallestNode = bstMinumum(node->right);
        if (smallestNode->parent != node)
        {
            root = bstTransplant(root, smallestNode, smallestNode->right);
            addRight(smallestNode, node->right);
        }

        root = bstTransplant(root, node, smallestNode);
        addLeft(smallestNode, node->left);
        
    }
    free(node);

    return root;
    
}


int showMenu(){
    // Show user the prompt to choose their action
    printf(
        "\n\n\n\nEnter a number to take action:\n\n"
        "1) Insert new item.\n"
        "2) Delete an item.\n"
        "3) Count all Items.\n"
        "4) Search an item.\n"
        );
    // Take the user input.
    int choice;
    scanf("%d", &choice);

    // Checking the choice's validity.
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
    {
        return choice;
    }
    // Invalid user input.
    return 0;
}
Node *processChoice(Node *root, int choice){
    switch (choice)
    {
    case 1: {
            printf("Please enter a number: ");
            int number;
            scanf("%d", &number);
            Node *new = createNode(number);
            root = bstInsert(root, new);
            printf("The number (%d) has been added to BST.\n", number);
            break;
        }
    case 2:{
            printf("Please enter the number you want to delete:");
            int number;
            scanf("%d", &number);
            Node *find = search(root, number);
            if (find == NULL)
            {
                printf("Could not find the item (%d)\n", number);
                break;
            }
            root = bstDelete(root, find);
            printf("The number (%d) has been deleted from BST.\n", number);
            break;
        }
    default:
        break;
    }
    return root;
}