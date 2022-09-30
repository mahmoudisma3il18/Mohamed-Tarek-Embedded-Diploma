#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node *head    = NULL;
struct node *current = NULL;

void insertAtLast(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = NULL;

    if(head == NULL){
        head = link;
        return;
    }

    current = head;

    while(current->next != NULL)
        current = current->next;

    current->next = link;


}

void insertAtFirst(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = head;

    head = link;

}

void printList(void){

    struct node *ptr = head;

    printf("Head >>");

    while(ptr != NULL){
        printf("\t%d\t>>",ptr->data);
        ptr = ptr->next;
    }

    printf("\tNULL\n");

}


void sumOfList(void) {

    struct node *ptr = head;
    int sum = 0;

    while(ptr != NULL) {

        sum += ptr->data;
        ptr = ptr->next;
    }

    printf("Sum of list = %d\n",sum);

}

int main()
{

    insertAtLast(10);
    insertAtLast(13);
    insertAtFirst(5);
    printList();
    sumOfList();

    return 0;
}
