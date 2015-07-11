/**
 * Author: Min Hoo Lee
 * Date: 07-06-2015
 *
 * Tic Tac Toe Game
 * Player 1 uses 'X'
 * Player 2 uses 'O'
 */

#include <iostream>

int main()
{
	// Arrays for the tic tac toe board
	char board[3][3] = { { ' ', ' ', ' ' },
					     { ' ', ' ', ' ' },
					     { ' ', ' ', ' ' } };
	
	int row = 0;
	int col = 0;
	int game_num = 0;

	std::cout << "Welcome to the Tic Tac Toe Game!" << std::endl << std::endl;

	for (game_num = 0; game_num < 9; game_num++)
	{
		// Output game board
		std::cout << std::endl << "Game Board" << std::endl;
		std::cout << "----------" << std::endl;
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				std::cout << "| " << board[row][col];
			}
			std::cout << "|" << std::endl;
			std::cout << "----------" << std::endl;
		}

		// Label the board for the user to pick
		int square_index = 0;

		/**
		 *    -------------
		 * 	  | 1 | 2 | 3 |
		 *    -------------
		 *	  |	4 | 5 | 6 |
		 *    -------------
		 *    |	7 | 8 | 9 |
		 *    -------------
		 */
		std::cout << std::endl << "Labeled Board" << std::endl;
		std::cout << "----------" << std::endl;
		for (row = 0; row < 3; row++)
		{

			for (col = 0; col < 3; col++)
			{
				square_index++;
				std::cout << "| " << square_index;
			}
			std::cout << "|" << std::endl;
			std::cout << "----------" << std::endl;
		}

		char *current_player = "Player 1";
		if ((game_num % 2) == 1)
		{
			current_player = "Player 2";
		}

		// Prompt user for input
		std::cout << std::endl << current_player << " please pick the square to select." << std::endl << std::endl;
		std::cout << current_player << ": ";

		// Receive user input
		std::cin >> square_index;

		// Decrement index for array index
		square_index--;

		if ((square_index >= 3) && (square_index < 6))
		{
			row = 1;
			col = square_index - 3;
		}
		
		else if ((square_index >= 6) && (square_index < 9))
		{
			row = 2;
			col = square_index - 6;
		}

		else
		{
			row = 0;
			col = square_index;
		}

		if ((game_num % 2) == 1)
			board[row][col] = 'O';
		else
			board[row][col] = 'X';

		/**
		 *    -------------
		 * 	  | X | O | X |
	 	 *    -------------
 		 *	  |	X | O | X |
		 *    -------------
		 *    |	X | O | X |
		 *    -------------
		 */

		// Check vertical rows (3 cases)
		for (col = 0; col < 3; col++)
		{
			if ((board[0][col] == board[1][col]) && (board[0][col] == board[2][col]))
			{
				if (board[0][col] == 'X')
				{
					std::cout << std::endl << "Player 1 wins!" << std::endl;
					game_num = 9;
				}

				else if (board[0][col] == 'O')
				{
					std::cout << std::endl << "Player 2 wins!" << std::endl;
					game_num = 9;
				}
			}
		}

		/**
		 *    -------------
		 * 	  | X | X | X |
		 *    -------------
		 *	  |	O | O | O |
		 *    -------------
		 *    |	X | X | X |
		 *    -------------
		 */
		// Check horizontal rows (3 cases)
		for (row = 0; row < 3; row++)
		{
			if ((board[row][0] == board[row][1]) && (board[row][0] == board[row][2]))
			{
				if (board[row][0] == 'X')
				{
					std::cout << std::endl << "Player 1 wins!" << std::endl;
					game_num = 9;
				}

				else if (board[row][0] == 'O')
				{
					std::cout << std::endl << "Player 2 wins!" << std::endl;
					game_num = 9;
				}
			}
		}

		/**
		 *    -------------
		 * 	  | X |   |   |
		 *    -------------
		 *	  |	  | X |   |
		 *    -------------
		 *    |	  |   | X |
		 *    -------------
		 */
		// Check diagonals (2 cases)
		int i = 0;
		if ((board[i][i] == board[i + 1][i + 1]) && (board[i][i] == board[i + 2][i + 2]))
		{
			if (board[i][i] == 'X')
			{
				std::cout << std::endl << "Player 1 wins!" << std::endl;
				game_num = 9;
			}

			else if (board[i][i] == 'O')
			{
				std::cout << std::endl << "Player 2 wins!" << std::endl;
				game_num = 9;
			}
		}

		/**
		 *    -------------
		 * 	  |   |   | O |
		 *    -------------
		 *	  |	  | O |   |
		 *    -------------
		 *    |	O |   |   |
		 *    -------------
		 */
		if ((board[i + 2][i] == board[i + 1][i + 1]) && (board[i + 2][i] == board[i][i + 2]))
		{
			if (board[i + 2][i] == 'X')
			{
				std::cout << std::endl << "Player 1 wins!" << std::endl;
				game_num = 9;
			}

			else if (board[i + 2][i] == 'O')
			{
				std::cout << std::endl << "Player 2 wins!" << std::endl;
				game_num = 9;
			}
		}
	} 

	// Output game board
	std::cout << std::endl << "Game Board" << std::endl;
	std::cout << "----------" << std::endl;
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			std::cout << "| " << board[row][col];
		}
		std::cout << "|" << std::endl;
		std::cout << "----------" << std::endl;
	}

	// Tie game, achieved naturally in loop
	if (game_num == 8)
	std::cout << std::endl << "Tie Game! Cat's Cradle!" << std::endl;

	return 0; 
}
