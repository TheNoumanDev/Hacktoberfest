// Write a program to calculate the average of 10 numbers. Use array for storing 10 numbers.
//Name: Ahmad Bin Abdul Jabbar

//Username: Ahmad Bin Abdul JabBr

//Favorite Language: C language
#include<stdio.h>

int main()
{
    int num[10];
    int total;
    printf("Enter 10 Numbers: \n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d",&num[i]);
        total = total + num[i];
    }

    int avg = total / 10;
    printf("The average of 10 numbers entered is %d: ",avg);
    getch();
}
