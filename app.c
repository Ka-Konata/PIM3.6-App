// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
//#include <json.c/json.h>

// Definindo constantes
// Cores
#define red "\x1b[31m"
#define green "\x1b[32m"
#define blue "\x1b[34m"
#define default "\x1b[0m"
// Path para os arquivos .json
#define BD_ALUNOS_PATH "bd/bd_alunos.json"
#define BD_CURSOS_PATH "bd/bd_cursos.json"
#define BD_TURMAS_PATH "bd/bd_turmas.json"
#define BD_DISCIPLINAS_PATH "bd/bd_disciplinas.json"
#define BD_PROFESSORES_PATH "bd/bd_professores.json"
#define BD_SIZE 1024

// Para armazenar os arquivos em strings
char bd_alunos[BD_SIZE] = {0};
char bd_cursos[BD_SIZE] = {0};
char bd_turmas[BD_SIZE] = {0};
char bd_disciplinas[BD_SIZE] = {0};
char bd_professores[BD_SIZE] = {0};
// Para armazenar as informações dos arquivos em formato de arrays
char bd_alunos_arr[500][8][200];
char bd_cursos_arr[20][4][200];
char bd_turmas_arr[100][4][200];
char bd_disciplinas_arr[300][5][200];
char bd_professores_arr[50][8][200];
// Para informar erros ao longo da execução
char *global_error_message;

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

char* ask_and_validate_info(int skip, char **key_list, char **value_list, int n, char *title, char *info, char *requirements, char *example, int (*validate_func)(char *)) 
{
	int run = 1, c = 0;
	char answer[200], cancel[200] = "cancelar", *ptr;
	
	while (run = 1)
	{
		printf("=================== CADASTRANDO %s ===================\n\n", title);
		for (int i = 0; i < n; i++)
		{
			printf("\n%s: ", key_list[i]);
			if(value_list[i] != NULL)  printf(green "%s" default, value_list[i]);
		}
		printf(green "\n\nRequisitos: %s \nExemplo: %s" default, requirements, example);

		printf("\n\nDigite cancelar para interromper o cadastro.\n> Informe (%s) [tentativa %d]: ", info, c);
		gets(answer);

		if(strcmp(answer, cancel) == 0)
		{
			system("cls");
			return "⤬";
		}
		
		else if((*validate_func)(answer)) {
			system("cls");
			ptr = answer;
			return ptr;
		}
		else
		{
			system("cls");
			printf(red "Algo deu errado. Verifique os requisitos e tente novamente." default);
			printf(red "%s" default, global_error_message);
		}
	}
	
}

int validate_nome(char *numero_de_matricula)
{
	for(int i=0; i<strlen(numero_de_matricula); i++)
	{
		if(!isalpha(numero_de_matricula[i]) && !isspace(numero_de_matricula[i])) {
			global_error_message = "\nUm ou mais caracteres nao sao letras.\n\n";
			return 0;
		}
	}
	
	return 1;
}

int validate_RG(char *RG)
{
	for(int i=0; i<strlen(RG); i++)
	{
		if(!isdigit(RG[i])) {
			global_error_message = "\nDeve conter apenas numeros.\n\n";
			return 0;
		}
	}
	
	return 1;
}

int validate_CPF(char *CPF)
{
	if (strlen(CPF) != 11)
	{
			global_error_message = "\nDeve conter exatamente 11 numeros.\n\n";
			return 0;
	}
	
	for(int i=0; i<strlen(CPF); i++)
	{
		if(!isdigit(CPF[i])) {
			global_error_message = "\nDeve conter apenas numeros.\n\n";
			return 0;
		}
	}
}

int validate_telefone(char *telefone)
{
	if (strlen(telefone) != 9)
	{
			global_error_message = "\nDeve conter exatamente 9 numeros. Nao esqueca de incluir o nono digito.\n\n";
			return 0;
	}
	
	for(int i=0; i<strlen(telefone); i++)
	{
		if(!isdigit(telefone[i])) {
			global_error_message = "\nDeve conter apenas numeros.\n\n";
			return 0;
		}
	}
}

int validate_email(char *email)
{
	if (!strstr(email, "@") || !strstr(email, "."))
	{
			global_error_message = "\nE obrigatorio inserir @ e o provedor.\n\n";
			return 0;
	}
	
}

void load_bd()
{
	// Definindo funções
	char get_bd_as_a_vector(char *bd, char *which_bd, const int TABLE_RANGE);

	// Abre os arquivos
	FILE *f_alunos = fopen(BD_ALUNOS_PATH, "r");
	FILE *f_cursos = fopen(BD_CURSOS_PATH, "r");
	FILE *f_turmas = fopen(BD_TURMAS_PATH, "r");
	FILE *f_disciplinas = fopen(BD_DISCIPLINAS_PATH, "r");
	FILE *f_professores = fopen(BD_PROFESSORES_PATH, "r");

	// Salva as informações dos arquivos em strings
	fread(bd_alunos, BD_SIZE, 1, f_alunos);
	fread(bd_cursos, BD_SIZE, 1, f_cursos);
	fread(bd_turmas, BD_SIZE, 1, f_turmas);
	fread(bd_disciplinas, BD_SIZE, 1, f_disciplinas);
	fread(bd_professores, BD_SIZE, 1, f_professores);

	// Converte as informações em matrizes 3d
	get_bd_as_a_vector(bd_alunos, "alunos", 8);
	get_bd_as_a_vector(bd_cursos, "cursos", 4);
	get_bd_as_a_vector(bd_turmas, "turmas", 4);
	get_bd_as_a_vector(bd_disciplinas, "disciplinas", 5);
	get_bd_as_a_vector(bd_professores, "professores", 8);

	// Fecha os arquivos
	fclose(f_alunos);
	fclose(f_cursos);
	fclose(f_turmas);
	fclose(f_disciplinas);
	fclose(f_professores);
}

void save_bd()
{
	// Definindo funções
	char construct_bd_string(char *which_bd, char *file_path, int table_range, const int VALUE_RANGE);

	construct_bd_string("alunos", BD_ALUNOS_PATH, 500, 8);
	construct_bd_string("cursos", BD_CURSOS_PATH, 20, 4);
	construct_bd_string("turmas", BD_TURMAS_PATH, 100, 4);
	construct_bd_string("disciplinas", BD_DISCIPLINAS_PATH, 300, 5);
	construct_bd_string("professores", BD_PROFESSORES_PATH, 50, 8);
}

void check_bd()
{
	char paths[5][25] = {"bd/bd_alunos.json", "bd/bd_cursos.json", "bd/bd_turmas.json", "bd/bd_disciplinas.json", "bd/bd_professores.json"};
	// Para criar os arquivos caso necessário
	char reset_bd[5][150] = {"{\"0\":[\"numero de matricula\",\"nome completo\",\"RG\",\"CPF\",\"nome do pai\",\"nome da mae\",\"telefone\",\"e-mail\"]}", "{\"0\":[\"codigo do curso\",\"nome do curso\",\"carga horaria total\",\"areas do conhecimento\"]}", "{\"0\":[\"codigo da turma\",\"nome da turma\",\"periodo\",\"limite maximo de alunos matriculados\"]}", "{\"0\":[\"codigo da disciplina\",\"nome da disciplina\",\"carga horaria semanal\",\"carga horaria total\",\"tipo\"]}", "{\"0\":[\"numero da funcional\",\"nome completo\",\"titularidade\",\"RG\",\"CPF\",\"CPTS\",\"telefone\",\"e-mail\"]}"};

	for (int i = 0; i < 5; i++)
	{
		FILE *actual_file = fopen(paths[i], "r");
		if (!actual_file)
		{
			mkdir("bd", 0777);
			FILE *f = fopen(paths[i], "w+");

			fputs(reset_bd[i], f);
			fclose(f);
			printf(red "Arquivo [%s] nao encontrado... Criado com sucesso\n" default, paths[i]);
			sleep(1);
		}
	}
}

char construct_bd_string(char *which_bd, char *file_path, int table_range, const int VALUE_RANGE)
{
	// Definindo variáveis
	char new_file_complete[800000] = "{", // Arquivo após compactado em uma única string
		new_file[800000] = " ",			  // Arquivo (vai sofrer muitas alterações)
		(*bd_arr)[VALUE_RANGE][200],	  // Matriz do bd a ser usada
		table_num[2] = " ";				  // Para auxilar na criação da strig
	int i, j;							  // Contadores

	FILE *f = fopen(file_path, "w"); // Abre o arquivo escolhido

	// Estrutura para verifica qual arquivo foi escolhido para processar
	if (which_bd == "alunos")	// Caso seja alunos
		bd_arr = bd_alunos_arr; // O ponteiro aponta para a matriz alunos
	else if (which_bd == "cursos")
		bd_arr = bd_cursos_arr;
	else if (which_bd == "turmas")
		bd_arr = bd_turmas_arr;
	else if (which_bd == "disciplinas")
		bd_arr = bd_disciplinas_arr;
	else if (which_bd == "professores")
		bd_arr = bd_professores_arr;

	for (i = 0; i < table_range; i++) // Para cada table
	{
		sprintf(table_num, "%d", i);		   // Define o número da table como string
		memset(new_file, 0, strlen(new_file)); // Evita um problema, limpando a variavel new_file
		strcat(new_file, "\"");				   // Acrescenta uma " à string

		if (i < 10)							 // Caso o numero da table seja menor que 10
			strncat(new_file, table_num, 1); // Acrescenta o numero da table à string
		else								 // Caso o numero da table seja maior que 10
			strncat(new_file, table_num, 2); // Acrescenta o numero da table à string
		strcat(new_file, "\":[");			 // Acrescenta "outra " e um [ à string

		for (j = 0; j < VALUE_RANGE; j++) // Para cada valor da table
		{
			strcat(new_file, bd_arr[i][j]); // Acrescenta o valor à string
			if (j != VALUE_RANGE - 1)		// Verifica se precisa ou não da virgula
				strcat(new_file, ",");		// Acrescenta a virgula
		}

		strcat(new_file, "]");					// Acrescenta um ] à string
		if (strstr(bd_arr[i][j], "\"") == NULL) // Verifica se ainda tem informações na matriz para salvar
		{
			strcat(new_file_complete, new_file); // Insere as alterações na variavel new_file_complete
			break;								 // Encerra o laço antecipadamente
		}
		if (i != (table_range - 1)) // Verifica se já processou a matriz completamente
		{
			strcat(new_file, ","); // Acrescenta uma , à string
		}
		strcat(new_file_complete, new_file); // Insere as alterações na variavel new_file_complete
	}

	strcat(new_file_complete, "}"); // Fecha a string com uma }
	fputs(new_file_complete, f);	// Salva as informações no arquivo
	fclose(f);						// Fecha o arquivo

	free(new_file_complete); // Limpa
	free(new_file);			 // Limpa
}

char get_bd_as_a_vector(char *bd, char *which_bd, const int TABLE_RANGE)
{
	// --------------------------------------- Propósito --------------------------------------------//
	// É selecionado qual arquivo quer manipular. Faz uma cópia temporária deste e armazena suas     //
	// informações em formato de array, para que possa ser mais facilmente usado ao longo do produto //
	// ----------------------------------------------------------------------------------------------//

	// Definindo funções
	int get_substr_position(char *source, char *substr);

	// Definindo variáveis
	char *bd_clear = (char *)malloc(strlen(bd) + 1), // Cópia da variável global original para ser manipulada
		index[5],									 // Para encontrar a posição da informação desejada dentro da string
		table[TABLE_RANGE][200],					 // Para armazenar temporariamente a informação adquirida
		*bd_table,									 // Para auxiliar na separação das informações
		separator[] = ",",							 // Separador
		(*new_bd)[TABLE_RANGE][200];				 // *new_bd[500][4][200] // Ponteiro
	int run = 1, count = 0, i;						 // Flag e contadores

	// Estrutura para verifica qual arquivo foi escolhido para processar
	if (which_bd == "alunos")	// Caso seja alunos
		new_bd = bd_alunos_arr; // O ponteiro aponta para a matriz alunos
	else if (which_bd == "cursos")
		new_bd = bd_cursos_arr;
	else if (which_bd == "turmas")
		new_bd = bd_turmas_arr;
	else if (which_bd == "disciplinas")
		new_bd = bd_disciplinas_arr;
	else if (which_bd == "professores")
		new_bd = bd_professores_arr;

	strcpy(bd_clear, bd); // Copia a variável global
	while (run == 1)
	{
		char *bd_clear_actual = (char *)malloc(bd_clear); // Warning que eu não consegui resolver ainda, mas funciona igual // Copia da cópia (é feita uma alteração nessa que não pode afetar a outra)

		sprintf(index, "%d", count); // Define o index para procurar a informação desejada
		strcat(index, "\":");

		// Alguns caracteres indesejados vão ser apagados
		if (count < 10)
			bd_clear = 4 + strstr(bd_clear, index); // Caso sejam 4 caracteres
		else if (count < 100)
			bd_clear = 5 + strstr(bd_clear, index); // Caso sejam 5 caracteres
		else
			bd_clear = 6 + strstr(bd_clear, index); // Caso sejam 6 caracteres

		strcpy(bd_clear_actual, bd_clear);				// Copia a cópia da variável global
		bd_clear_actual = strtok(bd_clear_actual, "]"); // Apaga os caracteres anteriores a certa posição

		bd_table = strtok(bd_clear_actual, separator); // Prepara parar separar as informações
		i = 0;										   // Zera o contador i

		while (bd_table != NULL)
		{
			strcpy(table[i], bd_table);			// Guarda uma informação da table
			bd_table = strtok(NULL, separator); // Próxima informação
			i++;								// soma contador
		}

		for (int c1 = 0; c1 < (int)(sizeof(table) / sizeof(table[0])); c1++) // Salva as informaçoes na matriz
		{
			strcpy(new_bd[count][c1], table[c1]); // Salva a informação
												  // printf("%s\n", new_bd[count][c1]);
		}

		// printf("index = %s | table = [%s, %s, %s, %s]\n", index, table[0], table[1], table[2], table[3]);
		// printf("bd_clear = %s\n", bd_clear);

		count++;							 // Soma contador
		if (strstr(bd_clear, "\":") == NULL) // Flag | verifica se é para encerrar o laço
			break;							 // Encerra o laço
	}
	// printf("\n\nbd_clear = %s\n", bd_clear);
}

int get_substr_position(char *source, char *substr)
{
	// --------------------------------------- Propósito --------------------------------------------//
	// Retorna a posição de uma substring em uma string, encontrada através do parâmetro "source"    //
	// ----------------------------------------------------------------------------------------------//

	// Definindo variáveis
	char *index;	  // Para encontrar a substring
	int str_position; // Posição da substring

	index = strstr(source, substr); // Encontra a substring
	str_position = index - source;	// Define a localização da substring no formato int
	return str_position;			// Retorna a posição
}