// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

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
    		mkdir("bd", 0700);
			FILE *f = fopen(paths[i], "w+");

			fputs(reset_bd[i], f);
			fclose(f);
			printf(red "Arquivo [%s] nao encontrado... Criado com sucesso\n" default, paths[i]);
			sleep(1);
		}
	}
}

void insert_to_bd(int c_bd, int M, int N, char **table) { 
	int i, j, k, lpos_A, lpos_B;
	char (*bd_ptr)[N][200];
	switch (c_bd)
	{
		case 1:
			bd_ptr = bd_alunos_arr;
			break;
		case 2:
			bd_ptr = bd_cursos_arr;
			break;
		case 3:
			bd_ptr = bd_turmas_arr;
			break;
		case 4:
			bd_ptr = bd_disciplinas_arr;
			break;
		case 5:
			bd_ptr = bd_professores_arr;
			break;
	}

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if(strcmp(bd_ptr[i][j], "") == 0) {
				for (k = 0; k < N; k++)
				{
					char info[200] = "\0";
					strcat(info, "\"");
					strcat(info, table[k]);
					strcat(info, "\"");
					strcpy(bd_ptr[i][k], info);
				}
				return 0;
			}
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