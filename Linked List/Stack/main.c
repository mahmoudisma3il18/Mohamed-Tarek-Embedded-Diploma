#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int data){

    struct node *link = (struct node*)malloc(sizeof(struct node));

    link->data = data;
    link->next = top;

    top = link;
}

void pop(int *data){

    struct node *delted_node = top;

    if(top == NULL)
    {
        return;
    }


    *data = delted_node->data;
    top = delted_node->next;

    free(delted_node);

}

int peek(void){
    return top->data;
}

void printList(void){

    struct node *ptr = top;

    printf("Top of stack\n");

    while(ptr != NULL){
        printf("\t%d\n",ptr->data);
        ptr = ptr->next;
    }

    printf("End of stack\n");


}

int main()
{
    int x;
    int *data = &x;
    push(10);

    // print the list
    printList();

    push(20);

    // print the list
    printList();

    push(30);

    // print the list
    printList();

    printf("The value of the Top node : %d\n",peek());

    push(1);

    // print the list
    printList();

    push(40);

    // print the list
    printList();

    push(56);

    // print the list
    printList();

    pop(data);

    // print the list
    printList();

    printf("The value of the Top node : %d\n",peek());

    pop(data);

    // print the list
    printList();

    printf("The value of the Top node : %d\n",peek());
    return 0;

}
