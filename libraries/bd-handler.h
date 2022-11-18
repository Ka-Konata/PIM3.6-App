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

// Para informar erros ao longo da execução
char *global_error_message;

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