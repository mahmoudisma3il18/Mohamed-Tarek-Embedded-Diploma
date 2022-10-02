#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;

};


struct node *head = NULL;
struct node *current = NULL;

void insertAtLast(int data) {

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = NULL;

    if(head == NULL){
        head = link;
        return;
    }

    current = head ;

    while(current->next != NULL)
        current = current->next;

    current->next = link;


}

void printList(void) {

    struct node *ptr = head;

    printf("Head >> ");

    while(ptr != NULL) {
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }

    printf("End");


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
    return 0;
}
