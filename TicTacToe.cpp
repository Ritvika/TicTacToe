#include<iostream>
using namespace std;
char box[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int turn = 1, player_num, box_num;
bool win = false;
char symbol;
void Draw_Board()                   //Draw TicTacToe Board
{
	system("cls");
	cout << "\nTic-Tac-Toe\n\n";
	cout << "Player 1 (X)";
	cout << "\n";
	cout << "Player 2 (0)";
	cout << "\n\n\n\n";
	cout << "     |     |     "<<endl;
	cout << "  " << box[0] << "  |  " << box[1] << "  |  " << box[2]<<endl;
	cout << "_____|_____|_____"<<endl;
	cout << "     |     |     "<<endl;
	cout << "  " << box[3] << "  |  " << box[4] << "  |  " << box[5] << endl;
	cout << "_____|_____|_____"<<endl;
	cout << "     |     |     "<<endl;
	cout << "  " << box[6] << "  |  " << box[7] << "  |  " << box[8] << endl;
	cout << "     |     |     "<<endl;	
}
void Player_Turn()                   //Accept input from player
{
	player_num = (turn % 2 == 0) ? 2 : 1;
	cout << "\nPlayer " << player_num << ", select your box: ";
	cin >> box_num;
	while (!cin)
	{
		cout << "Invalid Move. Player " << player_num << ", select a valid box: ";
		cin.clear();
		cin.ignore();
		cin >> box_num;
	}
}
void Fill_Box()                       //Fill up the appropriate symbol
{
	if (player_num == 1)
		symbol = 'X';
	else
		symbol = 'O';
	box[--box_num] = symbol;
}
void Player_Win()                      //Check if a player wins
{                             
	if ((box[0] == box[1] && box[1] == box[2]) 
		|| (box[3] == box[4] && box[4] == box[5]) 
		|| (box[6] == box[7] && box[7] == box[8])
		|| (box[0] == box[3] && box[3] == box[6]) 
		|| (box[1] == box[4] && box[4] == box[7]) 
		|| (box[2] == box[5] && box[5] == box[8])
		|| (box[0] == box[4] && box[4] == box[8]) 
		|| (box[2] == box[4] && box[4] == box[6]))
	{
		win = true;
		cout << "\nPlayer " << player_num << " wins!";
	}
}
int main()
{
	Draw_Board();
	while(!win)
	{
		Player_Turn();	
		Fill_Box();
		Draw_Board();
		Player_Win();
		turn++;
	}
	cin.ignore();
	cin.get();
	return 0;
}
