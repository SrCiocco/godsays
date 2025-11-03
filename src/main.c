#include <stdio.h>
#include <stdlib.h> /* rand, srand */
#include <unistd.h> /* getpid */
#include <string.h> /* strtok */

#include "cwords.h" /* count_words */

void tokenize_words(char words[], char* godMessage[]);
void print_random(char* godMessage[], int wordsCounter);

int main()
{
	srand(getpid());

	char words[] = "El Espíritu del Señor está sobre mí por cuanto me ha ungido para anunciar buenas noticias a los pobres. Me ha enviado a proclamar libertad a los cautivos y dar vista a los ciegos, a poner en libertad a los oprimidos.";
	int wordsCounter = count_words(words);
	char* godMessage[wordsCounter];
	tokenize_words(words, godMessage);
	print_random(godMessage, wordsCounter);
	return 0;
}

void tokenize_words(char words[], char* godMessage[])
{
	char* actualWord = strtok(words, " ");
	int i = 0;
	while (actualWord != NULL) {
		godMessage[i] = actualWord;
		i++;
		actualWord = strtok(NULL, " ");
	}
}

void print_random(char* godMessage[], int wordsCounter)
{
	for (int i = 0; i < wordsCounter; i++) {
		int randNum = rand() % wordsCounter;
		printf("%s ", godMessage[randNum]);
	}
}
