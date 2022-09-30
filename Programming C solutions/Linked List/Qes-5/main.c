#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next ;


};

struct node *head  = NULL;
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


    printf("Head >>\t");

    while(ptr != NULL){
        printf("\t%d\t>>",ptr->data);
        ptr = ptr->next;
    }

    printf("\tNULL\n");

}


void maxOfList(void){

    struct node *ptr = head ;

    int max = 0;

    while(ptr != NULL){

        if(ptr->data > max)
            max = ptr->data;

        ptr = ptr->next;
    }

    printf("Max of list : %d\n",max);
}

int main()
{
    insertAtFirst(10);
    insertAtFirst(55);
    insertAtLast(99);
    printList();
    maxOfList();
    return 0;
}
