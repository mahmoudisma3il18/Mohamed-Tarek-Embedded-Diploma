#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
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

    printf("HEAD >>\t");

    while(ptr!= NULL){
        printf("\t%d\t>>",ptr->data);
        ptr = ptr->next;
    }

    printf("\tNULL\n");

}

int sizeOfList(void){

    int size = 0;

    struct node *ptr = head;



    while(ptr!= NULL){
       size++;
        ptr = ptr->next;
    }

return size;

}

void getMiddleNode(void){

    struct node *ptr1 = head;
    struct node *ptr2 = head;
    int steps = 0 ;

    if(head == NULL){
        printf("List is empty \n");
        return;
    }

    if(sizeOfList() == 1){
        printf("Only 1 node : %d \n",ptr1->data);
        return;
    }

    while(ptr1->next != NULL){

        steps++;
        ptr1 = ptr1->next;

        if(steps == 2){
            ptr2 = ptr2->next;
            steps = 0 ;
        }

    }

    printf("Middle node : %d",ptr2->data);



}

int main()
{
    insertAtLast(10);
    insertAtLast(20);
    insertAtLast(22);
    insertAtLast(15);
    insertAtLast(101);
    getMiddleNode();
    return 0;
}

