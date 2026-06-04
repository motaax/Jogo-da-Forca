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

int palavra(char palavra[], char tentativas[]) {
    for(int i = 0; palavra[i] != '\0'; i++) {
        int encontrou = 0;
        for(int j = 0; tentativas[i] != '\0'; j++) {
            if(tentativas[j] == palavra[i]) {
                encontrou = 1;
                break;
            }
        }

        if(!encontrou) {
            return 0;
        }
    }

    return 1;
}

int main(){
    char palavra_secreta[50];
    sorteia_palavra_arquivo(palavra_secreta, "palavras.txt");

    char tentativas[30] = "";
    int erros = 0;

    printf("Bem-vindo ao Jogo da Forca! \n");
    printf("Palavra: ");
    printf("Tentativas restantes: 6");
    printf("Informe uma letra: a");
    printf("Palavra atualizada.");
    printf("Palavra: a*****a");
    printf("Tentativas restantes: 6");
    printf("Informe uma letra: e: ");

    printf("Palavra atualizada.");
    printf("Palavra: a*e***a");
    printf("Tentativas restantes: 6");
    printf("Informe uma letra: b: ");

    printf("Letra incorreta.");
    printf("Palavra: a*e***a");
    printf("Tentativas restantes: 5");
    printf("Informe uma letra: b: ");

    printf("Palavra atualizada.");
    printf("Palavra: a*ergia");
    printf("Tentativas restantes: 3");
    printf("Informe uma letra: l: ");

    printf("Palavra atualizada.");
    printf("Palavra secreta: %s\n", palavra_secreta);
    printf("Parabens! Voce ganhou!");


    return 0;
}