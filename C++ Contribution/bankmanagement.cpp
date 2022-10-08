#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <ctime>
using namespace std;
////////////////////////////////////structs/////////////////////////////
struct History
{
    string CNIC;
    string Trans_Type;
    string e_mail;
};
struct User
{
    string first_name;
    string Last_Name;
    string DOB;
    string Contact_Number;
    string CNIC;
    string Adress;
    string e_mail;
    string password;
    int Amount;
    History H_Array[100];
};

///////////////////////////////////functions//////////////////////////
void Halt();
void Login_Menu();
bool isValidName(string name);
bool isValidDOB(string DOB);
bool isValidCellNo(string CellNo);
bool isValidEmail(string e_mail);
bool isValidCNIC(string CNIC);
bool add_User(User Struct, User Array[100]);
bool Save_Account(User Array[100]);
bool Load_Account(User Array[100]);
bool search(User Struct, User Array[100]);
void User_Menu();
bool Add_Money(User Struct, User Array[100]);
bool Withdraw_Money(User Struct, User Array[100]);
bool save_Trans(User Array[100]);
int main()
{
    ////////////////////////variables////////////////////
    User Struct;
    User Array[100];
    int input;
    int input2;
    ///////////////////////intialization/////////////////
    for (int i = 0; i < 100; i++)
    {
        Array[i].first_name = "";
        Array[i].Last_Name = "";
        Array[i].DOB = "";
        Array[i].Contact_Number = "";
        Array[i].CNIC = "";
        Array[i].Adress = "";
        Array[i].password = "";
        Array[i].e_mail = "";
        for (int j = 0; j < 100; j++)
        {
            Array[i].H_Array[j].Trans_Type = "";
            Array[i].H_Array[j].e_mail = "";
            Array[i].H_Array[j].CNIC = "";
        }
    }
    if (Load_Account(Array))
    {
        cout << "Loaded!!" << endl;
    }
    ///////////////////////////Main Programn/////////////
    do
    {
    back:
        Login_Menu();
        cout << "Enter user input:";
        cin >> input;
        system("CLS");
        switch (input)
        {
        case 1:
            cout << "**************************************************************\n";
            cout << "                    Bank Management System\n";
            cout << "**************************************************************\n";
            cout << "Fill the required input to create an Account\n";
            cin.ignore();
            cout << "Enter First Name:";
            getline(cin, Struct.first_name);
            cout << "Enter Last Name:";
            getline(cin, Struct.Last_Name);
            cout << "Enter Date-of-birth:";
            getline(cin, Struct.DOB);
            cout << "Enter Contact Number:";
            getline(cin, Struct.Contact_Number);
            cout << "Enter Valid CNIC:";
            getline(cin, Struct.CNIC);
            cout << "Enter Address:";
            getline(cin, Struct.Adress);
            cout << "Enter Email Address:";
            getline(cin, Struct.e_mail);
            cout << "Enter Password:";
            getline(cin, Struct.password);
            if (isValidName(Struct.first_name) && isValidName(Struct.Last_Name) && isValidDOB(Struct.DOB) && isValidCellNo(Struct.Contact_Number) && isValidEmail(Struct.e_mail) && isValidCNIC(Struct.CNIC))
            {
                if (add_User(Struct, Array))
                {
                    if (Save_Account(Array))
                    {
                        cout << "Your account has been created successfully!!!\n";
                    }
                    else
                    {
                        cout << "Your account has not created successfully!!!\n";
                    }
                }
                else
                {
                    cout << "Your account has not created successfully!!!\n";
                }
            }
            else
            {
                cout << "Your account has not created successfully!!!\n";
            }
            system("CLS");
            cout << "Press 0 to go back:\n";
            cout << "Enter user input:";
            cin >> input2;
            if (input2 == 0)
            {
                goto back;
            }
            else
            {
                cout << "Wrong input\n";
            }
            
            break;
            
        case 2:
            cout << "**************************************************************\n";
            cout << "                    Bank Management System\n";
            cout << "**************************************************************\n";
            cout << "Enter valid credential for login\n";
            cin.ignore();
            cout << "Enter Email Address:";
            getline(cin, Struct.e_mail);
            cout << "Enter Password:";
            getline(cin, Struct.password);
            if (search(Struct, Array))
            {
                do
                {
                    system("CLS");
                    User_Menu();
                    cout << "Enter user input:";
                    cin >> input2;
                    system("CLS");
                    switch (input2)
                    {
                    case 1:
                        cout << "**************************************************************\n";
                        cout << "                    Bank Management System\n";
                        cout << "**************************************************************\n";
                        cout << "Enter the required information to deposit amount:\n";
                        cin.ignore();
                        cout << "Enter CNIC:";
                        getline(cin, Struct.CNIC);
                        cout << "Enter Contact Number:";
                        getline(cin, Struct.Contact_Number);
                        cout << "Enter your Password:";
                        getline(cin, Struct.password);
                        cout << "Enter the amount to deposit (in digits):";
                        cin >> Struct.Amount;
                        if (Add_Money(Struct, Array))
                        {
                            cout << "Amount has been added to your account\n";
                        }
                        else
                        {
                            cout << "Account Not Found!!\n";
                        }
                        Halt();
                        break;
                    case 2:
                        cout << "**************************************************************\n";
                        cout << "                    Bank Management System\n";
                        cout << "**************************************************************\n";
                        cout << "Enter the required information to deposit amount:\n";
                        cin.ignore();
                        cout << "Enter CNIC:";
                        getline(cin, Struct.CNIC);
                        cout << "Enter Contact Number:";
                        getline(cin, Struct.Contact_Number);
                        cout << "Enter your Password:";
                        getline(cin, Struct.password);
                        cout << "Enter the amount to withdraw:";
                        cin >> Struct.Amount;
                        if (Withdraw_Money(Struct, Array))
                        {
                            cout << "Collect your money!\n";
                        }
                        else
                        {
                            cout << "Account Not Found!!\n";
                        }
                        Halt();
                        break;
                    case 3:
                        cout << "**************************************************************\n";
                        cout << "                    Bank Management System\n";
                        cout << "**************************************************************\n";
                        cin.ignore();
                        cout << "Enter CNIC To View History:";
                        getline(cin, Struct.CNIC);
                        cout << setw(15) << left << "S.NO." << setw(35) << left << "Email" << setw(35) << left << "CNIC" << setw(35) << left << "Transaction-Type" << endl;
                        for (int i = 0; i < 100; i++)
                        {
                            if (Array[i].CNIC == Struct.CNIC)
                            {
                                for (int j = 0; j < 100; j++)
                                {
                                    if (Array[i].H_Array[j].CNIC != "")
                                    {
                                        cout << setw(15) << left<< i + 1 << setw(35) << left << Array[i].H_Array[j].e_mail << setw(35) << left << Array[i].H_Array[j].CNIC << setw(35) << left << Array[i].H_Array[j].Trans_Type << endl;
                                    }
                                }
                            }
                        }
                        Halt();
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Invalid input\n";
                    }
                } while (input2 != 5);
            }
            else
            {
                cout << "Account Not Found!!Create an account\n";
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            cout<<"Program Closed Successfully...\n";
            cout<<"Thank for using the Program...";
            break;
        default:
            cout << "Inavlid Choice\n";
            Halt();
        }

    } while (input != 0);
}
void Halt()
{
    cout << "Press any key to continue:";
    getch();
    system("CLS");
}
void Login_Menu()
{
    cout << "**************************************************************\n";
    cout << "                    Bank Management System\n";
    cout << "**************************************************************\n";
    cout << "Welcome to Bank\n";
    cout << "1. Create a new account\n";
    cout << "2. Login Account\n";
    cout << "3. Loan Management\n";
    cout << "0. Close the program\n";
}
bool isValidName(string name)
{
    bool flag = false;
    int size = name.length();
    for (int i = 0; i < size; i++)
    {
        if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || (name[i] == ' '))
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
bool isValidDOB(string DOB)
{
    int size = DOB.length();
    bool f1 = false, f2 = false;
    // cout << "dob size : "<< size;
    if (size == 10)
    {
        if ((DOB[0] >= '0' && DOB[0] <= '3') && (DOB[1] >= '0' && DOB[1] <= '9') && (DOB[2] == '-') && (DOB[3] == '0' || DOB[3] == '1') && (DOB[4] >= '0' && DOB[4] <= '9') && (DOB[5] == '-') && (DOB[6] >= '1' && DOB[6] <= '2') && (DOB[7] == '9' || DOB[7] == '0'))
        {
            f1 = true;
        }

        for (int i = 8; i < size; i++)
        {
            if (DOB[i] >= '0' && DOB[i] <= '9')
            {
                f2 = true;
            }
        }
        if (f1 == true && f2 == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool isValidCellNo(string CellNo)
{
    int size = CellNo.length();
    bool f1 = false, f2 = false;
    if (size == 12)
    {
        if ((CellNo[0] == '0' && CellNo[1] == '3') && (CellNo[2] >= '0' && CellNo[2] <= '9') && (CellNo[3] >= '0' && CellNo[3] <= '9') && (CellNo[4] == '-'))
        {
            f1 = true;
        }
        for (int i = 5; i < size; i++)
        {
            if (CellNo[i] >= '0' && CellNo[i] <= '9')
            {
                f2 = true;
            }
        }
        if (f1 == true && f2 == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool isValidEmail(string e_mail)
{
    bool flag = false;
    int email_size;

    email_size = e_mail.length();

    if (e_mail[0] != '@' && e_mail[email_size - 1] != '@')
    {

        for (int i = 0; i < email_size; i++)
        {
            if (e_mail[i] == '@')
            {
                flag = true;
            }
        }
    }
    return flag;
}
bool isValidCNIC(string CNIC)
{
    int size = CNIC.length();
    bool f1 = false, f2 = false, f3 = false;
    if (size == 15)
    {
        for (int i = 0; i < 5; i++)
        {
            if (CNIC[i] >= '0' && CNIC[i] <= '9')
            {
                f1 = true;
            }
        }
        for (int i = 6; i < 13; i++)
        {
            if (CNIC[i] >= '0' && CNIC[i] <= '9')
            {
                f2 = true;
            }
        }
        if ((CNIC[5] == '-' && CNIC[13] == '-') && (CNIC[14] >= '0' && CNIC[14] <= '9'))
        {
            f3 = true;
        }
        if ((f1 == true && f2 == true) && (f3 == true))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool add_User(User Struct, User Array[100])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Array[i].first_name == "")
        {
            Array[i].first_name = Struct.first_name;
            Array[i].Last_Name = Struct.Last_Name;
            Array[i].DOB = Struct.DOB;
            Array[i].Contact_Number = Struct.Contact_Number;
            Array[i].CNIC = Struct.CNIC;
            Array[i].Adress = Struct.Adress;
            Array[i].password = Struct.password;
            Array[i].e_mail = Struct.e_mail;
            flag = true;
            break;
        }
    }
    return flag;
}
bool Save_Account(User Array[100])
{
    bool flag = false;
    ofstream SaveAcc("Account.txt");
    if (SaveAcc.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (Array[i].first_name != "")
            {
                SaveAcc << Array[i].first_name << " ";
                SaveAcc << Array[i].Last_Name << ",";
                SaveAcc << Array[i].CNIC << ",";
                SaveAcc << Array[i].e_mail << ",";
                SaveAcc << Array[i].Contact_Number << ",";
                SaveAcc << Array[i].password << ",";
                SaveAcc << Array[i].Adress << ",";
                SaveAcc << Array[i].DOB << "\n";
                flag = true;
            }
        }
    }
    return flag;
}
bool Load_Account(User Array[100])
{
    bool flag;
    int i = 0;
    ifstream LoadAccount("Account.txt");
    if (!LoadAccount.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string firstName, LastName, cnic, email, cntnumber, password, address, dob;
        string line;
        while (!LoadAccount.eof() && i < 100)
        {
            getline(LoadAccount, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, firstName, ' ');
            Array[i].first_name = firstName;
            getline(ss, LastName, ',');
            Array[i].Last_Name = LastName;
            getline(ss, cnic, ',');
            Array[i].CNIC = cnic;
            getline(ss, email, ',');
            Array[i].e_mail = email;
            getline(ss, cntnumber, ',');
            Array[i].Contact_Number = cntnumber;
            getline(ss, password, ',');
            Array[i].password = password;
            getline(ss, address, ',');
            Array[i].Adress = address;
            getline(ss, dob, ',');
            Array[i].DOB = dob;
            i++;
        }

        LoadAccount.close();
        return true;
    }
    return flag;
}
bool search(User Struct, User Array[100])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Struct.e_mail == Array[i].e_mail && Struct.password == Array[i].password)
        {
            flag = true;
        }
    }
    return flag;
}
void User_Menu()
{
    cout << "**************************************************************\n";
    cout << "                    Bank Management System\n";
    cout << "**************************************************************\n";
    cout << "1- Deposit Money\n";
    cout << "2- Withdraw Money\n";
    cout << "3- View all transaction\n";
    cout << "4- View account details\n";
    cout << "5- Logout the current user\n";
}
bool Add_Money(User Struct, User Array[100])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Struct.CNIC == Array[i].CNIC && Struct.Contact_Number == Array[i].Contact_Number && Struct.password == Array[i].password)
        {
            Array[i].Amount = Struct.Amount;
            for (int j = 0; j < 100; j++)
            {
                if (Array[i].H_Array[j].CNIC == "")
                {
                    Array[i].H_Array[j].CNIC = Array[i].CNIC;
                    Array[i].H_Array[j].Trans_Type = "D";
                    Array[i].H_Array[j].e_mail = Array[i].e_mail;
                    flag = true;
                    break;
                }
            }
        }
    }
    return flag;
}
bool Withdraw_Money(User Struct, User Array[100])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Struct.CNIC == Array[i].CNIC && Struct.Contact_Number == Array[i].Contact_Number && Struct.password == Array[i].password)
        {
            Array[i].Amount = Array[i].Amount - Struct.Amount;
            for (int j = 0; j < 100; j++)
            {
                if (Array[i].H_Array[j].CNIC == "")
                {
                    Array[i].H_Array[j].CNIC = Array[i].CNIC;
                    Array[i].H_Array[j].Trans_Type = "W";
                    Array[i].H_Array[j].e_mail = Array[i].e_mail;
                    flag = true;
                    break;
                }
            }
        }
    }
    return flag;
}
bool save_Trans(User Array[100])
{
    bool flag = false;
    ofstream SaveAcc("trans.txt");
    if (SaveAcc.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            for(int j=0;j<100;j++)
            {
            if (Array[i].H_Array[j].CNIC != "")
            {
                SaveAcc << Array[i].H_Array[j].CNIC << ",";
                SaveAcc << Array[i].H_Array[j].Trans_Type << ",";
                SaveAcc << Array[i].Amount << "\n";
                flag = true;
            }
            }
        }
    }
    return flag;
}