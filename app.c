// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
//#include <json.c/json.h>

#include "libraries/bd-handler.h"
#include "libraries/validations.h"

// Definindo constantes
// Cores
#define red "\x1b[31m"
#define green "\x1b[32m"
#define blue "\x1b[34m"
#define default "\x1b[0m"
// Path para os arquivos .json
#define BD_SIZE 1024

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
				{
					system("cls");
					char *key_list[8] = {"numero de matricula", "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"};
					char *value_list[8] = {'\0'};
					char value[8][200] = {'\0'};
					int cad_stop = 0;

					ask_and_validate_info(key_list, value_list, 8, "", "", "", "", validate_nome, 1); // Impede um bug de repetição

					strcpy(value[0], "A001");
					value_list[0] = value[0];

					char *infos[8] = {NULL, "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"};
					char *requirements[8] = {NULL, "somente letras, inclua espacos", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "somente letras, inclua espacos", "somente letras, inclua espacos", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "obrigatorio incluir @ e provedor"};
					char *exemples[8] = {NULL, "pedro alberto", "1234567890", "02212533330", "pedro alberto", "pedro alberto", "911119999", "exemplo@gmail.com"};
					int (*validate_func[8])(char*) = {NULL, validate_nome, validate_num, validate_CPF, validate_nome, validate_nome, validate_telefone, validate_email};

					char number_sub[11] = "+55 ";
					for (int i_alunos = 1; i_alunos < 8; i_alunos++)
					{
						strcpy(value[i_alunos], ask_and_validate_info(key_list, value_list, 8, "ALUNO", key_list[i_alunos], requirements[i_alunos], exemples[i_alunos], validate_func[i_alunos], 0));

						if (i_alunos == 6) {
							strcat(number_sub, value[6]);
							strcpy(value[6], number_sub);
						}
						value_list[i_alunos] = value[i_alunos];
						if (strcmp(value_list[i_alunos], "⤬") == 0) {cad_stop = 1; break;}
					} 
					if (cad_stop == 1) break;

					// FINAL: Inserindo no bd
					insert_to_bd(1, 500, 8, value_list);
					save_bd();

					printf(green "ALUNO [%s|%s] cadastrado com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}

				else if (answer_cadastrar == 2)
				{

					system("cls");
					char *key_list[4] = {"codigo do curso", "nome do curso", "carga horaria total", "areas do conhecimento"};
					char *value_list[4] = {'\0'};
					char value[4][200] = {'\0'};
					int cad_stop = 0;

					ask_and_validate_info(key_list, value_list, 4, "", "", "", "", validate_nome, 1); // Impede um bug de repetição

					strcpy(value[0], "C01");
					value_list[0] = value[0];

					char *requirements[4] = {NULL, "somente letras, inclua espacos", "em horas, somente numeros, sem espacos ou simbolos", "Escreva exatamente como demonstrado abaixo. \nAreas de Conhecimento Disponiveis: \n\nCiencias Exatas e da Terra \nCiencias Biologicas \nEngenharias \nCiencias da Saude \nCiencias Agrarias \nLinguistica, Letras e Artes \nCiencias Sociais Aplicadas \nCiencias Humanas\n"};
					char *exemples[4] = {NULL, "Engenharia de Software", "3000", ""};
					int (*validate_func[4])(char*) = {NULL, validate_nome, validate_num, validate_choice};

					for (int i_curso = 1; i_curso < 4; i_curso++)
					{
						if (i_curso == 3) type_choices = 0;
						strcpy(value[i_curso], ask_and_validate_info(key_list, value_list, 4, "CURSO", key_list[i_curso], requirements[i_curso], exemples[i_curso], validate_func[i_curso], 0));
						value_list[i_curso] = value[i_curso];
						if (strcmp(value_list[i_curso], "⤬") == 0) {cad_stop = 1; break;}
					} 
					if (cad_stop == 1) break;

					// FINAL: Inserindo no bd
					insert_to_bd(2, 20, 4, value_list);
					save_bd();

					printf(green "CURSO [%s|%s] cadastrado com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}

				else if (answer_cadastrar == 3)
				{

					system("cls");
					char *key_list[4] = {"codigo da turma", "nome da turma", "periodo", "limite maximo de alunos matriculados"};
					char *value_list[4] = {'\0'};
					char value[4][200] = {'\0'};
					int cad_stop = 0;

					ask_and_validate_info(key_list, value_list, 4, "", "", "", "", validate_nome, 1); // Impede um bug de repetição

					strcpy(value[0], "T001");
					value_list[0] = value[0];

					char *requirements[4] = {NULL, "somente letras e numeros, sem simbolos ou espacos", "Escreva exatamente como demonstrado abaixo. \nPeriodos Disponiveis: \n\nmanha \ntarde \nnoite\n", "Somente numeros"};
					char *exemples[4] = {NULL, "DS2P30", "", "50"};
					int (*validate_func[4])(char*) = {NULL, validate_turma, validate_choice, validate_num};

					for (int i_turma = 1; i_turma < 4; i_turma++)
					{
						if (i_turma == 2) type_choices = 1;
						strcpy(value[i_turma], ask_and_validate_info(key_list, value_list, 4, "TURMA", key_list[i_turma], requirements[i_turma], exemples[i_turma], validate_func[i_turma], 0));
						value_list[i_turma] = value[i_turma];
						if (strcmp(value_list[i_turma], "⤬") == 0) {cad_stop = 1; break;}
					} 
					if (cad_stop == 1) break;

					// FINAL: Inserindo no bd
					insert_to_bd(3, 100, 4, value_list);
					save_bd();

					printf(green "TURMA [%s|%s] cadastrada com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}

				else if (answer_cadastrar == 4)
				{

					system("cls");
					char *key_list[5] = {"codigo da disciplina", "nome da disciplina", "carga horaria semanal", "carga horaria total", "tipo"};
					char *value_list[5] = {'\0'};
					char value[5][200] = {'\0'};
					int cad_stop = 0;

					ask_and_validate_info(key_list, value_list, 5, "", "", "", "", validate_nome, 1); // Impede um bug de repetição

					strcpy(value[0], "D001");
					value_list[0] = value[0];

					char *requirements[5] = {NULL, "somente letras, sem simbolos", "em horas, somente numeros, sem espacos ou simbolos", "Somente numeros", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\npresencial \nead\n"};
					char *exemples[5] = {NULL, "Matematica para Computacao", "6", "50", ""};
					int (*validate_func[5])(char*) = {NULL, validate_nome, validate_num, validate_num, validate_choice};

					for (int i_disciplina = 1; i_disciplina < 5; i_disciplina++)
					{
						if (i_disciplina == 4) type_choices = 2;
						strcpy(value[i_disciplina], ask_and_validate_info(key_list, value_list, 5, "DISCIPLINA", key_list[i_disciplina], requirements[i_disciplina], exemples[i_disciplina], validate_func[i_disciplina], 0));
						value_list[i_disciplina] = value[i_disciplina];
						if (strcmp(value_list[i_disciplina], "⤬") == 0) {cad_stop = 1; break;}
					} 
					if (cad_stop == 1) break;

					// FINAL: Inserindo no bd
					insert_to_bd(4, 300, 5, value_list);
					save_bd();

					printf(green "DISCIPLINA [%s|%s] cadastrada com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}

				if (answer_cadastrar == 5)
				{
					system("cls");
					char *key_list[8] = {"numero da funcional", "nome completo", "titularidade", "RG", "CPF", "CPTS", "telefone", "e-mail"};
					char *value_list[8] = {'\0'};
					char value[8][200] = {'\0'};
					int cad_stop = 0;

					ask_and_validate_info(key_list, value_list, 8, "", "", "", "", validate_nome, 1); // Impede um bug de repetição

					char *requirements[8] = {"Somente numeros, sem simbolos ou espacos", "somente letras, inclua espacos", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\especialista \nmestre \ndoutor\n", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "Insira o Numero, Serie e UF da CTPS, separados por espacos", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "obrigatorio incluir @ e provedor"};
					char *exemples[8] = {"###############", "pedro alberto", "", "1234567890", "02212533330", "1111111 1111 DF", "911119999", "exemplo@gmail.com"};
					int (*validate_func[8])(char*) = {validate_num, validate_nome, validate_choice, validate_num, validate_CPF, validate_CTPS, validate_telefone, validate_email};

					char number_sub[11] = "+55 ";
					for (int i_professor = 0; i_professor < 8; i_professor++)
					{
						if (i_professor == 2) type_choices = 3;
						strcpy(value[i_professor], ask_and_validate_info(key_list, value_list, 8, "PROFESSOR", key_list[i_professor], requirements[i_professor], exemples[i_professor], validate_func[i_professor], 0));
						value_list[i_professor] = value[i_professor];

						if (i_professor == 6) {
							strcat(number_sub, value[6]);
							strcpy(value[6], number_sub);
						}
						if (strcmp(value_list[i_professor], "⤬") == 0) {cad_stop = 1; break;}
					} 
					if (cad_stop == 1) break;

					// FINAL: Inserindo no bd
					insert_to_bd(1, 50, 8, value_list);
					save_bd();

					printf(green "PROFESSOR [%s|%s] cadastrado com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}

				/**OUTROS*/

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
			printf("ACESSAR CADASTRO.\n");
			printf("Pressione ENTER para continuar...");
			getch();
			system("cls");
		}

		else if (answer_menu == 3)
		{
			system("cls");
			printf("Encerrando Programa.\n");
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