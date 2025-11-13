#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Guess(int i)
{
	const int MIN = 1;
	const int MAX = 100;
	int guess;
	int guesses;
	int answer;
	
	srand (time(0));
	
	answer = (rand() % MAX) + MIN;
	
	
		do{
			printf("ENTER A GUESS (Number Is Between (1,100)): ");
			scanf("%d",&guess);
			if(guess > answer) printf("TOO HIGH\n");
			else if(guess < answer) printf("TOO LOW\n");
			else printf("Guess is Correct User WINS\n\n");
			guesses++;
			
		}while(guess != answer && guesses<i);
	
	if(guess != answer)printf("You Lost\n");
	printf("**********************************\n");
	printf("ANSWER: %d\n",answer);
	printf("Total Number of Attempts on Guesses: %d\n",guesses);
	printf("**********************************\n");
	
}
void guess_number()
{
		printf("WELCOME TO THE NUMBER GUESSING GAME\n");
	printf("SELECT THE DIFFICULTY LEVEL\n");
	printf("Press\n 1 For Easy mode\n 2 For Medium Mode\n 3 For Difficult mode\n ");
	int difficulty;
	scanf("%d",&difficulty);
	switch(difficulty)
	{
		case 1:
			printf("You have selected Easy mode\nYou have 20 attempts\n\n");
			Guess(20);
			break;
		case 2: 
			printf("You have selected Medium mode\nYou have 10 attempts\n\n");
			Guess(10);
			break;
		case 3:
			printf("You have selected Hard mode\nYou have 5 attempts\n\n");
			Guess(5);
			break;
	}
}
// Toss function
int toss(char *ptr, int n)
{
	int randInt = rand() % 2;
	if (n == randInt)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// Function to generate random number between 1 and 6, used in both batting and bowling functions
int rand_number()
{
	return (rand() % 6 + 1);
}

// Max function used in multiplayer
int max(int arr[], int n)
{
	int i, max = arr[0], max_i = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			max_i = i;
		}
	}
	return max_i;
}
int batting(int target)
{
	int user_num, user_score = 0, user_out = 0;

	while (user_out == 0)
	{
		if (user_score > target)
		{
			printf("User won\n");
			break;
		}

		// Prompt user for input until a valid number is entered
		do
		{
			printf("Enter a num between 1 and 6: ");
			scanf("%d", &user_num);

			if (user_num < 1 || user_num > 6)
			{
				printf("Enter a valid number between 1 and 6.\n");
			}
		} while (user_num < 1 || user_num > 6);

		int pc_rand = rand_number();
		if (pc_rand == user_num)
		{
			printf("You got Out for %d\n", user_score);
			user_out = 1;
			return user_score;
		}
		else
		{
			user_score += user_num;
			printf("User score: %d\n", user_score);
		}
	}
}

int bowling(int target)
{
	int user_num, pc_score = 0, pc_out = 0;

	while (pc_out == 0)
	{
		if (pc_score > target)
		{
			printf("Pc won\n");
			break;
		}

		// Prompt user for input until a valid number is entered
		do
		{
			printf("Enter a num between 1 and 6: ");
			scanf("%d", &user_num);

			if (user_num < 1 || user_num > 6)
			{
				printf("Enter a valid number between 1 and 6.\n");
			}
		} while (user_num < 1 || user_num > 6);

		int pc_rand = rand_number();
		if (pc_rand == user_num)
		{
			printf("You bowled the pc for %d runs\n", pc_score);
			pc_out = 1;
			return pc_score;
		}
		else
		{
			pc_score += pc_rand;
			printf("Pc score: %d\n", pc_score);
		}
	}
}

// Mode functions i.e singleplayer and multiplayer
void singleplayer()
{
	srand(time(NULL));
	char toss_choice, choice;
	int n, user_out, pc_out, user_score, pc_score;
	printf("Welcome to Hand cricket!\n Get ready for the toss \nEnter H to pick heads and T to pick tails: ");

	scanf(" %c", &toss_choice);
	switch (toss_choice)
	{
	case 'h':
	case 'H':
		n = 0;
		break;
	case 't':
	case 'T':
		n = 1;
		break;
	default:
		printf("Invalid");
		break;
	}
	char toss_arr[2] = {'H', 'T'};
	if (toss(toss_arr, n))
	{
		printf("Congrats you won the toss\n Enter 1 to bat first and 2 to bowl first");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("You elected to bat first\n");
			user_score = batting(10000000); // Passing a very high number so that it ends when the user gets out
			printf("Pcs turn to bat!\n");
			pc_score = bowling(user_score);
			if (user_score > pc_score)
			{
				printf("User won by %d\n", user_score - pc_score);
			}
			else if (pc_score == user_score)
			{
				printf("Its a tie\n");
			}
			break;
		case 2:
			printf("You elected to bowl first\n");
			pc_score = bowling(10000000);
			printf("Your turn to bat!\n");
			user_score = batting(pc_score);
			if (pc_score > user_score)
			{
				printf("Pc won by %d runs\n", pc_score - user_score);
			}
			else if (pc_score == user_score)
			{
				printf("Its a tie\n");
			}
			break;
		default:
			printf("Invalid\n");
			break;
		}
	}
	else
	{
		printf("You lost the toss\n");
		int pc_choice_rand = rand() % 2;
		if (pc_choice_rand == 1)
		{
			printf("Computer elected to bat first\n");
			pc_score = bowling(10000000);
			printf("Your turn to bat!\n");
			user_score = batting(pc_score);
			if (pc_score > user_score)
			{
				printf("Pc won by %d runs\n", pc_score - user_score);
			}
			else if (pc_score == user_score)
			{
				printf("Its a tie\n");
			}
		}
		else
		{
			printf("Computer elected to bowl first\n");
			user_score = batting(10000000);
			printf("Pcs turn to bat!\n");
			pc_score = bowling(user_score);
			if (user_score > pc_score)
			{
				printf("User won by %d runs\n", user_score - pc_score);
			}
			else if (pc_score == user_score)
			{
				printf("Its a tie\n");
			}
		}
	}
}
void multiplayer()
{
	int no_players, i;
	do
	{
		printf("Rules for Multplayer\n1. Min 2 players and max 5 players can play\n2.Players can only bat\n3.The player with the highest score wins.\nIn Case of two or more players with same highest score the player who batted first wins\nEnter the  no of players: ");
		scanf("%d", &no_players);

		if (no_players < 2 || no_players > 5)
		{
			printf("Invalid number of players. Please enter a number between 2 and 5.\n");
		}
	} while (no_players < 2 || no_players > 5);
	// Using an array to store the players batting score

	int arr[no_players];
	for (i = 0; i < no_players; i++)
	{
		if (i == no_players - 1)
		{
		}
		arr[i] = batting(10000000);
		printf("Player %d scored %d\n", i + 1, arr[i]);
	}
	// Now displaying the winner using max function defined above
	int max_index = max(arr, no_players);
	printf("The winner is player %d with a score %d. Congrats!", max_index + 1, arr[max_index]);
}

// The main game function
void handCricket()
{
	int mode_choice, isrepeat = 1;
	while (isrepeat == 1)
	{
		printf("Welcome to hand cricket\nHere are the general rules\n1. Whether you are batting or bowling, you have to enter a num between 1 and 6\n");
		printf("2. If your batting and both the pc's num and your num match, you are out. Same is true if your bowling\n");
		printf("3. For Multiplayer all the users have only the choice for batting. The user with the highest batting score wins\n");
		printf("Press 1 for singleplayer and 2 for mutiplayer");
		scanf("%d", &mode_choice);
		switch (mode_choice)
		{
		case 1:
			singleplayer();
			break;

		case 2:
			multiplayer();
			break;
		default:
			printf("Invalid");
		}
		printf("To replay press 1. press any other number to exit to the main menu: ");
		scanf("%d", &isrepeat);
	}
}
void swg_m()
{
	int i = 0, u1 = 0, u2 = 0, t = 0, j = 0;
	int run = 0;
	char a[20];
	char b[20];
	printf("Welcome To Snake Water Gun Game (Mulitplayer)\n");
	printf("\nGame Possibilities:\nSnake Will Drink Water\nGun Will Shoot Snake\nGun Will Sink In Water\n");
	printf("\nEnter Player 1 Name: ");
	scanf(" %s", a);
	printf("Enter Player 2 Name: ");
	scanf(" %s", b);

	while (i < 5)
	{
		char user1_choice;
		char user2_choice;
		printf("%s Choose Any One \"S\", \"W\", \"G\" ", a);
		scanf(" %c", &user1_choice);
		printf("%s Choose Any One \"S\", \"W\", \"G\" ", b);
		scanf(" %c", &user2_choice);
		if ((user1_choice == 'S' || user1_choice == 's') && (user2_choice == 'W' || user2_choice == 'w'))
		{
			printf("%s Choose %c And %s Choose %c So %s Is Winner\n", a, user1_choice, b, user2_choice, a);
			u1 += 1;
		}
		else
		{
			if ((user1_choice == 'W' || user1_choice == 'w') && (user2_choice == 'W' || user2_choice == 'w'))
			{
				printf("%s Choose %c And %s Choose %c So It Is A Tie\n", a, user1_choice, b, user2_choice);
				t += 1;
			}
			else
			{
				if ((user1_choice == 'G' || user1_choice == 'g') && (user2_choice == 'W' || user2_choice == 'w'))
				{
					printf("%s Choose %c And %s Choose %c So %s Is Winner\n", a, user1_choice, b, user2_choice, b);
					u2 += 1;
				}
				else
				{
					if ((user1_choice == 'S' || user1_choice == 's') && (user2_choice == 'G' || user2_choice == 'g'))

					{
						printf("%s Choose %c And %s Choose %c So %s Is Winner\n", a, user1_choice, b, user2_choice, b);
						u2 += 1;
					}
					else
					{
						if ((user1_choice == 'W' || user1_choice == 'w') && (user2_choice == 'G' || user2_choice == 'g'))

						{
							printf("%s Choose %c And %s Choose %c So %s Is Winner\n", a, user1_choice, b, user2_choice, a);
							u1 += 1;
						}
						else
						{
							if ((user1_choice == 'G' || user1_choice == 'g') && (user2_choice == 'G' || user2_choice == 'g'))
							{
								printf("%s Choose %c And %s Choose %c So It Is A Tie\n", a, user1_choice, b, user2_choice);
								t += 1;
							}
							else
							{
								if ((user1_choice == 'S' || user1_choice == 's') && (user2_choice == 'S' || user2_choice == 's'))

								{
									printf("%s Choose %c And %s Choose %c So It Is A Tie\n", a, user1_choice, b, user2_choice);
									t += 1;
								}
								else
								{
									if ((user1_choice == 'W' || user1_choice == 'w') && (user2_choice == 'S' || user2_choice == 's'))

									{
										printf("%s Choose %c And %s Choose %c So %s Is Winner\n", a, user1_choice, b, user2_choice, b);
										u2 += 1;
									}
									else
									{
										if ((user1_choice == 'G' || user1_choice == 'g') && (user2_choice == 'S' || user2_choice == 's'))
										{
											printf("%s Choose %c And %s Choose %c So %s Is Winner\n", a, user1_choice, b, user2_choice, a);
											u1 += 1;
										}
										else{
											printf("Invalid Choice\n");
											continue;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		i = i + 1;
	}
	printf("\nFInal Results\n");
	printf("%s Score Is %d\n", a, u1);
	printf("%s Is %d\n", b, u2);
	printf("Tied Games %d\n", t);
	if (u1 > u2)
	{
		printf("%s Is Overall Winner", a);
	}
	else
	{
		if (u1 < u2)
		{
			printf("%s Is Overall Winner", b);
		}
		else
		{
			printf("Final Score Is Tied\n");
		}
	}
}
void swg_s()
{

	srand(time(NULL));
	int i = 0, u = 0, cs = 0, t = 0, j = 0;
	int run = 0;
	char a[20] = "Your Are A Winner";
	char b[20] = "Your Are A Loser";
	char c[20] = "It Is A Tie";
	printf("Welcome To Snake Water Gun Game\n");
	printf("\nGame Possibilities:\nSnake Will Drink Water\nGun Will Shoot Snake\nGun Will Sink In Water\n\n");
	while (i < 5)
	{
		char user_choice;
		char computer_choice;
		int randomNum = rand() % 3;
		switch (randomNum)
		{
		case 0:
			computer_choice = 'S';
			break;
		case 1:
			computer_choice = 'W';
			break;
		case 2:
			computer_choice = 'G';
			break;
		}
		printf("Select Any One \"S\", \"W\", \"G\" ");
		scanf(" %c", &user_choice);
		if ((user_choice == 'S' || user_choice == 's') && computer_choice == 'W')
		{
			printf("Computer Choose %c So %s\n", computer_choice, a);
			u += 1;
		}
		else
		{
			if ((user_choice == 'W' || user_choice == 'w') && computer_choice == 'W')
			{
				printf("Computer Choose %c So %s\n", computer_choice, c);
				t += 1;
			}
			else
			{
				if ((user_choice == 'G' || user_choice == 'g') && computer_choice == 'W')
				{
					printf("Computer Choose %c So %s\n", computer_choice, b);
					cs += 1;
				}
				else
				{
					if ((user_choice == 'S' || user_choice == 's') && computer_choice == 'G')
					{
						printf("Computer Choose %c So %s\n", computer_choice, b);
						cs += 1;
					}
					else
					{
						if ((user_choice == 'W' || user_choice == 'w') && computer_choice == 'G')
						{
							printf("Computer Choose %c So %s\n", computer_choice, a);
							u += 1;
						}
						else
						{
							if ((user_choice == 'G' || user_choice == 'g') && computer_choice == 'G')
							{
								printf("Computer Choose %c So %s\n", computer_choice, c);
								t += 1;
							}
							else
							{
								if ((user_choice == 'S' || user_choice == 's') && computer_choice == 'S')
								{
									printf("Computer Choose %c So %s\n", computer_choice, c);
									t += 1;
								}
								else
								{
									if ((user_choice == 'W' || user_choice == 'w') && computer_choice == 'S')
									{
										printf("Computer Choose %c So %s\n", computer_choice, b);
										cs += 1;
									}
									else
									{
										if ((user_choice == 'G' || user_choice == 'g') && computer_choice == 'S')
										{
											printf("Computer Choose %c So %s\n", computer_choice, a);
											u += 1;
										}
										else{
											printf("Invalid Choice\n");
											continue;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		i = i + 1;
	}
	printf("\nFInal Results\n");
	printf("Your Score Is %d\n", u);
	printf("Computer Score Is %d\n", cs);
	printf("Tied Games %d\n", t);
	if (u > cs)
	{
		printf("You Are Overall Winner");
	}
	else
	{
		if (u < cs)
		{
			printf("Computer Is Overall Winner");
		}
		else
		{
			printf("Final Score Is Tied\n");
		}
	}
}

int main()
{
	int j = 0;
	while (j != 1)
	{
		char game_choice;
		char game_mode;
		printf("\nWelcome To Gaming Arena!\nPress S For Snake Water Gun\nPress H For Hand Cricket\nPress G For Guess A Number: ");
		scanf(" %c", &game_choice);
		switch (game_choice)
		{
		case 's':
		case 'S':

			printf("Press S For Single Player\nPress M For Multiplayer: ");
			scanf(" %c", &game_mode);
			if (game_mode == 'S' || game_mode == 's')
			{
				swg_s();
			}
			else
			{
				if (game_mode == 'M' || game_mode == 'm')
					swg_m();
				else{
					printf("Invalid Choice");
				}
			}
			break;
		case 'h':
		case 'H':
			handCricket();
			break;
		case 'g':
		case 'G':
			guess_number();
			break;
		default:
			printf("Invalid Choice\n");
			break;
		}
		printf("\nPress 1 To Exit: or Press any key to play other Games: ");
		scanf(" %d", &j);
		getchar();
		if (j == 1)
		{
			int rating;
			printf("\nRate Gaming Arena Between 1 to 5: ");
				scanf("%d", &rating);

			if (rating >= 3 && rating <= 5)
			{
				printf("Thanks! Hope You Enjoyed Your Time Here");
			}
			else
			{
				printf("\n We Will Surely Include Updates Which Will Improve User Experience");
			}
		}
	}
}

	
