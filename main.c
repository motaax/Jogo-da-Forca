#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao para sortear uma palavra de um arquivo
// Nao precisa alterar
void sorteia_palavra_arquivo(char dest[], char nome_arquivo[]){
    char palavras[1000][50];
    int qtd = 0;
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) { // verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    // scanf ou fscanf retornam 1 quando conseguem ler uma palavra
    // podemos aproveitar isso para ler até o arquivo acabar
    while (fscanf(file, "%s ", palavras[qtd]) == 1) {
        qtd++;
    }
    fclose(file);
    // sorteio da palavra
    srand(time(NULL)); // inicializa o gerador de números aleatórios
    int indice = rand() % qtd; // escolhe um índice aleatório entre 0 e qtd-1
    strcpy(dest, palavras[indice]); // copia a palavra sorteada para dest
}

// Limpa a tela dos printfs (somente Linux)
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