/*
Name: Moizza Azhar

Username: imoizza
Favorite Language: c++,python
*/



#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define num_of_threads 27

int validate[num_of_threads]={0};

typedef struct 
{
   int row;
   int column;
}parameters;

int sudoku[9][9]=
{
    {6, 2, 4, 5, 3, 9, 1, 8, 7},
	{5, 1, 9, 7, 2, 8, 6, 3, 4},
	{8, 3, 7, 6, 1, 4, 2, 9, 5},
	{1, 4, 3, 8, 6, 5, 7, 2, 9},
	{9, 5, 8, 2, 4, 7, 3, 6, 1},
	{7, 6, 2, 3, 9, 1, 4, 5, 8},
	{3, 7, 1, 9, 5, 6, 8, 4, 2},
	{4, 9, 6, 1, 8, 2, 5, 7, 3},
	{2, 8, 5, 4, 7, 3, 9, 1, 6}
};

void *column_check (void *line)
{
    parameters *lines=(parameters*)line;
    int row=lines->row;
    int column=lines->column;
    if(row!=0||column>8)
    {
        fprintf(stderr,"invalid row or column in column subsection\n row:%d,column:%d\n",row,column);
        pthread_exit(NULL);
    }

    int array_validation[9]={0};
    
    for (int i =0;i<9;i++)
    {
        int number=sudoku[i][column];
        if(number<1||number>9||array_validation[number-1]==1)
        {
            pthread_exit(NULL);
        }
        else
        {
            array_validation[number-1]=1;
        }
    }
    validate[18+column]=1;
    pthread_exit(NULL);
}

void *row_check (void *line)
{
    parameters *lines=(parameters*)line;
    int row=lines->row;
    int column=lines->column;
    if(column!=0||row>8)
    {
        fprintf(stderr,"invalid row or column in row subsection\n row:%d,column:%d\n",row,column);
        pthread_exit(NULL);
    }

    int array_validation[9]={0};
    
    for (int i =0;i<9;i++)
    {
        int number=sudoku[row][i];
        if(number<1||number>9||array_validation[number-1]==1)
        {
            pthread_exit(NULL);
        }
        else
        {
            array_validation[number-1]=1;
        }
    }
    validate[9+row]=1;
    pthread_exit(NULL);
}

void *Square3X3_valid(void *line)
{
    parameters *lines=(parameters*)line;
    int row=lines->row;
    int column=lines->column;
    if(row>6||row%3!=0||column>6||column%3!=0)
    {
        fprintf(stderr,"invalid row or column for subsection\n row:%d,column:%d\n",row,column);
        pthread_exit(NULL);
    }

    int array_validation[9]={0};

    for(int i=0;i<row+3;i++)
    {
        for (int j=0; j<column+3;j++)
        {
            int number=sudoku[i][j];
            if (number<1||number>9||array_validation[number-1]==1)
            {
                pthread_exit(NULL);
            }
            else
            {
                array_validation[number-1]=1;
            }
        }
    }
    validate[row+column/3]=1;
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[num_of_threads];
    int index=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(i%3==0&&j%3==0)
            {
                parameters *data=(parameters*)malloc(sizeof(parameters));
               data->row=i;
               data->column=j;
               pthread_create(&thread[index++],NULL,Square3X3_valid,data);

            }
            if(i==0)
            {
                parameters *col_data=(parameters*)malloc(sizeof(parameters));
               col_data->row=i;
               col_data->column=j;
               pthread_create(&thread[index++],NULL,column_check,col_data);

            }
            if(j==0)
            {
               parameters *row_data=(parameters*)malloc(sizeof(parameters));
               row_data->row=i;
               row_data->column=j;
               pthread_create(&thread[index++],NULL,row_check,row_data);

            }
        }
    }
    for(int i=0;i<num_of_threads;i++)
    {
        pthread_join(thread[i],NULL);
    }
    for(int i=0;i<num_of_threads;i++)
    {
        if (validate[i]==0)
        {
            printf("This Sudoku solution is invalid!\n");
            return EXIT_SUCCESS;
        }
    }
    printf("This Sudoku solution is Valid!\n");
    return EXIT_SUCCESS;

}

