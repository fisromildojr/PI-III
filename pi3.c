#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#include "pi3.h"
/*
void ConectaDB(MYSQL conexao){
	mysql_init(&conexao);
	if ( !mysql_real_connect(&conexao, "localhost", "root", "123456", "pi3", 0, NULL, 0) ){
    	// Se não estabelecer conexão segue aqui!!!
		return;
    }
}
*/
void Cabecalho(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    char sql[200];
    int Qtd;
    strcpy(sql, "select * from usuario;");
    mysql_query(&conexao, sql);
    resp = mysql_store_result(&conexao);
    linhas=mysql_fetch_row(resp);
    Qtd = mysql_num_rows(resp);
    printf("%d\n",Qtd);
    mysql_close(&conexao);
}


void CABECALHO_1(int Op){
        //setlocale(LC_ALL,"");
        int Op;
        system("clear");
        printf("\t     ******  ######  ######     ##   ########   ####### \n");
        printf("\t     ******  ######  ######     ##   ##        ##      #\n");
        printf("\t     ######  #######            ##   ##       ##        \n");
        printf("\t     ######  ######             ##   ######   ##        \n");
        printf("\t     ######  ######  ######     ##   ##       ##        \n");
        printf("\t     ######  ######  ######     ##   ##       ##    ####\n");
        printf("\t     ######  ######             ##   ##        ##     ##\n");
        printf("\t     ######  ######             ##   ##         #######\n");


        printf("\n\n\t   Seja bem vindo ao DESAFIO DO TERCEIRAO.  SISTEMA ESPELHO PONTO \nAo aceitar  participar voce vera o sistema desenvolvido pelos alunos como\ndesafio para o Terceiro Período de TADS!");
        printf("\n\n\n\t(1)-Aceito\t   Ou precione qualquer tecla para sair...");
        printf("\n\nOpção ==> ");
        __fpurge(stdin);
         scanf("%i", &Op);
    
        if(Op==1){
            return Op;
        }
            return 3;
}

void CABECALHO_2(int Op){
        
        system("clear");
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx       SISTEMA      xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx  ESPELHO DE PONTO  xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" );
        printf(" xxxxxxxxxxxxxxxxxxxxxxxxxxxx                    xxxxxxxxxxxxxxxxxxxxxxxxxxxx\n\n\n\n" );
        
        printf("              Digite as opção abaixo para prosseguir no sistema\n");
        printf("            (1) - acessar o menu  (2) - Cadastra senha  (3) - Sair \n" );
        scanf("%i", &Op);

        if(Op==1){
            return Op;
        }
        else 
        if(Op==2){
            return Op;
        }
            return 3;
}


void MenuPrincipal(){
    system("clear");
    printf("<<< ESCOLHA UMA OPCAO DO MENU >>>\n\n");
    printf("1 - Cadastrar Funcionario\n");
    printf("2 - Listar Funcionarios Cadastrados\n");
    printf("3 - Lancar Horas Trabalhadas\n");
    printf("4 - Gerar espelho ponto\n");
}

void InserirFuncionario(MYSQL conexao, MYSQL_RES *resp, MYSQL_ROW linhas, MYSQL_FIELD *campos){
    TipoFuncionario funcionario;
    int Erro;
    char nomeFuncionario[100],
         telefoneFuncionario[15],
         enderecoFuncionario[200],
         bairroFuncionario[30],
         cidadeFuncionario[30],
         ufFuncionario[3],
         sql[200];
    
    system("clear");
    printf("<<< CADASTRO DE FUNCIONARIO >>>\n\n");
    printf("Nome: ");
    fgets(nomeFuncionario,100,stdin);
    nomeFuncionario[strlen(nomeFuncionario)-1] = '\0';
    strcpy(funcionario.Nome, nomeFuncionario);            

    printf("Telefone: ");
    fgets(telefoneFuncionario,15,stdin);
    telefoneFuncionario[strlen(telefoneFuncionario)-1] = '\0';
    strcpy(funcionario.Telefone, telefoneFuncionario);

    printf("Endereco: ");
    fgets(enderecoFuncionario,200,stdin);
    enderecoFuncionario[strlen(enderecoFuncionario)-1] = '\0';
    strcpy(funcionario.Endereco, enderecoFuncionario);
                
    printf("Bairro: ");
    fgets(bairroFuncionario,30,stdin);
    bairroFuncionario[strlen(bairroFuncionario)-1] = '\0';
    strcpy(funcionario.Bairro, bairroFuncionario);

    printf("Cidade: ");
    fgets(cidadeFuncionario,30,stdin);
    cidadeFuncionario[strlen(cidadeFuncionario)-1] = '\0';
    strcpy(funcionario.Cidade, cidadeFuncionario);

    printf("UF: ");
    fgets(ufFuncionario,3,stdin);
    //ufFuncionario[strlen(ufFuncionario)-1] = '\0';
    strcpy(funcionario.UF, ufFuncionario);

    strcpy(sql, "INSERT INTO funcionario VALUES(null,'");
    strcat(sql, funcionario.Nome);
    strcat(sql, "','");
    strcat(sql, funcionario.Telefone);
    strcat(sql, "','");
    strcat(sql, funcionario.Endereco);
    strcat(sql, "','");
    strcat(sql, funcionario.Bairro);
    strcat(sql, "','");
    strcat(sql, funcionario.Cidade);
    strcat(sql, "','");
    strcat(sql, funcionario.UF);
    strcat(sql, "');");


//    printf("QUERY: %s\n", sql);
    system("clear");
    printf("<<< DADOS DO FUNCIONARIO >>>\n\n");
    printf("\nNOME FUNCIONARIO: %s\n", funcionario.Nome);
    printf("TELEFONE FUNCIONARIO: %s\n", funcionario.Telefone);
    printf("ENDERECO FUNCIONARIO: %s\n", funcionario.Endereco);
    printf("BAIRRO FUNCIONARIO: %s\n", funcionario.Bairro);
    printf("CIDADE FUNCIONARIO: %s\n", funcionario.Cidade);
    printf("UF FUNCIONARIO: %s\n\n", funcionario.UF);

    mysql_query(&conexao, sql);

    if(mysql_affected_rows(&conexao) != 1){
        printf("Erro: Nao foi possivel cadastrar o funcionario\n\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getchar();
    }else{
        printf("Funcionario cadastrado com sucesso!!!\n\n");
        printf("Pressione qualquer tecla para continuar...\n");
        getchar();
    }
    mysql_close(&conexao);
}

void CadastrarCartaoPonto(){

}

void GerarEspelho(){

}

void GerarHolerite(){

}

void ExibirFuncionario(){

}

void ExibirEspelho(){

}

void ExibirHolerite(){

}