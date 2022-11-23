// Inserindo bibliotecas
//#include <json.c/json.h>

//#include "libraries/bd-handler.h"
//#include "libraries/validations.h"
#include "libraries/registers.h"

// Definindo constantes
// Cores
#define red "\x1b[31m"
#define green "\x1b[32m"
#define blue "\x1b[34m"
#define default "\x1b[0m"
// Path para os arquivos .json
#define BD_SIZE 1024

char *aluno_key_list[8] = {"numero de matricula", "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"};
char *aluno_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras, inclua espacos", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "somente letras, inclua espacos", "somente letras, inclua espacos", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "obrigatorio incluir @ e provedor"};
char *aluno_exemples[8] = {"A001", "pedro alberto", "1234567890", "02212533330", "pedro alberto", "pedro alberto", "911119999", "exemplo@gmail.com"};
int (*aluno_validate_func[8])(char *) = {validate_codigo, validate_nome, validate_num, validate_CPF, validate_nome, validate_nome, validate_telefone, validate_email};

char *curso_key_list[8] = {"codigo do curso", "nome do curso", "carga horaria total", "areas do conhecimento"};
char *curso_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras, inclua espacos", "em horas, somente numeros, sem espacos ou simbolos", "Escreva exatamente como demonstrado abaixo. \nAreas de Conhecimento Disponiveis: \n\nCiencias Exatas e da Terra \nCiencias Biologicas \nEngenharias \nCiencias da Saude \nCiencias Agrarias \nLinguistica, Letras e Artes \nCiencias Sociais Aplicadas \nCiencias Humanas\n"};
char *curso_exemples[8] = {"C01", "Engenharia de Software", "3000", ""};
int (*curso_validate_func[8])(char *) = {validate_codigo, validate_nome, validate_num, validate_choice};

char *turma_key_list[8] = {"codigo da turma", "nome da turma", "periodo", "limite maximo de alunos matriculados"};
char *turma_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras e numeros, sem simbolos ou espacos", "Escreva exatamente como demonstrado abaixo. \nPeriodos Disponiveis: \n\nmanha \ntarde \nnoite\n", "Somente numeros"};
char *turma_exemples[8] = {"T001", "DS2P30", "", "50"};
int (*turma_validate_func[8])(char *) = {validate_codigo, validate_turma, validate_choice, validate_num};

char *disciplina_key_list[8] = {"codigo da disciplina", "nome da disciplina", "carga horaria semanal", "carga horaria total", "tipo"};
char *disciplina_requirements[8] = {"nao inclua espacos, de preferencia apenas letras e numeros", "somente letras, sem simbolos", "em horas, somente numeros, sem espacos ou simbolos", "Somente numeros", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\npresencial \nead\n"};
char *disciplina_exemples[8] = {"D001", "Matematica para Computacao", "6", "50", ""};
int (*disciplina_validate_func[8])(char *) = {validate_codigo, validate_nome, validate_num, validate_num, validate_choice};

char *professor_key_list[8] = {"numero da funcional", "nome completo", "titularidade", "RG", "CPF", "CPTS", "telefone", "e -mail"};
char *professor_requirements[8] = {"Somente numeros (6 digitos), sem simbolos ou espacos", "somente letras, inclua espacos", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\especialista \nmestre \ndoutor\n", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "Insira o Numero, Serie e UF da CTPS, separados por espacos", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "obrigatorio incluir @ e provedor"};
char *professor_exemples[8] = {"123456", "pedro alberto", "", "1234567890", "02212533330", "1111111 1111 DF", "911119999", "exemplo@gmail.com"};
int (*professor_validate_func[8])(char *) = {validate_funcional, validate_nome, validate_choice, validate_num, validate_CPF, validate_CTPS, validate_telefone, validate_email};

// Código Principal
// Código Principal
int main(void)
{
	setlocale(LC_ALL, ""); // Definição padrão do idioma

	// Defininfo funções

	// Defininfo variáveis
	int run = 1, answer_menu, answer_cadastrar, answer_acessar;

	// Iniciando o programa
	printf("\n\n            ____                  __      ___           _       \n           |  _ \\                 \\ \\    / (_)         | |      \n           | |_) | ___ _ __ ___    \\ \\  / / _ _ __   __| | ___  \n           |  _ < / _ \\ '_ ` _ \\    \\ \\/ / | | '_ \\ / _` |/ _ \\ \n           | |_) |  __/ | | | | |    \\  /  | | | | | (_| | (_) |\n           |____/ \\___|_| |_| |_|     \\/   |_|_| |_|\\__,_|\\___/");
	printf("\n\n\n\n\n           PIM 2nd Semestre | Grupo: DS2.7");
	printf("\n           Nomes: Victor G. Ramos, Jeferson");

	check_bd();
	load_bd(); // Carrega o as informações já salvas

	printf("\n\n           Pressione ENTER para continuar...");
	getch();
	system("cls");

	while (run == 1)
	{
		answer_menu = NULL;
		printf("=========================================\n");
		printf("| MENU PRINCIPAL                        |\n");
		printf("=========================================\n");
		printf("| [1] - Realizar Cadastro               |\n");
		printf("| [2] - Acessar Cadastro                |\n");
		printf("| [3] - Encerrar Programa               |\n");
		printf("=========================================\n");
		printf("\n> Insira o numero referente a funcao que voce deseja utilizar: ");
		if (!scanf("%d", &answer_menu))
			scanf("%*[^\n]");

		if (answer_menu == 1)
		{
			system("cls");
			while (run = 1)
			{
				answer_cadastrar = NULL;

				printf("=========================================\n");
				printf("| REALIZAR CADASTRO                     |\n");
				printf("=========================================\n");
				printf("| [1] - Cadastrar Aluno                 |\n");
				printf("| [2] - Cadastrar Curso                 |\n");
				printf("| [3] - Cadastrar Turma                 |\n");
				printf("| [4] - Cadastrar Disciplina            |\n");
				printf("| [5] - Cadastrar Professor             |\n");
				printf("| [6] - Voltar                          |\n");
				printf("=========================================\n");
				printf("\n> Tipo de cadastro: ");
				if (!scanf("%d", &answer_cadastrar))
					scanf("%*[^\n]");

				if (answer_cadastrar == 1)
					register_loop(1, 8, aluno_key_list, aluno_requirements, aluno_exemples, aluno_validate_func, "ALUNO", 500, 8);
				else if (answer_cadastrar == 2)
					register_loop(2, 4, curso_key_list, curso_requirements, curso_exemples, curso_validate_func, "CURSO", 20, 4);
				else if (answer_cadastrar == 3)
					register_loop(3, 4, turma_key_list, turma_requirements, turma_exemples, turma_validate_func, "TURMA", 100, 4);
				else if (answer_cadastrar == 4)
					register_loop(4, 5, disciplina_key_list, disciplina_requirements, disciplina_exemples, disciplina_validate_func, "DISCIPLINA", 300, 5);
				else if (answer_cadastrar == 5)
					register_loop(5, 8, professor_key_list, professor_requirements, professor_exemples, professor_validate_func, "PROFESSOR", 50, 8);
				else if (answer_cadastrar == 6)
				{
					system("cls");
					break;
				}
				else
				{
					system("cls");
					printf(red "Algo deu errado. Por favor, leia e tente novamente.\n\n" default);
				}
			}
		}

		else if (answer_menu == 2)
		{
			system("cls");
			while (run = 1)
			{
				answer_acessar = NULL;

				printf("=========================================\n");
				printf("| ENCONTRAR CADASTRO                    |\n");
				printf("=========================================\n");
				printf("| [1] - Encontrar Aluno                 |\n");
				printf("| [2] - Encontrar Curso                 |\n");
				printf("| [3] - Encontrar Turma                 |\n");
				printf("| [4] - Encontrar Disciplina            |\n");
				printf("| [5] - Encontrar Professor             |\n");
				printf("| [6] - Voltar                          |\n");
				printf("=========================================\n");
				printf("\n> Tipo de cadastro: ");
				if (!scanf("%d", &answer_acessar))
					scanf("%*[^\n]");

				char *key_list[8] = {"numero de matricula", "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"};
				if (answer_acessar != 6)
					search_loop(1, "", "", "", aluno_key_list, 0, 0, 1);

				if (answer_acessar == 1)
					{printf("1\n"); search_loop(1, "ALUNO", "Insira o numero de matricula", "A001", aluno_key_list, 500, 8, 0);}
				else if (answer_acessar == 2)
					{printf("2\n"); search_loop(2, "CURSO", "Insira o codigo do curso", "C01", curso_key_list, 20, 4, 0);}
				else if (answer_acessar == 3)
					{printf("3\n"); search_loop(3, "TURMA", "Insira o codigo da turma", "T01", turma_key_list, 100, 4, 0);}
				else if (answer_acessar == 4)
					{printf("4\n"); search_loop(4, "DISCIPLINA", "Insira o codigo da disciplina", "D001", disciplina_key_list, 300, 5, 0);}
				else if (answer_acessar == 5)
					{printf("5\n"); search_loop(5, "PROFESSOR", "Insira o numero funcional", "123456", professor_key_list, 50, 8, 0);}
				else if (answer_acessar == 6)
				{
					system("cls");
					break;
				}
				else
				{
					system("cls");
					printf(red "Algo deu errado. Por favor, leia e tente novamente.\n\n" default);
				}
				printf("Pressione ENTER para continuar...");
				// getch();
				system("cls");
			}
		}

		else if (answer_menu == 3)
		{
			system("cls");
			printf("Programa Encerrado.\n");
			break;
		}

		else
		{
			system("cls");
			printf(red "Algo deu errado. Por favor, leia e tente novamente.\n\n" default);
		}
	}

	save_bd(); // Salva as informações
	system("pause");
}