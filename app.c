// Inserindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
//#include <json.c/json.h>

// Definindo Funções
// [...]

// Definindo constantes
#define BD_path "bd/teste.json"
#define BD_size 1024

// Código Principal
int main(void) {
    char buffer[BD_size] = {0};

    FILE * f = fopen(BD_path, "r");
    fread(buffer, BD_size, 1, f);


    printf("Arquivo aberto/criado com sucesso!\n"); //DEBUG
    printf("%s\n", buffer); //DEBUG
    fclose(f);
    system("pause");
} 