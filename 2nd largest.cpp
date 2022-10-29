#include<stdio.h>
int main()
{
	int a[10],i;
	int l1 = a[0];
	int l2 = a[0];
	printf("Enter the numbers ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		if(a[i]>l1)
		l1 = a[i];
		else
		a[i] = a[i+1];
    } 
	printf("Largest number = %d ",l1);
	
	for(i=0;i<10;i++)
	{
		if(a[i]>l2 && a[i]<l1)
		l2 = a[i];
		else
		a[i] = a[i+1];	
	}
	printf("Second largest number = %d ",l2);
}
