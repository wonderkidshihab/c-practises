#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

char* nodeToString(struct Node* node){
    if (node == NULL)
    {
        char* str = malloc(5 * sizeof(char));
        sprintf(str, "Null");
        return str;
    } else{
        char* leftStr = nodeToString(node->left);
        char* rightStr = nodeToString(node->right);
        char* result = malloc(sizeof(char) * (strlen(leftStr) + strlen(rightStr)));
        sprintf(result, "Node(data: %d,left: %s,right: %s)", node->data, leftStr, rightStr);
        return result;
    }
}

int main(){
    struct Node left = {1, NULL, NULL};
    struct Node right = {2, NULL, NULL};
    
    struct Node root = {0, &left, &right};

    printf("Your Node is: %s\n", nodeToString(&root));
    return 0;
}
