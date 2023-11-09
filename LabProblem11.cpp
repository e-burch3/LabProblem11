/*
*	File:			LabProblem11.cpp
*	Author:			Ethan Burch
* 
*	Date:			11/9/2023
*	Description:	Allows a person to reserve a seat on a CRJ 200 jet airplane
*/

#include <iostream>
#include <string>

using namespace std;
 

// constants

const int ROWS = 13;
const int COLUMNS = 4;
const int ERROR = 100;
// function prototypes

int findRowIndex(int thisRow);
int findSeatIndex(char thisSeat);
void displaySeatColumn(char seats[][ROWS], int column);

void setSeats(char seats[COLUMNS][ROWS]);
void displaySeatChart(char seats[][ROWS]);
int getRow(string str);
char getColumn(string str);
void getSeat(char seats[][ROWS], string str);

int main(void) {
	string input;

	   
	char seat[COLUMNS][ROWS];
	setSeats(seat);

	
	while (true) {
		cout << endl;
		displaySeatChart(seat);

		cout << "\nEnter a seat or Q to quit: ";
		cin >> input;
		if (input == "Q" || input == "q")
			break;
		getSeat(seat, input);

	}
	
	
}
   


int findRowIndex(int thisRow) {
	if (thisRow > 13 || thisRow < 0) {
		return ERROR;
	}
	else
		return thisRow - 1;
}

int findSeatIndex(char thisSeat) {
	if (thisSeat == 'A')
		return 3;
	else if (thisSeat == 'B')
		return 2;
	else if (thisSeat == 'C')
		return 1;
	else if (thisSeat == 'D') 
		return 0;
	else
		return ERROR;
}

void displaySeatColumn(char seats[][ROWS], int column) {
	for (int row = 0; row < ROWS; row++) {
		cout << seats[column][row] << ' ';
	}
	cout << endl;
}

void setSeats(char seats[COLUMNS][ROWS]) {
	for (int column = 0; column < COLUMNS; column++) {
		for (int row = 0; row < ROWS; row++) {
			switch (column) {
			case 0: 
				if (row == ROWS - 1)
					seats[column][row] = ' ';
				else
					seats[column][row] = 'D';
				break;
			case 1:
				if (row == ROWS - 1)
					seats[column][row] = ' ';
				else
					seats[column][row] = 'C';
				break;
			case 2:
				seats[column][row] = 'B';
				break;
			case 3:
				seats[column][row] = 'A';
				break;
			}
		}
	}
}

void displaySeatChart(char seats[][ROWS]) {
	for (int column = 0; column < COLUMNS + 4; column++) {
		switch (column) {
		case 0:
		case 1:
			displaySeatColumn(seats, column);
			break;

		case 6:
		case 7:
			displaySeatColumn(seats, column - 4);
			break;

		case 2:
		case 5:
			for (int i = 0; i < ROWS; i++)
				cout << "  ";
			cout << endl;
			break;

		case 3:
			for (int i = 0; i < ROWS; i++) {
				if (i / 10 || i == 9)
					cout << "1 ";
				else
					cout << "  ";
			}
			cout << endl;
			break;

		case 4:
			for (int i = 0; i <= ROWS; i++) {
				if (i < 9)
					cout << i + 1 << ' ';
				else if (i == 9)
					cout << "0 ";
				else if (i == 10)
					continue;
				else
					cout << i % 10 << ' ';
			}
			cout << endl;
			break;
		}
	}
}

int getRow(string str) {
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 48 && str[i] <= 57)
			num += (str[i] - 48) * pow(10, str.length() - i - 2 );
		else
			continue;
	}
	return num;
}


char getColumn(string str) {
	char letter = '0';
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			letter = str[i];
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			letter = str[i] - 32;
		}
		else {
			continue;
		}
	}
	return letter;
}

void getSeat(char seats[][ROWS], string str) {
	int row, column;
	
	row = findRowIndex(getRow(str));
	column = findSeatIndex(getColumn(str));

	if (row == 100 || column == 100) {
		cout << "Sorry, no such seat exists on the CRJ 200.\n";
		return;
	}
	else if (row == 12 && column == 0 || row == 12 && column == 1) {
		cout << "Sorry, no such seat exists on the CRJ 200.\n";
		return;
	}
	else if (seats[row][column] == 'X') {
		cout << "Sorry, seat already taken.\n";
		return;
	}
	else {
		seats[column][row] = 'X';
		return;
	}
}