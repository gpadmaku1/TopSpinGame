#include<iostream>
#include "CircularDoublyLinkedList.h"
#include "TopSpin.h"
#include <ctime>
#include <cstdlib>

using namespace std;

//RandomizePuzzle with a random number of moves, calls both ShiftLeft and Spin functions
void randomizePuzzle(int numbOfMoves, TopSpin &TopSpinObj1) {
	for (int i = 0; i < numbOfMoves; i++)
	{
		int random = (rand() % 19) + 1;
		for (int j = 0; j < random; j++)
		{
			TopSpinObj1.shiftLeft();
		}
		TopSpinObj1.spin();
	}
}

int main()
{
	//Create TopSpin object
	TopSpin TopSpinObject(20,4);

	srand(time(NULL));

	//Number of moves to initalize the puzzle with

	int numOfMoves;
	cout << "How many moves would you like to initialize the puzzle with? ";
	cin >> numOfMoves;

	//Created a function to randomize the puzzle with a random number of shiftLeft function calls and a spin

	randomizePuzzle(numOfMoves, TopSpinObject);

	//Prints the object through the overloaded ostream operator

	cout << TopSpinObject << endl;


	//While loop that runs till the user selects Quit or Wins the game
	while (true)
	{
		cout << endl << "Please choose from the following options enter your choice by entering the corresponding " <<
			"number: " << endl;
		cout << endl << "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		int optionNumber;
		cout << endl << "Your choice: ";
		cin >> optionNumber;
		cout << endl;
		//Switch statement for the user options to Shift, Spin or Quit
		switch (optionNumber)
		{
		case 1:
		{
			int numOfShifts;
			cout << "Enter number of shifts: ";
			cin >> numOfShifts;
			cout << endl << "1. Shift right\n";
			cout << "2. Shift left\n";
			cout << endl << "Your choice: ";
			int shiftOption;
			cin >> shiftOption;

			//Nested switch statement for user options to Shift Left or Shift Right
			switch (shiftOption)
			{
			case 1:
			{
				for (int i = 0; i < numOfShifts; i++)
				{
					TopSpinObject.shiftRight();
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < numOfShifts; i++)
				{
					TopSpinObject.shiftLeft();
				}
				break;
			}
			}
			break;
		}
		case 2:
		{
			TopSpinObject.spin();
			break;
		}
		case 3:
		{
			return 0;
		}
		}

		cout << TopSpinObject << endl;

		//If statement that continuously checks if the puzzle is solved
		if (TopSpinObject.isSolved())
		{
			cout << "Congratulations! You solved the puzzle. \n";
			break;
			return 0;
		}

	} //While loop ends here
	return 0;
}