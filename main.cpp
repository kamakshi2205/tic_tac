#include <iostream>
#include<string>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard()
{

 for(int i=0;i<3;i++)
 {
     for(int j=0;j<3;j++)
      if(board[i][j]=='o'||board[i][j]=='x')
       cout<<board[i][j]<<" ";
      else
       cout<<". ";

     cout<<'\n';
 }
}

char current_marker;
int current_player;

bool placeMarker(int slot)
{ //getting row and column
  int row = slot/3,col;
  if(slot % 3 == 0)
  { row = row-1;
    col=2;
   }
  else col = (slot % 3 ) - 1;

  if(board[row][col] != 'x' && board[row][col] != 'o')
  {
    board[row][col] = current_marker;
    return true;
  }
  else return false;
}

int winner()
{
  for(int i=0;i<3;i++)
  {
    if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
    return current_player;

    if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
    return current_player;
  }

  if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
  return current_player;

  if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
  return current_player;

  return 0;
}

void swap_player_and_marker()
{
  if(current_marker=='x')
  current_marker = 'o';
  else
  current_marker = 'x';

  if(current_player==1)
  current_player = 2;
  else
  current_player = 1;

}


void game()
{ char pl1[20],pl2[20],name[20],choice;

  do{
  cout<<"Enter name for x player : "<<endl;
  cin>>pl1;
  cout<<"Enter name for o player : "<<endl;
  cin>>pl2;

  do{

  cout<<"\nWho plays first "<<pl1<<" or "<<pl2<<" ?\n";
  cin>>name;

  if(strcmp(name,pl1)==0)
  current_player=1;
  else if(strcmp(name,pl2)==0)
  current_player=2;
  else
  cout<<name<<" is not a registered player."<<endl;

  }while((strcmp(name,pl1)!=0)&&(strcmp(name,pl2)!=0));

  current_marker='x';

  cout<<endl;
  drawBoard();
  cout<<endl;

  int player_won;

  for(int i =0; i<9;i++)
  {
    cout<< "Player of current turn: ";
    if(current_player==1)
    cout<<pl1<<endl;
    else
    cout<<pl2<<endl;

    cout<<"Choose slot 0 to 9: "<<endl;
    int slot;
    cin>>slot;

    if((slot < 1) || (slot > 9))
    {
      cout<<"Invalid slot. Try again. "<<endl;
      i--;
      continue;
    }

    if(!placeMarker(slot))
    {
      cout<<"Slot is occupied. Try another."<<endl;
      i--;
      continue;
    }

    cout<<endl;
    drawBoard();
    cout<<endl;

  player_won =winner();

   if(player_won == 1)
   {cout<<"Game is over: "<<endl<<pl1<<" wins!"<<endl;
   break;}

   if(player_won == 2)
   {cout<<"Game is over: "<<endl<<pl2<<" wins!"<<endl;
   break;}

    swap_player_and_marker();

  }

  if(player_won == 0)
  cout<<"Game is over: "<<endl<<"it is a tie!"<<endl;

  do{
      cout<<endl<<"Would you like to play again? (y/n)\n";
      cin>>choice;
      if(choice!='y'&&choice!='n')
       cout<<choice<<" is not a valid answer\n";
    }while(choice!='y'&&choice!='n');

    if(choice=='n')
        cout<<"Bye\n";

  }while(choice=='y');
}

int main()
{

    game();


  return 0;
}
