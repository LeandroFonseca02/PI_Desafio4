#include "textlib.h"
#include <string.h>


int getNumberOfLines(char *chrFile);
int getNumberOfWords(char *chrFile, char separador);
int getNumberOfFieldsPerLine(char *chrFile, char separador);

char *changeFile(char *chrFile);
char changeSeparator(char chrSeparador);

void readFile(char *chrFile);
void getInfoFile(char * chrFile, char chrSeparador);