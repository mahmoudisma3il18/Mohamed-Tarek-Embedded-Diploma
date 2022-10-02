#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;

};

struct node *current = NULL;
struct node *head    = NULL;

void insertAtLast(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = NULL;

    if(head == NULL){
        head = link;
        return;
    }

    current = head;
    while(current->next != NULL){
        current = current->next;
    }

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
        printf("\t%d\t>>",(*ptr).data);
        ptr = ptr->next;
    }
    printf(" Null\n");
}


void updateItemInTheList(int old,int new){

    struct node *ptr = head;

    if(head == NULL)
        printf("List is empty\n");

    while(ptr != NULL){

        if(ptr->data == old){
            ptr->data = new;
            return;
        }
        ptr = ptr->next;
    }

    printf("Item doesnt exist\n");

}




int main()
{
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(1);
    insertAtLast(40);
    insertAtLast(56);

    // print the list
    printList();

    // update item 1 in the list with a new value 50
    updateItemInTheList(1,50);

    // print the list
    printList();

    // update item 100 in the list with a new value 50
    updateItemInTheList(100,50);

    // update item 56 in the list with a new value 50
    updateItemInTheList(56,50);

    // print the list
    printList();

    return 0;
}
