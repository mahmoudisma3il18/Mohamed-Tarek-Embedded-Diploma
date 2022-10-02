#include <stdio.h>

int findMostOccuring(int Array_Size,int *Array){

    int max_occurence = 0,max_number = 0,count = 0;


    for(int i = 0 ; i <Array_Size - 1;i++){ // Sort to the last before element

        if(*(Array + i) == *(Array + i +1)){
            count++; // lw la'eet rkm ey b3du zy b3d +1

            if(count>=max_occurence){ // hena lw l counetr tl3 akbr mn l max
                max_occurence = count;
                max_number =*(Array + i);
            }
        }
        else
            count = 0; // lw laa khly l counter b zero;
    }
    return max_number;
}

int main()
{
    int Array[13] = {1,2,2,3,3,3,3,4,4,4,4,3,3};
    printf("Max number occurenece : %d\n",findMostOccuring(13,Array));
    return 0;
}
