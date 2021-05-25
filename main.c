#include "csvlib.h"
#include "textlib.h"

int main()
{
    FILE *fp;
    char chrSeparador = ',', chrMenuOption = '\0';
    char chrFile[50] = "\0";
    int intExit = 0;

    *chrFile = changeFile(chrFile);
    chrSeparador = changeSeparator(chrSeparador);


    while (intExit != 1){
        printMainMenu(chrFile);
        scanf(" %c", &chrMenuOption);

        switch (chrMenuOption) {
            case '1':
                readFile(chrFile);
                returnMenu();
                break;
            case '2':
                getInfoFile(chrFile, chrSeparador);
                returnMenu();
                break;
            case '3':
                sortFile(chrFile, chrSeparador);
                returnMenu();
                break;
            case '4':
                *chrFile = changeFile(chrFile);
                returnMenu();
                break;
            case '5':
                chrSeparador = changeSeparator(chrSeparador);
                returnMenu();
                break;
            case '6':
                sobrePrograma();
                returnMenu();
                break;
            case '0':
                intExit = 1;
                break;
            default:
                printf("Opção invalida!");
                returnMenu();
                break;
        }
    }

    return 0;
}