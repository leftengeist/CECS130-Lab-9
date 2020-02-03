#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;
/*
This program allows the user to play a game of Tic-Tac-Toe with the computer
Walton Levi, Section 1
*/
class Box{
	private:
		int iBoardSpace;
		bool bOpenSpace;
	public:
		void set(int);
		char cGameState;
	 	bool bPlayersTurn(void);
		bool bCompTurn(void);
};
class Board{
	public:
		Box place1;
		Box place2;
		Box place3;
		Box place4;
		Box place5;
		Box place6;
		Box place7;
		Box place8;
		Box place9;
		Board();
		void vGameBoard(void);
		bool bChooseSpace(bool, int);
		bool bCheck(bool);
};
int main(){
	Board board;
	srand(time(NULL));
	bool bPTurn = (rand()%2);
	bool bGameOver = 0;
	int iSelection;
	bool bEndTurn;
	while(bGameOver == 0)    {
		board.vGameBoard();
		do{
			if(bPTurn)            {
				cout<<endl<<"Player's Turn!"<<endl<<"Choose a Box: ";
				cin>>iSelection;
				bEndTurn = board.bChooseSpace(bPTurn, iSelection);
				if (bEndTurn == 0)                {
					cout<<endl<<"Invalid Choice"<<endl<<"Please Choose Again";
				}
				else if (bEndTurn)				{				    system("cls");
					bGameOver = board.bCheck(bPTurn);
					bPTurn = 0;
				}
			}
			else            {
				iSelection = (rand()%9)+1;
				bEndTurn = board.bChooseSpace(bPTurn, iSelection);
				if(bEndTurn)                {
					bGameOver = board.bCheck(bPTurn);
					bPTurn = 1;					system("cls");
				}
			}
		}while(bEndTurn==0);
	}

	board.vGameBoard();
	return 0;
}



void Box::set(int x){
	iBoardSpace = x;
	bOpenSpace = 1;
	cGameState = ' ';
}
bool Box::bPlayersTurn(){
	if(bOpenSpace)	{
		cGameState = 'X';
		bOpenSpace = 0;
		return 1;
	}
	else    {
		return 0;
	}

}
bool Box::bCompTurn(){
	if(bOpenSpace)    {
		cGameState = 'O';
		bOpenSpace = 0;
		return 1;    }
	else	{
		return 0;
	}

}

Board::Board(){
	place1.set(1);
	place2.set(2);
	place3.set(3);
	place4.set(4);
	place5.set(5);
	place6.set(6);
	place7.set(7);
	place8.set(8);
	place9.set(9);
}
void Board::vGameBoard(){
		cout<<endl<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<place1.cGameState<<")  |  ("<<place2.cGameState<<")  |  ("<<place3.cGameState<<")  |"<<endl<<"|   1   |   2   |   3   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<place4.cGameState<<")  |  ("<<place5.cGameState<<")  |  ("<<place6.cGameState<<")  |"<<endl<<"|   4   |   5   |   6   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|  ("<<place7.cGameState<<")  |  ("<<place8.cGameState<<")  |  ("<<place9.cGameState<<")  |"<<endl<<"|   7   |   8   |   9   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
}
bool Board::bChooseSpace(bool bPTurn, int iSelection){
	if(bPTurn)    {
		switch(iSelection)		{
			case 1:			    {
					return place1.bPlayersTurn();
					break;
				}
			case 2:			    {
					return place2.bPlayersTurn();
					break;
				}
			case 3:			    {
					return place3.bPlayersTurn();
					break;
				}
			case 4:			    {
					return place4.bPlayersTurn();
					break;
				}
			case 5:			    {
					return place5.bPlayersTurn();
					break;
				}
			case 6:			    {
					return place6.bPlayersTurn();
					break;
				}
			case 7:			    {
					return place7.bPlayersTurn();
					break;
				}
			case 8:			    {
					return place8.bPlayersTurn();
					break;
				}
			case 9:			    {
					return place9.bPlayersTurn();
					break;
				}
			default:			    {
					return 0;
				}
		}
	}
	else    {
		switch(iSelection)		{
			case 1:			    {
					return place1.bCompTurn();
					break;
				}
			case 2:			    {
					return place2.bCompTurn();
					break;
				}
			case 3:			    {
					return place3.bCompTurn();
					break;
				}
			case 4:			    {
					return place4.bCompTurn();
					break;
				}
			case 5:			    {
					return place5.bCompTurn();
					break;
				}
			case 6:			    {
					return place6.bCompTurn();
					break;
				}
			case 7:			    {
					return place7.bCompTurn();
					break;
				}
			case 8:			    {
					return place8.bCompTurn();
					break;
				}
			case 9:			    {
					return place9.bCompTurn();
					break;
				}
			default:			    {
					return 0;
				}
		}
	}
}
bool Board::bCheck(bool bPTurn){
	int iGameEnd = 0;
	char empty = ' ';
	if (place1.cGameState == place2.cGameState && place1.cGameState == place3.cGameState && place1.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place1.cGameState == place4.cGameState && place1.cGameState == place7.cGameState && place1.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place1.cGameState == place5.cGameState && place1.cGameState == place9.cGameState && place1.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place2.cGameState == place5.cGameState && place2.cGameState == place8.cGameState && place2.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place3.cGameState == place5.cGameState && place3.cGameState == place7.cGameState && place3.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place3.cGameState == place6.cGameState && place3.cGameState == place9.cGameState && place3.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place4.cGameState == place5.cGameState && place4.cGameState == place6.cGameState && place4.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place7.cGameState == place8.cGameState && place7.cGameState == place9.cGameState && place7.cGameState != empty)    {
		iGameEnd = 1;

	}
	else if (place1.cGameState != empty && place2.cGameState != empty && place3.cGameState != empty && place4.cGameState != empty && place5.cGameState != empty && place6.cGameState != empty && place7.cGameState != empty && place8.cGameState != empty && place9.cGameState != empty && iGameEnd != 1)    {
		iGameEnd = 2;
	}
	else	{
		iGameEnd = 0;
	}

	if (iGameEnd == 1)    {
		cout<<endl<<"GAME OVER";
		if(bPTurn)		{
			cout<<endl<<"Congratulations You WON!";
			return 1;
		}
		else		{
			cout<<endl<<"Sorry you LOST!";
			return 1;
		}

	}
	else if (iGameEnd == 2)    {
		cout<<endl<<"GAME OVER"<<endl<<"PLAYER AND COMPUTER TIED!";
	}
	else	{
		return 0;
	}
}
