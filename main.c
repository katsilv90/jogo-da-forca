#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char palavra[32], mostrar[32], letra, jogar;
    int tentativas = 0 , acertou= 0;
    int letracerta;


    printf("Escreva uma palavra secreta: ");
    scanf("%s", &palavra);

    system("cls");
    printf("*** Jogo da Forca ***\n");
    printf("\nTem 10 tentativas!\n");


    for (int i = 0; i <strlen(palavra); i++) {   //mostra espaços da palavra secreta
            mostrar[i] = '_';
        }

    do {
            printf("\nPalavra: ");                                 //mostra letras existentes na palavra
            for (int i = 0; i < strlen(palavra); i++) {
                printf("%c ", mostrar[i]);
            }

            printf("\nDigite uma letra: ");
            scanf(" %c", &letra);

            letracerta = 0;

            for (int i = 0; i < strlen(palavra); i++) {
                if (palavra[i] == letra && mostrar[i] == '_') {
                    mostrar[i] = letra;
                    acertou++;
                    letracerta = 1;
                }
            }

            tentativas++;
            printf("\nTentativa número %d .", tentativas);

            if (letracerta){
                printf("\nLetra correta!\n");
            }else{
            printf("\nLetra errada!\n");
            }
    } while (tentativas < 10 && acertou < strlen(palavra));

        if (acertou == strlen(palavra)) {
            printf("\nParabéns acertou! A palavra era: %s\n", palavra);
        } else {
            printf("\nPerdeu! A palavra era: %s\n", palavra);
        }

    system("pause");
    return 0;
}
