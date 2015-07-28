#include "card.hpp"
#include <iostream>

int shuffleDeck()
{
	card deckOfCards[52];

	for (int i = 0; i < 13; i++)
	{
		deckOfCards[i].value = i + 2;
		deckOfCards[i].suit = 'S';
	}
	for (int i = 0; i < 13; i++)
	{
		deckOfCards[i + 13].value = i + 2;
		deckOfCards[i + 13].suit = 'D';
	}
	for (int i = 0; i < 13; i++)
	{
		deckOfCards[i + 26].value = i + 2;
		deckOfCards[i + 26].suit = 'C';
	}
	for (int i = 0; i < 13; i++)
	{
		deckOfCards[i + 39].value = i + 2;
		deckOfCards[i + 39].suit = 'H';
	}
	shuffle(deckOfCards, 52);

	card player1Hand[5];
	card player2Hand[5];

	int topCard = 0;

	int p1Size = 0;
	int p2Size = 0;

	for (int i = 0; i < 5; i++)
	{
		player1Hand[i] = deckOfCards[topCard];
		topCard++;
		p1Size++;

		player2Hand[i] = deckOfCards[topCard];
		topCard++;
		p2Size++;
	}


	cout << "Player 1's Hand" << endl;
	for (int i = 0; i < p1Size; i++)
	{
		cout << player1Hand[i].displayCard();
	}
	cout << endl << "Player 2's Hand" << endl;
	for (int i = 0; i < p2Size; i++)
	{
		cout << player2Hand[i].displayCard();
	}

	int p1Score = 0;
	for (int i = 0; i < p1Size; i++)
	{
		p1Score += player1Hand[i].value;
	}

	int p2Score = 0;
	for (int i = 0; i < p2Size; i++)
	{
		p2Score += player2Hand[i].value;
	}

	if (p1Score > p2Score)
		cout << endl << "Player 1 wins!" << endl;
	if (p2Score > p1Score)
		cout << endl << "Player 2 wins!" << endl;
	if (p1Score == p2Score)
		cout << endl << "Its a tie" << endl;

	return 0;
}