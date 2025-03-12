#include <stdio.h>//biblioteca de comunica��o com o usuario
#include <stdlib.h>//biblioteca responsavel pela aloca��o de espa�o na memoria
#include <locale.h>//biblicote responsavel pela aloca��o de texto por regiao
#include <string.h>//biblioteca responsavel por cuidar das string 

//sem precisar que o programa execute a fun��o a n�o ser que seja chamada.
int registro()//registro do usuario
{
	char arquivo[40];//guardara o valor do "cpf" na variavel arquivo 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s,", cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file; //responsavel por criar um arquivo ou file no "banco de dados"
	file = fopen(arquivo, "w");//fopen abre  um arquivo com nome da "varivel", "W" vem de write que abre um arquivo novo. ou so cria
	fprintf(file,"%s,",cpf);//salva da variavel no arquivo 
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");//"a" essa sigla � responsavel por atualizar o arquivo. parte responsavel pela "formata��o" do arquivo
	fprintf(file,"%s,",nome );
	fclose(file);
	
	printf("Digite o sobrenome  a ser cadastrado: ");
	scanf("%s", sobrenome );
	file = fopen(arquivo, "a");
	fprintf(file,"%s,", sobrenome);
	fclose (file); 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file =fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	
	system("pause");
}

int consulta()//consulta atraves do cpf
{
	setlocale(LC_ALL, "Portuguese");//seta a linguagem usada para a escrita?
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado:\n");
	scanf(" %s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//"r" letra responsavel por falar ao sistema que � para ler o aquivo
	
	if(file == NULL)
	{
		printf("CPF esta errado ou n�o exite no sistema.\n");	
	}
	
	while(fgets(conteudo, 200, file ) !=  NULL)
	{
		printf("Essas s�o as informa��es do usuario:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system ("pause");
}

int deletar()//deletar usuarios
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Informe o cpf do usu�rio que voce deseja deletar:\n");
	scanf("%s", cpf);

	//remove(cpf);
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		fclose(file);
		remove(cpf);//lembrete � importante fechar o arquivo para que o remove consiga apaga-lo
		
		printf("Usuario deletado com sucesso!\n");
		system("pause");
	}
	else
	{
		
		printf("O usu�rio n�o existe no sistema ou ja foi deletado\n");
		
		system("pause");
	}
	
	
}

int main()//menu
{
	
	int opcao = 0;
	int laco = 1;
	
	setlocale(LC_ALL, "Portuguese");//seta a linguagem usada para a escrita?
	
	while(laco==1)
	{
	
		system("cls");
		
		
		
		printf("\t###Cart�rio EBAC ###\n\n");
		printf("Escola a opc�o desejada no menu:\n\n");//inicio do menu
		
		printf("\t1- Registar nomes.\n");
		printf("\t2- Consultar nomes.\n");
		printf("\t3- Deletar nomes.\n\n");	
		printf("Ou pressione 4 para sair da execu��o\n");
	//	printf("Esse software livre, feito pelo Turnare\n"); //usar depois.
	
		scanf("%d", &opcao);//"captura" o input do usuario 
	
		
		
		system ("cls");
		
	
		switch(opcao)//inicio da sele��o 
		{
			case 1:
				registro();//chama a fun��o registro			
				break;
			
			case 2:
				consulta();//chama a fun��o consulta
				break; 
			
			case 3: 
				deletar();//chama a fun��o deletar
				break;
			case 4:
				printf("Obrigado por usar o cart�rio da EBAC!!");
				laco = 0;
				break;
			default:
				printf("Esta op��o � invalida\n");
				system ("pause");
				break;	
		}
	}
}

