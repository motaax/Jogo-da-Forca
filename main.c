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

int achou(char palavra[], char tentativas[]) {
    for(int i = 0; palavra[i] != '\0'; i++) {
        int encontrou = 0;

        for(int j = 0; tentativas[j] != '\0'; j++) {
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
    int num = 0;
    int erros = 0;
    char letra;

    printf("Bem-vindo ao Jogo da Forca! \n");

    for(; erros < 6 && !achou(palavra_secreta, tentativas);) {
        printf("Palavra: ");
        for(int i = 0; palavra_secreta[i] != '\0'; i++) {
            int achou = 0;
            for(int j = 0; tentativas[j] != '\0'; j++) {
                if(tentativas[j] == palavra_secreta[i]) {
                    achou = 1;
                    break;
                }
            }

            if(achou) {
                printf("%c", palavra_secreta[i]);
            } else {
                printf("*");
            }
        }

        printf("\n");

        printf("Tentativas restantes: %d \n", 6 - erros);

        printf("Letras usadas: ");
        for(int i = 0; tentativas[i] != '\0'; i++) {
            printf("%c ", tentativas[i]); 
        }

        printf("\nInforme uma letra: ");
        scanf(" %c", &letra);

        int tentou = 0;
        for(int j = 0; tentativas[j] != '\0'; j++) {
            if(tentativas[j] == letra) {
                tentou = 1;
                break;
            }
        }

        if(!tentou) {
            tentativas[num] = letra;
            num++;
            tentativas[num] = '\0';

            int encontrou = 0;
            for(int i = 0; palavra_secreta[i] != '\0'; i++) {
                if(palavra_secreta[i] == letra) {
                    encontrou = 1;
                    break;
                }
            }

            limpar_tela();

            if(encontrou) {
                printf("Palavra atualizada.\n");
            } else {
                printf("Letra incorreta.\n");
                erros++;
            }
        } 
    }

    if(achou(palavra_secreta, tentativas)) {
        printf("Palavra secreta: %s\n", palavra_secreta);
        printf("Parabens! Voce ganhou!\n");
    } else {
        printf("Voce perdeu! \n");
        printf("Palavra secreta: %s\n", palavra_secreta);
    }

    return 0;
}