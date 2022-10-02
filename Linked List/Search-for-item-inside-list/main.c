#include <stdio.h>
#include <stdlib.h>

struct node{

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

    while(current->next != NULL)
        current = current->next;

    current->next = link;

}


void insertAtFirst(int data){

    struct node *link=(struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = head;

    head = link;



}

void printList(void){

    struct node *ptr = head;

    printf("Head >> ");
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }

    printf(">> NULL\n");

}

void findItemInTheList(int data){

    struct node *ptr = head;
    int index = 0;

    if(head == NULL){
        printf("List is empty\n");
    }

    while(ptr != NULL){

        if(ptr->data == data){
            printf("Number %d is found at postion %d \n",data,index);
            return;
        }
        ptr = ptr->next;
        index++;
    }

    printf("Item doesnt exist in list \n");

}


int main()
{

    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(30);
    insertAtLast(1);
    insertAtLast(40);
    insertAtFirst(56);

    // print the list
    printList();

    // find item 1 in the list
    findItemInTheList(1);

    // find item 100 in the list
    findItemInTheList(100);

    // find item 56 in the list
    findItemInTheList(56);
}
