/*Tic-Tac-Toe Game Project
*/

//Headers
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<termios.h>
#include<errno.h>
#include<stdio.h>
#include<sys_index.h>

using namespace std;

/*Function for checking which player has won the game*
 returns 1 if player 1 has won the game
 returns 2 if player 2 has won the game
 returns 0 if no player has won
 key_1 refers to the token of player 1
 key_2 refers to the token of player 2*/

/*getch has to be implemented as a user defined function 
because linux does'nt support it
Credits : Stackoverflow.com*/

char getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    return buf;
 }


 
int CheckWin(char game_data[],char key_1,char key_2);


int CheckWin(char game_data[],char key_1,char key_2)
 {
	 
	 
 //checking diagonally from left top
  if(game_data[0]== key_1 && game_data[4]== key_1 && game_data[8]== key_1)
  {
  //player 1 has won the game
  return 1;
  }
  
  
  
  else if(game_data[0]== key_2 && game_data[4]== key_2 && game_data[8]== key_2)
  {
  //player 2 won the game
  return 2;
  }
 
 
   //checking diagonally from right top
  else if(game_data[6]== key_1 && game_data[4] == key_1 && game_data[2]== key_1)
  {
  return 1;
  }


  else if(game_data[6] == key_2 && game_data[4]== key_2  && game_data[2]== key_2 )
  {
  return 2;
  }


 //checking vertically

 else if(game_data[0]== key_1 && game_data[3]== key_1 && game_data[6]== key_1)
  {
   return 1;
   }


   else if(game_data[0]== key_2 && game_data[3]== key_2 && game_data[6]== key_2)
  {
  return 2;
  }


  
  else if(game_data[1]==key_1 && game_data[4]==key_1 && game_data[7]==key_1)
  {
  return 1;
  }


  else if(game_data[1]==key_2 && game_data[4]==key_2 && game_data[7]==key_2)
  {
   return 2;
   }


 else  if(game_data[2]==key_1 && game_data[5]==key_1 && game_data[8]==key_1)
  {
  return 1;
  }


  else if(game_data[2]==key_2 && game_data[5]==key_2 && game_data[8]==key_2)
  {
  return 2;
  }

  //checking horizontally
  else if(game_data[0]==key_1 && game_data[1]==key_1 && game_data[2]==key_1)
  {
  return 1;
  }


  else if(game_data[0]==key_2 && game_data[1]==key_2 && game_data[2]==key_2)
  {
  return 2;
  }


  else if(game_data[3]==key_1 && game_data[4]==key_1 && game_data[5]==key_1)
  {
  return 1;
  }


  else if(game_data[3]==key_2 && game_data[4]==key_2 && game_data[5]==key_2)
  {
  return 2;
  }


  else if(game_data[6]==key_1 && game_data[7]==key_1 && game_data[8]==key_1)
  {
  return 1;
  }


  else if(game_data[6]==key_2 && game_data[7]==key_2 && game_data[8]==key_2)
  {
  return 2;
  }

  //control comes here only when the above conditions are false
  return 0;
  }


void Win(char data,int win,char key_1,char key_2);
void Win(char data[],int win,int player,char key_1,char key_2)
  {

  //invoked when the game is over
	  //displays the player no who won the game
	  
   system("tput reset");
	  
	   cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t Player : "<<player;

		if(player == 1) { cout<<"       Token : "<<key_1<<endl; }
	    else { cout<<"        Token : "<<key_2<<endl; }


		
	cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[0]    <<"   |    "<<data[1]     <<"   |    "<<data[2]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[3]    <<"   |    "<<data[4]     <<"   |    "<<data[5]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[6]    <<"   |    "<<data[7]     <<"   |    "<<data[8]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;

	
	
  cout<<"Player "<<win<<" won"<<endl;
  cout<<"Press any key to return to main menu"<<endl;
   getch();
  }


void AboutGame(void);
void AboutGame(void)
{
	
system("tput reset");
	//gives information about the program
	
	cout<<"Tic-Tac-Toe Game Project"<<endl;
	cout<<"Computer Science Project"<<endl;
	getch();
}



void DrawGame(char data[]);
void DrawGame(char data[])
{
	
	//invoked when the game becomes draw

	system("tput reset");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[0]    <<"   |    "<<data[1]     <<"   |    "<<data[2]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[3]    <<"   |    "<<data[4]     <<"   |    "<<data[5]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[6]    <<"   |    "<<data[7]     <<"   |    "<<data[8]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;


	cout<<"The game is Draw....."<<endl;
	cout<<"Press any key to return to main menu"<<endl;
        getch();	

}


  int main(void)
  {


	  int ch = 0;
	  register int rand_val = 0;
	  int u_vs_sys = 0; //set to 1 if User vs System game is going on
	
	main_menu:
	  

  //menu for choosing options
  //Play->start playing the game
  //About->Displays details about the program
  //Exit->exis the program
        
           system("tput reset");
       
       cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "||               1.Play User vs System         ||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "||               2.Play User vs User           ||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\t\t" << "||      			               ||" << endl;
	cout << "\t\t" << "||               3.About                       ||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "||               4.Exit                        ||" << endl;
	cout << "\t\t" << "||                                             ||" << endl;
	cout << "\t\t" << "|||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << "\t\t" << "                                                 " << endl;
	cout << " " << endl;


	cin>>ch;
	switch(ch)
	{
	
	case 1:
		u_vs_sys = 1;
		goto start;
		break;

		
	case 2:
		u_vs_sys = 0;
		goto start;
		break;

		
	case 3:AboutGame();
		goto main_menu;

		
	case 4:
		exit(0);

		
	default:
		goto main_menu;
	}


    start:
	
    
	
	char data[]={'1','2','3','4','5','6','7','8','9'};//for storing X or O tokens
    int player=1;  //for storing player number
    int index=0;  //for getting table position while playing
	int start=0;
	int ascii_sum=0;
	char key_1;
	char key_2;

system("tput reset");
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t|-----------------------------|"<<endl;
    cout<<"\t\t\t| Welcome to Tic-Tac-Toe Game |"<<endl;
    cout<<"\t\t\t|    Press any key......      |"<<endl;
    cout<<"\t\t\t|-----------------------------|"<<endl;
 
getch();

    ask_again:
	
system("tput reset");
	//getting the token from the user
	cout<<"Enter Player 1 token(X | O) : ";
	cin>>key_1;
	cout<<endl;


	//if User vs User game is going on player have to chose the token manually
	if (u_vs_sys == 0)
	{
		cout << "Enter Player 2 token(X | O) : ";
		cin >> key_2;
		cout << endl;
	}
	
	
	else
	{
		//if User vs System game is going on system choses the token automatically after the user choses the token
		if (key_1 == 'X'){ key_2 = 'O'; }
		else{ key_2 = 'X'; }
	}

	/*checking for error in chosen tokens
	Possible errors->
	->Chosing of a token other than X or O

	In case of an error the user will be asked to enter the token again*/

	
	
	if(key_1 != 'X' && key_1 != 'O')
	{
	//if player 1 choses a token other than X or O
		goto ask_again;
	}

	if(key_2 != 'X' && key_2 != 'O')

        {
         goto ask_again;
        } 
	
	//displays the player no and their respective tokens
       system("tput reset");	
cout<<endl<<endl<<endl<<endl<<endl<<endl;
 cout<<"\t\t\t|--------------------|"<<endl;
 cout<<"\t\t\t| Player 1 token : "<< key_1<<" |"<<endl;
 cout<<"\t\t\t| Player 2 token : "<< key_2<<" |"<<endl;
 cout<<"\t\t\t| Best of luck...!   |"<<endl;
 cout<<"\t\t\t| Press any key....  |"<<endl;
 cout<<"\t\t\t|--------------------|"<<endl;
 
getch();

 
   /*After each player's turn CheckWin() is invoked
   if the function returns 1 player 1 won the game
   if the function returns 2 player 2 won the game
   Win is then invoked depending on the value returned
   here the player value is incremented/decremented to get the player that played previously for passing it to Win()
   incrementing or decrementing the player value gives the previous player who won the game */

 
 _continue:
    if(CheckWin(data,key_1,key_2)==1)
    {
		if(player==1){player++;}
		else{player--;}

    Win(data,1,player,key_1,key_2);
	goto main_menu;
    }

	
    else if(CheckWin(data,key_1,key_2)==2)
    {
		if(player==1){player++;}
		else{player--;}

    Win(data,2,player,key_1,key_2);
	goto main_menu;
	}

	
	else
	{
		/*        if CheckWin() returns 0 it comes here
		if the game is draw there may be 5 X's and 4 O's.The sum of the ascii codes of this combination is 756
		else there may be 4 X's and 5 O's.The sum of the ascii codes of this combination is 747
		if the sum of the ascii codes of all the elements of the array is equal to 756 or 747 then the game is draw*/

		
	int sum=0;
	for(int i=0;i<9;i++)
	{

sum=(int)data[i]+sum;
	
	}
	if(sum == 756 || sum == 747)
	{
		DrawGame(data);
		goto main_menu;
	}
	}
 
system("tput reset");

	/*The values at each position in the arrays is displayed in a table*/
	
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    if(player == 2){cout<<"\t\t\t     System is Playing"<<endl<<endl;}
    cout<<"\t\t\t Player : "<<player;

	
	//displaying token depending on player number
	if(player == 1) { cout<<"       Token : "<<key_1<<endl; }
	else { cout<<"        Token : "<<key_2<<endl; }
    
	
	
	cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[0]    <<"   |    "<<data[1]     <<"   |    "<<data[2]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[3]    <<"   |    "<<data[4]     <<"   |    "<<data[5]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;
    cout<<"\t\t\t|    "<<data[6]    <<"   |    "<<data[7]     <<"   |    "<<data[8]     <<"   |"<<endl;
    cout<<"\t\t\t|--------|--------|--------|"<<endl;



    //game starts from here
	/*the player choses the number in the table where he want his token to be put
	the value is then taken to access the corresponding value of the array and the token is put in that place*/
    
    if(player == 1)
    {
	

	cin >> index;
    if(data[index-1]!= key_2 && data[index-1]!=key_1)
    {
    data[index-1]=key_1;
	player++;
	goto _continue;
    }

	//if player 2 has already chosen the box
    else if(data[index-1]==key_2 || data[index-1] == key_1)
    {
    player++;
    goto _continue;
    }
    }

	
    else if(player == 2)
    {
		
		if (u_vs_sys == 0) //if User vs User game is going on.....
		{
			
			cin >> index;
			if (data[index - 1] != key_2 && data[index - 1] != key_1)
			{
				data[index - 1] = key_2;
				player--;
				goto _continue;
			}
			
			
			else if (data[index - 1] == key_2 || data[index - 1] == key_1)
			{
				player--;
				goto _continue;
			}

		}
		
		
		//Player 2 refers to the system
		for (;;)
		{
//code inside infinite for loop.random value is created between the range 0-9.This value is taken as the index of the data[] array.
//if the corresponding position of the array is suitable for the system to place the token the token is placed.else the loop continues.
                        
                       //if system can find an entry to complete the three consecutive entries
                        rand_val=systemIndexFind(data,key_1,key_2);
			if(rand_val != -1)
			{
                        data[rand_val]=key_2;
			player--;
			goto _continue;
			break;
			}

			srand((unsigned)time(0));
			rand_val = (rand() % 9) + 0;
			
			
			if (data[rand_val] == key_1)
			{
				//if the corresponding position was already used by player 1
				continue;
			}
			
			
			else if (data[rand_val] == key_2)
			{
			//if the corresponding position was already used by the system itself
				continue;
			}

			
			
			else
			{
				//if the position is unused
				data[rand_val] = key_2;
				player--;
				goto _continue;
			}
		}
    }

    return 0;
    }
	                                                                      /*END OF PROJECT*/
