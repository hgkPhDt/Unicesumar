#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

//Aqui estou definindo constantes com valores de cores para deixar o programa mais bonitinho e apresentável. (espero que isso não desconte nota kk)
#define BOLD "\x1B[1m"
#define BLINK "\x1B[5m"
#define RED "\x1B[31m"
#define REVERSE "\x1B[7m"
#define RESET "\x1B[0m"

/*
	Autor do programa: Philip José Cordeiro de Torres
	github: https://github.com/hgkPhDt/
	Sistema usado para realizar a atividade: Debian 11 (Linux);

	Descrição: Grande parte do programa foi feito inteiramente por mim, salvo algumas partes que peguei de alguns amigos como o limpa buffer do Major Anilton. 
	O C tem um sério problema com buffer, podendo dar erro em algumas entradas de dados, e essa função limpa o lixo armazenado no buffer para evitar problemas no programa.

	Exitem algumas outras coisas mais avançadas que não foram abordadas no curso de Algoritmos e Lógica de programação, porém já se faz muito tempo que aprendi e salvei 
	em meu github para usar futuramente, então perdi a sua fonte.

	Programa salvo no github com imagens do programa rodando: https://github.com/hgkPhDt/Unicesumar/tree/master/Atividades/ALP.II/MAPA
*/

//Limpa buffer do Major Anilton -> Conhecido no grupo de linguagem C do whatszapp.
//Limpa buffer melhor que o fflush(stdin)
void bufferClean(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

//Função para converter caracteres maiúsculos para minúsculos.
void lowCase(char x[]){
	int i = 0;
	while(x[i]){
		x[i] = tolower(x[i]);
		i++;
	}
}

int main(){
	char op[30];
	int quantidade = 99;
	bool brahma = true;

	struct cadastro{
		int codigo;
		char name[51];
		char cpf[15];
		char vacina[30];
		char data[11];
		int lote;
	}vacinado[quantidade];

	//Laço de repetição para que o programa possa continuar sendo executado sem a necessidade de sair dele após a conclusão de uma determinada tarefa.
	while(brahma){

		system("clear");
		printf(BOLD "\n\n\t:::PREFEITURA DE LONDRINA:::" RESET);
		printf(BOLD BLINK RED REVERSE "\n\t::::::::::COVID-19::::::::::" RESET);

		printf("\n Para acessar um tópico, basta digitar: Cadastrar, Listar, Consultar ou Sair.");
		printf("\n\n -> Cadastrar vacina.");
		printf("\n -> Listar Aplicações.");
		printf("\n -> Consultar por CPF.");
		printf( RED "\n -> Sair." RESET);

		printf("\n\n Digite a operação desejada: ");
		scanf("%29[^\n]", &op);
		bufferClean();
		lowCase(op);

		if(strcmp(op, "sair") == 0){
			system("clear");
			break;
		}

		if(strcmp(op, "cadastrar") == 0 ){
			system("clear");
			printf(BOLD "\n\n\t:::PREFEITURA DE LONDRINA:::" RESET);
			printf(BOLD "\n\t::::CADASTRO DE VACINADO::::" RESET);

			int i = 0;
			do{
				
				printf("\n\n Cadastrado nº: %d\n", i+1);
				vacinado[i].codigo = i;
				
				printf(" Nome do vacinado: ");
				scanf("%50[^\n]", vacinado[i].name);
				bufferClean();

				printf(" CPF: ");
				scanf("%14[^\n]", vacinado[i].cpf);
				bufferClean();

				printf(" Vacina: ");
				scanf("%29[^\n]", vacinado[i].vacina);
				bufferClean();

				printf(" Data: ");
				scanf("%10[^\n]", vacinado[i].data);
				bufferClean();

				printf(" Número Lote: ");
				scanf("%d", &vacinado[i].lote);
				bufferClean();

				printf("\n\n -> Deseja cadastrar mais um [Y/n]? ");
				scanf("%29[^\n]", &op);
				bufferClean();
				lowCase(op);

				i++;

			//Esse laço de repetição irá fazer com que o usuário possa colocar quantos cadastrados ele quiser.
			}while(strcmp(op, "y") == 0);

			printf("\n Em 5 segundos você voltará a tela inícial.\n");
			sleep(5);
		}

		if(strcmp(op, "listar") == 0 ){
				system("clear");
				printf(BOLD "\n\n\t:::PREFEITURA DE LONDRINA:::" RESET);
				printf(BOLD "\n\t::::LISTAR  OS VACINADOS::::\n\n" RESET);

				int j = 0;
				while(vacinado[j].lote != 0){
					printf(" Código: %d\n", vacinado[j].codigo);
					printf(" Nome: %s\n", vacinado[j].name);
					printf(" cpf: %s\n", vacinado[j].cpf);
					printf(" Vacina: %s\n", vacinado[j].vacina);
					printf(" data: %s\n", vacinado[j].data);
					printf(" lote: %d\n", vacinado[j].lote);
					printf("=============================\n");
					j++;
				}

				printf("\n Pressione ENTER para sair.");
				system("read REPLY");
				bufferClean();		
			}

		if(strcmp(op, "consultar") == 0 ){
			system("clear");
			printf(BOLD "\n\n\t:::PREFEITURA DE LONDRINA:::" RESET);
			printf(BOLD "\n\t:::CONSULTAR  UM VACINADO:::" RESET);

			printf("\n\n\n Qual o CPF do vacinado? ");
			scanf("%29[^\n]", &op);
			bufferClean();

			int ultimo = 0;
			for(int j = 0; j <= quantidade; j++){
				if(strcmp(op, vacinado[j].cpf) == 0){
					printf("\n\n Código: %d\n", vacinado[j].codigo);
					printf(" Nome: %s\n", vacinado[j].name);
					printf(" cpf: %s\n", vacinado[j].cpf);
					printf(" Vacina: %s\n", vacinado[j].vacina);
					printf(" data: %s\n", vacinado[j].data);
					printf(" lote: %d\n", vacinado[j].lote);
					ultimo = j;

				}
			}

			if(!strcmp(op, vacinado[ultimo].cpf) == 0){
				printf(BOLD RED "\n CPF não encontrado.\n" RESET);
			}

			printf("\n Pressione ENTER para sair.");
			system("read REPLY");
			bufferClean();	
		}
	}
	return 0;

	/*
		MATERIAIS DE ESTUDO:

		Falhas de segmentação que aconteceu em meu programa:
		https://br.ccm.net/faq/10323-linguagem-c-c-c-falha-de-segmentacao

		Como comparar strings: 
		https://www.codegrepper.com/code-examples/c/how+to+compare+strings+in+c

		Como ler strings com espaços:
		https://www.youtube.com/watch?v=AAnuyKNzm_k

		Esclarecimento sobre structs com o professor Eduardo Casavella: 
		https://www.youtube.com/watch?v=h0GL9vWcxB8
	
		Converter palavras maiúsculas para minúsculas:
		https://wagnergaspar.com/como-converter-uma-string-em-maiusculo-ou-minusculo-em-qualquer-so-com-a-linguagem-c/

		Repositório das cores do terminal:
		https://github.com/hgkPhDt/terminal-colors

		Como ler uma string de forma adequada:
		https://www.youtube.com/watch?v=AAnuyKNzm_k

		Usando o parâmetro 'read' na função system():
		https://qastack.com.br/programming/1449324/how-to-simulate-press-any-key-to-continue
		https://unix.stackexchange.com/questions/581409/error-sh-1-read-arg-count


	*/
}


