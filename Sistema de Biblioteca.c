#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define QTD 100


typedef struct{
	char titulo[40];
	char autor[20];
	float numeroDoCatalogo;
	int anoDePublicacao;
	int numeroDaCopia;
	
	char dataEmprestimo[10];
	char dataRetorno[10];
}LIVRO;


void exibe_livro(LIVRO[QTD], int num); // h. Listar todos os livros existentes.
void inserir_livro(LIVRO[QTD], int num);//b. Inserir um livro.
void procurar_titulo(LIVRO[QTD], int num); //c. Procurar um livro através do seu título
void exibe_um_livro(LIVRO[QTD], int num); //a. Mostrar os dados de um livro
void procurar_autor(LIVRO[QTD], int num);//d. Procurar um livro através do nome do seu autor
void alterar_titulo(LIVRO[QTD], int num);//e. Alterar o título de um livro

void data_emprestimo(LIVRO[QTD], int num);//f. Registar a data de empréstimo de um livro
void data_retorno(LIVRO[QTD], int num);//g. Registar a data de retorno de um livro.


int main(int argc, char* argv){
	
	LIVRO lv[QTD];//Struct
	int sel;// menu
	int num_livro;//numero de livro existente
	bool existe;
	
	do{
	
		printf("********************\n");
		printf("BIBLIOTECA DA IES\n");
		printf("**********************\n");
		printf("1 - Inserir novo livro\n");
		printf("2 - Procurar livro por titulo\n");
		printf("3 - Procurar livro por autor.\n");
		printf("4 - Alterar nome do livro.\n");
		printf("5 - Registar data de emprestimo de um livro.\n");
		printf("6 - Registar data de retorno de um livro\n");
		printf("7 - Listar livros existentes na biblioteca.\n");
		printf("8 - Sair\n");
		printf("Selecione: ");
		scanf("%d",&sel);
		
		system("cls");
		
		if(sel == 1){//- Inserir novo livro
			
			inserir_livro(lv, num_livro);
			
			num_livro = num_livro + 1;//contador de livro
			existe = true;// exist livro
			printf("\n");
			system("cls");
			
		} else if(sel == 2){//2 - Procurar livro por titulo\n
			procurar_titulo(lv, num_livro);//procurar livro mesmo se não existi
		
		}else if(sel == 3){//3 - Procurar livro por autor
		
			procurar_autor(lv, num_livro);//procurar autor mesmo se não existi
		
		}else if(sel == 4){//4 - Alterar nome do livro.
			
			if(existe == true){//se existir livro continua
				
				alterar_titulo(lv, num_livro);
				
			}else{
				printf("***Nao e possivel alterar pois ");
				printf("Nao ha livro registrado***\n");
				system("pause");
			}
			
		
		}else if(sel == 5){//5 - Registar data de emprestimo de um livro.
			if(existe == true){//se existir livro continua
				data_emprestimo(lv, num_livro);
			}else{
				printf("***Nao ha livro registrado***\n");
				system("pause");
			}
		
		}else if (sel == 6){//6 - Registar data de retorno de um livro
			if(existe == true){//se existir livro continua
				data_retorno(lv,num_livro);
			}else{
				printf("***Nao ha livro registrado***\n");
				system("pause");
			}
			
		}else if(sel == 7){//7 - Listar livros existentes na biblioteca.
			exibe_livro(lv, num_livro);
			system("pause");		
		}else if(sel == 8){//8 - sair
			printf("OK");// nao parece mas ok
		}else{
			printf("Numero Invalido\n");// aparece se digita algo invalido
			system("pause");
		}
	
		
		
		system("cls");
		
	}while(sel!= 8);
	printf("Programa Finalizado");//Fim
}

void exibe_um_livro(LIVRO lv[QTD], int num){//a. Mostrar os dados de um livro
	
	printf("\n**********Livro %d**********\n", num+1);

	printf("Nome do Livro: %s\n", lv[num].titulo);
	printf("Nome do Autor: %s\n", lv[num].autor);
	printf("Ano de Publicacao: %d\n", lv[num].anoDePublicacao);
	printf("Catalogo: %f\n", lv[num].numeroDoCatalogo);
	printf("Copias disponivel: %d\n", lv[num].numeroDaCopia);
	
}

void exibe_livro(LIVRO lv[QTD], int num){//h. Listar todos os livros existentes.
	
	int i;
	
	if(num == 0){
		printf("***Nenhum Livro registrado!***\n");
		
	}else{
		for(i =0; i < num; i++){
		
			printf("\n**********Livro %d**********\n", i+1);

			printf("Nome do Livro: %s\n", lv[i].titulo);
			printf("Nome do Autor: %s\n", lv[i].autor);
			printf("Ano de Publicacao: %d\n", lv[i].anoDePublicacao);
			printf("Catalogo: %f\n", lv[i].numeroDoCatalogo);
			printf("Copias disponivel: %d\n", lv[i].numeroDaCopia);
			//printf("Data de Emprestimo: %s\n", lv[i].dataEmprestimo);
			//printf("Data de Emprestimo: %s\n", lv[i].dataRetorno); Iria colocar esse campo mas não estava funcionado do jeito que queria
			
			
		}
		
	}
	
}




void inserir_livro(LIVRO lv[QTD], int num){ //b. Inserir um livro.
	
	
	printf("%d* Livro Cadastrado:\n", num+1);
	printf("Qual titulo do livro: ");
	fflush(stdin);
	gets(lv[num].titulo);
	
	printf("Qual o nome do Autor: ");
	gets(lv[num].autor);
	
	printf("Qual o ano de Publicacao: ");
	scanf("%d", &lv[num].anoDePublicacao);
	
	printf("Qual o numero no catalogo: ");
	scanf("%f", &lv[num].numeroDoCatalogo);
	
	printf("Numero de copia disponivel: ");
	scanf("%d", &lv[num].numeroDaCopia);
	
}

void procurar_titulo(LIVRO lv[QTD], int num){//c. Procurar um livro através do seu título

	
	int i;
	char pesquisar[40];
	char resu;
	bool existe;
	printf("Qual titulo procuras: ");
	fflush(stdin);
	gets(pesquisar);
	
	for(i =0; i< num; i++){	
    	resu = strstr(lv[i].titulo, pesquisar);
    	
    	if(resu != NULL){
    		if(existe == false){
    			printf("Livro Encontrado: %s\n", lv[i].titulo);
			}
    		exibe_um_livro(lv,i);
    		printf("\n");
    		existe = true;
		}
	}
	
	if(existe == false){
		printf("***Nao existe esse Livro no banco de dados***\n");
	}
    system("pause");
}

void procurar_autor(LIVRO lv[QTD], int num){//d. Procurar um livro através do nome do seu autor
	
	int i;
	char pesquisar[40];
	char resu;
	bool existe;
	printf("Qual o Autor procuras: ");
	fflush(stdin);
	gets(pesquisar);
	
	for(i =0; i< num; i++){	
    	resu = strstr(lv[i].autor, pesquisar); 
    	
    	if(resu != NULL){
    		
    		if(existe == false){
    			printf("Autor Encontrado: %s\n", lv[i].autor);
			}
    		exibe_um_livro(lv,i);
    		printf("\n");
    		existe = true;
		}
	}
	
	if(existe == false){
		printf("***Nao existe esse autor no banco de dados***\n");
	}
    system("pause");
	
}


void alterar_titulo(LIVRO lv[QTD], int num){ //e. Alterar o título de um livro

	int liv, SorN;
	
	do{
		printf("[Exemplo: LIVRO 1 digite '1']\n");
		printf("Qual o numero do Livro que \nvoce quer alterar o titulo: ");
		
		scanf("%d", &liv );
		system("cls");
		
		liv--;
		
		printf("***************************");
		printf("\nE Esse livro que queres alterar?");
		exibe_um_livro(lv,liv);
		printf("\nDigite [1] PARA SIM E [2] PARA NAO [Qualquer numero] Sair\n");
		printf("Digite: ");
		scanf("%d", &SorN);
		
		
	}while(SorN == 2);

	if(SorN == 1){
		printf("QUAL O NOVO NOME DO LIVRO: ");
		fflush(stdin);
		gets(lv[liv].titulo);
		
	}
	
	

}


void data_emprestimo(LIVRO lv[QTD], int num){//f. Registar a data de empréstimo de um livro
	
	int num_liv, SorN;
	
	do{
		printf("[Exemplo: LIVRO 1 digite '1']\n");
		printf("Qual o numero do Livro que \nfoi emprestado: ");
		
		scanf("%d", &num_liv);
		
		num_liv--;
	
		printf("E Esse livro que queres alterar?\n");
		exibe_um_livro(lv,num_liv);
		printf("Digite [1] PARA SIM E [2] PARA NAO [Qualquer numero] Sair\n");
		printf("Digite: ");
		scanf("%d", &SorN);
		
	}while(SorN == 2);
	
	if(SorN == 1){
		printf("QUAL DATA FOI EMPRESTADO: ");
		fflush(stdin);
		gets(lv[num_liv].dataEmprestimo);
		lv[num_liv].numeroDaCopia -= 1;

		
	}	
	
}

void data_retorno(LIVRO lv[QTD], int num){ //g. Registar a data de retorno de um livro.
	
	int num_liv, SorN;
	
	do{
		printf("[Exemplo: LIVRO 1 digite '1']\n");
		printf("Qual o numero do Livro que \quer anotar o retorno dele: ");
		
		scanf("%d", &num_liv );
		
		num_liv--;
	
		printf("E Esse livro que queres alterar?\n");
		exibe_um_livro(lv,num_liv);
		printf("Digite [1] PARA SIM E [2] PARA NAO [Qualquer numero] Sair\n");
		printf("Digite: ");
		scanf("%d", &SorN);
		
	}while(SorN == 2);
	
	if(SorN == 1){

		printf("QUAL A DATA DO RETORNO: ");
		fflush(stdin);
		gets(lv[num_liv].dataRetorno);
		lv[num_liv].numeroDaCopia += 1;
		
	}
	
	
	
}





