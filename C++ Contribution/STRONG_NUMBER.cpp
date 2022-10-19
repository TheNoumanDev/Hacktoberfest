#include <iostream>
using namespace std;
 
// Function declarations
long long fact(int num);
void printStrongNumbers(int start, int end);
 
 
int main()
{
    int start, end;
 
    /* Input start and end range */
    cout<<"Enter the lower limit: ";
    cin>>start;
    cout<<"Enter the upper limit: ";
    cin>>end;
 
    cout<<"List of strong numbers between"<<start<<"to "<<end << " are: "<<endl;
    printStrongNumbers(start, end);
 
    return 0;
}
 
 
 
//Printing all strong numbers in a given range
void printStrongNumbers(int start, int end)
{
    long long sum;
    int num;
 
    // Iterates from start to end
    while(start != end)
    {
        sum = 0;
        num = start;
 
        // Calculating sum of factorial of digits
        while(num != 0)
        {
            sum += fact(num % 10);
            num /= 10;
        }
 
        // If sum of factorial of digits equal to current number
        if(start == sum)
        {
           cout<<start<<endl;
        }
 
        start++;
    }
}
 
//Recursively find factorial of any number
long long fact(int num)
{
    if(num == 0)
        return 1;
    else
        return (num * fact(num-1));
}