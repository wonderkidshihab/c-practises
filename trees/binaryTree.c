#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data);
void addLeft(Node *node, Node *left);
void addRight(Node *node, Node *right);
Node *createTree();
void preOrder(Node *tree);
void postOrder(Node *tree);
void inOrder(Node *tree);

int main(){
    Node *root = createTree();
    inOrder(root);

}

Node *createNode(int dat){
    Node *n = (Node *) malloc(sizeof(Node));
    if (n == NULL)
    {
        printf("Could not create node with Data: %d\n", dat);
        exit(1);
    }

    n->data = dat;
    return n;
}

void addLeft(Node *root, Node *left){
    root->left = left;
}

void addRight(Node *root, Node *right){
    root->right = right;
}

Node *createTree(){
    Node *two = createNode(2);
    Node *seven = createNode(7);
    Node *nine = createNode(9);
    addLeft(two, seven);
    addRight(two, nine);
    Node *one = createNode(1);
    Node *six = createNode(6);
    Node *eight = createNode(8);
    addLeft(seven, one);
    addRight(seven, six);
    addRight(nine, eight);
    Node *five = createNode(5);
    Node *ten = createNode(10);
    Node *three = createNode(3);
    Node *four = createNode(4);
    addLeft(six, five);
    addRight(six, ten);
    addLeft(eight, three);
    addRight(eight, four);
    return two;
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
        printf("%d\t", tree->data);
        inOrder(tree->right);
    }
    return;
}