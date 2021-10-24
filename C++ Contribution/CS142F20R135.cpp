#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <conio.h>
using namespace std;

///////////////////////////////////////////////////////////////Customize Car//////////////////////////////////////////////////////////////////
/////////////////////////user//////////////////////
void whole_CustomizeCaseFunCout(string option, string Cars_Customizer[100][3], string CarsCustomizers[5], int Cars_CustomizerAmount[100], int input, int Input_Copy, string CustPar_Name);
void Car_CustomizerMenu();
void View_CustomizerPartsOne(string Cars_Customizer[100][3], string CarsCustomizers[5], int Cars_CustomizerAmount[100], int input, int Input_Copy);
bool Buy_CustPart(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100], string CustPar_Name);
void Customizer_IFcaseFunctCout(string Cars_Customizer[100][3], string CarsCustomizers[5], int Cars_CustomizerAmount[100], int input, int Input_Copy, string CustPar_Name);
/////////////////////////aadmin/////////
void Cust_ifcaseFunCout(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100], string CarsCustomizers[5], int input, string CustPar_Name, string price, int amount, int Input_Copy);
void View_CustomizerPartsAll(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100]);
void Cust_AdminMenu();
void Admin_MENUinMenu();
bool Add_CustPart(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100], string CarsCustomizers[5], int input, string CustPar_Name, string price, int amount, int Input_Copy);

//////////////////////////////////////////////////////////////serviceProcessing////////////////////////////////////////////////////////////////
void View_EngineOil(string Engine_Oil[100][2], int Engine_oil_Amount[100]);
//////////////////////User////////////////////////////////////////
void UserService_Menu();
bool UserService_Done(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name);
void UserService_CarintoServiceDone(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name);
void User_ServiceFunctcout(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name, int amount, int input, string option);
//////////////////////Admin////////////////////////////////////////////////////
bool Add_EnginseOil(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name, int amount, string price);
void Admin_ManageServMenu();
void Admin_ServiceFunCout(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name, int amount, string price, int input, string option);

///////////////////////////////////////////////////////////////////Rent Car////////////////////////////////////////////////////////////////////
bool Rent_Car(string CarName, int Days, int RentCar_Price[100], string RentCar[100][4], int Rent[1]);
bool Add_RentCar(string Brand_Car, string Model, string ModelYear, string Colour, int amount, int RentCar_Price[100], string RentCar[100][4]);

//////////////////////////////////////////////////////////////users fuction////////////////////////////////////////////////////////////////////
bool Add_User(string User_Name, string Users[100][6]);
bool Buy_Car(string CarName, string CarDetails[100][6], string Users[100][6], string Cars_Brand[5], string User_Name, int input, int Input_Copy, string Model);

//////////////////////////////////////////////////////////////////Cars Fuctions//////////////////////////////////////////////////////////////////
bool Car_Search(string CarName, string CarDetails[100][6], string Cars_Brand[5], int input, int Input_Copy, string Brand_Car);
bool Add_Car(string CarName, string Model, string ModelYear, string Colour, string price, int input, string Cars_Brand[5], string CarDetails[100][6]);

/////////////////////////////////////////////////////////////Parts/////////////////////////////////////////////////////////////////////////////
bool Buy_Part(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], string Brand_Car, int amount);
bool Add_Parts(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy, string price, string Brand_Car, int amount);

////////////////////////////////////////////////////////////////Void Functions///////////////////////////////////////////////////////////////////
void Car_SectionMenu();
void Parts_Section();
void RentCars_Section();
void Add_RentCarFunctionCout(string Brand_Car, string Model, string ModelYear, string Colour, int amount, int RentCar_Price[100], string RentCar[100][4]);
void Rent_CarFunctionCout(string CarName, int Days, int RentCar_Price[100], string RentCar[100][4], int Rent[1]);
void View_RentCars(string RentCar[100][4], int RentCar_Price[100]);
void Buy_PartsFunctionCout(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy, string price, string Brand_Car, int amount);
void Add_PartsFunctionCout(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy, string price, string Brand_Car, int amount);
void Parts_WithOnePartName(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy);
void ViewCars_Parts(string PartsDetail[100][3], int Parts_Amount[100]);
void Parts_Menu();
void User_Dashboard(string Users[100][6]);
void Search_CarFunctionCout(string option, string CarName, string CarDetails[100][6], string Cars_Brand[5], int input, int Input_Copy, string Brand_Car);
void Cars_WithOneBrand(string Cars_Brand[5], string CarDetails[100][6], int input, int Input_Copy);
void Cars_Display(string CarDetails[100][6]);
void Admin_Menu();
void User_Menu();
void Top_Cars(string CarDetails[100][6]);
void Menu_CarsBrand();
void Buy_CarFunctionCout(string CarDetails[100][6], string Cars_Brand[5], string CarName, int input, int Input_Copy, string User_Name, string Users[100][6], string Model);
void Add_CarsFunctionCout(string CarDetails[100][6], string Cars_Brand[5], string CarName, string Model, string ModelYear, string Colour, string price, int input, int Input_Copy);

////////////////////////////////////////////////////////Validators///////////////////////////////////////////////////////////////////////////////
bool Valid_Days(int Days);
bool Valid_CarName(string CarName);
bool Valid_CarModel(string Model);
bool Valid_ModelYear(string ModelYear);
bool Valid_CarColor(string Colour);
bool Valid_CarPrice(string price);
bool Valid_PartAmount(int amount);
bool Valid_Brand_Car(string Brand_Car);
bool Valid_UersName(string User_Name);
bool Valid_Engine_Name(string Engine_Name);
bool Valid_CustPar_Name(string CustPar_Name);

//////////////////////////////////////////////////////////////////////File Handling////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////save///////////////////////////////////////////////////////////////////////
bool Save_Cars(string CarDetails[100][6]);
bool Save_Parts(string PartsDetail[100][3], int Parts_Amount[100]);
bool Save_RentCars(int RentCar_Price[100], string RentCar[100][4]);
bool Save_Users(string Users[100][6]);
bool Save_ServiceData(string Engine_Oil[100][2], int Engine_oil_Amount[100]);
bool Save_CustomizeCar(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100]);

//////////////////////////////////////////////////////////////////////load///////////////////////////////////////////////////////////////////////
bool Load_Cars(string CarDetails[100][6]);
bool Load_Parts(string PartsDetail[100][3], int Parts_Amount[100]);
bool Load_RentCars(int RentCar_Price[100], string RentCar[100][4]);
bool Load_Users(string Users[100][6]);
bool Load_ServiceData(string Engine_Oil[100][2], int Engine_oil_Amount[100]);
bool Load_CustomizeCar(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100]);

//////////////////////////////////////////////////////////////////Halts Fuction///////////////////////////////////////////////////////////////////
void Halt();
int main()
{

    /////////////////////////////////////////////////////////////flag////////////////////////////////////////////////////////////////////////
    bool flag;

    /////////////////////////////////////////////////////Variable Declaration That i'll use////////////////////////////////////////////////////

    int Days;
    int Rent[1] = {0};
    int Choose_option = -1;
    int count = 0;
    int input;
    string option;
    int Input_Copy;
    int select;
    string CustPar_Name;

    ///////////////////////////////////////////////////////////Servicing Variables////////////////////////////////////////////////////////////
    string Engine_Name;

    //////////////////////////////////////////////////////////user variable////////////////////////////////////////////////////////////////
    string User_Name;

    ///////////////////////////////////////////////////////////////////Cars Variable//////////////////////////////////////////////////////////
    string CarName;
    string Model;
    string ModelYear;
    string Colour;
    string price;
    string Brand_Car;

    ////////////////////////////////////////////////////////////////////parts variavles////////////////////////////////////////////////////
    string name_parts;
    int amount;

    //////////////////////////////////////////////////////////Login Variables////////////////////////////////////////////////////////////////
    string user_name = {"1"};
    string password = {"1"};
    string user;
    string pass;

    ////////////////////////////////////////////////////////////////Enums section////////////////////////////////////////////////////////////
    enum Cars
    {
        Tesla_Inc,
        Toyota_Motor_Corporation,
        Volkswagen,
        Ford_Motor_Company,
        Honda,

    };
    enum Car_Parts
    {
        Engines,
        Batteries,
        Tyres,
        Radiators,
        Axles,
    };

    //////////////////////////////////////////////////////////arrays (1D and 2D)//////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////cars Arrays////////////////////////////////////////////////////////////
    string CarDetails[100][6];
    string Cars_Brand[5] = {"Tesla_Inc", "Toyota_Motor_Corporation", "Volkswagen", "Ford_Motor_Company", "Honda"};

    //////////////////////////////////////////////////////parts Arrays/////////////////////////////////////////////////////////////
    string PartsDetail[100][3];
    int Parts_Amount[100] = {25, 13, 15, 25, 16, 30, 12, 13, 14, 25, 26, 2, 1, 23, 34, 23, 12, 34, 56, 1, 32, 34, 56, 3, 2};
    string Parts_Name[5] = {"Engines", "Batteries", "Tyres", "Radiators", "Axles"};

    //////////////////////////////////////////////////////rent cars//////////////////////////////////////////////////////////////

    string RentCar[100][4];

    int RentCar_Price[100] = {10000, 9000, 12000, 11000, 22000, 9000, 21000};
    /////////////////////////////////////////////////////////////user Array/////////////////////////////////////////////////////////
    string Users[100][6];

    ///////////////////////////////////////////////////////////////carcustomizer inventory/////////////////////////////////////////////////////////
    string Cars_Customizer[100][3];
    int Cars_CustomizerAmount[100];
    string CarsCustomizers[5] = {"Paints", "wheels", "Suspension kits", "Engines", "Brake kits"};

    /////////////////////////////////////////////////////////////////////Service Engine Oil////////////////////////////////////////////////////
    string Engine_Oil[100][2];
    int Engine_oil_Amount[100];

//////////////////////////////////////////////////////////////////////////start/////////////////////////////////////////////////////////////////////////
start:
    if (Load_CustomizeCar(Cars_Customizer, Cars_CustomizerAmount) && Load_ServiceData(Engine_Oil, Engine_oil_Amount) && Load_Cars(CarDetails) && Load_RentCars(RentCar_Price, RentCar) && Load_Parts(PartsDetail, Parts_Amount) && Load_Users(Users))
    {
        cout << "                    Previouse Data Loaded Successfully!!!..." << endl;
    }

    cout
        << endl;
    cout << "                                 Choose The Type OF Access: " << endl;
    cout << "                                      1.Admin" << endl;
    cout << "                                      2.Customer" << endl;
    cout << "                                Enter The Type(1/2): ";
    cin >> Choose_option;
    system("CLS");

    /////////////////////////////////////////////////////////admin portion/////////////////////////////////////////////////////////////////////

    if (Choose_option == 1)
    {
    userdetail:
        cin.ignore();
        cout << "                            Enter Username: ";
        getline(cin, user);

        cout << "                            Enter Password: ";
        getline(cin, pass);
        system("CLS");
        if (user == user_name && pass == password)
        {
            cout << "****************++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++****************" << endl;
            cout << "                                     WelCome To Branded Automotive Showroom" << endl;
            cout << "****************++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++****************\n\n";
            while (Choose_option != 0)
            {
                cout << "                       ++++******************************************************++++" << endl;
                if (count == 0)
                {
                    cout << "                                        Pleausre To have You !!!" << endl;
                    count = count + 1;
                }
                Admin_Menu();
                cout << "                             Please Enter Your Action ....: ";
                cin >> Choose_option;
                system("CLS");

                /////////////////////////////////////////////////////////switch///////////////////////////////////////////////////////////////////////////////////

                switch (Choose_option)
                {
                    //////////////////////////////////////////////////////////////case 1////////////////////////////////////////////////////////////////////////////

                case 1:
                carsection:
                    while (select != 4)
                    {
                        Car_SectionMenu();
                        cout << "                                 Select From Above: ";
                        cin >> select;
                        system("CLS");
                        if (select == 1)
                        {
                            Cars_Display(CarDetails);
                        }
                        else if (select == 2)
                        {
                            cout << "===================================================================================================================================================" << endl;
                            cout << "                                                Add a Car\n";
                            cout << "                             %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
                                 << "\n\n";
                        repeat1:

                            Menu_CarsBrand();
                            cout << "                                              Enter Your Choice: ";
                            cin >> input;
                            system("CLS");
                            if (input == 1)
                            {
                                Add_CarsFunctionCout(CarDetails, Cars_Brand, CarName, Model, ModelYear, Colour, price, input, Input_Copy);
                            }
                            else if (input == 2)
                            {
                                Add_CarsFunctionCout(CarDetails, Cars_Brand, CarName, Model, ModelYear, Colour, price, input, Input_Copy);
                            }
                            else if (input == 3)
                            {
                                Add_CarsFunctionCout(CarDetails, Cars_Brand, CarName, Model, ModelYear, Colour, price, input, Input_Copy);
                            }
                            else if (input == 4)
                            {
                                Add_CarsFunctionCout(CarDetails, Cars_Brand, CarName, Model, ModelYear, Colour, price, input, Input_Copy);
                            }
                            else if (input == 5)
                            {
                                Add_CarsFunctionCout(CarDetails, Cars_Brand, CarName, Model, ModelYear, Colour, price, input, Input_Copy);
                            }

                            else if (!(input > 0 && input < 6))
                            {
                                cout << "                            You Have Enter invalid Option....." << endl;
                                cout << "                              Do you wanna try again(Y/N) :";
                                cin >> option;
                                system("CLS");
                                if (option == "Y" || option == "y")
                                {
                                    goto repeat1;
                                }
                                else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                                {
                                    cout << "                                You Have Enter Wrong ..." << endl;
                                }
                            }
                        }
                        else if (select == 3)
                        {
                            Search_CarFunctionCout(option, CarName, CarDetails, Cars_Brand, input, Input_Copy, Brand_Car);
                        }
                        else if (input == 4)
                        {
                        }
                        else if (!(select > 0 && select < 5))
                        {
                            cout << "                            You Have Enter invalid Option....." << endl;
                            cout << "                              Do you wanna try again(Y/N) :";
                            cin >> option;
                            system("CLS");
                            if (option == "Y" || option == "y")
                            {
                                goto carsection;
                            }
                            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                            {
                                cout << "                                You Have Enter Wrong ..." << endl;
                            }
                        }
                        Halt();
                    }

                    break;

                    /////////////////////////////////////////////////////////////// //case 2///////////////////////////////////////////////////////////////////////

                case 2:
                    while (select != 3)
                    {
                        Parts_Section();
                        cout << "                                 Select From Above: ";
                        cin >> select;
                        system("CLS");
                        if (select == 1)
                        {
                            ViewCars_Parts(PartsDetail, Parts_Amount);
                        }
                        if (select == 2)
                        {
                            cout << "                                            Add Parts/Accessories\n";
                        repeat2:
                            Parts_Menu();
                            cout << "                                              Enter Your Choice: ";
                            cin >> input;
                            system("CLS");

                            if (input == 1)
                            {
                                Add_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                            }
                            else if (input == 2)
                            {
                                Add_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                            }
                            else if (input == 3)
                            {
                                Add_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                            }
                            else if (input == 4)
                            {
                                Add_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                            }
                            else if (input == 5)
                            {
                                Add_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                            }

                            ///////////////////////// //wrong input///////////////////////////////

                            else if (!(input > 0 && input < 6))
                            {
                                cout << "                            You Have Enter invalid Option....." << endl;
                                cout << "                              Do you wanna try again(Y/N) :";
                                cin >> option;
                                system("CLS");
                                if (option == "Y" || option == "y")
                                {
                                    goto repeat1;
                                }
                                else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                                {
                                    cout << "                                You Have Enter Wrong ..." << endl;
                                }
                            }
                        }
                        else if (!(select > 0 && select < 4))
                        {
                            cout << "                            You Have Enter invalid Option....." << endl;
                            cout << "                              Do you wanna try again(Y/N) :";
                            cin >> option;
                            system("CLS");
                            if (option == "Y" || option == "y")
                            {
                                goto carsection;
                            }
                            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                            {
                                cout << "                                You Have Enter Wrong ..." << endl;
                            }
                        }
                    }
                    Halt();

                    break;

                    ///////////////////////////////////////////////////////////////case 3////////////////////////////////////////////////////////////////////////

                case 3:
                    User_Dashboard(Users);
                    break;

                    ////////////////////////////////////////////////////////////////case 7/////////////////////////////////////////////////////////////////////

                case 4:
                    while (select != 3)
                    {
                        RentCars_Section();
                        cout << "                                 Select From Above: ";
                        cin >> select;
                        system("CLS");
                        if (select == 1)
                        {
                            Add_RentCarFunctionCout(Brand_Car, Model, ModelYear, Colour, amount, RentCar_Price, RentCar);
                        }
                        else if (select == 2)
                        {
                            View_RentCars(RentCar, RentCar_Price);
                        }
                        else if (!(select > 0 && select < 4))
                        {
                            cout << "                            You Have Enter invalid Option....." << endl;
                            cout << "                              Do you wanna try again(Y/N) :";
                            cin >> option;
                            system("CLS");
                            if (option == "Y" || option == "y")
                            {
                                goto carsection;
                            }
                            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                            {
                                cout << "                                You Have Enter Wrong ..." << endl;
                            }
                        }
                        Halt();
                    }

                    break;

                    ///////////////////////////////////////////////////////////////////////////case 5/////////////////////////////////////////////////////////////////////////////////
                case 5:
                    Admin_ServiceFunCout(Engine_Oil, Engine_oil_Amount, Engine_Name, amount, price, input, option);
                    break;

                //////////////////////////////////////////////////////////////////////////////////////////Case 6///////////////////////////////////
                case 6:
                    while (input != 0)
                    {
                        Cust_AdminMenu();
                        cout << "                                 Select The Option: ";
                        cin >> input;
                        system("CLS");

                        if (input == 1)
                        {
                            Admin_MENUinMenu();
                            cout << "                                 Select The Option: ";
                            cin >> input;
                            system("CLS");
                            if (input == 1)
                            {
                                Cust_ifcaseFunCout(Cars_Customizer, Cars_CustomizerAmount, CarsCustomizers, input, CustPar_Name, price, amount, Input_Copy);
                            }
                            else if (input == 2)
                            {
                                Cust_ifcaseFunCout(Cars_Customizer, Cars_CustomizerAmount, CarsCustomizers, input, CustPar_Name, price, amount, Input_Copy);
                            }
                            else if (input == 3)
                            {
                                Cust_ifcaseFunCout(Cars_Customizer, Cars_CustomizerAmount, CarsCustomizers, input, CustPar_Name, price, amount, Input_Copy);
                            }
                            else if (input == 4)
                            {
                                Cust_ifcaseFunCout(Cars_Customizer, Cars_CustomizerAmount, CarsCustomizers, input, CustPar_Name, price, amount, Input_Copy);
                            }
                            else if (input == 5)
                            {
                                Cust_ifcaseFunCout(Cars_Customizer, Cars_CustomizerAmount, CarsCustomizers, input, CustPar_Name, price, amount, Input_Copy);
                            }
                        }
                        else if (input == 2)
                        {
                            View_CustomizerPartsAll(Cars_Customizer, Cars_CustomizerAmount);
                        }
                        else if (!(input >= 0 && input < 6))
                        {
                            cout << "                            You Have Enter invalid Option....." << endl;
                        }
                        Halt();
                    }
                    break;
                    //////////////////////////////////////////////////////////////////////////case 7/////////////////////////////////////////////////////////////

                case 7:
                    cout
                        << "                                           Logout Successfully!!!!!\n ";
                    cout << "                                          Press any key to login again: ";
                    getch();
                    system("CLS");
                    goto start;
                    break;

                    ///////////////////////////////////////////////////////////////////////////case 0//////////////////////////////////////////////////////////////////

                case 0:
                    if (Save_CustomizeCar(Cars_Customizer, Cars_CustomizerAmount) && Save_ServiceData(Engine_Oil, Engine_oil_Amount) && Save_RentCars(RentCar_Price, RentCar) && Save_Parts(PartsDetail, Parts_Amount) && Save_Cars(CarDetails))
                    {
                        cout << "                                              All Data Has Saved" << endl;
                    }
                    cout << "                                              Program Closed Successfully\n";
                    return 0;
                    break;

                    //////////////////////////////////////////////////////////////////////////defaualt//////////////////////////////////////////////////////////////////

                default:
                    cout << "                                   You Have Selected Wrong Option\n";
                    cout << "                                   Press any Key For Main Menu: ";
                    getch();
                    system("CLS");
                    break;
                }
            }
        }
        else
        {
            cout << "                              Wrong user name or password.. " << endl;
            cout << "                               Do you want try again(Y/N)...: ";
            cin >> option;
            if (option == "Y" || option == "y")
            {
                goto userdetail;
            }
            else if (option == "n" || option == "N")
            {
                cout << "Press any Key for login options.....: ";
                getch();
                system("CLS");
                goto start;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////customer//////////////////////////////////////////////////////////////////

    else if (Choose_option == 2)
    {
        cout << "****************++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++****************" << endl;
        cout << "                                     WelCome To Branded Automotive Showroom" << endl;
        cout << "****************++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++****************\n\n";
    userAgain:
        cin.ignore();
        cout << "Plaese Enter your Name: ";
        getline(cin, User_Name);
        system("CLS");
        if (Valid_UersName(User_Name) == true)
        {
            if (Add_User(User_Name, Users))
            {

                while (Choose_option != 0)
                {
                    cout << "                       ++++******************************************************++++" << endl;
                    if (count == 0)
                    {
                        cout << "                                        Pleausre To have You !!!" << endl;
                        count = count + 1;
                    }
                    User_Menu();

                    cout << "                             Please Enter Your Action ....: ";
                    cin >> Choose_option;
                    system("CLS");

                    /////////////////////////////////////////////////////switch for submenu///////////////////////////////////////////////////////////////////

                    switch (Choose_option)
                    {

                        //////////////////////////////////////////////////////////Case To show all cars////////////////////////////////////////////////////////

                    case 1:
                        Cars_Display(CarDetails);
                        break;

                        ////////////////////////////////////////////////////////case for buy car/////////////////////////////////////////////////////////////////

                    case 2:
                    repeat3:
                        Menu_CarsBrand();
                        cout << "                                              Enter Your Choice: ";
                        cin >> input;
                        system("CLS");

                        ///////////////////////////////////////////////////////////code for submenu///////////////////////////////////////////////////////////////

                        //1...

                        if (input == 1)
                        {
                            Buy_CarFunctionCout(CarDetails, Cars_Brand, CarName, input, Input_Copy, User_Name, Users, Model);
                        }

                        //2..

                        else if (input == 2)
                        {
                            Buy_CarFunctionCout(CarDetails, Cars_Brand, CarName, input, Input_Copy, User_Name, Users, Model);
                        }

                        //3...

                        else if (input == 3)
                        {
                            Buy_CarFunctionCout(CarDetails, Cars_Brand, CarName, input, Input_Copy, User_Name, Users, Model);
                        }

                        //4...

                        else if (input == 4)
                        {
                            Buy_CarFunctionCout(CarDetails, Cars_Brand, CarName, input, Input_Copy, User_Name, Users, Model);
                        }

                        //5....

                        else if (input == 5)
                        {
                            Buy_CarFunctionCout(CarDetails, Cars_Brand, CarName, input, Input_Copy, User_Name, Users, Model);
                        }
                        else if (!(input > 0 && input < 6))
                        {
                            cout << "                            You Have Enter invalid Option....." << endl;
                            cout << "                              Do you wanna try again(Y/N) :";
                            cin >> option;
                            system("CLS");
                            if (option == "Y" || option == "y")
                            {
                                goto repeat1;
                            }
                            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                            {
                                cout << "                                You Have Enter Wrong ..." << endl;
                            }
                        }
                        Halt();
                        break;

                        /////////////////////////////////////////////////////////////case for search a car//////////////////////////////////////////////////////////////

                    case 3:
                        Search_CarFunctionCout(option, CarName, CarDetails, Cars_Brand, input, Input_Copy, Brand_Car);
                        break;

                        ////////////////////////////////////////////////////////////////View parts//////////////////////////////////////////////////////////////////////

                    case 4:

                        ViewCars_Parts(PartsDetail, Parts_Amount);
                        break;

                        ////////////////////////////////////////////////////////////////case Accessories///////////////////////////////////////////////////////////////////

                    case 5:
                    repeat4:

                        Parts_Menu();
                        cout << "                                              Enter Your Choice: ";
                        cin >> input;
                        system("CLS");

                        //1.....

                        if (input == 1)
                        {
                            Buy_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                        }

                        //2..

                        else if (input == 2)
                        {
                            Buy_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                        }

                        //3....

                        else if (input == 3)
                        {
                            Buy_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                        }

                        //4.......

                        else if (input == 4)
                        {
                            Buy_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                        }

                        //5....

                        else if (input == 5)
                        {
                            Buy_PartsFunctionCout(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount);
                        }

                        //wrong input

                        else if (!(input > 0 && input < 6))
                        {
                            cout << "                            You Have Enter invalid Option....." << endl;
                            cout << "                              Do you wanna try again(Y/N) :";
                            cin >> option;
                            system("CLS");
                            if (option == "Y" || option == "y")
                            {
                                goto repeat1;
                            }
                            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
                            {
                                cout << "                                You Have Enter Wrong ..." << endl;
                            }
                        }
                        Halt();
                        break;

                        ///////////////////////////////////////////////////////////////////case for///////////////////////////////////////////////////////////////////

                    case 6:
                        User_Dashboard(Users);
                        break;

                        /////////////////////////////////////////////////////////////////////View Rent Cars///////////////////////////////////////////////////////////

                    case 7:
                        View_RentCars(RentCar, RentCar_Price);
                        Halt();
                        break;

                        /////////////////////////////////////////////////////////////////////case rent a car///////////////////////////////////////////////////////////

                    case 8:
                        Rent_CarFunctionCout(CarName, Days, RentCar_Price, RentCar, Rent);
                        break;

                        ////////////////////////////////////////////////////////////////////case for servicing/////////////////////////////////////////////////////////////

                    case 9:
                        User_ServiceFunctcout(Engine_Oil, Engine_oil_Amount, Engine_Name, amount, input, option);
                        break;

                        //////////////////////////////////////////////////////////////////////////CarCustomizer///////////////////////////////////////////////
                    case 10:
                        whole_CustomizeCaseFunCout(option, Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy, CustPar_Name);
                        break;

                        /////////////////////////////////////////////////////////////////////////// logout//////////////////////////////////////////////////////////////

                    case 11:
                        cout << "                             Logout Successfully....." << endl;
                        cout << "                          Press any key To login again..";
                        getch();
                        system("CLS");
                        goto start;
                        break;

                        ////////////////////////////////////////////////////////////////////////Case To Exit//////////////////////////////////////////////////////////

                    case 0:
                        cout << "Programmed Exited Successfully!!!.." << endl;
                        if (Save_CustomizeCar(Cars_Customizer, Cars_CustomizerAmount) && Save_ServiceData(Engine_Oil, Engine_oil_Amount) && Save_RentCars(RentCar_Price, RentCar) && Save_Parts(PartsDetail, Parts_Amount) && Save_Cars(CarDetails) && Save_Users(Users))
                        {
                            cout << "                                              All Data Has Saved" << endl;
                        }
                        return 0;
                        break;

                        ///////////////////////////////////////////////////////////////////////////////Deafault Case///////////////////////////////////////////////////

                    default:
                        cout << "                       You have Entered Wrong Action..." << endl;
                        cout << "                        Press any key for main menu: ";
                        getch();
                        system("CLS");
                        break;
                    }
                }
            }
            else
            {
                cout << "                                 No More Space For User...." << endl;
                Halt();
            }
        }
        else
        {
            cout << "                                 Please Enter Your Name Correctly. Try Again....." << endl;
            Halt();
            goto userAgain;
        }
    }

    if (Choose_option != 1 && Choose_option != 2)
    {
        cout << "                                       Invalid Key Please Try again\n";
        cout << "                                       Press any key to try again......";
        getch();
        system("CLS");
        goto start;
    }

    return 0;
}

/////////////////////////////////////////////////////////////////Fuctions Definition//////////////////////////////////////////////////////////////
bool Search_CarBrand(string Brand_Name, string Cars_Brand[], int size)
{
    bool flag;
    for (int i = 0; i < size; i++)
    {
        if (Brand_Name == Cars_Brand[i])
        {
            flag = true;
        }
    }
    return flag;
}
bool Add_Car(string CarName, string Model, string ModelYear, string Colour, string price, int input, string Cars_Brand[5], string CarDetails[100][6])
{
    bool flag;
    for (int i = 0; i < 100; i++)
    {
        if (CarDetails[i][0] == "")
        {
            input = input - 1;
            CarDetails[i][0] = Cars_Brand[input];
            CarDetails[i][1] = CarName;
            CarDetails[i][2] = Model;
            CarDetails[i][3] = ModelYear;
            CarDetails[i][4] = price;
            CarDetails[i][5] = Colour;
            flag = true;
            break;
        }
    }
    return flag;
}
void Halt()
{
    cout << "                                 Press any Key For continue: ";
    getch();
    system("CLS");
}
bool Valid_CarName(string CarName)
{

    bool flag;
    int size = CarName.length();
    if (size <= 28)
    {
        for (int i = 0; i < size; i++)
        {
            if ((CarName[i] >= 'A' && CarName[i] <= 'Z') || (CarName[i] >= 'a' && CarName[i] <= 'z') || CarName[i] == ' ' || CarName[i] == '_' || CarName[i] == '-')
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
bool Valid_CarModel(string Model)
{
    bool flag;
    int size = Model.length();
    if (size <= 28)
    {
        for (int i = 0; i < size; i++)
        {
            if ((Model[i] >= 'A' && Model[i] <= 'Z') || (Model[i] >= 'a' && Model[i] <= 'z') || Model[i] == ' ' || Model[i] == '_' || (Model[i] >= '0' && Model[i] <= '9'))
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
bool Valid_ModelYear(string ModelYear)
{
    bool flag;
    int size = ModelYear.length();
    if (size == 4)
    {
        for (int i = 0; i < size; i++)
        {
            if (ModelYear[i] >= '0' && ModelYear[i] <= '9')
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
bool Valid_CarColor(string Colour)
{
    bool flag;
    int size = Colour.length();
    if (size <= 28)
    {
        for (int i = 0; i < size; i++)
        {
            if ((Colour[i] >= 'A' && Colour[i] <= 'Z') || (Colour[i] >= 'a' && Colour[i] <= 'z') || Colour[i] == ' ' || Colour[i] == '_' || Colour[i] == '[' || Colour[i] == ']')
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
bool Valid_CarPrice(string price)
{
    bool flag;
    int size = price.length();
    if (size <= 28)
    {
        for (int i = 0; i < size; i++)
        {
            if (price[i] >= '0' && price[i] <= '9')
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
void Add_CarsFunctionCout(string CarDetails[100][6], string Cars_Brand[5], string CarName, string Model, string ModelYear, string Colour, string price, int input, int Input_Copy)
{
    bool flag;
    Cars_WithOneBrand(Cars_Brand, CarDetails, input, Input_Copy);
    cout << "\n\n";
    cin.ignore();
    cout << "Enter The Name Of the Car: ";
    getline(cin, CarName);
    cout << "Enter Model Of The Car: ";
    getline(cin, Model);
    cout << "Enter The Colour of the Car: ";
    getline(cin, Colour);
    cout << "Enter The Model Year Of the Car: ";
    cin >> ModelYear;
    cout << "Enter The Price of car in Dollar: ";
    cin >> price;
    if (Valid_CarName(CarName) && Valid_CarModel(Model) && Valid_ModelYear(ModelYear) && Valid_CarColor(Colour) && Valid_CarPrice(price))
    {
        flag = Add_Car(CarName, Model, ModelYear, Colour, price, input, Cars_Brand, CarDetails);
        if (flag == true)
        {
            cout << "Car Is Added..." << endl;
        }
        else
        {
            cout << "Car Is not Because Space is Full" << endl;
        }
    }
    else
    {
        cout << "Invalid Input " << endl;
    }
}
void Menu_CarsBrand()
{
    cout << "           ********************************************************************************************" << endl;
    cout << "                   Pats/Accessories of following Manaufacturer Company(Brands) cars are Available..." << endl;
    cout << "                                                1.Tesla_Inc" << endl;
    cout << "                                                2.Toyota_Motor_Corporation" << endl;
    cout << "                                                3.Volkswagen" << endl;
    cout << "                                                4.Ford_Motor_Company" << endl;
    cout << "                                                5.Honda\n"
         << endl;
    cout << "           ********************************************************************************************\n\n"
         << endl;
}
bool Car_Search(string CarName, string CarDetails[100][6], string Cars_Brand[5], int input, int Input_Copy, string Brand_Car)
{
    bool flag = false;
    Input_Copy = input - 1;
    system("CLS");
    for (int i = 0; i < 100; i++)
    {
        if (CarDetails[i][0] == Cars_Brand[Input_Copy] || CarDetails[i][0] == Brand_Car)
        {
            if (CarDetails[i][1] == CarName)
            {
                cout << "                                                                       Seach Result" << endl;
                cout << endl;
                cout << "********************************************************************************************************************************************************************" << endl;
                cout << setw(28) << left << "ManuFacturer/Brand" << setw(28) << left << "Car Name " << setw(28) << left << "Car_Model" << setw(28) << left << "Model_Year" << setw(28) << left << "Price(In Dollars $)" << setw(28) << left << "Available colors" << endl;
                cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
                for (int j = 0; j < 6; j++)
                {
                    if (j == 6 - 1)
                    {
                        cout << setw(28) << left << CarDetails[i][j] << endl;
                        flag = true;
                    }
                    else
                    {
                        cout << setw(28) << left << CarDetails[i][j];
                        flag = true;
                    }
                }
                cout << "********************************************************************************************************************************************************************" << endl;
                break;
            }
        }
    }
    return flag;
}
void Top_Cars(string CarDetails[100][6])
{
}
void User_Menu()
{
    cout << "                        Branded Automotive Showroom Provided You Following Facilities \n"
         << endl;
    cout << "                             Press  1.To View The Cars With Details(Name,Brand,Price etc..)" << endl;
    cout << "                             Press  2.To Buy A Car" << endl;
    cout << "                             Press  3.To Search Your Favourite Car " << endl;
    cout << "                             Press  4.To View All Availables Parts" << endl;
    cout << "                             Press  5.To Buy Parts(Accessories)" << endl;
    cout << "                             Press  6.To View User Dashboard" << endl;
    cout << "                             Press  7.To View All Cars Available For Rent" << endl;
    cout << "                             Press  8.To Rent A Car" << endl;
    cout << "                             Press  9.For service Processing " << endl;
    cout << "                             Press 10.To Customize Your Car " << endl;
    cout << "                             Press 11.Logout " << endl;
    cout << "                             Press  0.To Exit From The Program " << endl;
    cout << "                       ++++******************************************************++++\n\n"
         << endl;
}
void Cars_Display(string CarDetails[100][6])
{
    cout << "********************************************************************************************************************************************************************" << endl;
    cout << "                                                       All Cars With Details(Name,Brand,Price etc..)" << endl;
    cout << setw(28) << left << "ManuFacturer/Brand" << setw(28) << left << "Car Name " << setw(28) << left << "Car_Model" << setw(28) << left << "Model_Year" << setw(28) << left << "Price(In Dollars $)" << setw(28) << left << "Available colors" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (CarDetails[i][0] != "")
        {
            cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
            for (int j = 0; j < 6; j++)
            {
                cout << setw(28) << left << CarDetails[i][j];
            }
            cout << endl;
        }
    }
    cout << "********************************************************************************************************************************************************************" << endl;

    cout << "\n\n";
}
void Admin_Menu()
{
    cout << "                        Branded Automotive Showroom Provided You Following Facilities \n"
         << endl;
    cout << "                             Press 1.To Manage Cars Section" << endl;
    cout << "                             Press 2.To Manage Parts Section" << endl;
    cout << "                             Press 3.To View User's Dashboard " << endl;
    cout << "                             Press 4.To Manage Rent Cars Section " << endl;
    cout << "                             Press 5.To Manage Servicing Facilities" << endl;
    cout << "                             Press 6.To Manage Customize Car System" << endl;
    cout << "                             Press 7.To Logout" << endl;
    cout << "                             Press 0.To Exit From The Program " << endl;
    cout << "                       ++++******************************************************++++\n\n"
         << endl;
}
bool Valid_UersName(string User_Name)
{
    bool flag;
    int size = User_Name.length();
    if (size <= 28)
    {
        for (int i = 0; i < size; i++)
        {
            if ((User_Name[i] >= 'A' && User_Name[i] <= 'Z') || (User_Name[i] >= 'a' && User_Name[i] <= 'z') || User_Name[i] == ' ')
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
bool Add_User(string User_Name, string Users[100][6])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Users[i][0] == "")
        {
            Users[i][0] = User_Name;
            flag = true;
            break;
        }
    }
    return flag;
}
bool Buy_Car(string CarName, string CarDetails[100][6], string Users[100][6], string Cars_Brand[5], string User_Name, int input, int Input_Copy, string Model)
{
    bool flag = false;
    Input_Copy = input - 1;
    for (int i = 0; i < 100; i++)
    {

        if (Users[i][0] == User_Name)
        {
            for (int k = 0; k < 100; k++)
            {
                if (CarDetails[k][0] == Cars_Brand[Input_Copy])
                {
                    if (CarDetails[k][1] == CarName)
                    {
                        if (Model == CarDetails[k][2])
                        {
                            Users[i][1] = CarDetails[k][0];
                            Users[i][2] = CarDetails[k][1];
                            Users[i][3] = CarDetails[k][2];
                            Users[i][4] = CarDetails[k][3];
                            Users[i][5] = CarDetails[k][4];

                            CarDetails[k][0] = {""};
                            CarDetails[k][1] = {""};
                            CarDetails[k][2] = {""};
                            CarDetails[k][3] = {""};
                            CarDetails[k][4] = {""};

                            flag = true;
                        }
                    }
                }
            }
        }
    }
    return flag;
}
void Cars_WithOneBrand(string Cars_Brand[5], string CarDetails[100][6], int input, int Input_Copy)
{
    Input_Copy = input;
    Input_Copy = Input_Copy - 1;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                                              List Of All Cars Belongs To " << Cars_Brand[Input_Copy] << " \n";
    cout << setw(28) << left << "ManuFacturer/Brand" << setw(28) << left << "Car Name " << setw(28) << left << "Car_Model" << setw(28) << left << "Model_Year" << setw(28) << left << "Price(In Dollars $)" << setw(28) << left << "Available colors" << endl;
    for (int i = 0; i < 100; i++)
    {

        if (CarDetails[i][0] == Cars_Brand[Input_Copy])
        {
            cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
            for (int j = 0; j < 6; j++)
            {
                cout << setw(28) << left << CarDetails[i][j];
            }
            cout << endl;
        }
    }

    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
void Buy_CarFunctionCout(string CarDetails[100][6], string Cars_Brand[5], string CarName, int input, int Input_Copy, string User_Name, string Users[100][6], string Model)
{
    bool flag;
    Cars_WithOneBrand(Cars_Brand, CarDetails, input, Input_Copy);
    cout << "\n\n";
    cin.ignore();
    cout << "                                 Enter The Name Of the Car: ";
    getline(cin, CarName);
    cout << "                                 Enter The Model of the Car: ";
    getline(cin, Model);
    if (Valid_CarName(CarName))
    {
        flag = Buy_Car(CarName, CarDetails, Users, Cars_Brand, User_Name, input, Input_Copy, Model);
        if (flag == true)
        {
            cout << "                                 Please Pay Your Money And Get Your Car Is Ready..." << endl;
        }
        else
        {
            cout << "                                 Cannot Find Car OF Such Name ..." << endl;
        }
    }
    else
    {
        cout << "                                    Invalid CarName Or Color ...." << endl;
    }

    Halt();
}
void Search_CarFunctionCout(string option, string CarName, string CarDetails[100][6], string Cars_Brand[5], int input, int Input_Copy, string Brand_Car)
{
back1:
    cout << "               *********************************************************************************" << endl;
    cout << "                                              Searching Facility" << endl;
    cout << "               *********************************************************************************\n"
         << endl;
    cout << "               Dear Customer Would you like me to show You Some Available Brand So you Can Choose\n";
    cout << "                            Which You want to Search of sepecific Brand...(Y/N) \n"
         << endl;
    cout << "           Please Type Y For Yes And N For No To search Manually.Only Available Brand's Car will Be Found...: ";
    cin >> option;
    system("CLS");
    if (option == "Y" || option == "y")
    {
        Menu_CarsBrand();
        cout << endl;
        cout << "                                Enter The Brand/Macfacturer Of Car From Above(in form of 1,2,3..): ";
        cin >> input;
        cin.ignore();
        cout << "                                Enter The Name of the Car: ";
        getline(cin, CarName);
        if (Valid_CarName(CarName))
        {
            if (Car_Search(CarName, CarDetails, Cars_Brand, input, Input_Copy, Brand_Car))
            {
            }
            else
            {
                cout << "                                 Car not Found Or Out OF stack!!!!" << endl;
            }
        }
        else
        {
            cout << "                                  You Have Enter Wrong CarName..." << endl;
        }
        cout << "\n\n";
    }
    else if (option == "N" || option == "n")
    {
        cin.ignore();
        cout << "                                Enter The Brand/Macfacturer Of Car : ";
        getline(cin, Brand_Car);
        cout << "                                Enter The Name & Model Number Of the Car: ";
        getline(cin, CarName);

        if (Valid_CarName(CarName))
        {

            if (Car_Search(CarName, CarDetails, Cars_Brand, input, Input_Copy, Brand_Car))
            {
            }
            else
            {
                cout << "                                 Car not Found Or Out OF stack!!!!" << endl;
            }
        }
        else
        {
            cout << "                                 You Have Enter Wrong CarName..." << endl;
            cout << "                                You Have Enter Wrong.Do you want try again(Y/N)...: ";
            cin >> option;
            if (option == "Y" || option == "y")
            {
                goto back1;
            }
        }

        cout << "\n\n";
    }
    else if (!(option == "Y" || option == "Y") || (option == "n" || option == "N"))
    {
        cout << "                                You Have Enter Wrong.Do you want try again(Y/N)...: ";
        cin >> option;
        if (option == "Y" || option == "y")
        {
            goto back1;
        }
        else if (!(option == "n" || option == "N"))
        {
            cout << "                                You Have Enter Wrong" << endl;
        }
    }
    Halt();
}
void User_Dashboard(string Users[100][6])
{
    cout << "====================================================================================================================================================================" << endl;
    cout << "                                                              Users Dashboard \n"
         << endl;
    cout << setw(28) << left << "User Name" << setw(28) << left << "ManuFacturer/Brand" << setw(28) << left << "Car Name" << setw(28) << left << " Car_Model" << setw(28) << left << "Model_Year" << setw(28) << left << "Price(In Dollars $)" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (Users[i][1] != "")
        {
            cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
            for (int j = 0; j < 6; j++)
            {
                cout << setw(28) << left << Users[i][j];
            }
            cout << endl;
        }
    }
    cout << "====================================================================================================================================================================" << endl;

    cout << "\n\n";
    Halt();
}
void Parts_Menu()
{
    cout << "        ***********************************************************************************************" << endl;
    cout << "                                List Of All Parts Available In Branded Showroom\n";
    cout << "                                1.Engines" << endl;
    cout << "                                2.Batteries " << endl;
    cout << "                                3.Tyres " << endl;
    cout << "                                4.Radiators " << endl;
    cout << "                                5.Axles " << endl;
    cout << "        ***********************************************************************************************\n\n"
         << endl;
}
void ViewCars_Parts(string PartsDetail[100][3], int Parts_Amount[100])
{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                                                        All Parts of Cars Available In Branded ShowRoom" << endl;
    cout << setw(40) << left << "Part Type" << setw(40) << left << "Brand/Manufacturer" << setw(40) << left << "Price(In $Dollars)" << setw(40) << left << "Available Amounts(Stack)" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (PartsDetail[i][0] != "")
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == 3)
                {
                    cout << setw(40) << left << Parts_Amount[i] << endl;
                }
                else
                {
                    cout << setw(40) << left << PartsDetail[i][j];
                }
            }
        }
    }
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    Halt();
}
bool Valid_PartAmount(int amount)
{
    bool flag = false;
    if (amount <= 50 && amount > 0)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}
bool Valid_Brand_Car(string Brand_Car)
{

    bool flag;
    int size = Brand_Car.length();
    if (size <= 28)
    {
        for (int i = 0; i < size; i++)
        {
            if ((Brand_Car[i] >= 'A' && Brand_Car[i] <= 'Z') || (Brand_Car[i] >= 'a' && Brand_Car[i] <= 'z') || Brand_Car[i] == ' ' || Brand_Car[i] == '_' || Brand_Car[i] == '-')
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
bool Add_Parts(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy, string price, string Brand_Car, int amount)
{
    bool flag = false;
    Input_Copy = input - 1;
    for (int i = 0; i < 100; i++)
    {
        if (PartsDetail[i][0] == "")
        {
            PartsDetail[i][0] = Parts_Name[Input_Copy];
            PartsDetail[i][1] = Brand_Car;
            PartsDetail[i][2] = price;
            Parts_Amount[i] = amount;
            flag = true;
            break;
        }
    }
    return flag;
}
void Parts_WithOnePartName(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy)
{
    Input_Copy = input - 1;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                                                        All Parts of Cars Belongs To " << Parts_Name[Input_Copy] << endl;
    cout << setw(40) << left << "Part Type" << setw(40) << left << "Brand/Manufacturer" << setw(40) << left << "Price(In $Dollars" << setw(40) << left << "Available Amounts(Stack)" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (PartsDetail[i][0] == Parts_Name[Input_Copy])
        {
            cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
            for (int j = 0; j < 4; j++)
            {
                if (j == 3)
                {
                    cout << setw(40) << left << Parts_Amount[i] << endl;
                }
                else
                {
                    cout << setw(40) << left << PartsDetail[i][j];
                }
            }
        }
    }
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
void Add_PartsFunctionCout(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy, string price, string Brand_Car, int amount)
{
    Parts_WithOnePartName(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy);
    cin.ignore();
    cout << "                          Enter Brand Name: ";
    getline(cin, Brand_Car);
    cout << "                          Enter Price: ";
    getline(cin, price);
    cout << "                          Enter The Amount Of Part: ";
    cin >> amount;
    if (Valid_PartAmount(amount) && Valid_CarPrice(price) && Valid_Brand_Car(Brand_Car))
    {
        if (Add_Parts(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy, price, Brand_Car, amount))
        {
            cout << "                          Part Added Successfully!!!" << endl;
        }
        else
        {
            cout << "                          Part Not Added Because Room IS Full" << endl;
        }
    }
    else
    {
        cout << "                          You Entered The Name inCorrect!!!!.." << endl;
    }
    Halt();
}
bool Buy_Part(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], string Brand_Car, int amount)
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Brand_Car == PartsDetail[i][1])
        {
            if (Parts_Amount[i] > amount)
            {
                Parts_Amount[i] = Parts_Amount[i] - amount;
                flag = true;
            }
            else if (Parts_Amount[i] == amount)
            {
                Parts_Amount[i] = 0;
                for (int j = 0; j < 3; j++)
                {
                    PartsDetail[i][j] = {""};
                    flag = true;
                }
            }
        }
    }
    return flag;
}
void Buy_PartsFunctionCout(string PartsDetail[100][3], int Parts_Amount[100], string Parts_Name[5], int input, int Input_Copy, string price, string Brand_Car, int amount)
{
    Parts_WithOnePartName(PartsDetail, Parts_Amount, Parts_Name, input, Input_Copy);

    cout << "                          Enter The Brand Name Of Part You want to buy: ";
    cin.ignore();
    getline(cin, Brand_Car);
    cout << "                          Enter The Amount: ";
    cin >> amount;
    if (Buy_Part(PartsDetail, Parts_Amount, Parts_Name, Brand_Car, amount))
    {
        cout << "                          Part Has Been Purchased Please Pay The Bill!!!!!!!!!" << endl;
    }
    else
    {
        cout << "                          Sorry Something Is Wrong.....!!!!!!!!" << endl;
    }
    Halt();
}
void View_RentCars(string RentCar[100][4], int RentCar_Price[100])
{
    cout << "===================================================================================================================================================" << endl;
    cout << "                                                         Rent a Car\n";
    cout << "                                       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
         << "\n\n";
    cout << "                                                    Available Cars For Rent..." << endl;
    cout << "**************************************************************************************************************************************************" << endl;
    cout << setw(30) << left << "Brand Name" << setw(30) << left << "Car Model" << setw(30) << left << "Car Model Year" << setw(30) << left << "Available Colors" << setw(30) << left << "Price(Per Day In Dollars)" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (RentCar[i][0] != "")
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == 4)
                {
                    cout << setw(30) << left << RentCar_Price[i] << endl;
                }
                else
                {
                    cout << setw(30) << left << RentCar[i][j];
                }
            }
        }
    }
    cout << "===================================================================================================================================================" << endl;
}
bool Rent_Car(string CarName, int Days, int RentCar_Price[100], string RentCar[100][4], int Rent[1])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (RentCar[i][0] != "")
        {
            if (RentCar[i][1] == CarName)
            {
                for (int j = 0; j < 4; j++)
                {
                    RentCar[i][j] = {""};
                    flag = true;
                }
                Rent[0] = RentCar_Price[i] * Days;
                RentCar_Price[i] = {0};
                flag = true;
            }
        }
    }
    return flag;
}
bool Valid_Days(int Days)
{
    bool flag = false;
    if (Days > 0 && Days <= 15)
    {
        flag = true;
    }
    return flag;
}
void Rent_CarFunctionCout(string CarName, int Days, int RentCar_Price[100], string RentCar[100][4], int Rent[1])
{
    View_RentCars(RentCar, RentCar_Price);
    cin.ignore();
    cout << "                                 Enter The Name Of Car From Above: ";
    getline(cin, CarName);
    cout << "                                 Enter No. of Days to rent a car Max(15) & Min(1): ";
    cin >> Days;
    cout << endl;
    if (Valid_Days(Days))
    {
        if (Rent_Car(CarName, Days, RentCar_Price, RentCar, Rent))
        {
            cout << "                                 You Have Rented a Car From Us... Have A Good Ride Sir And\n";
            cout << "                                                     Enjoy " << endl;
            cout << "                                 You have to Pay $" << Rent[0] << " Thank You!!!!" << endl;
        }
        else
        {
            cout << "                                 You have Entered WRONG Car Name" << endl;
        }
    }
    else
    {
        cout << "                                 The Days Numbers Are Invalid " << endl;
    }

    Halt();
}
bool Add_RentCar(string Brand_Car, string Model, string ModelYear, string Colour, int amount, int RentCar_Price[100], string RentCar[100][4])
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (RentCar[i][0] == "")
        {
            RentCar[i][0] = Brand_Car;
            RentCar[i][1] = Model;
            RentCar[i][2] = ModelYear;
            RentCar[i][3] = Colour;
            RentCar_Price[i] = amount;
            flag = true;
            break;
        }
    }
    return flag;
}
void Add_RentCarFunctionCout(string Brand_Car, string Model, string ModelYear, string Colour, int amount, int RentCar_Price[100], string RentCar[100][4])
{
    View_RentCars(RentCar, RentCar_Price);
    cin.ignore();
    cout << "                                 Enter The Brand of Car: ";
    getline(cin, Brand_Car);
    cout << "                                 Enter Model Of The Car: ";
    getline(cin, Model);
    cout << "                                 Enter The Model Year Of the Car: ";
    getline(cin, ModelYear);
    cout << "                                 Enter The Color OF the Car: ";
    getline(cin, Colour);
    cout << "                                 Enter The Price Of The Car(Per Day In Dollars): ";
    cin >> amount;
    if (Valid_Brand_Car(Brand_Car) && Valid_CarModel(Model) && Valid_ModelYear(ModelYear) && Valid_CarColor(Colour))
    {
        if (Add_RentCar(Brand_Car, Model, ModelYear, Colour, amount, RentCar_Price, RentCar))
        {
            cout << "                                 Car Added In Rent Section Successfully!!!!" << endl;
        }
        else
        {
            cout << "                                 Car is not Added Because Room Is Full!!!" << endl;
        }
    }
    else
    {
        cout << "                                 You Have Enter SomeThing Wrong!!!!" << endl;
    }
    Halt();
}
bool Save_Cars(string CarDetails[100][6])
{
    bool flag = false;
    ofstream SaveCars("Cars.csv");
    if (SaveCars.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (CarDetails[i][0] != "")
            {
                for (int j = 0; j < 6; j++)
                {
                    SaveCars << CarDetails[i][j] << ",";
                }
                SaveCars << endl;
                flag = true;
            }
        }
    }
    return flag;
}
bool Save_Parts(string PartsDetail[100][3], int Parts_Amount[100])
{
    bool flag = false;
    ofstream SaveParts("Parts.csv");
    if (SaveParts.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (PartsDetail[i][0] != "")
            {
                for (int j = 0; j < 3; j++)
                {
                    SaveParts << PartsDetail[i][j] << ",";
                }
                SaveParts << Parts_Amount[i] << ",";
                SaveParts << endl;
                flag = true;
            }
        }
    }
    return flag;
}
bool Save_RentCars(int RentCar_Price[100], string RentCar[100][4])
{
    bool flag = false;
    ofstream SaveRentCars("RentCars.csv");
    if (SaveRentCars.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (RentCar[i][0] != "")
            {
                for (int j = 0; j < 4; j++)
                {
                    SaveRentCars << RentCar[i][j] << ",";
                }
                SaveRentCars << RentCar_Price[i] << ",";
                flag = true;
                SaveRentCars << endl;
            }
        }
    }
    return flag;
}
bool Load_Cars(string CarDetails[100][6])
{
    bool flag;
    int i = 0;
    ifstream LoadCars("Cars.csv");
    if (!LoadCars.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string Brandname, carname, carmodel, modelyear, carprice, carcolor;
        string line;
        while (!LoadCars.eof() && i < 100)
        {
            getline(LoadCars, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, Brandname, ',');
            CarDetails[i][0] = Brandname;
            getline(ss, carname, ',');
            CarDetails[i][1] = carname;
            getline(ss, carmodel, ',');
            CarDetails[i][2] = carmodel;
            getline(ss, modelyear, ',');
            CarDetails[i][3] = modelyear;
            getline(ss, carprice, ',');
            CarDetails[i][4] = carprice;
            getline(ss, carcolor, ',');
            CarDetails[i][5] = carcolor;
            i++;
        }

        LoadCars.close();
        return true;
    }
}
bool Load_Parts(string PartsDetail[100][3], int Parts_Amount[100])
{
    int i = 0;
    ifstream LoadParts("Parts.csv");
    if (!LoadParts.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string partname, partbrand, partprice, partamount;
        string line;
        int amount;
        while (!LoadParts.eof() && i < 100)
        {
            getline(LoadParts, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, partname, ',');
            PartsDetail[i][0] = partname;
            getline(ss, partbrand, ',');
            PartsDetail[i][1] = partbrand;
            getline(ss, partprice, ',');
            PartsDetail[i][2] = partprice;
            getline(ss, partamount, ',');
            amount = stoi(partamount);
            Parts_Amount[i] = amount;
            i++;
        }

        LoadParts.close();
        return true;
    }
}
bool Load_RentCars(int RentCar_Price[100], string RentCar[100][4])
{
    int i = 0;
    ifstream LoadRentCars("RentCars.csv");
    if (!LoadRentCars.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string carbrand, carmodel, carmodelyear, carcolor, carprice;
        string line;
        int price;
        while (!LoadRentCars.eof() && i < 100)
        {
            getline(LoadRentCars, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, carbrand, ',');
            RentCar[i][0] = carbrand;
            getline(ss, carmodel, ',');
            RentCar[i][1] = carmodel;
            getline(ss, carmodelyear, ',');
            RentCar[i][2] = carmodelyear;
            getline(ss, carcolor, ',');
            RentCar[i][3] = carcolor;
            getline(ss, carprice, ',');
            price = stoi(carprice);
            RentCar_Price[i] = price;
            i++;
        }

        LoadRentCars.close();
        return true;
    }
}
bool Save_Users(string Users[100][6])
{
    bool flag = false;
    ofstream SaveUsers("Users.csv");
    if (SaveUsers.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (Users[i][0] != "")
            {
                for (int j = 0; j < 6; j++)
                {
                    SaveUsers << Users[i][j] << ",";
                }
                SaveUsers << endl;
                flag = true;
            }
        }
    }
    return flag;
}
bool Load_Users(string Users[100][6])
{
    int i = 0;
    ifstream LoadUsers("Users.csv");
    if (!LoadUsers.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string username, carbrand, carname, carmodel, carcolor, carprice;
        string line;
        while (!LoadUsers.eof() && i < 100)
        {
            getline(LoadUsers, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, username, ',');
            Users[i][0] = username;
            getline(ss, carbrand, ',');
            Users[i][1] = carbrand;
            getline(ss, carname, ',');
            Users[i][2] = carname;
            getline(ss, carmodel, ',');
            Users[i][3] = carmodel;
            getline(ss, carcolor, ',');
            Users[i][4] = carcolor;
            getline(ss, carprice, ',');
            Users[i][5] = carprice;
            i++;
        }

        LoadUsers.close();
        return true;
    }
}
void UserService_Menu()
{
    cout << "===================================================================================================================================================" << endl;
    cout << "                                       Service Processing Facility\n";
    cout << "                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                              Branded Service Facility Provides Following Facilities" << endl;
    cout << "                              Press 1.To Check If Your Car Needs Service Processing" << endl;
    cout << "                              Press 2.To Change The Engine Oil" << endl;
    cout << "===================================================================================================================================================" << endl;
}
void View_EngineOil(string Engine_Oil[100][2], int Engine_oil_Amount[100])
{
    cout << "===================================================================================================================================================" << endl;
    cout << "                                       Available Engins's Oils\n";
    cout << "                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << setw(40) << left << "Engines" << setw(40) << left << "Price In Dollars" << setw(40) << left << "Stack Available" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (Engine_Oil[i][0] != "")
        {
            for (int j = 0; j < 2; j++)
            {
                cout << setw(40) << left << Engine_Oil[i][j];
            }
            cout << setw(40) << left << Engine_oil_Amount[i] << endl;
        }
    }
    cout << "===================================================================================================================================================" << endl;
}
bool UserService_Done(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name)
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Engine_Oil[i][0] == Engine_Name)
        {
            if (Engine_Oil[i][0] != "")
            {
                if (Engine_oil_Amount[i] == 1)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        Engine_Oil[i][j] = {""};
                    }
                    Engine_oil_Amount[i] = {0};
                    flag = true;
                }
                else
                {
                    Engine_oil_Amount[i] = Engine_oil_Amount[i] - 1;
                    flag = true;
                }
            }
        }
    }
    return flag;
}
void UserService_CarintoServiceDone(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name)
{
    View_EngineOil(Engine_Oil, Engine_oil_Amount);
    cin.ignore();
    cout << "                                 Enter The Name of The Engine's Oil for Your Car to Services: ";
    getline(cin, Engine_Name);
    if (UserService_Done(Engine_Oil, Engine_oil_Amount, Engine_Name))
    {
        cout << "                                 Your Car Is Being under Service" << endl;
        cout << "                                 Thank You!!For Coming.." << endl;
    }
    else
    {
        cout << "                                 Can't Find The Engine's Oil You Entered..." << endl;
    }
}
bool Valid_Engine_Name(string Engine_Name)
{
    bool flag;
    int size = Engine_Name.length();
    if (size <= 40)
    {
        for (int i = 0; i < size; i++)
        {
            if ((Engine_Name[i] >= 'A' && Engine_Name[i] <= 'Z') || (Engine_Name[i] >= 'a' && Engine_Name[i] <= 'z') || Engine_Name[i] == ' ' || Engine_Name[i] == '_' || (Engine_Name[i] >= '0' && Engine_Name[i] <= '9'))
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
bool Add_EnginseOil(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name, int amount, string price)
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Engine_Oil[i][0] == "")
        {
            Engine_Oil[i][0] = Engine_Name;
            Engine_Oil[i][1] = price;
            Engine_oil_Amount[i] = amount;
            flag = true;
            break;
        }
    }
    return flag;
}
void Admin_ManageServMenu()
{
    cout << "############################################################################################################################" << endl;
    cout << "                                                 Service Facilities Maanagement" << endl;
    cout << "                                                 Press 1.To Add Engine's Oil" << endl;
    cout << "                                                 Press 2.To View All Engine's Oil Available" << endl;
    cout << "############################################################################################################################" << endl;
}
void Admin_ServiceFunCout(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name, int amount, string price, int input, string option)
{
admin:
    Admin_ManageServMenu();
    cout << "Enter The Option: ";
    cin >> input;
    system("CLS");
    if (input == 1)
    {
        View_EngineOil(Engine_Oil, Engine_oil_Amount);
        cin.ignore();
        cout << "Enter The Name of Engine's Oil: ";
        getline(cin, Engine_Name);
        cout << "Enter The Price of Engine's oil: ";
        getline(cin, price);
        cout << "Enter Amount of Engine's oil(MAX:50): ";
        cin >> amount;
        if (Valid_Engine_Name(Engine_Name) && Valid_PartAmount(amount) && Valid_CarPrice(price))
        {
            if (Add_EnginseOil(Engine_Oil, Engine_oil_Amount, Engine_Name, amount, price))
            {
                cout << "Engines's oil Added To Stack Successfully" << endl;
            }
            else
            {
                cout << "Could not Add Because Inventory is Full!!!" << endl;
            }
        }
        else
        {
            cout << "Please Enter Correct Data" << endl;
        }
    }
    if (input == 2)
    {
        View_EngineOil(Engine_Oil, Engine_oil_Amount);
    }
    else if (!(input > 0 && input < 3))
    {
        cout << "                            You Have Enter invalid Option....." << endl;
        cout << "                              Do you wanna try again(Y/N) :";
        cin >> option;
        system("CLS");
        if (option == "Y" || option == "y")
        {
            goto admin;
        }
        else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
        {
            cout << "                                You Have Enter Wrong ..." << endl;
        }
    }
    Halt();
}
void User_ServiceFunctcout(string Engine_Oil[100][2], int Engine_oil_Amount[100], string Engine_Name, int amount, int input, string option)
{
user:
    UserService_Menu();
    cout << "                           Enter Option From Above: ";
    cin >> input;
    system("CLS");
    if (input == 1)
    {
        cout << "                           Please Enter The Distance in KM Car Travelled Till now: ";
        cin >> amount;
        if (amount >= 2500)
        {
            cout << "                                   Your Car Need Servicing Facility..." << endl;
            cout << "                   Your Vehicle Travelled " << amount << " But The Limit For Servicing is 2500KM\n\n";
            UserService_CarintoServiceDone(Engine_Oil, Engine_oil_Amount, Engine_Name);
        }
        else if (amount < 2500)
        {
            cout << "                       Your Vehicle Travelled " << amount << " But The Limit For Servicing is 2500KM\n";
            cout << "                                   Do you want to service your car(Y/N): ";
            cin >> option;
            if (option == "Y" || option == "y")
            {
                UserService_CarintoServiceDone(Engine_Oil, Engine_oil_Amount, Engine_Name);
            }
            else if (option == "n" || option == "N")
            {
                cout << "                               Thanks For Coming...\n\n";
            }
            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
            {
                cout << "                             You Have Enter Wrong ..." << endl;
            }
        }
    }
    if (input == 2)
    {
        UserService_CarintoServiceDone(Engine_Oil, Engine_oil_Amount, Engine_Name);
    }
    else if (!(input > 0 && input < 3))
    {
        cout << "                            You Have Enter invalid Option....." << endl;
        cout << "                              Do you wanna try again(Y/N) :";
        cin >> option;
        system("CLS");
        if (option == "Y" || option == "y")
        {
            goto user;
        }
        else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
        {
            cout << "                                You Have Enter Wrong ..." << endl;
        }
    }
    Halt();
}
bool Save_ServiceData(string Engine_Oil[100][2], int Engine_oil_Amount[100])
{
    bool flag = false;
    ofstream Save_ServiceData("Service.csv");
    if (Save_ServiceData.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (Engine_Oil[i][0] != "")
            {
                for (int j = 0; j < 2; j++)
                {
                    Save_ServiceData << Engine_Oil[i][j] << ",";
                }
                Save_ServiceData << Engine_oil_Amount[i] << ",";
                Save_ServiceData << endl;
                flag = true;
            }
        }
    }
    return flag;
}
bool Load_ServiceData(string Engine_Oil[100][2], int Engine_oil_Amount[100])
{
    int i = 0;
    ifstream LoadServiceData("Service.csv");
    if (!LoadServiceData.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string enginename, engineprice, amount;
        string line;
        int price;
        while (!LoadServiceData.eof() && i < 100)
        {
            getline(LoadServiceData, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, enginename, ',');
            Engine_Oil[i][0] = enginename;
            getline(ss, engineprice, ',');
            Engine_Oil[i][1] = engineprice;
            getline(ss, amount, ',');
            price = stoi(amount);
            Engine_oil_Amount[i] = price;
            i++;
        }

        LoadServiceData.close();
        return true;
    }
}
void Car_SectionMenu()
{
    cout << "############################################################################################################################" << endl;
    cout << "                                                Manage Car Section" << endl;
    cout << "                                 =========================================================" << endl;
    cout << "                                 Press 1.To View The Cars With Details(Name,Brand,Price etc..)" << endl;
    cout << "                                 Press 2.To Add A Car" << endl;
    cout << "                                 Press 3.To Search a Car " << endl;
    cout << "                                 Press 4.Return To Main Menu " << endl;
    cout << "############################################################################################################################" << endl;
}
void Parts_Section()
{
    cout << "===================================================================================================================================================" << endl;
    cout << "                                       Manage Car Parts Section\n";
    cout << "                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                             Press 1.To View All Parts/Accessories" << endl;
    cout << "                             Press 2.To Add  Parts(Accessories)" << endl;
    cout << "                             Press 3.To Return To Main Menu" << endl;
    cout << "===================================================================================================================================================" << endl;
}
void RentCars_Section()
{
    cout << "===================================================================================================================================================" << endl;
    cout << "                                       Manage RentCars Section\n";
    cout << "                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                             Press 1.To Add Car For Rent " << endl;
    cout << "                             Press 2.To View Cars Available For Rent " << endl;
    cout << "                             Press 3.To Return To Main Menu" << endl;
    cout << "===================================================================================================================================================" << endl;
}
void Car_CustomizerMenu()
{
    cout << "############################################################################################################################" << endl;
    cout << "                                                Customizer Your Car" << endl;
    cout << "                                 =========================================================" << endl;
    cout << "                                 Press 1.To Change Paint of Car" << endl;
    cout << "                                 Press 2.To Change Wheel of Car" << endl;
    cout << "                                 Press 3.To Change Suspension Kits " << endl;
    cout << "                                 Press 4.To Change Engine of Car" << endl;
    cout << "                                 Press 5.To Change Brake Kit of Car" << endl;
    cout << "                                 Press 0.To Return To Main Menu" << endl;
    cout << "############################################################################################################################" << endl;
}
void View_CustomizerPartsOne(string Cars_Customizer[100][3], string CarsCustomizers[5], int Cars_CustomizerAmount[100], int input, int Input_Copy)
{
    Input_Copy = input - 1;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                                                        All Availables " << CarsCustomizers[Input_Copy] << endl;
    cout << setw(40) << left << "Part Type" << setw(40) << left << "Name/Special Tag" << setw(40) << left << "Price(In $Dollars" << setw(40) << left << "Available Amounts(Stack)" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (Cars_Customizer[i][0] == CarsCustomizers[Input_Copy])
        {
            cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
            for (int j = 0; j < 4; j++)
            {
                if (j == 3)
                {
                    cout << setw(40) << left << Cars_CustomizerAmount[i] << endl;
                }
                else
                {
                    cout << setw(40) << left << Cars_Customizer[i][j];
                }
            }
        }
    }
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
bool Buy_CustPart(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100], string CustPar_Name)
{
    bool flag = false;
    for (int i = 0; i < 100; i++)
    {
        if (Cars_Customizer[i][1] == CustPar_Name)
        {
            if (Cars_Customizer[i][1] != "")
            {
                if (Cars_CustomizerAmount[i] == 1)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        Cars_Customizer[i][j] = {""};
                    }
                    Cars_CustomizerAmount[i] = {0};
                    flag = true;
                }
                else
                {
                    Cars_CustomizerAmount[i] = Cars_CustomizerAmount[i] - 1;
                    flag = true;
                }
            }
        }
    }
    return flag;
}
void Customizer_IFcaseFunctCout(string Cars_Customizer[100][3], string CarsCustomizers[5], int Cars_CustomizerAmount[100], int input, int Input_Copy, string CustPar_Name)
{
    View_CustomizerPartsOne(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy);
    cin.ignore();
    cout << "                                 Enter Name/special Tag of Part: ";
    getline(cin, CustPar_Name);
    if (Buy_CustPart(Cars_Customizer, Cars_CustomizerAmount, CustPar_Name))
    {
        cout << "                                 Your Car is Being Customizing " << endl;
        cout << "                                    Have a Nice Ride Sir!!!!" << endl;
    }
    else
    {
        cout << "                                 Cant Find The Item You Entered" << endl;
    }
}
void whole_CustomizeCaseFunCout(string option, string Cars_Customizer[100][3], string CarsCustomizers[5], int Cars_CustomizerAmount[100], int input, int Input_Copy, string CustPar_Name)
{
    while (input != 0)
    {
    user1:
        Car_CustomizerMenu();
        cout << "                                 Select From Above: ";
        cin >> input;
        system("CLS");
        if (input == 1)
        {
            Customizer_IFcaseFunctCout(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy, CustPar_Name);
        }
        else if (input == 2)
        {
            Customizer_IFcaseFunctCout(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy, CustPar_Name);
        }
        else if (input == 3)
        {
            Customizer_IFcaseFunctCout(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy, CustPar_Name);
        }
        else if (input == 4)
        {
            Customizer_IFcaseFunctCout(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy, CustPar_Name);
        }
        else if (input == 5)
        {
            Customizer_IFcaseFunctCout(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy, CustPar_Name);
        }
        else if (!(input >= 0 && input < 6))
        {
            cout << "                            You Have Enter invalid Option....." << endl;
            cout << "                              Do you wanna try again(Y/N) :";
            cin >> option;
            system("CLS");
            if (option == "Y" || option == "y")
            {
                goto user1;
            }
            else if (!(option == "Y" || option == "y") || (option == "n" || option == "N"))
            {
                cout << "                                You Have Enter Wrong ..." << endl;
            }
        }
        Halt();
    }
}
bool Valid_CustPar_Name(string CustPar_Name)
{
    bool flag;
    int size = CustPar_Name.length();
    if (size <= 40)
    {
        for (int i = 0; i < size; i++)
        {
            if ((CustPar_Name[i] >= 'A' && CustPar_Name[i] <= 'Z') || (CustPar_Name[i] >= 'a' && CustPar_Name[i] <= 'z') || CustPar_Name[i] == ' ' || CustPar_Name[i] == '_' || (CustPar_Name[i] >= '0' && CustPar_Name[i] <= '9'))
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
void Cust_ifcaseFunCout(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100], string CarsCustomizers[5], int input, string CustPar_Name, string price, int amount, int Input_Copy)
{
    View_CustomizerPartsOne(Cars_Customizer, CarsCustomizers, Cars_CustomizerAmount, input, Input_Copy);
    cin.ignore();
    cout << "                                 Enter The Name/Special Tag Of Part: ";
    getline(cin, CustPar_Name);
    cout << "                                 Enter The Price of Part: ";
    getline(cin, price);
    cout << "                                 Enter Amount of Part(MAX:50): ";
    cin >> amount;
    if (Valid_CustPar_Name(CustPar_Name) && Valid_PartAmount(amount) && Valid_CarPrice(price))
    {
        if (Add_CustPart(Cars_Customizer, Cars_CustomizerAmount, CarsCustomizers, input, CustPar_Name, price, amount, Input_Copy))
        {
            cout << "                                 Parts Added SuccessFullyy!!!" << endl;
        }
        else
        {
            cout << "                                 Slot Is Full Sorry!!" << endl;
        }
    }
    else
    {
        cout << "                                 Wrong Name/Amount/Price" << endl;
    }
}
bool Add_CustPart(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100], string CarsCustomizers[5], int input, string CustPar_Name, string price, int amount, int Input_Copy)
{
    bool flag;
    for (int i = 0; i < 100; i++)
    {
        if (Cars_Customizer[i][0] == "")
        {
            Input_Copy = input - 1;
            Cars_Customizer[i][0] = CarsCustomizers[Input_Copy];
            Cars_Customizer[i][1] = CustPar_Name;
            Cars_Customizer[i][2] = price;
            Cars_CustomizerAmount[i] = amount;
            flag = true;
            break;
        }
    }
    return flag;
}
void Cust_AdminMenu()
{
    cout << "===================================================================================================================================================" << endl;
    cout << "                                       Car Customize Management\n";
    cout << "                           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                              Branded  Car Customize Management Provides Following Facilities" << endl;
    cout << "                              Press 1.To Add New Part For Car customizer" << endl;
    cout << "                              Press 2.To View All Parts Available To Customize a Car" << endl;
    cout << "                              Press 0.To Retuen To Main Menu" << endl;
    cout << "===================================================================================================================================================" << endl;
}
void View_CustomizerPartsAll(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100])
{
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << "                                                        All Availables Parts To Customize Car" << endl;
    cout << setw(40) << left << "Part Type" << setw(40) << left << "Name/Special Tag" << setw(40) << left << "Price(In $Dollars" << setw(40) << left << "Available Amounts(Stack)" << endl;
    for (int i = 0; i < 100; i++)
    {
        if (Cars_Customizer[i][0] != "")
        {
            cout << "____________________________________________________________________________________________________________________________________________________________________" << endl;
            for (int j = 0; j < 4; j++)
            {
                if (j == 3)
                {
                    cout << setw(40) << left << Cars_CustomizerAmount[i] << endl;
                }
                else
                {
                    cout << setw(40) << left << Cars_Customizer[i][j];
                }
            }
        }
    }
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
}
void Admin_MENUinMenu()
{
    cout << "############################################################################################################################" << endl;
    cout << "                                                Customizer Your Car" << endl;
    cout << "                                 =========================================================" << endl;
    cout << "                                 Press 1.To Add Paint of Car" << endl;
    cout << "                                 Press 2.To Add Wheel of Car" << endl;
    cout << "                                 Press 3.To Add Suspension Kits " << endl;
    cout << "                                 Press 4.To Add Engine of Car" << endl;
    cout << "                                 Press 5.To Add Brake Kit of Car" << endl;
    cout << "                                 Press 0.To Return To Main Menu" << endl;
    cout << "############################################################################################################################" << endl;
}
bool Save_CustomizeCar(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100])
{
    bool flag = false;
    ofstream Save_CustomizeData("CarCustomize.csv");
    if (Save_CustomizeData.is_open())
    {
        for (int i = 0; i < 100; i++)
        {
            if (Cars_Customizer[i][0] != "")
            {
                for (int j = 0; j < 3; j++)
                {
                    Save_CustomizeData << Cars_Customizer[i][j] << ",";
                }
                Save_CustomizeData << Cars_CustomizerAmount[i] << ",";
                Save_CustomizeData << endl;
                flag = true;
            }
        }
    }
    return flag;
}
bool Load_CustomizeCar(string Cars_Customizer[100][3], int Cars_CustomizerAmount[100])
{
    int i = 0;
    ifstream LoadCarCustomize("CarCustomize.csv");
    if (!LoadCarCustomize.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string parttype, partname, partprice, amount;
        string line;
        int price;
        while (!LoadCarCustomize.eof() && i < 100)
        {
            getline(LoadCarCustomize, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, parttype, ',');
            Cars_Customizer[i][0] = parttype;
            getline(ss, partname, ',');
            Cars_Customizer[i][1] = partname;
            getline(ss, partprice, ',');
            Cars_Customizer[i][2] = partprice;
            getline(ss, amount, ',');
            price = stoi(amount);
            Cars_CustomizerAmount[i] = price;
            i++;
        }

        LoadCarCustomize.close();
        return true;
    }
}