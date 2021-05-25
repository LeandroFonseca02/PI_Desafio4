#include "textlib.h"
#include <stdlib.h>
#include <string.h>

struct linha{
    char chrLinha[20][50];
};

int getNumberOfLines(char *chrFile);
int getNumberOfWords(char *chrFile, char separador);
int getNumberOfFieldsPerLine(char *chrFile, char separador);

char *changeFile(char *chrFile);
char changeSeparator(char chrSeparador);

void readFile(char *chrFile);
void getInfoFile(char * chrFile, char chrSeparador);
void insertionSort(struct linha *pArray, int intNumLines, int intNumField);
void sortFile(char *chrFile, char chrSeparador);