#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");	
	//Declara��es de vari�veis que ser�o usadas na calculadora de bin�rios.
	char string_binario_1[1000];//Onde ser� armazenado o primeiro n�mero bin�rio digitado pelo usu�rio.
	char string_binario_2[1000];//Onde ser� armazenado o segundo n�mero bin�rio digitado pelo usu�rio.
	int verficador_de_formatacao_1 = 0;//Onde ser� armazenado o resultado da verifica��o da escrita do primeiro n�mero.
	int verficador_de_formatacao_2 = 0;//Onde ser� armazenado o resultado da verifica��o da escrita do segundo n�mero.
	//Declara��es de vari�veis que ser�o usadas na calculadora de decimais.
	char operador[5];//Onde ser� armazenada a opera��o que o usu�rio deseja realizar.
	double numero_decimal_1 = 0.0;//Onde ser� armazenado o primeiro n�mero decimal digitado pelo usu�rio.
	double numero_decimal_2 = 0.0;//Onde ser� armazenado o segundo n�mero decimal digitado pelo usu�rio.
	double resultado;//Onde ser� armazenado o resultado da opera��o dos n�meros digitados.
	//Declara��es de vari�veis do conversor de bin�rio para decimal desconsiderando e considerando o bit de sinal.
	char string_binario[1000];//Onde ser� armazenado o n�mero bin�rio em forma de string.
	int binario[1000];//Onde ser� armazenado o n�mero bin�rio em forma de n�mero inteiro.
	int expoente = 0;//Onde ser� armazenado o expoente para a convers�o do n�mero bin�rio.
	int tamanho_da_string_binario;//Onde ser� armazenado o tamanho do n�mero bin�rio em forma de string.
	int tamanho_da_parte_inteira;//Onde ser� armazenado o tamanho da parte inteira do vetor 'string_bin�rio' ap�s serem retirados os espa�os do n�mero.
	int tamanho_da_parte_fracionaria; //Onde ser� armazenado o tamanho da parte fracion�ria do vetor 'string_bin�rio' ap�s serem retirados os espa�os do n�mero.
	int posicao; //Onde ser� armazenado determindadas posi��es do vetor bin�rio.	
	//Declara��es de vari�veis do conversor de bin�rio para decimal considerando o bit de sinal.
	int verificador_de_fracionario;
	// * Declara��es de vari�veis do conversor de decimal para bin�rio
	char decimal_string [1000];
	double parte_fracionaria_do_decimal;//Onde ser� armazenada a parte fracion�ria do n�mero decimal.
	double produto_fracionario = 0;//Onde ser� armazenado o produto das multiplica��es da parte fracion�ria do n�mero decimal.
	int *binario_inteiro;//Onde ser� armazenada a parte inteira do n�mero decimal convertido para bin�rio.
	int *binario_fracionario;//Onde ser� armazenada a parte fracion�ria do n�mero decimal convertido para bin�rio.
	int parte_inteira_do_decimal;//Onde ser� armazenada a parte inteira do n�mero decimal.
	int parte_inteira_do_produto_fracionario;
	int quociente = 1; //Onde ser� armazenado o quociente das multplipas divis�es inteiras.
	int tamanho_inteiro_do_binario = 0; //Onde ser� armazenado o tamanho da parte inteira do n�mero bin�rio.
	int tamanho_fracionario_do_binario = 0; //Onde ser� armazenado o tamanho da parte fracion�ria do n�mero bin�rio.
	int tamanho_da_string_decimal;//Onde ser� armazenado o tamanho do n�mero bin�rio em forma de string.
	// * Declara��es de vari�veis do conversor de decimal para bin�rio considerando o sinal do n�mero.
	double decimal_positivo; //Onde ser� armazenado o n�mero decimal positivo.
	// * Declara��es de vari�veis de uso geral.
	int ultima_posicao = 0;//Onde ser� armazenada a �ltima posi��o de determinados vetores.
	int contador;//Onde ser� armazenado o contador dos la�os de repeti��es.
	int resposta;//Onde ser� armazenada as escolhas do usu�rio.
	int verficador_de_formatacao = 0;//Onde ser� armazenado o resultado da verifica��o da escrita do n�mero.
	double decimal = 0.0; //Onde ser� armazenado o n�mero decimal.
	//A seguir o usu�rio deve escolher entre selecionar calculadoras ou conversores.
	printf(" * Digite 1 para entrar na aba de calculadoras.\n * Digite 2 para entrar na aba de conversores.\n");
	printf("\n");
	scanf("%d", &resposta);
	printf("\n");
	//O Switch a seguir tem como finalidade dar ao usu�rio alternativas para utilizar o programa.
	switch(resposta)
	{
		case 1 :
			printf(" * Digite 2 para selecionar a calculadora com n�meros bin�rios.\n * Digite 3 para selecionar a calculadora com n�meros decimais.\n");
			printf("\n");
			scanf("%d", &resposta);
			printf("\n");
			//O Switch a seguir tem como finalidade dar ao usu�rio alternativas para utilizar as calculadoras do programa.
			switch(resposta)
			{
				case 2:
					printf(" * Digite 3 para selecionar a calculadora com n�meros bin�rios\n   desconsiderando os bits de sinais dos n�meros.\n * Digite 4 para selecionar a calculadora com n�meros bin�rios\n   considerando os bits de sinais dos n�meros.\n");
					printf("\n");
					scanf("%d", &resposta);
					printf("\n");
					//O Switch a seguir tem como finalidade dar ao usu�rio alternativas para utilizar n�meros bin�riaos considerando o sinal ou n�o.
					switch(resposta)
					{
						case 3:
							printf(" * Tabela de poss�veis opera��es:\n");
							printf("   - Adi��o: + \n");
							printf("   - Subtra��o: - \n");
							printf("   - Multiplica��o: * \n");					
							printf("   - Divis�o Inteira: div \n");
							printf("   - Divis�o Fracion�ria: / \n");
							printf("   - Pot�ncia: ^ \n");
							printf("\n");
							printf(" * Digite uma opera��o matem�tica com apenas dois n�meros bin�rios\n   e uma opera��o, de forma infixada. Entre cada um deles digite espa�o.\n   Ex: 0010+ 0010:\n");
							printf("\n");
							setbuf(stdin, NULL);
							scanf("%s %s %s", string_binario_1, operador, string_binario_2);
							printf("\n");
							//Convers�o de 'string_binario_1', para decimal:
							tamanho_da_string_binario = strlen(string_binario_1);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O la�o de repeti��o a seguir verifica se o n�mero digitado est� na formata��o exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condi��o a seguir verifica se o primeiro digito � uma virgula ou algum espa�amento.
								if(string_binario_1[0] == ',')
								{	
									printf(" * Primeiro n�mero inv�lido: n�o utilize virgula no inicio do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se o ultimo digito � uma virgula ou algum espa�amento.
								else if(string_binario_1[ultima_posicao] == ',' )
								{
									printf(" * Primeiro n�mero inv�lido: n�o utilize virgula no final do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se s� h� caracteres v�lidos para bin�rio.
								else if((string_binario_1[contador] == '1') || (string_binario_1[contador] == '0') || (string_binario_1[contador] == ','))
								{
									verficador_de_formatacao_1 = 1;
								}
								//A seguir � verificado se o caractere inv�lido � um ponto, ou se � outro caractere inv�lido qualquer.
								else
								{
									verficador_de_formatacao_1 = 0;	
									if(string_binario_1[contador] == '.')
									{
										printf(" * Primeiro n�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do\n   programa, para n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
									}
									else
									{
										printf(" * Primeiro n�mero inv�lido: utilize somente os n�meros 0 e 1, podendo ainda\n   haver virgula em casos de n�meros fracion�rios\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verifica��o anterior, a convers�o � realizada. 
							if(verficador_de_formatacao_1 == 1)
							{
								// O la�o de repeti��o a seguir retira os espa�os do n�mero bin�rio digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espa�os entre os n�meros, o condicional a seguir atrav�s da fun��o 'isspace' verifica se em determinada posi��o, � um desses casos.  
									if(isspace(string_binario_1[posicao]))
									{
										//Podendo haver espa�os adjacentes, o la�o de repeti��o a seguir adiciona +1 a posi��o sempre que isso ocorrer. 
										do
										{
											posicao ++;
										}
										while(isspace(string_binario_1[posicao]));
									}
									//A String sem espa�os ser� armazenada no inicio dela mesma, por�m sem os espa�os.
									string_binario_1[contador] = string_binario_1 [posicao]; 
									/*N�o conferir se a vari�vel 'posicao' j� atingiu a quebra de linha - \n - pode resultar em conte�dos indesej�veis 
									armazenados na mesma, visto que a vari�vel 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_1 [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espa�os.
								tamanho_da_string_binario = strlen(string_binario_1); 
								//Para convers�o em bin�rio, deve-se iniciar pelo �ltimo n�mero, a fun��o 'strrev' inverte 'string_bin�rio' facilitando calcular pelo �ltimo n�mero, pois ele se torna o primeiro.
								strrev(string_binario_1);
								/* O la�o de repeti��o a seguir converte o n�mero bin�rio em string, para um n�mero inteiro, atribuindo cada caractere n�merico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracion�ria, ser� atribuida ao seu valor na tabela ASCII: 44 */
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
								//No la�o de repeti��o a seguir, ser� contada a quantidade de n�meros da parte inteira e fracion�ria (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_1[contador] == ',')
									{ 
										tamanho_da_parte_fracionaria  = contador;//Ap�s inveter a String, contar at� que se encontre uma virgula, � contar a quantidade de n�meros fracion�rios.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//� necess�rio diminuir 1, pois a subtra��o do tamanho da string menos a parte fr�cion�ria, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para convers�o da parte fracion�ria do bin�rio usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se n�o houver parte fracion�ria, o tamanho da parte inteira ser� o contador +1 (pois inicia em 0).
									}
								}
								/*O condicional a seguir converte o n�mero bin�rio em n�mero decimal. Se houver parte fracion�ria, 
								a convers�o se iniciar� por ela, se n�o houver. a convers�o ser� somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a virgula como ponto de referencia para convers�o entre a parte fracion�ria e inteira. A virgula 
										ocupa um espa�o no vetor, e esse espa�o diz respeito a uma posi��o depois da parte fracion�ria e uma antes do inicio parte inteira*/
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
							//Convers�o de 'string_binario_2', para decimal:
							expoente = 0;
							tamanho_da_string_binario = strlen(string_binario_2);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O la�o de repeti��o a seguir verifica se o n�mero digitado est� na formata��o exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condi��o a seguir verifica se o primeiro digito � uma virgula.
								if(string_binario_2[0] == ',')
								{	
									printf(" * Segundo n�mero inv�lido: n�o utilize virgula no inicio do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se o ultimo digito � uma virgula ou algum espa�amento.
								else if(string_binario_2[ultima_posicao] == ',' )
								{
									printf(" * Segundo n�mero inv�lido: n�o utilize virgula no final do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se s� h� caracteres v�lidos para bin�rio.
								else if((string_binario_2[contador] == '1') || (string_binario_2[contador] == '0') || (string_binario_2[contador] == ','))
								{
									verficador_de_formatacao_2 = 1;
								}
								//A seguir � verificado se o caractere inv�lido � um ponto, ou se � outro caractere inv�lido qualquer.
								else
								{
									verficador_de_formatacao_2 = 0;	
									if(string_binario_2[contador] == '.')
									{ 
										printf(" * Segundo n�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do\n   programa, para n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
									}
									else
									{
										printf(" * Segundo n�mero inv�lido: utilize somente os n�meros 0 e 1, podendo ainda\n   haver virgula em casos de n�meros fracion�rios\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verifica��o anterior, a convers�o � realizada. 
							if(verficador_de_formatacao_2 == 1)
							{
								// O la�o de repeti��o a seguir retira os espa�os do n�mero bin�rio digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espa�os entre os n�meros, o condicional a seguir atrav�s da fun��o 'isspace' verifica se em determinada posi��o, � um desses casos.  
									if(isspace(string_binario_2[posicao]))
									{
										//Podendo haver espa�os adjacentes, o la�o de repeti��o a seguir adiciona +1 a posi��o sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario_2[posicao]));
									}
									//A String sem espa�os ser� armazenada no inicio dela mesma, por�m sem os espa�os.
									string_binario_2[contador] = string_binario_2 [posicao]; 
									/*N�o conferir se a vari�vel 'posicao' j� atingiu a quebra de linha - \n - pode resultar em conte�dos indesej�veis 
									armazenados na mesma, visto que a vari�vel 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_2 [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espa�os.
								tamanho_da_string_binario = strlen(string_binario_2); 
								//Para convers�o em bin�rio, deve-se iniciar pelo �ltimo n�mero, a fun��o 'strrev' inverte 'string_bin�rio' facilitando calcular pelo �ltimo n�mero, pois ele se torna o primeiro.
								strrev(string_binario_2);
								/* O la�o de repeti��o a seguir converte o n�mero bin�rio em string, para um n�mero inteiro, atribuindo cada caractere n�merico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracion�ria, ser� atribuida ao seu valor na tabela ASCII: 44 */
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
								//No la�o de repeti��o a seguir, ser� contada a quantidade de n�meros da parte inteira e fracion�ria (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_2[contador] == ',')
									{ 
										tamanho_da_parte_fracionaria  = contador;//Ap�s inveter a String, contar at� que se encontre uma virgula, � contar a quantidade de n�meros fracion�rios.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//� necess�rio diminuir 1, pois a subtra��o do tamanho da string menos a parte fr�cion�ria, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para convers�o da parte fracion�ria do bin�rio usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se n�o houver parte fracion�ria, o tamanho da parte inteira ser� o contador +1 (pois inicia em 0).
									}
								}
								/*O condicional a seguir converte o n�mero bin�rio em n�mero decimal. Se houver parte fracion�ria, 
								a convers�o se iniciar� por ela, se n�o houver. a convers�o ser� somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a virgula como ponto de referencia para convers�o entre a parte fracion�ria e inteira. A virgula 
										ocupa um espa�o no vetor, e esse espa�o diz respeito a uma posi��o depois da parte fracion�ria e uma antes do inicio parte inteira*/
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
							//Depois que os n�meros forem convertidos para decimal, se estiverem de acordo com a formata��o exigida, � necess�rio realizar o c�lculo de acordo com a opera��o digitada e converter o resultado para bin�rio.
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
										printf(" * N�o � poss�vel realizar divisa� por 0");
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
										printf(" * N�o � poss�vel realizar divisa� por 0");
										printf("\a");
									}
								}
								else if(strcmp(operador , "^") == 0)
								{
									resultado = pow(numero_decimal_1 , numero_decimal_2);
								}
								else
								{	
									printf(" * Opera��o inv�lida: %s n�o � uma opera��o v�lida.\n", operador);
									printf("\a");
								}
								// - Convers�o do resultado para bin�rio.
								//Em uma divis�o se o primeiro for menor que o segundo, o resultado ser� negativo.
								if((numero_decimal_1 < numero_decimal_2) && (strcmp(operador , "-") == 0))
								{
									decimal_positivo = resultado * -1;
									//Como 'parte_inteira_do_decimal' � uma vari�vel do tipo inteiro, faz�-la receber o resultado � armazenar sua parte inteira.
									parte_inteira_do_decimal = decimal_positivo;
									//Como 'parte_fracion�ria_do_decimal' � uma vari�vel do tipo double, fazendo-a receber o resultado menos sua parte inteira, obteremos a parte fracion�ria do n�mero real (se hover).
									parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
									/*O la�o de repeti��es a seguir define o tamanho da parte inteira do bin�rio pela quantidade de vezes que o 
									resultado - em m�ltiplas divis�es inteiras - for divis�vel por 2 , at� que o quociente chegue em 0 */	
									while(quociente !=0)
									{
										quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma vari�vel inteira, recebe a parte inteira do resto da divis�o da 'parte_inteira_do_decimal' por 2.
										parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: caracter�stica de m�ltiplas divis�es inteiras. 
										tamanho_inteiro_do_binario ++;
									}
									tamanho_inteiro_do_binario++;// Devido ao bit de sinal, acrescenta-se mais um ao tamanho do bin�rio.
									binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Aloca��o de mem�ria, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
									ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padr�o, vetores t�m sua primeira posi��o em zero, logo a �ltima posi��o de 'binario_inteiro' � o 'tamanho_inteiro_do_binario' menos um.
									parte_inteira_do_decimal = decimal_positivo;								
									//Como o n�mero � negativo seu primeiro digito ser� 1.
									binario_inteiro[0] = 1;
									for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
									{
										binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na �ltima posi��o recebe o resto (% - mod) da divis�o inteira da 'parte_inteira_do_decimal' por 2. 	
										quociente = parte_inteira_do_decimal/2;
										parte_inteira_do_decimal = quociente;
										ultima_posicao--;
									}
									/*Como o n�mero � negativo, � necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
									d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/		
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
									//Exibi��o da parte inteira em bin�rio.
									printf(" * O resultado da opera��o �: ");
									for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
									{
										printf("%d", binario_inteiro[contador]);
									}
									//Se houver parte fracion�ria no decimal digitado, mutiplica��es definir�o seu tamanho no vetor 'binario_fracionario'.
									if(parte_fracionaria_do_decimal > 0)
									{
										/*O la�o de repeti��es a seguir define o tamanho da parte fracion�ria do bin�rio pela quantidade de vezes que ela 
										� multiplicada por 2 - tendo sempre sua parte inteira retirada - at� que 'produto_fracionario' se chegue em 1 */
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
										/*O la�o de repeti��es a seguir armazena em 'binario_fracionario' - na posi��o do contador - 
										a parte inteira retirada das multipli��es do 'produto_fracionario' por 2 */
										for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
										{
											produto_fracionario = parte_fracionaria_do_decimal * 2;
										 	parte_inteira_do_produto_fracionario = produto_fracionario;
											binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
											parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										}
										/*Como o n�mero for negativo, � necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
										d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
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
								//Qualquer outra opera��o que tenha o primeiro n�mero menor que o primeiro, n�o resultar� em um resultado negativo. 
								parte_inteira_do_decimal = resultado;//Como 'parte_inteira_do_decimal' � uma vari�vel do tipo inteiro, faz�-la receber o reaultado � armazenar sua parte inteira.
								//Como 'parte_fracion�ria_do_decimal' � uma vari�vel do tipo double, fazendo-a receber o resultado menos sua parte inteira, obteremos a parte fracion�ria do resultado (se hover).
								parte_fracionaria_do_decimal = resultado - parte_inteira_do_decimal;
								/*O la�o de repeti��es a seguir define o tamanho da parte inteira do bin�rio pela quantidade de vezes que a parte
								inteira do resultado - em m�ltiplas divis�es inteiras - for divis�vel por 2 , at� que o quociente chegue em 0 */	
								while(quociente !=0)
								{
									quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma vari�vel inteira, recebe a parte inteira do resto da divis�o da 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: caracter�stica de m�ltiplas divis�es inteiras. 
									tamanho_inteiro_do_binario ++;
								}
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Aloca��o de mem�ria, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
								ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padr�o, vetores t�m sua primeira posi��o em zero, logo a �ltima posi��o de 'binario_inteiro' � o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = resultado;
								/*O la�o de repeti��o a seguir converte a parte inteira do resultado para bin�rio, armazenando o resto de divis�es 
								inteiras da 'parte_inteira_do_decimal' por 2, at� que o contador do la�o atinja o 'tamanho_inteiro_do_binario' */
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na �ltima posi��o recebe o resto (% - mod) da divis�o inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--;
								}
								//Exibi��o da parte inteira em bin�rio.
								printf(" * O resultado da opera��o �: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracion�ria no resultado, mutiplica��es definir�o seu tamanho no vetor 'binario_fracionario'.
								if((parte_fracionaria_do_decimal > 0 ) && (strcmp(operador , "div") != 0)) 
								{
									/*O la�o de repeti��es a seguir define o tamanho da parte fracion�ria do resultado pela quantidade de vezes que ela 
									� multiplicada por 2 - tendo sempre sua parte inteira retirada - at� que 'produto_fracionario' se chegue em 1 */
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
									/*O la�o de repeti��es a seguir armazena em 'binario_fracionario' - na posi��o do 
									contador - a parte  inteira retirada das multipli��es do 'produto_fracionario' por 2 */
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
								printf(" * N�o � poss�vel realizar a opera��o. O(s) n�mero(s) n�o est�o no padr�o\n   de escrita exigidos.\n");
								printf("\a");
							}					
						break;					
						case 4:
							printf(" * Tabela de poss�veis opera��es:\n");
							printf("   - Adi��o: + \n");
							printf("   - Subtra��o: - \n");
							printf("   - Multiplica��o: * \n");					
							printf("   - Divis�o Inteira: div \n");
							printf("   - Divis�o Fracion�ria: / \n");
							printf("   - Pot�ncia: ^ \n");
							printf("\n");
							printf(" * Digite uma opera��o matem�tica com apenas dois n�meros bin�rios\n   e uma opera��o, de forma infixada. Entre cada um deles digite espa�o.\n   Ex:0010 + 0010:\n");
							printf("\n");
							setbuf(stdin, NULL);
							scanf("%s %s %s", string_binario_1, operador, string_binario_2); // N�o pode haver espa�os na calculadora indexada
							printf("\n");
							
							//Convers�o do primeiro n�mero digitado
							tamanho_da_string_binario = strlen(string_binario_1);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O la�o de repeti��o a seguir verifica se o n�mero digitado est� na formata��o exigida.
							for(contador = 0; contador < tamanho_da_string_binario; contador++)
							{
								//A condi��o a seguir verifica se o primeiro digito � uma virgula ou algum espa�amento.
								if(string_binario_1[0] == ',')
								{	
									printf(" * Primeiro n�mero inv�lido: n�o utilize virgula no inicio do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se o ultimo digito � uma virgula ou algum espa�amento.
								else if(string_binario_1[ultima_posicao] == ',')
								{
									printf(" * Primeiro n�mero inv�lido: n�o utilize virgula no final do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se s� h� caracteres v�lidos para bin�rio.
								else if((string_binario_1[contador] == '1') || (string_binario_1[contador] == '0') || (string_binario_1[contador] == ','))
								{
									verficador_de_formatacao_1 = 1;
								}
								//A seguir � verificado se o caractere inv�lido � um ponto, ou se � outro caractere inv�lido qualquer.
								else
								{
									verficador_de_formatacao_1 = 0;	
									if(string_binario_1[contador] == '.')
									{
										printf(" * Primeiro n�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do\n   programa, para n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
									}
									else
									{
										printf(" * Primeiro n�mero inv�lido: utilize somente os n�meros 0 e 1, podendo ainda, haver\n   virgula em casos de n�meros fracion�rios.\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verifica��o anterior, a convers�o � realizada. 
							if(verficador_de_formatacao_1 == 1)
							{	
								// O la�o de repeti��o a seguir retira os espa�os do n�mero bin�rio digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espa�os entre os n�meros, o condicional a seguir atrav�s da fun��o 'isspace' verifica se em determinada posi��o, � um desses casos.  
									if(isspace(string_binario_1[posicao]))
									{
										//Podendo haver espa�os adjacentes, o la�o de repeti��o a seguir adiciona +1 a posi��o sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario_1[posicao]));
									}
									string_binario_1[contador] = string_binario_1[posicao]; //A String sem espa�os ser� armazenada no inicio dela mesma, por�m sem os espa�os. 
									/*N�o conferir se a vari�vel 'posicao' j� atingiu a quebra de linha - \n - pode resultar em conte�dos indesej�veis 
									armazenados na mesma, visto que a vari�vel 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_1[posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espa�os.
								tamanho_da_string_binario = strlen(string_binario_1);			
								/*Se o n�mero iniciar em 1, ou seja, for negativo, ser� necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
								d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
								if(string_binario_1[0] == '1')
								{
									ultima_posicao = tamanho_da_string_binario - 1; 
									//Primeiro � necess�rio verificar se h� parte fracion�ria. Isso se d� pela procura da virgula.
									for(contador = 0; contador < tamanho_da_string_binario; contador++)
									{
										if(string_binario_1[contador] == ',')
										{
											verificador_de_fracionario = 1;
											break;
										}
									}
									//Se houver parte fracion�ria ele fara o complemento de dois nela;
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
										ultima_posicao--;//Depois do complemento da parte fracion�ria, ainda � necess�rio diminuir uma posi��o, por causa da virgula
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
								//Para convers�o em bin�rio, deve-se iniciar pelo �ltimo n�mero, a fun��o 'strrev' inverte 'string_bin�rio' facilitando calcular pelo �ltimo n�mero, pois ele se torna o primeiro.
								strrev(string_binario_1); 
								/* O la�o de repeti��o a seguir converte o n�mero bin�rio em string, para um n�mero inteiro, atribuindo cada caractere n�merico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracion�ria, ser� atribuida ao seu valor na tabela ASCII: 44 */
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
								//No la�o de repeti��o a seguir, ser� contada a quantidade de n�meros da parte inteira e fracion�ria (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_1[contador] == ',')
									{
										tamanho_da_parte_fracionaria  = contador;//Ap�s inveter a String, contar at� que se encontre uma virgula, � contar a quantidade de n�meros fracion�rios.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//� necess�rio diminuir 1, pois a subtra��o do tamanho da string menos a parte fr�cion�ria, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para convers�o da parte fracion�ria do bin�rio usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se n�o houver parte fracion�ria, o tamanho da parte inteira ser� o contador +1 (pois inicia em 0).
									}
								}						
								//Na convers�o n�o deve ser contado o bit de sinal, logo diminui-se 1 do seu tamanho.
								tamanho_da_string_binario = tamanho_da_string_binario - 1;
								tamanho_da_parte_inteira = tamanho_da_parte_inteira - 1;
								/*O condicional a seguir converte o n�mero bin�rio em n�mero decimal. Se houver parte fracion�ria, 
								a convers�o se iniciar� por ela, se n�o houver. a convers�o ser� somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a v�rgula como ponto de refer�ncia para convers�o entre a parte fracion�ria e inteira. A v�rgula 
										ocupa um espa�o no vetor, e esse espa�o diz respeito a uma posi��o depois da parte fracion�ria e uma antes do in�cio parte inteira*/
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
								//Se o n�mero inicar em 1, resultar� em um resultado negativo. Por�m com a utiliza��o da fun��o strrev, a primeira posi��o se tona a �ltima.
								if(string_binario_1[tamanho_da_string_binario] == '1')
								{
									numero_decimal_1 = numero_decimal_1 * -1;	
								}
							}
							//Convers�o do Segundo N�mero digitado.
							expoente = 0;
							tamanho_da_string_binario = strlen(string_binario_2);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O la�o de repeti��o a seguir verifica se o n�mero digitado est� na formata��o exigida.
							for(contador = 0; contador < tamanho_da_string_binario; contador++)
							{
								//A condi��o a seguir verifica se o primeiro digito � uma virgula ou algum espa�amento.
								if(string_binario_2[0] == ',')
								{	
									printf(" * Segundo n�mero inv�lido: n�o utilize virgula no inicio do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se o ultimo digito � uma virgula ou algum espa�amento.
								else if(string_binario_2[ultima_posicao] == ',')
								{
									printf(" * Segundo n�mero inv�lido: n�o utilize virgula no final do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se s� h� caracteres v�lidos para bin�rio.
								else if((string_binario_2[contador] == '1') || (string_binario_2[contador] == '0') || (string_binario_2[contador] == ','))
								{
									verficador_de_formatacao_2 = 1;
								}
								//A seguir � verificado se o caractere inv�lido � um ponto, ou se � outro caractere inv�lido qualquer.
								else
								{
									verficador_de_formatacao_2 = 0;	
									if(string_binario_2[contador] == '.')
									{
										printf(" * Segundo n�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do\n   programa, para n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
									}
									else
									{
										printf(" * Segundo n�mero inv�lido: utilize somente os n�meros 0 e 1, podendo ainda, haver\n   virgula em casos de n�meros fracion�rios.\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verifica��o anterior, a convers�o � realizada. 
							if(verficador_de_formatacao_2 == 1)
							{	
								// O la�o de repeti��o a seguir retira os espa�os do n�mero bin�rio digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espa�os entre os n�meros, o condicional a seguir atrav�s da fun��o 'isspace' verifica se em determinada posi��o, � um desses casos.  
									if(isspace(string_binario_2[posicao]))
									{
										//Podendo haver espa�os adjacentes, o la�o de repeti��o a seguir adiciona +1 a posi��o sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario_2[posicao]));
									}
									string_binario_2[contador] = string_binario_2[posicao]; //A String sem espa�os ser� armazenada no inicio dela mesma, por�m sem os espa�os. 
									/*N�o conferir se a vari�vel 'posicao' j� atingiu a quebra de linha - \n - pode resultar em conte�dos indesej�veis 
									armazenados na mesma, visto que a vari�vel 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario_2[posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espa�os.
								tamanho_da_string_binario = strlen(string_binario_2);			
								/*Se o n�mero iniciar em 1, ou seja, for negativo, ser� necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
								d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
								if(string_binario_2[0] == '1')
								{
									ultima_posicao = tamanho_da_string_binario - 1; 
									//Primeiro � necess�rio verificar se h� parte fracion�ria. Isso se d� pela procura da virgula.
									for(contador = 0; contador < tamanho_da_string_binario; contador++)
									{
										if(string_binario_2[contador] == ',')
										{
											verificador_de_fracionario = 1;
											break;
										}
									}
									//Se houver parte fracion�ria ele fara o complemento de dois nela;
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
										ultima_posicao--;//Depois do complemento da parte fracion�ria, ainda � necess�rio diminuir uma posi��o, por causa da virgula
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
								//Para convers�o em bin�rio, deve-se iniciar pelo �ltimo n�mero, a fun��o 'strrev' inverte 'string_bin�rio' facilitando calcular pelo �ltimo n�mero, pois ele se torna o primeiro.
								strrev(string_binario_2); 
								/* O la�o de repeti��o a seguir converte o n�mero bin�rio em string, para um n�mero inteiro, atribuindo cada caractere n�merico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracion�ria, ser� atribuida ao seu valor na tabela ASCII: 44 */
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
								//No la�o de repeti��o a seguir, ser� contada a quantidade de n�meros da parte inteira e fracion�ria (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario_2[contador] == ',')
									{
										tamanho_da_parte_fracionaria  = contador;//Ap�s inveter a String, contar at� que se encontre uma virgula, � contar a quantidade de n�meros fracion�rios.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//� necess�rio diminuir 1, pois a subtra��o do tamanho da string menos a parte fr�cion�ria, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para convers�o da parte fracion�ria do bin�rio usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se n�o houver parte fracion�ria, o tamanho da parte inteira ser� o contador +1 (pois inicia em 0).
									}
								}						
								//Na convers�o n�o deve ser contado o bit de sinal, logo diminui-se 1 do seu tamanho.
								tamanho_da_string_binario = tamanho_da_string_binario - 1;
								tamanho_da_parte_inteira = tamanho_da_parte_inteira - 1;
								/*O condicional a seguir converte o n�mero bin�rio em n�mero decimal. Se houver parte fracion�ria, 
								a convers�o se iniciar� por ela, se n�o houver. a convers�o ser� somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a v�rgula como ponto de refer�ncia para convers�o entre a parte fracion�ria e inteira. A v�rgula 
										ocupa um espa�o no vetor, e esse espa�o diz respeito a uma posi��o depois da parte fracion�ria e uma antes do in�cio parte inteira*/
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
								//Se o n�mero inicar em 1, resultar� em um resultado negativo. Por�m com a utiliza��o da fun��o strrev, a primeira posi��o se tona a �ltima.
								if(string_binario_2[tamanho_da_string_binario] == '1')
								{
									numero_decimal_2 = numero_decimal_2 * -1;	
								}
							}
							//Se os dois n�meros estiverem na formata��o exigida, o c�lculo ser� efetuado
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
										printf(" * N�o � poss�vel realizar divisa� por 0");
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
										printf(" * N�o � poss�vel realizar divisa� por 0");
										printf("\a");
									}
								}
								else if(strcmp(operador , "^") == 0)
								{
									resultado = pow(numero_decimal_1 , numero_decimal_2);
								}
								else
								{	
									printf(" * Opera��o inv�lida: %s n�o � uma opera��o v�lida.\n", operador);
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
									//Como 'parte_inteira_do_decimal' � uma vari�vel do tipo inteiro, faz�-la receber o resultado � armazenar sua parte inteira.
									parte_inteira_do_decimal = decimal_positivo;
									//Como 'parte_fracion�ria_do_decimal' � uma vari�vel do tipo double, fazendo-a receber o resultado menos sua parte inteira, obteremos a parte fracion�ria do n�mero real (se hover).
									parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
									/*O la�o de repeti��es a seguir define o tamanho da parte inteira do bin�rio pela quantidade de vezes que o 
									resultado - em m�ltiplas divis�es inteiras - for divis�vel por 2 , at� que o quociente chegue em 0 */	
									while(quociente !=0)
									{
										quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma vari�vel inteira, recebe a parte inteira do resto da divis�o da 'parte_inteira_do_decimal' por 2.
										parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: caracter�stica de m�ltiplas divis�es inteiras. 
										tamanho_inteiro_do_binario ++;
									}
									tamanho_inteiro_do_binario++;// Devido ao bit de sinal, acrescenta-se mais um ao tamanho do bin�rio.
									binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Aloca��o de mem�ria, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
									ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padr�o, vetores t�m sua primeira posi��o em zero, logo a �ltima posi��o de 'binario_inteiro' � o 'tamanho_inteiro_do_binario' menos um.
									parte_inteira_do_decimal = decimal_positivo;								
									//Como o n�mero � negativo seu primeiro digito ser� 1.
									binario_inteiro[0] = 1;
									for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
									{
										binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na �ltima posi��o recebe o resto (% - mod) da divis�o inteira da 'parte_inteira_do_decimal' por 2. 	
										quociente = parte_inteira_do_decimal/2;
										parte_inteira_do_decimal = quociente;
										ultima_posicao--;
									}
									/*Como o n�mero � negativo, � necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
									d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/		
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
									//Exibi��o da parte inteira em bin�rio.
									printf(" * O resultado da opera��o �: ");
									for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
									{
										printf("%d", binario_inteiro[contador]);
									}
									//Se houver parte fracion�ria no decimal digitado, mutiplica��es definir�o seu tamanho no vetor 'binario_fracionario'.
									if(parte_fracionaria_do_decimal > 0)
									{
										/*O la�o de repeti��es a seguir define o tamanho da parte fracion�ria do bin�rio pela quantidade de vezes que ela 
										� multiplicada por 2 - tendo sempre sua parte inteira retirada - at� que 'produto_fracionario' se chegue em 1 */
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
										/*O la�o de repeti��es a seguir armazena em 'binario_fracionario' - na posi��o do contador - 
										a parte inteira retirada das multipli��es do 'produto_fracionario' por 2 */
										for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
										{
											produto_fracionario = parte_fracionaria_do_decimal * 2;
										 	parte_inteira_do_produto_fracionario = produto_fracionario;
											binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
											parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
										}
										/*Como o n�mero for negativo, � necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
										d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
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
								
								parte_inteira_do_decimal = decimal_positivo; //Como 'parte_inteira_do_decimal' � uma vari�vel do tipo inteiro, faz�-la receber o n�mero real digitado e armazenar sua parte inteira.
								//Como 'parte_fracion�ria_do_decimal' � uma vari�vel do tipo double, faz�-la receber o n�mero real menos sua parte inteira e isolar sua parte fracion�ria.
								parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
								/*O la�o de repeti��es a seguir define o tamanho da parte inteira do bin�rio pela quantidade de vezes que a parte
								inteira do decimal - em m�ltiplas divis�es inteiras - for divis�vel por 2 , at� que o quociente chegue em 0 */	
								while(quociente != 0)
								{
									quociente = parte_inteira_do_decimal/2; //'quociente' por ser uma vari�vel inteira, recebe a parte inteira do resto da divis�o, de 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente; //Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: caracter�stica de m�ltiplas divis�es inteiras. 
									tamanho_inteiro_do_binario++;
								}
								
								tamanho_inteiro_do_binario++; // Devido ao bit de sinal, acrescenta-se mais um ao tamanho do bin�rio.
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Aloca��o de mem�ria, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. binario_inteiro[tamanho_inteiro_do_binario];
								//binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Alocando mem�ria din�micamente, atrav�s da fun��o calloc.
								ultima_posicao = tamanho_inteiro_do_binario - 1; //Por padr�o, vetores t�m sua primeira posi��o em zero, logo a �ltima posi��o de 'binario_inteiro' � o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = decimal_positivo;
								//Se o n�mero for negativo seu primeiro digito ser� 1, se n�o, 0.
								if(resultado < 0)
								{
									binario_inteiro[0] = 1;
								}
								else
								{
									binario_inteiro[0] = 0;
								}
								/*O la�o de repeti��o a seguir converte a parte inteira do n�mero decimal para bin�rio, por armazenar o resto 
								de divis�es inteiras da 'parte_inteira_do_decimal' por 2, at� que o contador do la�o atinja o 'tamanho_inteiro_do_binario' */		
								for(contador = 1; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2; //O vetor 'binario_inteiro' na �ltima posi��o recebe o resto (% - mod) da divis�o inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--; //A cada intera��o a 'ultima_posi��o' diminui 1, preenchendo o vetor ao final.
								}
								//Se o n�mero for negativo � necess�rio realizar o complemeto de 2.
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
								//Exibi��o da parte inteira em bin�rio.
								printf(" * O resultado da opera��o �: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracion�ria no decimal digitado, mutiplica��es definir�o seu tamanho no vetor 'binario_fracionario'.
								if((parte_fracionaria_do_decimal > 0) && (strcmp(operador , "div") != 0))
								{
									/*O la�o de repeti��es a seguir define o tamanho da parte fracion�ria do bin�rio pela quantidade de vezes que ela 
									� multiplicada por 2 - tendo sempre sua parte inteira retirada - at� que 'produto_fracionario' se chegue em 1 */
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
									/*O la�o de repeti��es a seguir armazena em 'binario_fracionario' - na posi��o do contador - a parte inteira retirada
									das multipli��es do 'produto_fracionario' por 2 */
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
									}
									//Se o n�mero for negativo � necess�rio realizar o complemeto de 2.
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
								printf(" * N�o � poss�vel realizar a opera��o. O(s) n�mero(s) n�o est�o no padr�o\n   de escrita exigidos.\n");
								printf("\a");
							}
						break;
						default:
							printf(" * Erro ao selecionar aba: %d n�o � um caso v�lido.\n", resposta);
							printf("\a");
						break;						
					}
				break;
				case 3:
					printf("\n");
					printf(" * Tabela de poss�veis opera��es:\n");
					printf("   - Adi��o: + \n");
					printf("   - Subtra��o: - \n");
					printf("   - Multiplica��o: * \n");					
					printf("   - Divis�o Inteira: div \n");
					printf("   - Divis�o Fracion�ria: / \n");
					printf("   - Pot�ncia: ^ \n");
					printf("\n"); 
					printf(" * Digite uma opera��o matem�tica com apenas dois n�meros decimais \n   e uma opera��o, de forma infixada. Entre cada um deles digite espa�o.\n   Ex: 2 + 2:\n");
					printf("\n");
					scanf("%lf %s %lf", &numero_decimal_1, operador, &numero_decimal_2);
					printf("\n");
					//O condicional a seguir atrav�s da fun��o 'strcmp' compara o operador digitado com os operadores v�lidos. Se forem iguais a fun��o retorna 0.
					if(strcmp(operador , "+") == 0)
					{
				    	resultado = numero_decimal_1 + numero_decimal_2;
				    	printf(" * O resultado da opera��o matem�tica �: %.2lf", resultado);
					}
					else if(strcmp(operador , "-") == 0)
					{
				    	resultado = numero_decimal_1 - numero_decimal_2;
				    	printf(" * O resultado da opera��o matem�tica �: %.2lf", resultado);
					}
					else if(strcmp(operador , "*") == 0)
					{
				    	resultado = numero_decimal_1 * numero_decimal_2;
				    	printf(" * O resultado da opera��o matem�tica �: %.2lf", resultado);
					}
					else if(strcmp(operador , "div") == 0)
					{
						if(numero_decimal_2 != 0)
						{
					    	resultado = numero_decimal_1 / numero_decimal_2;
					    	printf(" * O resultado da opera��o matem�tica �: %d",(int)resultado);
						}
						else
						{
							printf(" * N�o � poss�vel realizar divisa� por 0");
							printf("\a");
						}
					}
					else if(strcmp(operador , "/") == 0)
					{
						if(numero_decimal_2 != 0)
						{
							resultado = numero_decimal_1 / numero_decimal_2;
					    	printf(" * O resultado da opera��o matem�tica �: %.2lf", resultado);
						}
						else
						{
							printf(" * N�o � poss�vel realizar divisa� por 0");
							printf("\a");
						}
					}
					else if(strcmp(operador , "^") == 0)
					{
						resultado = pow(numero_decimal_1 , numero_decimal_2);
				    	printf(" * O resultado da opera��o matem�tica �: %.2lf", resultado);
					}else{
						printf(" * Opera��o inv�lida: %s n�o � uma opera��o v�lida.\n", operador);
						printf("\a");
					}
					printf("\n");
				break;
				default:
					printf(" * Erro ao selecionar aba: %d n�o � um caso v�lido.\n", resposta);
					printf("\a");
				break;
		 }
		break;
		case 2 :
			printf(" * Digite 3 para selecionar o conversor de bin�rio para decimal.\n * Digite 4 para selecionar o conversor de decimal para bin�rio.\n");
			printf("\n");
			scanf("%d", &resposta);
			printf("\n");
			switch(resposta)
			{
				case 3:
					printf(" * Digite 4 para selecionar o conversor de n�mero bin�rio, para decimal\n   desconsiderando o bit de sinal.\n * Digite 5 para selecionar o conversor de n�mero bin�rio para decimal\n   considerando o bit de sinal.\n");
					printf("\n");
					scanf("%d", &resposta);
					printf("\n");
					switch(resposta)
					{
						case 4:
							printf(" * Digite um n�mero em bin�rio - fracion�rio ou n�o - cujo deseja saber sua\n   convers�o em decimal.\n   Ex: 1111 a sa�da ser� 15, se 10001,1 a sa�da ser� 17,5.\n");
							setbuf(stdin, NULL);
							printf("\n");
							gets(string_binario);
							printf("\n");
							tamanho_da_string_binario = strlen(string_binario);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O la�o de repeti��o a seguir verifica se o n�mero digitado est� na formata��o exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condi��o a seguir verifica se o primeiro digito � uma virgula ou algum espa�amento.
								if((string_binario[0] == ',') || (string_binario[0] == ' '))
								{	
									printf(" * N�mero inv�lido: n�o utilize espa�amentos ou virgula no inicio do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se o ultimo digito � uma virgula ou algum espa�amento.
								else if((string_binario[ultima_posicao] == ',' ) || (string_binario[ultima_posicao] == ' '))
								{
									printf(" * N�mero inv�lido: n�o utilize espa�amentos nem virgula no final do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se s� h� caracteres v�lidos para bin�rio.
								else if((string_binario[contador] == '1') || (string_binario[contador] == '0') || (string_binario[contador] == ' ') || (string_binario[contador] == ','))
								{
									verficador_de_formatacao = 1;
								}
								//A seguir � verificado se o caractere inv�lido � um ponto, ou se � outro caractere inv�lido qualquer.
								else
								{
									verficador_de_formatacao = 0;	
									if(string_binario[contador] == '.')
									{
										printf(" * N�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do programa, para\n   n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
									}
									else
									{
										printf(" * N�mero inv�lido: utilize somente os n�meros 0 e 1, podendo ainda, haver\n   virgula em casos de n�meros fracion�rios e espa�amentos entre os n�meros\n   (exceto no incio e no final do n�mero)\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verifica��o anterior, a convers�o � realizada. 
							if(verficador_de_formatacao == 1)
							{
								// O la�o de repeti��o a seguir retira os espa�os do n�mero bin�rio digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espa�os entre os n�meros, o condicional a seguir atrav�s da fun��o 'isspace' verifica se em determinada posi��o, � um desses casos.  
									if(isspace(string_binario[posicao]))
									{
										//Podendo haver espa�os adjacentes, o la�o de repeti��o a seguir adiciona +1 a posi��o sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario[posicao]));
									}
									//A String sem espa�os ser� armazenada no inicio dela mesma, por�m sem os espa�os.
									string_binario[contador] = string_binario [posicao]; 
									/*N�o conferir se a vari�vel 'posicao' j� atingiu a quebra de linha - \n - pode resultar em conte�dos indesej�veis 
									armazenados na mesma, visto que a vari�vel 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espa�os.
								tamanho_da_string_binario = strlen(string_binario); 
								//Para convers�o em bin�rio, deve-se iniciar pelo �ltimo n�mero, a fun��o 'strrev' inverte 'string_bin�rio' facilitando calcular pelo �ltimo n�mero, pois ele se torna o primeiro.
								strrev(string_binario);
								/* O la�o de repeti��o a seguir converte o n�mero bin�rio em string, para um n�mero inteiro, atribuindo cada caractere n�merico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracion�ria, ser� atribuida ao seu valor na tabela ASCII: 44 */
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
								//No la�o de repeti��o a seguir, ser� contada a quantidade de n�meros da parte inteira e fracion�ria (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario[contador] == ',')
									{ 
										tamanho_da_parte_fracionaria  = contador;//Ap�s inveter a String, contar at� que se encontre uma virgula, � contar a quantidade de n�meros fracion�rios.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//� necess�rio diminuir 1, pois a subtra��o do tamanho da string menos a parte fr�cion�ria, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para convers�o da parte fracion�ria do bin�rio usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se n�o houver parte fracion�ria, o tamanho da parte inteira ser� o contador +1 (pois inicia em 0).
									}
								}
								/*O condicional a seguir converte o n�mero bin�rio em n�mero decimal. Se houver parte fracion�ria, 
								a convers�o se iniciar� por ela, se n�o houver. a convers�o ser� somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a virgula como ponto de referencia para convers�o entre a parte fracion�ria e inteira. A virgula 
										ocupa um espa�o no vetor, e esse espa�o diz respeito a uma posi��o depois da parte fracion�ria e uma antes do inicio parte inteira*/
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
								//O condicional a seguir trata da exibi��o do n�mero convertido, se houver parte facion�ria no n�mero bin�rio ela ser� exibida no em seu equivalente decimal.
								if(tamanho_da_parte_fracionaria > 0)
								{
									printf(" * O n�mero digitado convertido para decimal �: %.5lf\n", decimal);	
								}
								else
								{
									printf(" * O n�mero digitado convertido para decimal �: %d\n", (int)decimal);
								}
							}
						break;
						case 5:
							printf(" * Digite um n�mero em bin�rio positivo ou negativo - fracion�rio ou n�o - cujo\n   deseja saber sua convers�o em decimal, considere o primeiro n�mero o sinal\n   do n�mero.\n * 0 para n�meros positivos\n * 1 para n�meros negativo\n   Ex: 01111 a sa�da ser� 15, se 10001,01 a sa�da ser� -15,75\n");
							setbuf(stdin, NULL);
							printf("\n");
							gets(string_binario);
							printf("\n");
							tamanho_da_string_binario = strlen(string_binario);//'tamanho_da_string_binario' recebe o tamanho da string digitada.
							ultima_posicao = tamanho_da_string_binario - 1;//'ultima_posicao', recebe o indice do ultimo caractere da string.
							//O la�o de repeti��o a seguir verifica se o n�mero digitado est� na formata��o exigida.
							for(contador = 0; contador < tamanho_da_string_binario;contador++)
							{
								//A condi��o a seguir verifica se o primeiro digito � uma virgula ou algum espa�amento.
								if((string_binario[0] == ',') || (string_binario[0] == ' '))
								{	
									printf(" * N�mero inv�lido: n�o utilize espa�amentos ou virgula no inicio do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se o ultimo digito � uma virgula ou algum espa�amento.
								else if((string_binario[ultima_posicao] == ',' ) || (string_binario[ultima_posicao] == ' '))
								{
									printf(" * N�mero inv�lido: n�o utilize espa�amentos nem virgula no final do n�mero.\n");
									printf("\a");
									break;
								}
								//A condi��o a seguir verifica se s� h� caracteres v�lidos para bin�rio.
								else if((string_binario[contador] == '1') || (string_binario[contador] == '0') || (string_binario[contador] == ' ') || (string_binario[contador] == ','))
								{
									verficador_de_formatacao = 1;
								}
								//A seguir � verificado se o caractere inv�lido � um ponto, ou se � outro caractere inv�lido qualquer.
								else
								{
									verficador_de_formatacao = 0;	
									if(string_binario[contador] == '.')
									{
										printf(" * N�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do programa, para\n   n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
									}
									else
									{
										printf(" * N�mero inv�lido: utilize somente os n�meros 0 e 1, podendo ainda, haver\n   virgula em casos de n�meros fracion�rios e espa�amentos entre os n�meros\n   (exceto no incio e no final do n�mero)\n");
									}
									printf("\a");
									break;
								}
							}
							//Dependendo da verifica��o anterior, a convers�o � realizada. 
							if(verficador_de_formatacao == 1)
							{	
								// O la�o de repeti��o a seguir retira os espa�os do n�mero bin�rio digitado.
								for(contador = 0, posicao = 0;contador < tamanho_da_string_binario; contador ++, posicao ++)
								{	
									//Se houverem espa�os entre os n�meros, o condicional a seguir atrav�s da fun��o 'isspace' verifica se em determinada posi��o, � um desses casos.  
									if(isspace(string_binario[posicao]))
									{
										//Podendo haver espa�os adjacentes, o la�o de repeti��o a seguir adiciona +1 a posi��o sempre que isso ocorrer. 
										do
										{
											posicao ++;				
										}
										while(isspace(string_binario[posicao]));
									}
									string_binario[contador] = string_binario [posicao]; //A String sem espa�os ser� armazenada no inicio dela mesma, por�m sem os espa�os. 
									/*N�o conferir se a vari�vel 'posicao' j� atingiu a quebra de linha - \n - pode resultar em conte�dos indesej�veis 
									armazenados na mesma, visto que a vari�vel 'posicao' pode exceder o 'tamanho_da_string_binario'*/
									if(string_binario [posicao] == '\n')
									{
										break;
									}
								}
								//'tamanho_da_string_binario' recebe agora o tamanho da string que fora armazenada sem os espa�os.
								tamanho_da_string_binario = strlen(string_binario);			
								/*Se o n�mero iniciar em 1, ou seja, for negativo, ser� necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
								d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
								if(string_binario[0] == '1')
								{
									ultima_posicao = tamanho_da_string_binario - 1; 
									//Primeiro � necess�rio verificar se h� parte fracion�ria. Isso se d� pela procura da virgula.
									for(contador = 0; contador < tamanho_da_string_binario; contador++)
									{
										if(string_binario[contador] == ',')
										{
											verificador_de_fracionario = 1;
											break;
										}
									}
									//Se houver parte fracion�ria ele fara o complemento de dois nela;
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
										ultima_posicao--;//Depois do complemento da parte fracion�ria, ainda � necess�rio diminuir uma posi��o, por causa da virgula
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
								//Para convers�o em bin�rio, deve-se iniciar pelo �ltimo n�mero, a fun��o 'strrev' inverte 'string_bin�rio' facilitando calcular pelo �ltimo n�mero, pois ele se torna o primeiro.
								strrev(string_binario); 
								/* O la�o de repeti��o a seguir converte o n�mero bin�rio em string, para um n�mero inteiro, atribuindo cada caractere n�merico 
								ao seu corresponde inteiro, exceto a virgula que se houver parte fracion�ria, ser� atribuida ao seu valor na tabela ASCII: 44 */
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
								//No la�o de repeti��o a seguir, ser� contada a quantidade de n�meros da parte inteira e fracion�ria (se houver).
								for(contador = 0; contador < tamanho_da_string_binario; contador ++)
								{
									if(string_binario[contador] == ',')
									{
										tamanho_da_parte_fracionaria  = contador;//Ap�s inveter a String, contar at� que se encontre uma virgula, � contar a quantidade de n�meros fracion�rios.
										tamanho_da_parte_inteira = (tamanho_da_string_binario - tamanho_da_parte_fracionaria) - 1;//� necess�rio diminuir 1, pois a subtra��o do tamanho da string menos a parte fr�cion�ria, conta com a virgula.
										expoente = -tamanho_da_parte_fracionaria; //Para convers�o da parte fracion�ria do bin�rio usa-se expoente negativo. 
										break;
									}
									else
									{
										tamanho_da_parte_fracionaria = 0;
										tamanho_da_parte_inteira = contador + 1; //Se n�o houver parte fracion�ria, o tamanho da parte inteira ser� o contador +1 (pois inicia em 0).
									}
								}						
								//Na convers�o n�o deve ser contado o bit de sinal, logo diminui-se 1 do seu tamanho.
								tamanho_da_string_binario = tamanho_da_string_binario - 1;
								tamanho_da_parte_inteira = tamanho_da_parte_inteira - 1;
								/*O condicional a seguir converte o n�mero bin�rio em n�mero decimal. Se houver parte fracion�ria, 
								a convers�o se iniciar� por ela, se n�o houver. a convers�o ser� somente na parte inteira.*/
								if(tamanho_da_parte_fracionaria > 0)
								{
									for(contador = 0; contador < tamanho_da_string_binario; contador ++)
									{	
										/*O	condicional a seguir, usa a v�rgula como ponto de refer�ncia para convers�o entre a parte fracion�ria e inteira. A v�rgula 
										ocupa um espa�o no vetor, e esse espa�o diz respeito a uma posi��o depois da parte fracion�ria e uma antes do in�cio parte inteira*/
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
								//Se o n�mero inicar em 1, resultar� em um resultado negativo. Por�m com a utiliza��o da fun��o strrev, a primeira posi��o se tona a �ltima.
								if(string_binario[tamanho_da_string_binario] == '1')
								{
									decimal = decimal * -1;	
								}
								//O condicional a seguir trata da exibi��o do n�mero convertido, se houver parte facion�ria no n�mero bin�rio ela ser� exibida no em seu equivalente decimal.
								if(tamanho_da_parte_fracionaria > 0)
								{
									printf(" * O n�mero convertido para decimal �: %.5lf\n", decimal);	
								}
								else
								{
									printf(" * O n�mero convertido para decimal �: %d\n", (int)decimal);
								}
							}
						break;
						default:
							printf(" * Erro ao selecionar aba: %d n�o � um caso v�lido.\n", resposta);
							printf("\a");
						break;						
					}
				break;	
				case 4:
					printf(" * Digite 5 para selecionar o conversor de n�mero decimal para bin�rio\n   deconsiderando o sinal do n�mero.\n * Digite 6 para selecionar o conversor de n�mero decimal para bin�rio\n   considerando o sinal do n�mero.\n");
					printf("\n");
					scanf("%d", &resposta);
					printf("\n");
					switch(resposta)
					{
						case 5:
							printf(" * Digite um n�mero decimal - fracion�rio ou n�o - deconsiderando o sinaL do\n   n�mero, cujo deseja saber sua convers�o em binario:\n");
							printf("\n");
							scanf("%s", &decimal_string);
							printf("\n");
							tamanho_da_string_decimal = strlen(decimal_string);
							ultima_posicao = tamanho_da_string_decimal - 1;
							//Verifica se o n�mero que o usu�rio digitou est� de acordo com a formata��o exigida.
							contador = 0;
							if(decimal_string[contador] == '+')
							{
								verficador_de_formatacao = 1;
								contador++;
							}
							else if(decimal_string[contador] == '-')
							{
								verficador_de_formatacao = 0;
								printf(" * N�o � poss�vel realizar a convers�o de n�meros negativos nessa parte do\n   programa. H� uma �rea especifica para isso.\n");
								printf("\a");
								contador++;
								break;
							}
							else if(decimal_string[contador] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * N�mero inv�lido: n�o utilize virgula no inicio do n�mero.\n");
								printf("\a");
								break;
							}
							else if(decimal_string[ultima_posicao] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * N�mero inv�lido: n�o utilize virgula no final do n�mero.\n");
								printf("\a");
								break;
							}
							while(contador < tamanho_da_string_decimal)
							{
								if(decimal_string[contador] == '.')
								{
									verficador_de_formatacao = 0;
									printf(" * N�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do programa, para\n   n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
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
									printf(" * %s n�o � um n�mero decimal poss�vel de realizar a convers�o para bin�rio.\n", decimal_string);
									printf("\a");
									break;
								}
								contador++;
							}
							//Se o n�mero estiver de acordo com a formata��o exigida, ser� feita sua convers�o.
							if(verficador_de_formatacao == 1)
							{
								decimal = atof(decimal_string); // Convers�o da String para um n�mero decimal tipo real(float).
								//Como 'parte_inteira_do_decimal' � uma vari�vel do tipo inteiro, faz�-la receber o n�mero real digitado � armazenar sua parte inteira.
								parte_inteira_do_decimal = decimal;
								//Como 'parte_fracion�ria_do_decimal' � uma vari�vel do tipo double, fazendo-a receber o n�mero real menos sua parte inteira, obteremos a parte fracion�ria do n�mero real (se hover).
								parte_fracionaria_do_decimal = decimal - parte_inteira_do_decimal;
								/*O la�o de repeti��es a seguir define o tamanho da parte inteira do bin�rio pela quantidade de vezes que a parte
								inteira do decimal - em m�ltiplas divis�es inteiras - for divis�vel por 2 , at� que o quociente chegue em 0 */	
								while(quociente !=0)
								{
									quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma vari�vel inteira, recebe a parte inteira do resto da divis�o da 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: caracter�stica de m�ltiplas divis�es inteiras. 
									tamanho_inteiro_do_binario ++;
								}
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Aloca��o de mem�ria, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
								ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padr�o, vetores t�m sua primeira posi��o em zero, logo a �ltima posi��o de 'binario_inteiro' � o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = decimal;
								/*O la�o de repeti��o a seguir converte a parte inteira do n�mero decimal para bin�rio, armazenando o resto 
								de divis�es inteiras da 'parte_inteira_do_decimal' por 2, at� que o contador do la�o atinja o 'tamanho_inteiro_do_binario' */		
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na �ltima posi��o recebe o resto (% - mod) da divis�o inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--;
								}
								//Exibi��o da parte inteira em bin�rio.
								printf(" * O n�mero digitado convertido para bin�rio �: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracion�ria no decimal digitado, mutiplica��es definir�o seu tamanho no vetor 'binario_fracionario'.
								if(parte_fracionaria_do_decimal > 0 ) 
								{
									/*O la�o de repeti��es a seguir define o tamanho da parte fracion�ria do bin�rio pela quantidade de vezes que ela 
									� multiplicada por 2 - tendo sempre sua parte inteira retirada - at� que 'produto_fracionario' se chegue em 1 */
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
									/*O la�o de repeti��es a seguir armazena em 'binario_fracionario' - na posi��o do 
									contador - a parte  inteira retirada das multipli��es do 'produto_fracionario' por 2 */
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
							printf(" * Digite um n�mero decimal - fracion�rio ou n�o - considerando o sinaL do\n   n�mero cujo deseja saber sua convers�o em bin�rio:\n");
							printf("\n");
							scanf("%s", &decimal_string);
							printf("\n");
							tamanho_da_string_decimal = strlen(decimal_string);
							ultima_posicao = tamanho_da_string_decimal - 1;
							//Verifica se o n�mero que o usu�rio digitou est� de acordo com a formata��o exigida.
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
								printf(" * N�mero inv�lido: n�o utilize virgula no inicio do n�mero.\n");
								printf("\a");
								break;
							}
							else if(decimal_string[ultima_posicao] == ',')
							{
								verficador_de_formatacao = 0;
								printf(" * N�mero inv�lido: n�o utilize virgula no final do n�mero.\n");
								printf("\a");
								break;
							}
							while(contador < tamanho_da_string_decimal)
							{
								if(decimal_string[contador] == '.')
								{
									verficador_de_formatacao = 0;
									printf(" * N�mero inv�lido: Voc� est� utilizando a vers�o Brasileira do programa, para\n   n�meros fracion�rios utilize virgula ao inv�s de ponto.\n");
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
									printf(" * %s n�o � um n�mero decimal poss�vel de realizar a convers�o para bin�rio.\n", decimal_string);
									printf("\a");
									break;
								}
								contador++;
							}
							//Se o n�mero estiver de acordo com a formata��o exigida, ser� feita sua convers�o.
							if(verficador_de_formatacao == 1)
							{
								decimal = atof(decimal_string);// Convers�o da String para um n�mero decimal tipo real(float).	
								//Realizar a convers�o com o n�mero em negativo d� erro, logo � necess�rio t�-lo positivo.
								if(decimal < 0)
								{
									decimal_positivo = decimal * -1;
								}
								else
								{
									decimal_positivo = decimal;
								}
								//Como 'parte_inteira_do_decimal' � uma vari�vel do tipo inteiro, faz�-la receber o n�mero real digitado � armazenar sua parte inteira.
								parte_inteira_do_decimal = decimal_positivo;
								//Como 'parte_fracion�ria_do_decimal' � uma vari�vel do tipo double, fazendo-a receber o n�mero real menos sua parte inteira, obteremos a parte fracion�ria do n�mero real (se hover).
								parte_fracionaria_do_decimal = decimal_positivo - parte_inteira_do_decimal;
								/*O la�o de repeti��es a seguir define o tamanho da parte inteira do bin�rio pela quantidade de vezes que a parte
								inteira do decimal - em m�ltiplas divis�es inteiras - for divis�vel por 2 , at� que o quociente chegue em 0 */	
								while(quociente !=0)
								{
									quociente = parte_inteira_do_decimal/2;//'quociente' por ser uma vari�vel inteira, recebe a parte inteira do resto da divis�o da 'parte_inteira_do_decimal' por 2.
									parte_inteira_do_decimal = quociente;//Agora, 'parte_inteira_do_decimal' se torna a parte inteira do resto: caracter�stica de m�ltiplas divis�es inteiras. 
									tamanho_inteiro_do_binario ++;
								}
								tamanho_inteiro_do_binario++; // Devido ao bit de sinal, acrescenta-se mais um ao tamanho do bin�rio.
								binario_inteiro = calloc(sizeof(int), tamanho_inteiro_do_binario); //Aloca��o de mem�ria, para 'binario_inteiro', antes definido como um ponteiro, e agora usado como vetor. 
								ultima_posicao = tamanho_inteiro_do_binario - 1;//Por padr�o, vetores t�m sua primeira posi��o em zero, logo a �ltima posi��o de 'binario_inteiro' � o 'tamanho_inteiro_do_binario' menos um.
								parte_inteira_do_decimal = decimal_positivo;								
								//Se o n�mero for negativo seu primeiro digito ser� 1, se n�o, 0.
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
									binario_inteiro[ultima_posicao] = parte_inteira_do_decimal % 2;//O vetor 'binario_inteiro' na �ltima posi��o recebe o resto (% - mod) da divis�o inteira da 'parte_inteira_do_decimal' por 2. 	
									quociente = parte_inteira_do_decimal/2;
									parte_inteira_do_decimal = quociente;
									ultima_posicao--;
								}
								/*Se o n�mero for negativo, ser� necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
								d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
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
								//Exibi��o da parte inteira em bin�rio.
								printf(" * O n�mero digitado convertido para bin�rio �: ");
								for(contador = 0; contador < tamanho_inteiro_do_binario; contador ++)
								{
									printf("%d", binario_inteiro[contador]);
								}
								//Se houver parte fracion�ria no decimal digitado, mutiplica��es definir�o seu tamanho no vetor 'binario_fracionario'.
								if(parte_fracionaria_do_decimal > 0)
								{
									/*O la�o de repeti��es a seguir define o tamanho da parte fracion�ria do bin�rio pela quantidade de vezes que ela 
									� multiplicada por 2 - tendo sempre sua parte inteira retirada - at� que 'produto_fracionario' se chegue em 1 */
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
									/*O la�o de repeti��es a seguir armazena em 'binario_fracionario' - na posi��o do contador - 
									a parte inteira retirada das multipli��es do 'produto_fracionario' por 2 */
									for(contador = 0; contador < tamanho_fracionario_do_binario; contador ++)
									{
										produto_fracionario = parte_fracionaria_do_decimal * 2;
									 	parte_inteira_do_produto_fracionario = produto_fracionario;
										binario_fracionario[contador] = parte_inteira_do_produto_fracionario;
										parte_fracionaria_do_decimal = produto_fracionario - parte_inteira_do_produto_fracionario;
									}
									/*Se o n�mero for negativo, ser� necess�rio realizar o complemento de 2. H� v�rias maneiras de aplica-lo, a que utilizamos aqui se 
									d� pela procura - da direita para a esquerda - do n�mero 1, quando encontrado inverte-se todos os n�meros ap�s ele, exceto o bit de sinal.*/
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
							printf(" * Erro ao selecionar aba: %d n�o � um caso v�lido.\n", resposta);
							printf("\a");
						break;
					}
				break;
				default:
					printf(" * Erro ao selecionar aba: %d n�o � um caso v�lido.\n", resposta);
					printf("\a");
				break;
			}
		break;
		default:
			printf(" * Erro ao selecionar aba: %d n�o � um caso v�lido.\n", resposta);
			printf("\a");
		break;
	}
	setbuf(stdin, NULL);
	printf("\n");
	printf(" * Deseja realizar outra opera��o?\n   Digite 1 p/ SIM ou 2 p/ para N�O\n");
	printf("\n");
	scanf("%d",&resposta);
	//O Switch a seguir tem como finalidade dar a oportunidade ao usuario fazer alguma escolha entre as alternativas novamente, se quiser.
	switch(resposta)
	{
		case 1:
			system("CLS");//Limpa a tela.
			return main();//Retorna ao in�cio do programa.
		break;
		case 2:
			exit(0);//Finaliza o programa.
		break;
	}
	return(0);
}
