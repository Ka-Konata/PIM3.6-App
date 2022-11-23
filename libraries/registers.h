// Inserindo bibliotecas

#include "bd-handler.h"
#include "validations.h"

int register_loop(int type, int range, char *key_list[8], char *requirements[8], char *exemples[8], int (*validate_func[8])(char*), char *title, int M, int N) 
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

int search_loop(int type, char *title, char *how, char* exemple, char *key_list[8], int M, int N, int skip)
{
    int flag = 0, found = 0;

    system("cls");
    while (flag == 0)
    {
        char answer[200], cancel[200] = "cancelar", *table_res;
        printf("==================== Procurando por: %s ====================", title);
        printf(green "\n\nComo funciona: %s \nExemplo: %s" default, how, exemple);
        printf("\n\nDigite cancelar para interromper a pesquisa\n> Pesquisar: ");
        gets(answer);
        if(skip == 1) return 0;
        if(strcmp(answer, cancel) == 0)
        {
            system("cls");
            return 0;
        }
        if(found == 0)  
        {
            system("cls");
            table_res = get_table(type, M, N, answer, key_list);
            if(strcmp(table_res, "⤬") == 0) {                
               printf(red "Nao encontrado(a)\n\n" default);
            }
            else {
                found = 1;
                printf("=================================== Resultado da Pesquisa ===================================");
                printf("\n%s", table_res);
                printf("\n\n\nDigite 1 para ALTERAR O CADASTRO. \nDigite 2 para DELETAR O CADASTRO. \nDigite qualquer outra coisa para continuar pesquisando.");
                printf("\n> ");
                if (!scanf("%d", &flag))
                    scanf("%*[^\n]");
                if(flag == 1) return 1;
                else if(flag == 2) {
                    delete_element(type, M, N, get_table_position(type, M, N, answer));
                    printf(green "\nCadastro deletado com sucesso!" default "\nPressione ENTER para voltar...");
                    getch();
                    return 0;
                }
                system("cls");
            }
        }
        else {
            found = 0;
            system("cls");
        }
    }
}