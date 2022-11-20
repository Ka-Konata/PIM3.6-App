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
	// char cad_aluno_matricula[10], cad_aluno_nomecompleto[200], cad_aluno_rg[12], cad_aluno_cpf[14], cad_aluno_nomepai[200], cad_aluno_nomemae[200], cad_aluno_telefone[20], cad_aluno_email[200];
	char to_validate[8][200],
		dados_cadastro_aluno[8][200],
		dados_cadastro_curso[4][200],
		dados_cadastro_turma[4][200],
		dados_cadastro_disciplina[5][200],
		dados_cadastro_professor[8][200];

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

					ask_and_validate_info(key_list, value_list, 8, "LIMPA", "LIMPA", "LIMPA", "LIMPA", validate_nome, 1); // Impede um bug de repetição

					// numero de matricula
					strcpy(value[0], "A001");
					strcpy(dados_cadastro_aluno[0], "A001");
					value_list[0] = value[0];

					char *infos[8] = {"", "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"};
					char *requirements[8] = {"", "somente letras, inclua espacos", "somente numeros, sem  simbolos ou espacos", "somente numeros, sem  simbolos ou espacos", "somente letras, inclua espacos", "somente letras, inclua espacos", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "@ e provedor obrigatorio"};
					char *exemples[8] = {"", "pedro alberto", "1234567890", "02212533330", "pedro alberto", "pedro alberto", "911119999", "e-mail"};
					int (*functionPtr[8])(char*) = {NULL, validate_nome, validate_num, validate_CPF, validate_nome, validate_nome, validate_telefone, validate_email};

					for (int i_alunos = 1; i_alunos < 7; i_alunos++)
					{
						if (i_alunos == 6) strcpy(value[i_alunos], "+55 ");
						strcpy(value[i_alunos], ask_and_validate_info(key_list, value_list, 8, "ALUNO", infos[i_alunos], requirements[i_alunos], exemples[i_alunos], functionPtr[i_alunos], 0));
						strcpy(dados_cadastro_aluno[i_alunos], value[i_alunos]);
						value_list[i_alunos] = value[i_alunos];
						if (strcmp(value_list[i_alunos], "⤬") == 0) break;
					}

					// nome completo
					//strcpy(value[1], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "nome completo", "somente letras, inclua espacos", "pedro alberto", validate_nome, 0));
					//strcpy(dados_cadastro_aluno[1], value[1]);
					//value_list[1] = value[1];
					//if (strcmp(value_list[1], "⤬") == 0) break;

					// RG
					//strcpy(value[2], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "RG", "somente numeros, sem  simbolos ou espacos", "1234567890", validate_num, 0));
					//strcpy(dados_cadastro_aluno[2], value[2]);
					//value_list[2] = value[2];
					//if (strcmp(value_list[2], "⤬") == 0) break;

					// CPF
					//strcpy(value[3], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "CPF", "somente numeros, sem  simbolos ou espacos", "02212533330", validate_CPF, 0));
					//strcpy(dados_cadastro_aluno[3], value[3]);
					//value_list[3] = value[3];
					//if (strcmp(value_list[3], "⤬") == 0) break;

					// nome do pai
					//strcpy(value[4], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "nome do pai", "somente letras, inclua espacos", "pedro alberto", validate_nome, 0));
					//strcpy(dados_cadastro_aluno[4], value[4]);
					//value_list[4] = value[4];
					//if (strcmp(value_list[4], "⤬") == 0) break;

					// nome da mae
					//strcpy(value[5], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "nome da mae", "somente letras, inclua espacos", "pedro alberto", validate_nome, 0));
					//strcpy(dados_cadastro_aluno[5], value[5]);
					//value_list[5] = value[5];
					//if (strcmp(value_list[5], "⤬") == 0) break;

					// telefone
					//strcpy(value[6], "+55 ");
					//strcat(value[6], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "telefone", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "911119999", validate_telefone, 0));
					//strcpy(dados_cadastro_aluno[6], value[6]);
					//value_list[6] = value[6];
					//if (strcmp(value_list[6], "⤬") == 0) break;

					// nome da mae
					//strcpy(value[7], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "e-mail", "@ e provedor obrigatorio", "exemplo123@gmail.com", validate_email, 0));
					//strcpy(dados_cadastro_aluno[7], value[7]);
					//value_list[7] = value[7];
					//if (strcmp(value_list[7], "⤬") == 0) break;

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

					ask_and_validate_info(key_list, value_list, 4, "LIMPA", "LIMPA", "LIMPA", "LIMPA", validate_nome, 1); // Impede um bug de repetição

					// codigo do curso
					strcpy(value[0], "C01");
					strcpy(dados_cadastro_aluno[0], "C01");
					value_list[0] = value[0];

					// nome do curso
					strcpy(value[1], ask_and_validate_info(key_list, value_list, 4, "CURSO", "nome do curso", "somente letras, inclua espacos", "Engenharia de Software", validate_nome, 0));
					strcpy(dados_cadastro_aluno[1], value[1]);
					value_list[1] = value[1];
					if (strcmp(value_list[1], "⤬") == 0) break;

					// carga horaria total
					strcpy(value[2], ask_and_validate_info(key_list, value_list, 4, "CURSO", "carga horaria total", "em horas, somente numeros, sem espacos ou simbolos", "3000", validate_num, 0));
					strcpy(dados_cadastro_aluno[2], value[2]);
					value_list[2] = value[2];
					if (strcmp(value_list[2], "⤬") == 0) break;

					// area do conhecimento
					type_choices = 0;
					strcpy(value[3], ask_and_validate_info(key_list, value_list, 4, "CURSO", "area do conhecimento", "Escreva exatamente como demonstrado abaixo. \nAreas de Conhecimento Disponiveis: \n\nCiencias Exatas e da Terra \nCiencias Biologicas \nEngenharias \nCiencias da Saude \nCiencias Agrarias \nLinguistica, Letras e Artes \nCiencias Sociais Aplicadas \nCiencias Humanas\n", "", validate_choice, 0));
					strcpy(dados_cadastro_aluno[3], value[3]);
					value_list[3] = value[3];
					if (strcmp(value_list[3], "⤬") == 0) break;

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

					ask_and_validate_info(key_list, value_list, 4, "LIMPA", "LIMPA", "LIMPA", "LIMPA", validate_nome, 1); // Impede um bug de repetição

					// codigo da turma
					strcpy(value[0], "T001");
					strcpy(dados_cadastro_aluno[0], "T001");
					value_list[0] = value[0];

					// nome da turma
					strcpy(value[1], ask_and_validate_info(key_list, value_list, 4, "TURMA", "nome da turma", "somente letras e numeros, sem simbolos ou espacos", "DS2P30", validate_turma, 0));

					strcpy(dados_cadastro_aluno[1], value[1]);
					value_list[1] = value[1];
					if (strcmp(value_list[1], "⤬") == 0) break;

					// periodo
					type_choices = 1;
					strcpy(value[2], ask_and_validate_info(key_list, value_list, 4, "TURMA", "periodo", "Escreva exatamente como demonstrado abaixo. \nPeriodos Disponiveis: \n\nmanha \ntarde \nnoite\n", "", validate_choice, 0));
					strcpy(dados_cadastro_aluno[2], value[2]);
					value_list[2] = value[2];
					if (strcmp(value_list[2], "⤬") == 0) break;

					// limite maximo de alunos matriculados
					strcpy(value[3], ask_and_validate_info(key_list, value_list, 4, "TURMA", "limite maximo de alunos matriculados", "Somente numeros", "50", validate_num, 0));
					strcpy(dados_cadastro_aluno[3], value[3]);
					value_list[3] = value[3];
					if (strcmp(value_list[3], "⤬") == 0) break;

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

					ask_and_validate_info(key_list, value_list, 5, "LIMPA", "LIMPA", "LIMPA", "LIMPA", validate_nome, 1); // Impede um bug de repetição

					// codigo da disciplina
					strcpy(value[0], "D001");
					strcpy(dados_cadastro_aluno[0], "T001");
					value_list[0] = value[0];

					// nome da disciplina
					strcpy(value[1], ask_and_validate_info(key_list, value_list, 5, "DISCIPLINA", "nome da disciplina", "somente letras, sem simbolos", "Matematica para Computacao", validate_nome, 0));
					strcpy(dados_cadastro_aluno[1], value[1]);
					value_list[1] = value[1];
					if (strcmp(value_list[1], "⤬") == 0) break;

					// carga horaria semanal
					strcpy(value[2], ask_and_validate_info(key_list, value_list, 5, "DISCIPLINA", "carga horaria semanal", "em horas, somente numeros, sem espacos ou simbolos", "6", validate_num, 0));
					strcpy(dados_cadastro_aluno[2], value[2]);
					value_list[2] = value[2];
					if (strcmp(value_list[2], "⤬") == 0) break;

					// carga horaria total
					strcpy(value[3], ask_and_validate_info(key_list, value_list, 5, "DISCIPLINA", "carga horaria total", "Somente numeros", "50", validate_num, 0));
					strcpy(dados_cadastro_aluno[3], value[3]);
					value_list[3] = value[3];
					if (strcmp(value_list[3], "⤬") == 0) break;

					// tipo
					type_choices = 2;
					strcpy(value[4], ask_and_validate_info(key_list, value_list, 5, "DISCIPLINA", "tipo", "Escreva exatamente como demonstrado abaixo. \nTipos Disponiveis: \n\npresencial \nead\n", "", validate_choice, 0));
					strcpy(dados_cadastro_aluno[4], value[4]);
					value_list[4] = value[4];
					if (strcmp(value_list[4], "⤬") == 0) break;

					// FINAL: Inserindo no bd
					insert_to_bd(4, 300, 5, value_list);
					save_bd();

					printf(green "TURMA [%s|%s] cadastrada com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}

				/**
				if (answer_cadastrar == 5)
				{
					system("cls");
					char *key_list[8] = {"numero da funcional", "nome completo", "titularidade", "RG", "CPF", "CPTS", "telefone", "e-mail"};
					char *value_list[8] = {'\0'};
					char value[8][200] = {'\0'};

					ask_and_validate_info(key_list, value_list, 8, "LIMPA", "LIMPA", "LIMPA", "LIMPA", validate_nome, 1); // Impede um bug de repetição

					// numero da funcional
					strcpy(value[0], ask_and_validate_info(key_list, value_list, 8, "PROFESSOR", "numero da funcional", "somente numeros, sem  simbolos ou espacos", "12345678", validate_nome, 0));
					strcpy(dados_cadastro_aluno[0], value[0]);
					value_list[0] = value[0];
					if (strcmp(value_list[0], "⤬") == 0) break;

					// nome completo
					strcpy(value[1], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "nome completo", "somente letras, inclua espacos", "pedro alberto", validate_nome, 0));

					strcpy(dados_cadastro_aluno[1], value[1]);
					value_list[1] = value[1];
					if (strcmp(value_list[1], "⤬") == 0)
						break;

					// RG
					strcpy(value[2], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "RG", "somente numeros, sem  simbolos ou espacos", "1234567890", validate_num, 0));

					strcpy(dados_cadastro_aluno[2], value[2]);
					value_list[2] = value[2];
					if (strcmp(value_list[2], "⤬") == 0)
						break;

					// CPF
					strcpy(value[3], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "CPF", "somente numeros, sem  simbolos ou espacos", "02212533330", validate_CPF, 0));

					strcpy(dados_cadastro_aluno[3], value[3]);
					value_list[3] = value[3];
					if (strcmp(value_list[3], "⤬") == 0)
						break;

					// nome do pai
					strcpy(value[4], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "nome do pai", "somente letras, inclua espacos", "pedro alberto", validate_nome, 0));

					strcpy(dados_cadastro_aluno[4], value[4]);
					value_list[4] = value[4];
					if (strcmp(value_list[4], "⤬") == 0)
						break;

					// nome da mae
					strcpy(value[5], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "nome da mae", "somente letras, inclua espacos", "pedro alberto", validate_nome, 0));

					strcpy(dados_cadastro_aluno[5], value[5]);
					value_list[5] = value[5];
					if (strcmp(value_list[5], "⤬") == 0)
						break;

					// telefone
					strcpy(value[6], "+55 ");
					strcat(value[6], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "telefone", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "911119999", validate_telefone, 0));

					strcpy(dados_cadastro_aluno[6], value[6]);
					value_list[6] = value[6];
					if (strcmp(value_list[6], "⤬") == 0)
						break;

					// nome da mae
					strcpy(value[7], ask_and_validate_info(key_list, value_list, 8, "ALUNO", "e-mail", "@ e provedor obrigatorio", "exemplo123@gmail.com", validate_email, 0));

					strcpy(dados_cadastro_aluno[7], value[7]);
					value_list[7] = value[7];
					if (strcmp(value_list[7], "⤬") == 0)
						break;

					// FINAL: Inserindo no bd
					insert_to_bd(1, 500, 8, value_list);
					save_bd();

					printf(green "ALUNO [%s|%s] cadastrado com sucesso!" default "\n\nPressione ENTER para continuar...", value_list[0], value_list[1]);
					getch();
					system("cls");
				}
				**/

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