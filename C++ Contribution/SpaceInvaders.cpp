#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;
void gotoxy(short x, short y);
int ghostx = 45;
int ghosty = 13; //ghost Axis
int firex = 0;
int firey = 13;  //ghost fire
int ghostx2 = 3; //2nd ghost
int ghosty2 = 2;
int firex_2 = 0;
int firey_2 = 13; //2nd ghost bullet
int planex = 30;  //player
int planey = 28;
int firey2 = 2;
int counter = 0;
int leftLimit = 2; //ghost movement limit
int rightLimit = 60;
int BulletX = 0;
int BulletY = 0; //player bullet
int BulletX_2 = 30;
int BulletY_2 = 28;
int PositionX = 23;
int space = 0; //bullet flag
int bulletCounter = 0;
int PositionY = 9;
string ghostDirection = "Right";
string ghostDirection2 = "Left";
void movePlaneLeft();
void movePlaneRight(); //player movment
void movePlayerUP();
void movePlayerDown();
void moveGhost();
bool gameRunning = true;
void moveGhost2(); //ghost movement
void ShowMap();
void fire();
bool Win = false;
int scoreSet = 0;
void fire2();
void PlayerGun();
void RandomShot();
void Score(int ScoreX, int ScoreY);
void gameRun();
void Bombs();      //random indexes
void Difficulty(); //set scores
char map[32][63] = {
    "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
    "+                                                            +",
    "+                                                            +", //map
    "+            ************************************            +", //74 *
    "+              ###$$#####################$$####              +", //28 #
    "+                ****************************                +", //28 $
    "+                  $$$$$$$$$$$$$$$$$$$$$$$$                  +",
    "+                         **********                         +",
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
    "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ "};
int main(void)
{
  Difficulty();
  system("cls");
  ShowMap();
  //showing plane
  gotoxy(planex, planey);
  cout << "T";
  while (gameRunning == true)
  { //ascii code for escape
    gotoxy(68, 15);
    cout << counter << endl;
    if (GetAsyncKeyState(VK_LEFT))
    { //ascii LEFT arrow
      movePlaneLeft();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    { //ascii right arrow
      movePlaneRight();
    }

    if (GetAsyncKeyState(VK_UP))
    { // up arrow key
      movePlayerUP();
    }
    if (GetAsyncKeyState(VK_DOWN))
    { //down arrow key
      movePlayerDown();
    }

    if (GetAsyncKeyState(VK_SPACE))
    { //down arrow key
      gotoxy(BulletX, BulletY);
      cout << " ";
      BulletX = planex;
      BulletY = planey - 1;
      space++;
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    { // escape from game
      gameRunning = false;
    }

    if (map[BulletY][BulletX] == 'g')
    { //lately used for 2nd bullet
      bulletCounter++;
    }
    if (space != 0)
    { //bullet must move upward till another key is pressed
      PlayerGun();
    }
    gameRun();   //till player catches a bullet
    moveGhost(); //ghost moves
    moveGhost2();
    RandomShot(); //bombs
    Sleep(100);
  }
  if (Win == true)
  { //if checkpoint reaches
    system("CLS");
    gotoxy(9, 10);
    cout << "YOU WON!";
    cout << "----------------------";
    cout << " Your Score is -: " << counter << endl;
    getch();
    gameRunning = true;
  }
  if (gameRunning == false)
  { //if player dies bullet/touches ghost etc..
    system("CLS");
    gotoxy(9, 10);
    cout << "YOU LOST!";
    cout << "----------------------";
    cout << " Your Score is -: " << counter << endl;
    getch();
  }
}
void movePlayerUP()
{ // playerup
  if (map[planey - 1][planex] != '+')
  {
    if (map[planey - 1][planex] == '#' || map[planey - 1][planex] == '$' || map[planey - 1][planex] == '*')
    {
      system("CLS");
      gameRunning = false;
    }
    if (map[planey - 1][planex] == ':' || map[planey - 1][planex] == ';' || map[planey - 1][planex] == 'g')
    {
      gameRunning = false;
    }
    gotoxy(planex, planey);
    cout << " ";
    // this condition stop player to cross the boundaries.
    planey = planey - 1;
    gotoxy(planex, planey);
    cout << "T";
  }
}
void movePlayerDown()
{ //Player Down
  if (map[planey + 1][planex] != '+')
  {
    if (map[planey + 1][planex] == '#' || map[planey + 1][planex] == '$' || map[planey + 1][planex] == '*')
    { // death boundries
      system("CLS");
      gameRunning = false;
    }
    gotoxy(planex, planey);
    cout << " ";
    planey = planey + 1;
    gotoxy(planex, planey);
    cout << "T";
  }
}

void movePlaneRight()
{ //player Right
  if (map[planey][planex + 1] != '+')
  {
    if (map[planey][planex + 1] == '#' || map[planey][planex + 1] == '$' || map[planey][planex + 1] == '*')
    { //boundries (death)
      system("CLS");
      gameRunning = false;
    }
    gotoxy(planex, planey);
    cout << " ";
    planex = planex + 1;
    gotoxy(planex, planey);
    cout << "T";
  }
}
void movePlaneLeft()
{ //player left
  if (map[planey][planex - 1] != '+')
  {
    if (map[planey][planex - 1] == '#' || map[planey][planex - 1] == '$' || map[planey][planex - 1] == '*')
    { //death condition
      system("CLS");
      gameRunning = false;
    }
    gotoxy(planex, planey);
    cout << " ";
    planex = planex - 1;
    gotoxy(planex, planey);
    cout << "T";
  }
}

void moveGhost()
{ //Ghost 1 moves from left to right

  gotoxy(ghostx, ghosty);
  cout << " ";
  if (ghostDirection == "Right")
  {
    ghostx = ghostx + 1;
  }
  if (ghostDirection == "Left")
  {
    ghostx = ghostx - 1;
  }

  if (ghostx >= rightLimit)
  {
    ghostDirection = "Left";
  }
  if (ghostx <= leftLimit)
  {
    ghostDirection = "Right";
  }
  gotoxy(ghostx, ghosty);
  cout << "g";

  fire();
}
void moveGhost2()
{ //2nd ghost movement

  gotoxy(ghostx2, ghosty2);
  cout << " ";
  if (ghostDirection2 == "Right")
  {
    ghostx2 = ghostx2 + 1;
  }
  if (ghostDirection2 == "Left")
  {
    ghostx2 = ghostx2 - 1;
  }

  if (ghostx2 >= 58)
  {
    ghostDirection2 = "Left";
  }
  if (ghostx2 <= 2)
  {
    ghostDirection2 = "Right";
  }
  gotoxy(ghostx2, ghosty2);
  cout << "g";
  fire2();
}
void gotoxy(short x, short y) //movement
{
  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD position = {x, y};
  SetConsoleCursorPosition(hStdout, position);
}
void ShowMap() //to Show Grid
{
  for (int i = 0; i < 32; i++)
  {
    for (int j = 0; j < 63; j++)
    {
      cout << map[i][j];
    }
    cout << endl;
  }
}
void fire()
{ //ghost fire
  gotoxy(firex, firey);
  cout << " " << endl;
  gotoxy(firex, firey + 1);
  cout << " " << endl;
  if (ghostx == planex)
  {
    firex = ghostx;
    firey = ghosty;
  }
  //boundries
  if (map[firey + 1][firex] != '+' && map[firey + 1][firex] != '*' && map[firey + 1][firex] != '|' && map[firey + 1][firex] != '$' && map[firey + 1][firex] != '#')
  {
    gotoxy(ghostx, firey);
    cout << " ";
    gotoxy(ghostx, firey + 1);
    cout << " ";
    if (firey != 29)
    {
      gotoxy(firex, firey);
      cout << " ";
      firey++;
      gotoxy(firex, firey);
      cout << ",";
      gotoxy(firex, firey + 1);
      cout << ",";
    }
    else
    {
      gotoxy(firex, firey);
      cout << " " << endl;
      gotoxy(firex, firey + 1);
      cout << " " << endl;
      firex = 0;
      firey = 13;
    }
  }
}
void fire2()
{ //2nd ghost fire
  gotoxy(firex_2, firey_2);
  cout << " " << endl;
  gotoxy(firex_2, firey_2 + 1);
  cout << " " << endl;
  if (ghostx2 == planex)
  {
    firex_2 = ghostx2;
    firey_2 = ghosty2;
  }
  //boundries
  if (map[firey_2 + 1][firex_2] != '+' && map[firey_2 + 1][firex_2] != '*' && map[firey_2 + 1][firex_2] != '|' && map[firey_2 + 1][firex_2] != '$' && map[firey_2 + 1][firex_2] != '#')
  {
    gotoxy(ghostx2, firey_2);
    cout << " ";
    gotoxy(ghostx2, firey_2 + 1);
    cout << " ";
    if (firey_2 != 29)
    {
      gotoxy(firex_2, firey_2);
      cout << " ";
      firey_2++;
      gotoxy(firex_2, firey_2);
      cout << ",";
      gotoxy(firex_2, firey_2 + 1);
      cout << ",";
    }
    else
    {
      gotoxy(firex_2, firey_2);
      cout << " " << endl;
      gotoxy(firex_2, firey_2 + 1);
      cout << " " << endl;
      firex_2 = 0;
      firey_2 = 13;
    }
  }
}
void RandomShot()
{
  //bombs down
  gotoxy(PositionX, PositionY);
  cout << " ";
  if (map[PositionY + 1][PositionX] != '+')
  {
    if (PositionY != 29)
    {
      gotoxy(PositionX, PositionY);
      cout << " ";
      PositionY++;
      gotoxy(PositionX, PositionY);
      cout << ":";
    }
    else
    {
      gotoxy(PositionX, PositionY);
      cout << " " << endl;
      Bombs();
    }
  }
}
void Bombs()
{
  //random numbers generator to fall bombs
  int Index = (rand() % 52) + 4;
  PositionY = 9;
  PositionX = Index;
}
void PlayerGun()
{ //players gun
  if (map[BulletY - 1][BulletX] != '+' && map[BulletY - 1][BulletX] != ':' && map[BulletY - 1][BulletX] != ',')
  {
    gotoxy(BulletX, BulletY);
    cout << " ";
    BulletY--;
    gotoxy(BulletX, BulletY);
    cout << "^";
    Score(BulletX, BulletY);
  }
  else
  {
    gotoxy(BulletX, BulletY);
    cout << " " << endl;
    space = 0;
  }
}
void Score(int ScoreX, int ScoreY)
{ //Score Counter
  if (map[ScoreY][ScoreX] == '*')
  {
    map[ScoreY][ScoreX] = ' ';
    counter++;
    gotoxy(ScoreX, ScoreY);
    cout << " " << endl;
    //space=0;
  }
  else if (map[ScoreY][ScoreX] == '#')
  {
    map[ScoreY][ScoreX] = ' ';
    counter = counter + 2;
    gotoxy(ScoreX, ScoreY);
    cout << " " << endl;
    //space=0;
  }
  else if (map[ScoreY][ScoreX] == '$')
  {
    map[ScoreY][ScoreX] = ' ';
    counter = counter + 5;
    gotoxy(ScoreX, ScoreY);
    cout << " " << endl;
    //space=0;
  }
  else if (map[ScoreY - 1][ScoreX] == 'g')
  {
    map[ScoreY][ScoreX] = ' ';
    counter = counter + 10;
    gotoxy(ScoreX, ScoreY);
    cout << " " << endl;
    //space=0;
  }
}
void gameRun()
{ //conditions to stop game Running
  if ((planex == PositionX && planey == PositionY) || (planex == firex_2 && planey == firey_2) || (planex == firex && planey == firey))
  {
    gameRunning = false;
  }
  if (planex == ghostx && planey == ghosty || planex == ghostx2 && planey == ghosty2)
  {
    gameRunning = false;
  }
  if (counter == scoreSet)
  {
    gameRunning = false;
    Win = true;
  }
}
void Difficulty()
{ //Set Difficulty
  system("CLS");
  cout << "***********************************************" << endl;
  cout << "      SPACE " << endl;
  cout << "                     INVADERS" << endl;
  cout << "===============================================" << endl;
  int Choose;
  cout << "                   -- Set Difficulty --   " << endl;
  cout << " 1- Easy (target -> 100) " << endl;
  cout << " 2- Normal (target -> 150) " << endl;
  cout << " 3- Hard (target -> 200) " << endl;
  cout << " Selected ->";
  cin >> Choose;
  if (Choose == 1)
  {
    scoreSet = 100;
  }
  if (Choose == 2)
  {
    scoreSet = 150;
  }
  if (Choose == 3)
  {
    scoreSet = 200;
  }
}