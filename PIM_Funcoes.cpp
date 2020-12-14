#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#define const 20 // CONTANTE DE LINHAS = Número máximo de cadastros que o programa fará

// Variaveis Globais

/*	somatotal = ao total final da compra realizada pelo cliente
	total = ao total final da compra CASO ELE NÃO POSSUA JUROS
	op = variavel responsavel por ver se o programa se repetirá em todas as funções, menos na função caixa.
	validacao_codigo =  variavel responsavel por fazer a função cadastro parar caso haja duas matriculas ou cpf iguais cadastrados.
*/
float somatotal,total;
int op,cod_vendedor; 
int validacao=0;
int validacao_codigo=0;

// Variaves de cadastro do Funcinario
char nome[const] [50]; 
char premio[const] [50];
int ra[const]; // ra = matricula do funcionario
int cpf[const];
float meta[const];
float meta_batida[const]; // meta_batida = valor da meta batida (Por compra) pelo funcinario. Este valor é 20% do valor total do produto.
float meta_faltante[const]; // meta_faltante = valor restante da meta total.
// --------------------------------------------------------------------

//Prototipo da função:
void cadastro(); // Função cadastro fará o cadastro dos funcionários da loja
void pesquisa(); // Função pesquisa fará a pesquisa dos cadastros
int valid_ra(int); // Função valid_ra checará se há duas matrículas iguais cadastradas
int valid_cod(int); // Função valid_cod checará se a matricula do venddor digitada na tela de caixa é valida
int valid_cpf(int); // Função valid_cpf checará se há dois CPFs iguais cadastrados
int valid_meta(int); // Função valid_meta pegará o valor total de venda e abaterá 20% dele na meta do funcionário
int caixa(); // Função caixa ficará responsável pela Tela de caixa
// --------------------------------------------------------------------

int caixa (){
setlocale(LC_ALL, "Portuguese");

	//Variaveis locais caixa	

	// Struct do cliente
	
	struct cadastro_cliente{
    char nome_cliente[30], bairro_cliente[30], rua_cliente[30];
    int numCasa_cliente;
	};

 	struct cadastro_cliente cad_cliente_dados;
	
	//Variaveis Soma das mercadorias
	float soma, demais_compras,primeira_compra,acc,par; 
	char continua;
	
	//Variaveis Matrícula do funcionário
	int i=1,matricula_func,senha_func,acesso_func; 
	
	// Variaveis Forma de pagamento
	int pagamento,opPagamento,opParcela,esParcela;
	float parcela,troco,valorRecebido,juros;
	int cod_vendedor;
	
	//Variaveis CPF
	char cpf[12];  
	int icpf[12];  
	int accCPF=0,digito1,result1,result2,digito2,valor;
	
	// ------------------------------------------------------

	printf("\n---- MERCADO - CAIXA ----\n");
	
	printf("\n--- MATRICULAS E SENHA PARA ACESSO DO FUNCIONÁRIO ---");
	printf("\n- Matricula 1 = 4152387\n");
	printf("- Matricula 2 = 1234567\n");
	printf("- Matricula 3 = 7418529\n");
	printf("- Matricula 4 = 1472583\n");
	printf("- Senha Matricula 1 = 10\n");
	printf("- Senha Matricula 2 = 15\n");
	printf("- Senha Matricula 3 = 12\n");
	printf("- Senha Matricula 4 = 20\n");
	
	//Seção Matrícula do funcionário;
	// Aqui será solicitado ao caixa a matrícula e a senha para que se possa prosseguir com a compra;
	
	
	do{
		printf("\n--- LOGIN ---");
		printf("\n- Digite sua matricula: ");
		scanf ("%d",&matricula_func); // matricula_func = matrícula do funcionario
		
		//Seção validar acesso;
		//O switch ler a matrícula se caso estiver certa ele ler a senha, caso não estiver ele pede a matrícula de novo;
		switch (matricula_func){
			
			case 4152387: // matrícula de acesso, opção 1;
				printf("- Digite sua senha: ");
				scanf ("%d",&senha_func);
				
				if (senha_func == 10){
					acesso_func = true;
					printf("\n- CAIXA 01 - ANA\n"); // Caso a senha e matrícula estejam certas o acesso será verdadeiro
				}else{
					printf("\n--- SENHA INVÁLIDA!! ---\n");
				}
		    	break;
		    	
			case 1234567: //matrícula de acesso, opção 2;
				printf("- Digite sua senha: ");
				scanf ("%d",&senha_func);
				
				if (senha_func == 15){
					acesso_func = true;
					printf("\n- CAIXA 02 - GUSTAVO\n"); // Caso a senha e matrícula estejam certas o acesso será verdadeiro
				}else{
					printf("\n--- SENHA INVÁLIDA!! ---\n");
				}
				break;
				
			case 7418529: //matrícula de acesso, opção 2;
				printf("- Digite sua senha: ");
				scanf ("%d",&senha_func);
				
				if (senha_func == 12){
					acesso_func = true;
					printf("\n- CAIXA 03 - RICARDO\n"); // Caso a senha e matrícula estejam certas o acesso será verdadeiro
				}else{
					printf("\n--- SENHA INVÁLIDA!! ---\n");
				}
				break;
				
			case 1472583: //matrícula de acesso, opção 2;
				printf("- Digite sua senha: ");
				scanf ("%d",&senha_func);
				
				if (senha_func == 20){
					acesso_func = true;
					printf("\n- CAIXA 04 - ALINE\n"); // Caso a senha e matrícula estejam certas o acesso será verdadeiro
				}else{
					printf("\n--- SENHA INVÁLIDA!! ---\n");
				}
				
				break;				
				
			default:
				acesso_func == false; // Caso a senha e matrícula  não estejam certas o acesso será falso
				printf("\n--- ACESSO NEGADO!! ---\n");
				break;
		}
				i++;
				
		}while (acesso_func != true); // Enquanto acesso for diferente de verdadeiro o laço irá se repetir
			
	
	if (acesso_func = true){
		
	//Seção dados do cliente;
	//Aqui será perguntado os dados pessoais do cliente (Nome , CPF e Endereço) para sair na nota fiscal

	printf("\n--- DADOS DO CLIENTE ---");
	printf("\n- Nome: ");
	scanf(" %s",&cad_cliente_dados.nome_cliente);
	fflush(stdin);

	printf("- CPF: ");
	scanf("%s",&cpf);

	//Efetua a conversao de array de char para um array de int.  
	for(i=0;i<11;i++)  
	{  
	icpf[i]=cpf[i]-48;  
	}  
	  
	//PRIMEIRO DIGITO.  
	  
	for(i=0;i<9;i++)  
	{  
	accCPF+=icpf[i]*(10-i);  
	}  
	  
	result1=accCPF%11;  
	  
	if( (result1==0) || (result1==1) )  
	{  
	digito1=0;  
	}  
	  
	else  
	{  
	digito1 = 11-result1;  
	}  
	  
	//SEGUNDO DIGITO.  
	  
	accCPF=0;  
	  
	for(i=0;i<10;i++)  
	{  
	accCPF+=icpf[i]*(11-i);  
	}  
	  
	valor=(accCPF/11)*11;  
	result2=accCPF-valor;  
	  
	if( (result2==0) || (result2==1) )  
	{  
	digito2=0;  
	}  
	  
	else  
	{  
	digito2=11-result2;  
	}  
	  
	//RESULTADOS DA VALIDACAO.  
	  
	if((digito1==icpf[9]) && (digito2==icpf[10]))  
	{  
	
	printf("\n--- Endereço ---");
	printf("\n- Bairro: ");
	scanf(" %[^\n]s",&cad_cliente_dados.bairro_cliente);
	fflush(stdin);
	printf("- Rua: ");
	scanf(" %[^\n]s",&cad_cliente_dados.rua_cliente);
	fflush(stdin);
	printf("- Nº: ");
	scanf("%d",&cad_cliente_dados.numCasa_cliente);
	fflush(stdin);

	// Seção Soma das mercadorias ;
	//Aqui será perguntado ao caixa se ele deseja passar um ao mais produtos e no final será dado o valor total da compra;
	
	printf("\n--- COMPRAS ---\n");
	printf("\n- Digite o código do vendedor:  -");
	scanf("%d",&cod_vendedor);
	valid_cod(cod_vendedor);
	if (validacao_codigo==1){
		
	printf("\n- Digite o valor do produto: R$");
	scanf("%f",&primeira_compra); // Var primeira_compra = a primeira que o caixa passa;
	fflush(stdin);
	
	do{	
		printf("\n- Deseja passar outra compra? \n- [ S ] Sim / [ N ] Não: ");
		scanf(" %s",&continua); 
		switch (continua){
			
		case 's': case 'S':
			printf("\n- Digite o valor do produto: R$");
			scanf("%f",&demais_compras);
			acc = acc + demais_compras; // acc = acumulador das demais compras; demais_compras = todos os demais produtos que o caixa irá pssar depois do primeiro;
			soma = primeira_compra + acc; // soma = Irá somar todas as compras realizadas pelo cliente;
		break;	
			
		case 'n': case 'N':
			break;
			
		default :
			printf("\n--- OPÇÃO INVÁLIDA!! ---\n");
		}
		i++;
		
	}while (op == 's' || op =='S'); 

	if ( soma != 0){
		total = soma;
		printf("\n- O valor da compra é R$%.2f \n",total); // Caso o cliente tneha feito mais de uma compra será somado tudo e dado o valor final;
		
	} else{
		total = primeira_compra;
		printf("\n- O valor da compra é R$%.2f \n",total); //Caso haja somente uma compra o valor dela será o valor final;
	}

	// Seção Forma de pagamento ;
	//Aqui será perguntado qula a forma de pagamento que o cliente quer fazer;

	printf("\n--- FORMA DE PAGAMENTO ---");
	printf("\n- [ 1 ] Dinheiro / [ 2 ] Cartao ");
	scanf("%d",&pagamento);
	
	switch (pagamento){
	
		case 1:
			printf("\n- Digite o valor recebido em dinheiro: R$");
			scanf("%f",&valorRecebido);
			troco = valorRecebido - total;
			somatotal= total;
			valid_meta(cod_vendedor);
			if (troco < 0){
				printf("\n--- COMPRA NÃO REALIZADA - FALTANDO DINHEIRO ---\n");
			}else{	
				printf("\n- Nome: %s\n",cad_cliente_dados.nome_cliente);
				printf("- CPF: %s\n",cpf);
				printf("- Bairro: %s\n",cad_cliente_dados.bairro_cliente);
				printf("- Rua: %s\n",cad_cliente_dados.rua_cliente);
				printf("- Nº: %d\n",cad_cliente_dados.numCasa_cliente);
				printf("\n- Troco = R$ %.2f \n",troco);
				printf("- Preço final: R$%.2f\n",total);
				printf("--- OBRIGADO(A), VOLTE SEMPRE ---");
			}
			break;
		
		case 2:
			printf("\n- Selecione Débito ou Crédito \n");
			printf("- [ 1 ] Débito / [ 2 ] Crédito ");
			scanf("%d",&opPagamento);
			switch (opPagamento){
				case 1:
					somatotal= total;
					valid_meta(cod_vendedor);
					printf("\n--- DÉBITO ---\n");
					printf("\n- Nome: %s\n",cad_cliente_dados.nome_cliente);
					printf("- CPF: %s\n",cpf);
					printf("- Bairro: %s\n",cad_cliente_dados.bairro_cliente);
					printf("- Rua: %s\n",cad_cliente_dados.rua_cliente);
					printf("- Nº: %d\n",cad_cliente_dados.numCasa_cliente);
					printf("- Preço final: R$%.2f\n",total);
					printf("--- OBRIGADO(A), VOLTE SEMPRE ---");
					break;
					
				case 2:
					printf("\n- Opçoes de parcelamento \n");
					printf("\n- De 1 até 4 vezes - Sem juros \n");
					printf("\n- De 5 até 8 vezes - 1,6 do total\n");
					printf("\n- De 9 até 12 vezes - 2,0 do total \n");
					
					printf("\n- Selecione a quantidade de parcelas: ");
					scanf("%d",&opParcela);
					
						if (total <10){
								if(opParcela>1){
									printf("\n--- VALOR MINIMO PARA PARCELAR E DE 10 REIAS!! ---\n");
								}else{
									somatotal= total;
									valid_meta(cod_vendedor);
									printf("\n--- DÉBITO ---\n");
									printf("\n- Nome: %s\n",cad_cliente_dados.nome_cliente);
									printf("- CPF: %s\n",cpf);
									printf("- Bairro: %s\n",cad_cliente_dados.bairro_cliente);
									printf("- Rua: %s\n",cad_cliente_dados.rua_cliente);
									printf("- Nº: %d\n",cad_cliente_dados.numCasa_cliente);
									printf("- Preço final: R$%.2f\n",total);
									printf("--- OBRIGADO(A), VOLTE SEMPRE ---");
								
								}
						}else{
								
							if (opParcela<=4 && opParcela>=2 ){
								parcela = total/opParcela;
								somatotal= total;
								valid_meta(cod_vendedor);
								printf("\n--- CRÉDITO ---\n");
								printf("\n- Nome: %s\n",cad_cliente_dados.nome_cliente);
								printf("- CPF: %s\n",cpf);
								printf("- Bairro: %s\n",cad_cliente_dados.bairro_cliente);
								printf("- Rua: %s\n",cad_cliente_dados.rua_cliente);
								printf("- Nº: %d\n",cad_cliente_dados.numCasa_cliente);
								printf("\t- Total: R$%.2f\n",somatotal);
								printf("- Preço final: R$%.2f em %dx\n",parcela,opParcela);
								printf("--- OBRIGADO(A), VOLTE SEMPRE ---");					
								
							}else if (opParcela >=5 && opParcela<=8){
								juros = ((total*1.6)/100);
								somatotal= total+juros;
								valid_meta(cod_vendedor);
								parcela = ((total + juros)/opParcela);
								printf("\n--- CRÉDITO ---\n");
								printf("\n- Nome: %s\n",cad_cliente_dados.nome_cliente);
								printf("- CPF: %s\n",cpf);
								printf("- Bairro: %s\n",cad_cliente_dados.bairro_cliente);
								printf("- Rua: %s\n",cad_cliente_dados.rua_cliente);
								printf("- Nº: %d\n",cad_cliente_dados.numCasa_cliente);
								printf("\t- Total: R$%.2f\n",somatotal);
								printf("\t- Preço final: R$%.2f em %dx\n",parcela,opParcela);
								printf("--- OBRIGADO(A), VOLTE SEMPRE ---");
								
							}else if (opParcela >=9 && opParcela<=12){
								juros = ((total*2)/100);
								somatotal= total+juros;
								valid_meta(cod_vendedor);
								parcela = ((total+ juros)/opParcela);
								printf("\n\t--- CRÉDITO ---\n");
								printf("\n\t- Nome: %s\n",cad_cliente_dados.nome_cliente);
								printf("\t- CPF: %s\n",cpf);
								printf("\t- Bairro: %s\n",cad_cliente_dados.bairro_cliente);
								printf("\t- Rua: %s\n",cad_cliente_dados.rua_cliente);
								printf("\t- Nº: %d\n",cad_cliente_dados.numCasa_cliente);
								printf("\t- Total: R$%.2f\n",somatotal);
								printf("\t- Preço final: R$%.2f em %dx\n",parcela,opParcela);
								printf("\t--- OBRIGADO(A), VOLTE SEMPRE ---");
							}else{
								printf("\n--- FORMA DE PARCELAMENTO INVALIDA! ---\n");
							}
						
						}			
						
			}
	break;
	default:
		printf("\n--- FORMA DE PAGAMENTO NÃO ENCONTRADA!! ---\n");
	}	
	
	}else{
		printf("\n ERRO!! MATRICULA INVALIDA");
	}
	
	} else{
		printf("\n--- CPF INVALIDO!! ---\n");
	}
	
	}else{  
	printf("\n--- ACESSO NEGADO!! ---\n");
	}  
	return 0; 

}


void cadastro(){	
static int linha=1;//static: a variavel ela permanece inteira, estatica não importa onde esteja.

	do{	
		printf("\n- CPF: ");
		scanf("%d",&cpf[linha]);
		valid_cpf(cpf[linha]);
		if (validacao>=2){
			cpf[linha]=0;
			validacao=1;
		}else{
		printf("\n- RA: ");
		scanf("%d",&ra[linha]);
		valid_ra(ra[linha]);
		if (validacao>=2){
			ra[linha]=0;
			validacao=1;
	}else{
		printf("\n- Nome: ");
		scanf("%s",&nome[linha]);
		printf("\n- Meta: ");
		scanf("%f",&meta[linha]);
		meta_faltante[linha]=meta[linha];
		meta_batida[linha]=0;
		printf("\n- Premio: ");
		scanf("%s",&premio[linha]);
		linha++;
	}
		}
	printf("\n-  Digite [ 1 ] para continuar cadastrando ou 0 para sair ");
	scanf("%d",&op);
	}while (op ==1); // Enquanto op = 1 o laço repete
}


void pesquisa(){
	//variaveis locais:
	int cpf_pesquisa,ra_pesquisa,i;
	char nome_pesquisa;
	do{
		
	printf("\nDigite as opções de pesquisa \n");
	printf("- 1 para CPF\n");
	printf("- 2 para RA\n");
	scanf("%d",&op);
	switch(op){
		case 0:
			printf("\n--- OPÇÃO INVÁLIDA!! ---\n");
			printf("\n Digite [ 1 ] para fazer uma nova pesquisa ou [0] para sair ");
			scanf("%d",&op); 
			break;
		case 1:
			printf("\n- Digite o CPF: ");
			scanf("%d",&cpf_pesquisa);
			for(i=0;i<=const;i++){ //Enquanto i<=cosnt(valor contante de linhas) ele percorrerar as linhas da matriz
				if(cpf[i]==cpf_pesquisa){
					printf("\n- Nome: %s",nome[i]);
					printf("\n- CPF: %d",cpf[i]);
					printf("\n- RA: %d",ra[i]);
					printf("\n- META: %2.f",meta[i]);
					printf("\n- META BATIDA: %2.f",meta_batida[i]);
					printf("\n- META FALTANTE: %f",meta_faltante[i]);
					printf("\n- PREMIO: %s",premio[i]);
				}
			}
		printf("\n Digite [ 1 ] para continuar consultando ou [0] para sair ");
		scanf("%d",&op); 	
		break;
		
		case 2:
			printf("\n- Digite o RA: ");
			scanf("%d",&ra_pesquisa);
			for(i=0;i<=const;i++){ //Enquanto i<=cosnt(valor contante de linhas) ele percorrerar as linhas da matriz
				if(ra[i]==ra_pesquisa){
					printf("\n- Nome: %s",nome[i]);
					printf("\n- CPF: %d",cpf[i]);
					printf("\n- RA: %d",ra[i]);
					printf("\n- META: %2.f",meta[i]);
					printf("\n- META FALTANTE: %2.f",meta_faltante[i]);
					printf("\n- META BATIDA: %2.f",meta_batida[i]);
					printf("\n- PREMIO: %s",premio[i]);

				}
			}
		printf("\n Digite [ 1 ] para continuar consultando ou [0] para sair ");
		scanf("%d",&op); 	
		break;	
		
		default:
		printf("\n--- OPÇÃO INVÁLIDA!! ---\n");
		printf("\n Digite [ 1 ] para fazer uma nova pesquisa ou [0] para sair ");
		scanf("%d",&op); 
		break;
	}

	}while(op ==1);
	
}

int valid_cpf(int cpf_pesquisa){
	//variaveis locais:
	int i,valid=0;
			if(cpf_pesquisa<=0){
				printf("\n ERRO!! MATRICULA INVALIDA");
			}else{
				for(i=0;i<=const;i++){ //Enquanto i<=cosnt(valor contante de linhas) ele percorrerar as linhas da matriz
					if(cpf[i]==cpf_pesquisa){
						valid=valid+1;
					}
				}
			}
			if(valid>=2){
				validacao=valid;
				printf("\n ERRO!! Funcionario ja cadastrado");
			}
}

int valid_ra(int ra_pesquisa){
	//variaveis locais:
	
	int i,valid=0;
	
			if(ra_pesquisa<=0){
				printf("\n ERRO!! MATRICULA INVALIDA");
			}else{
				for(i=0;i<=const;i++){ //Enquanto i<=cosnt(valor contante de linhas) ele percorrerar as linhas da matriz
					if(ra[i]==ra_pesquisa){
						valid=valid+1;
						validacao_codigo=1;	
					}
				}
			}
			if(valid>=2){
				validacao=valid;
				printf("\n ERRO!! Funcionario ja cadastrado");
			}
}

int valid_cod(int ra_pesquisa){
	//variaveis locais:
	
	int i;
			if(ra_pesquisa<=0){
				printf("\n ERRO!! MATRICULA INVALIDA");
			}else{
				for(i=0;i<=const;i++){ //Enquanto i<=cosnt(valor contante de linhas) ele percorrerar as linhas da matriz
					if(ra[i]==ra_pesquisa){
						validacao_codigo=1;
						printf("\n VALIDAÇÃO COD = %d",validacao_codigo);
					}
				}
			}
}

int valid_meta(int ra_pesquisa){
	//variaveis locais:
	int i;
			if(ra_pesquisa<=0){
				printf("\n ERRO!!");
			}else{
				for(i=0;i<=const;i++){ //Enquanto i<=cosnt(valor contante de linhas) ele percorrerar as linhas da matriz
				if(ra[i]==ra_pesquisa){
				meta_batida[i]=(somatotal*20)/100;
				meta_faltante[i]=meta[i]-meta_batida[i];
				break;	
				}
				}
			}

}

