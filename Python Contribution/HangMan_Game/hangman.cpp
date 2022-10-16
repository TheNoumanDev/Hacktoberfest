#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<ctime>
#include <stdio.h>
#include <windows.h>
using namespace std;

void printHangMan ();
void printHeader();
void wordFile ();
string getDisplayWord (string store);
string name (string store);
void takeInput ();
bool checkGess (char z);
void replacer (char z);
void update ( int idx);
bool isWordFound (char z);
void addCharInArray (char z); 
void gotoxy( short x, short y );
void condition1 ();
void condition2 ();
void condition3 ();
void condition4 ();
void condition5 ();

fstream fileWords;
int idx =0 , counter =0 ,wrongCount = 0;
string Words[100];
string hangMan[17] ;
char chances[7];
string gess;
string gessWord;
string temp;

int main () 
{
 int num;


  wordFile ();
 srand((unsigned)time(0));
 num = rand()%idx;
 gessWord = Words[num];
 temp = getDisplayWord (gessWord);
  cout<<temp<<endl;
  while (true)
  {  system ("cls");
      printHeader();
      cout<<" Gess the words which is ----->    ";
      cout<<temp<<endl;
       cout<<" You have guessed the Alphabets ... > ";
      for(int idx =0 ; idx < counter;idx++){
       cout<<chances[idx]<<" ,";
      }
       cout<<endl;
      gotoxy(0,15);
      printHangMan ();
     
      gotoxy(0,33);
      takeInput ();
      if(wrongCount==1){
        condition1 ();
      }
      if(wrongCount==2){
        condition2 ();
      }
      if(wrongCount==3){
        condition3 ();
      }
      if(wrongCount==4){
        condition4 ();
      }
      if(wrongCount==5){
        condition5 ();
      }
      gotoxy(0,15);
      printHangMan ();
      
     if(temp==gessWord){
        cout<<endl;
        cout<<"**********************************************************************************************"<<endl;
        cout<<"***                                     YOU WIN                                            ***"<<endl;
         cout<<"*********************************************************************************************"<<endl;
         cout<<"The world was "<<gessWord<<endl;
         return 0;
      }
     if(wrongCount==5){
        cout<<"**********************************************************************************************"<<endl; 
        cout<<"***                                     YOU Lose                                          ***"<<endl;
        cout<<"*********************************************************************************************"<<endl;
        cout<<"The world was "<<gessWord<<endl;
        return 0;
     }
     getch ();
      


    }

}
void condition5 () {
  hangMan[7]="                    |          |    ";
  hangMan[8]="                    |         / \\ ";
}
void condition4 (){
  hangMan[4]="                    |          |     ";
  hangMan[5]="                    |          @     ";
  hangMan[6]="                    |         /|\\    ";
}

void condition3 ()  {
  hangMan[3]="                    +----------+   ";
}

void condition2 () {
 hangMan[4]="                    |        ";
 hangMan[5]="                    |        ";
 hangMan[6]="                    |        ";
 hangMan[7]="                    |        ";
 hangMan[8]="                    |        ";
}

void condition1 () {
 hangMan[9] ="                ____|__________________";
 hangMan[10]="               /    |                 /|";
 hangMan[11]="              /                      / |";
 hangMan[12]="             /_____________________ /  /";
 hangMan[13]="             |                     |  /";
 hangMan[14]="             |                     | /";
 hangMan[15]="             |_____________________|/ ";
}

void printHangMan (){
  for(int idx =0 ;idx<17 ;idx++){
    cout<<hangMan[idx]<<endl;
  }
}

void takeInput (){
    char z;
  cout<<"Gess an Alphabet in small Letter .... > ";
  cin>>z;
  if(checkGess(z)){
     replacer (z);
     addCharInArray ( z);
     cout<<"Your gess is right "<<endl;
    }
  else{
    addCharInArray (z);
    cout<<"TRY AGAIN  "<<endl;
   }
}
bool isWordFound (char z) {
 for(int idx =0 ;idx<counter ;idx++){
   if(chances[idx]==z){
     return true;
   }
   
  }
  return false;
}

void addCharInArray (char z){
  if(isWordFound (z)==false){
    chances[counter]=z;
   counter++;
   if(checkGess (z)==false){
     wrongCount++;
   }
  }
  else{
    cout<<"The alphabets"<<z<<" is already tried "<<endl;
  }
}

void replacer (char z){
 for(int idx =0 ; idx< gessWord.length() ;idx++)
 {
    if(gessWord[idx]==z){
       update(idx);
    }
 }
}

void update ( int idx){
    temp[idx]=gessWord[idx];
}

bool checkGess (char z) {
   
   for(int idx =0 ; idx< gessWord.length() ;idx++)
    {
        if( gessWord[idx]==z){
    
          return true;
        }
    }
    return false;
}

void wordFile ()
{
    string store;   
    fileWords.open("words.txt",ios::in);
    while(getline(fileWords,store)){
     Words[idx]=name( store);
     idx++;
    }
    fileWords.close();
}
string name (string store){
  int idx =0 ,count =0 ;
  string name="";
 while(count<1){
   char c = store[idx];
   if(c==' '){
     count++;
     }
   else{
     name=name+c;
    }
    idx++;
 }
 return name;
}

string getDisplayWord (string gessWord) {
  int times = 0;
  char c = 0;
  int length = gessWord.length ();
  char displayWord[length];
  float midValue =length/2;
  int middleValue = midValue;

   while(times!=length){
        c=gessWord[times];
      if(times == 0 || times == length-1 || times == middleValue){
         displayWord[times]=c;
      }
      else {
          displayWord[times]='-';
      }
       times++;
    }
    return displayWord;
} 

void printHeader() {
  cout<<"**********************************************************************************************"<<endl;
  cout<<"***                                     WELCOME                                            ***"<<endl;
  cout<<"**********************************************************************************************"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"\t"<< "<>    <>     <><>     <>    <>   <>>>>>>    <>      <>    <><>    <>    <>"<<endl;
  cout<<"\t"<< "<>    <>    <>   <>   <>>>  <>  <>     <>   <>>>  <<<>   <>  <>   <>>>  <>"<<endl;
  cout<<"\t"<< "<><<>><>   <><<<>><>  <> <> <>  <>          <> <<>> <>  <><<>><>  <> <> <>"<<endl;
  cout<<"\t"<< "<>    <>   <>     <>  <>  <<<>  <>   <<<<   <>  <>  <>  <>    <>  <>  <<<>"<<endl;
  cout<<"\t"<< "<>    <>   <>     <>  <>    <>    <>>>>>    <>      <>  <>    <>  <>    <>"<<endl;
  cout<<endl;
  cout<<endl;
}
void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}


    