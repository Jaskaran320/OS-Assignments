#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct Stud{
	int roll;
	char name[50];
	int year;
	char prog[50];
	struct Stud *next;
}*head;
void insert(int roll, char* name, int year, char* prog){
    struct Stud* stud = (struct Stud *) malloc(sizeof(struct Stud));
    stud -> roll = roll;
    strcpy(stud -> name, name);
    stud -> year = year;
    strcpy(stud -> prog, prog);
    stud -> next = NULL;
    if(head == NULL)
        head = stud;
    else{
        struct Stud* cur = head;
        while(cur -> next != NULL)
            cur = cur ->next;
        cur -> next = stud;
    }
}
void delete(int roll){
    struct Stud *temp = head, *prev;
    while(temp != NULL){
        if(temp -> roll == roll){
            if(temp == head)
                head = head -> next;
            else
                prev -> next = temp -> next;
            return;
        }
        prev = temp;
        temp = temp -> next;
    }
}
void search(int roll)
{
    struct Stud* temp = head;
	while(temp!=NULL){
		if(temp -> roll == roll){
			printf("Roll Number: %d\n", temp -> roll);
			printf("Name: %s\n", temp -> name);
            printf("Year of joining: %d\n", temp -> year);
			printf("Program: %s\n", temp -> prog);
			return;
		}
		temp = temp->next;
	}
	printf("Record of roll number %d not found \n");
}
void printall()
{
    struct Stud* temp = head;
	while(temp!=NULL){
		printf("Roll Number: %d\n", temp -> roll);
		printf("Name: %s\n", temp -> name);
        printf("Year: %d\n", temp -> year);
		printf("Program: %s\n\n", temp -> prog);
		temp = temp->next;
	}
}
int main(){
    head = NULL;
    int roll, year, x;
    char name[50], prog[50];
    while(true){
        printf("\nPress 1 to insert new record\nPress 2 to delete record\nPress 3 to search for a record\nPress 4 to print all records\nPress 0 to exit\n");
        scanf("%d", &x);
        if(x == 1){
            printf("Enter roll number: ");
            scanf("%d", &roll);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Year of joining: ");
            scanf("%d", &year);
            printf("Enter Program: ");
            scanf("%s", prog);
            insert(roll, name, year, prog);
        }
        else if(x == 2){
            printf("Enter roll number of record to be deleted: ");
            scanf("%d", &roll);
            delete(roll);
        }
        else if(x == 3){
            printf("Enter roll number of record to be searched: ");
            scanf("%d", &roll);
            search(roll);
        }
        else if(x == 4)
            printall();
        else if(x == 0)
            break;
        else
            printf("Invalid input\n");
    }
    return 0;
}