#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
using namespace std;

//fuctions

//function to add a contact 

bool Addcontact(string phone, string name, string address, string email, string Users_Contact[30][4]);

//function to view list of all contacts

void View_All_ContactList(string Users_Contact[30][4]);

//function to search for a contact

bool Search_Contact(string phone, string Users_Contact[30][4]);

//function to update a contact

bool Update_Contact(string option, string phone, string name, string email, string address, string Users_Contact[30][4]);

//function to delete a contact

bool Del_Contact(string phone, string Users_Contact[30][4]);

//validators

//to valid the name

bool Valid_Name(string name);

//to valid phone number

bool Valid_Phone(string phone);
//to valid email address
bool Valid_email(string email);
//file handling
void Save_Contacts(string Users_Contact[30][4]);
void Load_Contacts(string Users_Contact[30][4]);

int main()
{
    ///////////////////////Variables
    
    int choose;
    string phone;
    string name, address, email;
    string option;

    ///////////////////////Arrays////////////////////////
    
    string Users_Contact[30][4];
    
    //////////////////////////////////////////Load data///////////////////////////////////
    
    Load_Contacts(Users_Contact);

    while (choose != 0)
    {
   	cout<<"\t\t\t\t*\t*";
  	cout<<"\t\t\t\t**\t**";
   	cout<<"\t\t\t\t***\t***";
   	cout<<"\t\t\t\t****\t****";
   	cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
   	cout<<"\t\t\t\t*******\t*******";
   	cout<<"\t\t\t\t*******\t*******";
   	cout<<"\t\t\t\t******\t******";
   	cout<<"\t\t\t\t*****\t*****";
   	cout<<"\t\t\t\t****\t****";
   	cout<<"\t\t\t\t***\t***";
   	cout<<"\t\t\t\t**\t**";
   	cout<<"\t\t\t\t*\t*";
        cout << "\n";
        cout << "\n";
        cout << "                        **** Welcome to Contact Management System ****\n";
        cout << "\n";
        
        // Menu of contact management system
        
        cout << "                                           MAIN MENU\n";
        cout << "                                      ======================\n";
        cout << "                                      1 Add a new Contact\n";
        cout << "                                      2 Search for Contact\n";
        cout << "                                      3 List of all Contacts\n";
        cout << "                                      4 Update a Contact\n";
        cout << "                                      5 Delete a Contact\n";
        cout << "                                      6 Check Valid Contact number\n";
        cout << "                                      0 Exit\n";
        cout << "                                      ======================\n";
        cout << "                                      Enter the choice:";
        cin >> choose;
        system("CLS");
        switch (choose)
        {
        	
            /////////////////////////////////////////////////Add a new contact///////////////////////////////////////
            
        case 1:
        addcontact:
            cout << "======================================================================================" << endl;
            cout << "                                  Add a new Contact" << endl;
            cout << "======================================================================================" << endl;
            cin.ignore();
            cout << "Phone No: ";
            getline(cin, phone);

            cout << "Name: ";
            getline(cin, name);

            cout << "Address: ";
            getline(cin, address);

            cout << "Email address: ";
            getline(cin, email);
            cout << endl
                 << endl;
            if (Valid_Name(name) && Valid_Phone(phone) && Valid_email(email))
            {
                if (Addcontact(phone, name, address, email, Users_Contact))
                {
                    cout << "New Contact is Added.."
					 << endl;
                }
                else
                {
                    cout << "New Contact Is Not Added Due To Some Error" << endl;
                }
            }
            else
            {
                cout << "Invalid Input...Please Enter The Above Details In Following Ways."
				 << endl;
                cout << "Phone: 03(XXXXXXXXX)only numers Are Allowed" << endl;
                cout << "Name: Only Alphabets Are Allowed(Smaller OR Cpaital) of length Max 30"
				 << endl;
                cout << "Address: All Type of characters are Valid " << endl;
                cout << "Email Addess: alphabets/numbers@gmail/yahoo.com\n"
                     << endl;
                cout << "Do you wanna try again(Y/N) :";
                cin >> option;
                system("CLS");
                if (option == "Y" || option == "y")
                {
                    goto addcontact;
                }
                else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                {
                    cout << "You Entered Wrong input..." << endl;
                }
            }
            cout << "Press any to continue: ";
            getch();
            system("CLS");
            break;
            
        /////////////////////////////////////////Search for contact/////////////////////////////////
        
		case 2:
            cout << "=========================================================================================================" << endl;
            cout << "                                                   Search a Contact" << endl;
            cout << "=========================================================================================================\n"
                 << endl;
            cout << "Enter The Phone Number of the Contact You Want to Search: ";
            cin.ignore();
            getline(cin, phone);
            system("CLS");
            if (Search_Contact(phone, Users_Contact))
            {
            }
            else
            {
                cout << "Sorry No Record Found!!!" << endl;
            }
            cout << "Press any to continue: ";
            getch();
            system("CLS");
            break;

        /////////////////////////////////////////List Of All contacts///////////////////////////////
        
        case 3:
            View_All_ContactList(Users_Contact);
            
            break;

        /////////////////////////////////////////Update a Contact///////////////////////////////////
        
        case 4:
            cout << "=========================================================================================================" << endl;
            cout << "                                                   Update a Contact" << endl;
            cout << "=========================================================================================================\n"
                 << endl;
            cin.ignore();
            cout << "Enter The Phone Number of Contact To update: ";
            getline(cin, phone);
            system("CLS");
            if (Update_Contact(option, phone, name, email, address, Users_Contact))
            {
            }
            else
            {
                cout << "No Contact Found Relate to This Phone Number " << endl;
            }

            cout << "Press any key to continue..: ";
            getch();
            system("CLS");
            break;
            
        /////////////////////////////////////////delete a contact////////////////////////////////////
        
        case 5:
            cout << "=========================================================================================================" << endl;
            cout << "                                                   Delete a Contact" << endl;
            cout << "=========================================================================================================\n"
                 << endl;
            cin.ignore();
            cout << "Enter The Phone Number of Contact to Delete: ";
            getline(cin, phone);
            if (Del_Contact(phone, Users_Contact))
            {
                cout << "Contact Is Deleted Successfully!!!" 
				<< endl;
            }
            else
            {
                cout << "Contact Not Deleted Because Of some Error.."
				 << endl;
            }
            cout << "Press amy key to continue: ";
            getch();
            system("CLS");
            break;
            
        ////////////////////////////////////////Check //////////////////////////////////////////////
        
        case 6:
            cout << "=========================================================================================================" << endl;
            cout << "                               Check Weather Number is Valid or not" << endl;
            cout << "=========================================================================================================\n"
                 << endl;
            cin.ignore();
            cout << "Enter the Phone No: ";
            getline(cin, phone);
            if (Valid_Phone(phone))
            {
                cout << "Phone Number Is Valid..." 
				<< endl;
            }
            else
            {
                cout << "Phone Number Is invalid..."
				 << endl;
            }
            cout << "Press amy key to continue: ";
            getch();
            system("CLS");
            cout << "=========================================================================================================" << endl;
            cout << "                               Check Weather name is Valid or not" << endl;
            cout << "=========================================================================================================\n"
                 << endl;
                 cout << "Enter the Name: ";
            cin.ignore();
            getline(cin, name);
            if (Valid_Name(name))
            {
                cout << "Name Is Valid..." 
				<< endl;
            }
            else
            {
                cout << "Name Is invalid..."
				 << endl;
            }
            cout << "Press amy key to continue: ";
            getch();
            system("CLS");
         cout << "=========================================================================================================" << endl;
            cout << "                               Check Weather email  is Valid or not" << endl;
            cout << "=========================================================================================================\n"
                 << endl;
                 cout << "Enter the Email: ";
            cin.ignore();
            
            getline(cin, email);
            if (Valid_email(email))
            {
                cout << "Email  Is Valid..." 
				<< endl;
            }
            else
            {
                cout << "Email Is invalid..."
				 << endl;
            }
            cout << "Press amy key to continue: ";
            getch();
            system("CLS");
            break;
        /////////////////////////////////////////Exit Case///////////////////////////////////////////
        
        case 0:
            cout<<"Program Exited Successfully...\n";
            cout << "Thanks For Using the Program!!" << endl;
            Save_Contacts(Users_Contact);
            return 0;
        default:
            cout << "Wrong Input!!!!!" << endl;
        }
    }
    return 0;
}
bool Addcontact(string phone, string name, string address, string email, string Users_Contact[30][4])
{
    bool flag;
    for (int i = 0; i < 100; i++)
    {
        if (Users_Contact[i][0] == "")
        {
            Users_Contact[i][0] = name;
            Users_Contact[i][1] = address;
            Users_Contact[i][2] = phone;
            Users_Contact[i][3] = email;
            flag = true;
            break;
        }
    }
    return flag;
}
bool Valid_Name(string name)
{
    bool flag;
    int size = name.length();
    if (size <= 30)
    {
        for (int i = 0; i < size; i++)
        {
            if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z') || name[i] == ' ')
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
bool Valid_Phone(string phone)
{
    bool flag;
    int size = phone.length();
    if (size == 11)
    {
        for (int i = 2; i < size; i++)
        {
            if ((phone[0] == '0' && phone[1] == '3') && (phone[i] >= '0' && phone[i] <= '9'))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
bool Valid_email(string email)
{
    bool flag = false;
    int email_size;

    email_size = email.length();

    if (email[0] != '@' && email[email_size - 4] == '.' && email[email_size - 3] == 'c' && email[email_size - 2] == 'o' && email[email_size - 1] == 'm')
    {

        for (int i = 0; i < email_size; i++)
        {
            if (email[i] == '@')
            {
                flag = true;
            }
        }
    }
    return flag;
}
void View_All_ContactList(string Users_Contact[30][4])
{

    cout << "\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================";
    cout<<endl;
    cout << "===========================================================================================================================================" << endl;
    cout << left << setw(30) << "Name" << left << setw(30) << "Address" << left << setw(30) << "Phone Number" << left << setw(30) << "Email"
	 << endl;
    for (int i = 0; i < 30; i++)
    {
        if (Users_Contact[i][0] != "")
        {
            for (int j = 0; j < 4; j++)
            {
                cout << left << setw(30) << Users_Contact[i][j];
            }
            cout << endl;
        }
    }
    cout
        << "==========================================================================================================================================="
        << endl;
    cout << "Press any to continue: ";
    getch();
    system("CLS");
}
bool Search_Contact(string phone, string Users_Contact[30][4])
{
    bool flag = false;
    for (int i = 0; i < 30; i++)
    {
        if (phone == Users_Contact[i][2])
        {
            cout << "===========================================================================================================================================" << endl;
            cout << "                                           Search Result" << endl;
            cout << left << setw(30) << "Name" << left << setw(30) << "Address" << left << setw(30) << "Phone Number" << left << setw(30) << "Email" << endl;
            for (int j = 0; j < 4; j++)
            {
                cout << left << setw(30) << Users_Contact[i][j];
            }
            cout << endl;
            flag = true;
            cout << "===========================================================================================================================================" << endl;
        }
    }
    return flag;
}
bool Update_Contact(string option, string phone, string name, string email, string address, string Users_Contact[30][4])
{
    bool flag = false;
    for (int i = 0; i < 30; i++)
    {
        if (phone == Users_Contact[i][2])
        {
        update:
            cout << "Name: ";
            getline(cin, name);

            cout << "Address: ";
            getline(cin, address);

            cout << "Email address: ";
            getline(cin, email);
            cout << endl;
            if (Valid_Name(name) && Valid_email(email))
            {
                Users_Contact[i][0] = name;
                Users_Contact[i][1] = address;
                Users_Contact[i][3] = email;
                cout << "Contact Updated Successfully!!!"
				<< endl;
                flag = true;
            }
            else
            {
                cout << "Invalid Input...Please Enter The Above Details In Following Ways." 
				<< endl;
                cout << "Name: Only Alphabets Are Allowed(Smaller OR Cpaital) of length Max 30" 
				<< endl;
                cout << "Address: All Type of characters are Valid " 
				<< endl;
                cout << "Email Addess: alphabets/numbers@gmail/yahoo.com\n"
                << endl;
                cout << "Do you wanna try again(Y/N) :";
                cin >> option;
                system("CLS");
                if (option == "Y" || option == "y")
                {
                    goto update;
                }
                else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                {
                    cout << "You Entered Wrong input..." << endl;
                }
            }
        }
    }
    return flag;
}
bool Del_Contact(string phone, string Users_Contact[30][4])
{
    bool flag = false;
    for (int i = 0; i < 30; i++)
    {
        if (Users_Contact[i][2] == phone)
        {
            Users_Contact[i][0] = {""};
            Users_Contact[i][1] = {""};
            Users_Contact[i][2] = {""};
            Users_Contact[i][3] = {""};
            flag = true;
        }
    }
    return flag;
}
void Save_Contacts(string Users_Contact[30][4])
{
    ofstream SaveContacts("Contacts.csv");
    if (SaveContacts.is_open())
    {
        for (int i = 0; i < 30; i++)
        {
            if (Users_Contact[i][0] != "")
            {
                for (int j = 0; j < 4; j++)
                {
                    SaveContacts << Users_Contact[i][j] << ",";
                }
                SaveContacts << endl;
            }
        }
    }
}
void Load_Contacts(string Users_Contact[30][4])
{
    int i = 0;
    ifstream LoadContacts("Contacts.csv");
    if (!LoadContacts.is_open())
    {
        cout << "File failed to open" << endl;
    }
    else
    {
        string name, Address, phonenumber, email;
        string line;
        while (!LoadContacts.eof() && i < 30)
        {
            getline(LoadContacts, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, name, ',');
            Users_Contact[i][0] = name;
            getline(ss, Address, ',');
            Users_Contact[i][1] = Address;
            getline(ss, phonenumber, ',');
            Users_Contact[i][2] = phonenumber;
            getline(ss, email, ',');
            Users_Contact[i][3] = email;
            i++;
        }

        LoadContacts.close();
    }
}
