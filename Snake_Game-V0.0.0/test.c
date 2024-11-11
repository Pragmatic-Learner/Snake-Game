// Example for getch() in C

#include <stdio.h>
#include <unistd.h>

// Library where getch() is stored
#include <conio.h>

int main()
{
	int var = 1;
	while (var != 0)
	{
		printf("\nPress a key...");
		var = getch();
		var = getch();
		printf("\nKey pressed : %i", var);
	}
	//trying to commit to git :(
	return 0;
}
