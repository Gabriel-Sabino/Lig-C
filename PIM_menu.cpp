#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "PIM_Funcoes.cpp" // Inportando código das funções

// Função responsável pelo menu;
int main(){
	
	//variaveis de tela
	int tela;
	int proxima_tela;
	
	// variaveis de tela gerente
	int matricula_gerente,senha_gerente,tela_gerente;
	
	do{
		printf("\n---- LOJA DE SAPATOS - MENU ----\n");
		printf("- Tela de gerente [1]\n");
		printf("- Tela de vendedor [2]\n");	
		printf("- Tela de caixa [3]\n");	
		scanf("%d",&tela);
		switch (tela){
		case 1:
			do{
			printf("\n TELA DE GERENTE\n");
			printf("\n--- LOGIN ---");
			printf("\n- Matricula = 1117776\n");
			printf("\n- Senha Matricula = 1010\n");
			printf("\n- Digite sua matricula: ");
			scanf ("%d",&matricula_gerente);
			 // O switch irá chegar se a matricula está correta
			switch (matricula_gerente){
			case 1117776:
				printf("- Digite sua senha: ");
				scanf ("%d",&senha_gerente);
				// O if irá chegar se a senha está correta
				if (senha_gerente == 1010){
					printf("\n");
					printf("- Digite a opcao de tela: \n");
					printf("- Tela de cadastro [1]\n");
					printf("- Tela de pesquisa [2]\n");	
					scanf("%d",&tela_gerente);
						if(tela_gerente == 1){
							cadastro();
							printf("\n");
							printf("\n-  Digite [ 1 ] para voltar a TELA DE GERENTE");
							printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
							printf("\n-  Digite [ 0 ] para SAIR ");
							scanf("%d",&proxima_tela);
						}else if(tela_gerente == 2){
							pesquisa();
							printf("\n");
							printf("\n-  Digite [ 1 ] para voltar a TELA DE GERENTE");
							printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
							printf("\n-  Digite [ 0 ] para SAIR ");
							scanf("%d",&proxima_tela);
						}else{
							printf("\n--- OPÇÃO DE TELA INVÁLIDA!! ---\n");
							printf("\n");
							printf("\n-  Digite [ 1 ] para voltar a TELA DE GERENTE");
							printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
							printf("\n-  Digite [ 0 ] para SAIR ");
							scanf("%d",&proxima_tela);
						}
				}else{
					printf("\n--- SENHA INVÁLIDA!! ---\n");
				}
		    	break;
		    default:
		    printf("\n--- MATRICULA INVALIDA!! ---\n");
		    printf("\n");
			printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
			printf("\n-  Digite [ 0 ] para SAIR ");
			scanf("%d",&proxima_tela);
			} 
			}while(proxima_tela==1);
			break;
		case 2:
			do{
			printf("\n TELA DE VENDEDOR\n");
			pesquisa();
			printf("\n");
			printf("\n-  Digite [ 1 ] para voltar a TELA DE FUNCINARIO");
			printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
			printf("\n-  Digite [ 0 ] para SAIR ");
			scanf("%d",&proxima_tela);
			}while(proxima_tela==1);
			break;
		case 3:
			do{
			printf("\n TELA DE CAIXA\n");
			caixa();
			printf("\n");
			printf("\n-  Digite [ 1 ] para voltar a TELA DE CAIXA");
			printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
			printf("\n-  Digite [ 0 ] para SAIR ");
			scanf("%d",&proxima_tela);
			}while(proxima_tela==1);
			break;
	
		default:
			printf("\n--- OPCAO DE TELA INVALIDA!! ---\n");
			printf("\n");
			printf("\n-  Digite [ 2 ] para voltar ao MENU INICIAL ");
			printf("\n-  Digite [ 0 ] para SAIR ");
			scanf("%d",&proxima_tela);
			break;
	}
	}while(proxima_tela==2);
}
	
