#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int score = 0;
    char input;
    cout << "              Welcome To Quiz Game           " << endl;
    cout << "________________________________________________" << endl;
    cout << endl;
    string name;
    cout << "Enter Your Name :";
    cin >> name;
    system("CLS");
    cout << "*******************************************************" << endl;
    cout << "                    Menu Of The Game    " << endl;
    cout << "*******************************************************" << endl;
    do
    {
        cout << endl;
        cout << "Press S To Start The Game" << endl;
        cout << "Press V To View The Score" << endl;
        cout << "Press R To Reset The Game" << endl;
        cout << "Press H For Help" << endl;
        cout << "Press Q To Quit The Game" << endl;
        cout << "Enter Your Choice :";
        cin >> input;
        system("CLS");
         if(input=='s'||input=='S')
         {
		 
            cout << name << ",Select an option from the following Categories :" << endl;
            cout << endl;
            cout << "1. Sports                       2.Movies     " << endl;
            cout << "3. Pakistan Affairs             4.International Affairs  " << endl;
            cout << endl;
            cout << "Select one of them :";
            cin >> input;
            system("CLS");
            if (input == '1')
            {
                cout << "Q1. Who is the Chairman PCB?" << endl;
                cout << endl;
                cout << "1.Najam Sethi               2.Ehsan Mani   " << endl;
                cout << "3.Misbah ul Haq             4.Saqlain Mushtaq" << endl;
                cout << endl;
                cout << "Your Answer :" << endl;
                cin >> input;
                if (input =='2')
                {
                    cout << "Congrats,Your Answer is correct.....";
                    score=score+100;
                    cout<<"Score is :"<<score;
                }
                else
                {
                    cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 2.Ehsan Mani........" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
                }
                getch();
                system("CLS");
		  cout<<"Q2. Winner of PSL 1 was? "<<endl;
              cout<<endl;
              cout<<"1.Karachi Kings                 2.Lahore Qalandars"<<endl;
              cout<<"3.Islamabad United           4.Peshawar Zalmi  "<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 3.Islamabad United........" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch(); 
			  system("CLS");
		  cout<<"Q3.When was 1st PSL played?"<<endl;
              cout<<endl;
              cout<<"1.2016                 2.2013"<<endl;
              cout<<"3.2015                4.2014"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 1.2016........" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch(); 
			   system("CLS");
		  cout<<"Q4.Which is the national sports of Pakistan: "<<endl;
              cout<<endl;
              cout<<"1.Cricket                 2.Tenis"<<endl;
              cout<<"3.Baseball                4.Hockey"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='4')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 4.Hockey" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
		  cout<<"Q5.Who was Captain in 2007 when Pakistan won T20 Worldcup?"<<endl;
              cout<<endl;
              cout<<"1.Shahid Afridi                2.Younas Khan"<<endl;
              cout<<"3.Misbah ul Haq                4.Muhammad Hafeez"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='2')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 2.Younas Khan" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  
			  getch();  
		}
            }
			if(input=='2')
		   {
		   	 cout<<"Q1.Which was the last movie of Irfaan Khan?"<<endl;
              cout<<endl;
              cout<<"1.Salam Bombay                2.Angrezi Medium"<<endl;
              cout<<"3.Karwaan                     4.Life of Pie"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 3.Karwaan" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
		  cout<<"Q2.What was the budget of Hollywood movie Godzilla 1?"<<endl;
              cout<<endl;
              cout<<"1.115 Million USD                2.140 Billion USD"<<endl;
              cout<<"3.140 Million USD                4.160 Million USD"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='4')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 4.160 Million USD" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
		  cout<<"Q3.All is Well song is of which movie?"<<endl;
              cout<<endl;
              cout<<"1.Taary Zameen Par                 2. 3 Idiots"<<endl;
              cout<<"3.Taalash                          4. PK"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='2')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 2. 3 Idiots" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
		  cout<<"Q4. Tery Naam movie was released in which year?"<<endl;
              cout<<endl;
              cout<<"1.2002                 2.2004"<<endl;
              cout<<"3.2003                3.2005"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 3.2003" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
		  cout<<"Q5.Who was lead cast in movie<<Hum Apke Hain Kon<<?"<<endl;
              cout<<endl;
              cout<<"1.Shahrukh khan                 2.Aamir Khan"<<endl;
              cout<<"3.Irfaan Khan                4.Salman Khan"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='4')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 4.Salman Khan" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
                     getch(); 
			  } 
			           
			 
		} 
			 if(input=='3')
			 {
			 	 cout<<"Q1.Who is the defence minister of Pakistan?"<<endl;
              cout<<endl;
              cout<<"1.Pervaiz Khatak                 2.Shah Mehmood Qureshi"<<endl;
              cout<<"3.Murad Saeed                    4.Asad Umar"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='1')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 1.Pervaiz Khatak" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			  system("CLS");
			   cout<<"Q2.Who is Governor of State Bank of Pakistan?"<<endl;
              cout<<endl;
              cout<<"1.Ashraf Wathra                 2.Yaseen Anwar"<<endl;
              cout<<"3.Raza Baqir                    4.Tariq Bajwa"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 3.Raza Baqir" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			  system("CLS");
			   cout<<"Q3.Who is the Governor of Sindh?"<<endl;
              cout<<endl;
              cout<<"1.Shah Farman                2.Imran Ismail"<<endl;
              cout<<"3.Jam Kamal                  4.Sanaullah Zahri"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='2')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 2.Imran Ismail" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			  system("CLS");
			   cout<<"Q4.Who is the Communication Affairs Minister?"<<endl;
              cout<<endl;
              cout<<"1.Asad Umar                 2.Fawad Chaudhary"<<endl;
              cout<<"3.Murad Saeed               4.Farogh Naseem"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is3.Murad Saeed" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch(); 
			  system("CLS");
			   cout<<"Q5.Who is the Chief Justice of Pakistan?"<<endl;
              cout<<endl;
              cout<<"1.Gulzar Ahmad                 2.Qazi Faiz Isa"<<endl;
              cout<<"3.Azmat Saeed                  4.Mushir Alam"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='1')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 1.Gulzar Ahmad" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
                     getch();
			  }
			                                                            
			   }
			  if(input=='4')
			   {
			   	cout<<"Q1.Who is elected as President Of America? "<<endl;
              cout<<endl;
              cout<<"1.Burak Obama                 2.Joe Biden"<<endl;
              cout<<"3.Donald Trump                4.George Bush"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='2')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 2.Joe Biden" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
			   cout<<"Q2.Acronym of<<CPEC<< is?"<<endl;
              cout<<endl;
              cout<<"1.China-Pakistan Economic Corridor                 2.China-Pakistan Elected Candidates"<<endl;
              cout<<"3.China-Pakistan Estimated Coordination            4.None of These"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='1')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 1.China-Pakistan Economic Corridor" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
			   cout<<"Q3.Who accepted Pakistan first? "<<endl;
              cout<<endl;
              cout<<"1.China                 2.Iraq"<<endl;
              cout<<"3.Iran                  4.Turkey"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 3.Iran" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();
			   system("CLS");
			   cout<<"Q4.Who is the President of Turkey?"<<endl;
              cout<<endl;
              cout<<"1.Turgut Ozal                         2.Abdullah Gul"<<endl;
              cout<<"3.Racep Tayyip Erdogan                4.Cevdet Sunay"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='3')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 3.Racep Tayyip Erdogan" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  } 
			  getch();
			   system("CLS");
			   cout<<"Q5.Who Is the Prime Minister of Lebanon?"<<endl;
              cout<<endl;
              cout<<"1.Saad Hariri                  2.Hassan Diab"<<endl;
              cout<<"3.Rashid Karami                4.Najib Mikati"<<endl;
              cout<<endl;
              cout<<"Your Answer :"<<endl;
              cin>>input;
              
              if(input=='2')
			  {
              	cout<<"Congrats,Your answer is correct.....";
              	score=score+100;
              	cout<<"Score is:"<<score;
			  }
			  else
			  {
			  	 cout << "Alas, Your answer was not correct......." << endl;
                    cout << "Correct answer is 2.Hassan Diab" << endl;
                    score=score-50;
                    cout<<"Score is:"<<score<<endl;
                    cout<<"Press any key to continue....."<<endl;
			  }
			  getch();                                      
			   }
	}
	if(input=='h'||input=='H'){
		system("CLS");
		cout<<"Here are some of the Rules and Regulations of the Game."<<endl;
		cout<<endl;
		cout<<"Firstly,there will be no hooting and shouting while playing the game."<<endl;
		cout<<"There are 4 categories in the Game."<<endl;
		cout<<"You can choose any of them."<<endl;
		cout<<"Each category consists of 5 Questions."<<endl;
		cout<<"Each Question carries 100 marks."<<endl;
		cout<<"Correct answer will give you +100 marks whereas Wrong answer will give you -50 marks."<<endl;
		cout<<"Press any key to continue......"<<endl;
	}
	getch();
	if(input=='v'||input=='V'){
		cout<<"You Scored: "<<score<<endl;
		cout<<"Press any key to continue......"<<endl;	
	}
	getch();
}
	while (input != 'Q'||input !='q');
    cout << "Game End...." << endl;
    return 0;
}
