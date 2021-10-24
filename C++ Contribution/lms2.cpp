#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

void initializeCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size);
void initializeUsers(string usernames[], string passwords[], int size);

//function for data persistent
bool saveCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int size);
bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size);
bool loadUser(string usersList[], string passwordList[], int size);

//COURSE MANAGEMENT
int searchCourseCode(string codeList[], int size, string courseCode);
bool addCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode, string courseName, int credit, int semester);
void viewCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size);
void viewSemesterCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, int semester);
bool updateCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string oldCourseCode, string courseCode, string courseName, int credit, int semester);
bool deleteCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode);

//VALIDATION FUNCTIONS
bool isValidCourseCode(string code);
bool isValidCreditHours(int creditHours);
bool isValidSemester(int semester);
bool isValidCourseName(string name);
bool validateAllData(string courseCode, string courseName, int credit, int semester);

//USER MANAGEMENT
bool userExist(string user[], string pass[], string users, string passs, int size);
void login(string &userName, string &password);

int main()
{

    //Maximum Size of All arrays
    int MAX_COURSES = 10;
    int MAX_USERS = 10;
    string oldCourseCode;
    bool flag = false;
    string userName;
    string password;
    string courseCode;
    string courseName;
    int credit;
    int semester;
    int input;
    //Declare All Arrays
    string usersList[MAX_USERS], passwordList[MAX_USERS];
    string codeList[MAX_COURSES], nameList[MAX_COURSES];
    int creditHours[MAX_COURSES], semList[MAX_COURSES];

    //Initialize all arrays
    initializeCourses(codeList, nameList, creditHours, semList, MAX_COURSES);
    initializeUsers(usersList, passwordList, MAX_USERS);

    //This function will load the courses in arrays
    loadCourses(codeList, nameList, creditHours, semList, MAX_COURSES);

    //This function will load the users in array
    loadUser(usersList, passwordList, MAX_USERS);

    //For starting code
    login(userName, password);

    do
    {

        while (userExist(usersList, passwordList, userName, password, MAX_USERS) != true || (userName == "" && password == ""))
        {
            cout << "Incorrect info please reenter username and password" << endl;
            cout << "Enter User name: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> password;
            cout << endl;
        }

        if (userExist(usersList, passwordList, userName, password, MAX_USERS))
        {

            cout << "Choose the following option" << endl;
            cout << "1   Add Courses" << endl;
            cout << "2   Update Courses" << endl;
            cout << "3   Delete Courses" << endl;
            cout << "4   View All Courses" << endl;
            cout << "5   View Courses of a Semester" << endl;
            cout << "6   Add a new student" << endl;
            cout << "7   Update student" << endl;
            cout<<"8  Delete student"<<endl;
            cout<<"9  View all students"<<endl;
            cout<<"10  Register the course for student"<<endl;
            cout<<"11  Unregister the course for student"<<endl;
            cout<<"12  Logout of the system"<<endl;
            cout<<"13  Exit program"<<endl;
            cout << "Enter the option: ";
            cin >> input;
            switch (input)
            {
            // This case for adding the course details
            case 1:

                cout << "Enter the details of the course: ";
                cin >> courseCode;
                cin >> credit;
                cin >> semester;
                cin.ignore();
                getline(cin, courseName);

                //Check validity of all inputs
                if (validateAllData(courseCode, courseName, credit, semester))
                {
                    //Call addCourse function
                    if (addCourses(codeList, nameList, creditHours, semList, MAX_COURSES, courseCode, courseName, credit, semester))
                    {
                        cout << "Course Successfully added" << endl;
                    }
                    else
                    {
                        cout << "Sorry No space to add new course" << endl;
                    }
                }
                else
                {
                    //If any validity is false it will not add the course
                    cout << "Invalid details" << endl;
                }

                break;

            // This case for Updating the course details
            case 2:

                cout << "Enter the course code" << endl;
                cin >> oldCourseCode;

                //check validity of courseCode
                if (isValidCourseCode(oldCourseCode))
                {

                    //Find the index of courseCode which user entered to update the course details

                    cout << "Enter the details of the course: ";
                    cin >> courseCode;
                    cin >> credit;
                    cin >> semester;
                    cin.ignore();
                    getline(cin, courseName);
                    //Check validity of all details entered by user
                    if (validateAllData(courseCode, courseName, credit, semester))
                    {

                        if (updateCourse(codeList, nameList, creditHours, semList, MAX_COURSES,oldCourseCode, courseCode, courseName, credit, semester))
                        {
                            cout << "Course successfully updated" << endl;
                        }
                        else
                        {
                            cout << "No course found" << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid data" << endl;
                    }
                }
                else
                {
                    //here we will show message of not valid data
                    cout << "Invalid Data" << endl;
                }

                break;

                //This case for deleting the course details

            case 3:
                cout << "Enter Course code" << endl;
                cin >> courseCode;
                //Validate the course Code
                if (isValidCourseCode(courseCode))
                {
                    //call function to delete the course detail which has same course code as user enter
                    if (deleteCourse(codeList, nameList, creditHours, semList, MAX_COURSES, courseCode))
                    {
                        cout << "Course Successfully deleted" << endl;
                    }
                    else
                    {
                        cout << "Sorry No Course found " << endl;
                    }
                }
                else
                {
                    //if course code is invalid then this message will show
                    cout << "Invalid Course code" << endl;
                }

                break;

                //This case for displaying all details of all courses

            case 4:
                //View All details of All courses
                viewCourses(codeList, nameList, creditHours, semList, MAX_COURSES);
                break;

            //This case for displaying course details of specific semester
            case 5:
                cout << "Enter the semester:";
                cin >> semester;
                //Check valildidty of semester entered by user
                if (isValidSemester(semester))
                {
                    //Show All details of course of the semester entered by user
                    viewSemesterCourse(codeList, nameList, creditHours, semList, MAX_COURSES, semester);
                }
                else
                {
                    //If our semester is invalid
                    cout << "Invalid data" << endl;
                }

                break;
                case 6:
                int i;
                string name[i],regno[i];
                cout<<"Enter student name:";
                getline(cin,name[i]);
                cout<<"Enter registration no:";
                cin>>regno[i];
                if(isvalidregistrationNo(regno[i])=true&& isvalidstudentName(name[i])=true){
                    cout<<"Valid RegNo and name\n";
                }
                else{
                    cout<<"Invalid RegNo and name\n";
                }

            // For Closing the Program
            case 7:
                if (saveCourse(codeList, nameList, creditHours, semList, MAX_COURSES))
                {
                    cout << "All courses Data Saved successfully" << endl;
                }
                else
                {
                    cout << "All data you entered is lost due to some error" << endl;
                }
                userName = "";
                password = "";
                login(userName, password);
                break;
            case 7:
                if (saveCourse(codeList, nameList, creditHours, semList, MAX_COURSES))
                {
                    cout << "All courses Data Saved successfully" << endl;
                }
                else
                {
                    cout << "All data you entered is lost due to some error" << endl;
                }
                cout << "Program closed ";
                break;
            default:
                cout << "Invalid choice";
            }
        }
    } while (input != 7);

    return 0;
}
bool isvalidstudentName( string name)
{
    bool flag=true;
    if (name.length()<=30)
    {
        for(int i=0;i<name.length();i++)
        {
            if(!((name[i]>='a'&& name[i]<='z') || (name[i]>='A'&& name[i]<='Z')))
            flag=false;
        }
    }
    else
    {
        flag=true;
        return flag;
    }
    
}
bool isvalidregistrationNo(string regno)

{
    bool text=false;
    if(regno[0]=='2')
    {
        if(regno[1]=='0')
        {
            if(regno[2]>='0'&&regno[2]<='9')
            {
                if(regno[3]>='0'&&regno[3]<='9')
                {
                  if(regno[4]=='-' &&regno[7]=='-')
                  {
                      if(regno[5]=='C'&&regno[6]>='A'&&regno[6]<='Z')
                      {
                          if(regno[8]>='0'&&regno[8]<='9'&&regno[9]>='0'&&regno[9]<=9&&regno[10]>='0'&&regno[10]<='9')
                      }
                  }
                }
            }
        }
        
    }
     text=true;
     else{
         text=false;
     }
    }

void initializeCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size)
{
    for (int s = 0; s < size; s++)
    {
        codeList[s] = " ";
        nameList[s] = " ";
        crtHrsList[s] = 0;
        semList[s] = 0;
    }
}

void initializeUsers(string usernames[], string passwords[], int size)
{
    for (int s = 0; s < size; s++)
    {
        usernames[s] = " ";
        passwords[s] = " ";
    }
}

bool saveCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int size)
{
    // This variable for read data from file
    ofstream myfile;
    /*Open the file if exist if not exist then make new file of this name ios::app maens that the new data will append in file and 
	not remove previous content of file */
    myfile.open("Courses.txt");
    //This function will check if the file open then write data from file
    if (myfile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            if (codeList[i] != "" && nameList[i] != "" && crtHrsList[i] != 0 && semList[i] != 0)
            {
                //These lines will write all array data to the file and make a comma separated file
                myfile << codeList[i] << ",";
                myfile << nameList[i] << ",";
                myfile << crtHrsList[i] << ",";
                myfile << semList[i] << endl;
            }
        }

        myfile.close();
        return true;
    }
    else
    {
        //If there is error while opening file this function will return false
        return false;
    }
}
//Function to load course in arrays
bool loadCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int size)
{
    int i = 0;
    ifstream getCourse("Courses.txt");
    if (!getCourse.is_open())
    {
        //cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string courseCode, courseName;
        string creditHours, semester;
        int credit, sem;
        string line;
        while (!getCourse.eof() && i < size)
        {
            getline(getCourse, line);
            if (line == "")
                continue;
            stringstream ss(line);
            getline(ss, courseCode, ',');
            codeList[i] = courseCode;
            getline(ss, courseName, ',');
            nameList[i] = courseName;
            getline(ss, creditHours, ',');
            credit = stoi(creditHours);
            crtHrsList[i] = credit;
            getline(ss, semester, ',');
            sem = stoi(semester);
            semList[i] = sem;
            i++;
        }

        getCourse.close();
        return true;
    }
}

//Fuunction to read users from file and load then onto the arrays
bool loadUser(string usersList[], string passwordList[], int size)
{
    int i = 0;
    ifstream getUsers("Users.txt");
    if (!getUsers.is_open())
    {
        cout << "File failed to open" << endl;
        return false;
    }
    else
    {
        string username, password;
        string line;
        while (!getUsers.eof() && i < size)
        {
            getline(getUsers, line);
            stringstream ss(line);
            getline(ss, username, ',');
            usersList[i] = username;
            getline(ss, password, ',');
            passwordList[i] = password;
            i++;
        }

        getUsers.close();
        return true;
    }
}

int searchCourseCode(string codeList[], int size, string courseCode)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
      
        if (codeList[i] == courseCode)
        {
            index = i;
            break;
        }
    }
    return index;
}
//This Function Will add the function
bool addCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode, string courseName, int credit, int semester)
{
    bool flag = false;
    int i = searchCourseCode(codeList, size, " ");
    if (i != -1)
    {

        codeList[i] = courseCode;
        nameList[i] = courseName;
        creditHours[i] = credit;
        semList[i] = semester;
        flag = true;
    }
    return flag;
}

// This Function will display all course details
void viewCourses(string codeList[], string nameList[], int creditHours[], int semList[], int size)
{

    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    cout << left;
    cout << setw(10) << "Course"
         << setw(50) << "Course"
         << setw(10) << "Credit"
         << setw(10) << "Semester" << endl;
    cout << setw(10) << "Code"
         << setw(50) << "Name"
         << setw(10) << "Hours"
         << setw(10) << "" << endl;
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (codeList[i] != " ")
        {

            cout << setw(10) << codeList[i]
                 << setw(50) << nameList[i]
                 << setw(10) << creditHours[i]
                 << setw(10) << semList[i] << endl;
        }
    }
    cout << endl;
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
}

//This function will display the course details of the specific semester
void viewSemesterCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, int semester)
{

    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
    cout << left;
    cout << setw(10) << "Course"
         << setw(50) << "Course"
         << setw(10) << "Credit"
         << setw(10) << "Semester" << endl;
    cout << setw(10) << "Code"
         << setw(50) << "Name"
         << setw(10) << "Hours"
         << setw(10) << "" << endl;
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        if (semList[i] == semester && codeList[i] != "")
        {
            cout << setw(10) << codeList[i]
                 << setw(50) << nameList[i]
                 << setw(10) << creditHours[i]
                 << setw(10) << semList[i] << endl;
        }
    }
    cout << endl;
    for (int u = 0; u < 80; u++)
        cout << "-";
    cout << endl;
}

// This function will update the course by using courseCode index which we define as globel varaible
bool updateCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size,string oldCourseCode, string courseCode, string courseName, int credit, int semester)
{

    bool flag = false;
    int updateIndex = searchCourseCode(codeList, size, oldCourseCode);
    cout<<"Upate Index "<<updateIndex<<endl;
    if (updateIndex != -1)
    {
        codeList[updateIndex] = courseCode;
        nameList[updateIndex] = courseName;
        creditHours[updateIndex] = credit;
        semList[updateIndex] = semester;
        flag = true;
    }
    return flag;
}

// This function will delete the course by using courseCode
bool deleteCourse(string codeList[], string nameList[], int creditHours[], int semList[], int size, string courseCode)
{
    bool flag = false;
    int i = searchCourseCode(codeList, size, courseCode);
    if (i != -1)
    {
        codeList[i] = " ";
        nameList[i] = " ";
        creditHours[i] = 0;
        semList[i] = 0;
        flag = true;
    }

    return flag;
}
//checking validity of coursecode
bool isValidCourseCode(string code)
{
    int x = code.length();
    bool flag = true;
    if (x == 5)
    {

        for (int i = 0; i < 2; i++)
        {
            if (!((code[i] >= 'a' && code[i] <= 'z') || (code[i] >= 'A' && code[i] <= 'Z')))
            {
                flag = false;
                break;
            }
        }

        for (int i = 2; i < 5 && flag; i++)
        {
            if (!(code[i] >= '0' && code[i] <= '9'))
            {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

// checking the credit hours
bool isValidCreditHours(int creditHours)
{
    bool flag = true;
    if (!(creditHours >= 1 && creditHours <= 3))
    {
        flag = false;
    }

    return flag;
}

//checking semester
bool isValidSemester(int semester)
{
    bool flag = true;
    if (!(semester >= 1 && semester <= 9))
    {
        flag = false;
    }
    return flag;
}

//checking coursename
bool isValidCourseName(string name)
{
    bool flag = true;
    if (name.length() <= 50)
    {
        for (int i = 0; i < name.length(); i++)
        {
            if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] == ' ')))
                flag = false;
        }
    }
    else
        flag = false;

    return flag;
}

bool validateAllData(string courseCode, string courseName, int credit, int semester)
{
    if (!(isValidCourseCode(courseCode) && isValidCreditHours(credit) && isValidSemester(semester) && isValidCourseName(courseName)))
    {
        return false;
    }
    return true;
}

bool userExist(string user[], string pass[], string users, string passs, int size)
{
    bool flag = false;
    int i;
    for (i = 0; i < size; i++)
    {
        if (user[i] == users && pass[i] == passs)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

void login(string &userName, string &password)
{

    system("cls");
    cout << endl;
    cout << "** Welcome To University Learning Management System ** " << endl;
    cout << "Dear users current software is intended for authorized users only." << endl;
    cout << "Login to the system to get access" << endl;
    cout << "Enter User name: ";
    cin >> userName;
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;
}