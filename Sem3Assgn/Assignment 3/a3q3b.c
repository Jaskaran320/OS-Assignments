#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
};
int height(struct Node *node){
    if(node == NULL)
        return 0;
    return node -> height;
}
int max(int x, int y){
    return (x > y ) ? x : y;
}
struct Node *newNode(int val){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    node -> height = 1;
    return (node);
}
struct Node *right(struct Node *node){
    struct Node *node1 = node -> left;
    struct Node *temp = node1 -> right;
    node1 -> right = node;
    node -> left = temp;
    node -> height = 1 + max(height(node -> left), height(node -> right));
    node1 -> height = 1 + max(height(node1 -> left), height(node1 -> right));
    return node1;
}
struct Node *left(struct Node *node){
    struct Node *node1 = node -> right;
    struct Node *temp = node1 -> left;
    node1 -> left = node;
    node -> right = temp;
    node -> height = 1 + max(height(node -> left), height(node -> right));
    node1 -> height = 1 + max(height(node1 -> left), height(node1 -> right));
    return node1;
}
int balance(struct Node *node){
  if(node == NULL)
    return 0;
  return height(node -> left) - height(node -> right);
}
struct Node *insert(struct Node *node, int val){
    if(node == NULL)
        return (newNode(val));
    if(val < node -> val)
        node -> left = insert(node -> left, val);
    else if(val > node -> val)
        node -> right = insert(node -> right, val);
    else
        return node;
    node -> height = 1 + max(height(node -> left), height(node -> right));
    int bal = balance(node);
    if(bal > 1 && val < node -> left -> val)
        return right(node);
    if(bal < -1 && val > node -> right -> val)
        return left(node);
    if(bal > 1 && val > node -> left -> val){
        node -> left = left(node -> left);
        return right(node);
    }
    if(bal < -1 && val < node -> right -> val){
        node -> right = right(node -> right);
        return left(node);
    }
    return node;
}
struct Node *delete(struct Node *root, int val){
    if(root == NULL)
        return root;
    if(val < root -> val)
        root -> left = delete(root -> left, val);
    else if(val > root -> val)
        root -> right = delete(root -> right, val);
    else{
        if ((root -> left == NULL) || (root -> right == NULL)){
            struct Node *temp = root -> left ? root -> left : root -> right;
            if (temp == NULL){
                temp = root;
                root = NULL;
            } 
            else
                *root = *temp;
        } 
        else{
            struct Node *temp, *cur = root -> right;
            while (cur -> left != NULL)
                cur = cur -> left;
            *temp = *cur;
            root -> val = temp -> val;
            root -> right = delete(root -> right, temp -> val);
        }
    } 
    if(root == NULL)
        return root;
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int bal = balance(root);
    if(bal > 1 && balance(root -> left) >= 0)
        return right(root);
    if(bal < -1 && balance(root -> right) <= 0)
        return left(root);
    if(bal > 1 && balance(root -> left) < 0){
        root -> left = left(root -> left);
        return right(root);
    }
    if(bal < -1 && balance(root -> right) > 0){
        root -> right = right(root -> right);
        return left(root);
    }
    return root;
}
void print(struct Node *root) {
    if(root == NULL)
        return;
    printf("%d\n", root -> val);
    print(root -> left);
    print(root -> right);
}
int main(){
    int x, y;
    struct Node* root = NULL;
    while(true){
        printf("Press 1 to insert node, Press 2 to delete nodes, Press 3 to print nodes, Press 0 to exit\n");
        scanf("%d", &x);
        if(x == 1){
            printf("Enter value of node to be added: ");
            scanf("%d", &y);
            root = insert(root, y);
        }
        else if(x == 2){
            printf("Enter value of node to be deleted: ");
            scanf("%d", &y);
            root = delete(root, y);
        }
        else if(x == 3){
            print(root);
        }
        else if(x == 0)
            break;
        else
            printf("Invalid Input\n");
    }
}