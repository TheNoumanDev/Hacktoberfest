#include <iostream>
#include <cstring>
#include <string>
#include <fstream> // For File Handling.
#include <cstdlib> // For generating a random number
#include <ctime>   // i.e; Account Number
#include <iomanip> // For Manipulated Interface.
#include <conio.h>
using namespace std;

// Administrator Login Details.
string admin_usname;
string admin_pswrd;
bool isValidAdmin(string user, string pswrd);
bool loadAdmin();

// customer login details........
enum c_details
{
    accNo,
    name,
    f_name,
    DOB,
    CNIC,
    cellNo,
    address,
    accountType,
    securityKey
};

// Cutomer information validators:
bool isValidCName(string c_name);
bool isValidCFName(string cf_name);
bool isValidDOB(string DOB);
bool isValidCNIC(string CNIC);
bool isValidCellNo(string C_CellNo);
bool isValidEmail(char arr[], int size);
bool isValidAccounType(string c_accountType);

// Admin jobs
bool addCustomer(string Customer_data[][9], bool cs_flag[], string c_accNo, string c_name, string cf_name, string c_dob, string c_cnic, string c_cellno, string c_address, string c_accountType, string c_securitykey, int Total_Customers);
void viewCustomer(string Customer_data[][9], bool cs_flag[], int Total_Customers);
bool deleteCustomer(string Customer_data[][9], bool cs_flag[], int balance[], int temp);
bool editCustomer(string Customer_data[][9], bool cs_flag[], string c_name, string cf_name, string c_dob, string c_cnic, string c_cellno, string c_address, string c_accountType, string c_securitykey, int temp);
bool searchAccNo(string Customer_data[][9], string c_accNo, int Total_Customers);
bool searchSecurityKey(string Customer_data[][9], string c_securitykey, int temp);
bool saveCustomer(string Customer_data[][9], bool cs_flag[], string c_accNo, string c_name, string cf_name, string c_dob, string c_cnic, string c_cellno, string c_address, string c_accountType, string c_securitykey, int balance[], int Total_Customers);
bool loadCustomer(string Customer_data[][9], bool cs_flag[], int balance[], int Total_Customers);

void halt();

// for storing temporary values
int temp;
char check;

// Main Function..
int main()
{
    // For Admin login
    string user_name;
    string pswrd;

    // For customer deatials
    const int Total_Customers = 10;
    const int Customer_Details = 9;
    string customer_data[Total_Customers][Customer_Details];
    char email[Total_Customers][30];
    int balance[Total_Customers];
    string c_accNo;
    string c_name;
    string cf_name;
    string c_dob;
    string c_cnic;
    string c_cellno;
    string c_address;
    string c_accountType;
    string c_securitykey;
    char c_email[30];
    int email_size; // To store the size of email
    int amount;

    bool csFlag[Total_Customers];
    for (int i = 0; i < Total_Customers; i++)
    {
        csFlag[i] = false;
    }
    for (int i = 0; i < Total_Customers; i++)
    {
        balance[i] = 0;
    }

    // menu loop control variables
    int menu;
    int input;
    int UserType = -10;

    // for storing random number
    int random;

    // Load admin login details into memory.
    loadAdmin();

    // Load Customers data from file into arrays.
    loadCustomer(customer_data, csFlag, balance, Total_Customers);

    system("CLS");
    for (int i = 0; i < 80; i++)
    {
        cout << "*";
    }
    cout << "\n*\t\t             ~~~DUKO BNAK LIMITED~~~\t\t\t       *\n";
    for (int i = 0; i < 80; i++)
    {
        cout << "*";
    }
    do
    {
        cout << endl;
        cout << "Choose the desired option\n";
        cout << left << setw(10) << "\t"
             << setw(25) << "1. Administrator Login"
             << setw(25) << "2. Customer Login"
             << setw(25) << "0. Exit";
        cout << endl;

        cout.unsetf(ios::left);
        cout.unsetf(ios::right);

        cout << "\tChoose an option: ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            system("cls");
            cout << endl;
            cout << "\t\t\t** Welcome To Admin Section ** " << endl;
            cout << "Dear users current software is intended for authorized users only." << endl;
            cout << "Login to the system to get access" << endl;
            cout << "\nEnter User name: ";
            cin >> user_name;
            cout << "\nEnter Password: ";
            cin >> pswrd;
            // cout << user_name << endl;
            // cout << pswrd << endl;
            // cout << admin_usname << endl;
            // cout << admin_pswrd << endl;
            // cout << isValidAdmin(user_name , pswrd) << endl;
            if (isValidAdmin(user_name, pswrd))
            {
                cout << "Admin successfully Login!!!\n";
                UserType = 1;
                halt();
            }
            else
            {
                // cout << "Invalid credentials!!!\n";
                UserType = -1;
            }
            break;
        case 2:
            system("CLS");
            cout << endl;
            cout << "\t\t\t** Welcome To Customer Section ** " << endl;
            cout << "Dear users current software is intended for authorized users only." << endl;
            cout << "Login to the system to get access" << endl;
            cout << "\nEnter Your Account No. : ";
            cin >> c_accNo;
            if (searchAccNo(customer_data, c_accNo, Total_Customers))
            {
                cout << "\nAccount Found!!";
                cout << "\nEnter the Security key : ";
                cin >> c_securitykey;
                if (searchSecurityKey(customer_data, c_securitykey, temp))
                {
                    UserType = 2;
                }
                else
                {
                    UserType = -1;
                    cout << "\nSecurity key Mismatch!!!";
                }
            }
            else
            {
                UserType = -1;
                cout << "\nAccount not Found!!";
            }
            break;
        case 0:
            if (saveCustomer(customer_data, csFlag, c_accNo, c_name, cf_name, c_dob, c_cnic, c_cellno, c_address, c_accountType, c_securitykey, balance, Total_Customers))
            {
                cout << "All Customers Data Saved successfully" << endl;
            }
            else
            {
                cout << "All data you entered is lost due to some error" << endl;
            }
            UserType = -10;
            cout << "\nThanks for using the System!!!";
            cout << "\nProgram Exited Sucessfully.";
            return 0;
            break;

        default:
            cout << "\nInvalid Choice!!!";
            break;
        }
        if (UserType == 1)
        {
            do
            {
                system("CLS");
                for (int i = 0; i < 80; i++)
                {
                    cout << "*";
                }
                cout << "\n*\t\t             ~~~DUKO BNAK LIMITED~~~\t\t\t       *";
                cout << "\n*\t\t    ~~WELCOME TO ACCOUNT MANAGEMENT SYSTEM~~\t\t       *\n";
                for (int i = 0; i < 80; i++)
                {
                    cout << "*";
                }
                cout << "\n| MAIN MENU:                                                                   |"
                     << "\n|\t01. NEW ACCOUNT                                                        |"
                     << "\n|\t02. DEPOSIT AMOUNT                                                     |"
                     << "\n|\t03. WITHDRAW AMOUNT                                                    |"
                     << "\n|\t04. BALANCE INQUIRY                                                    |"
                     << "\n|\t05. ALL ACCOUNT HOLDER LIST                                            |"
                     << "\n|\t06. CLOSE AN ACCOUNT                                                   |"
                     << "\n|\t07. MODIFY AN ACCOUNT                                                  |"
                     << "\n|\t08. EXIT                                                               |\n";
                for (int i = 0; i < 80; i++)
                {
                    cout << "*";
                }
                cout << "\n\n> Select Your Option <1-8> ";
                cin >> menu;
                switch (menu)
                {
                case 1:
                    system("CLS");
                    cout << "\t\t~~~Enter the credentials of New Account Holder~~~\n";
                    cout << "\n> Name of Account Holder           : ";
                    cin.ignore();
                    getline(cin, c_name);
                    cout << "\n> Father's Name                    : ";
                    getline(cin, cf_name);
                    cout << "\n> Date of Birth(dd-mm-yyyy)        : ";
                    cin >> c_dob;
                    cout << "\n> CNIC-NO(xxxxx-xxxxxxx-x)         : ";
                    cin >> c_cnic;
                    cout << "\n> Cell NO(03xx-xxxxxxx)            : ";
                    cin >> c_cellno;
                    cout << "\n> Email Address                    : ";
                    cin >> c_email;
                    email_size = strlen(c_email);
                    cout << "\n> Address                          : ";
                    cin.ignore();
                    getline(cin, c_address);
                    cout << "\n> Account Type(current/savings)    : ";
                    cin >> c_accountType;
                    cout << "\n> Security Key                     : ";
                    cin >> c_securitykey;
                    if (isValidCName(c_name))
                    {
                        cout << "Customer name is Correct!\n";
                        if (isValidCFName(cf_name))
                        {
                            cout << "Customer's Father name is Correct!\n";
                            if (isValidDOB(c_dob))
                            {
                                cout << "Date of Birth is Correct!\n";
                                if (isValidCNIC(c_cnic))
                                {
                                    cout << "Cnic-No is Correct!\n";
                                    if (isValidCellNo(c_cellno))
                                    {
                                        cout << "Cell-No is Correct!\n";
                                        if (isValidEmail(c_email, email_size))
                                        {
                                            cout << "Email address is Correct!\n";
                                            if (isValidAccounType(c_accountType))
                                            {
                                                cout << "Account Type is Correct!\n";
                                                srand(time(0));
                                                random = rand() % 33 + 55555;
                                                c_accNo = to_string(random);

                                                if (addCustomer(customer_data, csFlag, c_accNo, c_name, cf_name, c_dob, c_cnic, c_cellno, c_address, c_accountType, c_securitykey, Total_Customers))
                                                {

                                                    cout << "\n\n           CONGRATUALATIONS!!!";
                                                    cout << "\nAccount has been created Succesfully!!!";
                                                    cout << "\nYour Account No is " << c_accNo << ".";
                                                    cout << "\nKindly note your Account no. and Security key for further corespondance!!!";
                                                    cout << "\nThanks to be a Part of Duko Community\n";
                                                }
                                                else
                                                {
                                                    cout << "Space fill!!\n";
                                                }
                                            }
                                            else
                                            {
                                                cout << "Account Type is Inorrect!\n";
                                            }
                                        }
                                        else
                                        {
                                            cout << "Email Address is Incorrect";
                                        }
                                    }
                                    else
                                    {
                                        cout << "Cell-No is Incorrect!\n";
                                    }
                                }
                                else
                                {
                                    cout << "Cnic-No is Incorrect!\n";
                                }
                            }
                            else
                            {
                                cout << "Date of Birth is Incorrect!\n";
                            }
                        }
                        else
                        {
                            cout << "Customer's Father name is Incorrect!\n";
                        }
                    }
                    else
                    {
                        cout << "Customer name is Incorrect!\n";
                    }

                    halt();
                    break;
                case 2:
                    system("CLS");
                    cout << "\t\t~~~Amount Deposit Section~~~\n";
                    cout << "\n> Enter the Account No. in which you want to Deposit Ammount: ";
                    cin >> c_accNo;
                    // cout << searchAccNo(customer_data, c_accNo, Total_Customers) << endl;
                    if (searchAccNo(customer_data, c_accNo, Total_Customers))
                    {
                        cout << "\nAccount Found!!";
                        if (customer_data[temp][accountType] == "savings")
                        {
                            cout << "\nAs this is savings account, So minimum cash deposit limit is Rs.500/-";
                            cout << "\n> Enter the Ammount: ";
                            cin >> amount;
                            if (amount >= 500)
                            {
                                balance[temp] = balance[temp] + amount;
                                cout << "\n\n Ammount successfully Deposited!!!";
                                cout << "\nYour New Balance is Rs." << balance[temp];
                            }
                            else
                            {
                                cout << "\nAik bar kahi gai baat smjh mai nhi aati.....500 sai zyada cash deposit kro....";
                            }
                        }
                        else if (customer_data[temp][accountType] == "current")
                        {
                            cout << "\nAs this is current account, So minimum cash deposit limit is Rs.2000/-";
                            cout << "\n> Enter the Ammount: ";
                            cin >> amount;
                            if (amount >= 2000)
                            {
                                balance[temp] = balance[temp] + amount;
                                cout << "\n\n Ammount successfully Deposited!!!";
                                cout << "\nYour New Balance is Rs." << balance[temp];
                            }
                            else
                            {
                                cout << "\nAik bar kahi gai baat smjh mai nhi aati.....2000 sai zyada cash deposit kro....";
                            }
                        }
                    }
                    else
                    {
                        cout << "\nAccount not Found!!";
                    }

                    halt();
                    break;
                case 3:
                    system("CLS");
                    cout << "\t\t~~~Amount WithDraw Section~~~\n";
                    cout << "\n> Enter the Account No. from which you want to WithDraw Ammount: ";
                    cin >> c_accNo;
                    if (searchAccNo(customer_data, c_accNo, Total_Customers))
                    {
                        cout << "\nAccount Found!!";
                        cout << "\nEnter the Security key : ";
                        cin >> c_securitykey;
                        if (searchSecurityKey(customer_data, c_securitykey, temp))
                        {
                            if (customer_data[temp][accountType] == "savings")
                            {
                                cout << "\nAs this is savings account, So minimum cash withdrawn limit is Rs.500/-";
                                cout << "\n> Enter the Ammount: ";
                                cin >> amount;
                                if (amount >= 500)
                                {
                                    if (amount <= balance[temp])
                                    {
                                        balance[temp] = balance[temp] - amount;
                                        cout << "\n\n Ammount successfully withdrawn!!!";
                                        cout << "\nYour New Balance is Rs." << balance[temp];
                                    }
                                    else
                                    {
                                        cout << "Sorry, you don't have enough balance for this transaction!!!";
                                    }
                                }
                                else
                                {
                                    cout << "\nAik bar kahi gai baat smjh mai nhi aati.....500 sai zyada cash withdraw kro....";
                                }
                            }
                            else if (customer_data[temp][accountType] == "current")
                            {
                                cout << "\nAs this is current account, So minimum cash withdrawn limit is Rs.2000/-";
                                cout << "\n> Enter the Ammount: ";
                                cin >> amount;
                                if (amount >= 2000)
                                {
                                    if (amount <= balance[temp])
                                    {
                                        balance[temp] = balance[temp] - amount;
                                        cout << "\n\n Ammount successfully withdrawn!!!";
                                        cout << "\nYour New Balance is Rs." << balance[temp];
                                    }
                                    else
                                    {
                                        cout << "Sorry, you don't have enough balance for this transaction!!!";
                                    }
                                }
                                else
                                {
                                    cout << "\nAik bar kahi gai baat smjh mai nhi aati.....2000 sai zyada cash deposit kro....";
                                }
                            }
                        }
                        else
                        {
                            cout << "\nSecurity key Mismatch!!!";
                        }
                    }
                    else
                    {
                        cout << "\nAccount not Found!!";
                    }

                    halt();
                    break;
                case 4:
                    system("CLS");
                    cout << "\t\t~~~Balance Inquiry Section~~~\n";
                    cout << "\n> Enter the Account No. : ";
                    cin >> c_accNo;
                    if (searchAccNo(customer_data, c_accNo, Total_Customers))
                    {
                        cout << "\nAccount found!!";
                        cout << "\n> Dear Customer, Your Account Balance is: " << balance[temp];
                        cout << "\n\n For any query, Please contact our Help-line No.(0900-78601)!!!";
                    }
                    else
                    {
                        cout << "\nAccount not found!!";
                    }
                    halt();
                    break;
                case 5:
                    system("CLS");
                    viewCustomer(customer_data, csFlag, Total_Customers);
                    halt();
                    break;
                case 6:
                    system("CLS");
                    cout << "\t\t\t~~~Account closing section~~~\n";
                    cout << "\n> Enter the Account No. to be Closed: ";
                    cin >> c_accNo;
                    if (searchAccNo(customer_data, c_accNo, Total_Customers))
                    {
                        cout << "\nEnter the Security key : ";
                        cin >> c_securitykey;
                        if (searchSecurityKey(customer_data, c_securitykey, temp))
                        {
                            cout << "\nAre you sure you want to close your account(Y/N) : ";
                            cin >> check;
                            if (check == 'y' || check == 'Y')
                            {
                                if (deleteCustomer(customer_data, csFlag, balance, temp))
                                {
                                    cout << "\nAccount Closed Successfully!!!";
                                    cout << "\nThanks to be a Part of Duko Community.";
                                    cout << "\nWe are looking for your next Visit!!";
                                }
                                else
                                {
                                    cout << "\nAccount could'nt closed!!!";
                                    cout << "\nPlease contact the Head Office for any inconvinence!!!";
                                }
                            }
                            else if (check == 'n' || check == 'N')
                            {
                                cout << "\nThanks..We apreciate your step!!!";
                                cout << "\nIf you have any issue regarding our services, Kindly register your complain at our compalaint cell!!";
                                cout << "\nThanks to be a Part of Duko Community.";
                                cout << "\nWe are looking for your next Visit!!";
                            }
                            else
                            {
                                cout << "\nYou have choosen an invalid option!!!";
                                cout << "\nKindly read the instructions carefully and Try again...";
                            }
                        }
                        else
                        {
                            cout << "\nSecurity key Mismatch!!!";
                        }
                    }
                    else
                    {
                        cout << "\nAccount not found!!!";
                    }

                    halt();
                    break;
                case 7:
                    system("CLS");
                    cout << "\t\t\t~~~Account Modification Section~~~\n";
                    cout << "\n> Enter the Account No. :";
                    cin >> c_accNo;
                    if (searchAccNo(customer_data, c_accNo, Total_Customers))
                    {
                        cout << "\nEnter the Security key : ";
                        cin >> c_securitykey;
                        if (searchSecurityKey(customer_data, c_securitykey, temp))
                        {
                            cout << "\n\t~~~Enter the New credentials Account Holder~~~\n";
                            cout << "\n> Name of Account Holder           : ";
                            cin.ignore();
                            getline(cin, c_name);
                            cout << "\n> Father's Name                    : ";
                            getline(cin, cf_name);
                            cout << "\n> Date of Birth(dd-mm-yyyy)        : ";
                            cin >> c_dob;
                            cout << "\n> CNIC-NO(xxxxx-xxxxxxx-x)         : ";
                            cin >> c_cnic;
                            cout << "\n> Cell NO(03xx-xxxxxxx)            : ";
                            cin >> c_cellno;
                            cout << "\n> Address                          : ";
                            cin.ignore();
                            getline(cin, c_address);
                            cout << "\n> Account Type(current/savings)    : ";
                            cin >> c_accountType;
                            cout << "\n> Security Key                     : ";
                            cin >> c_securitykey;
                            if (isValidCName(c_name))
                            {
                                cout << "Customer name is Correct!\n";
                                if (isValidCFName(cf_name))
                                {
                                    cout << "Customer's Father name is Correct!\n";
                                    if (isValidDOB(c_dob))
                                    {
                                        cout << "Date of Birth is Correct!\n";
                                        if (isValidCNIC(c_cnic))
                                        {
                                            cout << "Cnic-No is Correct!\n";
                                            if (isValidCellNo(c_cellno))
                                            {
                                                cout << "Cell-No is Correct!\n";
                                                if (isValidAccounType(c_accountType))
                                                {
                                                    cout << "Account Type is Correct!\n";

                                                    if (editCustomer(customer_data, csFlag, c_name, cf_name, c_dob, c_cnic, c_cellno, c_address, c_accountType, c_securitykey, temp))
                                                    {

                                                        cout << "\n\n           CONGRATUALATIONS!!!";
                                                        cout << "\nAccount has been Updated Succesfully!!!";
                                                        cout << "\nYour Account No is " << c_accNo << ".";
                                                        cout << "\nKindly note your Account no. and Security key for further corespondance!!!";
                                                        cout << "\nThanks to be a Part of Duko Community\n";
                                                    }
                                                    else
                                                    {
                                                        cout << "Space fill!!\n";
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "Account Type is Inorrect!\n";
                                                }
                                            }
                                            else
                                            {
                                                cout << "Cell-No is Inorrect!\n";
                                            }
                                        }
                                        else
                                        {
                                            cout << "Cnic-No is Incorrect!\n";
                                        }
                                    }
                                    else
                                    {
                                        cout << "Date of Birth is Incorrect!\n";
                                    }
                                }
                                else
                                {
                                    cout << "Customer's Father name is Incorrect!\n";
                                }
                            }
                            else
                            {
                                cout << "Customer name is Incorrect!\n";
                            }
                        }
                        else
                        {
                            cout << "\nSecurity key Mismatch!!!";
                        }
                    }
                    else
                    {
                        cout << "\nAccount not found!!!";
                    }

                    halt();
                    break;
                case 8:
                    break;

                default:
                    cout << "\nSorry, You have choosed an invalid option. Please Read the Instructions and Try Again.";
                    halt();
                    break;
                }
            } while (menu != 8);
        }
        else if (UserType == 2)
        {
            do
            {
                system("CLS");
                for (int i = 0; i < 80; i++)
                {
                    cout << "*";
                }
                cout << "\n*\t\t             ~~~DUKO BNAK LIMITED~~~\t\t\t       *";
                cout << "\n*\t\t    ~~WELCOME TO CUSTOMER ACCOUNT SECTION~~\t\t       *\n";
                for (int i = 0; i < 80; i++)
                {
                    cout << "*";
                }
                cout << "\n| MAIN MENU:                                                                   |"
                     << "\n|\t01. WITHDRAW AMOUNT                                                    |"
                     << "\n|\t02. MODIFY ACCOUNT                                                     |"
                     << "\n|\t03. BALANCE INQUIRY                                                    |"
                     << "\n|\t04. EXIT                                                               |\n";
                for (int i = 0; i < 80; i++)
                {
                    cout << "*";
                }
                cout << "\n\n> Select Your Option <1-3> ";
                cin >> menu;
                switch (menu)
                {
                case 1:
                    system("CLS");
                    cout << "\t\t~~~Amount WithDraw Section~~~\n";
                    cout << "\nAccount verified!!";
                    cout << "\nEnter the Security key : ";
                    cin >> c_securitykey;
                    if (searchSecurityKey(customer_data, c_securitykey, temp))
                    {
                        if (customer_data[temp][accountType] == "savings")
                        {
                            cout << "\nAs this is savings account, So minimum cash withdrawn limit is Rs.500/-";
                            cout << "\n> Enter the Ammount: ";
                            cin >> amount;
                            if (amount >= 500)
                            {
                                if (amount <= balance[temp])
                                {
                                    balance[temp] = balance[temp] - amount;
                                    cout << "\n\n Ammount successfully withdrawn!!!";
                                    cout << "\nYour New Balance is Rs." << balance[temp];
                                }
                                else
                                {
                                    cout << "Sorry, you don't have enough balance for this transaction!!!";
                                }
                            }
                            else
                            {
                                cout << "\nAik bar kahi gai baat smjh mai nhi aati.....500 sai zyada cash withdraw kro....";
                            }
                        }
                        else if (customer_data[temp][accountType] == "current")
                        {
                            cout << "\nAs this is current account, So minimum cash withdrawn limit is Rs.2000/-";
                            cout << "\n> Enter the Ammount: ";
                            cin >> amount;
                            if (amount >= 2000)
                            {
                                if (amount <= balance[temp])
                                {
                                    balance[temp] = balance[temp] - amount;
                                    cout << "\n\n Ammount successfully withdrawn!!!";
                                    cout << "\nYour New Balance is Rs." << balance[temp];
                                }
                                else
                                {
                                    cout << "Sorry, you don't have enough balance for this transaction!!!";
                                }
                            }
                            else
                            {
                                cout << "\nAik bar kahi gai baat smjh mai nhi aati.....2000 sai zyada cash deposit kro....";
                            }
                        }
                    }
                    else
                    {
                        cout << "\nSecurity key Mismatch!!!";
                    }

                    halt();
                    break;
                case 2:
                    system("CLS");
                    cout << "\t\t\t~~~Account Modification Section~~~\n";
                    cout << "\nEnter the Security key : ";
                    cin >> c_securitykey;
                    if (searchSecurityKey(customer_data, c_securitykey, temp))
                    {
                        cout << "\n\t~~~Enter the New credentials Account Holder~~~\n";
                        cout << "\n> Name of Account Holder           : ";
                        cin.ignore();
                        getline(cin, c_name);
                        cout << "\n> Father's Name                    : ";
                        getline(cin, cf_name);
                        cout << "\n> Date of Birth(dd-mm-yyyy)        : ";
                        cin >> c_dob;
                        cout << "\n> CNIC-NO(xxxxx-xxxxxxx-x)         : ";
                        cin >> c_cnic;
                        cout << "\n> Cell NO(03xx-xxxxxxx)            : ";
                        cin >> c_cellno;
                        cout << "\n> Address                          : ";
                        cin.ignore();
                        getline(cin, c_address);
                        cout << "\n> Account Type(current/savings)    : ";
                        cin >> c_accountType;
                        cout << "\n> Security Key                     : ";
                        cin >> c_securitykey;
                        if (isValidCName(c_name))
                        {
                            cout << "Customer name is Correct!\n";
                            if (isValidCFName(cf_name))
                            {
                                cout << "Customer's Father name is Correct!\n";
                                if (isValidDOB(c_dob))
                                {
                                    cout << "Date of Birth is Correct!\n";
                                    if (isValidCNIC(c_cnic))
                                    {
                                        cout << "Cnic-No is Correct!\n";
                                        if (isValidCellNo(c_cellno))
                                        {
                                            cout << "Cell-No is Correct!\n";
                                            if (isValidAccounType(c_accountType))
                                            {
                                                cout << "Account Type is Correct!\n";

                                                if (editCustomer(customer_data, csFlag, c_name, cf_name, c_dob, c_cnic, c_cellno, c_address, c_accountType, c_securitykey, temp))
                                                {

                                                    cout << "\n\n           CONGRATUALATIONS!!!";
                                                    cout << "\nAccount has been Updated Succesfully!!!";
                                                    cout << "\nYour Account No is " << c_accNo << ".";
                                                    cout << "\nKindly note your Account no. and Security key for further corespondance!!!";
                                                    cout << "\nThanks to be a Part of Duko Community\n";
                                                }
                                                else
                                                {
                                                    cout << "Space fill!!\n";
                                                }
                                            }
                                            else
                                            {
                                                cout << "Account Type is Inorrect!\n";
                                            }
                                        }
                                        else
                                        {
                                            cout << "Cell-No is Inorrect!\n";
                                        }
                                    }
                                    else
                                    {
                                        cout << "Cnic-No is Incorrect!\n";
                                    }
                                }
                                else
                                {
                                    cout << "Date of Birth is Incorrect!\n";
                                }
                            }
                            else
                            {
                                cout << "Customer's Father name is Incorrect!\n";
                            }
                        }
                        else
                        {
                            cout << "Customer name is Incorrect!\n";
                        }
                    }
                    else
                    {
                        cout << "\nSecurity key Mismatch!!!";
                    }
                    halt();
                    break;
                case 3:
                    system("CLS");
                    cout << "\t\t~~~Balance Inquiry Section~~~\n";
                    cout << "\n> Dear Customer, Your Account Balance is Rs." << balance[temp] << ".";
                    getch();
                    cout << "\n\n For any query, Please contact our Help-line No.(0900-78601): ";
                    halt();
                    break;
                case 4:
                    cout << "\nThanks for using the System!!!";
                    break;
                default:
                    cout << "\nSorry, You have choosed an invalid option. Please Read the Instructions and Try Again.";
                    halt();
                    break;
                }
            } while (menu != 4);
        }
        else if (UserType == -1)
        {
            cout << "\nYou have entered invalid Credentials!!!" << endl;
        }
    } while (input != 0);

    return 0;
}

//Fuunction to read admin login credentials from file and load them into memory.
bool loadAdmin()
{
    ifstream getUsers("Users.txt");
    if (!getUsers.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string username, password;
        getline(getUsers, username, ',');
        admin_usname = username;
        getline(getUsers, password);
        admin_pswrd = password;
        getUsers.close();
        return true;
    }
}

// Admin information Validator
bool isValidAdmin(string user, string pswrd)
{
    if (user == admin_usname && pswrd == admin_pswrd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Fuunction to customer data from file and load them onto arrays.
bool loadCustomer(string Customer_data[][9], bool cs_flag[], int balance[], int Total_Customers)
{
    int i = 0;
    string bal;
    ifstream getCustomers("Customer_data.txt");
    if (!getCustomers.is_open())
    {
        cout << "Customer's data file failed to open.\n";
        return false;
    }
    else
    {
        while (!getCustomers.eof() && i < Total_Customers)
        {
            getline(getCustomers, Customer_data[i][accNo], ',');
            getline(getCustomers, Customer_data[i][name], ',');
            getline(getCustomers, Customer_data[i][f_name], ',');
            getline(getCustomers, Customer_data[i][DOB], ',');
            getline(getCustomers, Customer_data[i][CNIC], ',');
            getline(getCustomers, Customer_data[i][cellNo], ',');
            getline(getCustomers, Customer_data[i][address], ',');
            getline(getCustomers, Customer_data[i][accountType], ',');
            getline(getCustomers, Customer_data[i][securityKey], ',');
            getline(getCustomers, bal);
            balance[i] = stoi(bal);
            cs_flag[i] = true;
            i++;
        }
        return true;
    }
}

// Customer information Validators........

// Customer name Validator......
bool isValidCName(string c_name)
{
    bool flag = false;
    cout << "Name : " << c_name << endl;
    int size = c_name.length();
    for (int i = 0; i < size; i++)
    {
        if ((c_name[i] >= 'A' && c_name[i] <= 'Z') || (c_name[i] >= 'a' && c_name[i] <= 'z') || (c_name[i] == ' '))
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

// Customer Father Name Validator.....
bool isValidCFName(string cf_name)
{
    cout << "Father's Name : " << cf_name << endl;
    int size = cf_name.length();
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if ((cf_name[i] >= 'A' && cf_name[i] <= 'Z') || (cf_name[i] >= 'a' && cf_name[i] <= 'z') || (cf_name[i] == ' '))
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

// Date of Birth Validator........
bool isValidDOB(string DOB)
{
    int size = DOB.length();
    cout << "DOB : " << DOB << endl;
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

// Cnic-No Validator...........
bool isValidCNIC(string CNIC)
{
    int size = CNIC.length();
    cout << "CNIC_No : " << CNIC << endl;
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

// Cell-no validator........
bool isValidCellNo(string C_CellNo)
{
    int size = C_CellNo.length();
    cout << "Cell_No : " << C_CellNo << endl;
    bool f1 = false, f2 = false;
    if (size == 12)
    {
        if ((C_CellNo[0] == '0' && C_CellNo[1] == '3') && (C_CellNo[2] >= '0' && C_CellNo[2] <= '9') && (C_CellNo[3] >= '0' && C_CellNo[3] <= '9') && (C_CellNo[4] == '-'))
        {
            f1 = true;
        }
        for (int i = 5; i < size; i++)
        {
            if (C_CellNo[i] >= '0' && C_CellNo[i] <= '9')
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

// Email address Validator.......
bool isValidEmail(char arr[], int size)
{
    cout << "Email Address : ";
    for (int x = 0; x < size; x++)
    {
        cout << arr[x];
    }
    cout << endl;
    bool flag = true;
    //Checking for first character i.e; alphabet
    if (arr[0] >= 'a' && arr[0] <= 'z')
    {
    }
    else
    {
        flag = false;
        return flag;
    }
    int i = 1;
    while (arr[i] != '@' && (i < size))
    {
        if (arr[i] >= 'a' || arr[i] <= 'z' || arr[i] >= 'A' || arr[i] <= 'Z' || arr[i] >= '0' || arr[i] <= '9')
        {
        }
        else
        {
            flag = false;
            return flag;
        }
        i++;
    }
    if (arr[i] != '@')
    {
        flag = false;
        return flag;
        ;
    }
    while (arr[i] != '.' && (i < size))
    {
        if (arr[i] >= 'a' || arr[i] <= 'z' || arr[i] >= 'A' || arr[i] <= 'Z')
        {
        }
        else
        {
            flag = false;
            return flag;
        }
        i++;
    }
    if (arr[i] != '.')
    {
        flag = false;
        return flag;
    }
    while (i < size)
    {
        if (arr[i] >= 'a' || arr[i] <= 'z' || arr[i] >= 'A' || arr[i] <= 'Z')
        {
        }
        else
        {
            flag = false;
        }
        i++;
    }
    return flag;
}

// Account type Validator.........
bool isValidAccounType(string c_accountType)
{
    cout << "Account Type : " << c_accountType << endl;
    if (c_accountType == "current" || c_accountType == "savings")
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Add Customer data
bool addCustomer(string Customer_data[][9], bool cs_flag[], string c_accNo, string c_name, string cf_name, string c_dob, string c_cnic, string c_cellno, string c_address, string c_accountType, string c_securitykey, int Total_Customers)
{
    bool flag = false;
    for (int i = 0; i < Total_Customers; i++)
    {
        if (!(cs_flag[i]))
        {
            Customer_data[i][accNo] = c_accNo;
            Customer_data[i][name] = c_name;
            Customer_data[i][f_name] = cf_name;
            Customer_data[i][DOB] = c_dob;
            Customer_data[i][CNIC] = c_cnic;
            Customer_data[i][cellNo] = c_cellno;
            Customer_data[i][address] = c_address;
            Customer_data[i][accountType] = c_accountType;
            Customer_data[i][securityKey] = c_securitykey;
            cs_flag[i] = true;
            flag = true;
            break;
        }
    }
    return flag;
}

// View Customer data....
void viewCustomer(string Customer_data[][9], bool cs_flag[], int Total_Customers)
{
    cout << "\t\t\t\t\t\t\t\t\t~~~Account Holders List~~~\n\n";
    cout << left;
    cout << setw(25) << "Account No."
         << setw(25) << "Customer Name"
         << setw(25) << "S/O"
         << setw(25) << "Date of Birth"
         << setw(25) << "CNIC No."
         << setw(25) << "Cell No."
         << setw(25) << "Address"
         << setw(25) << "Account Type"
         << setw(25) << "Security Key" << endl
         << endl;
    for (int i = 0; i < Total_Customers; i++)
    {
        if (cs_flag[i])
        {
            for (int j = 0; j < 9; j++)
            {
                cout << setw(25) << Customer_data[i][j];
            }
            cout << endl;
        }
    }

    // cout << setw(25) << "54707686939799" << setw(25) << "Rehan Khalid" << setw(25) << "Khalid Maqsood" << setw(25) << "21-10-2002" << setw(25) << "12345-6789022-3" << setw(25) << "0900-78601" << setw(25) << "Duko Enterprises" << endl;
}

// Delete Customer (close account)...
bool deleteCustomer(string Customer_data[][9], bool cs_flag[], int balance[], int temp)
{
    bool flag = false;
    if (cs_flag[temp])
    {
        Customer_data[temp][accNo] = "";
        Customer_data[temp][name] = "";
        Customer_data[temp][f_name] = "";
        Customer_data[temp][DOB] = "";
        Customer_data[temp][CNIC] = "";
        Customer_data[temp][cellNo] = "";
        Customer_data[temp][address] = "";
        Customer_data[temp][accountType] = "";
        Customer_data[temp][securityKey] = "";
        balance[temp] = 0;
        cs_flag[temp] = false;
        flag = true;
    }
    return flag;
}

// Modify Customer Data.....
bool editCustomer(string Customer_data[][9], bool cs_flag[], string c_name, string cf_name, string c_dob, string c_cnic, string c_cellno, string c_address, string c_accountType, string c_securitykey, int temp)
{
    bool flag = false;
    if (cs_flag[temp])
    {
        Customer_data[temp][name] = c_name;
        Customer_data[temp][f_name] = cf_name;
        Customer_data[temp][DOB] = c_dob;
        Customer_data[temp][CNIC] = c_cnic;
        Customer_data[temp][cellNo] = c_cellno;
        Customer_data[temp][address] = c_address;
        Customer_data[temp][accountType] = c_accountType;
        Customer_data[temp][securityKey] = c_securitykey;
        flag = true;
    }
    return flag;
}

// Search Account Number......
bool searchAccNo(string Customer_data[][9], string c_accNo, int Total_Customers)
{
    bool flag = false;
    for (int i = 0; i < Total_Customers; i++)
    {
        //cout << "Customer_data[i][accNo] " << Customer_data[i][accNo] <<endl;
        //cout << "c_accNo " << c_accNo <<endl;
        if (Customer_data[i][accNo] == c_accNo)
        {
            temp = i;
            flag = true;
        }
    }
    return flag;
}

// Seurity Key Validator......
bool searchSecurityKey(string Customer_data[][9], string c_securitykey, int temp)
{
    bool flag = false;
    //cout << "Customer_data[i][accNo] " << Customer_data[i][accNo] <<endl;
    //cout << "c_accNo " << c_accNo <<endl;
    if (Customer_data[temp][securityKey] == c_securitykey)
    {
        flag = true;
    }
    return flag;
}

// Functon to store Customer dataina file
bool saveCustomer(string Customer_data[][9], bool cs_flag[], string c_accNo, string c_name, string cf_name, string c_dob, string c_cnic, string c_cellno, string c_address, string c_accountType, string c_securitykey, int balance[], int Total_Customers)
{
    ofstream customer;
    customer.open("Customer_data.txt");
    if (customer.is_open())
    {
        for (int i = 0; i < Total_Customers; i++)
        {
            if (Customer_data[i][accNo] != "")
            {
                //These lines will write all array data to the file and make a comma separated file
                customer << Customer_data[i][accNo] << ",";
                customer << Customer_data[i][name] << ",";
                customer << Customer_data[i][f_name] << ",";
                customer << Customer_data[i][DOB] << ",";
                customer << Customer_data[i][CNIC] << ",";
                customer << Customer_data[i][cellNo] << ",";
                customer << Customer_data[i][address] << ",";
                customer << Customer_data[i][accountType] << ",";
                customer << Customer_data[i][securityKey] << ",";
                customer << balance[i] << endl;
            }
        }

        customer.close();
        return true;
    }
    else
    {
        //If there is error while opening file this function will return false
        return false;
    }
}

// For moified Interface purpose.....
void halt()
{
    cout << "\nPress any key to continue.....";
    getch();
}