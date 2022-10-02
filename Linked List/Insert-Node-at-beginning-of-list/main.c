#include <stdio.h>
#include <stdlib.h>


struct node {

    int data;
    struct node *next;

};

struct node *head = NULL;

void insertAtFirst(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));
    link->data = data;
    link->next = head;

    head = link;

}

void printList(void){

    struct node *ptr = head;


    printf("Head : ");

    while(ptr != NULL) {
        printf("%d >> ",ptr->data);
        ptr = ptr->next;
    }

    printf("End of list");



}


int main()
{
    insertAtFirst(10);
    insertAtFirst(20);
    insertAtFirst(30);
    insertAtFirst(1);
    insertAtFirst(40);
    insertAtFirst(56);

    // print the list
    printList();
    return 0;
}



