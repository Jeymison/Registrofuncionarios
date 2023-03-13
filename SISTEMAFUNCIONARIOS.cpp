#include <stdio.h> // Biblioteca de comunica��o com o usuario
#include <stdlib.h> // Biblioteca de aloca��o de espa�o de memoria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�es
#include <string.h> //Biblioteca responsavel por cuidar das Strings

int incluir() // Fun��o responsavel por cadastrar os usuarios no sistema
{
	// Inicio da cria��o das variaveis/strings
	char arquivo[40]; // 40 � numero de letras ou numeros que podem ser colocados
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da cria��o das variaveis/strings
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando as informa��es do usuario
    scanf("%s", cpf); // %s est� salvando/ armazenando as strings
    
    strcpy(arquivo, cpf); // STRCPY Responsavel por copiar os valores das strings cpf, nome, sobrenome e cargo
    
    FILE *file; // Cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // Cria a pasta no arquivo de banco de dados (W significa novo arquivo/escrever)
    fprintf(file,cpf); // Salva os dados da variavel
    fclose(file); // Fecha o Arquivo
    
    file = fopen(arquivo, "a"); // "A" � para atualizar o arquivo, abrindo e atualizando
    fprintf(file,","); // Colocando a virgula entre os dados informados pelo usuario
    fclose(file); // Fecha o Arquivo
    
    printf("Digite o nome a ser cadastrado: "); // Coletando as informa��es do usuario
    scanf("%s", nome); // %s est� salvando/ armazenando as strings
    
    file = fopen(arquivo, "a"); // "A" � para atualizar o arquivo, abrindo e atualizando
    fprintf(file,nome); // Salva os dados da variavel nome
    fclose(file); // Fecha arquivo
    
    file = fopen(arquivo, "a"); // "A" � para atualizar o arquivo, abrindo e atualizando
    fprintf(file, ","); // Colocando a virgula entre os dados informados pelo usuario
    fclose(file), // Fecha arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // Coletando as informa��es do usuario
    scanf("%s", sobrenome); // %s est� salvando/ armazenando as strings
    
    file = fopen(arquivo, "a"); // "A" � para atualizar o arquivo, abrindo e atualizando
    fprintf(file,sobrenome); // Salva os dados da variavel sobrenome
    fclose(file); // Fecha arquivo
    
    file = fopen(arquivo, "a"); // "A" � para atualizar o arquivo, abrindo e atualizando
    fprintf(file, ","); // Colocando a virgula entre os dados informados pelo usuario
    fclose(file); // Fecha arquivo
    
    printf("Digite o cargo a ser cadastrado: "); // Coletando as informa��es do usuario
    scanf("%s", cargo); // %s est� salvando/ armazenando as strings
	
	file = fopen(arquivo, "a"); // "A" � para atualizar o arquivo, abrindo e atualizando
	fprintf(file,cargo); // Salva os dados da variavel cargo
	fclose(file); // Fecha arquivo
	
	system("pause"); // Para parar a tela ao usuario		            
}

int consultar()
{  
    // Inicio da cria��o das variaveis/strings
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	char cpf[40];
	char conteudo[200];
	// Final da cria��o das variaveis/strings
	
	printf("Digite o CPF a ser consultado: "); // Coletando as informa��es do usuario
	scanf("%s", cpf); // %s est�ando as strings salvando/ armazen
	
	FILE *file; // Cria o arquivo no banco de dados
	file = fopen(cpf, "r"); // R significa ler o arquivo, abrindo
	
	
	if(file == NULL) // Null significa nulo
	{
		printf("CPF n�o localizado no sistema!\n"); // Informando o usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL) // lendo a varivael cpf dentro da pasta arquivo
	{
		printf("\nEssas s�o as informa��es cadastradas: "); // Informando ao usuario
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);	
    system("pause");  // Para parar a tela ao usuario	
}

int excluir()
{  
    // Inicio da cria��o das variaveis/strings
   	char cpf[40];
   	// Final da cria��o das variaveis/strings
	
	printf("Digite o CPF do usu�rio a ser excluido: "); // Coletando as informa��es do usuario
	scanf("%s", cpf); // %s est�ando as strings salvando/ armazen
	
	remove(cpf); // excluindo o dado
	
	FILE *file; // Cria o arquivo no banco de dados
	file = fopen(cpf, "r"); //  R significa ler o arquivo, abrindo'		
		
	if(file == NULL) // Null significa nulo
	{
		printf("Esse CPF n�o se encontra cadastrado no sistema!\n"); // Informando o usuario
		
	}	
	
	while(fgets(cpf, 40, file) != NULL)// lendo a varivael cpf dentro da pasta arquivo
	{
		printf("CPF excluido com sucesso!\n"); // Informando o usuario
		system("pause");  // Para parar a tela ao usuario
	}	
    fclose(file);
	system("pause");	
}

int main() // Definindo a Linguagem
    { 
	int opcao=0; // Definindo as variaveis
	int laco=1; // Definindo a repeti��o
	char senhadigitada[10]= "a"; // String para o usuario criar a senha
	int comparacao; // Comparar a Char senhadigitada
				
	printf("### Sistema de Controle de Funcionarios ###\n\n");
	printf("Seja bem vindo!\n\n");
	printf("Login de Administrador!\n\nDigite sua senha: "); // Colhendo os dados do usuario/ informando que � Login administrador
	scanf("%s", senhadigitada); // Armazenando os dados de senha do usuario na string
	
	comparacao = strcmp(senhadigitada, "admin"); //strcmp significa compara��o de strings
	
	if(comparacao == 0)
	{
		system("cls"); 	
	    for(laco=1;laco=1;) // Inicio do processo de repeti��o
	    {
	
	        system("cls"); // CLS serve para limpar a tela
	
	     	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	        printf("### Sistema de Controle de Funcion�rios ###\n\n"); // Inicio do Menu
	        printf("Escolha a op��o desejada do menu!\n\n");
     	    printf("\t1 - Incluir Funcion�rio\n");
       	    printf("\t2 - Consultar Funcion�rio\n");
	        printf("\t3 - Excluir Funcion�rio\n\n");
	        printf("\t4 - Sair do Sistema\n\n");
	        printf("Op��o:"); // Fim do Menu
	
	        scanf("%d", &opcao); // Armazenando a escolha do usuario 
	
	        system("cls");  // CLS serve para limpar a tela
	    
	        switch(opcao) 
	        {
	    	    // Inicio da escolha do usuario/ menu
	    	    case 1:
	    	    incluir();
	            break; // Break encerra cada op��o
	        
	            case 2:
	            consultar();
		        break; // Break encerra cada op��o
		    
		        case 3:
		        excluir();	
		        break; // Break encerra cada op��o
		    
		        case 4:
		        printf("Obrigado por utilizar o sistema!\n");
		        return 0;
		        break;
		    
		        default:
		        printf("Essa op��o n�o est� disponivel!\n"); // Informando o usuario 
		        system("pause"); // Pausa a tela para visualiza��o do usuario
		        break; // Break encerra cada op��o
		 	} // Fim da escolha usuario/menu
		} // Fim do processo de repeti��o
    }
    
    else
        printf("Senha incorreta!");
} 
