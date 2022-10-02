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
        head = link ;
        return;
    }

    current = head;

    while(current->next != NULL)
        current = current -> next;

    current->next = link;


}

void insertAtFirst(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->data = data;
    link->next = head;

    head = link;




}




void printList(void) {

    struct node *ptr = head;
    printf("Head >> ");
    while(ptr != NULL) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }


}

void sizeOfList(void) {

    int size = 0;

    if(head == NULL) {
        printf("Size of list : %d\n",size);
        return;
    }

    current = head;

    while(current != NULL){
        size++;
        current = current->next;
    }

    printf("Size of list : %d\n",size);



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

    // get the size of the list
    sizeOfList();

    return 0;
}
