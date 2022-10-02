#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *current = NULL;

void Enqueue(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->next = NULL;
    link->data = data;

    if(front == NULL){
        front = link;
        return;
    }

    current = front;

    while(current->next != NULL)
        current = current->next;

    current->next = link;

}

void Dequeue(void){

    struct node *deleted_node = front;

    front = deleted_node->next;

    free(deleted_node);

}

int Peek(void){

    return front->data;
}

void printList(void){

    struct node *ptr = front;

    printf("Front : \n");

    while(ptr != NULL){

        printf("\t%d\n",ptr->data);
        ptr = ptr->next;

    }

}

int main()
{
    Enqueue(10);

    // print the list
    printList();

    Enqueue(20);

    // print the list
    printList();

    Enqueue(30);

    // print the list
    printList();

    printf("The value of the Front(Head) node : %d\n",Peek());

    Enqueue(1);

    // print the list
    printList();

    Enqueue(40);

    // print the list
    printList();

    Enqueue(56);

    // print the list
    printList();

    Dequeue();

    // print the list
    printList();

    printf("The value of the Front(Head) node : %d\n",Peek());

    Dequeue();

    // print the list
    printList();

    printf("The value of the Front(Head) node : %d\n",Peek());
    return 0;
    return 0;
}
