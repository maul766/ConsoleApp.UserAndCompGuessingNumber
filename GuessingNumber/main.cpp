#include <iostream>
#include <random>

int InputInt()
{
	int validInt;
	std::cin >> validInt;
	if (!(std::cin))
	{	
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Please Enter The Number!" << std::endl;
	}
	return validInt;
}
char InputChar()
{
	std::string s;
	do {
		if (!(std::cin >> s)) throw;
		if (s.length() == 1) break;
		std::cout << "Invalid input. Enter a single character" << std::endl;
	} while (true);
	return s[0];
}
void Wait(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	while (clock() < startClock + secondsAhead);
	return;
}
int RandomInt(int low, int high)
{
	std::random_device rd;
	std::mt19937 gen(rd()); // Mersenne Twister engine
	std::uniform_int_distribution<> dis(low, high);
	return dis(gen);
}
void UserGuessNumber(int maxNumber,int maxLife)
{
	int randomNumber,i;
	int userGuess = 0;
	randomNumber = RandomInt(1,maxNumber);
	std::cout << "You Have: " << maxLife << " life to guess the Number" << std::endl;
	for (i = 0; i < maxLife; i++)
	{
		std::cout << "Guess The Number between 1-" << maxNumber << ": ";
		userGuess = InputInt();
		if (userGuess == randomNumber)
		{
			std::cout << "Yeay You Win!! The Number is: " << randomNumber << std::endl;
			break;
		}
		else if (userGuess > randomNumber && i != maxLife - 1)
		{
			std::cout << "Too High, the number is smaller than that" << std::endl;
		}
		else if (userGuess < randomNumber && i != maxLife - 1)
		{
			std::cout << "Too Low, the number is bigger than that" << std::endl;
		}
	}
	if (i == maxLife)
	{
		std::cout << "You out of Try!!" << std::endl;
		std::cout << "The Number is: " << randomNumber << std::endl;
	}
}
void CompGuessNumber(int maxNumber)
{
	int compGuess = 0;
	int low = 1;
	int high = maxNumber;
	char userInput{};
	std::cout << "Think of number between 1-"<< high << std::endl;
	Wait(3);
	while (userInput != 'c')
	{
		if (low != high)
		{
			/*compGuess = low + (static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / (high - low))));*/
			compGuess = low + RandomInt(low,high);
		}
		else
		{
			compGuess = high;
		}
		std::cout << "Your Number is " << compGuess << "? if not press (H) mean too High or press (L) mean too Low if Correct press (C)" << std::endl;
		userInput = InputChar();
		userInput = static_cast<char>(tolower(static_cast<unsigned char>(userInput)));

		if (userInput == 'h' )
		{
			high = compGuess - 1;
		}
		else if (userInput == 'l' )
		{
			low = compGuess + 1;
		}
	}
	std::cout << "Yeay I  win your Number is: "<< compGuess << std::endl;
}
int main()
{	
	int choices;
	menu:
		std::cout << "\t\t\t\tWelcome to Game Guess Number" << std::endl;
		std::cout << "\t\t\t\t  Which want u wanna play\n\n";
		std::cout << "\t\t\t1.You guessing AI's Number" << std::endl;
		std::cout << "\t\t\t2.AI Guess Your Number" << std::endl;
		std::cout << "\t\t\t3.Exit" << std::endl;
		std::cout << "\t\tEnter Your choice: ";
	choices = InputInt();
	if (choices == 1)
	{	
		int choice;
		gamePlay1:
			std::cout << std::endl;
			UserGuessNumber(10, 7);
		std::cout << "\n\tPress 1 to back to menu any Key to RestartGame: ";
		choice = InputInt();
		/*(choice == 1)? goto menu : goto gamePlay1;*/
		if (choice == 1)
		{	
			system("CLS");
			goto menu;
		}
		else
		{	
			system("CLS");
			goto gamePlay1;
		}
	}
	else if(choices == 2)
	{
		int choice;
	gamePlay2:
		std::cout << std::endl;
		CompGuessNumber(10);
		std::cout << "\n\tPress 1 to back to menu any Key to RestartGame: ";
		choice = InputInt();
		if (choice == 1)
		{
			system("CLS");
			goto menu;
		}
		else
		{
			system("CLS");
			goto gamePlay2;
		}
	}
	else if(choices == 3)
	{
		exit(0);
	}
	else
	{
		std::cout << "Please Input with following Instruction! ";
	}
	return 0;
}