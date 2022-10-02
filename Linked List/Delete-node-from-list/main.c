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

void insertAtFirst(int data) {

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = head;

    head = link;

}

void printList(void) {

    struct node *ptr = head;

    printf("Head >>");

    while(ptr != NULL){
        printf("\t%d\t>>",ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");

}


void deleteNodeFromList(int data){

    int index = 0;

    struct node *deleted_node = NULL;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->data == data){
        deleted_node = head;
        head = head->next;
        printf("%d is found at postion %d \n",data,index);
        free(deleted_node);
        return;
    }

    index++;

    current = head->next;
    prev = head;

    while(current != NULL){

        if(current->data == data){

            deleted_node = current;
            prev->next = current->next;
            printf("%d is delted at postion %d \n",index,data);
            free(deleted_node);
            return;

        }



        index++;
        prev = current;
        current = current->next;
    }


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

    //remove the head node
    deleteNodeFromList(10);
    // print the list
    printList();

    //remove the node which contains 1
    deleteNodeFromList(1);
    // print the list
    printList();

    //remove the tail node
    deleteNodeFromList(56);
    // print the list
    printList();
}
