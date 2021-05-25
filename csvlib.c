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
    return intNumLines+1;
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
    return intNumWords+1;
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
            printf(CHANGEFILE_ERROR,chrFile);
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

}

void getInfoFile(char *chrFile, char chrSeparador){

    int intNumLines = 0, intNumWords = 0, intNumFields = 0;



    intNumLines = getNumberOfLines(chrFile);
    intNumWords = getNumberOfWords(chrFile, chrSeparador);
    intNumFields = getNumberOfFieldsPerLine(chrFile,chrSeparador);

    printf(FILE_INFO_FIELDS, chrFile, intNumFields);
    printf(FILE_INFO_LINES, chrFile, intNumLines);
    printf(FILE_INFO_WORDS, chrFile, intNumWords);

}

void insertionSort(struct linha *pArray, int intNumLines, int intNumField){
    int i = 0, j = 0,k = 0;
    struct linha temp;
    intNumField--;

    for(i = 0; i < intNumLines-1; i++)
    {

        for(j = i + 1; j < intNumLines; j++)
        {
            if(strcmp(pArray[i].chrLinha[intNumField],pArray[j].chrLinha[intNumField])>0)
            {
                temp = pArray[i];
                pArray[i] = pArray[j];
                pArray[j] = temp;
            }
        }
    }

}


void sortFile(char *chrFile, char chrSeparador){
    int intNumLines = 0, intNumFields = 0, intCounter = 0, intCounterLines=0,intCounterCol=0, intFieldChoice = 1;
    char chrInput = '\0';
    FILE *fp = NULL;

    intNumLines = getNumberOfLines(chrFile);

    struct linha chrLinhas[intNumLines];


    fp = fopen(chrFile, "r");

    for(chrInput = fgetc(fp); chrInput != EOF; chrInput = fgetc(fp)){
        if (chrInput == chrSeparador){
            chrLinhas[intCounterLines].chrLinha[intCounterCol][intCounter] = '\0';
            intCounterCol++;
            intCounter = 0;
        }else if (chrInput == '\n'){
            chrLinhas[intCounterLines].chrLinha[intCounterCol][intCounter] = '\0';
            intCounterLines++;
            intCounterCol = 0;
            intCounter = 0;
        }else{
            chrLinhas[intCounterLines].chrLinha[intCounterCol][intCounter] = chrInput;
            intCounter++;
        }
    }
    chrLinhas[intCounterLines].chrLinha[intCounterCol][intCounter] = '\0';
    fclose(fp);

    intNumFields = getNumberOfFieldsPerLine(chrFile, chrSeparador);
    printf(SORT_FILE_BY_FIELD,intNumFields);
    scanf("%d", &intFieldChoice);

    if((intFieldChoice > 1) || (intFieldChoice < intNumFields)){
        insertionSort(chrLinhas, intNumLines,intFieldChoice);

        fp = fopen(chrFile, "w");

        for(intCounterLines = 0; intCounterLines < intNumLines; intCounterLines++){
            for(intCounterCol = 0; intCounterCol < intNumFields; intCounterCol++){
                fprintf(fp,"%s",chrLinhas[intCounterLines].chrLinha[intCounterCol]);
                if(intCounterCol != intNumFields-1){
                    fprintf(fp,"%c",chrSeparador);
                }
            }
            if(intCounterLines != intNumLines-1){
                fprintf(fp,"\n");
            }

        }
        fclose(fp);

        printf(SORT_FILE_SUCESS,intFieldChoice);

    }else {
        printf("\n\nOpcao invalida.");
    }





}