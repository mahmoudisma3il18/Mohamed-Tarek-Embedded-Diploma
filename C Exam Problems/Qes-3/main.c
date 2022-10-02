#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

int getMinimumInsideList1(void){

    struct node *ptr = head;
    int minimum = ptr->data;

    while(ptr!=NULL){

        if(minimum >= ptr->data)
            minimum = ptr->data;

        ptr = ptr->next;
    }


    return minimum;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
