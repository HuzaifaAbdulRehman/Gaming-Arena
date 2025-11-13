#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Guess(int i)
{
	const int MIN = 1;
	const int MAX = 100;
	int guess;
	int guesses;//int guesses = 0;
	int answer;
	
	srand (time(0));
	answer = (rand() % MAX) + MIN;
	
	
		do
		{
			printf("ENTER A NUMBER OF GUESS: ");
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
int main()
{
	printf("WELCOME TO THE NUMBER GUESSING GAME\n");
	printf("SELECT THE DIFFICULTY LEVEL\n");
	printf("Press\n 1 for Easy mode\n 2 for Medium Mode\n 3 for Difficult mode\n ");
	int difficulty;
	scanf("%d",&difficulty);
	switch(difficulty)
	{
		case 1:
			printf("You have selected Easy mode\nYou have 5 attempts\n\n");
			Guess(5);
			break;
		case 2: 
			printf("You have selected Medium mode\nYou have 10 attempts\n\n");
			Guess(10);
			break;
		case 3:
			printf("You have selected Hard mode\nYou have 20 attempts\n\n");
			Guess(20);
			break;
	}
	return 0;
}
