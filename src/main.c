#include <stdio.h>
#include <stdlib.h> /* rand, srand */
#include <string.h> /* strncpy, strcspn */
#include <ncurses.h> /* initscr, cbreak, noecho, printw, refresh, endwin */

/********** Conditional compiling **********/
#if defined(_WIN32)
#include <windows.h> /* GetCurrentProcessId */
#else
#include <unistd.h> /* getpid */
#include <locale.h> /* setlocale */
#endif
/*******************************************/

#define BUFFER_SIZE 128

int get_randl(FILE* file, char randLine[], unsigned int bufferSize);

int main(int argc, char* argv[])
{
	if (argc != 2) {
		fprintf(stderr, "%s: missing language argument\n Try '%s <en | es>'\n", argv[0], argv[0]);
		return EXIT_FAILURE;
	}

	char* filePath;

	if (strcmp(argv[1], "es") == 0) { 
		filePath = "data/dict_es.txt";
	}

	else if (strcmp(argv[1], "en") == 0) { 
		filePath = "data/dict.txt";
	}

	else {
		fprintf(stderr, "%s: invalid language\n Try '%s <en | es>'\n", argv[0], argv[0]);
		return EXIT_FAILURE;
	}

#if defined(_WIN32)
	srand(GetCurrentProcessId());
#else
    	srand(getpid());
	setlocale(LC_ALL, ""); /* Setup the program to use the system locale. */
#endif
	FILE* dict = fopen(filePath, "r");
	if (dict == NULL) {
		fprintf(stderr, "Can't find %s", filePath);
		return EXIT_FAILURE;
	}
	/* ncurses setup */
	initscr(); /* Initialize terminal screen. */
	cbreak(); /* Turn off the ability to see what we are typing. (We don't want to mess with our stdout). */
	noecho(); /* Turn off echo. (Same as above). */

	char godWord[BUFFER_SIZE] = {0};
	do {
		rewind(dict); /* Rewind the file. (In other words, go to the beginning). */
		if (get_randl(dict, godWord, BUFFER_SIZE)) { 
			printw("%s ", godWord);
			refresh();
		}
	} while (getch() != 'q');
	fclose(dict);
	endwin(); /* Kill ncurses terminal. Ba-bye! :D */
	return EXIT_SUCCESS;
}

int get_randl(FILE* file, char randLine[], unsigned int bufferSize)
{
	if (!file || !randLine || !bufferSize) {
		fprintf(stderr, "Can't get random text line :(");
		return 0;
	}

	char actualLine[bufferSize];
	unsigned int lineCounter = 0;

	while(fgets(actualLine, bufferSize, file) != NULL) {
		lineCounter++;
		if (rand() % lineCounter == 0) strncpy(randLine, actualLine, bufferSize);
	}

	if (lineCounter == 0) {
		fprintf(stderr, "The file is empty");
		return 0;
	}

	randLine[strcspn(randLine, "\n")] = 0; /* Find the character "\n" in the array and replace it with a "\0". */

	return 1;
}
