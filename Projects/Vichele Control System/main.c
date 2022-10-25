#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const char* Status [] = {"ON","OFF"};
int EngineStatusFlag = 1 ,AcStatus = 1,EngineTempControlStatus = 1;
char SecondChoice;
char TrafficLightColor;
int CarSpeed = 30 ,RoomTemp = 30,EngineTemp = 30;

void TakeSecondChoice();
void PrintResults ();
void PrintSecondMenu ();
void CheckFirstChoice(char FirstChoice);
void CheckSecondChoice();


void TakeSecondChoice()
{
    PrintSecondMenu();
    scanf(" %c",&SecondChoice);
    CheckSecondChoice();

}


void PrintResults ()
{
    if (CarSpeed == 30)
    {
        AcStatus = 0;
        RoomTemp = (RoomTemp * (5/4)) +1 ;
        EngineTempControlStatus = 0 ;
        EngineTemp = (EngineTemp * (5/4)) + 1 ;
    }

    printf("Engine Status : %s\n",Status[EngineStatusFlag]);
    printf("AC : %s\n",Status[AcStatus]);
    printf("Vechile Speed : %d\n",CarSpeed);
    printf("Room Temp : %d\n",RoomTemp);
    printf("Engine Controller Status : %s\n",Status[EngineTempControlStatus]);
    printf("Engine Temp : %d\n",EngineTemp);

}

void PrintSecondMenu ()
{
    printf("a. Turn off the engine \nb. Set the traffic light color. \nc. Set the room temperature (Temperature Sensor) \nd. Set the engine temperature (Engine Temperature Sensor)\n");

}


void CheckFirstChoice(char FirstChoice)
{
    if (FirstChoice == 'c' || FirstChoice == 'C')
    {
        printf("Turn off the vehicle engine\n");
                       exit(0);
    }

     if (FirstChoice == 'b' || FirstChoice == 'B')
     {
         printf("\nTurn off the vehicle engine\n\n");
                         main();
     }

}

void CheckSecondChoice()
{
    if (SecondChoice == 'a' || SecondChoice == 'A')
    {
        EngineStatusFlag = 0;
        main();
    }

    else if (SecondChoice == 'b' )
    {
        printf("Enter the traffic color : ");
        scanf(" %c",&TrafficLightColor);

        if(TrafficLightColor == 'G')
        {
            CarSpeed = 100;
        }

        else if (TrafficLightColor == 'O')
        {
            CarSpeed = 30;
        }

        else
        {
            CarSpeed = 0 ;
        }

        PrintResults();
        TakeSecondChoice();

    }


    else if (SecondChoice == 'c')
    {
        printf("Enter Room Temp : ");
        scanf("%d",&RoomTemp);

        if(RoomTemp <10 || RoomTemp > 30)
        {
            AcStatus = 0;
            RoomTemp = 20 ;
        }

        else
        {
            AcStatus = 1;
        }

        PrintResults();
        TakeSecondChoice();
    }

    else if (SecondChoice == 'd')
    {
        printf("Enter The Engine Temp : ");
        scanf("%d",&EngineTemp);

        if (EngineTemp < 100 || EngineTemp > 150)
        {
            EngineTempControlStatus = 0;
            EngineTemp = 125;
        }

        else
        {
            EngineTempControlStatus = 1 ;
        }

        PrintResults();
        TakeSecondChoice();
    }



}

int main()
{
    char FirstChoice;




     printf("Hello \nDo you want to ? \na.Turn on the vehicle engine\nb.Turn off the vehicle engine\nc.Quit the system\n");
     scanf(" %c",&FirstChoice);

     CheckFirstChoice(FirstChoice);

     EngineStatusFlag=0;



    TakeSecondChoice();




}
