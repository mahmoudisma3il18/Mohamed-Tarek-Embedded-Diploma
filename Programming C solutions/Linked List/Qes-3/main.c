#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *current = NULL;
struct node *head    = NULL;

void insertAtFirst(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = head;

    head = link;

}

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

void printList(void){

    struct node *ptr = head;

    printf("HEAD >> \t");

    while(ptr != NULL){
        printf("\t%d\t>>",ptr->data);
        ptr = ptr->next;
    }

    printf("\tNULL\n");

}

int sizeOfList(void){

    struct node *ptr= head;
    int size = 0;

    while(ptr != NULL){
        size++;
        ptr = ptr->next;
    }

    return size;
}

void getFifthDataInList(void){

    struct node *ptr = head;


    if(head == NULL){
        printf("LIST IS EMPTY \n");
        return;
    }

    if(sizeOfList() == 1)
        printf("Data = %d\n",ptr->data);

    else if(sizeOfList()>=5){
        while(ptr->next->next->next->next->next != NULL)
            ptr = ptr->next;
        printf("Fifth value from end %d \n",ptr->data);
    }

    else
        printf("List less than 5 elemnts\n");


}

int main()
{

    insertAtLast(10);
    insertAtLast(22);
    insertAtLast(13);
    insertAtLast(88);
    insertAtLast(101);
    insertAtLast(53);
    printList();
    getFifthDataInList();
}
