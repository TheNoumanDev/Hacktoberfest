#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
void welcomeNestle();
void halt();
//interfaces
char idInterface();
char DMinterface();
char ManagerInterface();
char RSMinterface();
char DSinterface();
char accountantInterface();
char SHincharge();
char WHinsharge();
char teamsInterface();
char viewMenuOfManager();
//Team's functions
int teamCList();
int avaiable_placeInTeam(int row);
void addTeamWorker(int row);
void updateTeamWorker();
void removeTeamWorker();
void viewTeamsWorkers();
void viewAtendanceOfTeams(bool attandance[12][30][7][5]);
void attendanceOfTeams(bool attandance[12][30][7][5]);
void teamAccounts(string email,int row);
void TcoutFormate(int row);

void detailsOfOB();

void diaplayMonth(int month);
// product functions
void initializeProductPrice(int productPrice[8][100]);
void availableProducts(int productNumber[8][100]);
void displayProductName(int row);
void deliverProducts(string companies[5],int companyRequirements[5][8][100],int productNumber[8][100],int productPrice[8][100]);
void managementOfAreas(string companies[5],int companyRequirements[5][8][100],int productNumber[8][100]);
void addStock(string productName[8],int productNumber[8][100],int productPrice[8][100]);

//companies
void viewCompanyRequirements(int companyRequirement[5][8][100] , string companies[5]);
//Rsm
void updatingRequirementsOfBuyyer(int companyRequirement[5][8][100],string companies[5],int productNumber[8][100]);
//management
void initializeManagementData(string managementNames[6][2],int managementSalary[6][2],bool managementAttendance[12][30][6][2],bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5]);
//accountant functions
void makeSalaryReport(string managementNames[6][2],int managementSalary[6][2],int basicSalary[6],bool managementAttendance[12][30][6][2],bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5]);
void salaryStatus(string managementNames[6][2],bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5]);
//manager
int listOfManagement();
int availablePlaceInManagement(string email[],int size);
void addManagement(string email[],string password[],string name[6][2],int basicSalary[],string category,int managementSalary[6][2],int row,int index);
void emailFormateManagement(int row);
void attendanceOfManagement(bool managementAttendance[12][30][6][2],string managementNames[6][2]);
void viewAttendanceOfManagement(bool managementAttendance[12][30][6][2],string managementNames[6][2]);
string returnManagementName(int index);
// email validation;s
bool emailValidation(string email);
bool checkEmailCategory(string email,string cat);
bool check_EandP(string emailList[],string passwordList[],string email,string password,int size);
bool check_EandP_of_team(string emailList[][5],string passwordList[][5],string email,string password,int rowNo);
//File Handling
bool saveTeamData(string teamsEmail[7][5],string teamsName[7][5],string teamsPassword[7][5],int teamsSalary[7][5]);
void loadTeamData(string teamsEmail[7][5],string teamsName[7][5],string teamsPassword[7][5],int teamsSalary[7][5]);
bool saveTeamAttendanve(bool teamsAttendance[12][30][7][5]);
void loadTeamAttendanve(bool teamsAttendance[12][30][7][5]);
bool saveProductData(string productName[8],int productPrice[8][100],int productNumber[8][100]);
void loadProductData(string productName[8],int productPrice[8][100],int productNumber[8][100]);
void saveCompanyData(string companies[5],int companyRequirement[5][8][100]);
void loadCompanyData(string companies[5],int companyRequirement[5][8][100]);
bool saveSalaryStatus(bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5]);
void loadSalaryStatus(bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5]);
void saveManagementData(string managementNames[6][2],int managementSalary[6][2],int basicSalary[6]);
void loadManagementData(string managementNames[6][2],int managementSalary[6][2],int basicSalary[6]);
bool saveManagementAttendance(bool managementAttendance[12][30][6][2]);
void loadManagementAttendance(bool managementAttendance[12][30][6][2]);
void saveCEOdata(string &ceoEmail,string &ceoPassword,string &ceoName,long &totalBalance,long &pendingPayment,long &priceOfSentProducts,long &recievedAmount);
void loadCEOdata(string &ceoEmail,string &ceoPassword,string &ceoName,long &totalBalance,long &pendingPayment,long &priceOfSentProducts,long &recievedAmount);
void saveToken(int &managerToken,int &rsmToken,int &dsToken,int &accToken,int &shiToken,int &whiToken);
void loadToken(int &managerToken,int &rsmToken,int &dsToken,int &accToken,int &shiToken,int &whiToken);
//global emails and passwords 

string ceoName="Nabeel";
string ceoEmail="abc@ceo.nestle.pk";
string managerEmail[2]={"abc@manager.nestle.pk","NV@manager.nestle.pk"};
string managerPassword[2]={"abc","abc"};
string rsmEmail[2]={"abc@rsm.nestle.pk","NV@asm.nestle.pk"};
string rsmPassword[2]={"abc","abc"};
string dsEmail[2]={"abc@ds.nestle.pk","NV@ds.nestle.pk"};
string dsPassword[2]={"abc","abc"};
string accEmail[2]={"abc@acc.nestle.pk","NV@acc.nestle.pk"};
string accPassword[2]={"abc","abc"};
string shiEmail[2]={"abc@shi.nestle.pk","NV@shi.nestle.pk"};
string shiPassword[2]={"abc","abc"};
string whiEmail[2]={"abc@whi.nestle.pk","NV@whi.nestle.pk"};
string whiPassword[2]={"abc","abc"};
//Team data
string teamsEmail[7][5]={"user1@ob.team.nestle.pk","ali@ob.team.nestle.pk","ahmad@ob.team.nestle.pk","NV@ob.team.nestle.pk","NV@ob.team.nestle.pk",
                         "muzammil@dm.team.nestle.pk","user2@dm.team.nestle.pk","faraz@dm.team.nestle.pk","NV@dm.team.nestle.pk","NV@dm.team.nestle.pk",
                         "ahsan@sm.team.nestle.pk","usher@sm.team.nestle.pk","taha@sm.team.nestle.pk","NV@sm.team.nestle.pk","NV@sm.team.nestle.pk",
                         "qamar@l.team.nestle.pk","hamza@l.team.nestle.pk","asad@l.team.nestle.pk","NV@l.team.nestle.pk","NV@l.team.nestle.pk",
                         "bilal@d.team.nestle.pk","azeem@d.team.nestle.pk","usama@d.team.nestle.pk","NV@d.team.nestle.pk","NV@d.team.nestle.pk",
                         "haris@s.team.nestle.pk","anas@s.team.nestle.pk","musharaf@s.team.nestle.pk","NV@s.team.nestle.pk","NV@s.team.nestle.pk",
                         "shafiq@sg.team.nestle.pk","ejaz@sg.team.nestle.pk","saif@sg.team.nestle.pk","NV@sg.team.nestle.pk","NV@sg.team.nestle.pk"};

string teamsPassword[7][5]={"abc","abc","abc","abc","abc",
                            "abc","abc","abc","abc","abc",
                            "abc","abc","abc","abc","abc",
                            "abc","abc","abc","abc","abc",
                            "abc","abc","abc","abc","abc",
                            "abc","abc","abc","abc","abc",
                            "abc","abc","abc","abc","abc"};
string teamsName[7][5]   ={"User 1","Ali","Ahmad","NV","NV",
                            "Muzammil","User 2","faraz","NV","NV",
                            "Ahsan","Usher","Taha","NV","NV",
                            "Qamar","Hamza","Asad","NV","NV",
                            "Bilal","Azeem","Usama","NV","NV",
                            "Haris","Anas","Musharaf","NV","NV",
                            "Shafiq","Ejaz","Saif","NV","NV"};
int teamsSalary[7][5]     ={20000,20000,20000,-1,-1,
                            18000,18000,18000,-1,-1,
                            17000,17000,17000,-1,-1,
                            16000,16000,16000,-1,-1,
                            21000,21000,21000,-1,-1,
                            22000,22000,22000,-1,-1,
                            23000,23000,20000,-1,-1};

bool teamsAttendance[12][30][7][5];

// Tokens
int managerToken=0;
int rsmToken=0;
int dsToken=0;
int accToken=0;
int shiToken=0;
int whiToken=0;
//Bank Balance
long totalBalance=5000000;
long pendingPayment=0;
long priceOfSentProducts=0;
long recievedAmount=0;

int main()   ////////////////////////////main////////////////////////////////
{

    string ceoPassword="abc";
    string productName[8]={"Fruita Vitals","Coffee","Nido","Milk","Chocolates","Kitkat","Juice","cheeze"};
    int productNumber[8][100] = {0};
    string companies[5]={"Hyperstar","Metro","Packages","Empirium","Mall of defence"};
    int companyRequirement[5][8][100]={0};
    int productPrice[8][100];
    //Management Data
    string managementNames[6][2];
    int managementSalary[6][2];
    int basicSalary[6]={100000,80000,60000,60000,50000,50000};
    bool managementAttendance[12][30][6][2];
    bool managementSalaryStatus[6][2];
    bool teamSalaryStatus[7][5];

    initializeManagementData(managementNames, managementSalary, managementAttendance,managementSalaryStatus,teamSalaryStatus);
    int customer_menu;
    char option;
    char subInput;
    string customer_id;
    string admin_id;
    string admin_pass;
    string email,password;
    int managerSubInput;
    int addIndex;
    
    
    
    for (int i = 0; i < 5; i++)                      //initialize requirements
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 20; k++)
            {
                companyRequirement[i][j][k]=1;
            }
            
        }
        
    }
    
    for (int i = 0; i < 8; i++)                     //initialize product number
    {
        for (int j = 0; j < 50; j++)
        {
            productNumber[i][j] = 1;
        }
        

    }

    for (int i = 0; i < 12; i++)                         //initialize attandance
    {
        for (int k = 0; k < 30; k++)
        {
            for (int j = 0; j < 7; j++)
            {
                for (int m = 0; m < 5; m++)
                {
                    teamsAttendance[i][k][j][m]=false;
                       
                }
                
                
            }
            
        }
        
    }
    //Load Data 
    loadTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
    loadTeamAttendanve( teamsAttendance);
    loadProductData( productName, productPrice, productNumber);
    loadCompanyData( companies, companyRequirement);
    loadSalaryStatus( managementSalaryStatus, teamSalaryStatus);
    loadManagementData( managementNames, managementSalary, basicSalary);
    loadManagementAttendance( managementAttendance);
    loadCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
    loadToken(managerToken,rsmToken,dsToken, accToken, shiToken,whiToken);
   
    initializeProductPrice(productPrice);        // InitiializeProductPrice
    system("CLS");
    cout<<"\n\nMake sure your screen is Enlarged...! "<<endl;
    cout<<"\nPress any key to continue...!\n";
    getch();

    Start:

    system("CLS");
    welcomeNestle();
    char input = idInterface();
    if (input == '1')
    {
        CeoEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && checkEmailCategory(email,"ceo"))
        {
            if(ceoEmail==email && ceoPassword==password)
            {
                do
                {
                    if (accToken==1)
                    {
                        
                        system("CLS");
                        cout<<"Mail from Accountsnt :\nAccountant deduct salary of some persons from Bank Balance "<<endl;
                        accToken=2;                        
                        halt();
                    }
                    if(rsmToken==1)
                    {
                        cout<<"Mail from RSM : "<<endl;
                        cout<<"Requirement has been updated and mail has been sent to Distributer Supervisor"<<endl;
                        cout<<"If wyou want to do work quickly, \nthen press Y to send mail to DS to do work quickly \nOtherwise any character to continue : ";
                        char y;
                        if(y=='Y' || y=='y')
                        {
                            cout<<"Mail has been sent to DS"<<endl;
                            rsmToken=10;
                        }
                        halt();
                    }
                    if (managerToken==1)
                    {
                        system("CLS");
                        cout<<"Mail from Manager :\nManager added some people in Company...!"<<endl;
                        cout<<"If you have already check them, then press Y else any other character to save the mail : ";
                        char y;
                        if(y=='Y' || y=='y')
                        {
                            cout<<"\nMail has been deleted from your inbox...!"<<endl;
                            managerToken=0;
                        }                        
                        halt();
                    }
                    if(dsToken==1)
                    {
                        cout<<"Mail From DS : \nProducts has been delivered, But payment is pending..."<<endl;
                        halt();
                    }
                    if(dsToken==2)
                    {
                        cout<<"Mail From DS : \nPayments of delivered products has been recieved ...!<<"<<endl;
                        dsToken=0;
                        halt();
                    }
                    if(whiToken==1)
                    {
                        cout<<"Mail from WHI:\n";
                        cout<<"Warehouse Incharge added some persons to Company, You can check their data ...!"<<endl;
                        whiToken=0;
                        halt();
                    }
                    if(shiToken==1)
                    {
                        cout<<"Mail for SHI\n";
                        cout<<"There is very low stock in Warehouse, and reuirement is high....\n";
                        shiToken=0;
                    }
                    option = DMinterface();
                    switch (option)
                    {
                    case '1':
                        availableProducts(productNumber);
                        halt();
                        break;
                    case '2':
                        cout<<"***********************PROFIT***********************"<<endl;
                        cout<<"                  PROFIT = "<<recievedAmount<<endl;
                        cout<<"****************************************************"<<endl;
                        cout<<"Bank Balance"<<right<<setw(40)<<totalBalance<<endl;
                        cout<<left<<setw(32)<<"Lsat recieved amount"<<right<<setw(20)<<recievedAmount+priceOfSentProducts<<endl;
                        cout<<"****************************************************"<<endl;
                        halt();
                        break;
                    case '3':
                        viewTeamsWorkers();
                        halt();
                        break;
                    case '4':
                        cout<<"Enter 1 to enter a Person of Management "<<endl;
                        cout<<"Enter 2 to enter a Team Member "<<endl;
                        cout<<"\nEnter your selction : ";
                        cin>>subInput;
                        if (subInput=='1')
                        {
                            managerSubInput = listOfManagement();
                            if (managerSubInput==1)
                            {
                                int index;
                                index=availablePlaceInManagement(managerEmail,2);
                                addManagement(managerEmail,managerPassword,managementNames,basicSalary,"manager",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==2)
                            {
                                int index;
                                index=availablePlaceInManagement(rsmEmail,2);
                                addManagement(rsmEmail,rsmPassword,managementNames,basicSalary,"rsm",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==3)
                            {
                                int index;
                                index=availablePlaceInManagement(dsEmail,2);
                                addManagement(dsEmail,dsPassword,managementNames,basicSalary,"ds",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==4)
                            {
                                int index;
                                index=availablePlaceInManagement(accEmail,2);
                                addManagement(accEmail,accPassword,managementNames,basicSalary,"acc",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==5)
                            {
                                int index;
                                index=availablePlaceInManagement(shiEmail,2);
                                addManagement(shiEmail,shiPassword,managementNames,basicSalary,"shi",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==6)
                            {
                                int index;
                                index=availablePlaceInManagement(whiEmail,2);
                                addManagement(whiEmail,whiPassword,managementNames,basicSalary,"whi",managementSalary,managerSubInput-1, index);
                            }


                            halt();    
                        }
                        else if (subInput=='2')
                        {
                            addTeamWorker(teamCList());
                        }
                        else{
                            cout<<"\nYou have entered an invalid input...!";
                            halt();
                        }
                        managerToken=0;
                        whiToken=0;
                        halt();
                        break;
                    case '5':
                        cout<<"***************Remove a Worker*****************"<<endl<<endl;
                        removeTeamWorker();
                        halt();
                        break;
                    case '6':
                        cout<<"***************************Pending Payments************************"<<endl<<endl;
                        cout<<"                Pending Peyment   =   "<<pendingPayment<<endl;
                        cout<<"*******************************************************************"<<endl<<endl;
                        halt();
                        break;
                    case '7':
                        addStock(productName, productNumber, productPrice);
                        break;
                    case '8':
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveManagementAttendance( managementAttendance);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        halt();
                        goto Start;
                        break;
                    case '9':
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveManagementAttendance( managementAttendance);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        cout << "Program has been closed successfully...!" << endl;
                        halt();
                        
                        break;
                    }
                } while (option != '9');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@ceo.nestle.pk \n\n";
                    goto CeoEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
        else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@ceo.nestle.pk \n\n";
                goto CeoEnterEmail;
            }
            else{
                goto Start;
            }
        }
    }
    else if (input == '2')
    {
        ManagerEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && checkEmailCategory(email,"manager"))
        {
            if(check_EandP(managerEmail,managerPassword,email,password,2))
            {

                do
                {
                    manager:
                    option = ManagerInterface();
                    switch (option)
                    {
                    
                    case '1':
                        cout<<"Enter 1 to enter a Person of Management "<<endl;
                        cout<<"Enter 2 to enter a Team Member "<<endl;
                        cout<<"\nEnter your selction : ";
                        cin>>subInput;
                        if (subInput=='1')
                        {
                            managerSubInput = listOfManagement();
                            if (managerSubInput==1)
                            {
                                cout<<"As you are a manager,so you cannot add yourself or other manager...!"<<endl;
                            }
                            else if (managerSubInput==2)
                            {
                                int index;
                                index=availablePlaceInManagement(rsmEmail,2);
                                addManagement(rsmEmail,rsmPassword,managementNames,basicSalary,"rsm",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==3)
                            {
                                int index;
                                index=availablePlaceInManagement(dsEmail,2);
                                addManagement(dsEmail,dsPassword,managementNames,basicSalary,"ds",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==4)
                            {
                                int index;
                                index=availablePlaceInManagement(accEmail,2);
                                addManagement(accEmail,accPassword,managementNames,basicSalary,"acc",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==5)
                            {
                                int index;
                                index=availablePlaceInManagement(shiEmail,2);
                                addManagement(shiEmail,shiPassword,managementNames,basicSalary,"shi",managementSalary,managerSubInput-1, index);
                            }
                            else if (managerSubInput==6)
                            {
                                int index;
                                index=availablePlaceInManagement(whiEmail,2);
                                addManagement(whiEmail,whiPassword,managementNames,basicSalary,"whi",managementSalary,managerSubInput-1, index);
                            }


                            halt();    
                        }
                        else if (subInput=='2')
                        {
                            addTeamWorker(teamCList());
                        }
                        else{
                            cout<<"\nYou have entered an invalid input...!";
                            halt();
                        }
                        
                        
                        
                        break;

                    case '2':
                        subInput = viewMenuOfManager();
                        if (subInput=='1')
                        {
                            char select;
                            cout<<"Enter 1 for Teams"<<endl;
                            cout<<"Enter 2 for Management"<<endl;
                            cout<<"Enter 0 for Exit"<<endl;
                            cin>>select;
                            if(select=='1')
                            {
                                viewAtendanceOfTeams(teamsAttendance);
                            }
                            else if(select=='2')
                            {
                                viewAttendanceOfManagement( managementAttendance, managementNames);
                            }
                            else if(select=='0')
                            {
                                goto manager;
                            }
                            
                        }
                        else if (subInput=='2')
                        {
                            viewTeamsWorkers();
                        }
                        else if (subInput=='3')
                        {
                            availableProducts(productNumber);
                        }
                       
                        else if (subInput=='4')
                        {
                            salaryStatus(managementNames, managementSalaryStatus, teamSalaryStatus);
                        }
                        
                        else if (subInput=='5')
                        {
                            viewCompanyRequirements(companyRequirement,companies);
                        }
                        else if (subInput=='6')
                        {
                            managementOfAreas( companies, companyRequirement, productNumber);
                        }
                        else{
                            cout<<"Tou have entered invalid input"<<endl;
                        }
                        
                        
                        halt();
                        break;
                    case '3':
                        cout<<"*************Attendance of Teams****************\n\n";
                        attendanceOfManagement( managementAttendance, managementNames);
                        break;
                    case '4':
                        if(saveManagementAttendance( managementAttendance))
                        {
                            cout<<"Data has been saved successfully...!"<<endl;
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveProductData( productName, productPrice, productNumber);
                            saveCompanyData(companies,companyRequirement);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        }
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        halt();
                        goto Start;
                        break;
                    case '5':
                        if(saveManagementAttendance( managementAttendance))
                        {
                            cout<<"Data has been saved successfully...!"<<endl;
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveProductData( productName, productPrice, productNumber);
                            saveCompanyData(companies,companyRequirement);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                            
                        }
                        cout << "Program has been closed successfully...!" << endl;
                        halt();
                        
                        break;
                    }
                } while (option != '5');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@manager.nestle.pk \n\n";
                    goto ManagerEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
        else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@manager.nestle.pk \n\n";
                goto ManagerEnterEmail;
            }
            else{
                goto Start;
            }
        }
    }
    else if (input=='3')
    {
        RSMEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && (checkEmailCategory(email,"asm") || checkEmailCategory(email,"rsm")))
        {
            if(check_EandP(rsmEmail,rsmPassword,email,password,2))
            {
                do{
                    if (rsmToken==-1)
                    {
                        system("CLS");
                        cout<<"Email:\nProducts has been sent to Market by Distributer Supervisor..."<<endl;
                        rsmToken=0;
                        halt();
                        
                    }
    

                    option=RSMinterface();
                    switch (option)
                    {
                    case '1':
                        updatingRequirementsOfBuyyer( companyRequirement, companies, productNumber);
                        halt();
                        break;

                    case '2':
                        managementOfAreas( companies, companyRequirement, productNumber);
                        halt();
                        break;

                    case '3':
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        halt();
                        goto Start;
                        break;

                    case '4':
                        cout << "Program has been closed successfully...!" << endl;
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        halt();
                        
                        break;

                    default:
                        cout<<"You have entered invalid input..!"<<endl;
                        break;
                    }
                }while(option != '4');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@rsm.nestle.pk or xyz@asm.nestle.pk \n\n";
                    goto RSMEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
        else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@rsm.nestle.pk or xyz@asm.nestle.pk \n\n";
                goto RSMEnterEmail;
            }
            else{
                goto Start;
            }
        }

    }       
    else if (input=='4')
    {
        DSEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && checkEmailCategory(email,"ds"))
        {
            if(check_EandP(dsEmail,dsPassword,email,password,1))
            {
                do{
                    if(rsmToken==1)
                    {
                        system("CLS");
                        cout<<"E-Mail:\nRSM has been updated all the requirements. \nNow its your task to deliver data to them..."<<endl;
                        halt();
                        
                    }
                    if(rsmToken==10)
                    {
                        cout<<"Mail from CEO :"<<endl;
                        cout<<"Please work quickly...";
                    }

                    option=DSinterface();
                    switch (option)
                    {
                    case '1':
                        detailsOfOB();
                        break;

                    case '2':
                        viewCompanyRequirements(companyRequirement,companies);
                        halt();
                        break;

                    case '3':
                        deliverProducts(companies, companyRequirement, productNumber, productPrice);
                        break;

                    case '4':
                        availableProducts(productNumber);
                        halt();
                        break;
                    
                    case '5':
                        if(saveProductData( productName, productPrice, productNumber))
                        {
                            saveCompanyData( companies, companyRequirement);
                            saveCompanyData( companies, companyRequirement);
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveManagementAttendance( managementAttendance);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            cout<<"Data has been saved Successfully...!"<<endl;
                        }
                        else{
                            cout<<"Due to some error,data has not been saved....!"<<endl;
                        }
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        halt();
                        goto Start;
                        break;
                    case '6':
                        if(saveProductData( productName, productPrice, productNumber))
                        {
                            saveCompanyData( companies, companyRequirement);
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveManagementAttendance( managementAttendance);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            cout<<"Data has been saved Successfully...!"<<endl;
                        }
                        else{
                            cout<<"Due to some error,data has not been saved....!"<<endl;
                        }
                        cout << "Program has been closed successfully...!" << endl;
                        halt();
                        
                        break;

                    default:
                        cout<<"You have entered invalid input..!"<<endl;
                        break;
                    }
                }while(option != '6');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@ds.nestle.pk \n\n";
                    goto DSEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
        else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@ds.nestle.pk \n\n";
                goto DSEnterEmail;
            }
            else{
                goto Start;
            }
        }
    }
    else if (input=='5')
    {
        
        AccEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && checkEmailCategory(email,"acc"))
        {
            if(check_EandP(accEmail,accPassword,email,password,2))
            {
                do{
                    if (accToken==2)
                    {
                        system("CLS");
                        cout<<"Mail has been seen by CEO ... \n Thanks!"<<endl;
                        accToken=0;
                        halt();
                    }
                    
                
                    option=accountantInterface();
                    switch (option)
                    {
                    case '1':
                        makeSalaryReport( managementNames, managementSalary, basicSalary, managementAttendance,managementSalaryStatus, teamSalaryStatus);
                        break;

                    case '2':
                        salaryStatus(managementNames, managementSalaryStatus, teamSalaryStatus);
                        break;

                    case '3':
                        if(saveSalaryStatus( managementSalaryStatus, teamSalaryStatus))
                        {
                            cout<<"Data has been saved successfully...!"<<endl;
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveProductData( productName, productPrice, productNumber);
                            saveCompanyData(companies,companyRequirement);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveManagementAttendance( managementAttendance);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        }
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        halt();
                        goto Start;
                        break;
                    case '4':
                        cout << "Program has been closed successfully...!" << endl;
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveManagementAttendance( managementAttendance);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        halt();
                        
                        break;

                    default:
                        cout<<"You have entered invalid input..!"<<endl;
                        break;
                    }
                }while(option != '4');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@acc.nestle.pk \n\n";
                    goto AccEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
         else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@acc.nestle.pk \n\n";
                goto AccEnterEmail;
            }
            else{
                goto Start;
            }
        }
        
    }

    else if (input=='6')
    {
        
        SHIEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && checkEmailCategory(email,"shi"))
        {
            if(check_EandP(shiEmail,shiPassword,email,password,2))
            {
                do{
                
                    option=SHincharge();
                    switch (option)
                    {
                    case '1':
                        availableProducts(productNumber);
                        if(shiToken=0)
                        {
                            cout<<"Would you like to send mail to CEO,if there is very low stock in our company ? "<<endl;
                            cout<<"Press Y for yes and any other character to leave : ";
                            char y;
                            cin>>y;
                            if(y=='Y' || y=='y')
                            {
                                cout<<"Mail has been sent to CEO"<<endl;
                                shiToken=1;
                                halt();
                            }
                        }   
                        break;

                    case '2':
                        viewTeamsWorkers();
                        break;

                    
                    case '3':
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveManagementAttendance( managementAttendance);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        halt();
                        goto Start;
                        break;
                    case '4':
                        cout << "Program has been closed successfully...!" << endl;
                        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                        saveTeamAttendanve( teamsAttendance);
                        saveProductData( productName, productPrice, productNumber);
                        saveCompanyData(companies,companyRequirement);
                        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                        saveManagementAttendance( managementAttendance);
                        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                        saveManagementData( managementNames, managementSalary, basicSalary);
                        saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        halt();
                        
                        break;
                    default:
                        cout<<"You have entered invalid input..!"<<endl;
                        break;
                    }
                }while(option != '4');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@shi.nestle.pk \n\n";
                    goto SHIEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
        else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@shi.nestle.pk \n\n";
                goto SHIEnterEmail;
            }
            else{
                goto Start;
            }
        }
        
    }
    else if (input=='7')
    {
        
        WHIEnterEmail:
        cout<<"Enter your email address (blank spaces are not allowed): ";
        cin>>email;
        cin.ignore(10,'\n');
        cout<<"Enter your password : ";
        getline(cin,password);
        
        if(emailValidation(email) && checkEmailCategory(email,"whi"))
        {
            if(check_EandP(whiEmail,whiPassword,email,password,2))
            {
                do{
                
                    option=WHinsharge();
                    switch (option)
                    {
                    case '1':
                        
                        cout<<"****************Adding Worker*****************"<<endl<<endl;
                        addTeamWorker(teamCList());

                        break;

                    case '2':
                        cout<<"***************Update Worket******************"<<endl<<endl;
                        updateTeamWorker();
                        break;

                    case '3':
                        cout<<"***************Remove a Worker*****************"<<endl<<endl;
                        removeTeamWorker();
                        break;
                    case '4':
                        cout<<"***************VIEW WORKERS*********************"<<endl;
                        viewTeamsWorkers();
                        break;
                   
                    case '5':
                        
                        case5Again:
                        cout<<"Enter 1 for Attendance "<<endl;
                        cout<<"Enter 2 to View Present people."<<endl;
                        cout<<"Select your option: ";
                        cin>>subInput;
                        if (subInput=='1')
                        {
                            cout<<"***************Attendance***********************"<<endl;
                            attendanceOfTeams(teamsAttendance);
                            cout<<"Attendance has been done successfully..."<<endl;
                        }
                        else if (subInput=='2')
                        {
                            cout<<"****************View Attandance*******************"<<endl;
                            viewAtendanceOfTeams(teamsAttendance);
                        }
                        else
                        {
                            char y;
                            cout<<"You have entered invalid input..."<<endl;
                            cout<<"press y for again input or and other key to leave this portion";
                            cin>>y;
                            if (y=='y' || y=='Y')
                            {
                                goto case5Again;
                            }
                            
                        }
                        halt();
                        
                        
                        
                        break;
                
                    case '6':
                        
                        if (saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary) && saveTeamAttendanve( teamsAttendance))
                        {
                            cout<<"Data has been saved successfully....!"<<endl;
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveProductData( productName, productPrice, productNumber);
                            saveCompanyData(companies,companyRequirement);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveManagementAttendance( managementAttendance);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        }
                        else
                        {
                            cout<<"Due to some error , data has not been saved...!"<<endl;
                        }
                        cout << "\nYour account has been logged out ....!\n\n" << endl;
                        halt();
                        goto Start;
                        break;
                    case '7':
                        if (saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary) && saveTeamAttendanve( teamsAttendance))
                        {
                            cout<<"Data has been saved successfully....!"<<endl;
                            saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                            saveTeamAttendanve( teamsAttendance);
                            saveProductData( productName, productPrice, productNumber);
                            saveCompanyData(companies,companyRequirement);
                            saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                            saveManagementAttendance( managementAttendance);
                            saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                            saveManagementData( managementNames, managementSalary, basicSalary);
                            saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                        }
                        else
                        {
                            cout<<"Due to some error , data has not been saved...!"<<endl;
                        }
                        cout << "Program has been closed successfully...!" << endl;
                        halt();
                        
                        break;
                    default:
                        cout<<"You have entered invalid input..!"<<endl;
                        break;
                    }
                }while(option != '7');
            }
            else{
                cout<<"You have entered Wrong email or password..!"<<endl;
                cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                char y;
                cin>>y;
                if(y=='Y' || y=='y')
                {
                    system("CLS");
                    cout<<"Use valid email address e.g, xyz@whi.nestle.pk \n\n";
                    goto WHIEnterEmail;
                }
                else{
                    goto Start;
                }
            }
        }
        else{
            cout<<"\nInvalid Login attempt...!\n";
            cout<<"Press Y for re-login OR and character to continue...!"<<endl;
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                system("CLS");
                cout<<"Use valid email address e.g, xyz@whi.nestle.pk \n\n";
                goto WHIEnterEmail;
            }
            else{
                goto Start;
            }
        }
        
    }
    else if (input=='8')
    {
        
        teamEnterEmail:
        
        do{
            option = teamsInterface();
            switch (option)
            {
            case '1':
                obEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"ob.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,0))
                    {
                        teamAccounts(email,0);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@ob.team.nestle.pk \n\n";
                            goto obEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n";
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@ob.team.nestle.pk \n\n";
                        goto obEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }

                
                break;

            case '2':
                dmEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"dm.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,1))
                    {
                        teamAccounts(email,1);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@dm.team.nestle.pk \n\n";
                            goto dmEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n";
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@dm.team.nestle.pk \n\n";
                        goto dmEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }
                break;
            
            case '3':
                smEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"sm.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,2))
                    {
                        teamAccounts(email,2);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@sm.team.nestle.pk \n\n";
                            goto smEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n";
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@sm.team.nestle.pk \n\n";
                        goto smEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }
                break;
            case '4':
                lEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"l.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,3))
                    {
                        teamAccounts(email,3);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@l.team.nestle.pk \n\n";
                            goto lEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n";
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@l.team.nestle.pk \n\n";
                        goto lEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }
                break;
            case '5':
                dEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"d.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,4))
                    {
                        teamAccounts(email,4);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@d.team.nestle.pk \n\n";
                            goto lEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n";
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@d.team.nestle.pk \n\n";
                        goto lEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }
                break;
            case '6':
                sEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"s.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,5))
                    {
                        teamAccounts(email,5);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@s.team.nestle.pk \n\n";
                            goto sEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n>>>>Use valid email address e.g, xyz@whi.nestle.pk  \n\n";
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@s.team.nestle.pk \n\n";
                        goto sEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }
                break;
            
            case '7':
                sgEnterEmail:
                cout<<"Enter your email address (blank spaces are not allowed): ";
                cin>>email;
                cin.ignore(10,'\n');
                cout<<"Enter your password : ";
                getline(cin,password);
                if(emailValidation(email) && checkEmailCategory(email,"sg.team"))
                {
                    if(check_EandP_of_team(teamsEmail,teamsPassword,email,password,6))
                    {
                        teamAccounts(email,6);
                    }
                    else{
                        cout<<"You have entered Wrong email or password..!"<<endl;
                        cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                        char y;
                        cin>>y;
                        if(y=='Y' || y=='y')
                        {
                            system("CLS");
                            cout<<"Use valid email address e.g, xyz@sg.team.nestle.pk \n\n";
                            goto sgEnterEmail;
                        }
                        else{
                            goto Start;
                        }
                    }
                }
                else{
                    cout<<"\nInvalid Login attempt...!\n";
                    cout<<"You have entered Wrong email or password..!"<<endl;
                    cout<<"Press Y for re-login OR and character to continue...!"<<endl;
                    char y;
                    cin>>y;
                    if(y=='Y' || y=='y')
                    {
                        system("CLS");
                        cout<<"Use valid email address e.g, xyz@sg.team.nestle.pk \n\n";
                        goto sgEnterEmail;
                    }
                    else{
                        goto Start;
                    }
                }
                break;
            
            case '0':
                if(saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary))
                {
                    cout<<"Data has been saved Sccessfull...!"<<endl;
                }
                else{
                    cout<<"Due to some error, your password has not been saved...!"<<endl;
                }
                saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
                saveTeamAttendanve( teamsAttendance);
                saveProductData( productName, productPrice, productNumber);
                saveCompanyData(companies,companyRequirement);
                saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
                saveManagementAttendance( managementAttendance);
                saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
                saveManagementData( managementNames, managementSalary, basicSalary);
                saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
                cout << "Program has been closed successfully...!" << endl;
                halt();
                
                break;
            default:
                cout<<"You have entered invalid input..!"<<endl;
                break;
            }
        }while(option != '0');
        
        
    }
    else if (input=='0')
    {
        saveTeamData( teamsEmail, teamsName, teamsPassword, teamsSalary);
        saveTeamAttendanve( teamsAttendance);
        saveProductData( productName, productPrice, productNumber);
        saveCompanyData(companies,companyRequirement);
        saveSalaryStatus( managementSalaryStatus, teamSalaryStatus);
        saveManagementAttendance( managementAttendance);
        saveToken(managerToken,rsmToken,dsToken,accToken,shiToken, whiToken);
        saveManagementData( managementNames, managementSalary, basicSalary);
        saveCEOdata( ceoEmail, ceoPassword, ceoName, totalBalance, pendingPayment, priceOfSentProducts, recievedAmount);
        cout<<"Program has been closed successfully...!"<<endl;
        //halt();
    }
    
    else
    {
        cout << "Invalid input" << endl;
        cout << "enter any key to contineou.....";
        getch();
        system("CLS");
        goto Start;
    }
    
    return 0;
}
void welcomeNestle()
{
    cout <<"          _______________________________________________________________________________________"<<endl;
    cout <<"        |*                                                                                       *|"<<endl;
    cout <<"        |       ***         **                                                                    |"<<endl;
    cout <<"        |       *** *       **   *******   *******   **********   **         *******              |"<<endl;
    cout <<"        |       ***   *     **   **        *         **********   **         **                   |"<<endl;
    cout <<"        |       ***     *   **   *****     *******       **       **         *****                |"<<endl;
    cout <<"        |       ***       * **   **              *       **       **      *  **                   |"<<endl;
    cout <<"        |       ***         **   *******   *******       **       *********  *******              |"<<endl;
    cout <<"        |       ______________________________________________________________________            |"<<endl;
    cout <<"        |       ----------------------------------------------------------------------            |"<<endl;
    cout <<"        |       **********************************************************************            |"<<endl;
    cout <<"        |                                                                                         |"<<endl;
    cout <<"        |                                                                                         |"<<endl;
    cout <<"         *_______________________________________________________________________________________*"<<endl;
     
    cout << "        ******************************************************************************************" << endl;
    cout << "                               &&----------Welcome to NESTLE ----------&&                                  " << endl;
    cout << "        ******************************************************************************************" << endl
         << endl;
    
}
void halt()
{
    
    cout<<"Press any key to continue....\n";
    getch();
    system("cls");
}
char idInterface() 
{
    char input;
    cout << "                                         ******************" << endl;
    cout << "                                   #-----Identification menu-----#          " << endl;
    cout << "                                         ******************" << endl;
    cout << endl;
    cout << "                   > Enter 1 for Directer Manager (Directer CEO)." << endl;
    cout << "                   > Enter 2 for Manager." << endl;
    cout << "                   > Enter 3 for RSM & ASM." << endl;
    cout << "                   > Enter 4 for Distributer Supervisor." << endl;
    cout << "                   > Enter 5 for Accountant." << endl;
    cout << "                   > Enter 6 for Stock Handling Incharge ." << endl;
    cout << "                   > Enter 7 for Warehouse Handling Incharge ." << endl;
    cout << "                   > Enter 8 for Team (Workers)." << endl;
    cout << "                   > Enter 0 to save all data and Exit." << endl;
         
    cout << "Enter your option: ";
    cin >> input;
    system("CLS");
    return input;
}

//interfaces
char DMinterface() 
{
    char admin_menu;
    cout << "                                                 ****************************                " << endl;
    cout << "                                                 #-----Director Manager-----#               " << endl;
    cout <<"                                                  ***************************" << endl;
    cout << endl<<endl;
    cout << "> Enter 1 to Checking products. " << endl;
    cout << "> Enter 2 to Check Profit or loss." << endl;
    cout << "> Enter 3 to Check Data of all Workers." << endl;
    cout << "> Enter 4 to Add some Workers." << endl;
    cout << "> Enter 5 to Delete a worker." << endl;
    cout << "> Enter 6 to Check Pending payments." << endl;
    cout << "> Enter 7 to Add Stock." << endl;
    cout << "> Enter 8 to Save Data and Exit from CEO menu." << endl;
    cout << "> Enter 9 to Save Data and Exit from System." << endl
         << endl;
    cout << "enter your option: ";
    cin >> admin_menu;
    system("CLS");
    return admin_menu;
}
char ManagerInterface() 
{
    char customer_menu;
    cout << "                                                   ******************" << endl;
    cout << "                                                   #-----MANAGER-----#            " << endl;
    cout << "                                                   ******************" << endl;
    cout << endl;
    cout << "> Enter 1 to Add a worker ." << endl;
    cout << "> Enter 2 to View Information." << endl;
    cout << "> Enter 3 for Attendance of Management Staff. " << endl;
    cout << "> Enter 4 to Save Data and Exit from User menu." << endl;
    cout << "> Enter 5 to Save Data and Exit from System." << endl
         << endl;
    cout << "enter your option: ";
    cin >> customer_menu;
    system("CLS");
    return customer_menu;
} 


char RSMinterface()
{
    char input;
    cout << "                                                   ******************" << endl;
    cout << "                                                   #-----RSM or ASM-----#            " << endl;
    cout << "                                                   ******************" << endl;
    cout << "> Enter 1 for checking/updating Requirements of Buyyers"<<endl;
    cout << "> Enter 2 for Checking manageent of different areas."<<endl;
    cout << "> Enter 3 to Save Data and Exit from RSM & ASM menu." << endl;
    cout << "> Enter 4 to Save Data and Exit from System." << endl;

    cout << "\nenter your option: ";
    cin >> input;
    system("CLS");
    return input;
}

char DSinterface()
{
    char DS;
    cout << "                                                   *********************************" << endl;
    cout << "                                                   #-----Distributer Supervisor-----#            " << endl;
    cout << "                                                   **********************************" << endl;
    cout<<"> Enter 1 for checking details of Order Bookers."<<endl;
    cout<<"> Enter 2 for Checking requirements of different cpmpanies"<<endl;
    cout<<"> Enter 3 to deliver amount of products"<<endl;
    cout<<"> Enter 4 Checking Stock information "<<endl;
   // cout<<"> Enter 5 For requirements of Different stores "<<endl;
    cout<<"> Enter 5 to Save Data and Exit from Distributer Supervisor's menu." << endl;
    cout<<"> Enter 6 to Save Data and Exit from System." << endl;
    cout << "enter your option: ";
    cin >> DS;
    system("CLS");
    return DS;
}
char accountantInterface()
{
    char input;
    cout << "                                                   **********************" << endl;
    cout << "                                                   #-----Accountant-----#            " << endl;
    cout << "                                                   **********************" << endl;
    cout<<"> Enter 1 to make salery reoprt "<<endl;
    cout<<"> Enter 2 to check salery status "<<endl;
    cout<<"> Enter 3 to Save Data and Exit from Accountant Interface menu." << endl;
    cout<<"> Enter 4 to Save Data and Exit from System." << endl;
    cout<<"\nEnter your option;";
    cin >> input;
    system("CLS");
    return input;
}
char SHincharge()
{
    char input;
    cout << "                                                   **********************************" << endl;
    cout << "                                                   #-----Stock Handling Incharge-----#            " << endl;
    cout << "                                                   ***********************************" << endl;
    cout<<"> Enter 1 View available products. "<<endl;
    cout<<"> Enter 2 View all worker's Information "<<endl;
    cout<<"> Enter 3 to Save Data and Exit from Stock Handling Incharge's menu." << endl;
    cout<<"> Enter 4 to Save Data and Exit from System." << endl;
    cout<<"\nEnter your option : ";
    cin >> input;
    system("CLS");
    return input;
}
char WHinsharge()
{
    char input;
    cout << "                                                   ******************************" << endl;
    cout << "                                                   #-----Warehouse Incharge-----#            " << endl;
    cout << "                                                   ******************************" << endl;
    cout <<"> Enter 1 to add Workers."<<endl;
    cout <<"> Enter 2 to update Worker."<<endl;
    cout <<"> Enter 3 to remove a worker."<<endl;
    cout <<"> Enter 4 View Registered Workers in team "<<endl;
    cout <<"> Enter 5 for Team Attendance ."<<endl;
    cout<<"> Enter 6 to Save Data and Exit from Warehouse Incharge's menu." << endl;
    cout<<"> Enter 7 to Save Data and Exit from System." << endl;
    cout<<"\nEnter your option  : ";
    cin >> input;
    system("CLS");
    return input;

}


char teamsInterface()
{
    char input;
    cout << "                                                   ****************" << endl;
    cout << "                                                   #-----TEAM-----#            " << endl;
    cout << "                                                   ****************"<< endl;
    cout<<"> Enter 1 for Order Bookers "<<endl;
    cout<<"> Enter 2 for Delivery Man "<<endl;
    cout<<"> Enter 3 for Sales Man "<<endl;
    cout<<"> Enter 4 for Driver "<<endl;
    cout<<"> Enter 5 for Loaders "<<endl;
    cout<<"> Enter 6 for Swiper "<<endl;
    cout<<"> Enter 7 for Security Guard "<<endl;
    cout<<"> Enter 0 for save and Exit" << endl;
    cout<<"\nEnter your option  : ";
    cin >> input;
    system("CLS");
    return input;

}
//validators
bool emailValidation(string email)
{
    bool flag=false;
    int size=email.length();
    for(int i=0;i<size;i++)
    {
        if(email[i]=='@')
        {
            if(email[i+1]=='.')
            {
                break;
            }
            else
            {
                for(int j=i+2;j<size;j++)
                {
                    if(email[j]=='.')
                    {
                        if( (email[j+1]=='N'||email[j+1]=='n') && (email[j+2]=='E'||email[j+2]=='e') && (email[j+3]=='S'||email[j+3]=='s') && (email[j+4]=='T'||email[j+4]=='t') && (email[j+5]=='L'||email[j+5]=='l') && (email[j+6]=='E'||email[j+6]=='e'))
                        {
                            if(email[j+7]=='.' && (email[j+8]=='P' ||email[j+8]=='p') && (email[j+9]=='K' ||email[j+9]=='k') )
                            {
                               
                                flag=true;
                                j=size;
                                i=size;
                                break;
                            }
                        }
                    }
                }

            }
        }

    }
    return flag;
}
bool checkEmailCategory(string email,string cat)
{
    bool flag = false;
    int k;
    int size1=email.length();
    int size2=cat.length();
    for(int i=0 ; i<size1 ;i++)
    {
        if(email[i]=='@')
        {
            k=i+1;
            for(int j=0 ;j<size2;j++)
            {
                if(email[k]==cat[j])
                {
                    flag=true;
                }
                else{
                    flag=false;
                    j=size2;
                    i=size1;
                    break;
                }
                k++;
            }
        }
    }

    return flag;
}
bool check_EandP(string emailList[],string passwordList[],string email,string password,int size)
{
    bool flag=false;
    // int sizeE = emailList.length();
    // int sizeP = passwordList.length();
    for(int i=0 ; i<size ; i++)
    {
        if(emailList[i]==email && passwordList[i]==password)
        {
            flag=true ;
            break;
        }
    }
    return flag;

}
bool check_EandP_of_team(string emailList[][5],string passwordList[][5],string email,string password,int rowNo)
{
    bool flag=false;
    // int sizeE = emailList.length();
    // int sizeP = passwordList.length();
    for(int i=0 ; i<5 ; i++)
    {
        if(emailList[rowNo][i]==email && passwordList[rowNo][i]==password)
        {
            flag=true ;
            break;
        }
    }
    return flag;
}


int teamCList()                             //Number of row
{
    int row;
    selectCorrectCategory:
    cout<<"> Enter 1 for Order Bookers "<<endl;
    cout<<"> Enter 2 for Delivery Man "<<endl;
    cout<<"> Enter 3 for Sales Man "<<endl;
    cout<<"> Enter 4 for Driver "<<endl;
    cout<<"> Enter 5 for Loaders "<<endl;
    cout<<"> Enter 6 for Swiper "<<endl;
    cout<<"> Enter 7 for Security Guard "<<endl;
    cout<<"\nSelect category to enter  : ";
    cin >> row;
    system("CLS");
    if (row>=1 && row<=7)
    {
        return row-1;
    }
    else
    {
        cout<<"You have selected wrong category..."<<endl;
        halt();
        goto selectCorrectCategory;
    }
    
    
    
}

int avaiable_placeInTeam(int row)            //No of available column
{
    int i=0;
    while (i<5)
    {
        if (teamsEmail[row][i][0]=='N' && teamsEmail[row][i][1]=='V' && teamsEmail[row][i][2]=='@')
        {
            return i;
            break;   
        }
        i=i+1;
    }
    return -1;
}


void addTeamWorker(int row)              //Adding team
{
    string enterEmail,enterName;
    int col=avaiable_placeInTeam(row);
    teamsSalary[0][0]=20000;
    teamsSalary[1][0]=18000;
    teamsSalary[2][0]=17000;
    teamsSalary[3][0]=19000;
    teamsSalary[4][0]=21000;
    teamsSalary[5][0]=22000;
    teamsSalary[6][0]=23000;
    if (col==-1 || col>4)
    {
        cout<<"\nThere is no more place to add worker in this category...!\n";
        halt();
    }
    else
    {
        cout<<"\nEnter Worker's Email in formate" ;
        TcoutFormate(row);
        cout<<" : ";
        cin>>enterEmail;
        cin.ignore(10,'\n');     
       if (emailValidation(enterEmail))
       {
            cout<<"Enter the Password of worker : ";
            getline(cin,teamsPassword[row][col]);
            teamsEmail[row][col]=enterEmail;
            cout<<"Enter the Name of worker: ";
            getline(cin,teamsName[row][col]);
            teamsSalary[row][col]=teamsSalary[row][0];
            cout<<"Salary of the worker is fixed : ";
            cout<<teamsSalary[row][col];

            cout<<"\n\nWorker has been Entered Successfully..!"<<endl;
            whiToken=1;
       }
        halt();        
    }
        
}
void updateTeamWorker()                  //Updating team
{
    bool flag = false;
    string email;
    enterUpdateEmail:
    int row=teamCList();
    cout<<"Enter Email address of Worker ,you want to update : ";
    cin>>email;
    if (emailValidation(email))
    {
        
        for (int i = 0; i < 5; i++)
        {
            if (teamsEmail[row][i]==email)
            {
                enterNewEmail:
                cout<<"\nEnter Worker's New Email in formate" ;
                TcoutFormate(row);
                
                cout<<" : ";
                cin>>teamsEmail[row][i];
                cin.ignore(10,'\n');
                if (emailValidation(teamsEmail[row][i]))
                {
                    cout<<"Enter the Password of worker : ";
                    getline(cin,teamsPassword[row][i]);
                    // cin.ignore(10,'\n');
                    cout<<"Enter the Name of worker: ";
                    getline(cin,teamsName[row][i]);
                    //cin.ignore(10,'\n');
                    cout<<"Salary of the worker is fixed : ";
                    cout<<teamsSalary[row][0];
                    cout<<"\n\nWorker has been Updated Successfully..!"<<endl;
                    flag=true;
                    halt();
                    break;
                            
                }
                else
                {
                    cout<<"You Have Entered Invalid Email...!"<<endl;
                    halt();              
                    goto enterNewEmail;
                }
                
                

            }
            
        }
        
    }
    else{
        char y='y';
        cout<<"You have entered an invalid email...!"<<endl;
        cout<<"Enter Y to enter email again Or press any character to leave: ";
        cin>>y;
        if (y=='Y' || y=='y')
        {
            goto enterUpdateEmail;
        }
        
    }
    if (flag==false)
    {
        char y='y';
        cout<<"We cannot find Your Desired Email.."<<endl<<endl;
        cout<<"Enter Y to enter email again Or press any character to leave: ";
        cin>>y;
        if (y=='Y' || y=='y')
        {
            goto enterUpdateEmail;
        }
        halt();
    }
}

void TcoutFormate(int row)                //Team Email formate
{
    if (row==0)
    {
        cout<<"(abc@ob.team.nestle.pk)";
    }
    else if (row==1)
    {
        cout<<"(abc@dm.team.nestle.pk)";
    }
    else if (row==2)
    {
        cout<<"(abc@sm.team.nestle.pk)";
    }
    else if (row==3)
    {
        cout<<"(abc@d.team.nestle.pk)";
    }
    else if (row==4)
    {
        cout<<"(abc@l.team.nestle.pk)";
    }
    else if (row==5)
    {
        cout<<"(abc@s.team.nestle.pk)";
    }
    else if (row==6)
    {
        cout<<"(abc@sg.team.nestle.pk)";
    }
}
void removeTeamWorker()                    //Remove team worker
{
    bool flag=false;
    int count=0;
    RemoveAccoune:
    cout<<"Select the category of the worker You want to remove "<<endl;
    int row = teamCList();
    cout<<"Details of yout selected category is given below...\n";
    cout<<left<<setw(5)<<"Sr."<<left<<setw(25)<<"Name"
        <<left<<setw(35)<<"Email"
        <<left<<setw(8)<<"Salary"<<endl;
    for (int i = 0; i < 5; i++)
    {
        if(teamsEmail[row][i][0]!='N' && teamsEmail[row][i][1]!='V')
        {
            cout<<left<<setw(5)<<i+1<<left<<setw(25)<<teamsName[row][i]
            <<left<<setw(35)<<teamsEmail[row][i]
            <<left<<setw(8)<<teamsSalary[row][i]<<endl;
            flag=true;
            
        }
        count++;
    }
    if(flag==true)
        {
        int col;
        cout<<"\nSelect the Number of user, You want to remove : ";
        cin>>col;
        col=col-1;
        if((col>=0 && col<count) && (row >=0 && row < 7))
        {   teamsEmail[row][col][0]='N';
            teamsEmail[row][col][1]='V';
            teamsName[row][col]="NV";
            teamsSalary[row][col]=-1;
            teamsPassword[row][col]="abc";
            cout<<"Account of worker has been removed Successfully..!"<<endl;
            halt();
        }
        else{
            char y;
            cout<<"You are selected wrong category...!"<<endl;
            cout<<"Enter Y to select category again Or press any character to leave: ";
            cin>>y;
            if (y=='Y' || y=='y')
            {
                goto RemoveAccoune;
            }
        }
    }
    else
    {
        cout<<"\nThere is no user to remove..!"<<endl;
        halt();
    }
}
void viewTeamsWorkers()                     //view team
{
    char input;
    int row;
    
    do
    {
        cout<<endl;
        cout<<"Enter 1 If you want to view All Workers"<<endl;
        cout<<"Enter 2 If you want to view According to category"<<endl;
        cout<<"Enter 0 to exit from View menu"<<endl;
        cout<<"\nEnter your option : ";
        cin>>input;
        switch(input)
        {
            case '1':
                cout<<left<<setw(20)<<"Category"
                    <<left<<setw(20)<<"1"
                    <<left<<setw(20)<<"2"
                    <<left<<setw(20)<<"3"
                    <<left<<setw(20)<<"4"
                    <<left<<setw(20)<<"5"
                    <<endl<<endl;
                for (int i = 0; i < 7; i++)
                {
                    if (i==0)
                    {
                        cout<<left<<setw(20)<<"Order Booker";
                    }
                    else if (i==1)
                    {
                        cout<<left<<setw(20)<<"Delivery Man";
                    }
                    else if (i==2)
                    {
                        cout<<left<<setw(20)<<"Sales Man";
                    }
                    else if (i==3)
                    {
                        cout<<left<<setw(20)<<"Driver";
                    }
                    else if (i==4)
                    {
                        cout<<left<<setw(20)<<"Loader";
                    }
                    else if (i==5)
                    {
                        cout<<left<<setw(20)<<"Swiper";
                    }
                    else if (i==6)
                    {
                        cout<<left<<setw(20)<<"Security Guard";
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        
                        if (teamsName[i][j]!="NV")
                        {
                            cout<<left<<setw(20)<<teamsName[i][j];
                        }
                        else
                        {
                            cout<<left<<setw(20)<<"-";
                        }
                        
                        
                    }
                    cout<<endl;
                    
                }
                halt();
                

                break;
            case '2':
                row=teamCList();
                
                cout<<left<<setw(20)<<"Sr."
                    <<left<<setw(25)<<"Name"
                    <<left<<setw(30)<<"Email"
                    <<left<<setw(9)<<"Salary"<<endl<<endl;
                for (int i = 0; i < 5; i++)
                {
                    if (teamsName[row][i]!="NV")
                    {
                        cout<<left<<setw(20)<<i+1
                            <<left<<setw(25)<<teamsName[row][i]
                            <<left<<setw(30)<<teamsEmail[row][i]
                            <<left<<setw(9)<<teamsSalary[row][i]<<endl<<endl;
                        
                    }
                    else
                    {
                        cout<<left<<setw(20)<<i+1
                            <<left<<setw(25)<<"-"
                            <<left<<setw(30)<<"-"
                            <<left<<setw(9)<<"-"<<endl<<endl;
                    }
                    
                    
                }
                halt();

                    
                break;
            case '0':
                cout<<"Menu of View has been closed...!"<<endl;
                halt();
                break;
        }
    } while (input!='0');
    


}
// functions of atttendance
void attendanceOfTeams(bool attandance[12][30][7][5])    //team attandance
{
    int category;
    int worker[5];
    int k=0;
    int day,month,year;
    again:
    cout<<"Enter the date in the specified formate DAY MONTH YEAR (e.g. 13 7 2020) : ";
    cin>>day>>month>>year;
    if(!((day>=1 && day <=30) && (month>=1 && month<=12) && (year==2020 || year==2021)))
    {
        cout<<"You have entered an invalid date...!"<<endl;
        cout<<"Press Y to re-enter date OR and character to leave : ";
        char y;
        cin>>y;
        if(y=='Y' || y=='y')
        {
            goto again;
        }
        
    }
    else{

        category=teamCList();
        cout<<"Workers according to your selected category are given below : \n\n";
        cout<<left<<setw(20)<<"Index Number"<<left<<setw(30)<<"Name"<<endl;
        for (int i = 0; i < 5; i++)
        {
            if (teamsName[category][i]!="NV")
            {
                cout<<left<<setw(20)<<i<<left<<setw(30)<<teamsName[category][i]<<endl;
                k++;
            }
            else{
                cout<<left<<setw(20)<<i<<left<<setw(30)<<"-"<<endl;
            }

        }
        // cout<<"How many persons are present today, from above list : ";
        // cin>>k;
        if(k>0)
        {   
            cout<<"\nWrite the Respective indexes of Present workers  : "<<endl;
            for (int i = 0; i < k; i++)
            {
                cout<<i+1<<". Enter Index : ";
                cin>>worker[i];
            }
            for (int i = 0; i < k; i++)
            {
                attandance[month-1][day-1][category][worker[i]]=true;
            }
        }
        else{
            cout<<"Nobody has been entered in this category...!"<<endl;
        }
    
    }
    
}
void viewAtendanceOfTeams(bool attandance[12][30][7][5])         // View team attendance
{
    char input;
    int day,month,year;

    case5Again:
    cout<<"Enter 1 to view Today's Present "<<endl;
    cout<<"Enter 2 to View Monthly Presents."<<endl;
    cout<<"Enter 3 to View Yearly Presents."<<endl;
    cout<<"Enter 4 to View Today's Absents."<<endl;
    cout<<"Enter 5 to View Monthly Absents."<<endl;
    cout<<"Enter 6 to View Yearly Absents."<<endl;
    cout<<"\n Enter your option : ";
    cin>>input;
    if (input=='1')
    {
        again:
        cout<<"\nEnter the date in the specified formate DAY MONTH YEAR (e.g. 13 7 2020) : ";
        cin>>day>>month>>year;
        if(!((day>=1 && day <=30) && (month>=1 && month<=12) && (year==2020 || year==2021)))
        {
            cout<<"You have entered an invalid date...!"<<endl;
            cout<<"Press Y to re-enter date OR and character to leave : ";
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                goto again;
            }

        }
        else{

            cout<<left<<setw(20)<<"Category"
                        <<left<<setw(20)<<"1"
                        <<left<<setw(20)<<"2"
                        <<left<<setw(20)<<"3"
                        <<left<<setw(20)<<"4"
                        <<left<<setw(20)<<"5"
                        <<endl<<endl;
            for (int i = 0; i < 7; i++)
            {
                if (i==0)
                {
                    cout<<left<<setw(20)<<"Order Booker";
                }
                else if (i==1)
                {
                    cout<<left<<setw(20)<<"Delivery Man";
                }
                else if (i==2)
                {
                    cout<<left<<setw(20)<<"Sales Man";
                }
                else if (i==3)
                {
                    cout<<left<<setw(20)<<"Driver";
                }
                else if (i==4)
                {
                    cout<<left<<setw(20)<<"Loader";
                }
                else if (i==5)
                {
                    cout<<left<<setw(20)<<"Swiper";
                }
                else if (i==6)
                {
                    cout<<left<<setw(20)<<"Security Guard";
                }
                for (int j = 0; j < 5; j++)
                {

                    if (teamsAttendance[month-1][day-1][i][j]!=false && teamsName[i][j]!="NV")
                    {
                        cout<<left<<setw(20)<<teamsName[i][j];
                    }
                    if (teamsAttendance[month-1][day-1][i][j]==false && teamsName[i][j]!="NV")
                    {
                        cout<<left<<setw(20)<<"A"; 
                    }
                    else if(teamsName[i][j]=="NV")
                    {
                        cout<<left<<setw(20)<<"-";
                    }


                }
                cout<<endl;

            }
        }
        halt();

    }
    else if (input=='2')
    {
        int row;
        cout<<"\nSelect category you want to search : "<<endl;
        row = teamCList();
        monthAgain:
        cout<<"Enter your desired month(in mumber i.e. 1,2,3..etc.): ";
        cin>>month;
        if(!(month>=1 && month<=12))
        {
            cout<<"You have selected a wrong option...!"<<endl;
            char y;
            cout<<"Enter Y to re-enter month OR any character to leave : ";
            cin>>y;
            if(y=='Y' || y=='y')
            {
                goto monthAgain;
            }
        }
        else{
            cout<<"\n\nAttendance accouding to your selected month is : "<<endl;
            diaplayMonth(month-1);
            cout<<"**************************************************************************"<<endl;
            // for (int row = 0; row < 7; row++)
            // {
                if (row==0)
                {
                    cout<<left<<setw(20)<<"                Order Booker"<<endl;
                }
                else if (row==1)
                {
                    cout<<left<<setw(20)<<"                Delivery Man"<<endl;
                }
                else if (row==2)
                {
                    cout<<left<<setw(20)<<"                Sales Man"<<endl;
                }
                else if (row==3)
                {
                    cout<<left<<setw(20)<<"                Driver"<<endl;
                }
                else if (row==4)
                {
                    cout<<left<<setw(20)<<"                Loader"<<endl;
                }
                else if (row==5)
                {
                    cout<<left<<setw(20)<<"                Swiper"<<endl;
                }
                else if (row==6)
                {
                    cout<<left<<setw(20)<<"                Security Guard"<<endl;
                }

            // }
            for (int i = 0; i < 30; i++)
            {
                cout<<i+1<<"\t";
                for (int j = 0; j < 5; j++)
                {

                    if (attandance[month-1][i][row][j]!=false && teamsName[row][j]!="NV")
                    {
                        cout<<left<<setw(20)<<teamsName[row][j];
                    }
                    if (attandance[month-1][i][row][j]==false && teamsName[row][j]!="NV")
                    {
                        cout<<left<<setw(20)<<"A";
                    }
                    else if(teamsName[row][j]=="NV" )
                    {
                        cout<<left<<setw(20)<<"-";
                    }
                }
                cout<<endl;
            }
        }
        halt();
        
    }
    else if (input=='3')
    {
        int row;
        cout<<"\nSelect category you want to search : "<<endl;
        row = teamCList();
        for (int month = 0; month < 12; month++)
        {
            diaplayMonth(month);
            cout<<"**************************************************************************"<<endl;
            // for (int row = 0; row < 7; row++)
            // {
            if (row==0)
            {
                cout<<left<<setw(20)<<"                Order Booker"<<endl;
            }
            else if (row==1)
            {
                cout<<left<<setw(20)<<"                Delivery Man"<<endl;
            }
            else if (row==2)
            {
                cout<<left<<setw(20)<<"                Sales Man"<<endl;
            }
            else if (row==3)
            {
                cout<<left<<setw(20)<<"                Driver"<<endl;
            }
            else if (row==4)
            {
                cout<<left<<setw(20)<<"                Loader"<<endl;
            }
            else if (row==5)
            {
                cout<<left<<setw(20)<<"                Swiper"<<endl;
            }
            else if (row==6)
            {
                cout<<left<<setw(20)<<"                Security Guard"<<endl;
            }

        //     }
            for (int i = 0; i < 30; i++)
            {
                cout<<i+1<<"\t";
                for (int j = 0; j < 5; j++)
                {

                    if (attandance[month][i][row][j]!=false && teamsName[row][j]!="NV")
                    {
                        cout<<left<<setw(20)<<teamsName[row][j];
                    }
                    if (attandance[month][i][row][j]==false && teamsName[row][j]!="NV")
                    {
                        cout<<left<<setw(20)<<"A";
                    }
                    else if(teamsName[row][j]=="NV" )
                    {
                        cout<<left<<setw(20)<<"-";
                    }
                }
                cout<<endl;
            }
        }
        
    }
    else if (input=='4')
    {
        again1:
        cout<<"\nEnter the date in the specified formate DAY MONTH YEAR (e.g. 13 7 2020) : ";
        cin>>day>>month>>year;
        if(!((day>=1 && day <=30) && (month>=1 && month<=12) && (year==2020 || year==2021)))
        {
            cout<<"You have entered an invalid date...!"<<endl;
            cout<<"Press Y to re-enter date OR and character to leave : ";
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                goto again1;
            }

        }
        else{    
            cout<<left<<setw(20)<<"Category"
                        <<left<<setw(20)<<"1"
                        <<left<<setw(20)<<"2"
                        <<left<<setw(20)<<"3"
                        <<left<<setw(20)<<"4"
                        <<left<<setw(20)<<"5"
                        <<endl<<endl;
            for (int i = 0; i < 7; i++)
            {
                if (i==0)
                {
                    cout<<left<<setw(20)<<"Order Booker";
                }
                else if (i==1)
                {
                    cout<<left<<setw(20)<<"Delivery Man";
                }
                else if (i==2)
                {
                    cout<<left<<setw(20)<<"Sales Man";
                }
                else if (i==3)
                {
                    cout<<left<<setw(20)<<"Driver";
                }
                else if (i==4)
                {
                    cout<<left<<setw(20)<<"Loader";
                }
                else if (i==5)
                {
                    cout<<left<<setw(20)<<"Swiper";
                }
                else if (i==6)
                {
                    cout<<left<<setw(20)<<"Security Guard";
                }
                for (int j = 0; j < 5; j++)
                {

                    if (teamsAttendance[month-1][day-1][i][j]==false && teamsName[i][j]!="NV")
                    {
                        cout<<left<<setw(20)<<teamsName[i][j];
                    }
                    if (teamsAttendance[month-1][day-1][i][j]!=false && teamsName[i][j]!="NV")
                    {
                        cout<<left<<setw(20)<<"P"; 
                    }
                    else if(teamsName[i][j]=="NV")
                    {
                        cout<<left<<setw(20)<<"-";
                    }


                }
                cout<<endl;

            }
        }
        halt();
    }
    else if (input=='5')
    {
        int row;
        cout<<"\nSelect category you want to search : "<<endl;
        row = teamCList();
        cout<<"Enter your desired month(in mumber i.e. 1,2,3..etc.): ";
        cin>>month;
        cout<<"\n\nAttendance accouding to your selected month is : "<<endl;
        diaplayMonth(month);
        cout<<"**************************************************************************"<<endl;
        // for (int row = 0; row < 7; row++)
        // {
            if (row==0)
            {
                cout<<left<<setw(20)<<"                Order Booker"<<endl;
            }
            else if (row==1)
            {
                cout<<left<<setw(20)<<"                Delivery Man"<<endl;
            }
            else if (row==2)
            {
                cout<<left<<setw(20)<<"                Sales Man"<<endl;
            }
            else if (row==3)
            {
                cout<<left<<setw(20)<<"                Driver"<<endl;
            }
            else if (row==4)
            {
                cout<<left<<setw(20)<<"                Loader"<<endl;
            }
            else if (row==5)
            {
                cout<<left<<setw(20)<<"                Swiper"<<endl;
            }
            else if (row==6)
            {
                cout<<left<<setw(20)<<"                Security Guard"<<endl;
            }

        // }
        for (int i = 0; i < 30; i++)
        {
            cout<<i+1<<"\t";
            for (int j = 0; j < 5; j++)
            {
                
                if (attandance[month-1][i][row][j]!=false && teamsName[row][j]!="NV")
                {
                    cout<<left<<setw(20)<<"P";
                }
                if (attandance[month-1][i][row][j]==false && teamsName[row][j]!="NV")
                {
                    cout<<left<<setw(20)<<teamsName[row][j];
                }
                else if(teamsName[row][j]=="NV" )
                {
                    cout<<left<<setw(20)<<"-";
                }
            }
            cout<<endl;
        }
    }
    else if (input=='6')
    {
        int row;
        cout<<"\nSelect category you want to search : "<<endl;
        row = teamCList();
        for (int month = 0; month < 12; month++)
        {
            diaplayMonth(month);
            cout<<"**************************************************************************"<<endl;
            // for (int row = 0; row < 7; row++)
            // {
            if (row==0)
            {
                cout<<left<<setw(20)<<"                Order Booker"<<endl;
            }
            else if (row==1)
            {
                cout<<left<<setw(20)<<"                Delivery Man"<<endl;
            }
            else if (row==2)
            {
                cout<<left<<setw(20)<<"                Sales Man"<<endl;
            }
            else if (row==3)
            {
                cout<<left<<setw(20)<<"                Driver"<<endl;
            }
            else if (row==4)
            {
                cout<<left<<setw(20)<<"                Loader"<<endl;
            }
            else if (row==5)
            {
                cout<<left<<setw(20)<<"                Swiper"<<endl;
            }
            else if (row==6)
            {
                cout<<left<<setw(20)<<"                Security Guard"<<endl;
            }

        //     }
            for (int i = 0; i < 30; i++)
            {
                cout<<i+1<<"\t";
                for (int j = 0; j < 5; j++)
                {

                    if (attandance[month][i][row][j]!=false && teamsName[row][j]!="NV")
                    {
                        cout<<left<<setw(20)<<"P";
                    }
                    if (attandance[month][i][row][j]==false && teamsName[row][j]!="NV")
                    {
                        cout<<left<<setw(20)<<teamsName[row][j];
                    }
                    else if(teamsName[row][j]=="NV" )
                    {
                        cout<<left<<setw(20)<<"-";
                    }
                }
                cout<<endl;
            }
        }
    }
    else
    {
        char y;
        cout<<"You have entered invalid input..."<<endl;
        cout<<"press y for again input or and other key to leave this portion";
        cin>>y;
        if (y=='y' || y=='Y')
        {
            goto case5Again;
        }
    }
    
    
        
}


void diaplayMonth(int month)                      //Display Months
{           
    if (month==0)
    {
        cout<<"                                         JANAUARY"<<endl;
    }
    else if (month==1)
    {
        cout<<"                                         FEBRUARY"<<endl;
    }
    
    else if (month==2)
    {
        cout<<"                                         MARCH"<<endl;
    }
    
    else if (month==3)
    {
        cout<<"                                         APRIL"<<endl;
    }
    
    else if (month==4)
    {
        cout<<"                                         MAY"<<endl;
    }
    
    else if (month==5)
    {
        cout<<"                                         JUNE"<<endl;
    }
    
    else if (month==6)
    {
        cout<<"                                         JULY"<<endl;
    }
    
    else if (month==7)
    {
        cout<<"                                         AUGUST"<<endl;
    }
    
    else if (month==8)
    {
        cout<<"                                         SEPTEMBER"<<endl;
    }
    
    else if (month==9)
    {
        cout<<"                                         OCTOBER"<<endl;
    }
    
    else if (month==10)
    {
        cout<<"                                         NOVEMBER"<<endl;
    }
    
    else if (month==11)
    {
        cout<<"                                         DECEMBER"<<endl;
    }
    
    
}

void teamAccounts(string email,int row)           //accounts of teams
{
    string category;
    int col;
    for (int i = 0; i < 5; i++)
    {
        if(teamsEmail[row][i]==email && teamsName[row][i]!= "NV")
        {
            col=i;
            break;
        }

    }
    if (row==0)
    {
        category = "Order Booker";
    }
    else if (row==1)
    {
        category = "Delivery Man";
    }
    else if (row==2)
    {
        category = "Sales Man";
    }
    else if (row==3)
    {
        category = "Driver";
    }
    else if (row==4)
    {
        category = "Loader";
    }
    else if (row==5)
    {
        category = "Swiper";
    }
    else if (row==6)
    {
        category = "Security Guard";
    }
    char p='n';
    string password;
    string newPassword;
    string confirmPassword;
    menu : 
    cout<<"                   "<<category<<endl;
    cout<<"*****************************************************"<<endl;
    cout<<left<<setw(35)<<"Name"<<right<<setw(35)<<teamsName[row][col]<<endl;
    cout<<left<<setw(35)<<"Team Category"<<right<<right<<setw(35)<<category<<endl;
    cout<<left<<setw(35)<<"Salary"<<right<<right<<setw(35)<<teamsSalary[row][col]<<endl;
    cout<<left<<setw(35)<<"Email address"<<right<<right<<setw(35)<<teamsEmail[row][col]<<endl;
    cout<<"\nIf you want to update your password ,press P (else any character to continue): ";
    cin>>p;
    cin.ignore(2,'\n');
    if(p=='P' ||p=='p')
    {
        incorrect:
        cout<<"Enter your previous password : ";
        getline(cin,password);
        if (password == teamsPassword[row][col])
        {
            confirm:
            cout<<"Enter your new Password : ";
            getline(cin,newPassword);
            
            cout<<"Confirm your new Password : ";
            getline(cin,confirmPassword);
            if (newPassword==confirmPassword)
            {
                teamsPassword[row][col] = newPassword;
                cout<<"\nYou password has been updated Successfully...\n";
            }
            else
            {
                cout<<"You din not write same password in both colomns\n";
                char y;
                cin.ignore(2,'\n');
                cout<<"Press y to re-enter the password : ";
                cin>>y;
                if (y=='Y' || y=='y')
                {
                    goto confirm;    
                }
                
                
            }
            
            

        }
        else
        {
            cout<<"You have entered an Incorrect password\n";
            char y;
            cout<<"Press y to re-enter the password : ";
            cin>>y;
            cin.ignore(2,'\n');
            if (y=='Y' || y=='y')
            {
                goto incorrect;    
            }
            
            
        }
            
        
    goto menu;
        
    }    
}

void availableProducts(int productNumber[8][100]) 
{      // display available and unavailable products
    int k=0;
    cout<<"Available products"<<endl;
    cout<<left<<setw(10)<<"No."<<left<<setw(15)<<"Name"<<left<<setw(15)<<"Available"<<left<<setw(15)<<"Unavailable"<<endl;
    for (int i = 0; i < 8; i++)
    {
        int counterA = 0;
        int counterU = 0;
        cout<<left<<setw(10)<<k+1;
        displayProductName(i);
        
        for (int j = 0; j < 100; j++)
        {
            if (productNumber[i][j]!=0)
            {
                counterA=counterA+1;
            }
            
            if (productNumber[i][j]==0)
            {
                counterU=counterU+1;
            }
            
        }
        cout<<left<<setw(15)<<counterA<<left<<setw(15)<<counterU<<endl;
        k++;
    }
}

void displayProductName(int row)
{         //it can display a specific product name according to input para meter
    if (row==0)
    {
        cout<<left<<setw(15)<<"Fruita Vitals";
    }
    if (row==1)
    {
        cout<<left<<setw(15)<<"Coffee";
    }
    else if (row==2)
    {
        cout<<left<<setw(15)<<"Nido";
    }
    else if (row==3)
    {
        cout<<left<<setw(15)<<"Milk";
    }
    else if (row==4)
    {
        cout<<left<<setw(15)<<"Chocolates";
    }
    else if (row==5)
    {
        cout<<left<<setw(15)<<"Kitkat";
    }
    else if (row==6)
    {
        cout<<left<<setw(15)<<"Juice";
    }
    else if (row==7)
    {
        cout<<left<<setw(15)<<"cheeze";
    }
    
    
}

void viewCompanyRequirements(int companyRequirement[5][8][100],string companies[5])
{             //requirements of different companies
    cout<<"\n*************************Requirement***********************\n\n";
 
    cout<<left<<setw(20)<<"Name";
    for (int i = 0; i < 8; i++)
    {
        displayProductName(i);
    }
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<left<<setw(20)<<companies[i];
        for (int j= 0; j < 8; j++)
        {
            int counter=0;
            for (int k = 0; k < 100; k++)
            {
                if (companyRequirement[i][j][k]!=0)
                {
                    counter++;
                }
                
            }
            cout<<left<<setw(15)<<counter;
        }
        cout<<endl;
        
    }
    
}

void detailsOfOB()
{          //Details of order bookers
    int day,month,year;
    cout<<"*******************Order Bookers****************"<<endl;
    cout<<"Enter today's date in the following formate(DAY MONTH YEAR e.g. 20 12 2200) : ";
    cin>>day>>month>>year;
    
    cout<<left<<setw(20)<<"Name"
    <<left<<setw(20)<<"Present/Absent"
    <<endl;
    for (int i = 0; i < 5; i++)
    {
        if(teamsName[0][i]!="NV")
        {
            cout<<left<<setw(20)<<teamsName[0][i];
            if (teamsAttendance[month-1][day-1][0][i]==true)
            {
                cout<<left<<setw(20)<<"Present";
            }
            else
            {
                cout<<left<<setw(20)<<"Absent";
            }
            cout<<endl;
            
        }
    }
    halt();    
}

void deliverProducts(string companies[5],int companyRequirements[5][8][100],int productNumber[8][100],int productPrice[8][100])
{     // Delivery of products
    
    double sentAmount=0;
    double recieved=0;
    double sent=0;
    long sum = 0;
    double profit=0;
    bool flag=false;
    int product,company,amount;
    int count1=0 ,count2=0;
    deliverProduct:
    availableProducts(productNumber);
    cout<<"\nSelect product : ";
    cin>>product;
    cout<<left<<setw(10)<<"No."<<left<<setw(20)<<"Company Name"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<left<<setw(10)<<i+1<<left<<setw(20)<<companies[i]<<endl;
    }
    cout<<"\nSelect Buyyer : ";
    cin>>company;
    viewCompanyRequirements(companyRequirements,companies);
    cout<<"\nEnter amount : ";
    cin>>amount;

    for (int i = 0; i < 100; i++)
    {
        if (productNumber[product-1][i]==1 && count1 != amount)
        {
            productNumber[product-1][i]=0;
            flag=true;
            sum = sum+productPrice[product-1][i];
            profit = profit + ((productPrice[product-1][i]*15) / 100);
            count1++;
            //cout<<productPrice[product-1][i]<<endl;
        }
        
        if (companyRequirements[company-1][product-1][i]==1 && count2 != amount)
        {
            companyRequirements[company-1][product-1][i]=0;
            count2++;
        }
        
    }
    sentAmount= sentAmount + (sum + profit);
    recieved = recieved + profit;
    sent = sent + sum;
    if (flag)
    {
        cout<<"Products has been delivered successfully...!"<<endl;
        halt();
    }
    else
    {
        cout<<"You don't have more available products in this caregory..."<<endl;
        halt();
    }
    
    
    char y;
    cout<<"Whould you like to deliver more products?\nPress Y for Yes OR any other character for No : ";
    cin>>y;
    if (y=='Y' || y=='y')
    {
        goto deliverProduct;
    }
    char free;
    cout<<"If you have recieved all amount, then press Y else any character to continue  : ";
    cin>>free;
    if (free=='y' || free=='Y')
    {
        totalBalance = totalBalance + sentAmount + pendingPayment;
        priceOfSentProducts = priceOfSentProducts + sent;
        recievedAmount = recievedAmount + recieved;
        pendingPayment = 0;
        dsToken=2;
    }
    else
    {
        pendingPayment = pendingPayment + sentAmount;
        dsToken=1;
    }
    
    
    char tokenFree;
    if (rsmToken==1)
    {
        cout<<"RSM:\nWould you like to stop the Remainder of RSM??\nEnter Y to stop OR any other character for panding";
        cin>>tokenFree;
        if(tokenFree=='Y' || tokenFree=='y')
        {
            rsmToken=-1;
            cout<<"Your remainder has been stopped Successfully...!"<<endl;
            halt();
        }
        else
        {
            cout<<"Your remainder is pending"<<endl;
            halt();
        }
        

    }
    
    
    
}

void updatingRequirementsOfBuyyer(int companyRequirement[5][8][100],string companies[5],int productNumber[8][100])
{    //Buyyer's Requirements
    updatesRequirements:
    bool flag=false;
    int company,product,amount;
    for (int i = 0; i < 5; i++)
    {
        cout<<left<<setw(10)<<i+1<<left<<setw(20)<<companies[i]<<endl;
    }
    cout<<"\nSelect Buyyer : ";
    cin>>company;
    availableProducts(productNumber);
    cout<<"\nSelect product : ";
    cin>>product;
    viewCompanyRequirements(companyRequirement,companies);
    cout<<"\nEnter amount : ";
    cin>>amount;
    int counter=0;
    int i=0;
    while (i<100)
    {
        if (companyRequirement[company-1][product-1][i]==0 && counter != amount)
        {
            companyRequirement[company-1][product-1][i]=1;
            counter++;
            flag = true;
        }
        i++;
    }
    if (flag)
    {
        cout<<"Requirements of the buyyer updated...!"<<endl;
        halt();
    }
    else
    {
        cout<<"We cannot send more data to this buyyer..."<<endl;
        halt();
    }
    char y;
    cout<<"Would you like to reuse this option?\nPress Y for Yes OR any other character for No : ";
    cin>>y;
    if (y=='Y' || y=='y')
    {
        goto updatesRequirements;
    }
    char mail;
    cout<<"\nAs your work has been done, would you like to send a Mail to Distributer Supervisor about updated requirements???\n";
    cout<<"Press Y for Yes OR any other character for No : ";
    cin>>mail;
    if (mail=='Y' || mail=='y')
    {
        rsmToken=1;
        cout<<"Mail has been sent to Distributer Supervision"<<endl;
        halt();
    }
    else
    {
        cout<<"Now,Updating has been done..."<<endl;
        halt();
    }
    

    
}
void managementOfAreas(string companies[5],int companyRequirements[5][8][100],int productNumber[8][100])
{      //area management
    areaManagenemt:
    int company;
    cout<<"We have following Buyyers : "<<endl;
    cout<<left<<setw(10)<<"Sr."<<left<<setw(30)<<"Name"<<endl<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<left<<setw(10)<<i+1<<left<<setw(30)<<companies[i]<<endl;
    }
    cout<<"\nSelect the number any Buyyer : ";
    cin>>company;
    cout<<"____________________________________________________________________________________"<<endl;
    cout<<"                  #*************"<<companies[company-1]<<"**************#"<<endl;
    cout<<"____________________________________________________________________________________"<<endl;
    for (int i = 0; i < 8; i++)
    {
        int counter=0;
        for (int j = 0; j < 100; j++)
        {
            
            if (companyRequirements[company-1][i][j] != 0)
            {
                counter++;
            }
            
        }
        cout<<"| ";
        displayProductName(i);
        cout<<right<<setw(65)<<counter<<" |"<<endl;
        
    }
    cout<<"____________________________________________________________________________________"<<endl;
    char y;
    cout<<"Would you like to reuse this option?\nPress Y for Yes OR any other character for No : ";
    cin>>y;
    if (y=='Y' || y=='y')
    {
        goto areaManagenemt;
    }
    
}

void initializeProductPrice(int productPrice[8][100])
{//initializing products prics
    for (int i = 1; i < 100; i++)
    {
        productPrice[0][i]= productPrice[0][0];
        productPrice[1][i]= productPrice[1][0];
        productPrice[2][i]= productPrice[2][0];
        productPrice[3][i]= productPrice[3][0];
        productPrice[4][i]= productPrice[4][0];
        productPrice[5][i]= productPrice[5][0];
        productPrice[6][i]= productPrice[6][0];
        productPrice[7][i]= productPrice[7][0];
    }
    
}

void initializeManagementData(string managementNames[6][2],int managementSalary[6][2],bool managementAttendance[12][30][6][2],bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5])                 
{  //initializing management data   
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            managementNames[i][j]="NV";
            managementSalary[i][j]=-1;
            managementSalaryStatus[i][j]=false;
        }
        
    }
    for (int i = 0; i < 12; i++)       
    {
        for (int k = 0; k < 30; k++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int m = 0; m < 2; m++)
                {
                    managementAttendance[i][k][j][m]=false;
                       
                }
                
                
            }
            
        }
        
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            teamSalaryStatus[i][j]=false;
        }
        
    }
    

}
void makeSalaryReport(string managementNames[6][2],int managementSalary[6][2],int basicSalary[6],bool managementAttendance[12][30][6][2],bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5])                    //Making salary report
{
    int category,persons;
    char input;
    cout<<"***********************Maing Salary*********************"<<endl;
    cout<<"Enter 1 for checking balance of company"<<endl;
    cout<<"Enter 2 for Management salary"<<endl;
    cout<<"Enter 3 for Teams salary"<<endl;
    cout<<"\nSelect your option : ";
    cin>>input;
    if (input=='1')
    {
        cout<<"*****************************************************"<<endl;
        cout<<"              Balance=         "<<totalBalance<<"\\-"<<endl;
        cout<<"*****************************************************"<<endl;
        halt();
    }
    else if (input=='2')
    {
        cout<<left<<setw(20)<<"Sr."<<left<<setw(30)<<"Category"
                    <<left<<setw(30)<<"1"
                    <<left<<setw(30)<<"2"
                    <<left<<setw(30)<<"Salary"
                    <<endl<<endl;
                for (int i = 0; i < 6; i++)
                {
                    if (i==0)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(30)<<"Manager";
                    }
                    else if (i==1)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(30)<<"RSM";
                    }
                    else if (i==2)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(30)<<"Distributer Supervisor";
                    }
                    else if (i==3)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(30)<<"Accountant";
                    }
                    else if (i==4)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(30)<<"Stock Handling Incgarge";
                    }
                    else if (i==5)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(30)<<"Warehouse Inchage";
                    }
                    
                    for (int j = 0; j < 2; j++)
                    {
                        
                        if (managementNames[i][j]!="NV")
                        {
                            cout<<left<<setw(30)<<managementNames[i][j];
                        }
                        else
                        {
                            cout<<left<<setw(30)<<"-";
                        }
                        
                        
                    }
                    cout<<left<<setw(30)<<basicSalary[i];
                    cout<<endl;
                    
                }
                cout<<"\nSelect a category(1-6) : ";
                cin>>category;
                cout<<"\nEnter persons(1-2) : ";
                cin>>persons;
                int k=0;
                if (category>0 && category<=6 && persons<=2 && persons>0)
                {
                   for (int i = 0; k < persons && i!=2; i++)
                    {
                        if(managementSalaryStatus[category-1][i]==false && managementNames[category-1][i]!="NV")
                        {
                            managementSalaryStatus[category-1][i]=true;
                            accToken=1;
                            k++;
                        }
                        
                    }
                    totalBalance=totalBalance-(k*(basicSalary[category-1]));
                    if (accToken==1)
                    {
                        system("CLS");
                        cout<<"Mail of amount deduction has been sent to the CEO..."<<endl;
                    }
                    

                }
                else{
                    cout<<"Invalid Options..."<<endl;
                }
                
                
                
                halt();
        
    }
    else if (input=='3')
    {
        cout<<left<<setw(20)<<"Sr."<<left<<setw(20)<<"Category"
                    <<left<<setw(20)<<"1"
                    <<left<<setw(20)<<"2"
                    <<left<<setw(20)<<"3"
                    <<left<<setw(20)<<"4"
                    <<left<<setw(20)<<"5"
                    <<left<<setw(20)<<"Salary"
                    <<endl<<endl;
                for (int i = 0; i < 7; i++)
                {
                    if (i==0)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Order Booker";
                    }
                    else if (i==1)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Delivery Man";
                    }
                    else if (i==2)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Sales Man";
                    }
                    else if (i==3)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Driver";
                    }
                    else if (i==4)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Loader";
                    }
                    else if (i==5)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Swiper";
                    }
                    else if (i==6)
                    {
                        cout<<left<<setw(20)<<i+1<<left<<setw(20)<<"Security Guard";
                    }
                    for (int j = 0; j < 5; j++)
                    {
                        
                        if (teamsName[i][j]!="NV")
                        {
                            cout<<left<<setw(20)<<teamsName[i][j];
                        }
                        else
                        {
                            cout<<left<<setw(20)<<"-";
                        }
                        
                        
                    }
                    cout<<left<<setw(20)<<teamsSalary[i][0];
                    cout<<endl;
                    
                }
                cout<<"\nSelect a category(1-7) : ";
                cin>>category;
                cout<<"\nEnter persons(1-5) : ";
                cin>>persons;
                int k=0;
                if (category>0 && category<=7 && persons<=5 && persons>0)
                {
                   for (int i = 0; k < persons && i!=5; i++)
                    {
                        if (teamSalaryStatus[category-1][i]==false && teamsName[category-1][i]!="NV")
                        {
                            teamSalaryStatus[category-1][i]=true;
                            accToken=1;
                            k++;
                        }
                        
                    }
                    totalBalance=totalBalance-(k*(teamsSalary[category-1][0]));
                    if (accToken==1)
                    {
                        system("CLS");
                        cout<<"Mail of amount deduction has been sent to the CEO..."<<endl;
                    }
                    

                }
                else{
                    cout<<"Invalid Options..."<<endl;
                }
                
                
                
                halt();
        
    }
    else{
        cout<<"You have selected invalid option..."<<endl;
    }
    
    
    
}

void salaryStatus(string managementNames[6][2],bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5])       //display samary status
{
    char input;
    cout<<"*************************View Salary Status**************************\n\n";
    cout<<"Enter 1 for Management salary"<<endl;
    cout<<"Enter 2 for Teams salary"<<endl;
    cout<<"\nSelect your option : ";
    cin>>input;
    if (input=='1')
    {
        cout<<"*****************Management**********************\n\n";
        cout<<left<<setw(10)<<"Sr."<<left<<setw(25)<<"Category"<<left<<setw(20)<<"Name"<<left<<setw(10)<<"yes/no"
        <<left<<setw(20)<<"Name"<<left<<setw(10)<<"Yes/No"<<endl;
        for (int i = 0; i < 6; i++)
        {
            if (i==0)
            {
                cout<<left<<setw(10)<<i+1<<left<<setw(25)<<"Manager";
            }
            else if (i==1)
            {
                cout<<left<<setw(10)<<i+1<<left<<setw(25)<<"RSM";
            }
            else if (i==2)
            {
                cout<<left<<setw(10)<<i+1<<left<<setw(25)<<"Distributer Supervisor";
            }
            else if (i==3)
            {
                cout<<left<<setw(10)<<i+1<<left<<setw(25)<<"Accountant";
            }
            else if (i==4)
            {
                cout<<left<<setw(10)<<i+1<<left<<setw(25)<<"Stock Handling Incgarge";
            }
            else if (i==5)
            {
                cout<<left<<setw(10)<<i+1<<left<<setw(25)<<"Warehouse Inchage";
            }
            for (int j = 0; j < 2; j++)
            {
                if(managementNames[i][j]!="NV" )
                {
                    cout<<left<<setw(20)<<managementNames[i][j];
                    if (managementSalaryStatus[i][j]==true)
                    {
                        cout<<left<<setw(10)<<"=Yes";
                    }
                    else
                    {
                        cout<<left<<setw(10)<<"=No";
                    }
                    
                    

                }
                else
                {
                    cout<<left<<setw(20)<<"-";
                    if (managementSalaryStatus[i][j]==true)
                    {
                        cout<<left<<setw(10)<<"-";
                    }
                    else
                    {
                        cout<<left<<setw(10)<<"-";
                    }
                }
                                
            }
            cout<<endl;
            
        }
        
    }
    else if (input=='2')
    {
        int row=teamCList();
        cout<<"----------------------------------"<<endl;
        if (row==0)
        {
            cout<<"Order Booker";
        }
        else if (row==1)
        {
            cout<<"Delivery Man";
        }
        else if (row==2)
        {
            cout<<"Sales Man";
        }
        else if (row==3)
        {
            cout<<"Driver";
        }
        else if (row==4)
        {
            cout<<"Loader";
        }
        else if (row==5)
        {
            cout<<"Swiper";
        }
        else if (row==6)
        {
            cout<<"Security Guard";
        }
        cout<<" : \n-------------------------------"<<endl;
        cout<<left<<setw(10)<<"Sr."
        <<left<<setw(30)<<"Name"
        <<left<<setw(20)<<"Yes/No"<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout<<left<<setw(10)<<i+1;
            if (teamsName[row][i]!="NV")
            {
                cout<<left<<setw(30)<<teamsName[row][i];
                if (teamSalaryStatus[row][i]==true)
                {
                    cout<<left<<setw(20)<<"Yes";
                }
                else
                {
                    cout<<left<<setw(20)<<"No";
                }
                
            }
            else
            {
                cout<<left<<setw(30)<<"-";
                if (teamSalaryStatus[row][i]==true)
                {
                    cout<<left<<setw(20)<<"-";
                }
                else
                {
                    cout<<left<<setw(20)<<"-";
                }
            }
            cout<<endl;
            
        }
        

    }
    else
    {
        cout<<"You have entered invalid input...!"<<endl;
        
    }
    
    halt();
    
}

int listOfManagement()                            //List of Management
{
    int row;
    selectCorrectCategory:
    cout<<"> Enter 1 for Manager "<<endl;
    cout<<"> Enter 2 for RSM "<<endl;
    cout<<"> Enter 3 for Distributer Supervisor "<<endl;
    cout<<"> Enter 4 for Accountant "<<endl;
    cout<<"> Enter 5 for Stock Handling Incharge "<<endl;
    cout<<"> Enter 6 for Warehouse Incharge "<<endl;
    cout<<"\nSelect category to enter  : ";
    cin >> row;
    system("CLS");
    if (row>=1 && row<=6)
    {
        return row;
    }
    else
    {
        cout<<"You have selected wrong category..."<<endl;
        halt();
        goto selectCorrectCategory;
    }
    
}

int availablePlaceInManagement(string email[],int size)        // return the index of available plave
{
    int i=0;
    while (i<size)
    {
        if (email[i][0]=='N' && email[i][1]=='V')
        {
            return i;
            break;
        }
        i=i+1;
    }
    return -1;
}

void addManagement(string email[],string password[],string name[6][2],int basicSalary[],string category,int managementSalary[6][2],int row,int index)        //add a person of management
{
    string enterEmail,enterName;
    if (index==-1 || index>1)
    {
        cout<<"\nThere is no more place to add worker in this category...!\n";
        halt();
    }
    else
    {
        reEnter:
        cout<<"\nEnter Worker's Email in formate" ;
        emailFormateManagement(row);
        cout<<" : ";
        cin>>enterEmail;
        cin.ignore(10,'\n');
        cout<<"Enter the Password of worker : ";
        getline(cin,password[index]);
       // cin.ignore(10,'\n');
        cout<<"Enter the Name of worker: ";
        getline(cin,enterName);
       // cin.ignore(10,'\n');
       if (emailValidation(enterEmail) && checkEmailCategory(enterEmail,category))
        {
            email[index]=enterEmail;
            name[row][index]=enterName;
            managementSalary[row][index]=basicSalary[row];
            cout<<"Enter the salary of the person is fixed : ";
            cout<<basicSalary[row];
            cout<<"\n\nPerson has been Entered Successfully..!"<<endl;
        }
        else
        {
            cout<<"You have entered an invalid email...."<<endl;
            char y;
            cout<<"Enter Y to re-enter email OR any key to leave : ";
            cin>>y;
            if(y=='Y' || y=='y')
            {
                goto reEnter;
            }
            
        }
        
        
        
               
    }
}
void emailFormateManagement(int row)        //formate of writing email(Manager)
{
    if (row==0)
    {
        cout<<"(abc@manager.nestle.pk)";
    }
    else if (row==1)
    {
        cout<<"(abc@rsm.nestle.pk) or (abc@asm.nestle.pk)";
    }
    else if (row==2)
    {
        cout<<"(abc@ds.nestle.pk)";
    }
    else if (row==3)
    {
        cout<<"(abc@acc.nestle.pk)";
    }
    else if (row==4)
    {
        cout<<"(abc@shi.nestle.pk)";
    }
    else if (row==5)
    {
        cout<<"(abc@whi.nestle.pk)";
    }
    
}

char viewMenuOfManager()                            // 
{
    char input;
    cout << "                                                   ******************************" << endl;
    cout << "                                                  #-----=========View========-----#            " << endl;
    cout << "                                                   ******************************" << endl;
    cout <<"> Enter 1 to check team(Atendance) ."<<endl;
    cout <<"> Enter 2 View all worker's Information."<<endl;
    cout <<"> Enter 3 Checking Stock information "<<endl;
    cout <<"> Enter 4 to check salery status ."<<endl;
    cout<<"> Enter 5 for Checking requirements of different cpmpanies" << endl;
    cout << "> Enter 6 for Checking manageent of different areas."<<endl;
    cout<<"\nEnter your option  : ";
    cin >> input;
    system("CLS");
    return input;
}
/////////////////////////////////////////// FILE HANDLING//////////////////////////////////////////////
bool saveTeamData(string teamsEmail[7][5],string teamsName[7][5],string teamsPassword[7][5],int teamsSalary[7][5])
{
    bool flag=false;
    ofstream saveData;
    saveData.open("teamData.txt");
    if (saveData.is_open())
    {
        for (int i = 0; i < 7; i++)
        {
            for(int j=0 ; j < 5; j++)
            {
                saveData << teamsEmail[i][j] << ","
                << teamsName[i][j] <<","
                << teamsSalary[i][j] <<","
                <<teamsPassword[i][j] <<endl;
                flag = true ;
            }
        }
        
    }
    
    saveData.close();
    return flag;
}
void loadTeamData(string teamsEmail[7][5],string teamsName[7][5],string teamsPassword[7][5],int teamsSalary[7][5])
{
    
    ifstream loadData;
    loadData.open("teamData.txt");
    if (loadData.is_open())
    {
        for (int i = 0; i < 7; i++)
        {
            for(int j=0 ; j < 5; j++)
            {
                getline(loadData,teamsEmail[i][j],',');
                getline(loadData,teamsName[i][j],',');     
                loadData >> teamsSalary[i][j];
                loadData.ignore(1,',');
                getline(loadData,teamsPassword[i][j],'\n');
                
            }
        }
        
    }
    
    loadData.close();
}
bool saveTeamAttendanve(bool teamsAttendance[12][30][7][5])
{
    bool flag=false;
    ofstream saveData;
    saveData.open("teamAttendance.txt");
    if(saveData.is_open())
    {
        for (int i = 0; i < 12; i++)                         //initialize attandance
        {
            for (int k = 0; k < 30; k++)
            {
                for (int j = 0; j < 7; j++)
                {
                    for (int m = 0; m < 5; m++)
                    {
                        saveData<<teamsAttendance[i][k][j][m]
                        <<",";
                        flag=true;

                    }
                    saveData << endl;

                }

            }

        }
    }
    saveData.close();
    return flag;
}
void loadTeamAttendanve(bool teamsAttendance[12][30][7][5])
{
    ifstream loadData;
    loadData.open("teamAttendance.txt");
    if(loadData.is_open())
    {
        for (int i = 0; i < 12; i++)                         //initialize attandance
        {
            for (int k = 0; k < 30; k++)
            {
                for (int j = 0; j < 7; j++)
                {
                    for (int m = 0; m < 5; m++)
                    {
                        loadData>>teamsAttendance[i][k][j][m];
                        loadData.ignore(1,',');                        
                    }
                    loadData.ignore(1,'\n');
                }

            }

        }
    }
    loadData.close();
}
bool saveProductData(string productName[8],int productPrice[8][100],int productNumber[8][100])
{
    int count[8]={0};
    bool flag=false;
    ofstream saveData;
    saveData.open("productDetails.txt");
    for(int i=0; i<8 ; i++)
    {
        for(int j=0 ;j<100;j++)
        {
            if(productNumber[i][j]==1)
            {
                count[i]++;
            }
        }
    }

    if(saveData.is_open())
    {
        for(int i=0 ; i<8 ; i++)
        {
            saveData<<productName[i]<<","
            <<productPrice[i][0]<<","
            <<count[i]<<endl;
            flag=true;
        }
    }
    saveData.close();
    return flag;
}
void loadProductData(string productName[8],int productPrice[8][100],int productNumber[8][100])
{
    int count[8]={0};
    ifstream loadData;
    loadData.open("productDetails.txt");
    if(loadData.is_open())
    {
        for(int i=0 ;i<8 ;i++)
        {
            getline(loadData,productName[i],',');
            loadData>>productPrice[i][0];
            loadData.ignore(1,',');
            loadData>>count[i];
            for(int j=0 ;j < count[i]; j++)
            {
                productNumber[i][j]=1;
            }
            for(int j=0 ; j<100 ;j++)
            {
                if(productNumber[i][j]!=1)
                {
                    productNumber[i][j]=0;
                }
            }
            loadData.ignore(1,'\n');
        }
    }
    loadData.close();
}
void saveCompanyData(string companies[5],int companyRequirement[5][8][100])
{
    ofstream saveData;
    saveData.open("companyData.txt");
    if(saveData.is_open())
    {
        for(int i=0 ; i<5 ; i++)
        {
            saveData<<companies[i]<<",";
        }
        saveData<<endl;
        for(int i=0; i<5 ;i++)
        {
            for(int j=0 ; j<8 ; j++)
            {
                for(int k=0 ; k<100 ; k++)
                {
                    saveData<<companyRequirement[i][j][k]
                    <<",";
                }
                saveData<<endl;
            }
        }
    }
    saveData.close();
}
void loadCompanyData(string companies[5],int companyRequirement[5][8][100])
{
    ifstream loadData;
    loadData.open("companyData.txt");
    if(loadData.is_open())
    {
        for(int i=0 ; i<5 ;i++)
        {
            getline(loadData,companies[i],',');
        }
        loadData.ignore(1,'\n');
        for(int i=0; i<5 ;i++)
        {
            for(int j=0 ; j<8 ; j++)
            {
                for(int k=0 ; k<100 ; k++)
                {
                    loadData>>companyRequirement[i][j][k];
                    loadData.ignore(1,',');
                }
                loadData.ignore(1,'\n');
            }
        }
    }
    loadData.close();
}
bool saveSalaryStatus(bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5])
{
    bool flag1=false;
    bool flag2=false;
    ofstream save;
    save.open("salaryStatus.txt");
    if(save.is_open())
    {
        for(int i=0 ; i<6 ;i++)
        {
            for(int j=0 ; j<2 ; j++)
            {
                save<<managementSalaryStatus[i][j]
                <<",";
                flag2=true;
            }
            save<<endl;
        }
        for(int i=0 ; i<7 ;i++)
        {
            for(int j=0 ; j<5 ; j++)
            {
                save<<teamSalaryStatus[i][j]
                <<",";
                flag1=true;
            }
            save<<endl;
        }
    }
    save.close();
    if(flag1 && flag2)
    {
        return true;
    }
    else{
        return false;
    }
}
void loadSalaryStatus(bool managementSalaryStatus[6][2],bool teamSalaryStatus[7][5])
{
    ifstream load;
    load.open("salaryStatus.txt");
    if(load.is_open())
    {
        for(int i=0 ; i<6 ;i++)
        {
            for(int j=0 ; j<2 ; j++)
            {
                load>>managementSalaryStatus[i][j];
                load.ignore(1,',');
            }
            load.ignore(1,'\n');
        }
        for(int i=0 ; i<7 ;i++)
        {
            for(int j=0 ; j<5 ; j++)
            {
                load>>teamSalaryStatus[i][j];
                load.ignore(1,',');
            }
            load.ignore(1,'\n');
        }
    }
    load.close();
}
void saveManagementData(string managementNames[6][2],int managementSalary[6][2],int basicSalary[6])
{
    int j=0;
    ofstream save;
    save.open("ManagementData.txt");
    if(save.is_open())
    {
        for(int i=0 ; i<2 ; i++)
        {
            save <<managementNames[j][i]<<","
            << managerEmail[i]<<","
            <<managerPassword[i]<<","
            <<managementSalary[j][i]<<endl;
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            save <<managementNames[j][i]<<","
            << rsmEmail[i]<<","
            <<rsmPassword[i]<<","
            <<managementSalary[j][i]<<endl;
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            save <<managementNames[j][i]<<","
            << dsEmail[i]<<","
            <<dsPassword[i]<<","
            <<managementSalary[j][i]<<endl;
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            save <<managementNames[j][i]<<","
            << accEmail[i]<<","
            <<accPassword[i]<<","
            <<managementSalary[j][i]<<endl;
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            save <<managementNames[j][i]<<","
            << shiEmail[i]<<","
            <<shiPassword[i]<<","
            <<managementSalary[j][i]<<endl;
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            save <<managementNames[j][i]<<","
            << whiEmail[i]<<","
            <<whiPassword[i]<<","
            <<managementSalary[j][i]<<endl;
            
        }
        for(int i=0 ; i<6 ;i++)
        {
            save<<basicSalary[i]<<endl;
        }

    }
    save.close();
}
void loadManagementData(string managementNames[6][2],int managementSalary[6][2],int basicSalary[6])
{
    int j=0;
    ifstream load;
    load.open("ManagementData.txt");
    if(load.is_open())
    {
        for(int i=0 ; i<2 ; i++)
        {
            getline(load,managementNames[j][i],',');
            getline(load,managerEmail[i],',');
            getline(load,managerPassword[i],',');
            load>>managementSalary[j][i];
            load.ignore(1,'\n');
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            getline(load,managementNames[j][i],',');
            getline(load,rsmEmail[i],',');
            getline(load,rsmPassword[i],',');
            load>>managementSalary[j][i];
            load.ignore(1,'\n');
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            getline(load,managementNames[j][i],',');
            getline(load,dsEmail[i],',');
            getline(load,dsPassword[i],',');
            load>>managementSalary[j][i];
            load.ignore(1,'\n');
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            getline(load,managementNames[j][i],',');
            getline(load,accEmail[i],',');
            getline(load,accPassword[i],',');
            load>>managementSalary[j][i];
            load.ignore(1,'\n');
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            getline(load,managementNames[j][i],',');
            getline(load,shiEmail[i],',');
            getline(load,shiPassword[i],',');
            load>>managementSalary[j][i];
            load.ignore(1,'\n');
            
        }
        j++;
        for(int i=0 ; i<2 ; i++)
        {
            getline(load,managementNames[j][i],',');
            getline(load,whiEmail[i],',');
            getline(load,whiPassword[i],',');
            load>>managementSalary[j][i];
            load.ignore(1,'\n');
            
        }
        for(int i=0 ; i<6 ;i++)
        {
            load>>basicSalary[i];
            load.ignore(1,'\n');
        }

    }
    load.close();
}
bool saveManagementAttendance(bool managementAttendance[12][30][6][2])
{
    bool flag=false;
    ofstream saveData;
    saveData.open("managementAttendance.txt");
    if(saveData.is_open())
    {
        for (int i = 0; i < 12; i++)                         //initialize attandance
        {
            for (int k = 0; k < 30; k++)
            {
                for (int j = 0; j < 6; j++)
                {
                    for (int m = 0; m < 2; m++)
                    {
                        saveData<<managementAttendance[i][k][j][m]
                        <<",";
                        flag=true;

                    }
                    saveData << endl;

                }

            }

        }
    }
    saveData.close();
    return flag;
}
void loadManagementAttendance(bool managementAttendance[12][30][6][2])
{
    ifstream loadData;
    loadData.open("managementAttendance.txt");
    if(loadData.is_open())
    {
        for (int i = 0; i < 12; i++)                         //initialize attandance
        {
            for (int k = 0; k < 30; k++)
            {
                for (int j = 0; j < 6; j++)
                {
                    for (int m = 0; m < 2; m++)
                    {
                        loadData>>managementAttendance[i][k][j][m];
                        loadData.ignore(1,',');                        
                    }
                    loadData.ignore(1,'\n');
                }

            }

        }
    }
    loadData.close();
}
void saveCEOdata(string &ceoEmail,string &ceoPassword,string &ceoName,long &totalBalance,long &pendingPayment,long &priceOfSentProducts,long &recievedAmount)
{
    ofstream save;
    save.open("CEOdata.txt");
    if(save.is_open())
    {
        save << ceoName << ","
        << ceoEmail << ","
        << ceoPassword<<endl;
        save << totalBalance << endl;
        save << pendingPayment <<endl;
        save << priceOfSentProducts << endl;
        save << recievedAmount << endl;
    }
    
    save.close();
}
void loadCEOdata(string &ceoEmail,string &ceoPassword,string &ceoName,long &totalBalance,long &pendingPayment,long &priceOfSentProducts,long &recievedAmount)
{
    ifstream load;
    load.open("CEOdata.txt");
    if(load.is_open())
    {
        getline(load,ceoName,',');
        getline(load,ceoEmail,',');
        getline(load,ceoPassword,'\n');
        load >> totalBalance;
        load.ignore(1,'\n');
        load >> pendingPayment;
        load.ignore(1,'\n');
        load >> priceOfSentProducts;
        load.ignore(1,'\n');
        load >> recievedAmount;
        load.ignore(1,'\n');
        
    }
    load.close();
}
//////////////////////////////////////MANAGEMENT FUNCTIONS/////////////////////////////////
void attendanceOfManagement(bool managementAttendance[12][30][6][2],string managementNames[6][2])
{
    again:
    int worker[2];
    int k=0;
    int day,month,year;
    cout<<"Enter the date in the specified formate DAY MONTH YEAR (e.g. 13 7 2020) : ";
    cin>>day>>month>>year;
    if(!((day>=1 && day <=30) && (month>=1 && month<=12) && (year==2020 || year==2021)))
    {
        cout<<"You have entered an invalid date...!"<<endl;
        cout<<"Press Y to re-enter date OR and character to leave : ";
        char y;
        cin>>y;
        if(y=='Y' || y=='y')
        {
            goto again;
        }
        
    }
    else{
        int row =listOfManagement();
        cout<<"Persons according to your selected category are given below : \n\n";
        cout<<left<<setw(20)<<"Index Number"<<left<<setw(20)<<"Name"<<endl;
        for (int i = 0; i < 2; i++)
        {
            if (managementNames[row-1][i]!="NV")
            {
                cout<<left<<setw(20)<<i<<left<<setw(30)<<teamsName[row-1][i]<<endl;
                k++;
            }
            else{
                cout<<left<<setw(20)<<i<<left<<setw(30)<<"-"<<endl;
            }

        }
        // cout<<"How many persons are present today, from above list : ";
        // cin>>k;
        if(k>0)
        {
            cout<<"\nWrite the Respective indexes of Present workers  : "<<endl;
            for (int i = 0; i < k; i++)
            {
                cout<<i+1<<". Enter Index : ";
                cin>>worker[i];
            }
            for (int i = 0; i < k; i++)
            {
                managementAttendance[month-1][day-1][row-1][worker[i]]=true;
            }
        }
        else{
            cout<<"Nobody has been entered in this category...!"<<endl;
        }
    }
}
void viewAttendanceOfManagement(bool managementAttendance[12][30][6][2],string managementNames[6][2])
{
    char input;
    int day,month,year;
    cout<<"Enter 1 to view Today's Present "<<endl;
    cout<<"Enter 2 to View Monthly Presents."<<endl;
    cout<<"Enter 3 to View Yearly Presents."<<endl;
    
    cin>>input;
    if (input=='1')
    {
        again:
        cout<<"\nEnter the date in the specified formate DAY MONTH YEAR (e.g. 13 7 2020) : ";
        cin>>day>>month>>year;
        if(!((day>=1 && day <=30) && (month>=1 && month<=12) && (year==2020 || year==2021)))
        {
            cout<<"You have entered an invalid date...!"<<endl;
            cout<<"Press Y to re-enter date OR and character to leave : ";
            char y;
            cin>>y;
            if(y=='Y' || y=='y')
            {
                goto again;
            }

        }
        else{
            cout<<left<<setw(30)<<"category"
                <<left<<setw(20)<<"1"
                <<left<<setw(20)<<"2"
                <<endl<<endl;
            for(int i = 0; i < 6; i++)
            {
                cout<<left<<setw(30)<<returnManagementName(i);
                for (int j = 0; j < 2; j++)
                {

                    if (managementAttendance[month-1][day-1][i][j]!=false && managementNames[i][j]!="NV")
                    {
                        cout<<left<<setw(30)<<teamsName[i][j];
                    }
                    if (managementAttendance[month-1][day-1][i][j]==false && managementNames[i][j]!="NV")
                    {
                        cout<<left<<setw(30)<<"A"; 
                    }
                    else if(managementNames[i][j]=="NV")
                    {
                        cout<<left<<setw(30)<<"-";
                    }


                }
                cout<<endl;
            }
        }
        halt();

    }
    else if(input=='2')
    {
        int row;
        cout<<"\nSelect category you want to search : "<<endl;
        row = listOfManagement()-1;
        monthAgain:
        cout<<"Enter your desired month(in mumber i.e. 1,2,3..etc.): ";
        cin>>month;
        if(!(month>=1 && month<=12))
        {
            cout<<"You have selected a wrong option...!"<<endl;
            char y;
            cout<<"Enter Y to re-enter month OR any character to leave : ";
            cin>>y;
            if(y=='Y' || y=='y')
            {
                goto monthAgain;
            }
        }
        else{
            cout<<"\n\nAttendance accouding to your selected month is : "<<endl;
            diaplayMonth(month-1);
            cout<<"**************************************************************************"<<endl;
            cout<<right<<setw(20)<<returnManagementName(row)<<endl;

        }
        for (int i = 0; i < 30; i++)
        {
            cout<<i+1<<"\t";
            for (int j = 0; j < 2; j++)
            {
                if (managementAttendance[month][i][row][j]!=false && managementNames[row][j]!="NV")
                {
                    cout<<left<<setw(30)<<managementNames[row][j];
                }
                if (managementAttendance[month][i][row][j]==false && managementNames[row][j]!="NV")
                {
                    cout<<left<<setw(30)<<"A";
                }
                else if(managementNames[row][j]=="NV" )
                {
                    cout<<left<<setw(30)<<"-";
                }
            }
            cout<<endl;
        }
        halt();
    }
    else if(input=='3')
    {
        int row;
        cout<<"\nSelect category you want to search : "<<endl;
        row = listOfManagement()-1;
        for (int month = 0; month < 12; month++)
        {
            diaplayMonth(month);
            cout<<"**************************************************************************"<<endl;
            cout<<right<<setw(20)<<returnManagementName(row)<<endl;
            for (int i = 0; i < 30; i++)
            {
                cout<<i+1<<"\t";
                for (int j = 0; j < 2; j++)
                {
                    if (managementAttendance[month-1][i][row][j]!=false && managementNames[row][j]!="NV")
                    {
                        cout<<left<<setw(30)<<managementNames[row][j];
                    }
                    if (managementAttendance[month-1][i][row][j]==false && managementNames[row][j]!="NV")
                    {
                        cout<<left<<setw(30)<<"A";
                    }
                    else if(managementNames[row][j]=="NV" )
                    {
                        cout<<left<<setw(30)<<"-";
                    }
                }
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"You are selected an incorrect option...!"<<endl;
    }
}

string returnManagementName(int index)
{
    string cat;
    if(index==0)
    {
        cat="Manager";
    }
    else if(index==1)
    {
        cat="RSM";
    }
    else if(index==2)
    {
        cat="Distributer Supervisor";
    }
    else if(index==3)
    {
        cat="Accountant";
    }
    else if(index==4)
    {
        cat="Stock Handling Incharge";
    }
    else if(index==2)
    {
        cat="Warehouse Incharge";
    }
    return cat;
}
void addStock(string productName[8],int productNumber[8][100],int productPrice[8][100])
{
    
    char input;
    do{
    cout<<"Enter 1 to check Available Products"<<endl;
    cout<<"Enter 2 for Add Stock"<<endl;
    cout<<"Enter 0 for Exit"<<endl;
    cout<<"Select your option : ";
    cin>>input;
    
        if(input=='1')
        {
            availableProducts( productNumber);
            halt();
        }
        else if(input=='2')
        {
            int amount=0;
            int row;
            cout<<left<<setw(20)<<"Sr."
            <<left<<setw(50)<<"Product Name"<<endl<<endl;
            for(int i=0; i<8;i++)
            {
                cout<<left<<setw(20)<<i+1
                <<left<<setw(50)<<productName[i]<<endl;
            }
            cout<<"Select your option : ";
            cin>>row;
            cout<<"Enter the amount(MAX CAPACITY 100) :";
            cin>>amount;
            for(int i=0 ; i<100 ;i++)
            {
                if(productNumber[row-1][i]==0 && amount!=0)
                {
                    productNumber[row-1][i]=1;
                    amount=amount-1;
                    totalBalance = totalBalance-productPrice[row-1][i];
                }
            }
            cout<<"Now available products are :- "<<endl<<endl;
            availableProducts( productNumber);
            halt();

        }
        else if(input=='0')
        {
            cout<<"Menu has been closed...!"<<endl;
            halt();
        }
        else
        {
            cout<<"You have selected an invalid option..!"<<endl;
            halt();
        }
    }while(input!='0');
}
void saveToken(int &managerToken,int &rsmToken,int &dsToken,int &accToken,int &shiToken,int &whiToken)
{
    ofstream save;
    save.open("token.txt");
    if(save.is_open())
    {
        save<<managerToken<<endl;
        save<<rsmToken<<endl;
        save<<dsToken<<endl;
        save<<accToken<<endl;
        save<<shiToken<<endl;
        save<<whiToken<<endl;
    }
    save.close();
}
void loadToken(int &managerToken,int &rsmToken,int &dsToken,int &accToken,int &shiToken,int &whiToken)
{
    ifstream load;
    load.open("token.txt");
    if(load.is_open())
    {
        load>>managerToken;
        load.ignore(1,'\n');
        load>>rsmToken;
        load.ignore(1,'\n');
        load>>dsToken;
        load.ignore(1,'\n');
        load>>accToken;
        load.ignore(1,'\n');
        load>>shiToken;
        load.ignore(1,'\n');
        load>>whiToken;
        load.ignore(1,'\n');
    }
    load.close();
}