// Arquivo app.c
// Inserindo bibliotecas
#include "libraries/registers.h"
 
// Definindo constantes - Estas informações serão usadas para exibição, cadastramento e pesquisa de dados
// Matrizes para TIPOS DE INFORMAÇÕES
char *aluno_key_list[8] = {"numero de matricula", "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"}; //
char *curso_key_list[8] = {"codigo do curso", "nome do curso", "carga horaria total", "areas do conhecimento"};
char *turma_key_list[8] = {"codigo da turma", "nome da turma", "periodo", "limite maximo de alunos matriculados"};
char *disciplina_key_list[8] = {"codigo da disciplina", "nome da disciplina", "carga horaria semanal", "carga horaria total", "tipo"};
char *professor_key_list[8] = {"numero da funcional", "nome completo", "titularidade", "RG", "CPF", "CPTS", "telefone", "e-mail"};
 
// Matrizes para EXEMPLOS de como os dados devem ser informados pelos usuários
char *aluno_exemples[8] = {"A001", "pedro alberto", "1234567890", "02212533330", "pedro alberto", "pedro alberto", "61 911119999", "exemplo@gmail.com"};
char *curso_exemples[8] = {"C01", "Engenharia de Software", "3000", ""};
char *turma_exemples[8] = {"T001", "DS2P30", "", "50"};
char *disciplina_exemples[8] = {"D001", "Matematica para Computacao", "6", "50", ""};
char *professor_exemples[8] = {"123456", "pedro alberto", "", "1234567890", "02212533330", "1111111 1111 DF", "61 911119999", "exemplo@gmail.com"};
 
// Matrizes para REQUISITOS para cadastrar dados
char *aluno_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras, inclua espacos", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "somente letras, inclua espacos", "somente letras, inclua espacos", "NAO COLOQUE O +55, insira seu DDD e resto do telefone separados por um espaco, o nono digito (9) e obrigatorio", "obrigatorio incluir @ e provedor"};
char *curso_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras, inclua espacos", "em horas, somente numeros, sem espacos ou simbolos", "Escreva exatamente como demonstrado abaixo. \nAreas de Conhecimento Disponiveis: \n\nCiencias Exatas e da Terra \nCiencias Biologicas \nEngenharias \nCiencias da Saude \nCiencias Agrarias \nLinguistica, Letras e Artes \nCiencias Sociais Aplicadas \nCiencias Humanas\n"};
char *turma_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras e numeros, sem simbolos ou espacos", "Escreva exatamente como demonstrado abaixo. \nPeriodos Disponiveis: \n\nmanha \ntarde \nnoite\n", "Somente numeros"};
char *disciplina_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras, sem simbolos", "em horas, somente numeros, sem espacos ou simbolos", "Somente numeros", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\npresencial \nead\n"};
char *professor_requirements[8] = {"Somente numeros (6 digitos), sem simbolos ou espacos", "somente letras, inclua espacos", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\especialista \nmestre \ndoutor\n", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "Insira o Numero, Serie e UF da CTPS, separados por espacos", "NAO COLOQUE O +55, insira seu DDD e resto do telefone separados por um espaco, o nono digito (9) e obrigatorio", "obrigatorio incluir @ e provedor"};
 
// Matrizes para FUNÇÔES de validação para cada tipo de dado
int (*aluno_validate_func[8])(char *) = {validate_codigo, validate_nome, validate_num, validate_CPF, validate_nome, validate_nome, validate_telefone, validate_email};
int (*curso_validate_func[8])(char *) = {validate_codigo, validate_nome, validate_num, validate_choice};
int (*turma_validate_func[8])(char *) = {validate_codigo, validate_turma, validate_choice, validate_num};
int (*disciplina_validate_func[8])(char *) = {validate_codigo, validate_nome, validate_num, validate_num, validate_choice};
int (*professor_validate_func[8])(char *) = {validate_funcional, validate_nome, validate_choice, validate_num, validate_CPF, validate_CTPS, validate_telefone, validate_email};
 
// Código Principal
int main(void)
{
    setlocale(LC_ALL, ""); // Definição padrão do idioma
    // Defininfo variáveis
    int run = 1, 
    answer_menu, answer_cadastrar, answer_acessar; // Para armazenar as respostas do usuário quanto aos menus
 
    // Iniciando o programa
    // Tela Inicial
    printf("\n\n            ____                  __      ___           _       \n           |  _ \\                 \\ \\    / (_)         | |      \n           | |_) | ___ _ __ ___    \\ \\  / / _ _ __   __| | ___  \n           |  _ < / _ \\ '_ ` _ \\    \\ \\/ / | | '_ \\ / _` |/ _ \\ \n           | |_) |  __/ | | | | |    \\  /  | | | | | (_| | (_) |\n           |____/ \\___|_| |_| |_|     \\/   |_|_| |_|\\__,_|\\___/"); // Mensagem de "bem vindo"
    printf("\n\n\n\n\n           PIM 2nd Semestre | Grupo: DS2.7"); // Exibe informações sobre o trabalho e sobre o grupo
    printf("\n           RA's: N913843, F346862, G6257F0, F3465J9, G6257D4 e F3467G9"); // Exibe os RA’s dos participantes do grupo
    check_bd(); // Tenta encontrar os arquivos .json, e os cria caso não encontre
    load_bd();  // Carrega o as informações já salvas
    printf("\n\n           Pressione ENTER para continuar...");
    getch(); // Espera resposta do usuário para sair da tela inicial
    system("cls"); // Limpa a tela
 
    while (run == 1) // Laço de repetição do Menu Principal
    {
        answer_menu = NULL; // Limpa a resposta
        printf("=========================================\n");
        printf("| MENU PRINCIPAL                        |\n"); // Título do Menu
        printf("=========================================\n"); // Explicação dos comandos do menu ...
        printf("| [1] - Realizar Cadastro               |\n");
        printf("| [2] - Acessar Cadastro                |\n");
        printf("| [3] - Encerrar Programa               |\n");
        printf("=========================================\n");
        printf("\n> Insira o numero referente a funcao que voce deseja utilizar: "); // Pede resposta do usuário
        if (!scanf("%d", &answer_menu)) // Espera a resposta, e valida para possíveis erros
            scanf("%*[^\n]"); // Caso dê erro resolve a situação
 
        if (answer_menu == 1) // Caso o usuário queira cadastrar algo
        {
            system("cls");  // Limpa a tela
            while (run = 1) // Laço de repetição do Menu Cadastro
            {
                answer_cadastrar = NULL; // Limpa a resposta
                printf("=========================================\n");
                printf("| REALIZAR CADASTRO                     |\n"); // Título do Menu
                printf("=========================================\n"); // Explicação dos comandos do menu ...
                printf("| [1] - Cadastrar Aluno                 |\n");
                printf("| [2] - Cadastrar Curso                 |\n");
                printf("| [3] - Cadastrar Turma                 |\n");
                printf("| [4] - Cadastrar Disciplina            |\n");
                printf("| [5] - Cadastrar Professor             |\n");
                printf("| [6] - Voltar                          |\n");
                printf("=========================================\n");
                printf("\n> Tipo de cadastro: "); // Pede resposta do usuário
                if (!scanf("%d", &answer_cadastrar)) // Espera a resposta, e valida para possíveis erros
                    scanf("%*[^\n]"); // Caso dê erro resolve a situação
 
                if (answer_cadastrar == 1) // Caso o usuário queira cadastrar um aluno
                   register_loop(1, 8, aluno_key_list, aluno_requirements, aluno_exemples, aluno_validate_func, "ALUNO", 500, 8, 0); // Executa a função de cadastro
                else if (answer_cadastrar == 2) // Caso o usuário queira cadastrar um curso
                   register_loop(2, 4, curso_key_list, curso_requirements, curso_exemples, curso_validate_func, "CURSO", 20, 4, 0); // Executa a função de cadastro
                else if (answer_cadastrar == 3) // Caso o usuário queira cadastrar uma turma
                    register_loop(3, 4, turma_key_list, turma_requirements, turma_exemples, turma_validate_func, "TURMA", 100, 4, 0); // Executa a função de cadastro
                else if (answer_cadastrar == 4) // Caso o usuário queira cadastrar uma disciplina
                    register_loop(4, 5, disciplina_key_list, disciplina_requirements, disciplina_exemples, disciplina_validate_func, "DISCIPLINA", 300, 5, 0); // Executa a função de cadastro
                else if (answer_cadastrar == 5) // Caso o usuário queira cadastrar um professor
                    register_loop(5, 8, professor_key_list, professor_requirements, professor_exemples, professor_validate_func, "PROFESSOR", 50, 8, 0); // Executa a função de cadastro
                else if (answer_cadastrar == 6) // Caso o usuário queira voltar ao menu anterior
                {
                    system("cls"); // Limpa a tela
                    break; // Encerra o laço
                }
                else // Caso seja detectado um erro na resposta do usuário
                {
                    system("cls"); // Limpa a tela
                    printf(red "Algo deu errado. Por favor, leia e tente novamente.\n\n" default); // Informa o erro
                }
            }
        }
 
        else if (answer_menu == 2) // Caso o usuário queira acessar um cadastro
        {
            system("cls"); // Limpa a tela
            while (run = 1) // Laço de repetição do Menu Acessar
            {
                int pos; // Para armazenar a posição de um dado na sua matriz correspondente
                answer_acessar = NULL; // Limpa a resposta
                printf("=========================================\n");
                printf("| ENCONTRAR CADASTRO                    |\n"); // Título do Menu
                printf("=========================================\n"); // Explicação dos comandos do menu ...
                printf("| [1] - Encontrar Aluno                 |\n");
                printf("| [2] - Encontrar Curso                 |\n");
                printf("| [3] - Encontrar Turma                 |\n");
                printf("| [4] - Encontrar Disciplina            |\n");
                printf("| [5] - Encontrar Professor             |\n");
                printf("| [6] - Voltar                          |\n");
                printf("=========================================\n");
                printf("\n> Tipo de cadastro: "); // Caso dê erro resolve a situação
                if (!scanf("%d", &answer_acessar)) // Espera a resposta, e valida para possíveis erros
                    scanf("%*[^\n]"); // Caso dê erro resolve a situação
                if (answer_acessar != 6) // Caso a resposta não seja "voltar"
                    search_loop(1, "", "", "", aluno_key_list, 0, 0, 1); // Impede um bug no algoritmo referente ao loop
                if (answer_acessar == 1) // Caso o usuário queira pesquisar por um aluno
                {
                    pos = search_loop(1, "ALUNO", "Insira o numero de matricula", "A001", aluno_key_list, 500, 8, 0); // Executa a função de pesquisa
                    if (pos > 0) // Caso o usuário queira alterar os dados encontrados
                        register_loop(1, 8, aluno_key_list, aluno_requirements, aluno_exemples, aluno_validate_func, "ALUNO", 500, 8, pos); // Executa a função de cadastro no modo de alteração
                    system("cls");
                }
                else if (answer_acessar == 2) // Caso o usuário queira pesquisar por um curso
                {
                    pos = search_loop(2, "CURSO", "Insira o codigo do curso", "C01", curso_key_list, 20, 4, 0); // Executa a função de pesquisa
                    if (pos > 0) // Caso o usuário queira alterar os dados encontrados
                        register_loop(2, 4, curso_key_list, curso_requirements, curso_exemples, curso_validate_func, "CURSO", 20, 4, pos); // Executa a função de cadastro no modo de alteração
                    system("cls"); // Limpa a tela
                }
                else if (answer_acessar == 3) // Caso o usuário queira pesquisar por uma turma
                {
                    pos = search_loop(3, "TURMA", "Insira o codigo da turma", "T01", turma_key_list, 100, 4, 0); // Executa a função de pesquisa
                    if (pos > 0) // Caso o usuário queira alterar os dados encontrados
                        register_loop(3, 4, turma_key_list, turma_requirements, turma_exemples, turma_validate_func, "TURMA", 100, 4, pos); // Executa a função de cadastro no modo de alteração
                    system("cls"); // Limpa a tela
                }
                else if (answer_acessar == 4) // Caso o usuário queira pesquisar por uma disciplina
                {
                    pos = search_loop(4, "DISCIPLINA", "Insira o codigo da disciplina", "D001", disciplina_key_list, 300, 5, 0); // Executa a função de pesquisa
                    if (pos > 0) // Caso o usuário queira alterar os dados encontrados
                        register_loop(4, 5, disciplina_key_list, disciplina_requirements, disciplina_exemples, disciplina_validate_func, "DISCIPLINA", 300, 5, pos); // Executa a função de cadastro no modo de alteração
                    system("cls"); // Limpa a tela
                }
                else if (answer_acessar == 5) // Caso o usuário queira pesquisar por um professor
                {
                    pos = search_loop(5, "PROFESSOR", "Insira o numero funcional", "123456", professor_key_list, 50, 8, 0); // Executa a função de pesquisa
                    if (pos == 1) // Caso o usuário queira alterar os dados encontrados
                    register_loop(5, 8, professor_key_list, professor_requirements, professor_exemples, professor_validate_func, "PROFESSOR", 50, 8, pos);  // Executa a função de cadastro no modo de alteração
                    system("cls"); // Limpa a tela
                }
                else if (answer_acessar == 6) // Caso o usuário queira voltar ao menu anterior
                {
                    system("cls"); // Limpa a tela
                    break; // Encerra o laço
                }
                else // Caso seja detectado um erro na resposta do usuário
                {
                    system("cls"); // Limpa a tela
                    printf(red "Algo deu errado. Por favor, leia e tente novamente.\n\n" default); // Informa o erro
                }
            }
        }
        else if (answer_menu == 3) // Caso o usuário queira encerrar o programa
        {
            system("cls"); // Limpa a tela
            printf("Programa Encerrado.\n"); // Informa que o programa será encerrado
            break; // Encerra o laço (e consequentemente programa)
        }
        else  // Caso seja detectado um erro na resposta do usuário
        {
            system("cls"); // Limpa a tela
            printf(red "Algo deu errado. Por favor, leia e tente novamente.\n\n" default); // Encerra o laço
        }
    }
    save_bd(); // Salva as informações nos arquivos .json
    system("pause"); // Espera resposta do usuário para encerrar
}