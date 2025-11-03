#include "include/cwords.h"

int count_words(char array[])
{
	int wordsCounter = 0;
	int inWord = 0;

	for (int i = 0; array[i] != '\0'; i++) {
		if (array[i] != ' ') {
			if (inWord == 0) {
				wordsCounter++;
				inWord = 1;
			}
		}
		else inWord = 0;
	}
	return wordsCounter;
}

