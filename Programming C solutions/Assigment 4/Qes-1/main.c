#include <stdio.h>
#include <string.h>


struct Student {


    char name[20];
    int marks;

};

int main()
{

    struct Student student1;
    strcpy(student1.name,"Mahmoud");
    student1.marks = 60;


    printf("Student Name : %s\n",student1.name);
    printf("Student Marks : %d\n",student1.marks);
    return 0;
}
