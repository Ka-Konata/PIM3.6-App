// Arquivo validations.h
// Inserindo bibliotecas

// Definindo constantes
// Cores
#define red "\x1b[31m"
#define green "\x1b[32m"
#define blue "\x1b[34m"
#define default "\x1b[0m"

int type_choices; // Auxilia na função validate_choice()
char valid_choices[4][8][200] = {{"Ciencias Exatas e da Terra", "Ciencias Biologicas", "Engenharias", "Ciencias da Saude", "Ciencias Agrarias", "Linguistica Letras e Artes", "Ciencias Sociais Aplicadas", "Ciencias Humanas"}, {"manha", "tarde", "noite"}, {"presencial", "ead"}, {"especialista", "mestre", "doutor"}}; // Opções válidas de escolha para a função validate_choice()
char *global_error_message; // Para informar erros ao longo da execução

char* ask_and_validate_info(char **key_list, char **value_list, int n, char *title, char *info, char *requirements, char *example, int (*validate_func)(char *), int skip, int alt_pos, char *to_change) 
{
	/* Pede para o usuário inserir alguma informação, e à valida logo em seguida */

	int run = 1; // Flag
	char answer[200], // Para armazenar a resposta do usuário
	cancel[200] = "cancelar", // Para identificar um cancelamento
	*ptr; // Para retorno
	
	while (run = 1) // Inicia o laço para entrada de dados
	{
		printf("==================== CADASTRANDO %s ====================\n", title); // Imprime o título
		if(alt_pos > 0) printf(green "\n(ALTERANDO CADASTRO) - Antigas Informacoes:" default "%s\n", to_change); // Para impressão caso esteja no modo de alteração de cadastro
		
		for (int i = 0; i < n; i++) // Laço para imprimir os dados já informados
		{
			printf("\n%s: ", key_list[i]); // imprime o tipo de dado
			if(value_list[i] != NULL)  printf(green "%s" default, value_list[i]); // imprime os dados já informados
		}
		printf(green "\n\nRequisitos: %s \nExemplo: %s" default, requirements, example); // imprime os requisitos e o exemplo
		printf("\n\n%.*s\n", 54+strlen(title), "===================================================================");
		printf("\n\nDigite cancelar para interromper o cadastro.\n> Informe (%s): ", info); // Pede para o usuário informar os dados
		gets(answer); // Entrada de dados

		if(skip == 0  && strlen(answer) == 0) // Caso nada seja informado
		{
			system("cls"); // Limpa a tela
			printf(red "Campo obrigatorio.\n\n" default); // Informa erro
		}
		else { // Caso contrário
			if(strcmp(answer, cancel) == 0) // Caso o usuário cancele 
			{
				system("cls"); // Limpa a tela
				return "⤬"; // Encerra a função e informa o cancelamento
			}
			else if((*validate_func)(answer)) { // Caso o dado informado passe na validação
				system("cls"); // Limpa a tela
				ptr = answer; // Prepara o retorno
				return ptr; // Encerra a função e retorna o dado informados
			}
			else // Caso outro não passe na validação
			{
				system("cls"); // Limpa a tela
				printf(red "Algo deu errado. Verifique os requisitos e tente novamente." default); // Informa que há um erro
				printf(red "%s" default, global_error_message); // Imprime a mensagem global de erro 
			}
		}
	}
	
}

int validate_nome(char *nome)
{
	/* Para validação de Nomes */

	for(int i=0; i<strlen(nome); i++) // Laço para verificar cada caractere
	{
		if(!isalpha(nome[i]) && !isspace(nome[i])) { // Caso o caractere não seja um nem do alfabeto e nem uma string
			global_error_message = "\nUm ou mais caracteres nao sao letras.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
		}
	}
	return 1; // Encerra a função informando sucesso
}

int validate_num(char *num)
{
	/* Para validação de números */

	for(int i=0; i<strlen(num); i++) // Laço para verificar cada caractere
	{
		if(!isdigit(num[i])) { // Caso o caractere não seja um número
			global_error_message = "\nDeve conter apenas numeros.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
		}
	}
	return 1; // Encerra a função informando sucesso
}

int validate_CPF(char *CPF)
{
	/* Para validação de CPF */

	if (strlen(CPF) != 11) // Caso não tenha 11 caracteres
	{
			global_error_message = "\nDeve conter exatamente 11 numeros.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
	}
	int validate_num(char *num); // Define função
	if(validate_num(CPF) == 1) return 1; return 0; // Incrementa também a validação de números
}

int validate_CTPS(char *CTPS)
{
	/* Para validação de CTPS */

	char *UFs[27] = {"RO", "AC", "AM", "RR", "PA", "AP", "TO", "MA", "PI", "CE", "RN", "PB", "PE", "AL", "SE", "BA", "MG", "ES", "RJ", "SP", "PR", "SC", "RS", "MS", "MT", "GO", "DF"}, UF[2]; // Para validar UF

	if (strlen(CTPS) != 15) // Caso tenha não tenha 15 caracteres
	{
			global_error_message = "\nDeve conter exatamente 15 caracteres. Confira o exemplo.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
	}
	for(int i = 0; i < 15; i++) // Laço para validar cada caractere
	{
		if(i==7 || i==12) // Caso seja o caractere 7 ou o 12
		{
			if(!isspace(CTPS[i])) // Caso não seja um espaço
			{	
				global_error_message = "\nSepare com espacos. Confira o exemplo.\n\n"; // Altera a mensagem global de erro
				return 0; // Encerra a função informando a falha
			}
		}
		else if(i<7) // Caso seja antes do 7
		{
			if(!isdigit(CTPS[i])) // Caso não seja um número
			{
				global_error_message = "\nO numero do CTPS deve conter apenas numeros. Confira o exemplo.\n\n"; // Altera a mensagem global de erro
				return 0; // Encerra a função informando a falha
			}
		}
		else if(i<12)// Caso seja antes do 12 e depos do 7
		{
			if(!isdigit(CTPS[i])) // Caso não seja um número
			{
				global_error_message = "\nA serie do CTPS deve conter apenas numeros. Confira o exemplo.\n\n"; // Altera a mensagem global de erro
				return 0; // Encerra a função informando a falha
			}
		}
	}

    strcpy(UF, CTPS + 13); // Pega a UF
	for(int i = 0; i < 27; i++)  // Laço para verificar se a UF informada existe
	{
		if(strcmp(UFs[i], UF) == 0) return 1; // Encerra a função retornando sucesso, caso a UF exista
	}
	// Caso não exista
	global_error_message = "\nUF nao identificada.\n\n"; // Altera a mensagem global de erro
	return 0; // Encerra a função informando a falha
}

int validate_telefone(char *telefone)
{
	/* Para validação de número de telefone */

	if (strlen(telefone) != 9) // Caso não tenha 9 caracteres
	{
			global_error_message = "\nDeve conter exatamente 9 numeros. Nao esqueca de incluir o nono digito.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
	}
	int validate_num(char *num); // Define a função
	if(validate_num(telefone) == 1) return 1; return 0; // Incrementa a validação de número
}

int validate_email(char *email)
{
	/* Para validação de e-mail */

	if (!strstr(email, "@") || !strstr(email, ".")) // Caso não tenha um @ ou um .
	{
			global_error_message = "\nE obrigatorio inserir @ e o provedor.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
	}
	return 1; // Encerra a função informando sucesso
}

int validate_choice(char *choice)
{
	/* Para validar escolha */

	int validate_nome(char *choice); // Define a função
	if (validate_nome(choice) == 1) // Caso sejam apenas letras
	{
		for(int i = 0; i < 8; i++) { // Laço para verificar se a escolha é válida
			if(strcmp(choice, valid_choices[type_choices][i]) == 0) return 1;  // Encerra a função informando sucesso, caso seja válida
		}
		global_error_message = "\nEscolha nao identificada.\n\n"; // Altera a mensagem global de erro
		return 0; // Encerra a função informando a falha
	}
	return 0; // Encerra a função informando a falha
}

int validate_turma(char *turma)
{
	/* Para validação de nome da turma */

	for(int i=0; i<strlen(turma); i++) // Laço para validar cada caractere
	{
		if(!isalpha(turma[i]) && !isdigit(turma[i])) { // Caso não seja nem do alfabeto e nem um número
			global_error_message = "\nUm ou mais caracteres nao sao letras ou numeros.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
		}
	}
	return 1; // Encerra a função informando sucesso
}

int validate_codigo(char *codigo)
{
	/* Para validação de nome da turma */
	
	for(int i=0; i<strlen(codigo); i++) // Laço para validar cada caractere
	{
		if(isspace(codigo[i])) { // Caso seja um espaço
			global_error_message = "\nNao pode conter espacos.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
		}
	}
	return 1; // Encerra a função informando a sucesso
}

int validate_funcional(char *funcional)
{
	/* Para validação de nome da turma */
	
	if (strlen(funcional) != 6) // Caso não tenha 6 caracteres
	{
			global_error_message = "\nDeve conter exatamente 6 numeros.\n\n"; // Altera a mensagem global de erro
			return 0; // Encerra a função informando a falha
	}
	int validate_num(char *num); // Define a função
	if(validate_num(funcional) == 1) return 1; return 0; // Verifica se tem apenas números
}