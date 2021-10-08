#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{  
    int val;  
    struct node *next;
};
struct node *head, *front, *rear; 
void push(int val){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));   
    if(head == NULL){
        ptr -> val = val;
        ptr -> next = NULL;
        head = ptr;
    }
    else{
        ptr -> val = val;
        ptr -> next = head;
        head = ptr;
    }
}
void pop()  
{
    if(head == NULL)
        return;
    int x = head -> val;
    head = head -> next;
    printf("Deleted element is: %d\n", x);     
}
void enqueue(int val){
    struct node *ptr = (struct node *) malloc (sizeof(struct node));  
    ptr -> val = val;  
    if(front == NULL){
        front = ptr;  
        rear = ptr;   
        front -> next = NULL;  
        rear -> next = NULL;  
    }
    else{
        rear -> next = ptr;  
        rear = ptr;  
        rear -> next = NULL;  
    }
}
void dequeue(){
    if(front == NULL)
        return;
    int x = front -> val;
    front = front -> next;
    printf("Deleted element is: %d\n", x);
}
void print(){
    struct node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = front;
    if(ptr1 == NULL)
        printf("Stack is empty\n");
    else{
        printf("Stack elements:\n");
        while(ptr1 != NULL){
            printf("%d\n", ptr1 -> val);
            ptr1 = ptr1 -> next;
        }
    }
    if(ptr2 == NULL)
        printf("Queue is empty\n");
    else{
        printf("Queue elements:\n");
        while(ptr2 != NULL){
            printf("%d\n", ptr2 -> val);
            ptr2 = ptr2 -> next;
        }
    }
}
int main(){
    int x, y;
    while(true){
        printf("Press 1 to push, Press 2 enqueue, Press 3 to pop, Press 4 to dequeue, Press 5 to print, Press 0 to exit\n");
        scanf("%d", &x);
        if(x == 1){
            printf("Enter element to be inserted: ");
            scanf("%d", &y);
            push(y);
        }
        else if(x == 2){
            printf("Enter element to be inserted: ");
            scanf("%d", &y);
            enqueue(y);
        }
        else if(x == 3)
            pop();
        else if(x == 4)
            dequeue();
        else if(x == 5)
            print();
        else if(x == 0)
            break;
        else
            printf("Invalid input\n");
    }
}