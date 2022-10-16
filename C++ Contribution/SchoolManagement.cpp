#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<fstream>

using namespace std;

struct Student {
string firstName;
string lastName;
string registrationNumber;
string degreeTitle;
};

struct Teacher {
string teafirstName;
string tealastName;
string experience;
string contactNumber;
string qualfication;
string Email;
};

void header();
short main_menu_();
short menu_option_1();
short menu_option_2();
bool isValidName(string realname);
bool isValidRegistrationName(string regno);
bool integar_vali(string exp);
bool Phone_Validator(string phone_number);
bool email_Validator(string e_mail);
bool teacher_validator(Teacher tea_info_var);
bool student_validator(Student stu_info_var);
bool add_stu(Student stu_info_arr[],short size,Student stu_info_var);
bool add_tea(Teacher tea_info_arr[],short max_teachers,Teacher tea_info_var);
void display_stu(Student stu_info_arr[],short max_students);
void initialization(Student stu_info_arr[],short max_students, Teacher tea_info_arr[],short max_teaches);
void display_tea(Teacher tea_info_arr[],short max_teachers);
bool save_stu( Student stu_info_arr[], short max_students );
bool save_tea( Teacher tea_info_arr[], short max_teachers );
bool load_stu(Student stu_info_arr[],short size);
bool load_tea(Teacher tea_info_arr[],short size);


int main()
{
   short max_students = 10;
   short max_teachers = 10;
   Student stu_info_arr[max_students];
   Student stu_info_var;
   Teacher tea_info_arr[max_teachers];
   Teacher tea_info_var;
    
   short main_menu; 
   short menu_option_1_;
   short menu_option_2_;                       
   bool flag = false;
   char choice;

   initialization(stu_info_arr,max_students,tea_info_arr,max_teachers);
   load_tea( tea_info_arr, max_teachers);
   load_stu( stu_info_arr, max_students);

   do
   {
       main:
      main_menu = main_menu_();
      switch (main_menu)
      {
      case 1:
           stu_menu:
           menu_option_1_ = menu_option_1();
           if ( menu_option_1_ == 1 )
           {
               enter_stu:
               header();
               cout << "=> Welcome to Student Information Section\n";
               cout << "=> Enter your First Name: ";
               cin >> stu_info_var.firstName;
               cout << "=> Enter your Last Name: ";
               cin >> stu_info_var.lastName;
               cin.ignore();

               cout << "=> Enter Registration Number: ";
               cin >> stu_info_var.registrationNumber;
               cout << "=> Enter Degree Title: ";
               cin.ignore();
               getline(cin,stu_info_var.degreeTitle);

               flag = student_validator(stu_info_var);
               if (flag == true )
               {
                   flag = add_stu(stu_info_arr,max_students,stu_info_var);
                   if ( flag == true )
                   {
                       cout << "Record Save Successfully\n";
                       save_stu( stu_info_arr, max_students);
                       cout << "Do You want to Add new record or not?(Enter Y for Yes and N for No): ";
                       cin >> choice;
                       if ( choice == 'Y' || choice == 'y' ) 
                       {
                           goto enter_stu;
                       }
                       else if( choice == 'N' || choice == 'n' )
                       {
                           goto stu_menu;   
                       }
                       else
                       {
                           cout << "Invalid Input \n";
                       }
                   }
               }
               else
               {
                   cout << "Invalid Inputs\n";
               }
               
               getch();
               
           }
           else if ( menu_option_1_ == 2 )
           {
               display_stu(stu_info_arr,max_students);
           }
          
           else 
           {
               cout << "This option is not available\n";
               cout << "Press any key to Select again From Students Menu\n";
               getch();
               goto stu_menu;
           }

          break;
      case 2:
            tea_menu:
            menu_option_2_ = menu_option_2();
            if ( menu_option_2_ == 1 )
           {
               header();
               cout << "=> Welcome to Teacher Information Section\n";
               cout << "=> Enter your First name: ";
               cin >> tea_info_var.teafirstName;
               cout << "=> Enter your Last Name: ";
               cin >> tea_info_var.tealastName;
               cout << "=> Enter your Qualification: ";
               cin >> tea_info_var.qualfication;
               cout << "=> Enter your Expreience(year): ";
               cin >> tea_info_var.experience;
               cout << "=> Enter your Contact Number: ";
               cin >> tea_info_var.contactNumber;
               cout << "=> Enter your Email Address: ";
               cin>> tea_info_var.Email;

                flag = teacher_validator(tea_info_var);
               if (flag == true )
               {
                   flag = add_tea(tea_info_arr,max_teachers,tea_info_var);
                   if ( flag == true )
                   {
                       cout << "Record Save Successfully\n";
                       save_tea( tea_info_arr,max_teachers );
                       cout << "Do You want to Add new record or not?(Enter Y for Yes and N for No): ";
                       cin >> choice;
                       if ( choice == 'Y' || choice == 'y' ) 
                       {
                           goto enter_stu;
                       }
                       else if( choice == 'N' || choice == 'n' )
                       {
                           goto stu_menu;   
                       }
                       else
                       {
                           cout << "Invalid Input \n";
                       }
                   }
               }
               else
               {
                   cout << "Invalid Inputs\n";
               }
             getch();
           }
           else if ( menu_option_2_ == 2 )
           {
                display_tea(tea_info_arr,max_teachers);
           }
           else 
           {
               cout << "This option is not available\n";
               cout << "Press any key to Select again From Teacher Menu\n";
               getch();
               goto tea_menu;
           }
          break;
          case 0:
          {
          cout<<"Thanks for using the program....\n";
          cout<<"Program closed...";
          getchar();
          
          }
      
      }
   } while ( main_menu != 0 );
   
}

short main_menu_()
{
    short option;
   header();
    cout << "                  => Choose the option from the menu:\n";
    cout << "                  => Enter 1 for Student Information\n";
    cout << "                  => Enter 2 for Teacher information\n";
    cout << "                  => Enter 0 to close program\n";
    cout << "                  => Enter Input: ";
    cin >> option;
    return option;
}
short menu_option_1()
{
   short option;
   header();
    cout << "                  => Welcome to Student information Section\n"; 
    cout << "                  => Choose the option from the menu:\n";
    cout << "                  => Enter 1 create new entry\n";
    cout << "                  => Enter 2 display previous record\n";
    cout << "                  => Enter 3 go to back\n";
    cout << "                  => Enter Input: ";
    cin >> option;
    return option;
}

short menu_option_2()
{
     short option;
     header();
    cout << "                  => Welcome to Teacher information Section\n"; 
    cout << "                  => Choose the option from the menu:\n";
    cout << "                  => Enter 1 create new entry\n";
    cout << "                  => Enter 2 display previous record\n";
    cout << "                  => Enter 3 go to back\n";
    cout << "                  => Enter Input: ";
    cin >> option;
    return option;
}

void header()
{
   system("cls");
    for (short i = 0; i < 70; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout <<  setw(25) << " " << "School Management System\n"; 
     for (short i = 0; i < 70; i++)
    {
        cout << "*";
    } 
    cout << endl;
}

bool student_validator(Student stu_info_var)
{
    bool flag_fname = false;
    bool flag_lname = false;
    bool flag_degreename = false;
    bool flag_regno = false;

    flag_fname=isValidName(stu_info_var.firstName);
    flag_lname=isValidName(stu_info_var.lastName);
    flag_degreename=isValidName(stu_info_var.degreeTitle);
    flag_regno=isValidRegistrationName(stu_info_var.registrationNumber);
    if ( flag_lname == true && flag_fname == true && flag_degreename == true && flag_regno == true )
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool isValidName(string realname)
{
 bool flag = false;

        for (int i = 0; i < realname.length(); i++)
        {
            if ((realname[i] >= 'a' && realname[i] <= 'z') || (realname[i] >= 'A' && realname[i] <= 'Z') || (realname[i] == ' ' ))
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
            
        }

    return flag;
}

bool isValidRegistrationName(string regno)
{
     int x = regno.length();
     bool flag_reg = false;
     if( x == 11 )
     {
         if(regno[0] == '2' && regno[1] == '0' && regno[4] == '-' && regno[7] == '-' )
         {
                        flag_reg==true;
                    for ( int n = 2; n < 4 ; n++)
                    {
                        if( regno[n] >= '0' && regno[n] <= '9' )
                        {
                            flag_reg = true;
                        }
                        else
                        {
                            flag_reg = false;
                            break;
                        } 
                    }
                    if ( flag_reg == true )
                    {
                        if( (regno[5] >= 'A' && regno[5]<= 'Z') && (regno[6] >= 'A' && regno[6]<= 'Z'))
                           {
                               flag_reg= true;
                           }
                           else
                           {
                               flag_reg= false;
                           }
                              if ( flag_reg == true )
                              {
                                 for (int j = 8; j < 11; j++)
                                 {
                                     if( regno[j] >= '0' && regno[j] <= '9')
                                     {
                                         flag_reg = true;
                                     }
                                     else
                                     {
                                         flag_reg = false;
                                     }   
                                 }
                              }  
                    }   
         }
         else
         {
             flag_reg = false;
         }
     }
     
     return flag_reg;
}

bool add_stu(Student stu_info_arr[],short size,Student stu_info_var)
{
    bool flag = false;
    for (short i = 0; i < size; i++)
    {
        if ( stu_info_arr[i].registrationNumber == " " )
        {
            stu_info_arr[i].firstName = stu_info_var.firstName;
            stu_info_arr[i].lastName = stu_info_var.lastName;
            stu_info_arr[i].degreeTitle = stu_info_var.degreeTitle;
            stu_info_arr[i].registrationNumber = stu_info_var.registrationNumber;
            flag = true;
            break;
        }   
    }
   return flag; 
}

bool add_tea(Teacher tea_info_arr[],short max_teachers,Teacher tea_info_var)
{
    bool flag = false;
    for (short i = 0; i < max_teachers ; i++)
    {
        if ( tea_info_arr[i].contactNumber == " " )
        {
             tea_info_arr[i].teafirstName = tea_info_var.teafirstName;
             tea_info_arr[i].tealastName = tea_info_var.tealastName;
             tea_info_arr[i].qualfication = tea_info_var.qualfication;
             tea_info_arr[i].experience = tea_info_var.experience;
             tea_info_arr[i].Email = tea_info_var.Email;
             tea_info_arr[i].contactNumber = tea_info_var.contactNumber;
             flag = true;
             break;
        }
    }
    return flag;
}

void display_stu(Student stu_info_arr[],short max_students)
{
    header();
    cout << "Welcome to Student Information Section\n\n";
    cout << left << setw(7) << "S.No." << setw(20) << "Student Name" << setw(30) 
         << "Student Registration Number" << setw(12) << "Degree Title\n"; 
         for (short i = 0; i < max_students; i++)
         {
             if ( stu_info_arr[i].registrationNumber != " ")
             {
                 cout << left << setw(7) << i+1 << stu_info_arr[i].firstName<< setw(15) << stu_info_arr[i].lastName << setw(30) 
                 << stu_info_arr[i].registrationNumber << setw(25) << stu_info_arr[i].degreeTitle << endl;
             }   
         } 
     getch();    
}

void display_tea(Teacher tea_info_arr[],short max_teachers)
{
    header();
    cout << "Welcome to Teacher Information Section\n\n";
    for (short i = 0; i < 70; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (short i = 0; i < max_teachers; i++)
    {
        if ( tea_info_arr[i].contactNumber != " " )
        {
        cout << tea_info_arr[i].teafirstName << " " << tea_info_arr[i].tealastName << endl;
        cout << "Experience: " << tea_info_arr[i].experience << endl;
        cout << "Qualification: " << tea_info_arr[i].qualfication << endl;
        cout << "Contact Number: " << tea_info_arr[i].contactNumber << endl;
        cout << "Email Address: " << tea_info_arr[i].Email << endl;
        for (short i = 0; i < 70; i++)
          {
              cout << "-";
          }
         cout << endl;

        }
    }
    getch();

}

void initialization(Student stu_info_arr[],short max_students, Teacher tea_info_arr[],short max_teaches)
{
    for ( short i = 0; i < max_students ; i++ )
    {
        stu_info_arr[i].degreeTitle = " ";
        stu_info_arr[i].firstName = " ";
        stu_info_arr[i].lastName = " ";
        stu_info_arr[i].registrationNumber = " ";
    }

    for (short i = 0; i < max_teaches; i++)
    {
        tea_info_arr[i].teafirstName = " ";
        tea_info_arr[i].tealastName = " ";
        tea_info_arr[i].qualfication = " ";
        tea_info_arr[i].experience = " ";
        tea_info_arr[i].Email = " ";
        tea_info_arr[i].contactNumber = " ";
    }

}

bool integar_vali(string exp)
{
    bool flag = false;
    for (short i = 0; i < exp.length(); i++)
    {
        if ( exp[i] >= '0' && exp[i] <= '9' )
        {
            flag = true;
        }
        else
        {
            flag = false;
            return flag;
        }
    }
    return flag;
}

bool Phone_Validator(string phone_number)
{
    bool flag = false;
    int size = phone_number.length();
     
if( size == 12 && phone_number[4] == '-')
{
    
    for (short i = 0; i <size ; i++)
    {
        if( (phone_number[i] >= '0' && phone_number[i] <= '9') || phone_number[i] == '-' )
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
else if ( size == 11)
{
    for (short i = 0; i <size ; i++)
    {
        if( (phone_number[i] >= '0' && phone_number[i] <= '9') )
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

bool email_Validator(string e_mail)
{
    bool flag = false;
    int email_size ;

    email_size = e_mail.length();

    if( e_mail[0] != '@' && e_mail[email_size-4] == '.' && e_mail[email_size-3] == 'c' && e_mail[email_size-2] == 'o' && e_mail[email_size-1] == 'm')
    {

        for(int i = 0; i < email_size; i++)
        {
            if( e_mail[i] == '@' )
            {
                flag = true;
            }
        }
    }
    return flag;
}

bool teacher_validator(Teacher tea_info_var)
{
    bool fflag = false;
    bool lflag = false;
    bool expflag = false;
    bool phoneflag = false;
    bool emailflag = false;
    fflag = isValidName(tea_info_var.teafirstName);
    cout << fflag;
    lflag = isValidName(tea_info_var.tealastName);
    cout << lflag;
    expflag = integar_vali(tea_info_var.experience);
    cout << expflag;
    phoneflag = Phone_Validator(tea_info_var.contactNumber);
    cout << phoneflag;
    emailflag = email_Validator(tea_info_var.Email);
    cout << emailflag;
    if ( fflag ==  true && lflag ==  true && expflag ==  true && phoneflag ==  true && emailflag ==  true  )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool save_stu( Student stu_info_arr[], short max_students )
{
    ofstream inn;
    inn.open("Student.txt");
    if(inn.is_open())
    {
        for (short i = 0; i < max_students; i++)
        {
            if ( stu_info_arr[i].registrationNumber != " " )
            {
                inn << stu_info_arr[i].firstName << " ";
                inn << stu_info_arr[i].lastName << ",";
                inn << stu_info_arr[i].registrationNumber << ",";
                inn << stu_info_arr[i].degreeTitle << "\n";
            }
        }
        inn.close();
        return true;
    }
    else
    {
        return false;
    }
    
}

bool save_tea( Teacher tea_info_arr[], short max_teachers )
{
    ofstream inn;
    inn.open("Teacher.txt");
    cout << "start";
    if(inn.is_open())
    { cout <<"hi\n";
        for (short i = 0; i < max_teachers; i++)
        {
            cout <<"hii\n";
            if ( tea_info_arr[i].contactNumber != " " )
            {
                cout <<"hiii\n";
                inn << tea_info_arr[i].teafirstName << " ";
                inn << tea_info_arr[i].tealastName<< ",";
                inn << tea_info_arr[i].experience<< ",";
                inn << tea_info_arr[i].qualfication << ",";
                inn << tea_info_arr[i].contactNumber << ",";
                inn << tea_info_arr[i].Email << "\n";
            }
        }
        inn.close();
        getch();
        return true;
    }
    else
    {
        getch();
        return false;
    }
    
}

bool load_stu(Student stu_info_arr[],short size)
{
    short i = 0;
    ifstream out;
    out.open("Student.txt");
    if ( out.is_open() )
    {
        string first,last,reg,degree;
        string line;
        while ( !out.eof() && i < size )
        {
            getline(out,line);
            if (line == "")
            continue;
            stringstream ss(line);
            getline(ss,first ,' ');
            stu_info_arr[i].firstName = first;
            getline(ss, last ,',');
            stu_info_arr[i].lastName = last;
            getline(ss, reg,',');
            stu_info_arr[i].registrationNumber = reg;
            getline(ss,degree,',');
            stu_info_arr[i].degreeTitle = degree;
            i++;
        }
        out.close();
        return true;
    }
    else
    {
        return false;
    }
}

bool load_tea(Teacher tea_info_arr[],short size)
{
    short i = 0;
    ifstream out;
    out.open("Teacher.txt");
    if ( out.is_open() )
    {
        string first,last,exp,qua,con,emai;
        string line;
        while ( !out.eof() && i < size )
        {
            getline(out,line);
            if (line == "")
            continue;
            stringstream ss(line);
            getline(ss,first ,' ');
            tea_info_arr[i].teafirstName = first;
            getline(ss, last ,',');
            tea_info_arr[i].tealastName = last;
            getline(ss, exp,',');
            tea_info_arr[i].experience = exp;
            getline(ss,qua,',');
            tea_info_arr[i].qualfication =qua;
            getline(ss,con,',');
            tea_info_arr[i].contactNumber = con;
            getline(ss,emai,',');
            tea_info_arr[i].Email = emai;
            i++;
        }
        out.close();
        return true;
    }
    else
    {
        return false;
    }  
}