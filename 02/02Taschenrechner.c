//Calvin Steinbach - Taschenrechner

#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int number1;
	int number2;
	char operator;
	int result;
	bool resultIsValid = false;

	void userInput()
	{
		printf("Gib die erste Zahl ein:\n");
		scanf("%i", &number1);
	
		printf("Gib die zweite Zahl ein:\n");
		scanf("%i", &number2);

		printf("Gib die Rechenoperation an: (+ - * /)\n");
		scanf(" %c", &operator);
	}

	void doMaths()
	{
		switch (operator)
		{
			case '+':
				result = number1 + number2;
				resultIsValid = true;
				break;
			case '-':
				result = number1 - number2;
				resultIsValid = true;
				break;
			case '*':
				result = number1 * number2;
				resultIsValid = true;
				break;
			case '/':
				if (number2 == 0)
				{
					printf("Man teilt nicht durch 0 du Schlingel!\n");
					break;
				}
				else
				{
					result = number1 / number2;
					resultIsValid = true;
					break;
				}

				
			default:
				printf("Ein Fehler ist aufgtreten..");
		}
	

	}

	void outputResult()
	{	
		if(resultIsValid)
		{
			printf("Das Ergebnis ist: %i.\n ", result);
			
		}
	}

	
	userInput();
	doMaths();
	outputResult();
	return 0;
}
