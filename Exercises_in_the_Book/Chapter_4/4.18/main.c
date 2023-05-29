#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int i;
	int j;
	int n;

	if (argc == 1) // if no argument was passed by user for n
		n = 5;
	else
		n = atoi(argv[1]);
	for(i = 0; i < 5; i++)
	{
		for(j = n; j > 0; j--)
			write(1, "*", 1);
		write(1, "\n", 1);
	}
	return (0);
}