// Arquivo registers.h
// Inserindo bibliotecas
#include "bd-handler.h"
#include "validations.h"

int register_loop(int type, int range, char *key_list[8], char *requirements[8], char *exemples[8], int (*validate_func[8])(char*), char *title, int M, int N, int alt_pos)
{
    /* Cria um laço de repetição para que o usuário informe todas os dados referente ao tipo de cadastro ao que se refere */

    // Definindo variáveis
    char *value_list[8] = {'\0'}, // Para armazenar os dados como ponteiros
    value[8][200] = {'\0'}; // Para armazenar os dados como strings
    int cad_stop = 0; // Flag

    system("cls"); // Limpa a tela
    ask_and_validate_info(key_list, value_list, range, "", "", "", "", validate_nome, 1, 0, ""); // Impede um bug de repetição
    for (int i = 0; i < range; i++) // Inicia o loop para pegar os dados
    {
         // Caso o tipo de dado seja validado pela função validate_choice é preciso predefinir as opções disponíveis
        if(type == 2 && i == 3) type_choices = 0; // Caso o tipo de cadastro seja: CURSO
        if(type == 3 && i == 2) type_choices = 1; // Caso o tipo de cadastro seja: TURMA
        if(type == 4 && i == 4) type_choices = 2; // Caso o tipo de cadastro seja: DISCIPLINA
        if(type == 5 && i == 2) type_choices = 3; // Caso o tipo de cadastro seja: PROFESSOR
        strcpy(value[i], ask_and_validate_info(key_list, value_list, range, title, key_list[i], requirements[i], exemples[i], validate_func[i], 0, alt_pos, table_to_change)); // Executa a função que exibe a tela de cadastro faz a entrada de dados

        value_list[i] = value[i]; // Copia o dado informado
        if (strcmp(value_list[i], "⤬") == 0) {cad_stop = 1; break;} // Caso o usuário queria cancelar
    } 
    if (cad_stop == 1) return 1; // Cancela o cadastro

    // FINAL: Inserindo no bd
    insert_to_bd(type, M, N, value_list, alt_pos); // Insere os dados na matriz global

    printf(green "%s [%s|%s] cadastrado(a) com sucesso!" default "\n\nPressione ENTER para continuar...", title, value_list[0], value_list[1]); // Informa que o cadastro foi concluido
    getch(); // Espera que o usuário clique para continuar
    system("cls"); // Limpa a tela
    return 0; // Encerra a função
}

int search_loop(int type, char *title, char *how, char* exemple, char *key_list[8], int M, int N, int skip)
{
    /* Cria um laço para que o usuário realize uma pesquisa, altere ou apague dados */

    // Definindo variáveis
    int flag = 0,  // Flag 
    found = 0, // Para saber quando limpar a tela
    pos; // Para retornar a posição dos dados na matriz

    system("cls"); // Limpa a tela
    while (flag == 0) // Inicia o Laço
    {
        char answer[200], // Para armazenar a resposta do usuároi
        cancel[200] = "cancelar", // Para identificar se é para cancelar
        *table_res; // Guarda os dados encontrados
        printf("==================== Procurando por: %s ====================", title); // Exibe o título
        printf(green "\n\nComo funciona: %s \nExemplo: %s" default, how, exemple); // Exibe uuma explicação e um exemplo
        printf("\n\nDigite cancelar para interromper a pesquisa\n> Pesquisar: "); // Ensina a cancelar e pede resposta do usuário
        gets(answer); // Espera a resposta
        if(skip == 1) return 0; // Caso seja necessário
        if(strcmp(answer, cancel) == 0) // Confere se o usuário deseja cancelar
        {
            system("cls"); // Limpa a tela
            return 0; // Retorna informando o cancelamento
        }
        if(found == 0) // Para não dar problema na ordem de exibição
        {
            system("cls"); // Limpa a tela
            pos = get_table_position(type, M, N, answer); // Executa a função que procura a posição dos dados
            table_res = get_table(type, M, N, answer, key_list); // Executa a função que procura os dados em sí
            if(strcmp(table_res, "⤬") == 0 || pos == 0) { // Caso a pesquisa não tenho sucesso
               printf(red "Nao encontrado(a)\n\n" default); // Informa
            }
            else {
                found = 1; // Para não dar problema na ordem de exibição
                printf("=================================== Resultado da Pesquisa ==================================="); // Imprime o título
                printf("\n%s", table_res); // Imprime o resultado da pesquisa
                printf("\n\n\nDigite 1 para ALTERAR O CADASTRO. \nDigite 2 para DELETAR O CADASTRO. \nDigite qualquer outra coisa para continuar pesquisando."); // Informa as opções do que fazer
                printf("\n> "); // Pede resposta do usuário
                if (!scanf("%d", &flag)) // Guarda resposta
                    scanf("%*[^\n]"); // Caso haja um erro na resposta
                if(flag == 1) {strcpy(table_to_change, table_res); return pos;} // Caso seja digitado 1, retorna uma requisição de alteração
                else if(flag == 2) { // Caso seja digitado 2, apaga os dados
                    delete_element(type, M, N, pos); // Executa função que apaga os dados
                    printf(green "\nCadastro deletado com sucesso!" default "\nPressione ENTER para voltar..."); // Informa que os dados foram apagados
                    getch(); // Espera que o usuário queira continuar
                    return 0; // Encerra a função
                }
                system("cls"); // Limpa a tela
            }
        }
        else { // Para não dar problema na ordem de exibição
            found = 0;
            system("cls"); // Limpa a tela
        }
    }
}