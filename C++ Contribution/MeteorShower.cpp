#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;
int planex=34;
int planey=28;  //position
int counter=0;
int meteorx=1;
int meteory=3;
int meteorx2=45;
int meteory2=3;
//functions
void ShowMap();
void movePlaneLeft();
void movePlaneRight();
void movePlaneUP();
void movePlaneDown();
void fire();
void fire2();
void gotoxy( short x, short y );
char map[32][63] = {
	"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
	"+                                                            +", //grid
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
	"+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "+                                                            +",
  "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	};
int main(void){
system("cls");
  ShowMap();
  bool gameRunning=true;
  //showing plane
  gotoxy(planex,planey);
  cout<<"P";
  while(gameRunning){//ascii codee for escape
    if(GetAsyncKeyState( VK_LEFT )){ //ascii LEFT arrow
       movePlaneLeft();
    }
    if(GetAsyncKeyState( VK_RIGHT )){ //ascii right arrow
       movePlaneRight();
    }

    if(GetAsyncKeyState( VK_UP )){ // up arrow key
       movePlaneUP();
    }
    if(GetAsyncKeyState( VK_DOWN)){ //down arrow key
       movePlaneDown();
    }
      if(GetAsyncKeyState( VK_ESCAPE) ){
        gameRunning=false;
      }
        fire();
        fire2();
        Sleep(100);
  }
}
void ShowMap()//to Show Grid
{
	for(int i = 0; i < 32; i++){
         for(int j = 0; j< 63; j++){
            cout << map[i][j];
          }
	cout<<endl;
	}
}
void movePlaneUP(){
   if (map[planey-1][planex]!='+'){
  gotoxy(planex,planey);
  cout<<" ";
   // this condition stop pacman to cross the boundaries.
    planey=planey-1;
  gotoxy(planex,planey);
  cout<<"P";
   }
}
void movePlaneDown(){
  if (map[planey+1][planex]!='+'){
  gotoxy(planex,planey);
  cout<<" ";
  planey=planey+1;
  gotoxy(planex,planey);
  cout<<"P";
  }
}

void movePlaneRight(){
   if (map[planey][planex+1] !='+'){
  gotoxy(planex,planey);
  cout<<" ";
  planex=planex+1;
  gotoxy(planex,planey);
  cout<<"P";
  }

}
void movePlaneLeft(){
  if(map[planey][planex-1]!='+'){
    if(map[planey][planex-1]=='#'){
    system("CLS");
    cout<< " YOU LOST "<<endl; 
    }
  gotoxy(planex,planey);
  cout<<" ";
  planex=planex-1;
  gotoxy(planex,planey);
  cout<<"P";
  }

}
void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}
void fire(){
    if(map[meteory+1][meteorx+4]=='+'){
         gotoxy(meteorx,meteory);
          cout<<"    ";
          meteorx=1;
          meteory=1;
  }
  else{
    gotoxy(meteorx,meteory);
    cout<<"(__)";
    gotoxy(meteorx,meteory);
    cout<<"    ";
    meteorx++;
    meteory++;    
    gotoxy(meteorx,meteory);
    cout<<"(__)";
      if(meteory==30){
          gotoxy(meteorx,meteory);
          cout<<"    ";
          meteory=1;
          counter++;
     } 
  } 
}
void fire2(){
  if(map[meteory2+1][meteorx2+4]=='+'){
         gotoxy(meteorx2,meteory2);
          cout<<"    ";
          meteorx2=45;
          meteory2=3;
  }
  else{
    gotoxy(meteorx2,meteory2);
    cout<<"(__)";
    gotoxy(meteorx2,meteory2);
    cout<<"    ";
    meteorx2++;
    meteory2++;    
    gotoxy(meteorx2,meteory2);
    cout<<"(__)";
      if(meteory2==30){
          gotoxy(meteorx2,meteory2);
          cout<<"    ";
          meteory2=1;
          counter++;
     } 
  } 
}