#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "SerialPort.h"
using namespace std;
//=========================================================================================================================//
int player = 2; // user
int y, y2; char x1, x2;
int col, col2;
bool valid, taken_by_piece = false;
float Max;
char *port_name = "\\\\.\\COM6";
char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];
SerialPort arduino(port_name);
//=========================================================================================================================//
void switch_role() {
	(player == 2) ? player = 1 : player = 2;
}
//=========================================================================================================================//
char board[8][8] = {

	{ 'R','N','B','Q','K','B','N','R' },
	{ 'P','P','P','P','P','P','P','P' },
	{ 'e','e','e','e','e','e','e','e' },
	{ 'e','e','e','e','e','e','e','e' },
	{ 'e','e','e','e','e','e','e','e' },
	{ 'e','e','e','e','e','e','e','e' },
	{ 'p','p','p','p','p','p','p','p' },
	{ 'r','n','b','k','q','b','n','r' },
};
//=========================================================================================================================//
float Pawn[8][8] =
{
	{ 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 },
	{ 0.5,1.0,1.0,-2.0,-2.0,1.0,1.0,0.5 },
	{ 0.5,-0.5,-1.0,0.0,0.0,-1.0,-0.5,0.5 },
	{ 0.0,0.0,0.0,2.0,2.0,0.0,0.0,0.0 },
	{ 0.5,0.5,1.0,2.5,2.5,1.0,0.5,0.5 },
	{ 1.0,1.0,2.0,3.0,3.0,2.0,1.0,1.0 },
	{ 5.0,5.0,5.0,5.0,5.0,5.0,5.0,5.0 },
	{ 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 },
};
float Rock[8][8] =
{
	{ 0.0,0.0,0.0,0.5,0.5,0.0,0.0,0.0 },
	{ 0.5,0.0,0.0,0.0,0.0,0.0,0.0,0.5 },
	{ 0.5,0.0,0.0,0.0,0.0,0.0,0.0,0.5 },
	{ 0.5,0.0,0.0,0.0,0.0,0.0,0.0,0.5 },
	{ 0.5,0.0,0.0,0.0,0.0,0.0,0.0,0.5 },
	{ 0.5,0.0,0.0,0.0,0.0,0.0,0.0,0.5 },
	{ 0.5,1.0,1.0,1.0,1.0,1.0,1.0,0.5 },
	{ 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 },
};
float Bishop[8][8] =
{
	{ -2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0 },
	{ -1.0,0.5,0.0,0.0,0.0,0.0,0.5,-1.0 },
	{ -1.0,0.0,1.0,1.0,1.0,1.0,0.0,-1.0 },
	{ -1.0,0.5,0.5,1.0,1.0,0.5,0.5,-1.0 },
	{ -1.0,0.5,0.5,1.0,1.0,0.5,0.5,-1.0 },
	{ -1.0,0.0,0.5,1.0,1.0,0.5,0.0,-1.0 },
	{ -1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0 },
	{ -2.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-2.0 },
};
float Queen[8][8] =
{
	{ -2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0 },
	{ -1.0,0.0,0.5,0.0,0.0,0.0,0.0,-1.0 },
	{ -1.0,0.5,0.5,0.5,0.5,0.5,0.0,-1.0 },
	{ 0.0,0.0,0.5,0.5,0.5,0.5,0.0,-0.5 },
	{ -0.5,0.0,0.5,0.5,0.5,0.5,0.0,-0.5 },
	{ -1.0,0.0,0.5,0.5,0.5,0.5,0.0,-1.0 },
	{ -1.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0 },
	{ -2.0,-1.0,-1.0,-0.5,-0.5,-1.0,-1.0,-2.0 },
};
float  King[8][8] =
{
	{ 2.0,3.0,1.0,0.0,0.0,1.0,3.0,2.0 },
	{ 2.0,2.0,0.0,0.0,0.0,0.0,2.0,2.0 },
	{ -1.0,-2.0,-2.0,-2.0,-2.0,-2.0,-2.0,-1.0 },
	{ -2.0,-3.0,-3.0,-4.0,-4.0,-3.0,-3.0,-2.0 },
	{ -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0 },
	{ -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0 },
	{ -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0 },
	{ -3.0,-4.0,-4.0,-5.0,-5.0,-4.0,-4.0,-3.0 },

};
float Knight[8][8] =
{
	{ -5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0 },
	{ -4.0,-2.0,0.0,0.5,0.5,0.0,-2.0,-4.0 },
	{ -3.0,0.5,1.0,1.5,1.5,1.0,0.5,-3.0 },
	{ -3.0,0.0,1.5,2.0,2.0,1.5,0.0,-3.0 },
	{ -3.0,0.5,1.5,2.0,2.0,1.5,0.5,-3.0 },
	{ -3.0,0.0,1.0,1.5,1.5,1.0,0.0,-3.0 },
	{ -4.0,-2.0,0.0,0.0,0.0,0.0,-2.0,-4.0 },
	{ -5.0,-4.0,-3.0,-3.0,-3.0,-3.0,-4.0,-5.0 },
};
//=========================================================================================================================//
struct Coordinate {
	int x, y;
	float Max;
};
Coordinate checking(char Piece, int x, int y) {
	Coordinate Place;
	Place.x = -1;
	Place.y = -1;
	//float Max = -10000;
	Place.Max = Max;
	Max = -1000;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pawn~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (Piece == 'P')
	{
		//if the place is empty then we give it a score of five

		if (x == 1) {//this is the first move for the pawn
			float Begins = Pawn[x][y];
			float Score = 0;
			//for the first condition that iot can move two step
			if (board[x + 1][y] == 'e') { //moving one step and its empty
				float Score = Pawn[x + 1][y];
				if (Begins - Score > Max) {
					Place.x = x + 1;
					Place.y = y;
					Place.Max = Score - Begins;
					cout << "this is your place.max " << Place.Max << endl;
					Max = Place.Max;
				}
			}
			if (board[x + 1][y] == 'e' && board[x + 2][y] == 'e') {// in case the pawn will move two steps
				float Score = Pawn[x + 2][y];
				if (Begins - Score  > Max) {
					Place.x = x + 2;
					Place.y = y;
					Place.Max = Score - Begins;
					Max = Place.Max;
				}
			}

			if (board[x + 1][y + 1] == 'r' || board[x + 1][y + 1] == 'q' || board[x + 1][y + 1] == 'k' || board[x + 1][y + 1] == 'p' || board[x + 1][y + 1] == 'n' || board[x + 1][y + 1] == 'b') {
				float Score = Pawn[x + 1][y + 1];
				if (board[x + 1][y + 1] == 'r') Score += 50;
				else if (board[x + 1][y + 1] == 'n')Score += 30;
				else if (board[x + 1][y + 1] == 'p')Score += 10;
				else if (board[x + 1][y + 1] == 'q')Score += 90;
				else if (board[x + 1][y + 1] == 'b')Score += 30;
				else if (board[x + 1][y + 1] == 'k')Score += 900;
				cout << "i am here in this condition " << endl;
				if (Score - Begins > Max) {
					Place.x = x + 1;
					Place.y = y + 1;
					Place.Max = Score - Begins;
					Max = Place.Max;
					taken_by_piece = true;
				}
			}
			if (board[x - 1][y + 1] == 'r' || board[x - 1][y + 1] == 'q' || board[x - 1][y + 1] == 'k' || board[x - 1][y + 1] == 'p' || board[x - 1][y + 1] == 'n' || board[x - 1][y + 1] == 'b') {
				float Score = Pawn[x - 1][y + 1];
				if (board[x - 1][y + 1] == 'r') Score += 50;
				else if (board[x - 1][y + 1] == 'n')Score += 30;
				else if (board[x - 1][y + 1] == 'p')Score += 10;
				else if (board[x - 1][y + 1] == 'q')Score += 90;
				else if (board[x - 1][y + 1] == 'b')Score += 30;
				else if (board[x - 1][y + 1] == 'k')Score += 900;
				if (Score - Begins > Max) {
					Place.x = x - 1;
					Place.y = y + 1;
					Place.Max = Score - Begins;
					Max = Place.Max;
					taken_by_piece = true;
				}
			}


		}//end if(x==1)
		else {
			float Begins = Pawn[x][y];
			float Score = 0;
			if (board[x + 1][y] == 'e') { //moving one step and its empty
				float Score = Pawn[x + 1][y];
				if (Begins - Score > Max) {
					Place.x = x + 1;
					Place.y = y;
					Place.Max = Score - Begins;
					Max = Place.Max;
				}
			}//
			if (board[x + 1][y + 1] == 'r' || board[x + 1][y + 1] == 'q' || board[x + 1][y + 1] == 'k' || board[x + 1][y + 1] == 'p' || board[x + 1][y + 1] == 'n' || board[x + 1][y + 1] == 'b') {
				float Score = Pawn[x + 1][y + 1];
				if (board[x + 1][y + 1] == 'r') Score += 50;
				else if (board[x + 1][y + 1] == 'n')Score += 30;
				else if (board[x + 1][y + 1] == 'p')Score += 10;
				else if (board[x + 1][y + 1] == 'q')Score += 90;
				else if (board[x + 1][y + 1] == 'b')Score += 30;
				else if (board[x + 1][y + 1] == 'k')Score += 900;
				if (Score - Begins > Max) {
					Place.x = x + 1;
					Place.y = y + 1;
					Place.Max = Score - Begins;
					Max = Place.Max;
					taken_by_piece = true;
				}
			}
			if (board[x - 1][y + 1] == 'r' || board[x - 1][y + 1] == 'q' || board[x - 1][y + 1] == 'k' || board[x - 1][y + 1] == 'p' || board[x - 1][y + 1] == 'n' || board[x - 1][y + 1] == 'b') {
				float Score = Pawn[x - 1][y + 1];
				if (board[x - 1][y + 1] == 'r') Score += 50;
				else if (board[x - 1][y + 1] == 'n')Score += 30;
				else if (board[x - 1][y + 1] == 'p')Score += 10;
				else if (board[x - 1][y + 1] == 'q')Score += 90;
				else if (board[x - 1][y + 1] == 'b')Score += 30;
				else if (board[x - 1][y + 1] == 'k')Score += 900;
				if (Score - Begins > Max) {
					Place.x = x - 1;
					Place.y = y + 1;
					Place.Max = Score - Begins;
					Max = Place.Max;
					taken_by_piece = true;
				}
			}
		}

	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~rock~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	//taken_by_piece = false;
	if (Piece == 'R') {
		float Begins = Rock[x][y];
		float Score = 0;

		if (board[x + 1][y] == 'e' || board[x + 1][y] == 'r' || board[x + 1][y] == 'n' || board[x + 1][y] == 'p' || board[x + 1][y] == 'q' || board[x + 1][y] == 'b' || board[x + 1][y] == 'k') { //moving down
			for (int i = x + 1; i < 8; i++) {
				float Score = Rock[i][y];
				if (board[i][y] == 'r') Score += 50;
				else if (board[i][y] == 'n')Score += 30;
				else if (board[i][y] == 'p')Score += 10;
				else if (board[i][y] == 'q')Score += 90;
				else if (board[i][y] == 'b')Score += 30;
				else if (board[i][y] == 'k')Score += 900;
				else if (board[i][y] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = y;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 10) break;
			}
		}//end of down if

		if (board[x - 1][y] == 'e' || board[x - 1][y] == 'r' || board[x - 1][y] == 'n' || board[x - 1][y] == 'p' || board[x - 1][y] == 'q' || board[x - 1][y] == 'b' || board[x - 1][y] == 'k') { //moving up
			for (int i = x - 1; i > 1; i--) {
				float Score = Rock[i][y];
				if (board[i][y] == 'r') Score += 50;
				else if (board[i][y] == 'n')Score += 30;
				else if (board[i][y] == 'p')Score += 10;
				else if (board[i][y] == 'q')Score += 90;
				else if (board[i][y] == 'b')Score += 30;
				else if (board[i][y] == 'k')Score += 900;
				else if (board[i][y] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = y;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}
		}//end of up if

		if (board[x][y + 1] == 'e' || board[x][y + 1] == 'r' || board[x][y + 1] == 'n' || board[x][y + 1] == 'p' || board[x][y + 1] == 'q' || board[x][y + 1] == 'b' || board[x][y + 1] == 'k') { //moving up
			for (int i = y + 1; i < 8; i++) {
				float Score = Rock[x][i];
				if (board[x][i] == 'r') Score += 50;
				else if (board[x][i] == 'n')Score += 30;
				else if (board[x][i] == 'p')Score += 10;
				else if (board[x][i] == 'q')Score += 90;
				else if (board[x][i] == 'b')Score += 30;
				else if (board[x][i] == 'k')Score += 900;
				else if (board[x][i] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = x;
					Place.y = i;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}
		}//end of right if

		if (board[x][y - 1] == 'e' || board[x][y - 1] == 'r' || board[x][y - 1] == 'n' || board[x][y - 1] == 'p' || board[x][y - 1] == 'q' || board[x][y - 1] == 'b' || board[x][y - 1] == 'k') { //moving up
			for (int i = y - 1; i > 1; i--) {
				float Score = Rock[x][i];
				if (board[x][i] == 'r') Score += 50;
				else if (board[x][i] == 'n')Score += 30;
				else if (board[x][i] == 'p')Score += 10;
				else if (board[x][i] == 'q')Score += 90;
				else if (board[x][i] == 'b')Score += 30;
				else if (board[x][i] == 'k')Score += 900;
				else if (board[x][i] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = x;
					Place.y = i;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}
		}//end of right if
	}//end of the rock

	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BISHOP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (Piece == 'B') {
		float Begins = Bishop[x][y];
		float Score = 0;
		if (board[x + 1][y + 1] == 'e' || board[x + 1][y + 1] == 'r' || board[x + 1][y + 1] == 'n' || board[x + 1][y + 1] == 'p' || board[x + 1][y + 1] == 'q' || board[x + 1][y + 1] == 'b' || board[x + 1][y + 1] == 'k') {
			for (int i = x, j = y; i < 7 && j < 7; i++, j++) {
				float Score = Bishop[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}
		}

		if (board[x - 1][y + 1] == 'e' || board[x - 1][y + 1] == 'r' || board[x - 1][y + 1] == 'n' || board[x - 1][y + 1] == 'p' || board[x - 1][y + 1] == 'q' || board[x - 1][y + 1] == 'b' || board[x - 1][y + 1] == 'k') {
			for (int i = x, j = y; i >0 && j < 7; i--, j++) {
				float Score = Bishop[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}
		}

		if (board[x + 1][y - 1] == 'e' || board[x + 1][y - 1] == 'r' || board[x + 1][y - 1] == 'n' || board[x + 1][y - 1] == 'p' || board[x + 1][y - 1] == 'q' || board[x + 1][y - 1] == 'b' || board[x + 1][y - 1] == 'k') {
			for (int i = x, j = y; i <7 && j >0; i++, j--) {
				float Score = Bishop[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}
		}

		if (board[x - 1][y - 1] == 'e' || board[x - 1][y - 1] == 'r' || board[x - 1][y - 1] == 'n' || board[x - 1][y - 1] == 'p' || board[x - 1][y - 1] == 'q' || board[x - 1][y - 1] == 'b' || board[x - 1][y - 1] == 'k') {
			for (int i = x, j = y; i >0 && j >0; i--, j--) {
				float Score = Bishop[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (Score > 5) break;
			}//end of loop
		}

	}//end of bishop
	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~King~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (Piece == 'K') {
		float Begins = Bishop[x][y];
		float Score = 0;
		//////////////////////////diagonal moves
		if (board[x - 1][y - 1] == 'e' || board[x - 1][y - 1] == 'r' || board[x - 1][y - 1] == 'n' || board[x - 1][y - 1] == 'p' || board[x - 1][y - 1] == 'q' || board[x - 1][y - 1] == 'b' || board[x - 1][y - 1] == 'k') {
			float Score = Bishop[x - 1][y - 1];
			if (board[x - 1][y - 1] == 'r') Score += 50;
			else if (board[x - 1][y - 1] == 'n')Score += 30;
			else if (board[x - 1][y - 1] == 'p')Score += 10;
			else if (board[x - 1][y - 1] == 'q')Score += 90;
			else if (board[x - 1][y - 1] == 'b')Score += 30;
			else if (board[x - 1][y - 1] == 'k')Score += 900;
			else if (board[x - 1][y - 1] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x - 1;
				Place.y = y - 1;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		if (board[x + 1][y - 1] == 'e' || board[x + 1][y - 1] == 'r' || board[x + 1][y - 1] == 'n' || board[x + 1][y - 1] == 'p' || board[x + 1][y - 1] == 'q' || board[x + 1][y - 1] == 'b' || board[x + 1][y - 1] == 'k') {
			float Score = Bishop[x + 1][y - 1];
			if (board[x + 1][y - 1] == 'r') Score += 50;
			else if (board[x + 1][y - 1] == 'n')Score += 30;
			else if (board[x + 1][y - 1] == 'p')Score += 10;
			else if (board[x + 1][y - 1] == 'q')Score += 90;
			else if (board[x + 1][y - 1] == 'b')Score += 30;
			else if (board[x + 1][y - 1] == 'k')Score += 900;
			else if (board[x + 1][y - 1] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x + 1;
				Place.y = y - 1;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		if (board[x - 1][y + 1] == 'e' || board[x - 1][y + 1] == 'r' || board[x - 1][y + 1] == 'n' || board[x - 1][y + 1] == 'p' || board[x - 1][y + 1] == 'q' || board[x - 1][y + 1] == 'b' || board[x - 1][y + 1] == 'k') {
			float Score = Bishop[x - 1][y + 1];
			if (board[x - 1][y + 1] == 'r') Score += 50;
			else if (board[x - 1][y + 1] == 'n')Score += 30;
			else if (board[x - 1][y + 1] == 'p')Score += 10;
			else if (board[x - 1][y + 1] == 'q')Score += 90;
			else if (board[x - 1][y + 1] == 'b')Score += 30;
			else if (board[x - 1][y + 1] == 'k')Score += 900;
			else if (board[x - 1][y + 1] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x - 1;
				Place.y = y + 1;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		if (board[x + 1][y + 1] == 'e' || board[x + 1][y + 1] == 'r' || board[x + 1][y + 1] == 'n' || board[x + 1][y + 1] == 'p' || board[x + 1][y + 1] == 'q' || board[x + 1][y + 1] == 'b' || board[x + 1][y + 1] == 'k') {
			float Score = Bishop[x - 1][y + 1];
			if (board[x + 1][y + 1] == 'r') Score += 50;
			else if (board[x + 1][y + 1] == 'n')Score += 30;
			else if (board[x + 1][y + 1] == 'p')Score += 10;
			else if (board[x + 1][y + 1] == 'q')Score += 90;
			else if (board[x + 1][y + 1] == 'b')Score += 30;
			else if (board[x + 1][y + 1] == 'k')Score += 900;
			else if (board[x + 1][y + 1] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x + 1;
				Place.y = y + 1;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		//////////////////////////stright moves
		if (board[x][y + 1] == 'e' || board[x][y + 1] == 'r' || board[x][y + 1] == 'n' || board[x][y + 1] == 'p' || board[x][y + 1] == 'q' || board[x][y + 1] == 'b' || board[x][y + 1] == 'k') {
			float Score = Bishop[x][y + 1];
			if (board[x][y + 1] == 'r') Score += 50;
			else if (board[x][y + 1] == 'n')Score += 30;
			else if (board[x][y + 1] == 'p')Score += 10;
			else if (board[x][y + 1] == 'q')Score += 90;
			else if (board[x][y + 1] == 'b')Score += 30;
			else if (board[x][y + 1] == 'k')Score += 900;
			else if (board[x][y + 1] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x;
				Place.y = y + 1;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		if (board[x][y - 1] == 'e' || board[x][y - 1] == 'r' || board[x][y - 1] == 'n' || board[x][y - 1] == 'p' || board[x][y - 1] == 'q' || board[x][y - 1] == 'b' || board[x][y - 1] == 'k') {
			float Score = Bishop[x][y - 1];
			if (board[x][y - 1] == 'r') Score += 50;
			else if (board[x][y - 1] == 'n')Score += 30;
			else if (board[x][y - 1] == 'p')Score += 10;
			else if (board[x][y - 1] == 'q')Score += 90;
			else if (board[x][y - 1] == 'b')Score += 30;
			else if (board[x][y - 1] == 'k')Score += 900;
			else if (board[x][y - 1] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x;
				Place.y = y - 1;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		if (board[x + 1][y] == 'e' || board[x + 1][y] == 'r' || board[x + 1][y] == 'n' || board[x + 1][y] == 'p' || board[x + 1][y] == 'q' || board[x + 1][y] == 'b' || board[x + 1][y] == 'k') {
			float Score = Bishop[x + 1][y];
			if (board[x][y - 1] == 'r') Score += 50;
			else if (board[x + 1][y] == 'n')Score += 30;
			else if (board[x + 1][y] == 'p')Score += 10;
			else if (board[x + 1][y] == 'q')Score += 90;
			else if (board[x + 1][y] == 'b')Score += 30;
			else if (board[x + 1][y] == 'k')Score += 900;
			else if (board[x + 1][y] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x + 1;
				Place.y = y;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}
		if (board[x - 1][y] == 'e' || board[x - 1][y] == 'r' || board[x - 1][y] == 'n' || board[x - 1][y] == 'p' || board[x - 1][y] == 'q' || board[x - 1][y] == 'b' || board[x - 1][y] == 'k') {
			float Score = Bishop[x - 1][y];
			if (board[x][y - 1] == 'r') Score += 50;
			else if (board[x - 1][y] == 'n')Score += 30;
			else if (board[x - 1][y] == 'p')Score += 10;
			else if (board[x - 1][y] == 'q')Score += 90;
			else if (board[x - 1][y] == 'b')Score += 30;
			else if (board[x - 1][y] == 'k')Score += 900;
			else if (board[x - 1][y] == 'e')Score += 0.5;
			if (Score - Begins > Max) {
				Place.x = x - 1;
				Place.y = y;
				Place.Max = Score - Begins;
				Max = Score - Begins;
				taken_by_piece = true;
			}
		}

	}//end of king condition
	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Queen~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (Piece == 'Q') {
		float Begins = Queen[x][y];
		float Score = 0;
		/////////////////////////////diagonal moves
		if (board[x + 1][y + 1] == 'e' || board[x + 1][y + 1] == 'r' || board[x + 1][y + 1] == 'n' || board[x + 1][y + 1] == 'p' || board[x + 1][y + 1] == 'q' || board[x + 1][y + 1] == 'b' || board[x + 1][y + 1] == 'k') {
			for (int i = x, j = y; i < 7 && j < 7; i++, j++) {
				float Score = Queen[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[i][j] >= 'A' && board[i][j] <= 'Z') break;
				if (Score > 5) break;
			}
		}

		if (board[x - 1][y + 1] == 'e' || board[x - 1][y + 1] == 'r' || board[x - 1][y + 1] == 'n' || board[x - 1][y + 1] == 'p' || board[x - 1][y + 1] == 'q' || board[x - 1][y + 1] == 'b' || board[x - 1][y + 1] == 'k') {
			for (int i = x, j = y; i >0 && j < 7; i--, j++) {
				float Score = Queen[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[i][j] >= 'A' && board[i][j] <= 'Z') break;
				if (Score > 5) break;
			}
		}

		if (board[x + 1][y - 1] == 'e' || board[x + 1][y - 1] == 'r' || board[x + 1][y - 1] == 'n' || board[x + 1][y - 1] == 'p' || board[x + 1][y - 1] == 'q' || board[x + 1][y - 1] == 'b' || board[x + 1][y - 1] == 'k') {
			for (int i = x, j = y; i <7 && j >0; i++, j--) {
				float Score = Queen[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[i][j] >= 'A' && board[i][j] <= 'Z') break;
				if (Score > 5) break;
			}
		}

		if (board[x - 1][y - 1] == 'e' || board[x - 1][y - 1] == 'r' || board[x - 1][y - 1] == 'n' || board[x - 1][y - 1] == 'p' || board[x - 1][y - 1] == 'q' || board[x - 1][y - 1] == 'b' || board[x - 1][y - 1] == 'k') {
			for (int i = x, j = y; i >0 && j >0; i--, j--) {
				float Score = Queen[i][j];
				if (board[i][j] == 'r') Score += 50;
				else if (board[i][j] == 'n')Score += 30;
				else if (board[i][j] == 'p')Score += 10;
				else if (board[i][j] == 'q')Score += 90;
				else if (board[i][j] == 'b')Score += 30;
				else if (board[i][j] == 'k')Score += 900;
				else if (board[i][j] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = j;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[i][j] >= 'A' && board[i][j] <= 'Z') break;
				if (Score > 5) break;
			}//end of loop
		}
		///////////////////////////////////////stright moves
		if (board[x + 1][y] == 'e' || board[x + 1][y] == 'r' || board[x + 1][y] == 'n' || board[x + 1][y] == 'p' || board[x + 1][y] == 'q' || board[x + 1][y] == 'b' || board[x + 1][y] == 'k') { //moving down
			for (int i = x + 1; i < 8; i++) {
				float Score = Queen[i][y];
				if (board[i][y] == 'r') Score += 50;
				else if (board[i][y] == 'n')Score += 30;
				else if (board[i][y] == 'p')Score += 10;
				else if (board[i][y] == 'q')Score += 90;
				else if (board[i][y] == 'b')Score += 30;
				else if (board[i][y] == 'k')Score += 900;
				else if (board[i][y] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = y;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[i][y] >= 'A' && board[i][y] <= 'Z') break;
				if (Score > 10) break;
			}
		}//end of down if

		if (board[x - 1][y] == 'e' || board[x - 1][y] == 'r' || board[x - 1][y] == 'n' || board[x - 1][y] == 'p' || board[x - 1][y] == 'q' || board[x - 1][y] == 'b' || board[x - 1][y] == 'k') { //moving up
			for (int i = x - 1; i > 1; i--) {
				float Score = Queen[i][y];
				if (board[i][y] == 'r') Score += 50;
				else if (board[i][y] == 'n')Score += 30;
				else if (board[i][y] == 'p')Score += 10;
				else if (board[i][y] == 'q')Score += 90;
				else if (board[i][y] == 'b')Score += 30;
				else if (board[i][y] == 'k')Score += 900;
				else if (board[i][y] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = i;
					Place.y = y;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[i][y] >= 'A' && board[i][y] <= 'Z') break;
				if (Score > 5) break;
			}
		}//end of up if

		if (board[x][y + 1] == 'e' || board[x][y + 1] == 'r' || board[x][y + 1] == 'n' || board[x][y + 1] == 'p' || board[x][y + 1] == 'q' || board[x][y + 1] == 'b' || board[x][y + 1] == 'k') { //moving up
			for (int i = y + 1; i < 8; i++) {
				float Score = Queen[x][i];
				if (board[x][i] == 'r') Score += 50;
				else if (board[x][i] == 'n')Score += 30;
				else if (board[x][i] == 'p')Score += 10;
				else if (board[x][i] == 'q')Score += 90;
				else if (board[x][i] == 'b')Score += 30;
				else if (board[x][i] == 'k')Score += 900;
				else if (board[x][i] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = x;
					Place.y = i;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[x][i] >= 'A' && board[x][i] <= 'Z') break;
				if (Score > 5) break;
			}
		}//end of right if

		if (board[x][y - 1] == 'e' || board[x][y - 1] == 'r' || board[x][y - 1] == 'n' || board[x][y - 1] == 'p' || board[x][y - 1] == 'q' || board[x][y - 1] == 'b' || board[x][y - 1] == 'k') { //moving up
			for (int i = y - 1; i > 1; i--) {
				float Score = Queen[x][i];
				if (board[x][i] == 'r') Score += 50;
				else if (board[x][i] == 'n')Score += 30;
				else if (board[x][i] == 'p')Score += 10;
				else if (board[x][i] == 'q')Score += 90;
				else if (board[x][i] == 'b')Score += 30;
				else if (board[x][i] == 'k')Score += 900;
				else if (board[x][i] == 'e')Score += 0.5;
				if (Score - Begins > Max) {
					Place.x = x;
					Place.y = i;
					Place.Max = Score - Begins;
					Max = Score - Begins;
					taken_by_piece = true;
				}
				if (board[x][i] >= 'A' && board[x][i] <= 'Z') break;
				if (Score > 5) break;
			}
		}//end of leftif

	}//end of if queen condition
	 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Knight~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	if (Piece == 'N') {
		float Begins = Knight[x][y];
		///To MAke two step right and one up
		if (x + 2<8 && y + 1<8 && (board[x + 2][y + 1] == 'e' || board[x + 2][y + 1] == 'r' || board[x + 2][y + 1] == 'n' || board[x + 2][y + 1] == 'p' || board[x + 2][y + 1] == 'q' ||
			board[x + 2][y + 1] == 'b' || board[x + 2][y + 1] == 'k'))
		{
			int a = x + 2, b = y + 1;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;
			}
		}
		if (x + 1<8 && y + 2<8 && (board[x + 1][y + 2] == 'e' || board[x + 1][y + 2] == 'r' || board[x + 1][y + 2] == 'n' || board[x + 1][y + 2] == 'p' || board[x + 1][y + 2] == 'q' ||
			board[x + 1][y + 2] == 'b' || board[x + 1][y + 2] == 'k'))
		{
			int a = x + 1, b = y + 2;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;

			}
		}
		if (x - 2>-1 && y + 1<8 && (board[x - 2][y + 1] == 'e' || board[x - 2][y + 1] == 'r' || board[x - 2][y + 1] == 'n' || board[x - 2][y + 1] == 'p' || board[x - 2][y + 1] == 'q' ||
			board[x - 2][y + 1] == 'b' || board[x - 2][y + 1] == 'k'))
		{
			int a = x - 2, b = y + 1;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;

			}
		}
		if (x - 1>-1 && y + 2<8 && (board[x - 1][y + 2] == 'e' || board[x - 1][y + 2] == 'r' || board[x - 1][y + 2] == 'n' || board[x - 1][y + 2] == 'p' || board[x - 1][y + 2] == 'q' || board[x - 1][y + 2] == 'b' || board[x - 1][y + 2] == 'k'))
		{
			int a = x - 1, b = y + 2;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;
			}
		}
		if (x + 2<8 && y - 1>-1 && (board[x + 2][y - 1] == 'e' || board[x + 2][y - 1] == 'r' || board[x + 2][y - 1] == 'n' || board[x + 2][y - 1] == 'p' || board[x + 2][y - 1] == 'q' || board[x + 2][y - 1] == 'b' || board[x + 2][y - 1] == 'k'))
		{
			int a = x + 2, b = y - 1;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;
			}
		}
		if (x + 1<8 && y - 2>-1 && (board[x + 1][y - 2] == 'e' || board[x + 1][y - 2] == 'r' || board[x + 1][y - 2] == 'n' || board[x + 1][y - 2] == 'p' || board[x + 1][y - 2] == 'q' ||
			board[x + 1][y - 2] == 'b' || board[x + 1][y - 2] == 'k'))
		{

			int a = x + 1, b = y - 2;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;
			}
		}
		if (x - 2>-1 && y - 1>-1 && (board[x - 2][y - 1] == 'e' || board[x - 2][y - 1] == 'r' || board[x - 2][y - 1] == 'n' || board[x - 2][y - 1] == 'p' || board[x - 2][y -
			1] == 'q' || board[x - 2][y - 1] == 'b' || board[x - 2][y - 1] == 'k'))
		{
			int a = x - 2, b = y - 1;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;
			}
		}
		if (x - 1>-1 && y - 2>-1 && (board[x - 2][y - 1] == 'e' || board[x - 2][y - 1] == 'r' || board[x - 2][y - 1] == 'n' || board[x - 2][y - 1] == 'p' || board[x - 2][y -
			1] == 'q' || board[x - 2][y - 1] == 'b' || board[x - 2][y - 1] == 'k'))
		{
			int a = x - 1, b = y - 2;
			float Score = Knight[a][b];
			if (board[a][b] == 'r')Score += 50;
			else if (board[a][b] == 'n')Score += 30;
			else if (board[a][b] == 'p')Score += 10;
			else if (board[a][b] == 'q')Score += 90;
			else if (board[a][b] == 'b')Score += 30;
			else if (board[a][b] == 'k')Score += 900;
			if (Score - Begins>Max) {
				Place.x = a;
				Place.y = b;
				Place.Max = Score - Begins;
				Max = Place.Max;
				taken_by_piece = true;
			}
		}
	}



	return Place;
}
//=========================================================================================================================//
void draw() {
	system("cls");
	char arr[8] = { 'A','B','C','D','E','F','G','H' };
	cout << "     ";
	for (int i = 0; i < 8; i++) cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << "   " << i + 1 << " ";
		for (int j = 0; j <8; j++) {
			if (board[i][j] == 'e') cout << "  ";
			else cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
//=========================================================================================================================//
void move() {

	char temp = board[y][col];
	if (board[y2][col2] == 'e') {
		board[y][col] = board[y2][col2];
	}
	else board[y][col] = 'e';
	board[y2][col2] = temp;

}
//=========================================================================================================================//
bool check_legal() {

	//translates user input
	if (x1 == 'a')col = 0;       else if (x1 == 'e')col = 4;
	else if (x1 == 'b')col = 1;  else if (x1 == 'f')col = 5;
	else if (x1 == 'c')col = 2;  else if (x1 == 'g')col = 6;
	else if (x1 == 'd')col = 3;  else if (x1 == 'h')col = 7;

	if (x2 == 'a')col2 = 0;      else if (x2 == 'e')col2 = 4;
	else if (x2 == 'b')col2 = 1; else if (x2 == 'f')col2 = 5;
	else if (x2 == 'c')col2 = 2; else if (x2 == 'g')col2 = 6;
	else if (x2 == 'd')col2 = 3; else if (x2 == 'h')col2 = 7;

	y = y - 1; y2 = y2 - 1;

	//checks if its opponent's piece
	if (board[y][col] >= 'A' && board[y][col] <= 'Z') return false;

	//valid range of numbers for destination index
	if (y > 8 || y < 0 || y2 > 8 || y2 < 0) return false;

	//checks that x is in range
	if (x1 <'a' || x1 >'h' || x2 < 'a' || x2 > 'h')
		return false;

	////////////////////////validating according to chess rules////////////////////////
	//if one of your peices is there
	string myPieces = "prnbkq";
	for (int i = 0; i < myPieces.size(); i++)
		if (board[y2][col2] == myPieces[i]) {
			return false;
		}
	//empty position
	if (board[y][col] == 'e')
		return false;

	//X AND Y DIFFERENCES
	int rowDiff = y - y2; // moving among the 1-8 list (rows)
	int colDiff = col2 - col; //int colDiff = col - col2; moving through a-h list (columns)

							  //~~~~~~~~~~~~~~~~~~~~~~~~PAWN RULES~~~~~~~~~~~~~~~~~~~~~~~~
	if (board[y][col] == 'p') {

		if (rowDiff == 2 && y == 6 && colDiff == 0) {
			if (board[y - 1][col] != 'e')
				return false;
			return true;
		}
		if (rowDiff == 2 && y != 6) return false;
		if (rowDiff != 1) return false;

		if (abs(colDiff) == 1 && abs(rowDiff) == 1) {
			string enemy = "PRNBKQ"; int cnt = 0;
			for (int i = 0; i < enemy.size(); i++) {
				if (board[y2][col2] == enemy[i]) cnt++;
			}
			if (cnt == 1) return true;
			else return false;
		}
		if (colDiff == 0 && abs(rowDiff) == 1 && board[y2][col2] != 'e') return false;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~KING RULES~~~~~~~~~~~~~~~~~~~~~~~~
	if (board[y][col] == 'k') {
		if (abs(rowDiff) > 1 || abs(colDiff) > 1) return false;

		else if (abs(rowDiff) == 1 || abs(rowDiff) == 0) {
			if (abs(colDiff) == 1 || abs(colDiff) == 0) {
				if (board[y2][col2] == 'e' || (board[y2][col2] >= 'A' && board[y2][col2] <= 'Z')) return true;
			}
		}
		else if (abs(rowDiff) == 1 && abs(colDiff) == 1)
			if (board[y2][col2] == 'e' || (board[y2][col2] >= 'A' && board[y2][col2] <= 'Z')) return true;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~QUEEN RULES~~~~~~~~~~~~~~~~~~~~~~~~
	if (board[y][col] == 'q') {
		//if they just try to move to some random spot
		if (abs(rowDiff) != abs(colDiff) && rowDiff != 0 && colDiff != 0) {
			return false;
		}
		/////////////////////////diagonal movements
		bool ok = true;
		if (rowDiff > 0 && colDiff > 0) {  //first quadrant
			int j = col + 1;
			for (int i = y - 1; i >= y2 && j <= col2; i--) {
				if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
					ok = false;
				}
				j++;
			}
			if (ok == true) return true; else return false;
		}
		if (rowDiff > 0 && colDiff < 0) {  //second quadrant
			int j = col - 1;
			for (int i = y - 1; i >= y2 && j >= col2; i--) {
				if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
					ok = false;
				}
				j--;
			}
			if (ok == true) return true; else return false;
		}
		if (rowDiff < 0 && colDiff < 0) {  //third quadrant
			int j = col - 1;
			for (int i = y + 1; i <= y2 && j >= col2; i++) {
				if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
					ok = false;
				}
				j--;
			}
			if (ok == true) return true; else return false;
		}
		if (rowDiff < 0 && colDiff > 0) {  //fourth quadrant
			int j = col + 1;
			for (int i = y + 1; i <= y2 && j <= col2; i++) {
				if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
					ok = false;
				}
				j++;
			}
			if (ok == true) return true; else return false;
		}
		////////////////////////striaght movements
		else if (rowDiff > 0 && colDiff == 0) { //up
			for (int i = y - 1; i >= y2; i--) {
				if (board[i][col] == 'r' || board[i][col] == 'n' || board[i][col] == 'p' || board[i][col] == 'q' || board[i][col] == 'b' || board[i][col] == 'k') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
		else if (rowDiff < 0 && colDiff == 0) { //down
			for (int i = y + 1; i <= y2; i++) {
				if (board[i][col] == 'r' || board[i][col] == 'n' || board[i][col] == 'p' || board[i][col] == 'q' || board[i][col] == 'b' || board[i][col] == 'k') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
		else if (rowDiff == 0 && colDiff > 0) { //right
			for (int i = col + 1; i <= col2; i++) {
				if (board[y][i] == 'r' || board[y][i] == 'n' || board[y][i] == 'p' || board[y][i] == 'q' || board[y][i] == 'b' || board[y][i] == 'k') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
		else if (rowDiff == 0 && colDiff < 0) { //left
			for (int i = col - 1; i >= col2; i--) {
				if (board[y][i] == 'r' || board[y][i] == 'n' || board[y][i] == 'p' || board[y][i] == 'q' || board[y][i] == 'b' || board[y][i] == 'k') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
		return true;
	}//end of main condition

	 //~~~~~~~~~~~~~~~~~~~~~~~~KNIGHT RULES~~~~~~~~~~~~~~~~~~~~~~~~
	if (board[y][col] == 'n') {
		if (abs(rowDiff)*abs(colDiff) != 2) {
			cout << "Knights can't move like that." << endl << endl;
			return false;
		}
		if (board[y2][col2] >= 'A' && board[y2][col2] <= 'Z') {
			return true;
		}
		string myPieces = "prnbkq";
		for (int i = 0; i < myPieces.size(); i++) {
			if (board[y2][col2] == myPieces[i])
				return false;
		}
		return true;
	}//end of main condition
	 //~~~~~~~~~~~~~~~~~~~~~~~~BISHOP RULES~~~~~~~~~~~~~~~~~~~~~~~~
	if (board[y][col] == 'b') {
		bool ok = true;
		//if they just try to move to some random spot
		if (abs(rowDiff) != abs(colDiff)) {
			return false;
		}
		else {
			if (rowDiff > 0 && colDiff > 0) {  //first quadrant
				int j = col + 1;
				for (int i = y - 1; i >= y2 && j <= col2; i--) {
					if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
						ok = false;
					}
					j++;
				}
				if (ok == true) return true; else return false;
			}
			else if (rowDiff > 0 && colDiff < 0) {  //second quadrant
				int j = col - 1;
				for (int i = y - 1; i >= y2 && j >= col2; i--) {
					if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
						ok = false;
					}
					j--;
				}
				if (ok == true) return true; else return false;
			}
			else if (rowDiff < 0 && colDiff < 0) {  //third quadrant
				int j = col - 1;
				for (int i = y + 1; i <= y2 && j >= col2; i++) {
					if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
						ok = false;
					}
					j--;
				}
				if (ok == true) return true; else return false;
			}
			else if (rowDiff < 0 && colDiff > 0) {  //fourth quadrant
				int j = col + 1;
				for (int i = y + 1; i <= y2 && j <= col2; i++) {
					if (board[i][j] == 'r' || board[i][j] == 'n' || board[i][j] == 'p' || board[i][j] == 'q' || board[i][j] == 'b' || board[i][j] == 'k') {
						ok = false;
					}
					j++;
				}
				if (ok == true) return true; else return false;
			}
		}//end else

	}//end of main condition
	 //~~~~~~~~~~~~~~~~~~~~~~~~ROCK RULES~~~~~~~~~~~~~~~~~~~~~~~~~~
	if (board[y][col] == 'r') {
		if (rowDiff != 0 && colDiff != 0) return false; //force moving stright in any direction

		else if (rowDiff > 0 && colDiff == 0) {//up
			for (int i = y - 1; i >= y2; i--) {
				if (board[i][col] != 'e') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}

		else if (rowDiff < 0 && colDiff == 0) { //down
			for (int i = y + 1; i <= y2; i++) {
				if (board[i][col] != 'e') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
		else if (rowDiff == 0 && colDiff > 0) { //right
			for (int i = col + 1; i <= col2; i++) {
				if (board[y][i] != 'e') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
		else if (rowDiff == 0 && colDiff < 0) { //left
			for (int i = col - 1; i >= col2; i--) {
				if (board[y][i] != 'e') {
					cout << "some peice is blocking your way!" << endl;
					return false;
				}
			}
		}
	}

	return true;
}
//=========================================================================================================================//
void arduino_fn(char x1, int y, char x2, int y2) { // i edited the x1 and x2 to char instead of an int 

	if (arduino.isConnected()) {
		string moves = "";
		y++; y2++;
		moves.push_back(x1); moves.push_back(y + '0'); moves.push_back(x2); moves.push_back(y2 + '0');

		char *c_string = new char[moves.size() + 1];
		for (int i = 0; i < moves.size(); i++)
			c_string[i] = moves[i];
        c_string[moves.size()] = '\n';
		
		arduino.writeSerialPort(c_string, MAX_DATA_LENGTH);

		//Sleep(5000);
		delete[] c_string; //delete[] attack;

	}
}
//=========================================================================================================================//
void arduino_fn_pc(int X1, int Y, int X2, int Y2) {

	if (arduino.isConnected()) {
		string moves = "";
		y  = X1 + '1';
		x1 = Y + 'a';
		x2 = Y2 + 'a';
		y2 = X2 + '1';
		cout << X1 << " " << Y << " " << X2 << " " << Y2 << endl;
		moves.push_back(x1 ); moves.push_back(y ); moves.push_back(x2 ); moves.push_back(y2 );

		char *c_string = new char[moves.size() + 1];
		for (int i = 0; i < moves.size(); i++)
			c_string[i] = moves[i];
		
		c_string[moves.size()] = '\n';
		cout << c_string << endl;
		Sleep(10000);
		
		arduino.writeSerialPort(c_string, MAX_DATA_LENGTH);

		//Sleep(5000);
		delete[] c_string;

	}
}
//=========================================================================================================================//
char winner() {
	int player1 = 0, player2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 'k') player2++;
			if (board[i][j] == 'K') player1++;
		}
	}
	if (player1 == 1 && player2 == 1) return 't';//tie
	if (player1 == 0 && player2 == 1) return 'u';//user
	if (player1 == 1 && player2 == 0) return 'p';//pc

}
//=========================================================================================================================//
int main() {

	cout << "  ####################" << endl;
	cout << "  # 1-Beginner level #" << endl;
	cout << "  ####################" << endl;
	cout << "  ####################" << endl;
	cout << "  # 2-Advanced level #" << endl;
	cout << "  ####################" << endl;
	int level; cin >> level;
	system("cls");

	/////////////////BEGINNER LEVEL///////////////////
	if (level == 1) {
		while (true) {
			draw();
			if (player == 2) {
				cout << "Role of player 2" << endl;
				cout << "please entre your move: ";
				bool valid;
				do {
					cin >> x1 >> y >> x2 >> y2;
					valid = check_legal();
					if (valid == true) {
						move();
						draw();
						arduino_fn(x1, y, x2, y2);
						player = 1;
						Sleep(10000);
					}
					else {
						cout << "Invalid! re-entre your move: ";
					}
				} while (valid == false);
			}
			
			if (player == 1) {
				cout << "Role of player 1" << endl;
				Coordinate Move, End;
				End.x = -1;
				End.y = -1;
				End.Max = -1000;
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						Coordinate temp = checking(board[i][j], i, j);
						if (temp.Max > End.Max)
						{
							End.x = temp.x;
							End.y = temp.y;
							End.Max = temp.Max;
							Move.x = i;
							Move.y = j;

						}
					}
				}
				if (taken_by_piece == false) {
					char temp = board[Move.x][Move.y];
					board[Move.x][Move.y] = board[End.x][End.y];
					board[End.x][End.y] = temp;
				}
				else {
					char temp = board[Move.x][Move.y];
					board[Move.x][Move.y] = 'e';
					board[End.x][End.y] = temp;
				}
				taken_by_piece = false;
				draw();
				cout << "pc is playing ";

				arduino_fn_pc(Move.x, Move.y, End.x, End.y);
				Sleep(10000);
				//cout << "this is the moves of the pc: " << Move.x << " " << Move.y << " " << End.x << " " << End.y << endl; Sleep(10000);
				player = 2;
				system("cls");
			}//end of player1

			 //////////checking if the game ended
			char win = winner();
			if (win == 't') continue;
			if (win == 'u') { cout << "congrats! player 2 is the winner!"; Sleep(10000); return 0; }
			if (win == 'p') { cout << "Hard luck! pc is the winner!"; Sleep(10000); return 0; }
		}//end of while true
	}//end of level 1
	 //Sleep(10000);
	 //system("pause");
	return 0;
}
