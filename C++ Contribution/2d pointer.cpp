#include<stdio.h>
int main()
{
	int a[3][4] = {{10, 11, 12, 13}, {20, 21, 2, 23}, {30, 31, 32, 33}};
	int i, j, m, n;
	printf(" Enter the row number ");
	scanf("%d",&n);
	printf("\nEnter the column number");
	scanf("%d",&m);
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(n==i && m==j)
			{
				printf("\n%d",a[i][j]);
				printf("\n%d",*(a[i] + j));
				printf("\n%d",*(*(a+i)+j));
				printf("\n%d",*((a+1) + j));
				
			}
		}
	}
}
