//Maheera Ashfaq
//i211158
//PF-D
//Final Project Cricket simulator

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void drawScoreCard(string batsman, string bowler, int runs, int total_score, int inning_score, int overss);


void startmenu()
{
    cout << "---------------------------------------" << endl;
    cout << "|========== CRICKET SIMULATOR=========|" << endl;
    cout << "---------------------------------------\n\n" << endl;

}



void Tossandchoose(char** TeamPAK, char** TeamIND, char** Bat_team, char** Bowl_team)
{


        int tossinput;

        cout << "\n*********************************\n";
        cout << "*        LET'S DO THE TOSS!       *\n";
        cout << "***********************************\n";
        cout<<"PRESS ENTER PLEASE...\n";
        cin.get();
        cout << "Wait for the Toss results...\n\n";

        srand(time(NULL));
        int randomVal = rand() % 2;   // 0 or 1 are tossvalues

    if (randomVal==0)  //if Team PAK won toss
        {

                        cout << "Team PAKISTAN won the toss" << endl << endl;
                        cout << "Enter 1 to bat or 2 to bowl first. " << endl<<"1. Bat\n2. Bowl\n";

                       cin>>tossinput;

                 if (tossinput==1) //if they choose to bat
                    {
                          cout <<"\nTeam PAKISTAN won the toss and elected to bat first\n\n" ;

                                for(int i=0; i<11; i++)
                                {
                                    for (int k=0;k<=25;k++)
                                    {
                                        Bat_team[i][k] = TeamPAK[i][k]; //assign batting team to pak
                                        Bowl_team[i][k] = TeamIND[i][k]; //assign bowling team to india
                                    }
                                }
                    }
                else if (tossinput==2) //if they choose to bowl
                {
                         cout <<"\nTeam PAKISTAN won the toss and elected to bowl first\n\n";

                                 for(int i=0; i<11; i++)
                                {
                                    for (int k=0;k<=25;k++)
                                    {
                                        Bat_team[i][k] = TeamIND[i][k]; //assign batting team to india
                                        Bowl_team[i][k] = TeamPAK[i][k]; //assign bowling team to pak
                                    }
                                }
                }


        }
    else if(randomVal==1)    // if Team IND is the toss winner
        {
                        cout << "Team INDIA won the toss" << endl << endl;
                        cout << "Enter 1 to bat or 2 to bowl first. " << endl<<"1. Bat\n2. Bowl\n";

                        cin>>tossinput;

                 if (tossinput==1) //if they choose to bat
                    {
                                 cout <<"\nTeam INDIA won the toss and elected to bat first\n\n" ;

                                 for(int i=0; i<11; i++)
                                {
                                    for (int k=0;k<=25;k++)
                                    {
                                        Bat_team[i][k] = TeamIND[i][k]; //assign batting team to india
                                        Bowl_team[i][k] = TeamPAK[i][k]; //assign bowling team to pak
                                    }
                                }
                        }
                else if (tossinput==2)    //if they choose to bowl
                {
                              cout <<"\nTeam INDIA won the toss and elected to bowl first\n\n" ;
                                 for(int i=0; i<11; i++)
                                {
                                    for (int k=0;k<=25;k++)
                                    {
                                        Bat_team[i][k] = TeamPAK[i][k]; //assign batting team to pak
                                        Bowl_team[i][k] = TeamIND[i][k]; //assign bowling team to india
                                    }
                                }
                }
        }
}
void bat(string batsman,string bowler, int runs,  int total_score ,int overss,int inning_score)
{
    int eachover= overss/5;     //max overs bowled by baller
    static int eachbowler=eachover;  //max bowls by a bowler
    static int wickets=0;
    static int total_scoree=total_score;

     srand(time(NULL));
     int probabilty=probabilty%10;     //we generate probabilty randomly

    for (int i=0; i<=eachbowler; i++ )
    {
    while(runs!=-1){
            if(probabilty==1 || probabilty==2 || probabilty==3)
            {
                runs=-1;
                break;
            }
            else
            srand(time(NULL));
	    	runs = (rand()%7) - 1;   //calculates runs between -1 and 6
	    	if(runs!=-1)
            {
		    total_scoree += runs;
            }
            if(runs==-1)
            {
                wickets++;
            }
		    drawScoreCard(batsman,bowler,runs,total_scoree,inning_score,overss); //calls score board to draw result
            cin.get();
            inning_score+=total_scoree;
	   }
	   if(wickets==10)
	   {
	       break;
	   }

    }

	        cout<<"The Total runs were: "<<inning_score<<endl;
	        cout<<"The Wickets Fallen are: "<<wickets<<endl;


}
void bat2(string batsman,string bowler, int runs,  int total_score ,int overss,int inning_score)
{
    int eachover= overss/5;     //max overs bowled by baller
    static int eachbowler=eachover;  //max bowls by a bowler
    static int wickets=0;
    static int total_scoree=total_score;

     srand(time(NULL));
     int probabilty=probabilty%10;     //we generate probabilty randomly

    for (int i=0; i<=eachbowler; i++ )
    {
    while(runs!=-1){
            if(probabilty==1 || probabilty==2 || probabilty==3)
            {
                runs=-1;
                break;
            }
            else
            srand(time(NULL));
	    	runs = (rand()%7) - 1;   //calculates runs between -1 and 6
	    	if(runs!=-1)
            {
		    total_scoree += runs;
            }
            if(runs==-1)
            {
                wickets++;
            }
		    drawScoreCard(batsman,bowler,runs,total_scoree,inning_score,overss); //calls score board to draw result
            cin.get();
            inning_score+=total_scoree;
	   }
	   if(wickets==10)
	   {
	       break;
	   }

    }

	        cout<<"The Total runs were: "<<inning_score<<endl;
	        cout<<"The Wickets Fallen are: "<<wickets<<endl;


}


void first_innings(char** Bat_team, char** Bowl_team,int runs, int total_score,int overss,int first_inning_score)
{

        string batsman;
        string bowler;
        int eachover= overss/5;     //max overs bowled by baller
        int eachbowler=eachover;  //max bowls by a bowler
        static int total_balls=overss*6;
        int overcounter=0;
        int i=0;

        for(int j=0; j<total_balls; j++)
            {

                    batsman = Bat_team[i];
                    for (int j=0; j<=eachbowler; j++ ){
                    bowler = Bowl_team[i];}
                    bat(batsman,bowler,runs,total_score,overss,first_inning_score);
                    overcounter++;
                    if(overcounter>overss)
                    {
                        break;
                    }
                    else
                    cout<<"\n\nOVER "<<overcounter<<"/"<<overss<<endl;
            }
}
void second_innings(char** Bat_team, char** Bowl_team,int runs, int total_score,int overss,int second_inning_score)
{

        //in this we replace both the teams

        string batsman;
        string bowler;
        int eachover= overss/5;     //max overs bowled by baller
        int eachbowler=eachover;  //max bowls by a bowler
        static int total_balls=overss*6;
        int overcounter=0;

        int i=0;

        for(int j=0; j<total_balls; j++)
            {

                    batsman = Bowl_team[i];
                    for (int j=0; j<=eachbowler; j++ ){
                    bowler = Bat_team[i];}
                    bat2(batsman,bowler,runs,total_score,overss,second_inning_score);
                    overcounter++;
                    if(overcounter>overss)
                    {
                        break;
                    }
                    else
                    cout<<"\n\nOVER "<<overcounter<<"/"<<overss<<endl;

            }

}


void drawScoreCard(string batsman, string bowler, int score, int total_score, int inning_score, int overss)
{
    cout<<"-----------------------------------------------------------------------------\n";
    cout<<"PLAYER\t\tBOWLER\t\tRUNS\t\tTOTAL RUNS\t\tRUN RATE\n\n";
	cout<<batsman<<" is batting\t";
	cout<<bowler<<" is bowling\t";
	score==-1 ? cout<<"out" : cout<<score;
	cout<<"\t\t\t"<<total_score<<"\t\t\t";
	int runrate=total_score/overss;
	cout<<runrate;
	cout<<endl;
	cout<<"-----------------------------------------------------------------------------\n";
}
void win_team()
{
    if (first_innings>second_innings)
    {
        cout<<"TEAM THAT PLAYED THE FIRST INNINGS WON!"<<endl;
    }
    else
    {
        cout<<"TEAM THAT PLAYED THE SECOND INNINGS WON!"<<endl;
    }
}

int main()
{

      startmenu();   //we call the start menu
   //to continue we use getchar so when user presses enter key we move forward
     cout << "\nPress Enter to continue";
     getchar();
 //declare and initialize dynamic arrays
  char **TeamPAK=new char*[11];
   for(int i=0; i<11; i++)
   {
       TeamPAK[i]=new char[25];
   }
 char **TeamIND=new char*[11];
   for(int i=0; i<11; i++)
   {
       TeamIND[i]=new char[25];
   }
 char **Bat_team=new char*[11];
   for(int i=0; i<11; i++)
   {
       Bat_team[i]=new char[25];
   }
 char **Bowl_team=new char*[11];
   for(int i=0; i<11; i++)
   {
       Bowl_team[i]=new char[25];
   }
 int runs=0;
 int total_score=0;
 int first_inning_score=0,second_inning_score=0;



 ofstream myfile;   //we open file
 myfile.open("file.txt", ios::out | ios::app);  //we use append so it does not overwrite

    for (int i=0; i<11; i++)
    {
        cout<<"Enter TEAM PAKISTAN Player "<<i<<" Name\n";
        cin>>TeamPAK[i];                         //store all players of PAK and write in file
        myfile<<TeamPAK[i]<<endl;
    }

    for (int i=0; i<11; i++)
    {
        cout<<"Enter TEAM INDIA Player "<<i<<" Name\n";
        cin>>TeamIND[i];                     //store all players of PAK and write in file
        myfile<<TeamIND[i]<<endl;
    }

     myfile.close();   //close the file

    Tossandchoose(TeamPAK,TeamIND,Bat_team,Bowl_team);   // call func
    srand(time(NULL));
    int overss=rand()%(10+1-5)+5;     //generating overs randomly between 50 and 20
    ofstream myfile1;
    myfile1.open("file.txt",ios::out| ios::app);
    myfile1<<overss;             //writing no of overs in file
    myfile1.close();
    cout<<"Match will be stimulated for "<< overss<< " number of overs\n";

    //now we display the end result and show menu
    char choose;
    do{                                           //use do while loop so it displays it till user enters exit
    cout<<"\n\n1.Play first inning\n";
    cout<<"2.Play second inning\n";
    cout<<"3.See Winning Team\n";
    cout<<"4.See batsman of the match\n";
    cout<<"5.See bowler of the match\n";
    cout<<"6.Exit\n\n";

    cin>>choose;
    system("cls");

    switch(choose)                    //we use switch to know what user uses and display that
    {
    case '1':
        {
             cout<<"********THE CHART FOR THE FIRST INNINGS**********\n";
             cout<<"               TO PLAY PRESS ENTER               \n";
             cin.get();
             first_innings(Bat_team,Bowl_team,runs,total_score,overss,first_inning_score);
            break;
        }
    case '2':
        {
            cout<<"********THE CHART FOR THE SECOND INNINGS**********\n";
            cout<<"                TO PLAY PRESS ENTER               \n";
            cin.get();
            second_innings(Bat_team,Bowl_team,runs,total_score,overss,second_inning_score);
            break;
        }
    case '3':
        {
            win_team();
            break;
        }
    case '4':
        {

            break;
        }
    case '5':
        {

            break;
        }
    case '6':
        {
            exit(0);
            break;
        }

    }
    }while(choose!=6);


   //delete the dynamic arrays at the end
   for(int i=0; i<11; i++)
   {
       delete[] TeamPAK[i];
   }

        delete[] TeamPAK;
    for(int i=0; i<11; i++)
   {
       delete[] TeamIND[i];
   }

        delete[] TeamIND;
    for(int i=0; i<11; i++)
   {
       delete[] Bat_team[i];
   }

        delete[] Bat_team;
    for(int i=0; i<11; i++)
   {
       delete[] Bowl_team[i];
   }

        delete[] Bowl_team;



    return 0;
}

