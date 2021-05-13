#include "csvlib.h"



int getNumberOfLines(char *chrFile)
{
    int intNumLines = 0;
    char chrInput = '\0';

    FILE *fp;
    fp = fopen(chrFile, "r");

    for (chrInput = getc(fp); chrInput != EOF; chrInput = getc(fp)){
        if (chrInput == '\n'){
            intNumLines++;
        }
    }

    fclose(fp);
    return intNumLines;
}

int getNumberOfWords(char *chrFile, char separador)
{
    int intNumWords = 0;
    char chrInput = '\0';

    FILE *fp;
    fp = fopen(chrFile, "r");

    for (chrInput = getc(fp); chrInput != EOF; chrInput = getc(fp)){
        if ((chrInput == '\n') || (chrInput == separador) || (chrInput == 32)){
            intNumWords++;
        }
    }
    fclose(fp);
    return intNumWords;
}

int getNumberOfFieldsPerLine(char *chrFile, char separador)
{
    int intNumFields = 0;
    char chrInput = '\0';

    FILE *fp;
    fp = fopen(chrFile, "r");

    chrInput=fgetc(fp);
    while(chrInput != '\n')
    {
        if(chrInput==separador)
        {
            intNumFields++;
        }
        chrInput=fgetc(fp);
    }

    fclose(fp);
    return intNumFields+1;
}


char *changeFile(char *chrFile){
    FILE *fp;
    while (1){
        clearString(chrFile);
        printf(CHANGEFILE_EXP);
        printf(CHANGEFILE_ENTRY);
        scanf(" %s", chrFile);

        if ((fp = fopen(chrFile,"r"))!=NULL){
            fclose(fp);
            return *chrFile;
        }else{
            printf(CHANGEFILE_ERROR);
        }
    }


}

char changeSeparator(char chrSeparador){
    printf(CHANGESEPARATOR_EXP);
    printf(CHANGESEPARATOR_ENTRY);
    scanf(" %c", &chrSeparador);
    return chrSeparador;
}

void readFile(char *chrFile){
    FILE *fp;
    char chrInput='\0';

    fp = fopen(chrFile, "r");

    printf("Filename: %s\n\n",chrFile);
    chrInput = fgetc(fp);
    while (chrInput != EOF)
    {
        printf ("%c", chrInput);
        chrInput = fgetc(fp);
    }
    printf("\n");

    printf("\nPrima Enter para continuar");
    clsKeyboardBuffer();
    getchar();
}

void getInfoFile(char *chrFile, char chrSeparador){

    int intNumLines = 0, intNumWords = 0, intNumFields = 0;



    intNumLines = getNumberOfLines(chrFile);
    intNumWords = getNumberOfWords(chrFile, chrSeparador);
    intNumFields = getNumberOfFieldsPerLine(chrFile,chrSeparador);

    printf(FILE_INFO_FIELDS, chrFile, intNumFields);
    printf(FILE_INFO_LINES, chrFile, intNumLines);
    printf(FILE_INFO_WORDS, chrFile, intNumWords);

    clsKeyboardBuffer();
    getchar();
}