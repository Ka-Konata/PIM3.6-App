// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "bd-handler.h"
#include "validations.h"

int register_aluno(int type, int range, char *key_list[8], char *requirements[8], char *exemples[8], int (*validate_func[8])(char*), char *title, int M, int N) 
{
    system("cls");
    char *value_list[8] = {'\0'};
    char value[8][200] = {'\0'};

    int cad_stop = 0;

    ask_and_validate_info(key_list, value_list, range, "", "", "", "", validate_nome, 1); // Impede um bug de repetição

    char number_sub[11] = "+55 ";
    for (int i = 0; i < range; i++)
    {
        if(type == 2 && i == 3) type_choices = 0;
        if(type == 3 && i == 2) type_choices = 1;
        if(type == 4 && i == 4) type_choices = 2;
        if(type == 5 && i == 2) type_choices = 3;

        strcpy(value[i], ask_and_validate_info(key_list, value_list, range, title, key_list[i], requirements[i], exemples[i], validate_func[i], 0));

        if (type == 1 || type == 5) if(i == 6) {
            strcat(number_sub, value[6]);
            strcpy(value[6], number_sub);
        }
        value_list[i] = value[i];
        if (strcmp(value_list[i], "⤬") == 0) {cad_stop = 1; break;}
    } 
    if (cad_stop == 1) return 1;

    // FINAL: Inserindo no bd
    insert_to_bd(type, M, N, value_list);
    save_bd();

    printf(green "%s [%s|%s] cadastrado(a) com sucesso!" default "\n\nPressione ENTER para continuar...", title, value_list[0], value_list[1]);
    getch();
    system("cls");
    return 0;
}