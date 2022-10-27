// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include <json.c/json.h>

// Definindo constantes
#define BD_ALUNOS_PATH "bd/bd_alunos.json"
#define BD_SIZE 1024

// Para armazenar os arquivos 
char bd_alunos[BD_SIZE] = {0};
// Para armazenar as informações dos arquivos em formato de arrays
char bd_alunos_arr;

// Código Principal
int main(void) {
	//setlocale(LC_ALL, );
	char get_bd_as_a_vector(char *bd);

    FILE * f = fopen(BD_ALUNOS_PATH, "r");
    fread(bd_alunos, BD_SIZE, 1, f);
	get_bd_as_a_vector(bd_alunos);

    //printf("Arquivo aberto/criado com sucesso!\n"); //DEBUG
    printf("bd_alunos: %s\n", bd_alunos); //DEBUG

    //fclose(f);
    system("pause");
} 

// Definindo Funções
// [...]

char get_bd_as_a_vector(char *bd) {
	int get_substr_position(char *source, char *substr);
	char *bd_clear = (char *)malloc(strlen(bd)+1);
	char index[5], *new_bd[500][4][200], table[4][200];
	int run = 1, count = 0;
	int c1, c2;

	strcpy(bd_clear, bd);
	while(run == 1) {
		char *bd_clear_actual = (char *)malloc(bd_clear); // Warning que eu não consegui resolver ainda, mas funciona igual

		sprintf(index, "%d", count);
		strcat(index, "\":");

		if (count < 10) bd_clear = 4 + strstr(bd_clear, index);
		else if (count < 100 ) bd_clear = 5 + strstr(bd_clear, index);
		else bd_clear = 6 + strstr(bd_clear, index);
		
		strcpy(bd_clear_actual, bd_clear);
		bd_clear_actual = strtok(bd_clear_actual, "]");

		char separator[] = ",";
		char *bd_table = strtok(bd_clear_actual, separator);
		int i = 0;

		while(bd_table != NULL)
		{
			strcpy(table[i], bd_table);
			bd_table = strtok(NULL, separator);
			i++;
		}

		for(c1 = 0; c1 < (int) (sizeof(table) / sizeof(table[0])); c1++) {
			strcpy(new_bd[count][c1], table[c1]);
			printf("%s\n", new_bd[count][c1]);
		}

		printf("index = %s | table = [%s, %s, %s, %s]\n", index, table[0], table[1], table[2], table[3]);
		printf("bd_clear = %s\n", bd_clear);
  
		count++;
		if(strstr(bd_clear, "\":") == NULL) break;
	}
	printf("\n\nbd_clear = %s\n", bd_clear);
}

int get_substr_position(char *source, char *substr) {
	char *index;
	int str_position;

	index = strstr(source, substr);
	str_position = index - source;
	return str_position;
}