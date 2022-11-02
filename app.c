// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include <json.c/json.h>

// Definindo constantes
#define BD_ALUNOS_PATH "bd/bd_alunos.json"
#define BD_SIZE 1024

// Para armazenar os arquivos em strings
char bd_alunos[BD_SIZE] = {0};
char bd_cursos[BD_SIZE] = {0};
char bd_turmas[BD_SIZE] = {0};
char bd_disciplinas[BD_SIZE] = {0};
char bd_professires[BD_SIZE] = {0};
// Para armazenar as informações dos arquivos em formato de arrays
char bd_alunos_arr[500][4][200];
char bd_cursos_arr[1][1][1];
char bd_turmas_arr[1][1][1];
char bd_disciplinas_arr[1][1][1];
char bd_professores_arr[1][1][1];

// Código Principal
int main(void)
{
	// setlocale(LC_ALL, );
	//  Definindo funções
	char get_bd_as_a_vector(char *bd, char *which_bd);

	FILE *f = fopen(BD_ALUNOS_PATH, "r");	 // Abre um arquivo
	fread(bd_alunos, BD_SIZE, 1, f);		 // Salva as informações do arquivo me strings
	get_bd_as_a_vector(bd_alunos, "alunos"); // Converte as informações em matrizes 3d

	// printf("Arquivo aberto/criado com sucesso!\n"); //DEBUG
	// printf("bd_alunos: %s\n", bd_alunos); //DEBUG

	// for (int i = 0; i < 500; i++)
	//{
	//	for(int c1 = 0; c1 < 4; c1++) {
	//		printf("%s\n", bd_alunos_arr[i][c1]);
	//	}
	// }

	// fclose(f);
	system("pause");
}

// Definindo Funções
// [...]

char get_bd_as_a_vector(char *bd, char *which_bd)
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
		table[4][200],								 // Para armazenar temporariamente a informação adquirida
		*bd_table,									 // Para auxiliar na separação das informações
		separator[] = ",",							 // Separador
		(*new_bd)[4][200];							 //*new_bd[500][4][200] // Ponteiro
	int run = 1, count = 0, i;						 // Flag e contadores

	if (which_bd == "alunos")
	{							// Verifica qual arquivo foi escolhido para processar
		new_bd = bd_alunos_arr; // Cria um ponteiro apontando para a matriz
	}

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
	char *index;      // Para encontrar a substring
	int str_position; // Posição da substring

	index = strstr(source, substr); // Encontra a substring
	str_position = index - source;  // Define a localização da substring no formato int 
	return str_position;            // Retorna a posição
}