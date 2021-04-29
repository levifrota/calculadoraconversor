#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");	
	//Declarações de variáveis que serão usadas na calculadora de binários.
	char string_binario_1[1000];//Onde será armazenado o primeiro número binário digitado pelo usuário.
	char string_binario_2[1000];//Onde será armazenado o segundo número binário digitado pelo usuário.
	int verficador_de_formatacao_1 = 0;//Onde será armazenado o resultado da verificação da escrita do primeiro número.
	int verficador_de_formatacao_2 = 0;//Onde será armazenado o resultado da verificação da escrita do segundo número.
	//Declarações de variáveis que serão usadas na calculadora de decimais.
	char operador[5];//Onde será armazenada a operação que o usuário deseja realizar.
	double numero_decimal_1 = 0.0;//Onde será armazenado o primeiro número decimal digitado pelo usuário.
	double numero_decimal_2 = 0.0;//Onde será armazenado o segundo número decimal digitado pelo usuário.
	double resultado;//Onde será armazenado o resultado da operação dos números digitados.
	//Declarações de variáveis do conversor de binário para decimal desconsiderando e considerando o bit de sinal.
	char string_binario[1000];//Onde será armazenado o número binário em forma de string.
	int binario[1000];//Onde será armazenado o número binário em forma de número inteiro.
	int expoente = 0;//Onde será armazenado o expoente para a conversão do número binário.
	int tamanho_da_string_binario;//Onde será armazenado o tamanho do número binário em forma de string.
	int tamanho_da_parte_inteira;//Onde será armazenado o tamanho da parte inteira do vetor 'string_binário' após serem retirados os espaços do número.
	int tamanho_da_parte_fracionaria; //Onde será armazenado o tamanho da parte fracionária do vetor 'string_binário' após serem retirados os espaços do número.
	int posicao; //Onde será armazenado determindadas posições do vetor binário.	
	//Declarações de variáveis do conversor de binário para decimal considerando o bit de sinal.
	int verificador_de_fracionario;
	// * Declarações de variáveis do conversor de decimal para binário
	char decimal_string [1000];
	double parte_fracionaria_do_decimal;//Onde será armazenada a parte fracionária do número decimal.
	double produto_fracionario = 0;//Onde será armazenado o produto das multiplicações da parte fracionária do número decimal.
	int *binario_inteiro;//Onde será armazenada a parte inteira do número decimal convertido para binário.
	int *binario_fracionario;//Onde será armazenada a parte fracionária do número decimal convertido para binário.
	int parte_inteira_do_decimal;//Onde será armazenada a parte inteira do número decimal.
	int parte_inteira_do_produto_fracionario;
	int quociente = 1; //Onde será armazenado o quociente das multplipas divisões inteiras.
	int tamanho_inteiro_do_binario = 0; //Onde será armazenado o tamanho da parte inteira do número binário.
	int tamanho_fracionario_do_binario = 0; //Onde será armazenado o tamanho da parte fracionária do número binário.
	int tamanho_da_string_decimal;//Onde será armazenado o tamanho do número binário em forma de string.
	// * Declarações de variáveis do conversor de decimal para binário considerando o sinal do número.
	double decimal_positivo; //Onde será armazenado o número decimal positivo.
	// * Declarações de variáveis de uso geral.
	int ultima_posicao = 0;//Onde será armazenada a última posição de determinados vetores.
	int contador;//Onde será armazenado o contador dos laços de repetições.
	int resposta;//Onde será armazenada as escolhas do usuário.
	int verficador_de_formatacao = 0;//Onde será armazenado o resultado da verificação da escrita do número.
	double decimal = 0.0; //Onde será armazenado o número decimal.
	//A seguir o usuário deve escolher entre selecionar calculadoras ou conversores.
	printf(" * Digite 1 para entrar na aba de calculadoras.\n * Digite 2 para entrar na aba de conversores.\n");
	printf("\n");
	scanf("%d", &resposta);
	printf("\n");
	//O Switch a seguir tem como finalidade dar ao usuário alternativas para utilizar o programa.
	switch(resposta)
	{
		case 1 :
			printf(" * Digite 2 para selecionar a calculadora com números binários.\n * Digite 3 para selecionar a calculadora com números decimais.\n");
			printf("\n");
			scanf("%d", &resposta);
			printf("\n");
			//O Switch a seguir tem como finalidade dar ao usuário alternativas para utilizar as calculadoras do programa.
			switch(resposta)
			{
				case 2:
					printf(" * Digite 3 para selecionar a calculadora com números binários\n   desconsiderando os bits de sinais dos números.\n * Digite 4 para selecionar a calculadora com números binários\n   considerando os bits de sinais dos números.\n");
					printf("\n");
					scanf("%d", &resposta);
					printf("\n");
					//O Switch a seguir tem como finalidade dar ao usuário alternativas para utilizar números bináriaos considerando o sinal ou não.
					switch(resposta)
					{
						case 3:
							printf(" * Tabela de possíveis operações:\n");
							printf("   - Adição: + \n");
							printf("   - Subtração: - \n");
							printf("   - Multiplicação: * \n");					
							printf("   - Divisão Inteira: div \n");
							printf("   - Divisão Fracionária: / \n");
							printf("   - Potência: ^ \n");
							printf("\n");
							printf(" * Digite uma operação matemática com apenas dois números binários\n   e uma operação, de forma infixada. Entre cada um deles digite espaço.\n   Ex: 0010+ 0010:\n");
							printf("\n");
							setbuf(stdin, NULL);
							scanf("%s %s %s", string_binario_1, operador, string_binario_2);
							printf("\n");
							//Conversão de 'string_binario_1', para decimal:
							tamanho_da_string_binario = strlen(string_binario_1);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O laço de repetição a seguir verifica se o número digitado está na formatação exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condição a seguir verifica se o primeiro digito é uma virgula ou algum espaçamento.
								if(string_binario_1[0] == ',')
								{	
									printf(" * Primeiro número inválido: não utilize virgula no inicio do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se o ultimo digito é uma virgula ou algum espaçamento.
								else if(string_binario_1[ultima_posicao] == ',' )
								{
									printf(" * Primeiro número inválido: não utilize virgula no final do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se só há caracteres válidos para binário.
								else if((string_binario_1[contador] == '1') || (string_binario_1[contador] == '0') || (string_binario_1[contador] == ','))
								{
									verficador_de_formatacao_1 = 1;
								}
								//A seguir é verificado se o caractere inválido é um ponto, ou se é outro caractere inválido qualquer.
								else
								{
									verficador_de_formatacao_1 = 0;	
									if(string_binario_1[contador] == '.')
									{
										printf(" * Primeiro número inválido: Você está utilizando a versão Brasileira do\n   programa, para números fracionários utilize virgula ao invés de ponto.\n");
									}
									else
									{
										printf(" * Primeiro número inválido: utilize somente os números 0 e 1, podendo ainda\n   haver virgula em casos de números fracionários\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verificação anterior, a conversão é realizada. 
							if(verficador_de_formatacao_1 == 1)
							{
								// O laço de repetição a seguir retira os espaços do número binário digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espaços entre os números, o condicional a seguir através da função 'isspace' verifica se em determinada posição, é um desses casos.  
									if(isspace(string_binario_1[posicao]))
									{
										//Podendo haver espaços adjacentes, o laço de repetição a seguir adiciona +1 a posição sempre que isso ocorrer. 
										do
										{
											posicao ++;
										}
										while(isspace(string_binario_1[posicao]));
									}
									//A String sem espaços será armazenada no inicio dela mesma, porém sem os espaços.
									string_binario_1[contador] = string_binario_1 [posicao]; 
									/*Não conferir se a variável 'posicao' já atingiu a quebra de linha - \n - pode resultar em conteúdos indesejáveis 
									armazenados na mesma, visto que a variável 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_1 [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espaços.
								tamanho_da_string_binario = strlen(string_binario_1); 
								//Para conversão em binário, deve-se iniciar pelo último número, a função 'strrev' inverte 'string_binário' facilitando calcular pelo último número, pois ele se torna o primeiro.
								strrev(string_binario_1);
								/* O laço de repetição a seguir converte o número binário em string, para um número inteiro, atribuindo cada caractere númerico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracionária, será atribuida ao seu valor na tabela ASCII: 44 */
								for(contador = 0;contador < tamanho_da_string_binario; contador++)
								{	
									if(string_binario_1[contador] == '1' )
									{
										binario[contador] = 1;
									}
									else if(string_binario_1[contador] == '0')
									{
										binario[contador] = 0;
									}
									else
									{
										binario[contador] = 44;
									}
								}
								//No laço de repetição a seguir, será contada a quantidade de números da parte inteira e fracionária (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_1[contador] == ',')
									{ 
										tamanho_da_parte_fracionaria  = contador;//Após inveter a String, contar até que se encontre uma virgula, é contar a quantidade de números fracionários.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//É necessário diminuir 1, pois a subtração do tamanho da string menos a parte frácionária, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para conversão da parte fracionária do binário usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se não houver parte fracionária, o tamanho da parte inteira será o contador +1 (pois inicia em 0).
									}
								}
								/*O condicional a seguir converte o número binário em número decimal. Se houver parte fracionária, 
								a conversão se iniciará por ela, se não houver. a conversão será somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a virgula como ponto de referencia para conversão entre a parte fracionária e inteira. A virgula 
										ocupa um espaço no vetor, e esse espaço diz respeito a uma posição depois da parte fracionária e uma antes do inicio parte inteira*/
										if(binario[contador] != 44)
										{
											numero_decimal_1 = numero_decimal_1 + ((binario[contador]) * (pow(2, expoente)));
											expoente ++;
										}
									}
								}
								else
								{
									for(contador = 0; contador < tamanho_da_parte_inteira; contador ++)
									{	
										numero_decimal_1 = numero_decimal_1 + ((binario[contador]) * (pow(2, expoente)));
										expoente ++;
									}		
								}
							}
							//Conversão de 'string_binario_2', para decimal:
							expoente = 0;
							tamanho_da_string_binario = strlen(string_binario_2);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O laço de repetição a seguir verifica se o número digitado está na formatação exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condição a seguir verifica se o primeiro digito é uma virgula.
								if(string_binario_2[0] == ',')
								{	
									printf(" * Segundo número inválido: não utilize virgula no inicio do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se o ultimo digito é uma virgula ou algum espaçamento.
								else if(string_binario_2[ultima_posicao] == ',' )
								{
									printf(" * Segundo número inválido: não utilize virgula no final do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se só há caracteres válidos para binário.
								else if((string_binario_2[contador] == '1') || (string_binario_2[contador] == '0') || (string_binario_2[contador] == ','))
								{
									verficador_de_formatacao_2 = 1;
								}
								//A seguir é verificado se o caractere inválido é um ponto, ou se é outro caractere inválido qualquer.
								else
								{
									verficador_de_formatacao_2 = 0;	
									if(string_binario_2[contador] == '.')
									{ 
										printf(" * Segundo número inválido: Você está utilizando a versão Brasileira do\n   programa, para números fracionários utilize virgula ao invés de ponto.\n");
									}
									else
									{
										printf(" * Segundo número inválido: utilize somente os números 0 e 1, podendo ainda\n   haver virgula em casos de números fracionários\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verificação anterior, a conversão é realizada. 
							if(verficador_de_formatacao_2 == 1)
							{
								// O laço de repetição a seguir retira os espaços do número binário digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espaços entre os números, o condicional a seguir através da função 'isspace' verifica se em determinada posição, é um desses casos.  
									if(isspace(string_binario_2[posicao]))
									{
										//Podendo haver espaços adjacentes, o laço de repetição a seguir adiciona +1 a posição sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario_2[posicao]));
									}
									//A String sem espaços será armazenada no inicio dela mesma, porém sem os espaços.
									string_binario_2[contador] = string_binario_2 [posicao]; 
									/*Não conferir se a variável 'posicao' já atingiu a quebra de linha - \n - pode resultar em conteúdos indesejáveis 
									armazenados na mesma, visto que a variável 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_2 [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espaços.
								tamanho_da_string_binario = strlen(string_binario_2); 
								//Para conversão em binário, deve-se iniciar pelo último número, a função 'strrev' inverte 'string_binário' facilitando calcular pelo último número, pois ele se torna o primeiro.
								strrev(string_binario_2);
								/* O laço de repetição a seguir converte o número binário em string, para um número inteiro, atribuindo cada caractere númerico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracionária, será atribuida ao seu valor na tabela ASCII: 44 */
								for(contador = 0;contador < tamanho_da_string_binario; contador++)
								{	
									if(string_binario_2[contador] == '1' )
									{
										binario[contador] = 1;
									}
									else if(string_binario_2[contador] == '0')
									{
										binario[contador] = 0;
									}
									else
									{
										binario[contador] = 44;
									}
								}
								//No laço de repetição a seguir, será contada a quantidade de números da parte inteira e fracionária (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_2[contador] == ',')
									{ 
										tamanho_da_parte_fracionaria  = contador;//Após inveter a String, contar até que se encontre uma virgula, é contar a quantidade de números fracionários.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//É necessário diminuir 1, pois a subtração do tamanho da string menos a parte frácionária, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para conversão da parte fracionária do binário usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se não houver parte fracionária, o tamanho da parte inteira será o contador +1 (pois inicia em 0).
									}
								}
								/*O condicional a seguir converte o número binário em número decimal. Se houver parte fracionária, 
								a conversão se iniciará por ela, se não houver. a conversão será somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a virgula como ponto de referencia para conversão entre a parte fracionária e inteira. A virgula 
										ocupa um espaço no vetor, e esse espaço diz respeito a uma posição depois da parte fracionária e uma antes do inicio parte inteira*/
										if(binario[contador] != 44)
										{
											numero_decimal_2 = numero_decimal_2 + ((binario[contador]) * (pow(2, expoente)));
											expoente ++;
										}
									}
								}
								else
								{
									for(contador = 0; contador < tamanho_da_parte_inteira; contador ++)
									{	
										numero_decimal_2 = numero_decimal_2 + ((binario[contador]) * (pow(2, expoente)));
										expoente ++;
									}		
								}
							}
							//Depois que os números forem convertidos para decimal, se estiverem de acordo com a formatação exigida, é necessário realizar o cálculo de acordo com a operação digitada e converter o resultado para binário.
							if((verficador_de_formatacao_1 == 1) && (verficador_de_formatacao_2 == 1))
							{
								if(strcmp(operador , "+") == 0)
								{
							    	resultado = numero_decimal_1 + numero_decimal_2;
								}
								else if(strcmp(operador , "-") == 0)
								{
									resultado = numero_decimal_1 - numero_decimal_2;
								}
								else if(strcmp(operador , "*") == 0)
								{
							    	resultado = numero_decimal_1 * numero_decimal_2;
								}
								else if(strcmp(operador , "div") == 0)
								{
									if(numero_decimal_2 != 0)
									{
								    	resultado = numero_decimal_1 / numero_decimal_2;
									}
									else
									{
										printf(" * Não é possível realizar divisaõ por 0");
										printf("\a");
									}
								}
								else if(strcmp(operador , "/") == 0)
								{
									if(numero_decimal_2 != 0)
									{
										resultado = numero_decimal_1 / numero_decimal_2;
									}
									else
									{
										printf(" * Não é possível realizar divisaõ por 0");
										printf("\a");
									}
								}
								else if(strcmp(operador , "^") == 0)
								{
									resultado = pow(numero_decimal_1 , numero_decimal_2);
								}
								else
								{	
									printf(" * Operação inválida: %s não é uma operação válida.\n", operador);
									printf("\a");
								}
								// - Conversão do resultado para binário.
								//Em uma divisão se o primeiro for menor que o segundo, o resultado será negativo.
								if((numero_decimal_1 < numero_decimal_2) && (strcmp(operador , "-") == 0))
								{
									decimal_positivo = resultado * -1;
									//Como 'parte_inteira_do_decimal' é uma variável do tipo inteiro, fazê-la receber o resultado é armazenar sua parte inteira.
									parte_inteira_do_decimal = decimal_positivo;
									//Como 'parte_fracionária_do_decimal' é uma variável do tipo double, fazendo-a receber o resultado menos sua parte inteira, obteremos a parte fracionária do número real (se hover).
									parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
									/*O laço de repetições a seguir define o tamanho da parte inteira do binário pela quantidade de vezes que o 
									resultado - em múltiplas divisões inteiras - for divisível por 2 , até que o quociente chegue em 0 */	
									while(quociente !=0)
									{
										quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma variável inteira, recebe a parte inteira do resto da divisão da 'parte_inteira_do_decimal' por 2.
										parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: característica de múltiplas divisões inteiras. 
										tamanho_inteiro_do_binario ++;
									}
									tamanho_inteiro_do_binario++;// Devido ao bit de sinal, acrescenta-se mais um ao tamanho do binário.
									binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocação de memória, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
									ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padrão, vetores têm sua primeira posição em zero, logo a última posição de 'binario_inteiro' é o 'tamanho_inteiro_do_binario' menos um.
									parte_inteira_do_decimal = decimal_positivo;								
									//Como o número é negativo seu primeiro digito será 1.
									binario_inteiro[0] = 1;
									for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
									{
										binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na última posição recebe o resto (% - mod) da divisão inteira da 'parte_inteira_do_decimal' por 2. 	
										quociente = parte_inteira_do_decimal/2;
										parte_inteira_do_decimal = quociente;
										ultima_posicao--;
									}
									/*Como o número é negativo, é necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
									dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/		
									ultima_posicao = tamanho_inteiro_do_binario - 1;
									while(binario_inteiro[ultima_posicao] != 1 )
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									contador = 0;
									while(contador < ultima_posicao)
									{
										if(binario_inteiro[ultima_posicao] == 1)
										{
											binario_inteiro[ultima_posicao] = 0;	
										}
										else
										{
											binario_inteiro[ultima_posicao] = 1;
										}
										ultima_posicao--;
									}
									//Exibição da parte inteira em binário.
									printf(" * O resultado da operação é: ");
									for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
									{
										printf("%d", binario_inteiro[contador]);
									}
									//Se houver parte fracionária no decimal digitado, mutiplicações definirão seu tamanho no vetor 'binario_fracionario'.
									if(parte_fracionaria_do_decimal > 0)
									{
										/*O laço de repetições a seguir define o tamanho da parte fracionária do binário pela quantidade de vezes que ela 
										é multiplicada por 2 - tendo sempre sua parte inteira retirada - até que 'produto_fracionario' se chegue em 1 */
										while(produto_fracionario != 1)
										{	
											produto_fracionario = parte_fracionaria_do_decimal * 2;
										 	parte_inteira_do_produto_fracionario = produto_fracionario;
											parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
											tamanho_fracionario_do_binario ++;
										}
										binario_fracionario = calloc(sizeof(int), tamanho_fracionario_do_binario);
										decimal_positivo = resultado * -1;
										parte_inteira_do_decimal = decimal_positivo;
										parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal; 
										produto_fracionario = 0;
										parte_inteira_do_produto_fracionario = 0;
										/*O laço de repetições a seguir armazena em 'binario_fracionario' - na posição do contador - 
										a parte inteira retirada das multiplições do 'produto_fracionario' por 2 */
										for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
										{
											produto_fracionario = parte_fracionaria_do_decimal * 2;
										 	parte_inteira_do_produto_fracionario = produto_fracionario;
											binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
											parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										}
										/*Como o número for negativo, é necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
										dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
										ultima_posicao = tamanho_fracionario_do_binario - 1;
										while(binario_fracionario[ultima_posicao] != 1 )
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										contador = 0;
										while(contador <= ultima_posicao)
										{
											if(binario_fracionario[ultima_posicao] == 1)
											{
												binario_fracionario[ultima_posicao] = 0;	
											}
											else
											{
												binario_fracionario[ultima_posicao] = 1;
											}
											ultima_posicao--;
										}
										printf(",");
										for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
										{
											printf("%d", binario_fracionario[contador]);
										}
									}
									break;
								}
								//Qualquer outra operação que tenha o primeiro número menor que o primeiro, não resultará em um resultado negativo. 
								parte_inteira_do_decimal = resultado;//Como 'parte_inteira_do_decimal' é uma variável do tipo inteiro, fazê-la receber o reaultado é armazenar sua parte inteira.
								//Como 'parte_fracionária_do_decimal' é uma variável do tipo double, fazendo-a receber o resultado menos sua parte inteira, obteremos a parte fracionária do resultado (se hover).
								parte_fracionaria_do_decimal = resultado - parte_inteira_do_decimal;
								/*O laço de repetições a seguir define o tamanho da parte inteira do binário pela quantidade de vezes que a parte
								inteira do resultado - em múltiplas divisões inteiras - for divisível por 2 , até que o quociente chegue em 0 */	
								while(quociente !=0)
								{
									quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma variável inteira, recebe a parte inteira do resto da divisão da 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: característica de múltiplas divisões inteiras. 
									tamanho_inteiro_do_binario ++;
								}
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocação de memória, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
								ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padrão, vetores têm sua primeira posição em zero, logo a última posição de 'binario_inteiro' é o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = resultado;
								/*O laço de repetição a seguir converte a parte inteira do resultado para binário, armazenando o resto de divisões 
								inteiras da 'parte_inteira_do_decimal' por 2, até que o contador do laço atinja o 'tamanho_inteiro_do_binario' */
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na última posição recebe o resto (% - mod) da divisão inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--;
								}
								//Exibição da parte inteira em binário.
								printf(" * O resultado da operação é: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracionária no resultado, mutiplicações definirão seu tamanho no vetor 'binario_fracionario'.
								if((parte_fracionaria_do_decimal > 0 ) && (strcmp(operador , "div") != 0)) 
								{
									/*O laço de repetições a seguir define o tamanho da parte fracionária do resultado pela quantidade de vezes que ela 
									é multiplicada por 2 - tendo sempre sua parte inteira retirada - até que 'produto_fracionario' se chegue em 1 */
									while(produto_fracionario != 1)
									{	
										produto_fracionario = parte_fracionaria_do_decimal * 2;
										parte_inteira_do_produto_fracionario = produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										tamanho_fracionario_do_binario ++;
									}
									binario_fracionario = calloc(sizeof(int), tamanho_fracionario_do_binario);
									parte_inteira_do_decimal = resultado;
									parte_fracionaria_do_decimal = resultado - parte_inteira_do_decimal; 
									produto_fracionario = 0;
									parte_inteira_do_produto_fracionario = 0;
									/*O laço de repetições a seguir armazena em 'binario_fracionario' - na posição do 
									contador - a parte  inteira retirada das multiplições do 'produto_fracionario' por 2 */
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
									}
									printf(",");
									for(contador = 0; contador< tamanho_fracionario_do_binario; contador ++)
									{
										printf("%d", binario_fracionario[contador]);
									}
								}
								printf("\n");	
							}
							else
							{
								printf(" * Não é possível realizar a operação. O(s) número(s) não estão no padrão\n   de escrita exigidos.\n");
								printf("\a");
							}					
						break;					
						case 4:
							printf(" * Tabela de possíveis operações:\n");
							printf("   - Adição: + \n");
							printf("   - Subtração: - \n");
							printf("   - Multiplicação: * \n");					
							printf("   - Divisão Inteira: div \n");
							printf("   - Divisão Fracionária: / \n");
							printf("   - Potência: ^ \n");
							printf("\n");
							printf(" * Digite uma operação matemática com apenas dois números binários\n   e uma operação, de forma infixada. Entre cada um deles digite espaço.\n   Ex:0010 + 0010:\n");
							printf("\n");
							setbuf(stdin, NULL);
							scanf("%s %s %s", string_binario_1, operador, string_binario_2); // Não pode haver espaços na calculadora indexada
							printf("\n");
							
							//Conversão do primeiro número digitado
							tamanho_da_string_binario = strlen(string_binario_1);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O laço de repetição a seguir verifica se o número digitado está na formatação exigida.
							for(contador = 0; contador < tamanho_da_string_binario; contador++)
							{
								//A condição a seguir verifica se o primeiro digito é uma virgula ou algum espaçamento.
								if(string_binario_1[0] == ',')
								{	
									printf(" * Primeiro número inválido: não utilize virgula no inicio do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se o ultimo digito é uma virgula ou algum espaçamento.
								else if(string_binario_1[ultima_posicao] == ',')
								{
									printf(" * Primeiro número inválido: não utilize virgula no final do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se só há caracteres válidos para binário.
								else if((string_binario_1[contador] == '1') || (string_binario_1[contador] == '0') || (string_binario_1[contador] == ','))
								{
									verficador_de_formatacao_1 = 1;
								}
								//A seguir é verificado se o caractere inválido é um ponto, ou se é outro caractere inválido qualquer.
								else
								{
									verficador_de_formatacao_1 = 0;	
									if(string_binario_1[contador] == '.')
									{
										printf(" * Primeiro número inválido: Você está utilizando a versão Brasileira do\n   programa, para números fracionários utilize virgula ao invés de ponto.\n");
									}
									else
									{
										printf(" * Primeiro número inválido: utilize somente os números 0 e 1, podendo ainda, haver\n   virgula em casos de números fracionários.\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verificação anterior, a conversão é realizada. 
							if(verficador_de_formatacao_1 == 1)
							{	
								// O laço de repetição a seguir retira os espaços do número binário digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espaços entre os números, o condicional a seguir através da função 'isspace' verifica se em determinada posição, é um desses casos.  
									if(isspace(string_binario_1[posicao]))
									{
										//Podendo haver espaços adjacentes, o laço de repetição a seguir adiciona +1 a posição sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario_1[posicao]));
									}
									string_binario_1[contador] = string_binario_1[posicao]; //A String sem espaços será armazenada no inicio dela mesma, porém sem os espaços. 
									/*Não conferir se a variável 'posicao' já atingiu a quebra de linha - \n - pode resultar em conteúdos indesejáveis 
									armazenados na mesma, visto que a variável 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_1[posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espaços.
								tamanho_da_string_binario = strlen(string_binario_1);			
								/*Se o número iniciar em 1, ou seja, for negativo, será necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
								dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
								if(string_binario_1[0] == '1')
								{
									ultima_posicao = tamanho_da_string_binario - 1; 
									//Primeiro é necessário verificar se há parte fracionária. Isso se dá pela procura da virgula.
									for(contador = 0; contador < tamanho_da_string_binario; contador++)
									{
										if(string_binario_1[contador] == ',')
										{
											verificador_de_fracionario = 1;
											break;
										}
									}
									//Se houver parte fracionária ele fara o complemento de dois nela;
									if(verificador_de_fracionario == 1)
									{
										while(string_binario_1[ultima_posicao] != '1')
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										for(contador = 0; contador < ultima_posicao; ultima_posicao--) 
										{
											if(string_binario_1[ultima_posicao] == '1')
											{
												string_binario_1[ultima_posicao] = '0';	
											}
											else if(string_binario_1[ultima_posicao] == '0')
											{
												string_binario_1[ultima_posicao] = '1';
											}
											else
											{
												string_binario_1[ultima_posicao] = ',';
												break;
											}
										}
										ultima_posicao--;//Depois do complemento da parte fracionária, ainda é necessário diminuir uma posição, por causa da virgula
									}
									//Complemento de 2 na parte inteira
									while(string_binario_1[ultima_posicao] != '1')
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									for(contador = 0; contador < ultima_posicao; ultima_posicao--) 
									{	
										if(string_binario_1[ultima_posicao] == '1')
										{
											string_binario_1[ultima_posicao] = '0';	
										}
										else
										{
											string_binario_1[ultima_posicao] = '1';
										}
									}
								}
								//Para conversão em binário, deve-se iniciar pelo último número, a função 'strrev' inverte 'string_binário' facilitando calcular pelo último número, pois ele se torna o primeiro.
								strrev(string_binario_1); 
								/* O laço de repetição a seguir converte o número binário em string, para um número inteiro, atribuindo cada caractere númerico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracionária, será atribuida ao seu valor na tabela ASCII: 44 */
								for(contador = 0;contador < tamanho_da_string_binario; contador++)
								{	
									if(string_binario_1[contador] == '1' )
									{
										binario[contador] = 1;
									}
									else if(string_binario_1[contador] == '0')
									{
										binario[contador] = 0;
									}
									else
									{
										binario[contador] = 44;
									}
								}								
								//No laço de repetição a seguir, será contada a quantidade de números da parte inteira e fracionária (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_1[contador] == ',')
									{
										tamanho_da_parte_fracionaria  = contador;//Após inveter a String, contar até que se encontre uma virgula, é contar a quantidade de números fracionários.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//É necessário diminuir 1, pois a subtração do tamanho da string menos a parte frácionária, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para conversão da parte fracionária do binário usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se não houver parte fracionária, o tamanho da parte inteira será o contador +1 (pois inicia em 0).
									}
								}						
								//Na conversão não deve ser contado o bit de sinal, logo diminui-se 1 do seu tamanho.
								tamanho_da_string_binario = tamanho_da_string_binario - 1;
								tamanho_da_parte_inteira = tamanho_da_parte_inteira - 1;
								/*O condicional a seguir converte o número binário em número decimal. Se houver parte fracionária, 
								a conversão se iniciará por ela, se não houver. a conversão será somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a vírgula como ponto de referência para conversão entre a parte fracionária e inteira. A vírgula 
										ocupa um espaço no vetor, e esse espaço diz respeito a uma posição depois da parte fracionária e uma antes do início parte inteira*/
										if(binario[contador] != 44)
										{
											numero_decimal_1 = numero_decimal_1 + ((binario[contador]) * (pow(2, expoente)));
											expoente ++;
										}
									}
								}
								else
								{
									for(contador = 0; contador < tamanho_da_parte_inteira; contador ++)
									{
										numero_decimal_1 = numero_decimal_1 + ((binario[contador]) * (pow(2, expoente)));
										expoente ++;
									}		
								}
								//Se o número inicar em 1, resultará em um resultado negativo. Porém com a utilização da função strrev, a primeira posição se tona a íltima.
								if(string_binario_1[tamanho_da_string_binario] == '1')
								{
									numero_decimal_1 = numero_decimal_1 * -1;	
								}
							}
							//Conversão do Segundo Número digitado.
							expoente = 0;
							tamanho_da_string_binario = strlen(string_binario_2);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O laço de repetição a seguir verifica se o número digitado está na formatação exigida.
							for(contador = 0; contador < tamanho_da_string_binario; contador++)
							{
								//A condição a seguir verifica se o primeiro digito é uma virgula ou algum espaçamento.
								if(string_binario_2[0] == ',')
								{	
									printf(" * Segundo número inválido: não utilize virgula no inicio do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se o ultimo digito é uma virgula ou algum espaçamento.
								else if(string_binario_2[ultima_posicao] == ',')
								{
									printf(" * Segundo número inválido: não utilize virgula no final do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se só há caracteres válidos para binário.
								else if((string_binario_2[contador] == '1') || (string_binario_2[contador] == '0') || (string_binario_2[contador] == ','))
								{
									verficador_de_formatacao_2 = 1;
								}
								//A seguir é verificado se o caractere inválido é um ponto, ou se é outro caractere inválido qualquer.
								else
								{
									verficador_de_formatacao_2 = 0;	
									if(string_binario_2[contador] == '.')
									{
										printf(" * Segundo número inválido: Você está utilizando a versão Brasileira do\n   programa, para números fracionários utilize virgula ao invés de ponto.\n");
									}
									else
									{
										printf(" * Segundo número inválido: utilize somente os números 0 e 1, podendo ainda, haver\n   virgula em casos de números fracionários.\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verificação anterior, a conversão é realizada. 
							if(verficador_de_formatacao_2 == 1)
							{	
								// O laço de repetição a seguir retira os espaços do número binário digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espaços entre os números, o condicional a seguir através da função 'isspace' verifica se em determinada posição, é um desses casos.  
									if(isspace(string_binario_2[posicao]))
									{
										//Podendo haver espaços adjacentes, o laço de repetição a seguir adiciona +1 a posição sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario_2[posicao]));
									}
									string_binario_2[contador] = string_binario_2[posicao]; //A String sem espaços será armazenada no inicio dela mesma, porém sem os espaços. 
									/*Não conferir se a variável 'posicao' já atingiu a quebra de linha - \n - pode resultar em conteúdos indesejáveis 
									armazenados na mesma, visto que a variável 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_2[posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espaços.
								tamanho_da_string_binario = strlen(string_binario_2);			
								/*Se o número iniciar em 1, ou seja, for negativo, será necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
								dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
								if(string_binario_2[0] == '1')
								{
									ultima_posicao = tamanho_da_string_binario - 1; 
									//Primeiro é necessário verificar se há parte fracionária. Isso se dá pela procura da virgula.
									for(contador = 0; contador < tamanho_da_string_binario; contador++)
									{
										if(string_binario_2[contador] == ',')
										{
											verificador_de_fracionario = 1;
											break;
										}
									}
									//Se houver parte fracionária ele fara o complemento de dois nela;
									if(verificador_de_fracionario == 1)
									{
										while(string_binario_2[ultima_posicao] != '1')
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										for(contador = 0; contador < ultima_posicao; ultima_posicao--) 
										{
											if(string_binario_2[ultima_posicao] == '1')
											{
												string_binario_2[ultima_posicao] = '0';	
											}
											else if(string_binario_2[ultima_posicao] == '0')
											{
												string_binario_2[ultima_posicao] = '1';
											}
											else
											{
												string_binario_2[ultima_posicao] = ',';
												break;
											}
										}
										ultima_posicao--;//Depois do complemento da parte fracionária, ainda é necessário diminuir uma posição, por causa da virgula
									}
									//Complemento de 2 na parte inteira
									while(string_binario_2[ultima_posicao] != '1')
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									for(contador = 0; contador < ultima_posicao; ultima_posicao--) 
									{	
										if(string_binario_2[ultima_posicao] == '1')
										{
											string_binario_2[ultima_posicao] = '0';	
										}
										else
										{
											string_binario_2[ultima_posicao] = '1';
										}
									}
								}
								//Para conversão em binário, deve-se iniciar pelo último número, a função 'strrev' inverte 'string_binário' facilitando calcular pelo último número, pois ele se torna o primeiro.
								strrev(string_binario_2); 
								/* O laço de repetição a seguir converte o número binário em string, para um número inteiro, atribuindo cada caractere númerico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracionária, será atribuida ao seu valor na tabela ASCII: 44 */
								for(contador = 0;contador < tamanho_da_string_binario; contador++)
								{	
									if(string_binario_2[contador] == '1' )
									{
										binario[contador] = 1;
									}
									else if(string_binario_2[contador] == '0')
									{
										binario[contador] = 0;
									}
									else
									{
										binario[contador] = 44;
									}
								}								
								//No laço de repetição a seguir, será contada a quantidade de números da parte inteira e fracionária (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_2[contador] == ',')
									{
										tamanho_da_parte_fracionaria  = contador;//Após inveter a String, contar até que se encontre uma virgula, é contar a quantidade de números fracionários.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//É necessário diminuir 1, pois a subtração do tamanho da string menos a parte frácionária, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para conversão da parte fracionária do binário usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se não houver parte fracionária, o tamanho da parte inteira será o contador +1 (pois inicia em 0).
									}
								}						
								//Na conversão não deve ser contado o bit de sinal, logo diminui-se 1 do seu tamanho.
								tamanho_da_string_binario = tamanho_da_string_binario - 1;
								tamanho_da_parte_inteira = tamanho_da_parte_inteira - 1;
								/*O condicional a seguir converte o número binário em número decimal. Se houver parte fracionária, 
								a conversão se iniciará por ela, se não houver. a conversão será somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a vírgula como ponto de referência para conversão entre a parte fracionária e inteira. A vírgula 
										ocupa um espaço no vetor, e esse espaço diz respeito a uma posição depois da parte fracionária e uma antes do início parte inteira*/
										if(binario[contador] != 44)
										{
											numero_decimal_2 = numero_decimal_2 + ((binario[contador]) * (pow(2, expoente)));
											expoente ++;
										}
									}
								}
								else
								{
									for(contador = 0; contador < tamanho_da_parte_inteira; contador ++)
									{
										numero_decimal_2 = numero_decimal_2 + ((binario[contador]) * (pow(2, expoente)));
										expoente ++;
									}		
								}
								//Se o número inicar em 1, resultará em um resultado negativo. Porém com a utilização da função strrev, a primeira posição se tona a íltima.
								if(string_binario_2[tamanho_da_string_binario] == '1')
								{
									numero_decimal_2 = numero_decimal_2 * -1;	
								}
							}
							//Se os dois números estiverem na formatação exigida, o cálculo será efetuado
							if((verficador_de_formatacao_1 == 1)&&(verficador_de_formatacao_2 == 1))
							{
								if(strcmp(operador , "+") == 0)
								{
							    	resultado = numero_decimal_1 + numero_decimal_2;
								}
								else if(strcmp(operador , "-") == 0)
								{
									resultado = numero_decimal_1 - numero_decimal_2;
								}
								else if(strcmp(operador , "*") == 0)
								{
							    	resultado = numero_decimal_1 * numero_decimal_2;
								}
								else if(strcmp(operador , "div") == 0)
								{
									if(numero_decimal_2 != 0)
									{
								    	resultado = numero_decimal_1 / numero_decimal_2;
									}
									else
									{
										printf(" * Não é possível realizar divisaõ por 0");
										printf("\a");
									}
								}
								else if(strcmp(operador , "/") == 0)
								{
									if(numero_decimal_2 != 0)
									{
										resultado = numero_decimal_1 / numero_decimal_2;
									}
									else
									{
										printf(" * Não é possível realizar divisaõ por 0");
										printf("\a");
									}
								}
								else if(strcmp(operador , "^") == 0)
								{
									resultado = pow(numero_decimal_1 , numero_decimal_2);
								}
								else
								{	
									printf(" * Operação inválida: %s não é uma operação válida.\n", operador);
									printf("\a");
								}
								
								if(decimal < 0)
								{
									decimal_positivo = resultado * -1;
								}
								else
								{
									decimal_positivo = resultado;
								}
								if((numero_decimal_1 < numero_decimal_2) && (strcmp(operador , "-") == 0))
								{
									decimal_positivo = resultado * -1;
									//Como 'parte_inteira_do_decimal' é uma variável do tipo inteiro, fazê-la receber o resultado é armazenar sua parte inteira.
									parte_inteira_do_decimal = decimal_positivo;
									//Como 'parte_fracionária_do_decimal' é uma variável do tipo double, fazendo-a receber o resultado menos sua parte inteira, obteremos a parte fracionária do número real (se hover).
									parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
									/*O laço de repetições a seguir define o tamanho da parte inteira do binário pela quantidade de vezes que o 
									resultado - em múltiplas divisões inteiras - for divisível por 2 , até que o quociente chegue em 0 */	
									while(quociente !=0)
									{
										quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma variável inteira, recebe a parte inteira do resto da divisão da 'parte_inteira_do_decimal' por 2.
										parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: característica de múltiplas divisões inteiras. 
										tamanho_inteiro_do_binario ++;
									}
									tamanho_inteiro_do_binario++;// Devido ao bit de sinal, acrescenta-se mais um ao tamanho do binário.
									binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocação de memória, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
									ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padrão, vetores têm sua primeira posição em zero, logo a última posição de 'binario_inteiro' é o 'tamanho_inteiro_do_binario' menos um.
									parte_inteira_do_decimal = decimal_positivo;								
									//Como o número é negativo seu primeiro digito será 1.
									binario_inteiro[0] = 1;
									for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
									{
										binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na última posição recebe o resto (% - mod) da divisão inteira da 'parte_inteira_do_decimal' por 2. 	
										quociente = parte_inteira_do_decimal/2;
										parte_inteira_do_decimal = quociente;
										ultima_posicao--;
									}
									/*Como o número é negativo, é necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
									dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/		
									ultima_posicao = tamanho_inteiro_do_binario - 1;
									while(binario_inteiro[ultima_posicao] != 1 )
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									contador = 0;
									while(contador < ultima_posicao)
									{
										if(binario_inteiro[ultima_posicao] == 1)
										{
											binario_inteiro[ultima_posicao] = 0;	
										}
										else
										{
											binario_inteiro[ultima_posicao] = 1;
										}
										ultima_posicao--;
									}
									//Exibição da parte inteira em binário.
									printf(" * O resultado da operação é: ");
									for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
									{
										printf("%d", binario_inteiro[contador]);
									}
									//Se houver parte fracionária no decimal digitado, mutiplicações definirão seu tamanho no vetor 'binario_fracionario'.
									if(parte_fracionaria_do_decimal > 0)
									{
										/*O laço de repetições a seguir define o tamanho da parte fracionária do binário pela quantidade de vezes que ela 
										é multiplicada por 2 - tendo sempre sua parte inteira retirada - até que 'produto_fracionario' se chegue em 1 */
										while(produto_fracionario != 1)
										{	
											produto_fracionario = parte_fracionaria_do_decimal * 2;
										 	parte_inteira_do_produto_fracionario = produto_fracionario;
											parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
											tamanho_fracionario_do_binario ++;
										}
										binario_fracionario = calloc(sizeof(int), tamanho_fracionario_do_binario);
										decimal_positivo = resultado * -1;
										parte_inteira_do_decimal = decimal_positivo;
										parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal; 
										produto_fracionario = 0;
										parte_inteira_do_produto_fracionario = 0;
										/*O laço de repetições a seguir armazena em 'binario_fracionario' - na posição do contador - 
										a parte inteira retirada das multiplições do 'produto_fracionario' por 2 */
										for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
										{
											produto_fracionario = parte_fracionaria_do_decimal * 2;
										 	parte_inteira_do_produto_fracionario = produto_fracionario;
											binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
											parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										}
										/*Como o número for negativo, é necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
										dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
										ultima_posicao = tamanho_fracionario_do_binario - 1;
										while(binario_fracionario[ultima_posicao] != 1 )
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										contador = 0;
										while(contador <= ultima_posicao)
										{
											if(binario_fracionario[ultima_posicao] == 1)
											{
												binario_fracionario[ultima_posicao] = 0;	
											}
											else
											{
												binario_fracionario[ultima_posicao] = 1;
											}
											ultima_posicao--;
										}
										printf(",");
										for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
										{
											printf("%d", binario_fracionario[contador]);
										}
									}
								printf("\n");
								break;
								}
								
								parte_inteira_do_decimal = decimal_positivo; //Como 'parte_inteira_do_decimal' é uma variável do tipo inteiro, fazê-la receber o número real digitado e armazenar sua parte inteira.
								//Como 'parte_fracionária_do_decimal' é uma variável do tipo double, fazê-la receber o número real menos sua parte inteira e isolar sua parte fracionária.
								parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
								/*O laço de repetições a seguir define o tamanho da parte inteira do binário pela quantidade de vezes que a parte
								inteira do decimal - em múltiplas divisões inteiras - for divisível por 2 , até que o quociente chegue em 0 */	
								while(quociente != 0)
								{
									quociente = parte_inteira_do_decimal/2; //'quociente' por ser uma variável inteira, recebe a parte inteira do resto da divisão, de 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente; //Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: característica de múltiplas divisões inteiras. 
									tamanho_inteiro_do_binario++;
								}
								
								tamanho_inteiro_do_binario++; // Devido ao bit de sinal, acrescenta-se mais um ao tamanho do binário.
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocação de memória, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. binario_inteiro[tamanho_inteiro_do_binario];
								//binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocando memória dinâmicamente, através da função calloc.
								ultima_posicao = tamanho_inteiro_do_binario - 1; //Por padrão, vetores têm sua primeira posição em zero, logo a última posição de 'binario_inteiro' é o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = decimal_positivo;
								//Se o número for negativo seu primeiro digito será 1, se não, 0.
								if(resultado < 0)
								{
									binario_inteiro[0] = 1;
								}
								else
								{
									binario_inteiro[0] = 0;
								}
								/*O laço de repetição a seguir converte a parte inteira do número decimal para binário, por armazenar o resto 
								de divisões inteiras da 'parte_inteira_do_decimal' por 2, até que o contador do laço atinja o 'tamanho_inteiro_do_binario' */		
								for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2; //O vetor 'binario_inteiro' na última posição recebe o resto (% - mod) da divisão inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--; //A cada interação a 'ultima_posição' diminui 1, preenchendo o vetor ao final.
								}
								//Se o número for negativo é necessário realizar o complemeto de 2.
								if(resultado < 0)
								{
									ultima_posicao = tamanho_inteiro_do_binario - 1;
									while(binario_inteiro[ultima_posicao] != 1 )
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									contador = 0;
									while(contador < ultima_posicao)
									{
										if(binario_inteiro[ultima_posicao] == 1)
										{
											binario_inteiro[ultima_posicao] = 0;	
										}
										else
										{
											binario_inteiro[ultima_posicao] = 1;
										}
										ultima_posicao--;
									}
								}
								//Exibição da parte inteira em binário.
								printf(" * O resultado da operação é: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracionária no decimal digitado, mutiplicações definirão seu tamanho no vetor 'binario_fracionario'.
								if((parte_fracionaria_do_decimal > 0) && (strcmp(operador , "div") != 0))
								{
									/*O laço de repetições a seguir define o tamanho da parte fracionária do binário pela quantidade de vezes que ela 
									é multiplicada por 2 - tendo sempre sua parte inteira retirada - até que 'produto_fracionario' se chegue em 1 */
									while(produto_fracionario != 1)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										tamanho_fracionario_do_binario ++;
									}
									binario_fracionario = calloc(sizeof(int), tamanho_fracionario_do_binario);
									if(decimal < 0)
									{
										decimal_positivo = decimal * -1;
									}
									else
									{
										decimal_positivo = decimal;
									}
									parte_inteira_do_decimal = decimal_positivo;
									parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal; 
									produto_fracionario = 0;
									parte_inteira_do_produto_fracionario = 0;
									/*O laço de repetições a seguir armazena em 'binario_fracionario' - na posição do contador - a parte inteira retirada
									das multiplições do 'produto_fracionario' por 2 */
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
									}
									//Se o número for negativo é necessário realizar o complemeto de 2.
									if(resultado < 0)
									{
										ultima_posicao = tamanho_fracionario_do_binario - 1;
										while(binario_fracionario[ultima_posicao] != 1 )
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										contador = 0;
										while(contador <= ultima_posicao)
										{
											if(binario_fracionario[ultima_posicao] == 1)
											{
												binario_fracionario[ultima_posicao] = 0;	
											}
											else
											{
												binario_fracionario[ultima_posicao] = 1;
											}
											ultima_posicao--;
										}
									}
									printf(",");
									for(contador = 0; contador< tamanho_fracionario_do_binario; contador ++)
									{
										printf("%d", binario_fracionario[contador]);
									}
								}
								printf("\n");
							}
							else{
								printf(" * Não é possível realizar a operação. O(s) número(s) não estão no padrão\n   de escrita exigidos.\n");
								printf("\a");
							}
						break;
						default:
							printf(" * Erro ao selecionar aba: %d não é um caso válido.\n", resposta);
							printf("\a");
						break;						
					}
				break;
				case 3:
					printf("\n");
					printf(" * Tabela de possíveis operações:\n");
					printf("   - Adição: + \n");
					printf("   - Subtração: - \n");
					printf("   - Multiplicação: * \n");					
					printf("   - Divisão Inteira: div \n");
					printf("   - Divisão Fracionária: / \n");
					printf("   - Potência: ^ \n");
					printf("\n"); 
					printf(" * Digite uma operação matemática com apenas dois números decimais \n   e uma operação, de forma infixada. Entre cada um deles digite espaço.\n   Ex: 2 + 2:\n");
					printf("\n");
					scanf("%lf %s %lf", &numero_decimal_1, operador, &numero_decimal_2);
					printf("\n");
					//O condicional a seguir através da função 'strcmp' compara o operador digitado com os operadores válidos. Se forem iguais a função retorna 0.
					if(strcmp(operador , "+") == 0)
					{
				    	resultado = numero_decimal_1 + numero_decimal_2;
				    	printf(" * O resultado da operação matemática é: %.2lf", resultado);
					}
					else if(strcmp(operador , "-") == 0)
					{
				    	resultado = numero_decimal_1 - numero_decimal_2;
				    	printf(" * O resultado da operação matemática é: %.2lf", resultado);
					}
					else if(strcmp(operador , "*") == 0)
					{
				    	resultado = numero_decimal_1 * numero_decimal_2;
				    	printf(" * O resultado da operação matemática é: %.2lf", resultado);
					}
					else if(strcmp(operador , "div") == 0)
					{
						if(numero_decimal_2 != 0)
						{
					    	resultado = numero_decimal_1 / numero_decimal_2;
					    	printf(" * O resultado da operação matemática é: %d",(int)resultado);
						}
						else
						{
							printf(" * Não é possível realizar divisaõ por 0");
							printf("\a");
						}
					}
					else if(strcmp(operador , "/") == 0)
					{
						if(numero_decimal_2 != 0)
						{
							resultado = numero_decimal_1 / numero_decimal_2;
					    	printf(" * O resultado da operação matemática é: %.2lf", resultado);
						}
						else
						{
							printf(" * Não é possível realizar divisaõ por 0");
							printf("\a");
						}
					}
					else if(strcmp(operador , "^") == 0)
					{
						resultado = pow(numero_decimal_1 , numero_decimal_2);
				    	printf(" * O resultado da operação matemática é: %.2lf", resultado);
					}else{
						printf(" * Operação inválida: %s não é uma operação válida.\n", operador);
						printf("\a");
					}
					printf("\n");
				break;
				default:
					printf(" * Erro ao selecionar aba: %d não é um caso válido.\n", resposta);
					printf("\a");
				break;
		 }
		break;
		case 2 :
			printf(" * Digite 3 para selecionar o conversor de binário para decimal.\n * Digite 4 para selecionar o conversor de decimal para binário.\n");
			printf("\n");
			scanf("%d", &resposta);
			printf("\n");
			switch(resposta)
			{
				case 3:
					printf(" * Digite 4 para selecionar o conversor de número binário, para decimal\n   desconsiderando o bit de sinal.\n * Digite 5 para selecionar o conversor de número binário para decimal\n   considerando o bit de sinal.\n");
					printf("\n");
					scanf("%d", &resposta);
					printf("\n");
					switch(resposta)
					{
						case 4:
							printf(" * Digite um número em binário - fracionário ou não - cujo deseja saber sua\n   conversão em decimal.\n   Ex: 1111 a saída será 15, se 10001,1 a saída será 17,5.\n");
							setbuf(stdin, NULL);
							printf("\n");
							gets(string_binario);
							printf("\n");
							tamanho_da_string_binario = strlen(string_binario);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O laço de repetição a seguir verifica se o número digitado está na formatação exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condição a seguir verifica se o primeiro digito é uma virgula ou algum espaçamento.
								if((string_binario[0] == ',') || (string_binario[0] == ' '))
								{	
									printf(" * Número inválido: não utilize espaçamentos ou virgula no inicio do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se o ultimo digito é uma virgula ou algum espaçamento.
								else if((string_binario[ultima_posicao] == ',' ) || (string_binario[ultima_posicao] == ' '))
								{
									printf(" * Número inválido: não utilize espaçamentos nem virgula no final do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se só há caracteres válidos para binário.
								else if((string_binario[contador] == '1') || (string_binario[contador] == '0') || (string_binario[contador] == ' ') || (string_binario[contador] == ','))
								{
									verficador_de_formatacao = 1;
								}
								//A seguir é verificado se o caractere inválido é um ponto, ou se é outro caractere inválido qualquer.
								else
								{
									verficador_de_formatacao = 0;	
									if(string_binario[contador] == '.')
									{
										printf(" * Número inválido: Você está utilizando a versão Brasileira do programa, para\n   números fracionários utilize virgula ao invés de ponto.\n");
									}
									else
									{
										printf(" * Número inválido: utilize somente os números 0 e 1, podendo ainda, haver\n   virgula em casos de números fracionários e espaçamentos entre os números\n   (exceto no incio e no final do número)\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verificação anterior, a conversão é realizada. 
							if(verficador_de_formatacao == 1)
							{
								// O laço de repetição a seguir retira os espaços do número binário digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espaços entre os números, o condicional a seguir através da função 'isspace' verifica se em determinada posição, é um desses casos.  
									if(isspace(string_binario[posicao]))
									{
										//Podendo haver espaços adjacentes, o laço de repetição a seguir adiciona +1 a posição sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario[posicao]));
									}
									//A String sem espaços será armazenada no inicio dela mesma, porém sem os espaços.
									string_binario[contador] = string_binario [posicao]; 
									/*Não conferir se a variável 'posicao' já atingiu a quebra de linha - \n - pode resultar em conteúdos indesejáveis 
									armazenados na mesma, visto que a variável 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espaços.
								tamanho_da_string_binario = strlen(string_binario); 
								//Para conversão em binário, deve-se iniciar pelo último número, a função 'strrev' inverte 'string_binário' facilitando calcular pelo último número, pois ele se torna o primeiro.
								strrev(string_binario);
								/* O laço de repetição a seguir converte o número binário em string, para um número inteiro, atribuindo cada caractere númerico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracionária, será atribuida ao seu valor na tabela ASCII: 44 */
								for(contador = 0;contador < tamanho_da_string_binario; contador++)
								{	
									if(string_binario[contador] == '1' )
									{
										binario[contador] = 1;
									}
									else if(string_binario[contador] == '0')
									{
										binario[contador] = 0;
									}
									else
									{
										binario[contador] = 44;
									}
								}
								//No laço de repetição a seguir, será contada a quantidade de números da parte inteira e fracionária (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario[contador] == ',')
									{ 
										tamanho_da_parte_fracionaria  = contador;//Após inveter a String, contar até que se encontre uma virgula, é contar a quantidade de números fracionários.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//É necessário diminuir 1, pois a subtração do tamanho da string menos a parte frácionária, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para conversão da parte fracionária do binário usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se não houver parte fracionária, o tamanho da parte inteira será o contador +1 (pois inicia em 0).
									}
								}
								/*O condicional a seguir converte o número binário em número decimal. Se houver parte fracionária, 
								a conversão se iniciará por ela, se não houver. a conversão será somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a virgula como ponto de referencia para conversão entre a parte fracionária e inteira. A virgula 
										ocupa um espaço no vetor, e esse espaço diz respeito a uma posição depois da parte fracionária e uma antes do inicio parte inteira*/
										if(binario[contador] != 44)
										{
											decimal = decimal + ((binario[contador]) * (pow(2, expoente)));
											expoente ++;
										}
									}
								}
								else
								{
									for(contador = 0; contador < tamanho_da_parte_inteira; contador ++)
									{	
										decimal = decimal + ((binario[contador]) * (pow(2, expoente)));
										expoente ++;
									}		
								}
								//O condicional a seguir trata da exibição do número convertido, se houver parte facionária no número binário ela será exibida no em seu equivalente decimal.
								if(tamanho_da_parte_fracionaria > 0)
								{
									printf(" * O número digitado convertido para decimal é: %.5lf\n", decimal);	
								}
								else
								{
									printf(" * O número digitado convertido para decimal é: %d\n", (int)decimal);
								}
							}
						break;
						case 5:
							printf(" * Digite um número em binário positivo ou negativo - fracionário ou não - cujo\n   deseja saber sua conversão em decimal, considere o primeiro número o sinal\n   do número.\n * 0 para números positivos\n * 1 para números negativo\n   Ex: 01111 a saída será 15, se 10001,01 a saída será -15,75\n");
							setbuf(stdin, NULL);
							printf("\n");
							gets(string_binario);
							printf("\n");
							tamanho_da_string_binario = strlen(string_binario);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O laço de repetição a seguir verifica se o número digitado está na formatação exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condição a seguir verifica se o primeiro digito é uma virgula ou algum espaçamento.
								if((string_binario[0] == ',') || (string_binario[0] == ' '))
								{	
									printf(" * Número inválido: não utilize espaçamentos ou virgula no inicio do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se o ultimo digito é uma virgula ou algum espaçamento.
								else if((string_binario[ultima_posicao] == ',' ) || (string_binario[ultima_posicao] == ' '))
								{
									printf(" * Número inválido: não utilize espaçamentos nem virgula no final do número.\n");
									printf("\a");
									break;
								}
								//A condição a seguir verifica se só há caracteres válidos para binário.
								else if((string_binario[contador] == '1') || (string_binario[contador] == '0') || (string_binario[contador] == ' ') || (string_binario[contador] == ','))
								{
									verficador_de_formatacao = 1;
								}
								//A seguir é verificado se o caractere inválido é um ponto, ou se é outro caractere inválido qualquer.
								else
								{
									verficador_de_formatacao = 0;	
									if(string_binario[contador] == '.')
									{
										printf(" * Número inválido: Você está utilizando a versão Brasileira do programa, para\n   números fracionários utilize virgula ao invés de ponto.\n");
									}
									else
									{
										printf(" * Número inválido: utilize somente os números 0 e 1, podendo ainda, haver\n   virgula em casos de números fracionários e espaçamentos entre os números\n   (exceto no incio e no final do número)\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verificação anterior, a conversão é realizada. 
							if(verficador_de_formatacao == 1)
							{	
								// O laço de repetição a seguir retira os espaços do número binário digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espaços entre os números, o condicional a seguir através da função 'isspace' verifica se em determinada posição, é um desses casos.  
									if(isspace(string_binario[posicao]))
									{
										//Podendo haver espaços adjacentes, o laço de repetição a seguir adiciona +1 a posição sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario[posicao]));
									}
									string_binario[contador] = string_binario [posicao]; //A String sem espaços será armazenada no inicio dela mesma, porém sem os espaços. 
									/*Não conferir se a variável 'posicao' já atingiu a quebra de linha - \n - pode resultar em conteúdos indesejáveis 
									armazenados na mesma, visto que a variável 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espaços.
								tamanho_da_string_binario = strlen(string_binario);			
								/*Se o número iniciar em 1, ou seja, for negativo, será necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
								dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
								if(string_binario[0] == '1')
								{
									ultima_posicao = tamanho_da_string_binario - 1; 
									//Primeiro é necessário verificar se há parte fracionária. Isso se dá pela procura da virgula.
									for(contador = 0; contador < tamanho_da_string_binario; contador++)
									{
										if(string_binario[contador] == ',')
										{
											verificador_de_fracionario = 1;
											break;
										}
									}
									//Se houver parte fracionária ele fara o complemento de dois nela;
									if(verificador_de_fracionario == 1)
									{
										while(string_binario[ultima_posicao] != '1')
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										for(contador = 0; contador < ultima_posicao; ultima_posicao--) 
										{
											if(string_binario[ultima_posicao] == '1')
											{
												string_binario[ultima_posicao] = '0';	
											}
											else if(string_binario[ultima_posicao] == '0')
											{
												string_binario[ultima_posicao] = '1';
											}
											else
											{
												string_binario[ultima_posicao] = ',';
												break;
											}
										}
										ultima_posicao--;//Depois do complemento da parte fracionária, ainda é necessário diminuir uma posição, por causa da virgula
									}
									//Complemento de 2 na parte inteira
									while(string_binario[ultima_posicao] != '1')
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									for(contador = 0; contador < ultima_posicao; ultima_posicao--) 
									{	
										if(string_binario[ultima_posicao] == '1')
										{
											string_binario[ultima_posicao] = '0';	
										}
										else
										{
											string_binario[ultima_posicao] = '1';
										}
									}
								}
								//Para conversão em binário, deve-se iniciar pelo último número, a função 'strrev' inverte 'string_binário' facilitando calcular pelo último número, pois ele se torna o primeiro.
								strrev(string_binario); 
								/* O laço de repetição a seguir converte o número binário em string, para um número inteiro, atribuindo cada caractere númerico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracionária, será atribuida ao seu valor na tabela ASCII: 44 */
								for(contador = 0;contador < tamanho_da_string_binario; contador++)
								{	
									if(string_binario[contador] == '1' )
									{
										binario[contador] = 1;
									}
									else if(string_binario[contador] == '0')
									{
										binario[contador] = 0;
									}
									else
									{
										binario[contador] = 44;
									}
								}								
								//No laço de repetição a seguir, será contada a quantidade de números da parte inteira e fracionária (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario[contador] == ',')
									{
										tamanho_da_parte_fracionaria  = contador;//Após inveter a String, contar até que se encontre uma virgula, é contar a quantidade de números fracionários.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//É necessário diminuir 1, pois a subtração do tamanho da string menos a parte frácionária, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para conversão da parte fracionária do binário usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se não houver parte fracionária, o tamanho da parte inteira será o contador +1 (pois inicia em 0).
									}
								}						
								//Na conversão não deve ser contado o bit de sinal, logo diminui-se 1 do seu tamanho.
								tamanho_da_string_binario = tamanho_da_string_binario - 1;
								tamanho_da_parte_inteira = tamanho_da_parte_inteira - 1;
								/*O condicional a seguir converte o número binário em número decimal. Se houver parte fracionária, 
								a conversão se iniciará por ela, se não houver. a conversão será somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a vírgula como ponto de referência para conversão entre a parte fracionária e inteira. A vírgula 
										ocupa um espaço no vetor, e esse espaço diz respeito a uma posição depois da parte fracionária e uma antes do início parte inteira*/
										if(binario[contador] != 44)
										{
											decimal = decimal + ((binario[contador]) * (pow(2, expoente)));
											expoente ++;
										}
									}
								}
								else
								{
									for(contador = 0; contador < tamanho_da_parte_inteira; contador ++)
									{
										decimal = decimal + ((binario[contador]) * (pow(2, expoente)));
										expoente ++;
									}		
								}
								//Se o número inicar em 1, resultará em um resultado negativo. Porém com a utilização da função strrev, a primeira posição se tona a íltima.
								if(string_binario[tamanho_da_string_binario] == '1')
								{
									decimal = decimal * -1;	
								}
								//O condicional a seguir trata da exibição do número convertido, se houver parte facionária no número binário ela será exibida no em seu equivalente decimal.
								if(tamanho_da_parte_fracionaria > 0)
								{
									printf(" * O número convertido para decimal é: %.5lf\n", decimal);	
								}
								else
								{
									printf(" * O número convertido para decimal é: %d\n", (int)decimal);
								}
							}
						break;
						default:
							printf(" * Erro ao selecionar aba: %d não é um caso válido.\n", resposta);
							printf("\a");
						break;						
					}
				break;	
				case 4:
					printf(" * Digite 5 para selecionar o conversor de número decimal para binário\n   deconsiderando o sinal do número.\n * Digite 6 para selecionar o conversor de número decimal para binário\n   considerando o sinal do número.\n");
					printf("\n");
					scanf("%d", &resposta);
					printf("\n");
					switch(resposta)
					{
						case 5:
							printf(" * Digite um número decimal - fracionário ou não - deconsiderando o sinaL do\n   número, cujo deseja saber sua conversão em binario:\n");
							printf("\n");
							scanf("%s", &decimal_string);
							printf("\n");
							tamanho_da_string_decimal = strlen(decimal_string);
							ultima_posicao = tamanho_da_string_decimal - 1;
							//Verifica se o número que o usuário digitou está de acordo com a formatação exigida.
							contador = 0;
							if(decimal_string[contador] == '+')
							{
								verficador_de_formatacao = 1;
								contador++;
							}
							else if(decimal_string[contador] == '-')
							{
								verficador_de_formatacao = 0;
								printf(" * Não é possível realizar a conversão de números negativos nessa parte do\n   programa. Há uma área especifica para isso.\n");
								printf("\a");
								contador++;
								break;
							}
							else if(decimal_string[contador] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * Número inválido: não utilize virgula no inicio do número.\n");
								printf("\a");
								break;
							}
							else if(decimal_string[ultima_posicao] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * Número inválido: não utilize virgula no final do número.\n");
								printf("\a");
								break;
							}
							while(contador < tamanho_da_string_decimal)
							{
								if(decimal_string[contador] == '.')
								{
									verficador_de_formatacao = 0;
									printf(" * Número inválido: Você está utilizando a versão Brasileira do programa, para\n   números fracionários utilize virgula ao invés de ponto.\n");
									printf("\a");
									break;
								}
								else if(isdigit(decimal_string[contador]) || decimal_string[contador] == ',')
								{
									verficador_de_formatacao = 1;
								}
								else
								{
									verficador_de_formatacao = 0;
									printf(" * %s não é um número decimal possível de realizar a conversão para binário.\n", decimal_string);
									printf("\a");
									break;
								}
								contador++;
							}
							//Se o número estiver de acordo com a formatação exigida, será feita sua conversão.
							if(verficador_de_formatacao == 1)
							{
								decimal = atof(decimal_string); // Conversão da String para um número decimal tipo real(float).
								//Como 'parte_inteira_do_decimal' é uma variável do tipo inteiro, fazê-la receber o número real digitado é armazenar sua parte inteira.
								parte_inteira_do_decimal = decimal;
								//Como 'parte_fracionária_do_decimal' é uma variável do tipo double, fazendo-a receber o número real menos sua parte inteira, obteremos a parte fracionária do número real (se hover).
								parte_fracionaria_do_decimal = decimal - parte_inteira_do_decimal;
								/*O laço de repetições a seguir define o tamanho da parte inteira do binário pela quantidade de vezes que a parte
								inteira do decimal - em múltiplas divisões inteiras - for divisível por 2 , até que o quociente chegue em 0 */	
								while(quociente !=0)
								{
									quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma variável inteira, recebe a parte inteira do resto da divisão da 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: característica de múltiplas divisões inteiras. 
									tamanho_inteiro_do_binario ++;
								}
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocação de memória, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
								ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padrão, vetores têm sua primeira posição em zero, logo a última posição de 'binario_inteiro' é o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = decimal;
								/*O laço de repetição a seguir converte a parte inteira do número decimal para binário, armazenando o resto 
								de divisões inteiras da 'parte_inteira_do_decimal' por 2, até que o contador do laço atinja o 'tamanho_inteiro_do_binario' */		
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na última posição recebe o resto (% - mod) da divisão inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--;
								}
								//Exibição da parte inteira em binário.
								printf(" * O número digitado convertido para binário é: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracionária no decimal digitado, mutiplicações definirão seu tamanho no vetor 'binario_fracionario'.
								if(parte_fracionaria_do_decimal > 0 ) 
								{
									/*O laço de repetições a seguir define o tamanho da parte fracionária do binário pela quantidade de vezes que ela 
									é multiplicada por 2 - tendo sempre sua parte inteira retirada - até que 'produto_fracionario' se chegue em 1 */
									while(produto_fracionario != 1)
									{	
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										tamanho_fracionario_do_binario ++;
									}
									binario_fracionario = calloc(sizeof(int), tamanho_fracionario_do_binario);
									parte_inteira_do_decimal = decimal;
									parte_fracionaria_do_decimal = decimal - parte_inteira_do_decimal; 
									produto_fracionario = 0;
									parte_inteira_do_produto_fracionario = 0;
									/*O laço de repetições a seguir armazena em 'binario_fracionario' - na posição do 
									contador - a parte  inteira retirada das multiplições do 'produto_fracionario' por 2 */
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
									}
									printf(",");
									for(contador = 0; contador< tamanho_fracionario_do_binario; contador ++)
									{
										printf("%d", binario_fracionario[contador]);
									}
									printf("\n");
								}	
							}
						break;
						case 6:
							printf(" * Digite um número decimal - fracionário ou não - considerando o sinaL do\n   número cujo deseja saber sua conversão em binário:\n");
							printf("\n");
							scanf("%s", &decimal_string);
							printf("\n");
							tamanho_da_string_decimal = strlen(decimal_string);
							ultima_posicao = tamanho_da_string_decimal - 1;
							//Verifica se o número que o usuário digitou está de acordo com a formatação exigida.
							contador = 0;
							if(decimal_string[contador] == '+')
							{
								verficador_de_formatacao = 1;
								contador++;
							}
							else if(decimal_string[contador] == '-')
							{
								verficador_de_formatacao = 1;
								contador++;
							}
							else if(decimal_string[contador] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * Número inválido: não utilize virgula no inicio do número.\n");
								printf("\a");
								break;
							}
							else if(decimal_string[ultima_posicao] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * Número inválido: não utilize virgula no final do número.\n");
								printf("\a");
								break;
							}
							while(contador < tamanho_da_string_decimal)
							{
								if(decimal_string[contador] == '.')
								{
									verficador_de_formatacao = 0;
									printf(" * Número inválido: Você está utilizando a versão Brasileira do programa, para\n   números fracionários utilize virgula ao invés de ponto.\n");
									printf("\a");
									break;
								}
								else if(isdigit(decimal_string[contador]) || decimal_string[contador] == ',')
								{
									verficador_de_formatacao = 1;
								}
								else
								{
									verficador_de_formatacao = 0;
									printf(" * %s não é um número decimal possível de realizar a conversão para binário.\n", decimal_string);
									printf("\a");
									break;
								}
								contador++;
							}
							//Se o número estiver de acordo com a formatação exigida, será feita sua conversão.
							if(verficador_de_formatacao == 1)
							{
								decimal = atof(decimal_string);// Conversão da String para um número decimal tipo real(float).	
								//Realizar a conversão com o número em negativo dá erro, logo é necessário tê-lo positivo.
								if(decimal < 0)
								{
									decimal_positivo = decimal * -1;
								}
								else
								{
									decimal_positivo = decimal;
								}
								//Como 'parte_inteira_do_decimal' é uma variável do tipo inteiro, fazê-la receber o número real digitado é armazenar sua parte inteira.
								parte_inteira_do_decimal = decimal_positivo;
								//Como 'parte_fracionária_do_decimal' é uma variável do tipo double, fazendo-a receber o número real menos sua parte inteira, obteremos a parte fracionária do número real (se hover).
								parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
								/*O laço de repetições a seguir define o tamanho da parte inteira do binário pela quantidade de vezes que a parte
								inteira do decimal - em múltiplas divisões inteiras - for divisível por 2 , até que o quociente chegue em 0 */	
								while(quociente !=0)
								{
									quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma variável inteira, recebe a parte inteira do resto da divisão da 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: característica de múltiplas divisões inteiras. 
									tamanho_inteiro_do_binario ++;
								}
								tamanho_inteiro_do_binario++; // Devido ao bit de sinal, acrescenta-se mais um ao tamanho do binário.
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocação de memória, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
								ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padrão, vetores têm sua primeira posição em zero, logo a última posição de 'binario_inteiro' é o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = decimal_positivo;								
								//Se o número for negativo seu primeiro digito será 1, se não, 0.
								if(decimal < 0)
								{
									binario_inteiro[0] = 1;
								}
								else
								{
									binario_inteiro[0] = 0;
								}
								
								for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na última posição recebe o resto (% - mod) da divisão inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--;
								}
								/*Se o número for negativo, será necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
								dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
								if(decimal < 0)
								{
									ultima_posicao = tamanho_inteiro_do_binario - 1;
									while(binario_inteiro[ultima_posicao] != 1 )
									{
										ultima_posicao--;
									}
									ultima_posicao--;
									contador = 0;
									while(contador < ultima_posicao)
									{
										if(binario_inteiro[ultima_posicao] == 1)
										{
											binario_inteiro[ultima_posicao] = 0;	
										}
										else
										{
											binario_inteiro[ultima_posicao] = 1;
										}
										ultima_posicao--;
									}
								}
								//Exibição da parte inteira em binário.
								printf(" * O número digitado convertido para binário é: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracionária no decimal digitado, mutiplicações definirão seu tamanho no vetor 'binario_fracionario'.
								if(parte_fracionaria_do_decimal > 0)
								{
									/*O laço de repetições a seguir define o tamanho da parte fracionária do binário pela quantidade de vezes que ela 
									é multiplicada por 2 - tendo sempre sua parte inteira retirada - até que 'produto_fracionario' se chegue em 1 */
									while(produto_fracionario != 1)
									{	
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										tamanho_fracionario_do_binario ++;
									}
									binario_fracionario = calloc(sizeof(int), tamanho_fracionario_do_binario);
									if(decimal < 0)
									{
										decimal_positivo = decimal * -1;
									}
									else
									{
										decimal_positivo = decimal;
									}
									parte_inteira_do_decimal = decimal_positivo;
									parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal; 
									produto_fracionario = 0;
									parte_inteira_do_produto_fracionario = 0;
									/*O laço de repetições a seguir armazena em 'binario_fracionario' - na posição do contador - 
									a parte inteira retirada das multiplições do 'produto_fracionario' por 2 */
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
									}
									/*Se o número for negativo, será necessário realizar o complemento de 2. Há várias maneiras de aplica-lo, a que utilizamos aqui se 
									dá pela procura - da direita para a esquerda - do número 1, quando encontrado inverte-se todos os números após ele, exceto o bit de sinal.*/
									if(decimal < 0)
									{
										ultima_posicao = tamanho_fracionario_do_binario - 1;
										while(binario_fracionario[ultima_posicao] != 1 )
										{
											ultima_posicao--;
										}
										ultima_posicao--;
										contador = 0;
										while(contador <= ultima_posicao)
										{
											if(binario_fracionario[ultima_posicao] == 1)
											{
												binario_fracionario[ultima_posicao] = 0;	
											}
											else
											{
												binario_fracionario[ultima_posicao] = 1;
											}
											ultima_posicao--;
										}	
									}	
									printf(",");
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										printf("%d", binario_fracionario[contador]);
									}
								}
							}
							printf("\n");
						break;
						default:
							printf(" * Erro ao selecionar aba: %d não é um caso válido.\n", resposta);
							printf("\a");
						break;
					}
				break;
				default:
					printf(" * Erro ao selecionar aba: %d não é um caso válido.\n", resposta);
					printf("\a");
				break;
			}
		break;
		default:
			printf(" * Erro ao selecionar aba: %d não é um caso válido.\n", resposta);
			printf("\a");
		break;
	}
	setbuf(stdin, NULL);
	printf("\n");
	printf(" * Deseja realizar outra operação?\n   Digite 1 p/ SIM ou 2 p/ para NÃO\n");
	printf("\n");
	scanf("%d",&resposta);
	//O Switch a seguir tem como finalidade dar a oportunidade ao usuario fazer alguma escolha entre as alternativas novamente, se quiser.
	switch(resposta)
	{
		case 1:
			system("CLS");//Limpa a tela.
			return main();//Retorna ao início do programa.
		break;
		case 2:
			exit(0);//Finaliza o programa.
		break;
	}
	return(0);
}
