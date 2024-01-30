#include <stdio.h>
#include <stdlib.h>

void print(FILE *fp, const char *l)
{
	printf("%s", l);
	fprintf(fp, "%s", l);
}

int main()
{
	int i;
	size_t length;
	ssize_t nread;
	char *line = NULL;
	FILE *file;

	file = fopen("the_forest", "a");

	print(file, "I am a Knight who says NI!\n");
	
	nread = getline(&line, &length, stdin);
	fprintf(file, "User input: %s", line);

	if (nread == -1) {
		fprintf(stderr, "WE HAVE FOUND A WITCH MAY WE BURN HER? (input failed)\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 5; ++i){
		print(file, "NI!\n");
	}
	print(file, "\nWe demand.... a shrubbery!\n");

	




	return 0;
}
