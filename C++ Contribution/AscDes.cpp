#include<iostream>
using namespace std;
int main()
{
    int size = 10;
    int arr = 10;
    int arrapr = arr;
    bool flaginc=true;
    bool flagdec=true;
    bool flagcons=true;

    cout<<"Enter Number ";
    for(int i=0;i<size;i++)
    {
        cin>>(arrapr + i);
    }
    for(int i=0;i<size;i++)
    {
         if( (arrapr + i) < (arrapr + (i+1)))
        {
          flaginc=false;
          
        }
        else if( (arrapr + i) > (arrapr + (i+1)))
        {
            flagdec=false;
        }
        else if( (arrapr + i) == (arrapr + (i+1)))
        {
           flagcons=false;
        }
    }
    
    if(flaginc==false && flagdec==false){
    cout<<"Array is increasing & decreasing"; 
    }
    else if(flaginc==false)
    {
        cout<<"increasing";
    }
    else if(flagdec==false)
    {
        cout<<"Decreasing";
    }
    else if(flagcons==false)
    {
        cout<<"Constant";
    }
    return 0;
}
    