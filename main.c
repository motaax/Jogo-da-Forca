#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sorteia_palavra_arquivo(char dest[], char nome_arquivo[]){
    char palavras[1000][50];
    int qtd = 0;
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) { 
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    // scanf ou fscanf retornam 1 quando conseguem ler uma palavra
    // podemos aproveitar isso para ler até o arquivo acabar
    while (fscanf(file, "%s ", palavras[qtd]) == 1) {
        qtd++;
    }

    fclose(file);

    srand(time(NULL)); 
    int indice = rand() % qtd; 
    strcpy(dest, palavras[indice]); 
}

void limpar_tela(){
    system("clear");
}

int main(){
    char palavra_secreta[50];
    sorteia_palavra_arquivo(palavra_secreta, "palavras.txt");

    // Implemente o jogo da forca aqui

    printf("Palavra secreta: %s\n", palavra_secreta);
    return 0;
}