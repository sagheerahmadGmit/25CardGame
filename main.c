//C 25 Game Project 2018 - Sagheer Ahmad 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

//method used to randomize cards
void cardDraw(char decision);

// Declaring Global Variables - card arrays
char *suits[4] = { "spades","clubs","diamonds","hearts" };
int ranks[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

//variables to save and load game
FILE * loadGame;
FILE * saveGame;

//main method
void main()
{
	//Declaration and initialisation of variables
	//int variables
	int players, start, load;
	//FILE * loadGame;
	//FILE * saveGame;
	int n = 13;
	int i, j;
	int player1num = 0, player2num = 0, player3num = 0, player4num = 0, player5num = 0, player6num = 0;
	int numplayer1 = 0, numplayer2 = 0, numplayer3 = 0, numplayer4 = 0, numplayer5 = 0, numplayer6 = 0;
	int player1 = 0;
	int player2 = 0;
	int player3 = 0;
	int player4 = 0;
	int player5 = 0;
	int player6 = 0;
	int cardNum;
	int trumpNum;
	int random;

	// char variables
	int numbers[7];
	char trumpSuit;
	char initStart;
	char filegame;
	char choice;
	char randomSuit = "";
	char newGame;
	char temp[52];
	char suit;

	//declaring file pointers
	loadGame = fopen("saveGame.txt", "r");
	saveGame = fopen("saveGame.txt", "w");

	printf("Welcome to 25!!! \n\n");

	//printing out the game rules
	//Game Rules for trump suits
	printf("Trump Suits\n");
	printf("-----------\n");
	printf("5H, JH, AH, KH, QH, 10H,  9H, 8H, 7H, 6H, 4H, 3H, 2H, \n");
	printf("5D, JD, AH, AD, KD,  QD, 10D, 9D  8D, 7D, 6D, 4D, 3D,  2D, \n");
	printf("5C, JC, AH, AC, KC,  QC,  2C, 3C, 4C, 6C, 7C, 8C, 9C, 10C, \n");
	printf("5S, JS, AH, AS, KS,  QS,  2S, 3S, 4S, 6S, 7S, 8S, 9S, 10S\n\n");

	// game rules for non trump suits
	printf("Non - Trump Suits\n");
	printf("-----------------\n");
	printf("KH, QH, JH, 10H, 9H, 8H, 7H, 6H, 5H, 4H, 3H, 2H, KD, QD\n");
	printf("JD, 10D, 9D, 8D, 7D, 6D 5D, 4D, 3D, 2D, AD, \nKC, QC, JC\n");
	printf("AC, 2C, 3C, 4C, 5C, 6C, 7C, 8C, 9C, 10C, \nKS, QS, QS\n");
	printf("JS, AS, 2S, 3S, 4S, 5S, 6S, 7S, 8S, 9S, 10S\n\n");

	// Input for the amount of players
	do {
		printf("Please enter 1 to start a new game or 2 load the previous game: ");
		scanf("%d", &start);
	} while (start < 1 || start > 2);//do while to make sure proper input is taken

	if (start == 1)//if 1 is entered create a new game
	{
		do {
			printf("\nPlease enter the number of players (From 2 up to 6): ");
			scanf("%d", &players);
		} while (players < 2 || players > 6);//making sure there only 2 to 6 players

		//printf("\nThe number of players entered is %d \n", players);

		//randomizing the array and picking a trump card
		random = rand() % 13;
		randomSuit = rand() % 4;
		ranks[random];
		suits[randomSuit];
		printf("\nThe Trump card is: %d of %s", ranks[random], suits[randomSuit]);
		//cardDraw('e');
		printf("\n");

		//depending on the trump card use the following if statements
		if (suits[randomSuit] == "hearts")
		{
			printf("\n\nThe Trump card is a HEART - Please use the following numbers\n");
			printf("------------------------------------------------------------");
			printf("\n5H - 52 || JH - 51 || AH - 50   || KH - 49 || QH - 48  || 10H - 47 || 9H - 46  || 8H - 45 || 7H - 44 || 6H - 43 || 5H - 42 || 4H - 41\n");
			printf("3H - 40   || 2H - 39 || KS - 38   || QS - 37 || JS - 36  || AS - 35  || 2S - 34  || 3S - 33 || 4S - 32 || 5S - 31 || 6S - 30 || 7S - 29\n");
			printf("8S - 28   || 9S - 27 || 10S - 26  || KD - 38 || QD - 37  || JD - 36 || 10D - 35 || 9D - 34 || 8D - 33 || 7D - 32 || 6D - 31 || 5D - 30\n");
			printf("4D - 29   || 3D - 28 || 2D - 27   || KC - 38 || QC - 37   || JC - 36 || AC - 35  || 2C - 34 || 3C - 33  || 4C - 32 || 5C - 31 || 6C - 30\n");
			printf("7C - 29   || 8C - 28 || 9C - 27   || 10C - 26 \n");
		}// trump card is a heart
		else if (suits[randomSuit] == "spades")
		{
			printf("\n\nThe Trump card is a SPADE - Please use the following numbers\n");
			printf("------------------------------------------------------------");
			printf("\n5S - 52 || JS - 51  || AH - 50 || AS - 49 || KS - 48 || QS - 47  || 2S - 46  || 3S - 45 || 4S - 46 || 6S - 45 || 7S - 44 || 8S - 43\n");
			printf("9S - 42 || 10S - 41 || KH - 40 || QH - 39 || JH - 38 || 10H - 37 || 9H - 36  || 8H - 35 || 7H - 34 || 6H - 33 || 6H - 32 || 5H - 31\n");
			printf("4H - 30 || 3H - 29  || 2H - 28 || KD - 40 || QD - 39 || JD - 38  || 10D - 37 || 9D - 36 || 8D - 35 || 7D - 34 || 6D - 33 || 6D - 32\n");
			printf("4D - 30 || 3D - 29  || 2D - 28 || KC - 40 || QC - 39 || JC - 38  || AC - 37  || 2C - 36 || 3C - 35 || 4C - 34 || 5C - 33 || 6C - 32\n");
			printf("7C - 30 || 8C - 29  || 9C - 28 || 10C - 27 \n");
		}//trump card is a spade
		else if (suits[randomSuit] == "clubs")
		{
			printf("\n\nThe Trump card is a CLUB - Please use the following numbers\n");
			printf("------------------------------------------------------------");
			printf("\n5C - 52 || JS - 51  || AH - 50 || AC - 49 || KC - 48 || QC - 47  || 2C - 46  || 3C - 45 || 4C - 46 || 6C - 45 || 7C - 44 || 8C - 43\n");
			printf("9C - 42 || 10C - 41 || KH - 40 || QH - 39 || JH - 38 || 10H - 37 || 9H - 36  || 8H - 35 || 7H - 34 || 6H - 33 || 6H - 32 || 5H - 31\n");
			printf("4H - 30 || 3H - 29  || 2H - 28 || KD - 40 || QD - 39 || JD - 38  || 10D - 37 || 9D - 36 || 8D - 35 || 7D - 34 || 6D - 33 || 6D - 32\n");
			printf("4D - 30 || 3D - 29  || 2D - 28 || KS - 40 || QS - 39 || JS - 38  || AS - 37  || 2S - 36 || 3S - 35 || 4S - 34 || 5S - 33 || 6S - 32\n");
			printf("7S - 30 || 8S - 29  || 9S - 28 || 10S - 27 \n");
		}//trump card is a club
		else
		{
			printf("\n\nIf the Trump card is a DIAMOND - Please use the following numbers\n");
			printf("------------------------------------------------------------");
			printf("\n5D - 52 || JD - 51  || AH - 50  || AD - 49  || 10D - 48 || 9D - 47  || 8D - 46 || 7D - 45 || 6D - 44 || 5D - 43 || 4D - 42 || 3D - 41\n");
			printf("2D - 40 || KS - 40  || QS - 39  || JS - 38  || AS - 37  || 2S - 36  || 3S - 35 || 4S - 34 || 5S - 33 || 6S - 31 || 7S - 30 || 8S - 29\n");
			printf("9S - 28 || 10S - 27 || KD - 40  || QD - 39  || JD - 38  || 10D - 37 || 9D - 36 || 8D - 35 || 7D - 34 || 6D - 33 || 5D - 32 || 4D - 30\n");
			printf("3D - 29 || 2D - 28  || KC - 40  || QC - 39  || JC - 38  || AC - 37  || 2C - 36 || 3C - 3  || 4C - 34 || 5C - 33 || 6C - 32 || 7C - 30\n");
			printf("8C - 29 || 9C - 28  || 10C - 27 \n\n");
		}//trump card is a diamond

		// using for loops to output the randomized cards
		for (int j = 1; j <= players; j++)
		{
			printf("\nPlayer %d: \n\n", j);
			for (int i = 0; i < 5; i++)
			{
				//card draw function called
				cardDraw('e');
			}
			printf("\n");
		}

		//depending on players run following statements
		if (players == 2)
			{
				printf("-------------------\n");

				//players enter there card numbers
				do
				{
					printf("Player 1 please play a card using the table above: ");
					scanf("%d", &player1num);
					printf("\n");

					printf("Player 2 please play a card using the table above: ");
					scanf("%d", &player2num);
					printf("\n");
				} while (player1num < 27 && player1num > 52 || player2num < 27 && player2num > 52);

				//save the card to an array
				numbers[1] = player1num;
				numbers[2] = player2num;

				// check to see who wins and output results
				if (player1num > player2num)
				{
					player1 += 5;
					printf("Player one won that round!!\n");
					printf("Player 1 has %d points\n", player1);
				}
				else
				{
					player2 += 5;
					printf("Player two won that round!!\n");
					printf("Player 2 has %d points\n", player2);
				}
			}

		if (players == 3)
		{
			printf("-------------------\n");

			//ask players to enter there card numbers

			printf("Player 1 please play a card using the table above: ");
			scanf("%d", &player1num);
			printf("\n");

			printf("Player 2 please play a card using the table above: ");
			scanf("%d", &player2num);
			printf("\n");

			printf("Player 3 please play a card using the table above: ");
			scanf("%d", &player3num);
			printf("\n");

			//save the numbers to an array
			numbers[1] = player1num;
			numbers[2] = player2num;
			numbers[3] = player3num;

			// compare all numbers and decide who wins and print out the results
			if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
			{
				player1 += 5;
				printf("Player one won that round!!\n");
				printf("Player 1 has %d points\n", player1);
			}//p1 won
			else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
			{
				player2 += 5;
				printf("Player two won that round!!\n");
				printf("Player 2 has %d points\n", player2);
			}//p2 won
			else
			{
				player3 += 5;
				printf("Player four won that round!!\n");
				printf("Player 3 has %d points\n", player3);
			}//p3 won
		}

		if (players == 4)
		{
			
			printf("-------------------\n");

			// input card numbers
			printf("Player 1 please play a card using the table above: ");
			scanf("%d", &player1num);
			printf("\n");

			printf("Player 2 please play a card using the table above: ");
			scanf("%d", &player2num);
			printf("\n");

			printf("Player 3 please play a card using the table above: ");
			scanf("%d", &player3num);
			printf("\n");

			printf("Player 4 please play a card using the table above: ");
			scanf("%d", &player4num);
			printf("\n");

			// save the numbers to an array
			numbers[1] = player1num;
			numbers[2] = player2num;
			numbers[3] = player3num;
			numbers[4] = player4num;

			// compare and output the winner
			if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
			{
				player1 += 5;
				printf("Player one won that round!!\n");
				printf("Player 1 has %d points\n", player1);
			}//p1 won
			else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
			{
				player2 += 5;
				printf("Player two won that round!!\n");
				printf("Player 2 has %d points\n", player2);
			}//p2 won
			else if (player3num > player1num && player3num > player2num && player3num > player4num && player3num > player5num)
			{
				player3 += 5;
				printf("Player three won that round!!\n");
				printf("Player 3 has %d points\n", player3);
			}//p3 won
			else
			{
				player4 += 5;
				printf("Player four won that round!!\n");
				printf("Player 4 has %d points\n", player4);
			}//p4 won
		}

		if (players == 5)
		{
			printf("-------------------\n");

			//players enter the card numbers
			printf("Player 1 please play a card using the table above: ");
			scanf("%d", &player1num);
			printf("\n");

			printf("Player 2 please play a card using the table above: ");
			scanf("%d", &player2num);
			printf("\n");

			printf("Player 3 please play a card using the table above: ");
			scanf("%d", &player3num);
			printf("\n");

			printf("Player 4 please play a card using the table above: ");
			scanf("%d", &player4num);
			printf("\n");

			printf("Player 5 please play a card using the table above: ");
			scanf("%d", &player5num);
			printf("\n");

			//numbers saved to an array
			numbers[1] = player1num;
			numbers[2] = player2num;
			numbers[3] = player3num;
			numbers[4] = player4num;
			numbers[5] = player5num;

			// compare and output the winners
			if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
			{
				player1 += 5;
				printf("Player one won that round!!\n");
				printf("Player 1 has %d points\n", player1);
			}//p1 won
			else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
			{
				player2 += 5;
				printf("Player two won that round!!\n");
				printf("Player 2 has %d points\n", player2);
			}//p2 won
			else if (player3num > player1num && player3num > player2num && player3num > player4num && player3num > player5num)
			{
				player3 += 5;
				printf("Player three won that round!!\n");
				printf("Player 3 has %d points\n", player3);
			}//p3 won
			else if (player4num > player1num && player4num > player2num && player4num > player3num && player4num > player5num)
			{
				player4 += 5;
				printf("Player four won that round!!\n");
				printf("Player 4 has %d points\n", player4);
			}//p4 won
			else if (player5num > player1num && player5num > player2num && player5num > player3num && player5num > player4num)
			{
				player5 += 5;
				printf("Player five won that round!!\n");
				printf("Player 5 has %d points\n", player5);
			}//p5 won
		}

		if (players == 6)
		{
			printf("-------------------\n");


			// ask for player card numbers
			printf("Player 1 please play a card using the table above: ");
			scanf("%d", &player1num);
			printf("\n");

			printf("Player 2 please play a card using the table above: ");
			scanf("%d", &player2num);
			printf("\n");

			printf("Player 3 please play a card using the table above: ");
			scanf("%d", &player3num);
			printf("\n");

			printf("Player 4 please play a card using the table above: ");
			scanf("%d", &player4num);
			printf("\n");

			printf("Player 5 please play a card using the table above: ");
			scanf("%d", &player5num);
			printf("\n");

			printf("Player 6 please play a card using the table above: ");
			scanf("%d", &player6num);
			printf("\n");

			// save to an array
			numbers[1] = player1num;
			numbers[2] = player2num;
			numbers[3] = player3num;
			numbers[4] = player4num;
			numbers[5] = player5num;
			numbers[6] = player6num;

			// compare and output the winner
			if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
			{
				player1 += 5;
				printf("Player one won that round!!\n");
				printf("Player 1 has %d points\n", player1);
			}//p1 won
			else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
			{
				player2 += 5;
				printf("Player two won that round!!\n");
				printf("Player 2 has %d points\n", player2);
			}//p2 won
			else if (player3num > player1num && player3num > player2num && player3num > player4num && player3num > player5num)
			{
				player3 += 5;
				printf("Player three won that round!!\n");
				printf("Player 3 has %d points\n", player3);
			}//p3 won
			else if (player4num > player1num && player4num > player2num && player4num > player3num && player4num > player5num)
			{
				player4 += 5;
				printf("Player four won that round!!\n");
				printf("Player 4 has %d points\n", player4);
			}//p4 won
			else if (player5num > player1num && player5num > player2num && player5num > player3num && player5num > player4num)
			{
				player5 += 5;
				printf("Player five won that round!!\n");
				printf("Player 5 has %d points\n", player5);
			}//p5 won
			else
			{
				player6 += 5;
				printf("Player six won that round!!\n");
				printf("Player 6 has %d points\n", player6);
			}//p6 won
		}
		
		// ask user what to do next
		printf("\nEnter c to play next round, s to save game or e to exit or to reshuffle cards: ");
		scanf("%s", &choice);

		do
		{
			//choice is e so exit the game
			if (choice == 'r')
			{
				for (int j = 1; j <= players; j++)
				{
					printf("\nPlayer %d: \n\n", j);
					for (int i = 0; i < 5; i++)
					{
						//card draw function called
						cardDraw('e');
					}
					printf("\n");

					printf("The Trump card is still: %d of %s", ranks[random], suits[randomSuit]);


				}
			}
			else if (choice == 'e')
			{
				//exit(12);
				//ask user to confirm exit or start a new game
				printf("\n\nPlease enter e to confirm exit or n to start a new game!!");
				scanf("%s", &newGame);

				// enter n for a new game
				if (newGame == 'n' || newGame == 'N')
				{
					printf("\n");
					//re run the entire game
					main();
				}
				else
				{
					// exit the application
					printf("Thank you for playing 25!!\n\n");
					exit(2);
				}

			}
			else if (choice == 'c' || choice == 'C')//choice is c so play next round
			{
				//depending on players using the following if statement
				if (players == 2)
				{
					printf("-------------------\n");

					//remind user to enter different cards each round
					printf("Please enter different cards this time \n\n");

					printf("Player 1 please play a card using the table above: ");
					scanf("%d", &player1num);
					printf("\n");

					// if the numbers have already been entered then ask for input again
					if (player1num == numbers[1] || player1num == numbers[2])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 1 please play a card using the table above: ");
						scanf("%d", &player1num);
						printf("\n");
					}

					//save the new card played to the array
					numbers[1] = player1num;

					//player 2 input
					printf("Player 2 please play a card using the table above: ");
					scanf("%d", &player2num);
					printf("\n");

					//check if numbers already entered or not
					if (player2num == numbers[2] || player2num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player2num);
						printf("\n");
					}

					//save new card played to the array
					numbers[2] = player2num;

					//check to see the winner and output it
					if (player1num > player2num)
					{
						player1 += 5;
						printf("Player one won that round!!\n");
						printf("Player 1 has %d points\n", player1);
					}
					else
					{
						player2 += 5;
						printf("Player two won that round!!\n");
						printf("Player 2 has %d points\n", player2);
					}
				}

				if (players == 3)
				{
					printf("-------------------\n");

					printf("Please enter different cards this time \n\n");

					// ask player 1 for input
					printf("Player 1 please play a card using the table above: ");
					scanf("%d", &player1num);
					printf("\n");

					// if card is already entered ask for input again
					if (player1num == numbers[1] || player1num == numbers[2] || player1num == numbers[3])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 1 please play a card using the table above: ");
						scanf("%d", &player1num);
						printf("\n");
					}

					numbers[1] = player1num;

					printf("Player 2 please play a card using the table above: ");
					scanf("%d", &player2num);
					printf("\n");

					// if card is already entered ask for input again
					if (player2num == numbers[2] || player2num == numbers[3] || player2num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player2num);
						printf("\n");
					}

					//save input to an array
					numbers[2] = player2num;

					printf("Player 3 please play a card using the table above: ");
					scanf("%d", &player3num);
					printf("\n");

					// if card is already entered ask for input again
					if (player3num == numbers[3] || player3num == numbers[2] || player3num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player3num);
						printf("\n");
					}

					//save the players card to the array
					numbers[3] = player3num;

					//compare the players cards and print out a winner
					if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
					{
						player1 += 5;
						printf("Player one won that round!!\n");
						printf("Player 1 has %d points\n", player1);
					}
					else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
					{
						player2 += 5;
						printf("Player two won that round!!\n");
						printf("Player 2 has %d points\n", player2);
					}
					else
					{
						player3 += 5;
						printf("Player four won that round!!\n");
						printf("Player 3 has %d points\n", player3);
					}
				}

				if (players == 4)
				{
					printf("-------------------\n");

					printf("Please enter different cards this time \n\n");

					//ask for the input 
					printf("Player 1 please play a card using the table above: ");
					scanf("%d", &player1num);
					printf("\n");

					// if card is already entered ask for input again
					if (player1num == numbers[1] || player1num == numbers[2] || player1num == numbers[3] || player1num == numbers[4])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 1 please play a card using the table above: ");
						scanf("%d", &player1num);
						printf("\n");
					}

					// save the card played to an array 
					numbers[1] = player1num;

					printf("Player 2 please play a card using the table above: ");
					scanf("%d", &player2num);
					printf("\n");

					// if card is already entered ask for input again
					if (player2num == numbers[2] || player2num == numbers[3] || player2num == numbers[1] || player2num == numbers[4])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player2num);
						printf("\n");
					}

					//save the card played to an array
					numbers[2] = player2num;

					printf("Player 3 please play a card using the table above: ");
					scanf("%d", &player3num);
					printf("\n");

					// if card is already entered ask for input again
					if (player3num == numbers[3] || player3num == numbers[4] || player3num == numbers[2] || player3num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player3num);
						printf("\n");
					}

					//save the card played to an array
					numbers[3] = player3num;

					printf("Player 4 please play a card using the table above: ");
					scanf("%d", &player4num);
					printf("\n");

					// if card is already entered ask for input again
					if (player4num == numbers[4] || player4num == numbers[3] || player4num == numbers[2] || player4num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player4num);
						printf("\n");
					}

					// save the card played to an array
					numbers[4] = player4num;

					// depending on the cards played choose a winner and output it
					if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
					{
						player1 += 5;
						printf("Player one won that round!!\n");
						printf("Player 1 has %d points\n", player1);
					}//player 1 won
					else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
					{
						player2 += 5;
						printf("Player two won that round!!\n");
						printf("Player 2 has %d points\n", player2);
					}//player2 won
					else if (player3num > player1num && player3num > player2num && player3num > player4num && player3num > player5num)
					{
						player3 += 5;
						printf("Player three won that round!!\n");
						printf("Player 3 has %d points\n", player3);
					}//player 3 won
					else
					{
						player4 += 5;
						printf("Player four won that round!!\n");
						printf("Player 4 has %d points\n", player4);
					}//player4 won
				}

				if (players == 5)
				{
					printf("-------------------\n");

					printf("Please enter different cards this time \n\n");

					//ask for input from each player
					printf("Player 1 please play a card using the table above: ");
					scanf("%d", &player1num);
					printf("\n");
					// if card is already entered ask for input again
					if (player1num == numbers[1] || player1num == numbers[2] || player1num == numbers[3] || player1num == numbers[4] || player1num == numbers[5])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 1 please play a card using the table above: ");
						scanf("%d", &player1num);
						printf("\n");
					}

					numbers[1] = player1num;

					printf("Player 2 please play a card using the table above: ");
					scanf("%d", &player2num);
					printf("\n");

					// if card is already entered ask for input again
					if (player2num == numbers[2] || player2num == numbers[1] || player2num == numbers[3] || player2num == numbers[4] || player2num == numbers[5])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player2num);
						printf("\n");
					}

					numbers[2] = player2num;

					printf("Player 3 please play a card using the table above: ");
					scanf("%d", &player3num);
					printf("\n");

					// if card is already entered ask for input again
					if (player3num == numbers[3] || player3num == numbers[2] || player3num == numbers[1] || player3num == numbers[4] || player3num == numbers[5])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player3num);
						printf("\n");
					}

					numbers[3] = player3num;

					printf("Player 4 please play a card using the table above: ");
					scanf("%d", &player4num);
					printf("\n");

					// if card is already entered ask for input again
					if (player4num == numbers[4] || player4num == numbers[2] || player4num == numbers[3] || player4num == numbers[1] || player4num == numbers[5])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player4num);
						printf("\n");
					}

					numbers[4] = player4num;

					printf("Player 5 please play a card using the table above: ");
					scanf("%d", &player5num);
					printf("\n");

					// if card is already entered ask for input again
					if (player5num == numbers[5] ||  player5num == numbers[2] || player5num == numbers[3] || player5num == numbers[4] || player5num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player1num);
						printf("\n");
					}

					numbers[5] = player5num;
					
					// depending on cards played choose a winner and output it
					if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
					{
						player1 += 5;
						printf("Player one won that round!!\n");
						printf("Player 1 has %d points\n", player1);
					}
					else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
					{
						player2 += 5;
						printf("Player two won that round!!\n");
						printf("Player 2 has %d points\n", player2);
					}
					else if (player3num > player1num && player3num > player2num && player3num > player4num && player3num > player5num)
					{
						player3 += 5;
						printf("Player three won that round!!\n");
						printf("Player 3 has %d points\n", player3);
					}
					else if (player4num > player1num && player4num > player2num && player4num > player3num && player4num > player5num)
					{
						player4 += 5;
						printf("Player four won that round!!\n");
						printf("Player 4 has %d points\n", player4);
					}
					else if (player5num > player1num && player5num > player2num && player5num > player3num && player5num > player4num)
					{
						player5 += 5;
						printf("Player five won that round!!\n");
						printf("Player 5 has %d points\n", player5);
					}
				}

				if (players == 6)
				{
					printf("-------------------\n");

					printf("Please enter different cards this time \n\n");

					//ask each player to enter a card
					printf("Player 1 please play a card using the table above: ");
					scanf("%d", &player1num);
					printf("\n");

					// if card is already entered ask for input again
					if (player1num == numbers[1] || player1num == numbers[5] || player1num == numbers[2] || player1num == numbers[3] || player1num == numbers[4] || player1num == numbers[6])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 1 please play a card using the table above: ");
						scanf("%d", &player1num);
						printf("\n");
					}

					numbers[1] = player1num;

					printf("Player 2 please play a card using the table above: ");
					scanf("%d", &player2num);
					printf("\n");

					// if card is already entered ask for input again
					if (player2num == numbers[2] || player2num == numbers[5] || player2num == numbers[6] || player2num == numbers[3] || player2num == numbers[4] || player2num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player2num);
						printf("\n");
					}

					numbers[2] = player2num;

					printf("Player 3 please play a card using the table above: ");
					scanf("%d", &player3num);
					printf("\n");

					// if card is already entered ask for input again
					if (player3num == numbers[3] || player3num == numbers[5] || player3num == numbers[2] || player3num == numbers[6] || player3num == numbers[4] || player3num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player3num);
						printf("\n");
					}

					numbers[3] = player3num;

					printf("Player 4 please play a card using the table above: ");
					scanf("%d", &player4num);
					printf("\n");

					// if card is already entered ask for input again
					if (player4num == numbers[4] || player4num == numbers[5] || player4num == numbers[2] || player4num == numbers[3] || player4num == numbers[6] || player4num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player4num);
						printf("\n");
					}

					numbers[4] = player4num;

					printf("Player 5 please play a card using the table above: ");
					scanf("%d", &player5num);
					printf("\n");

					// if card is already entered ask for input again
					if (player5num == numbers[5] || player5num == numbers[6] || player5num == numbers[2] || player5num == numbers[3] || player5num == numbers[4] || player5num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player5num);
						printf("\n");
					}

					numbers[5] = player5num;

					printf("Player 6 please play a card using the table above: ");
					scanf("%d", &player6num);
					printf("\n");

					// if card is already entered ask for input again
					if (player6num == numbers[6] || player6num == numbers[5] || player6num == numbers[2] || player6num == numbers[3] || player6num == numbers[4] || player6num == numbers[1])
					{
						printf("Card already entered - Try again!!\n");
						printf("Player 2 please play a card using the table above: ");
						scanf("%d", &player6num);
						printf("\n");
					}

					numbers[6] = player6num;

					//depending on the cards entered choose a winner and output it
					if (player1num > player2num && player1num > player3num && player1num > player4num && player1num > player5num)
					{
						player1 += 5;
						printf("Player one won that round!!\n");
						printf("Player 1 has %d points\n", player1);
					}
					else if (player2num > player1num && player2num > player3num && player2num > player4num && player2num > player5num)
					{
						player2 += 5;
						printf("Player two won that round!!\n");
						printf("Player 2 has %d points\n", player2);
					}
					else if (player3num > player1num && player3num > player2num && player3num > player4num && player3num > player5num)
					{
						player3 += 5;
						printf("Player three won that round!!\n");
						printf("Player 3 has %d points\n", player3);
					}
					else if (player4num > player1num && player4num > player2num && player4num > player3num && player4num > player5num)
					{
						player4 += 5;
						printf("Player four won that round!!\n");
						printf("Player 4 has %d points\n", player4);
					}
					else if (player5num > player1num && player5num > player2num && player5num > player3num && player5num > player4num)
					{
						player5 += 5;
						printf("Player five won that round!!\n");
						printf("Player 5 has %d points\n", player5);
					}
					else
					{
						player6 += 5;
						printf("Player six won that round!!\n");
						printf("Player 6 has %d points\n", player6);
					}
				}
			}
			else if (choice == 's' || choice == 'S')
			{
				//fprintf(saveGame,"Nothing here yet");
				// if the choice is s - save the game
				for (int j = 1; j <= players; j++)
				{
					fprintf(saveGame, "Player %d: \n\n", j);
					for (int i = 0; i < 5; i++)
					{
						cardDraw(choice);
					}
					fprintf(saveGame, "\n");
				}

				fprintf(saveGame,"\nThe Trump card is: %d of %s", ranks[random], suits[randomSuit]);
				fprintf(saveGame,"\n");

				//depending on the amount of players print out the scores for them to the file
				if (players == 2)
				{
					fprintf(saveGame, "Player 1 has %d points \n", player1);
					fprintf(saveGame, "Player 2 has %d points \n", player2);
				}
				else if (players == 3)
				{
					fprintf(saveGame, "Player 1 has %d points \n", player1);
					fprintf(saveGame, "Player 2 has %d points \n", player2);
					fprintf(saveGame, "Player 3 has %d points \n", player3);
				}
				else if (players == 4)
				{
					fprintf(saveGame, "Player 1 has %d points \n", player1);
					fprintf(saveGame, "Player 2 has %d points \n", player2);
					fprintf(saveGame, "Player 3 has %d points \n", player3);
					fprintf(saveGame, "Player 4 has %d points \n", player4);
				}
				else if (players == 5)
				{
					fprintf(saveGame, "Player 1 has %d points \n", player1);
					fprintf(saveGame, "Player 2 has %d points \n", player2);
					fprintf(saveGame, "Player 3 has %d points \n", player3);
					fprintf(saveGame, "Player 4 has %d points \n", player4);
					fprintf(saveGame, "Player 5 has %d points \n", player5);
				}
				else
				{
					fprintf(saveGame, "Player 1 has %d points \n", player1);
					fprintf(saveGame, "Player 2 has %d points \n", player2);
					fprintf(saveGame, "Player 3 has %d points \n", player3);
					fprintf(saveGame, "Player 4 has %d points \n", player4);
					fprintf(saveGame, "Player 5 has %d points \n", player5);
					fprintf(saveGame, "Player 6 has %d points \n", player6);
				}

				printf("\n\nGame Saved!!\n\n");
			}

		if (player1 == 25 || player2 == 25 || player3 == 25 || player4 == 25 || player5 == 25 || player6 == 25)
		{
			// if any player reaches 25 then end the game
			if (player1 == 25)
			{
				printf("Game Over - player 1 won the game!!\n\n");
				exit(2);
			}//player 1 won
			else if (player2 == 25)
			{
				printf("Game Over - player 2 won the game!!\n\n");
				exit(2);
			}//player 2 won
			else if (player3 == 25)
			{
				printf("Game Over - player 3 won the game!!\n\n");
				exit(2);
			}//player 3 won
			else if (player4 == 25)
			{
				printf("Game Over - player 4 won the game!!\n\n");
				exit(2);
			}//player 4 won
			else if (player5 == 25)
			{
				printf("Game Over - player 5 won the game!!\n\n");
				exit(2);
			}//player 5 won
			else
			{
				printf("Game Over - player 6 won the game!!\n\n");
				exit(2);
			}//player 6 won
		}

			//ask user again for the next step
			printf("\nEnter c to play next round, s to save game or e to exit: ");
			scanf("%s", &choice);

		}while (player1 != 25 || player2 != 25 || player3 != 25 || player4 != 25 || player5 != 25 || player6 != 25);//keep repeating until someone reaches 25

		//thank the user for playing the game
		printf("\nThank you for playing 25\n");
	}
	else if (start == 2)//entered 2 to load a game
	{
		//if nothing in the file print out the following
		if (loadGame == NULL)
		{
			printf("\nSorry there is no previous saved games\n");
			exit(2);
		}
	}
	else
	{
		//print out the contents of the file
		while (!feof(loadGame))
		{
			fscanf(loadGame, "%s", filegame);

			printf("%s",filegame);
			exit(2);

		}

		fclose(loadGame);
	}
}
//method to randomize and deal out cards
void cardDraw(char decision) {
	int r, s;
	int j = 1;
	//srand(time)
	r = randomNum(13);
	s = randomNum(4);

	//printf("%d of %s \n", ranks[r], suits[s]);

	//depending on decision deal out cards or save the cards to a txt file
	if (decision == 's' || decision == 'S')
	{
		fprintf(saveGame, "%d of %s \n", ranks[r], suits[s]);
	}
	else
	{
		printf("%d of %s \n", ranks[r], suits[s]);
	}
}
//getting a random number for the card
int randomNum(int num)
{
	//for loop to make sure all numbers are different
	for (int i = 0; i < 5; i++)
	{
		return rand() % num;
	}
}