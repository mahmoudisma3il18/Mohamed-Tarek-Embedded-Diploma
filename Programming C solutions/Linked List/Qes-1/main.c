#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *current = NULL;
struct node *head    = NULL;
struct node *prev    = NULL;

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

    while(ptr!=NULL){
        printf("\t%d\t>>",ptr->data);
        ptr = ptr->next;
    }

    printf("\tNULL\n");

}

void insertNodeAtPostion(int postion,int data){

    struct node *new_node = (struct node*)malloc(sizeof(struct node));


    int index =0;

    if(head == NULL){
        printf("List Empty \n");
        return;
    }

    if(postion == 0){
        new_node->data = data;
        new_node->next = head;

        head = new_node;
        return;
    }

    current = head;


    while(index < postion){
        prev = current;
        current = current->next;
        index++;
    }
    new_node->data = data;
    prev->next = new_node;
    new_node->next = current;




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

    //add node at the head
    insertNodeAtPostion(0,72);

    // print the list
    printList();

    //add node in position 5
    insertNodeAtPostion(5,60);

    // print the list
    printList();


}
