// #include<iostream>
// using namespace std;

// struct sterling{
//     int pounds;
//     int shillings;
//     int pence;
// };

// int main()
// {
//     sterling money;
//     double input_money;
//     cout<<"Enter amount of money in new style: ";
//     cin>>input_money;
//     money.pounds = input_money;
//     double temp = input_money - money.pounds;
//     money.shillings= temp*20;
//     double temp2 = temp*20 - money.shillings;
//     money.pence = temp2*12;
//     cout<<"Pounds: "<<money.pounds<<endl;
//     cout<<"Shillings: "<<money.shillings<<endl;
//     cout<<"Pennies: "<<money.pence<<endl;

//     return 0;
// }



#include<iostream>
using namespace std;

struct sterling{
    int* pounds;
    int shillings;
    int pence;
};

int main()
{
    // sterling* money = new sterling[3];
    // money->pounds= new int;
    // *((*money).pounds)=34;
    // cout<<*(money->pounds);
    // for (int i = 0; i < 3; i++)
    // {
    //     money[i].pounds = new int;
    //     *(money[i].pounds) = i*2;
    //     cout<<*(money[i].pounds)<<endl;
    // }
    sterling* money = new sterling;
    money->pence = 34;
    cout<<money->pence<<endl;
    cout<<(*money).pence;
    

    return 0;
}