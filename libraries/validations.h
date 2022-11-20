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

int type_choices;
char valid_choices[3][8][200] = {{"Ciencias Exatas e da Terra", "Ciencias Biologicas", "Engenharias", "Ciencias da Saude", "Ciencias Agrarias", "Linguistica Letras e Artes", "Ciencias Sociais Aplicadas", "Ciencias Humanas"}, {"manha", "tarde", "noite"}, {"presencial", "ead"}};

// Para informar erros ao longo da execução
char *global_error_message;

char* ask_and_validate_info(char **key_list, char **value_list, int n, char *title, char *info, char *requirements, char *example, int (*validate_func)(char *), int skip) 
{
	int run = 1;
	char answer[200], cancel[200] = "cancelar", *ptr;
	
	while (run = 1)
	{
		printf("==================== CADASTRANDO %s ====================\n", title);
		for (int i = 0; i < n; i++)
		{
			printf("\n%s: ", key_list[i]);
			if(value_list[i] != NULL)  printf(green "%s" default, value_list[i]);
		}
		printf(green "\n\nRequisitos: %s \nExemplo: %s" default, requirements, example);
		printf("\n\n%.*s\n", 54+strlen(title), "===================================================================");

		printf("\n\nDigite cancelar para interromper o cadastro.\n> Informe (%s): ", info);
		gets(answer);

		if(skip == 0  && strlen(answer) == 0)
		{
			system("cls");
			printf(red "Campo obrigatorio.\n\n" default);
		}

		else {
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
	
}

int validate_nome(char *nome)
{
	for(int i=0; i<strlen(nome); i++)
	{
		if(!isalpha(nome[i]) && !isspace(nome[i])) {
			global_error_message = "\nUm ou mais caracteres nao sao letras.\n\n";
			return 0;
		}
	}
	
	return 1;
}

int validate_num(char *num)
{
	for(int i=0; i<strlen(num); i++)
	{
		if(!isdigit(num[i])) {
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
	
	int validate_num(char *num);
	if(validate_num(CPF) == 1) return 1; return 0;
}

int validate_telefone(char *telefone)
{
	if (strlen(telefone) != 9)
	{
			global_error_message = "\nDeve conter exatamente 9 numeros. Nao esqueca de incluir o nono digito.\n\n";
			return 0;
	}
	
	int validate_num(char *num);
	if(validate_num(telefone) == 1) return 1; return 0;
}

int validate_email(char *email)
{
	if (!strstr(email, "@") || !strstr(email, "."))
	{
			global_error_message = "\nE obrigatorio inserir @ e o provedor.\n\n";
			return 0;
	}
}

int validate_choice(char *choice)
{
	int validate_nome(char *choice);

	if (validate_nome(choice) == 1)
	{
		for(int i = 0; i < 8; i++) {
			if(strcmp(choice, valid_choices[type_choices][i]) == 0) return 1;
		}
		global_error_message = "\nEscolha nao identificada.\n\n";
		return 0;
	}
	return 0;
}

int validate_turma(char *nome)
{
	for(int i=0; i<strlen(nome); i++)
	{
		if(!isalpha(nome[i]) && !isdigit(nome[i])) {
			global_error_message = "\nUm ou mais caracteres nao sao letras ou numeros.\n\n";
			return 0;
		}
	}
	
	return 1;
}