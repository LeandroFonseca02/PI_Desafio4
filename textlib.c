#include "textlib.h"

void printMainMenu(char *chrFile){
    printf(PROGRAM_TITLE);
    printf(MAINMENU_TITLE);
    printf(MAINMENU_TITLE_SEPARADOR);
    printf(MAINMENU_OPTION_1, chrFile);
    printf(MAINMENU_OPTION_2, chrFile);
    printf(MAINMENU_OPTION_3, chrFile);
    printf(MAINMENU_OPTION_4);
    printf(MAINMENU_OPTION_5);
    printf(MAINMENU_OPTION_6, chrFile);
    printf(MAINMENU_OPTION_7);
    printf(MAINMENU_OPTION_0);
    printf(MAINMENU_USER_OPTION);

}

void clearString(char *chrArray){
    for (int i = 0; i <50; ++i) {
        chrArray[i] = '\0';
    }
}

void sobrePrograma(){
    printf("\n\t\t================================\n\t\t\tSobre o Programa\n\t\t================================");
    printf("\n\n\n===================================================================================================");
    printf("\n\t  Este programa foi desenvolvido por Leandro Fonseca na disciplina de Programação Imperativa do curso de Engenharia Informática do Ismat pelo docente Francisco José de Melo Pereira.");
    printf("\n\n\t  O intuito do programa é ser um gestor de ficheiros .csv na quaç se pode ordenar e obter informação do ficheiro.");
    printf("\n\n..::Pressione qualquer tecla para continuar");

    clsKeyboardBuffer();
    getchar();
    }

//Limpa o buffer do teclado
void clsKeyboardBuffer(void){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        return;
    }
}