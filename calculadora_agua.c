#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char nome[12];
   float peso;
   float consumo_agua, consumo_ideal;
   float percentual_consumo, complemento_consumo;
   int sair;
   int c;

   //define a formatação do idioma para o português (aceita acentuação)
   setlocale(LC_ALL, "Portuguese");

   while(1){
       printf("           ============ CALCULADORA DE HIDRATAÇÃO ============ ");
       printf("\n\nDescubra qual a quantidade ideal de água que você precisa diariamente");

       printf("\n\nPrimeiramente, podemos saber o seu nome? ");
       fgets(nome, 12, stdin);

       // limpa o console para exibir as próximas instruções ao usuário
       system("cls");

       printf("           ============ INSIRA SEUS DADOS ============ ");
       printf("\nSeja bem vindo, %s", nome);

       printf("\nPor favor, insira seu peso em kg: ");
       scanf("%f", &peso);

       printf("Quantos litros de água você bebe por dia? ");
       scanf("%f", &consumo_agua);
       system("cls");

       consumo_ideal = peso * 35 / 1000;
       percentual_consumo = consumo_agua / consumo_ideal * 100;

       printf("           ============ RESULTADOS ============ ");
       printf("\n\nQuantidade de água consumida: %.2fL\n", consumo_agua);
       printf("Quantidade de água ideal a ser consumida: %.2fL", consumo_ideal);

       if (consumo_agua >= consumo_ideal) {
          printf("\n\nParabéns! Você consome água o suficiente para se manter hidratado!");
       } else {
          complemento_consumo = consumo_ideal - consumo_agua;
          printf("\n\nVocê consome %.1f%% da quantidade ideal de água diária.", percentual_consumo);
          printf("\nAcrescente mais %.2fL todos os dias!", complemento_consumo);
       }

       printf("\n\nDigite 0 para SAIR ou OUTRA TECLA para REFAZER O TESTE: ");
       scanf("%d", &sair);

       // limpa o buffer de entrada e remove o caractere \n após um input
       while ((c = getchar()) != '\n' && c != EOF);

       system("cls");

       // interrompe o loop infinito quando o usuário desejar sair da aplicação
       if(sair == 0){
        break;
       }
   }
   system("cls");
   printf("Obrigado por utilizar nosso aplicativo!");

   return 0;
}