#include <stdio.h>


/* Defines para imprimir o menu inicial*/
#define PROGRAM_TITLE "\t\t============ CSV Manager ============\n\n\n\n"
#define MAINMENU_TITLE "\t\t\t       Menu Principal\n"
#define MAINMENU_TITLE_SEPARADOR "\t\t\t============================\n"
#define MAINMENU_OPTION_1 "\t\t\t[1] Leitura do ficheiro %s\n"
#define MAINMENU_OPTION_2 "\t\t\t[2] Informacao do ficheiro %s\n"
#define MAINMENU_OPTION_3 "\t\t\t[3] Ordenar ficheiro %s\n"
#define MAINMENU_OPTION_4 "\t\t\t[4] Alterar ficheiro .csv\n"
#define MAINMENU_OPTION_5 "\t\t\t[5] Alterar separador de palavras\n"
#define MAINMENU_OPTION_6 "\t\t\t[6] Sobre o programa\n"
#define MAINMENU_OPTION_0 "\t\t\t[0] Sair do programa\n"
#define MAINMENU_USER_OPTION "\n\t\t\tDigite a opção que deseja: "


#define CHANGEFILE_EXP "Exemplo de ficheiro: ficheiro.csv\n"
#define CHANGEFILE_ENTRY "Introduza o nome do ficheiro que deseja usar: "
#define CHANGEFILE_ERROR "\n\nO ficheiro %s não fui encontrado, introduza outro ficheiro!\n\n"
#define CHANGESEPARATOR_EXP "Exemplo de separador: ;\n"
#define CHANGESEPARATOR_ENTRY "Introduza o caracter separador que deseja usar: "

#define FILE_INFO_FIELDS "\n\nO ficheiro %s tem %d campos por linha.\n"
#define FILE_INFO_LINES "O ficheiro %s tem %d linhas.\n"
#define FILE_INFO_WORDS "O ficheiro %s tem %d palavras.\n"

#define SORT_FILE_BY_FIELD "\nDigite o campo que deseja ordenar (1-%d): "
#define SORT_FILE_SUCESS "\n\nFicheiro ordenado pelo campo %d."


void clearString(char *chrArray);
void printMainMenu(char *chrFile);

//Display de algumas informações do programa
void sobrePrograma();

//Limpa o buffer do teclado
void clsKeyboardBuffer(void);

void returnMenu();