#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Node{
    int val;
    struct Node *left, *right;
};
struct Node *newNode(int val){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> val = val;
    temp -> left =NULL;
    temp -> right = NULL;
    return temp;
}
struct Node *insert(struct Node *root, int key) {
    if(root == NULL) 
        return newNode(key);
    if(key < root -> val)
        root -> left = insert(root -> left, key);
    else
        root -> right = insert(root -> right, key);
    return root;
}
struct Node *delete(struct Node *root, int key){
    if(root == NULL) 
        return root;
    if(key < root -> val)
        root -> left = delete(root -> left, key);
    else if(key > root -> val)
        root -> right = delete(root -> right, key);
    else{
        if (root -> left == NULL){
            struct Node *temp = root -> right;
            return temp;
        } 
        else if (root -> right == NULL) {
            struct Node *temp = root -> left;
            return temp;
        }
    }
}
void print(struct Node *root){
    if(root != NULL){
        print(root -> left);
        printf("%d ", root -> val);
        print(root -> right);
    }
}
int main(){
    struct Node *root = NULL;
    int x, y;
    while(true){
        printf("Press 1 to insert node, Press 2 to delete node, Press 3 to print nodes, Press 0 to exit\n");
        scanf("%d", &x);
        if(x == 1){
            printf("Enter value of node to be added: ");
            scanf("%d", &y);
            insert(root, y);
        }
        else if(x == 2){
            printf("Enter value of node to be deleted: ");
            scanf("%d", &y);
            delete(root, y);
        }
        else if(x == 3){
            print(root);
        }
        else if(x == 0)
            break;
        else
            printf("Invalid input\n");
    }
}