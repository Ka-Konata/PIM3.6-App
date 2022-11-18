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
	void load_bd();
	void save_bd();
	void check_bd();
	char* ask_and_validate_info(int skip, char **key_list, char **value_list, int n, char *title, char *info, char *requirements, char *example, int (*validate_func)(char *));
	int validate_nome(char *numero);
	int validate_RG(char *RG);
	int validate_CPF(char *CPF);
	int validate_telefone(char *telefone);
	int validate_email(char *email);

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
					//printf("CADASTRO"); sleep(4); 
					//**
					char *key_list[8] = {"numero de matricula", "nome completo", "RG", "CPF", "nome do pai", "nome da mae", "telefone", "e-mail"};
					char *value_list[8] = {'\0'};
					//char value_0[200], value_1[200], value_2[200], value_3[200], value_4[200], value_5[200], value_6[200], value_7[200];
					char value[8][200];

					ask_and_validate_info(1, key_list, value_list, 8, "LIMPA", "LIMPA", "LIMPA", "LIMPA", validate_nome); // TESTE TESTE

					// numero de matricula
					strcpy(value[0], "A001");
					strcpy(dados_cadastro_aluno[0], "A001");
					value_list[0] = value[0];

					// nome completo
					strcpy(value[1], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "nome completo", "somente letras, inclua espacos", "pedro alberto", validate_nome));
					
					strcpy(dados_cadastro_aluno[1], value[1]);
					value_list[1] = value[1];
					if (strcmp(value_list[1], "⤬") == 0) break;

					// RG
					strcpy(value[2], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "RG", "somente numeros, sem  simbolos ou espacos", "1234567890", validate_RG));

					strcpy(dados_cadastro_aluno[2], value[2]);
					value_list[2] = value[2];
					if (strcmp(value_list[2], "⤬") == 0) break;

					//printf("value[0:%s] value[1:%s] value[2:%s]\n", value[0], value[1], value[2]);sleep(1);
					//printf("value_list[0:%s] value_list[1:%s] value_list[2:%s]\n", value_list[0], value_list[1], value_list[2]);sleep(1);

					// CPF
					strcpy(value[3], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "CPF", "somente numeros, sem  simbolos ou espacos", "02212533330", validate_CPF));

					strcpy(dados_cadastro_aluno[3], value[3]);
					value_list[3] = value[3];
					if (strcmp(value_list[3], "⤬") == 0) break;

					// nome do pai
					strcpy(value[4], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "nome do pai", "somente letras, inclua espacos", "pedro alberto", validate_nome));
					
					strcpy(dados_cadastro_aluno[4], value[4]);
					value_list[4] = value[4];
					if (strcmp(value_list[4], "⤬") == 0) break;

					// nome da mae
					strcpy(value[5], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "nome da mae", "somente letras, inclua espacos", "pedro alberto", validate_nome));
					
					strcpy(dados_cadastro_aluno[5], value[5]);
					value_list[5] = value[5];
					if (strcmp(value_list[5], "⤬") == 0) break;

					// telefone
					strcpy(value[6], "+55 ");
					strcat(value[6], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "telefone", "NAO COLOQUE O +55, somente numeros, sem  simbolos ou espacos, o nono digito (9) e obrigatorio", "911119999", validate_telefone));
					
					strcpy(dados_cadastro_aluno[6], value[6]);
					value_list[6] = value[6];
					if (strcmp(value_list[6], "⤬") == 0) break;

					// nome da mae
					strcpy(value[7], ask_and_validate_info(1, key_list, value_list, 8, "ALUNO", "e-mail", "@ e provedor obrigatorio", "exemplo123@gmail.com", validate_email));
					
					strcpy(dados_cadastro_aluno[7], value[7]);
					value_list[7] = value[7];
					if (strcmp(value_list[7], "⤬") == 0) break;

					getch();
					system("cls");
				}

				/**OUTROS*/

				else if (answer_cadastrar == 6) {
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

	load_bd(); // Carrega o as informações já salvas
	save_bd(); // Salva as informações

	system("pause");
}